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

Private m_sd As XceedWinsockLib.ConnectionOrientedSocket

Private m_Name As String
Private m_PeerName As String

Private m_PeerAddress As String
Private m_PeerPort As Integer

Private m_Key As New KeyExchange
Private m_PeerKey As New KeyExchange

Private m_PeerTZOffset As Double

Private m_Events As SessionEvents

Private m_CurrentVolGuid As String
Private m_CurrentVolInfo As New VolInfo

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

Public Sub SendMessage(ByVal Message As String, Optional ByVal Encrypted As Boolean = False)
    If Encrypted Then
        Message = PeerKey.EncryptMessage(Message)
        SendCmd NTC_ENCRYPTEDMESSAGE, Message
    Else
        Message = StringToBase64(Message)
        SendCmd NTC_MESSAGE, Message
    End If
End Sub

Public Sub SendFile(ByVal Path As String, ByVal SegmentSize As Long, Optional ByVal Passphrase As String)
    Dim Zip As New XceedZipLib.XceedZip
    Zip.License "ZIP50-JR393-AHS98-HRBA"
    Zip.SplitSize = SegmentSize
    'Zip.ZipFilename = tempfile
    If Passphrase <> "" Then Zip.EncryptionPassword = Passphrase
    Zip.Zip

    m_CurrentVolInfo = New VolInfo
    'm_CurrentVolGuid = randomguid
End Sub

Friend Sub Initialize(ByVal Name As String, ByVal sd As XceedWinsockLib.ConnectionOrientedSocket)
    m_Name = Name
    Set m_sd = sd

    Dim addr As XceedWinsockLib.InetAddress
    Set addr = sd.RemoteAddress

    m_PeerAddress = addr.GetAddressString
    m_PeerPort = addr.Port
End Sub

Private Sub SendCmd(ByVal Cmd As String, ParamArray params_())
    Dim params
    params = ParamArrayToArray(params_)
    m_sd.SendString NtCmd(Cmd, params), wnfAnsiStrings, wsoNone
End Sub

Friend Sub ProcessCommand(ByVal Cmd As NtCommand)
    Dim Text As String
    Dim AckMessage As String
    Dim VolIndex As Long
    Dim Cancel As Boolean

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
            SendCmd NTC_SETKEY, m_Key.PublicKey, "R"
        End If
    Case NTC_TOUCH
        ' RemoteTime - LocalTime
        m_PeerTZOffset = CDbl(Cmd.Parameter(1)) - CDbl(Date + Time)
        If Cmd.Parameter(2) = "S" Then
            SendCmd NTC_TOUCH, CDbl(Date + Time), "R"
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
    Case NTC_VOLINFO
        ' send vol-info-xml
        ' ...
    Case NTC_VOLINFO_R
        Dim vi As New VolInfo
        Dim unsent_index
        Text = Base64ToString(Cmd.Parameter(1))
        vi.ParseXML Text
        Set m_CurrentVolInfo = vi
        For Each unsent_index In vi.UnsentSegments(True)
            ' Retry unsent segments
            SendCmd NTC_REQVOL, m_CurrentVolGuid, unsent_index
        Next
    Case NTC_PUTVOL
        m_Events.OnVolumes Me
        Assert Cmd.Parameter(1) = m_CurrentVolGuid
        VolIndex = Val(Cmd.Parameter(2))
        ' m_sd.ReceiveFile tmpfile, 0, 0, 0
        If True Then ' checksum ok
            SendCmd NTC_ACPTVOL, m_CurrentVolGuid, VolIndex
        Else
            SendCmd NTC_REQVOL, m_CurrentVolGuid, VolIndex
        End If
    Case NTC_REQVOL
        ' request to send specified vol-segment
        ' just do send
        Assert Cmd.Parameter(1) = m_CurrentVolGuid
        VolIndex = Val(Cmd.Parameter(2))
        ' force unmark if already marked
        ' ...
        SendCmd NTC_PUTVOL, m_CurrentVolGuid, VolIndex
    Case NTC_ACPTVOL
        ' specified vol-segment accepted
        ' mark as sent
        ' ...
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

Private Sub Class_Initialize()
    key.GenerateKeys
    m_Name = G.Secret
End Sub
