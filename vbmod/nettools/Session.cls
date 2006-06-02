VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Session"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Enum ReceivingStateConstants
    rsCommand = 0
    rsFileData
End Enum

Private m_Outer As NetTools.SystemEventListener

Private m_sd As XceedWinsockLib.ConnectionOrientedSocket
Private m_RecvState As ReceivingStateConstants

Private m_Name As String
Private m_PeerName As String

Private m_PeerAddress As String
Private m_PeerPort As Integer

Private m_Key As New KeyExchange
Private m_PeerKey As New KeyExchange

Private m_PeerTZOffset As Double

Private m_Events As SessionEvents

Private m_TrID As Long
Private m_SendFiles As New VBExt.Map
Private m_SendingFile As PutFile

Private m_ReceivingFile As RecvFile

Friend Property Get sd() As XceedWinsockLib.ConnectionOrientedSocket
    Set sd = m_sd
End Property

Property Get PeerAddress() As String
    PeerAddress = m_PeerAddress
End Property

Property Get PeerPort() As String
    PeerPort = m_PeerPort
End Property

Property Get Name() As String
    Name = m_Name
End Property

Property Let Name(ByVal newval As String)
    m_Name = newval
    ' send name
    SendCmd NTC_SETNAME, StringToBase64(m_Name)
End Property

Property Get PeerName() As String
    PeerName = m_PeerName
End Property

Property Get key() As KeyExchange
    Set key = m_Key
End Property

Property Get PeerKey() As KeyExchange
    Set PeerKey = m_PeerKey
End Property

Public Sub Advise(ByVal sEvents As SessionEvents)
    If sEvents Is Nothing Then
        Unadvise
    Else
        Set m_Events = sEvents
    End If
End Sub

Public Sub Unadvise()
    Set m_Events = Null_SessionEvents
End Sub

Public Sub SetName(Optional ByVal Initiative As Boolean = True)
    SendCmd NTC_SETNAME, StringToBase64(m_Name), IIf(Initiative, "S", "R")
End Sub

Public Sub SetKey(Optional ByVal Initiative As Boolean = True)
    SendCmd NTC_SETKEY, m_Key.PublicKey, IIf(Initiative, "S", "R")
End Sub

Public Sub Touch(Optional ByVal Initiative As Boolean = True)
    SendCmd NTC_TOUCH, CDbl(Date + Time), IIf(Initiative, "S", "R")
End Sub

Public Sub SysEvent(ByVal EventName As String, Optional ByVal Initiative As Boolean = True)
    SendCmd NTC_SYSEVENT, EventName, IIf(Initiative, "S", "R")
End Sub

Public Sub SendMessage(ByVal Message As String, Optional ByVal Encrypted As Boolean = False)
    If Encrypted Then
        If m_PeerKey.PublicKey = "" Then SetKey True
        Message = PeerKey.EncryptMessage(Message)
        SendCmd NTC_ENCRYPTEDMESSAGE, Message
    Else
        Message = StringToBase64(Message)
        SendCmd NTC_MESSAGE, Message
    End If
End Sub

Private Sub SendQueue()
    Dim TrID
    Dim pf As PutFile

    ' XXX: does collection support concurrent-r/w ?
    For Each TrID In m_SendFiles.KeySet
        Set pf = m_SendFiles(TrID)
        If Not pf.Done Then
            SendItem TrID, pf
        End If
    Next
End Sub

Private Sub SendItem(ByVal TrID As Long, ByVal pf As PutFile)
    Set m_SendingFile = pf
    ' PutFile(tr-id, size, [name], [cat], [hash], <size bytes>...>): ack/_R
    SendCmd NTC_PUTFILE, TrID, pf.Size, _
            StringToBase64(pf.RemoteName), StringToBase64(pf.Category), pf.HashCode

    ' This is really the same to send data bytes by hand
    ' The problem is occurred in receiving
    m_sd.SendFile pf.LocalPath, 0, pf.Size, 0

    ' To avoid if receiver can't switch to command-mode, correctly
    Touch
