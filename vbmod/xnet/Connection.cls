VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Connection"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::Connection"
Private Const SENDBUFFER                As Long = 1000000

Public Enum AsyncModeConstants
    amDefault = 0
    amSynchronized
    amAsynchronized
End Enum

Private m_Channel As Channel
Private m_Async As Boolean

Private m_Name As String
Private m_Address As String
Private m_Key As New AsymCrypto

Private m_PeerName As String
Private m_PeerAddress As String
Private m_PeerKey As AsymCrypto

Private m_SharedKey As New SymCrypto

Private m_PeerTZOffset As Double        ' RemoteTime - LocalTime

' All files, GUID -> File
Private m_SendFiles As New VBExt.Map
Private m_RecvFiles As New VBExt.Map
Private WithEvents m_SendingFile As Xnet.File      ' XXX   Not thread-safe
Attribute m_SendingFile.VB_VarHelpID = -1
Private m_SendingQueue As Boolean

Public Event OnPreSendPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnSentPacket(ByVal Pkt As Packet)
Public Event OnUnknownPacket(ByVal Pkt As Packet)

Public Event OnPreReceiveFile(ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnReceivingFile(ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnReceivingFileError(ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)
Public Event OnReceivedFile(ByVal f As Xnet.File)

Public Event OnSendingFile(ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnSendingFileError(ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)
Public Event OnSentFile(ByVal f As Xnet.File)

Public Event OnFileHashing(ByVal f As Xnet.File, ByVal ProcessedSize As Long)
Public Event OnFileCanceled(ByVal f As Xnet.File)

' Friend API
' ----------------------------------------------------------------------------
Property Get Channel() As Channel
    Set Channel = m_Channel
End Property

Property Set Channel(ByVal newval As Channel)
    Set m_Channel = newval
End Property

Property Let Address(ByVal newval As String)
    m_Address = newval
End Property

Property Let PeerAddress(ByVal newval As String)
    m_PeerAddress = newval
End Property

' Connection Attributes
' ----------------------------------------------------------------------------
Public Property Get Async() As Boolean
    Async = m_Async
End Property

Public Property Let Async(ByVal newval As Boolean)
    m_Async = newval
End Property

Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Name = newval
End Property

Public Property Get QName() As String
    QName = m_Name & "@" & m_Address
End Property

Property Get Address() As String
    Address = m_Address
End Property

Public Property Get PeerName() As String
    PeerName = m_PeerName
End Property

Public Property Get QPeer() As String
    QPeer = m_PeerName & "@" & m_PeerAddress
End Property

Property Get PeerAddress() As String
    PeerAddress = m_PeerAddress
End Property

Public Property Get Key() As AsymCrypto
    Set Key = m_Key
End Property

Public Property Set Key(ByVal newval As AsymCrypto)
    Assert Not newval Is Nothing
    Set m_Key = newval
    SendPacket MakePacket(NC_SETKEY, False, Nothing, newval.PublicKey)
End Property

Public Property Get PeerKey() As AsymCrypto
    Set PeerKey = m_PeerKey
End Property

Public Property Get SharedKey() As String
    SharedKey = m_SharedKey.Key
End Property

Public Property Let SharedKey(ByVal newval As String)
    m_SharedKey.Key = newval
End Property

' Sending
' ----------------------------------------------------------------------------
Public Sub SendPacket(ByVal Pkt As Packet, Optional ByVal Async As AsyncModeConstants = 0)
    Assert Not Pkt Is Nothing

    Dim Cancel As Boolean
    RaiseEvent OnPreSendPacket(Pkt, Cancel)
    If Cancel Then Exit Sub

    If Async = amDefault Then
        Async = IIf(m_Async, amAsynchronized, amSynchronized)
    End If

    If Async = amAsynchronized Then
        ' TODO...
        m_Channel.SendBytes Pkt.Encode, , , , True
        RaiseEvent OnSentPacket(Pkt)
        ' Assert False, "Not Implemented", LOCATION
        ' m_Channel.SendBytes Pkt.Encode, , , Pkt.PartialId, True
        ' When SentBytes:
        '   RaiseEvent OnSentPacket(Pkt)
    Else
        m_Channel.SendBytes Pkt.Encode
        RaiseEvent OnSentPacket(Pkt)
    End If
End Sub

Public Sub SendCmd0(ByVal CmdName As String, _
                    Optional ByVal Sequence As Long = 0)
    SendPacket MakePacket(CmdName, False, Nothing, Sequence)
End Sub

Public Sub SendCmd1(ByVal CmdName As String, _
                    ByVal Arg1 As String, _
                    Optional ByVal Encrypted As Boolean = False, _
                    Optional ByVal Sequence As Long = 0)
    SendPacket MakePacket(CmdName, Encrypted, m_SharedKey, Sequence, Arg1)
End Sub

Public Sub SendCmd2(ByVal CmdName As String, _
                    ByVal Arg1 As String, _
                    ByVal Arg2 As String, _
                    Optional ByVal Encrypted As Boolean = False, _
                    Optional ByVal Sequence As Long = 0)
    SendPacket MakePacket(CmdName, Encrypted, m_SharedKey, Sequence, Arg1, Arg2)
End Sub

Public Sub SendCmd3(ByVal CmdName As String, _
                    ByVal Arg1 As String, _
                    ByVal Arg2 As String, _
                    ByVal Arg3 As String, _
                    Optional ByVal Encrypted As Boolean = False, _
                    Optional ByVal Sequence As Long = 0)
    SendPacket MakePacket(CmdName, Encrypted, m_SharedKey, Sequence, Arg1, Arg2, Arg3)
End Sub

Public Sub SendCmd4(ByVal CmdName As String, _
                    ByVal Arg1 As String, _
                    ByVal Arg2 As String, _
                    ByVal Arg3 As String, _
                    ByVal Arg4 As String, _
                    Optional ByVal Encrypted As Boolean = False, _
                    Optional ByVal Sequence As Long = 0)
    SendPacket MakePacket(CmdName, Encrypted, m_SharedKey, Sequence, Arg1, Arg2, Arg3, Arg4)
End Sub

Public Sub SendSysCmd0(ByVal SysId As Long, _
                       Optional ByVal Sequence As Long = 0)
    SendCmd1 NC_SYSTEM, SysId, False, Sequence
End Sub

Public Sub SendSysCmd1(ByVal SysId As Long, _
                       ByVal Arg1 As String, _
                       Optional ByVal Encrypted As Boolean = False, _
                       Optional ByVal Sequence As Long = 0)
    SendCmd2 NC_SYSTEM, SysId, Arg1, Encrypted, Sequence
End Sub

Public Sub SendSysCmd2(ByVal SysId As Long, _
                       ByVal Arg1 As String, _
                       ByVal Arg2 As String, _
                       Optional ByVal Encrypted As Boolean = False, _
                       Optional ByVal Sequence As Long = 0)
    SendCmd3 NC_SYSTEM, SysId, Arg1, Arg2, Encrypted, Sequence
End Sub

Public Sub SendSysCmd3(ByVal SysId As Long, _
                       ByVal Arg1 As String, _
                       ByVal Arg2 As String, _
                       ByVal Arg3 As String, _
                       Optional ByVal Encrypted As Boolean = False, _
                       Optional ByVal Sequence As Long = 0)
    SendCmd4 NC_SYSTEM, SysId, Arg1, Arg2, Arg3, Encrypted, Sequence
End Sub

' Basic Protocol
' ----------------------------------------------------------------------------
Public Sub Register(Optional ByVal Sequence As Long = 0)
    SendCmd0 NC_REGISTER, Sequence
End Sub

Public Sub Unregister(Optional ByVal Sequence As Long = 0)
    SendCmd0 NC_UNREGISTER, Sequence
End Sub

Public Sub SetName(Optional ByVal Sequence As Long = 0)
    SendCmd1 NC_SETNAME, m_Name, , Sequence
End Sub

Public Sub SetKey(Optional ByVal Sequence As Long = 0)
    SendCmd1 NC_SETKEY, m_Key.PublicKey, , Sequence
End Sub

Public Sub SetSharedKey(Optional ByVal Sequence As Long = 0)
    If m_PeerKey Is Nothing Then
        SetKey Sequence
        ' The shared key will be set again, when SetKey/ACK is received.
    Else
        SendCmd1 NC_SETSHAREDKEY, _
            m_PeerKey.EncryptMessage(m_SharedKey.Key), , Sequence
    End If
End Sub

Public Sub SendTouch(Optional ByVal Sequence As Long = 0)
    SendCmd1 NC_TOUCH, CDbl(Date + Time), False, Sequence
End Sub

Public Sub SendMessage(ByVal Message As String, _
                       Optional ByVal Encrypted As Boolean = False, _
                       Optional ByVal Sequence As Long = 0)
    SendCmd1 NC_MESSAGE, Message, Encrypted, Sequence
End Sub

Public Sub SendScript(ByVal Script As String, _
                      Optional ByVal Language As String = "javascript", _
                      Optional ByVal Encrypted As Boolean = False, _
                      Optional ByVal Sequence As Long = 0)
    SendCmd2 NC_SCRIPT, Language, Script, Encrypted, Sequence
End Sub

Public Sub SendInvite(Optional ByVal Sequence As Long = 0)
    SendCmd0 NC_INVITE, Sequence
End Sub

' Send File
' ----------------------------------------------------------------------------
Public Sub SendFile(ByVal Path As String, _
                    Optional ByVal FullName As String, _
                    Optional ByVal Encrypted As Boolean = False, _
                    Optional ByVal DeleteWhenSent As Boolean = False, _
                    Optional ByVal DeleteWhenCanceled As Boolean = False, _
                    Optional ByVal PacketSize As Long = -1)
    If FullName = "" Then FullName = Path
    If PacketSize < 0 Then PacketSize = Constants.DEFAULT_PKTSIZE

    Dim f As New File
    f.RecvMode = False
    f.Path = Path
    f.FullName = FullName
    f.DeleteWhenTransferred = DeleteWhenSent
    f.DeleteWhenCanceled = DeleteWhenCanceled
    f.Init -1, PacketSize
    f.Encrypted = Encrypted

    ' To capture hashing progress.
    Set m_SendingFile = f
        f.Checksum = f.Hash
    Set m_SendingFile = Nothing

    Set m_SendFiles.Item(f.GUID) = f

    SendFileInfo f

    SendFileQueue
End Sub

Private Sub SendFileInfo(ByVal f As Xnet.File)
    Dim Pkt As Packet
    ' FileInfo(long id, long size, long pkt_size, char[20], string, fullname)
    Set Pkt = MakePacket(NC_PUTFILE, f.Encrypted, m_SharedKey, 0, _
                         f.GUID, f.Size, f.PacketSize, f.Checksum, f.FullName)

    ' If DebugMode Then RemakePacket Pkt
    SendPacket Pkt
End Sub

Private Sub SendFileQueue()
    If m_SendingQueue Then Exit Sub
    m_SendingQueue = True

    Dim IdSet As Collection
    Dim Id
    Dim f As Xnet.File
    Set IdSet = m_SendFiles.KeySet
    For Each Id In IdSet
        Set f = m_SendFiles.Item(Id)
        If f.Status = pktTransferred Then
            m_SendFiles.Remove Id
            RaiseEvent OnSentFile(f)
        Else
            SendFilePackets f
        End If
    Next

    m_SendingQueue = False
End Sub

Private Sub SendFilePackets(ByVal f As Xnet.File)
    Dim Id As String
    Id = f.GUID

    Dim i As Long
    For i = 0 To f.Packets - 1
        If f.PacketStatus(i) = pktQueued Then

            ' This will set packet(i).status => transferring
            SendFilePacket f, i

            ' Don't send too much at once.
            If f.TransferringSize > SENDBUFFER Then
                Exit Sub
            End If

        End If

        ' the SendFilePacket may in sync/async mode.
        ' in either mode, there should be a presending-delay
        '    (maybe async-buffer is full, or something else.)
        ' in this delay, the incoming messages might want to cancel the sending
        ' process.
        If Not m_SendFiles.Contain(Id) Then
            ' Canceled
            SendCmd3 NC_PUTFILE_C, Id, "C", "Removed entry in the sender's queue"
            RaiseEvent OnFileCanceled(f)
            Exit Sub
        End If
    Next
End Sub

Private Function SendFilePacket(ByVal f As Xnet.File, ByVal PacketIndex As Long) As Boolean
    Dim Pkt As Packet
    Dim PacketSize As Long
    Dim PacketData() As Byte
    Dim PacketChk As Long

    PacketSize = f.GetPacketSize(PacketIndex)
    PacketData = f.GetPacketData(PacketIndex)
    PacketChk = Val(CalcChecksum(PacketData))

    ' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
    Set Pkt = MakePacket(NC_FILEPACKET, f.Encrypted, m_SharedKey, 0, _
                         f.GUID, PacketIndex, PacketSize, PacketChk)
    If f.Encrypted Then
        Set Pkt.Key = m_SharedKey
        ' TODO   m_SharedKey.EncryptMessage ...
        Pkt.BytesArg(4) = PacketData
    Else
        Pkt.BytesArg(4) = PacketData
    End If

    Dim p2 As Packet
    'Set p2 = RemakePacket(Pkt)

    f.PacketStatus(PacketIndex) = pktTransferring

    ' Must using synchronized mode
    SendPacket Pkt ', amAsynchronized
End Function

Public Function ResumeFiles(ByVal SendFilesXML As String) As Boolean
'    Dim Doc As New DOMDocument
'    Dim SessionAttribute As String
'    Dim Segs
'
'    If Not Doc.loadXML(SendFilesXML) Then Exit Function
'
'    Dim elmSendFiles As IXMLDOMElement
'    Set elmSendFiles = Doc.childNodes(0)
'
'    SessionAttribute = elmSendFiles.getAttribute("session")
'    Segs = Split(SessionAttribute, ":")
'    Assert (UBound(Segs) - LBound(Segs) + 1) >= 2, _
'           "session attribute should be in format name:key", LOCATION
'
'    Name = Base64ToString(Segs(0))
'    SharedKey = Base64ToString(Segs(1))
'
'    Dim elmFile As IXMLDOMElement
'    Dim elmStatus As PacketStatusConstants
'    Dim i As Integer
'    For i = 0 To elmSendFiles.childNodes.length - 1
'        Set elmFile = elmSendFiles.childNodes(i)
'        elmStatus = Val(elmFile.getAttribute("status"))
'        If elmStatus <> pktTransferred Then
'            Dim f As New File
'            f.FullName = elmFile.getAttribute("fullname")
'            f.Path = elmFile.getAttribute("path")
'
'            SendFile f
'        End If
'    Next
End Function

' Packet Process
' ----------------------------------------------------------------------------
Friend Sub RecvPacket(ByVal Pkt As Packet)
    Dim Cancel As Boolean
    Dim Id As String
    Dim b As Boolean
    Dim l As Long

    Dim RecvFile As Xnet.File
    Dim SendFile As Xnet.File
    Dim f As Xnet.File

    Set Pkt.Key = m_SharedKey

    Select Case Pkt.Name
    Case NC_REGISTER
        ' Client.Register -> Server

    Case NC_UNREGISTER
        ' Client.Unregister -> Server

    Case NC_SETNAME
        m_PeerName = Pkt.XArg(0)
        If Pkt.Initiative Then SetName Pkt.Reply

    Case NC_SETKEY
        Set m_PeerKey = New AsymCrypto
        m_PeerKey.PublicKey = Pkt.XArg(0)
        If Pkt.Initiative Then
            SetKey Pkt.Reply
        Else
            ' When SetKey/Ack is received, set shared key
            SetSharedKey
        End If

    Case NC_SETSHAREDKEY
        Dim PeerSharedKey As String
        PeerSharedKey = m_Key.DecryptMessage(Pkt.XArg(0))
        If Pkt.Initiative Then
            m_SharedKey.Key = PeerSharedKey
            SetSharedKey Pkt.Reply
        Else
            ' Assert m_SharedKey.Key = PeerSharedKey
            ' Set again if something is wrong. maybe transfer not correct?
            If m_SharedKey.Key <> PeerSharedKey Then
                SetSharedKey Pkt.Reply
            End If
        End If

    Case NC_TOUCH
        ' Resuming if the sending is suspended
        SendFileQueue

    Case NC_MESSAGE
        ' Do nothing in connection.

    Case NC_SCRIPT
        Dim ScriptLang As String
        Dim Script As String
        ScriptLang = Pkt.XArg(0)
        Script = Pkt.XArg(1)
        RunScript Script, ScriptLang

    Case NC_PUTFILE
        ' PutFile(long id, long size, long pkt_size, char[20], string fullname)
        ' Receive File
        Id = Pkt.XArg(0)

        If Pkt.Initiative Then
            ' I'm receiver
            Assert Pkt.Args >= 5

            Set RecvFile = New File
            RecvFile.RecvMode = True
            RecvFile.GUID = Id
            RecvFile.Checksum = Pkt.XArg(3)
            RecvFile.FullName = Pkt.XArg(4)
            RecvFile.Path = RecvFile.FullName
            RecvFile.Init Val(Pkt.XArg(1)), Val(Pkt.XArg(2))
            RecvFile.DeleteWhenCanceled = True
            RaiseEvent OnPreReceiveFile(RecvFile, Cancel)

            If Cancel Then
                ' RecvFile hasn't been added to m_Files, yet.
                RecvFile.Cancel
                SendCmd3 NC_PUTFILE, Id, "C", "Put File Request Rejected", False, Pkt.Reply
                RaiseEvent OnFileCanceled(RecvFile)
            Else
                Set m_RecvFiles.Item(RecvFile.GUID) = RecvFile
                SendCmd2 NC_PUTFILE, Id, "A", False, Pkt.Reply
            End If
        Else
            ' I'm sender

            ' just ignore if the file is no longer be managed
            If Not m_SendFiles.Contain(Id) Then Exit Sub

            Select Case Pkt.XArg(1)
            Case "A"
                ' Do nothing
            Case "C"
                Set f = m_SendFiles.Item(Id)
                ' If the sender don't wait to fileinfo/Ack and sending data immediately
                ' after the fileinfo is sent, then this "entry lost" will notify the
                ' sender to stop sending the future data.
                m_SendFiles.Remove Id
            End Select
        End If

    Case NC_PUTFILE_C
        Id = Pkt.XArg(0)

        If Pkt.Initiative Then
            ' I'm receiver
            If Not m_RecvFiles.Contain(Id) Then Exit Sub

            Select Case Pkt.XArg(1)
            Case "C"                    ' Cancel receiving
                Set RecvFile = m_RecvFiles.Item(Id)
                m_RecvFiles.Remove Id
                RecvFile.Cancel
                RaiseEvent OnFileCanceled(RecvFile)
            End Select
        Else
            ' I'm sender
            ' Receiver send control to sender should using PUTFILE/Return method.
        End If

    Case NC_FILEPACKET
        ' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
        ' Receive File Packet
        Id = Pkt.XArg(0)

        Dim PktIndex As Long
        PktIndex = Val(Pkt.XArg(1))

        If Pkt.Initiative Then
            ' I'm receiver

            ' Stop the sender if the file is no longer managed.
            If Not m_RecvFiles.Contain(Id) Then
                SendCmd3 NC_PUTFILE, Id, "C", "Removed entry in receiver's queue", False, 9
                Exit Sub
            End If

            Set RecvFile = m_RecvFiles.Item(Id)

            Dim PktData() As Byte
            PktData = Pkt.BytesArg(4)
            If CalcChecksum(PktData) = Pkt.XArg(3) Then
                ' Packet OK
                ' (PktSize is ignored. )
                Do
                    ' This will update the file.status
                    l = RecvFile.PutPacket(PktIndex, PktData)

                    Cancel = l <> ERR_OK
                    If Cancel Then
                        RaiseEvent OnReceivingFileError(RecvFile, l, Cancel)
                    End If
                Loop While l <> ERR_OK And Not Cancel

                If Cancel Then
                    ' User canceled receiving, when packet ok or fail
                    SendCmd3 NC_PUTFILE, Id, "C", "Cancel Request", False, 9
                Else
                    SendCmd3 NC_FILEPACKET, Id, PktIndex, "A", False, Pkt.Reply
                    RaiseEvent OnReceivingFile(RecvFile, Cancel)

                    If RecvFile.Status = pktTransferred Then
                        RaiseEvent OnReceivedFile(RecvFile)
                    End If
                End If
            Else
                ' Packet Checksum Error
                ' RecvFile.PacketStatus = pktReTransfer
                RaiseEvent OnReceivingFileError(RecvFile, ERR_PFK_CHECKSUM, Cancel)

                If Cancel Then
                    ' User canceled receiving, when packet fail
                    SendCmd3 NC_PUTFILE, Id, "C", "Cancel Request For Error Packet", False, 9
                Else
                    ' Ask for Re-send this packet
                    SendCmd3 NC_FILEPACKET, Id, PktIndex, "R", False, Pkt.Reply
                End If
            End If

        Else

            ' I'm sender, process control code.

            ' If a sendfile is removed by either "Sent" or "Send-canceled"
            ' there should be no more incoming messages about this file.
            ' But if a control-message is sent before (maybe because of net delay)
            ' then just ignore it.
            If Not m_SendFiles.Contain(Id) Then
                ' Ignore
                Exit Sub
            End If

            Select Case Pkt.XArg(2)
            Case "A"    ' Packet Sent Completed
                Set SendFile = m_SendFiles.Item(Id)
                ' Mark as sent
                SendFile.PacketStatus(PktIndex) = pktTransferred

                RaiseEvent OnSendingFile(SendFile, Cancel)

            Case "R"    ' Packet Failed, Re-Send
                Set SendFile = m_SendFiles.Item(Id)
                ' Mark to re-send
                SendFile.PacketStatus(PktIndex) = pktQueued

                RaiseEvent OnSendingFile(SendFile, Cancel)

            End Select

            If Cancel Then
                m_SendFiles.Remove Id   ' The sending-loop may discover "entry lost"
                SendCmd3 NC_PUTFILE_C, Id, "C", "Canceled by sender"
            Else
                ' (Non-Reentrant)
                ' Send any lost packets, and check if the file is sent completed.
                SendFileQueue
            End If
        End If

    Case NC_INVITE
        ' This should be happened to client,
        ' when Client.Invite -> Server, the Server should spawn a client-connection
        ' to connect back to the peer server in the source client.
    Case Else
        RaiseEvent OnUnknownPacket(Pkt)
    End Select
End Sub

' m_SendingFile events
' ----------------------------------------------------------------------------
Private Sub m_SendingFile_OnError(ByVal ErrId As Long, ByVal Description As String)
    Dim Cancel As Boolean
    RaiseEvent OnSendingFileError(m_SendingFile, ErrId, Cancel)
    Assert Not Cancel, "The error is triggered by low-level I/O operation, " _
                     & "which cannot be canceled within event handler. ", LOCATION
End Sub

Private Sub m_SendingFile_OnHashing(ByVal ProcessedSize As Long)
    RaiseEvent OnFileHashing(m_SendingFile, ProcessedSize)
End Sub

' Class
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
    m_Name = Secret

    ' Default to enable asynchronize mode
    m_Async = True
End Sub
