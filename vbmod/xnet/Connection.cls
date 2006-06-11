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

Private m_Channel As Channel

Private m_Name As String
Private m_Address As String
Private m_Key As New AsymCrypto

Private m_PeerName As String
Private m_PeerAddress As String
Private m_PeerKey As AsymCrypto

Private m_SharedKey As New SymCrypto

Private m_PeerTZOffset As Double        ' RemoteTime - LocalTime

' All files, GUID -> File
Private m_Files As New VBExt.Map

Public Event OnPreSendPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnSentPacket(ByVal Pkt As Packet)

Public Event OnPreReceiveFile(ByVal f As File, ByRef Cancel As Boolean)
Public Event OnReceivingFile(ByVal f As File, ByRef Cancel As Boolean)
Public Event OnReceivedFile(ByVal f As File)

Public Event OnSendingFile(ByVal f As File, ByRef Cancel As Boolean)
Public Event OnSentFile(ByVal f As File)

Public Event OnFileCanceled(ByVal f As File)

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
Public Sub SendPacket(ByVal Pkt As Packet, _
                      Optional ByVal Async As Boolean = False)
    Assert Not Pkt Is Nothing

    Dim Cancel As Boolean
    RaiseEvent OnPreSendPacket(Pkt, Cancel)
    If Cancel Then Exit Sub

    If Async Then
        Assert False, "Not Implemented", LOCATION
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
                    Optional ByVal PacketSize As Long = Constants.DEFAULT_PKTSIZE)
    If FullName = "" Then FullName = Path

    Dim f As New File
    f.RecvMode = False
    f.Path = Path
    f.FullName = FullName
    f.DeleteWhenTransferred = DeleteWhenSent
    f.DeleteWhenCanceled = DeleteWhenCanceled
    f.Init -1, PacketSize

    SendFileInfo f, Encrypted
    SendFilePackets f, Encrypted
End Sub

Private Sub SendFileInfo(ByVal f As File, Optional ByVal Encrypted As Boolean = False)
    Dim Pkt As Packet
    ' FileInfo(long id, long size, long pkt_size, char[20], string, fullname)
    Set Pkt = MakePacket(NC_PUTFILE, Encrypted, m_SharedKey, 0, _
                         f.GUID, f.Size, f.PacketSize, f.Checksum, f.FullName)
    SendPacket Pkt
End Sub

Private Sub SendFilePackets(ByVal f As File, Optional ByVal Encrypted As Boolean = False)
    Dim Id As String
    Id = f.GUID

    Dim i As Long
    For i = 0 To f.Packets - 1
        If f.PacketStatus(i) = pktQueued Then
            SendFilePacket f, i, Encrypted
            If Not m_Files.Contain(Id) Then
                ' Canceled
                RaiseEvent OnFileCanceled(f)
                Exit Sub
            End If
        End If
    Next
End Sub