End Sub

Public Sub SendFile(ByVal Path As String, ByVal Category As String, _
                    Optional ByVal Encrypted As Boolean = False, _
                    Optional ByVal RemoteName As String)
    Dim pf As New PutFile
    pf.Category = Category
    If RemoteName = "" Then
        pf.RemoteName = baseName(Path)
    Else
        pf.RemoteName = RemoteName
    End If

    If Encrypted Then
        Dim srcpath As String
        srcpath = pf.LocalPath
        pf.SetTemporaryPath
        If m_PeerKey.PublicKey = "" Then SetKey True
        m_PeerKey.EncryptFile srcpath, pf.LocalPath
    Else
        pf.LocalPath = Path
    End If
    pf.UpdateHashCode

    pf.CancelPattern = NTC_PUTFILE_CANCELPATTERN

    ' If Not pf.isValid Then ...

    m_TrID = m_TrID + 1
    m_SendFiles(m_TrID) = pf

    SendQueue
End Sub

Public Sub SendFiles(ByVal Paths As Collection, ByVal Category As String, _
                     Optional ByVal Encrypted As Boolean = False)
    Dim p
    For Each p In Paths
        SendFile p, Category, Encrypted
    Next
End Sub

Public Sub SendDirectory(ByVal Directory As String, ByVal Category As String, _
                         Optional ByVal Encrypted As Boolean = False)
    Dim f
    For Each f In FSO.GetFolder(Directory).Files
        SendFile f.Path, Category, Encrypted
    Next
End Sub

Friend Sub Initialize(ByVal Outer As NetTools.SystemEventListener, ByVal sd As XceedWinsockLib.ConnectionOrientedSocket)
    Set m_Outer = Outer

    Set m_sd = sd
    m_sd.SendTimeOut = TIMEOUT_SEND
    m_sd.ReceiveTimeOut = TIMEOUT_RECEIVE

    Dim addr As XceedWinsockLib.InetAddress
    Set addr = sd.RemoteAddress

    m_PeerAddress = addr.GetAddressString
    m_PeerPort = addr.Port
End Sub

Private Function SendCmd(ByVal Cmd As String, ParamArray params_()) As Boolean
    Dim Params
    Params = ParamArrayToArray(params_)
    SendCmd = SendString(NtCmd(Cmd, Params))
End Function

Private Function SendString(ByVal str As String) As Boolean
    On Error GoTo x
    m_sd.SendString str, wnfAnsiStrings, wsoNone
    SendString = True
    Exit Function
x:
    ' Timeout?
    SendString = False
End Function

Friend Sub ProcessBytes(ByRef vaData As Variant)
    Dim Size As Long
    Dim Bytes() As Byte
    Bytes = vaData
    Size = ArraySize(Bytes)

    Select Case m_RecvState
    Case rsCommand
        Dim CmdLine As String
        Dim Cmd As NtCommand

        CmdLine = StrConv(Bytes, vbUnicode)
        Set Cmd = ParseCmd(CmdLine)
        If Cmd Is Nothing Then Exit Sub

        ProcessCommand Cmd

    Case rsFileData

        vaData = m_ReceivingFile.Append(Bytes)

        If m_ReceivingFile.EOF Then
            m_RecvState = rsCommand
            ProcessFileReceived m_ReceivingFile.LocalPath
        Else
            ProcessFileReceiving m_ReceivingFile.LocalPath, _
                                 m_ReceivingFile.CurrentSize - Size, Size, _
                                 m_ReceivingFile.ReqFileSize
        End If

        If Not IsEmpty(vaData) Then
            ' Rejected
            ProcessBytes vaData
        End If

    End Select
End Sub