Private Function SendFilePacket(ByVal f As File, ByVal PacketIndex As Long, _
                                Optional ByVal Encrypted As Boolean = False) As Boolean
    Dim Pkt As Packet
    Dim PacketSize As Long
    Dim PacketData() As Byte
    Dim PacketChk As Long

    PacketSize = f.GetPacketSize(PacketIndex)
    PacketData = f.GetPacketData(PacketIndex)
    PacketChk = CalcChecksum(PacketData)

    ' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
    Set Pkt = MakePacket(NC_FILEPACKET, Encrypted, m_SharedKey, _
                         f.GUID, PacketIndex, PacketSize, PacketChk, PacketData)

    If Encrypted Then Set Pkt.Key = m_SharedKey

    f.PacketStatus(PacketIndex) = pktTransferring

    SendPacket Pkt
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
    Dim B As Boolean

    Dim RecvFile As File
    Dim SendFile As File
    Dim f As File

    Set Pkt.Key = m_SharedKey

    Select Case Pkt.Name
    Case NC_REGISTER
        ' Client.Register -> Server

    Case NC_UNREGISTER
        ' Client.Unregister -> Server

    Case NC_SETNAME
        m_PeerName = Pkt.XArg(1)
        If Pkt.Initiative Then SetName Pkt.Reply

    Case NC_SETKEY
        Set m_PeerKey = New AsymCrypto
        m_PeerKey.PublicKey = Pkt.XArg(1)
        If Pkt.Initiative Then
            SetKey Pkt.Reply
        Else
            ' When SetKey/Ack is received, set shared key
            SetSharedKey
        End If

    Case NC_SETSHAREDKEY
        Dim PeerSharedKey As String
        PeerSharedKey = m_Key.DecryptMessage(Pkt.XArg(1))
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

    Case NC_MESSAGE
        ' Do nothing in connection.

    Case NC_SCRIPT
        Dim ScriptLang As String
        Dim Script As String
        ScriptLang = Pkt.XArg(1)
        Script = Pkt.XArg(2)
        RunScript Script, ScriptLang

    Case NC_PUTFILE
        ' PutFile(long id, long size, long pkt_size, char[20], string fullname)
        ' Receive File
        Id = Pkt.XArg(1)

        If Pkt.Initiative Then
            ' I'm receiver
            Assert Pkt.Args >= 6

            Set RecvFile = New File
            RecvFile.RecvMode = True
            RecvFile.GUID = Id
            RecvFile.Checksum = Pkt.XArg(4)
            RecvFile.FullName = Pkt.XArg(5)
            RecvFile.Init Val(Pkt.XArg(2)), Val(Pkt.XArg(3))
            RecvFile.DeleteWhenCanceled = True

            RaiseEvent OnPreReceiveFile(RecvFile, Cancel)

            If Cancel Then
                ' RecvFile hasn't been added to m_Files, yet.
                RecvFile.Cancel
                SendCmd2 NC_PUTFILE, Id, "C", False, Pkt.Reply
                RaiseEvent OnFileCanceled(RecvFile)
            Else
                SendCmd2 NC_PUTFILE, Id, "A", False, Pkt.Reply
                Set m_Files.Item(RecvFile.GUID) = RecvFile
            End If
        Else
            ' I'm sender

            ' just ignore if the file is no longer be managed
            If Not m_Files.Contain(Id) Then Exit Sub

            Select Case Pkt.XArg(2)
            Case "A"
                ' Do nothing
            Case "C"
                Set f = m_Files.Item(Id)
                ' If the sender don't wait to fileinfo/Ack and sending data immediately
                ' after the fileinfo is sent, then this "entry lost" will notify the
                ' sender to stop sending the future data.
                m_Files.Remove Id
            End Select
        End If

    Case NC_PUTFILE_C
        Id = Pkt.XArg(1)
        If Not m_Files.Contain(Id) Then Exit Sub

        If Pkt.Initiative Then
            ' I'm receiver
            Select Case Pkt.XArg(2)
            Case "C"                    ' Cancel receiving
                Set RecvFile = m_Files.Item(Id)
                m_Files.Remove Id
                RecvFile.Cancel
                RaiseEvent OnFileCanceled(RecvFile)
            End Select
        Else
            ' Receiver send control to sender should using PUTFILE/Return method.
        End If

    Case NC_FILEPACKET
        ' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
        ' Receive File Packet
        Id = Pkt.XArg(1)

        ' Stop the sender if the file is no longer managed.
        If Not m_Files.Contain(Id) Then
            SendCmd2 NC_PUTFILE, Id, "C", False, Pkt.Reply
            Exit Sub
        End If

        Dim PktIndex As Long
        PktIndex = Val(Pkt.XArg(2))

        If Pkt.Initiative Then
            ' I'm receiver
            Set RecvFile = m_Files.Item(Id)

            Dim PktData() As Byte
            PktData = Pkt.BytesArg(5)
            If CalcChecksum(PktData) = Pkt.XArg(4) Then
                ' Packet OK
                ' (PktSize is ignored. )
                B = RecvFile.PutPacket(PktIndex, Pkt.Segment(5))
                ' Assert b
                RaiseEvent OnReceivingFile(RecvFile, Cancel)

                If Cancel Then
                    ' User canceled receiving, when packet ok
                    SendCmd2 NC_PUTFILE, Id, "C", False, Pkt.Reply
                End If
            Else
                ' Packet Checksum Error
                ' RecvFile.PacketStatus = pktReTransfer
                RaiseEvent OnReceivingFile(RecvFile, Cancel)

                If Cancel Then
                    ' User canceled receiving, when packet fail
                    SendCmd2 NC_PUTFILE, Id, "C", False, Pkt.Reply
                Else
                    ' Ask for Re-send this packet
                    SendCmd3 NC_FILEPACKET, Id, PktIndex, "R", False, Pkt.Reply
                End If
            End If
        Else
            ' I'm sender, process control code.
            Select Case Pkt.XArg(2)
            Case "A"    ' Packet Sent Completed
                Set SendFile = m_Files.Item(Id)
                ' Mark as sent
                SendFile.PacketStatus(PktIndex) = pktTransferred

                RaiseEvent OnSendingFile(SendFile, Cancel)

                If SendFile.Status = pktTransferred Then
                    m_Files.Remove Id
                    RaiseEvent OnSentFile(SendFile)
                End If

            Case "R"    ' Packet Failed, Re-Send
                Set SendFile = m_Files.Item(Id)
                ' Mark to re-send
                SendFile.PacketStatus(PktIndex) = pktQueued

                SendFilePackets SendFile

                RaiseEvent OnSendingFile(SendFile, Cancel)
            End Select

            If Cancel Then
                m_Files.Remove Id       ' The sending-loop may discover "entry lost"
                SendCmd2 NC_PUTFILE_C, Id, "C"
            End If
        End If

    Case NC_INVITE
        ' This should be happened to client,
        ' when Client.Invite -> Server, the Server should spawn a client-connection
        ' to connect back to the peer server in the source client.
    End Select
End Sub

' Class
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
    '
End Sub