Friend Sub ProcessCommand(ByVal Cmd As NtCommand)
    Dim Text As String
    Dim AckMessage As String
    Dim TrID As Long
    Dim URI As String
    Dim Size As Long
    Dim Cancel As Boolean
    Dim Response
    Dim pf As PutFile

    m_Events.OnPreCommand Me, Cmd, Cancel
    If Cancel Then Exit Sub

    Select Case UCase(Cmd.Name)
    Case NTC_SETNAME ' sender : recver
        m_PeerName = Base64ToString(Cmd.Parameter(1))
        If Cmd.Parameter(2) = "S" Then
            SendCmd NTC_SETNAME, StringToBase64(m_Name), "R"
        End If
    Case NTC_SETKEY
        m_PeerKey.PublicKey = Cmd.Parameter(1)
        If Cmd.Parameter(2) = "S" Then
            SetKey False
        End If
    Case NTC_SYSEVENT
        Text = Cmd.Parameter(1)
        m_Outer.OnSystemEvent Me, Text, IIf(Cmd.Parameter(2) = "S", True, False)
    Case NTC_TOUCH
        ' RemoteTime - LocalTime
        m_PeerTZOffset = CDbl(Cmd.Parameter(1)) - CDbl(Date + Time)
        If Cmd.Parameter(2) = "S" Then
            Touch False
        End If
        m_Events.OnTouch Me
    Case NTC_MESSAGE
        Text = Base64ToString(Cmd.Parameter(1))
        m_Events.OnMessage Me, Text, False, AckMessage
        If Cmd.Parameter(2) = "S" Then
            SendCmd NTC_MESSAGE, StringToBase64(AckMessage), "R"
        End If
    Case NTC_ENCRYPTEDMESSAGE
        Text = m_Key.DecryptMessage(Cmd.Parameter(1))
        m_Events.OnMessage Me, Text, True, AckMessage
        If Cmd.Parameter(2) = "S" Then
            SendCmd NTC_ENCRYPTEDMESSAGE, m_PeerKey.EncryptMessage(AckMessage), "R"
        End If
    Case NTC_GET
        TrID = CLng(Cmd.Parameter(1))
        URI = Base64ToString(Cmd.Parameter(2))
        m_Events.OnGet Me, URI, Response
        SendCmd NTC_RESPONSE, TrID, Len(Response)
        m_sd.SendBytes Response, wsoNone
    Case NTC_RESPONSE
        TrID = CLng(Cmd.Parameter(1))
        Size = CLng(Cmd.Parameter(2))
        m_sd.ReceiveBytes Size, Response, wroWaitForData
        'URI=uris(TrID)
        m_Events.OnResponse Me, URI, Response
    Case NTC_PUTFILE
        TrID = CLng(Cmd.Parameter(1))
        Size = CLng(Cmd.Parameter(2))

        Set m_ReceivingFile = New RecvFile
        With m_ReceivingFile
            .TrID = TrID
            .ReqFileSize = Size
            .ReqHashCode = Cmd.Parameter(5)
            .RemoteName = Base64ToString(Cmd.Parameter(3))
            .Category = Base64ToString(Cmd.Parameter(4))

            Dim SavePath As String
            Dim Ignore As Boolean
            .SetTemporaryPath
            SavePath = .LocalPath
            m_Events.OnIncomingFile Me, .RemoteName, .Category, _
                                    .IsEncrypted, Size, SavePath, Ignore

            If SavePath <> .LocalPath Then
                FSO.DeleteFile .LocalPath, True
                MakeParents SavePath
                .LocalPath = SavePath
            End If

            m_RecvState = rsFileData

            If Ignore Then
                ' Cancel-Sending
                SendCmd NTC_PUTFILE_R, TrID, "CS"
            End If
        End With

    Case NTC_PUTFILE_R
        TrID = CLng(Cmd.Parameter(1))
        Text = Cmd.Parameter(2)

        Assert m_SendFiles.Contain(TrID)
        Set pf = m_SendFiles(TrID)

        Select Case Text
        Case "A"                        ' Acknowledged
            m_SendFiles.Remove TrID
        Case "R"                        ' Re-send
            m_Events.OnReSend Me, pf.LocalPath, pf.RemoteName, pf.Category, _
                              pf.IsEncrypted, Cancel
            If Cancel Then
                pf.Done = True          ' Maybe "Done = Cancel" is better
                SendCmd NTC_PUTFILE_R, TrID, "RR"
            Else
                SendItem TrID, pf
            End If
        Case "CS"                       ' Cancel-Sending
            ' Cancel m_SD.SendFile
            m_Events.OnSendingCanceled Me, pf.LocalPath, pf.RemoteName, _
                                       pf.Category, pf.IsEncrypted
            SendCmd NTC_PUTFILE_R, TrID, "CR", pf.CancelPattern
        Case "CR"                       ' Cancel-Receiving
            If m_ReceivingFile Is Nothing Then
                ' Skip this command
            Else
                With m_ReceivingFile
                    Assert TrID = .TrID
                    ' Cancel Receiving...
                    m_RecvState = rsCommand
                    m_Events.OnReceivingCanceled Me, .RemoteName, .Category, .IsEncrypted, .LocalPath
                End With
                Set m_ReceivingFile = Nothing
            End If
        End Select
    Case NTC_SCRIPT     ' lang, script
        Dim Sign As String
        Sign = Cmd.Parameter(3)
        Text = Base64ToString(Cmd.Parameter(2))

        ' Check sign against Text ?
        ' ...

        Dim Ret As Variant
        Dim SendRet As Boolean
        SendRet = Cmd.Parameter(2) = "S"

        LC.Assign Ret, ScriptEval(Cmd.Parameter(1), Text, SendRet)

        If IsObject(Ret) Then
            If Ret Is Err Then
                Ret = "Error: " & Err.Number & vbNewLine _
                    & Err.Source & vbNewLine _
                    & Err.Description & vbNewLine
            Else
                Ret = "Object: " & TypeName(Ret)
            End If
        End If
        If SendRet Then
            ' NETCOMM
            SendCmd NTC_SCRIPT_R, StringToBase64(Ret, True)
        End If
    Case NTC_SCRIPT_R
        Text = Base64ToString(Cmd.Parameter(1), True)
        m_Events.OnScriptResult Me, Text
    End Select

    m_Events.OnCommand Me, Cmd
End Sub

Friend Sub ProcessFileSending(ByVal FileName As String, ByVal StartOffset As Long, _
                              ByVal BytesSent As Long, ByVal BytesTotal As Long)
    Assert Not m_SendingFile Is Nothing
    With m_SendingFile
        Assert FileName = .LocalPath
        Assert BytesTotal = .Size
        m_Events.OnSendingFile Me, FileName, .RemoteName, .Category, .IsEncrypted, _
                               .Size, StartOffset, BytesSent
    End With
End Sub

Friend Sub ProcessFileSent(ByVal FileName As String)
    Assert Not m_SendingFile Is Nothing
    With m_SendingFile
        Assert FileName = .LocalPath
        m_Events.OnSentFile Me, FileName, .RemoteName, .Category, .IsEncrypted
    End With
End Sub

Friend Sub ProcessFileReceiving(ByVal FileName As String, ByVal StartOffset As Long, _
                                ByVal BytesReceived As Long, ByVal BytesTotal As Long)
    Assert Not m_ReceivingFile Is Nothing
    With m_ReceivingFile
        Assert FileName = .LocalPath
        Assert BytesTotal = .ReqFileSize
        m_Events.OnReceivingFile Me, .RemoteName, .Category, .IsEncrypted, _
                                 .ReqFileSize, StartOffset, BytesReceived, FileName
    End With
End Sub

Friend Sub ProcessFileReceived(ByVal FileName As String)
    Assert Not m_ReceivingFile Is Nothing
    With m_ReceivingFile
        Assert FileName = .LocalPath

        .UpdateHashCode
        If .ReqHashCode = .HashCode Then
            SendCmd NTC_PUTFILE_R, .TrID, "A"
            m_Events.OnReceivedFile Me, .RemoteName, .Category, .IsEncrypted, FileName
        Else
            SendCmd NTC_PUTFILE_R, .TrID, "R"
        End If
    End With
End Sub

Private Sub Class_Initialize()
    key.GenerateKeys
    m_Name = Secret
End Sub
