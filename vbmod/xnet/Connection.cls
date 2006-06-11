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

Private m_Socket As IClientSocket
Attribute m_Socket.VB_VarHelpID = -1

Private m_Name As String
Private m_PeerName As String
Private m_Key As New AsymCrypto
Private m_PeerKey As AsymCrypto
Private m_SharedKey As New SymCrypto

Private m_PeerTZOffset As Double        ' RemoteTime - LocalTime

' All files, GUID -> File
Private m_Files As New VBExt.Map

Public Event OnConnect()
Public Event OnDisconnect(ByVal Reason As DisconnectReasonConstants)

Public Event OnPreRecvPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnRecvPacket(ByVal Pkt As Packet)

Public Event OnPreSendPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnSentPacket(ByVal Pkt As Packet)

'Implements IClientEvents

' m_Socket Wrappers
' ----------------------------------------------------------------------------
Public Property Get Socket() As IClientSocket
    Set Socket = m_Socket
End Property

Public Property Get LocalHost() As String
    'LocalHost = m_Socket.LocalHost
End Property

Public Property Let LocalHost(ByVal newval As String)
    Assert False, "Not supported", LOCATION
    'm_Socket.LocalHost = newval
End Property

Public Property Get LocalPort() As Long
    'LocalPort = m_Socket.LocalPort
End Property

Public Property Let LocalPort(ByVal newval As Long)
    'm_Socket.LocalPort = newval
End Property

Public Property Get ServerHost() As String
    'ServerHost = m_Socket.ServerHost
End Property

Public Property Get ServerHostIP() As String
    'ServerHostIP = m_Socket.ServerHostIP
End Property

Public Property Get ServerPort() As Long
    'ServerPort = m_Socket.ServerPort
End Property

Public Property Get User()
'    If IsObject(m_Socket.User) Then
'        Set User = m_Socket.User
'    Else
'        User = m_Socket.User
'    End If
End Property

Public Property Get Tag() As String
'    Tag = m_Socket.Tag
End Property

Public Property Let Tag(ByVal newval As String)
'    m_Socket.Tag = newval
End Property

Public Property Let User(ByVal newval)
'    m_Socket.User = newval
End Property

Public Property Set User(ByVal newval)
'    Set m_Socket.User = newval
End Property

' Connection Attributes
' ----------------------------------------------------------------------------
Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Name = newval
    SendPacket MakePacket(NC_SETNAME, False, 0, newval)
End Property

Public Property Get PeerName() As String
    PeerName = m_PeerName
End Property

Public Property Get Key() As AsymCrypto
    Set Key = m_Key
End Property

Public Property Set Key(ByVal newval As AsymCrypto)
    Assert Not newval Is Nothing
    Set m_Key = newval
    SendPacket MakePacket(NC_SETKEY, False, 0, newval.PublicKey)
End Property

Public Property Get PeerKey() As AsymCrypto
    Set PeerKey = m_PeerKey
End Property

Public Property Get SharedKey() As String
    SharedKey = m_SharedKey.Key
End Property

Public Property Let SharedKey(ByVal newval As String)
    m_SharedKey.Key = newval
    If m_PeerKey Is Nothing Then
        Set Key = m_Key
    Else
        SendPacket MakePacket(NC_SETSESSIONKEY, False, 0, _
                              m_PeerKey.EncryptMessage(newval))
    End If
End Property

' Made Connection
' ----------------------------------------------------------------------------
Public Sub Connect(ByVal ServerHost As String, _
                   Optional ByVal ServerPort As Long = DEFAULT_PORT)
'    m_Socket.AutoMode = amConnect       ' XXX
    m_Socket.Connect ServerHost, ServerPort
End Sub

Public Sub Accept(ByVal requestID As Long)
'    m_Socket.AutoMode = amClose         ' XXX
'    m_Socket.Accept requestID
End Sub

' Sending
' ----------------------------------------------------------------------------

Public Sub SendPacket(ByVal Pkt As Packet)
    Assert Not Pkt Is Nothing

    Dim Cancel As Boolean
    RaiseEvent OnPreSendPacket(Pkt, Cancel)
    If Cancel Then Exit Sub

    Pkt.Send m_Socket

    RaiseEvent OnSentPacket(Pkt)
End Sub

Public Sub SendSimplePacket(ByVal CmdName As String, Optional ByVal Param0 As String, _
                            Optional ByVal Encrypted As Boolean = False, _
                            Optional ByVal Sequence As Long = 0)
    Dim Pkt As Packet
    If IsMissing(Param0) Then
        Set Pkt = MakePacket(CmdName, Encrypted, Sequence, Param0)
    Else
        Set Pkt = MakePacket(CmdName, Encrypted, Sequence, Param0)
    End If
    If Encrypted Then Set Pkt.Key = m_SharedKey
    SendPacket Pkt
End Sub

Public Sub Register()
    SendSimplePacket NC_REGISTER
End Sub

Public Sub Unregister()
    SendSimplePacket NC_UNREGISTER
End Sub

Public Sub SendSysCmd(ByVal SysId As Long, _
                      Optional ByVal Parameter, _
                      Optional ByVal Encrypted As Boolean = False)
    Dim Pkt As Packet
    If IsMissing(Parameter) Then
        Set Pkt = MakePacket(NC_SYSTEM, Encrypted, 0, SysId)
    Else
        Set Pkt = MakePacket(NC_SYSTEM, Encrypted, 0, SysId, Parameter)
    End If
    If Encrypted Then Set Pkt.Key = m_SharedKey
    SendPacket Pkt
End Sub

Public Sub SendTouch()
    SendSimplePacket NC_TOUCH
End Sub

Public Sub SendMessage(ByVal Message As String, _
                       Optional ByVal Encrypted As Boolean = False)
    SendSimplePacket NC_MESSAGE, Message, Encrypted
End Sub

Public Sub SendScript(ByVal Script As String, _
                      Optional ByVal Language As String = "javascript", _
                      Optional ByVal Encrypted As Boolean = False)
    Dim Pkt As Packet
    Set Pkt = MakePacket(NC_SCRIPT, Encrypted, 0, Language, Script)
    If Encrypted Then Set Pkt.Key = m_SharedKey
    SendPacket Pkt
End Sub

Public Sub SendFile(ByVal f As File, _
                    Optional ByVal Encrypted As Boolean = False)
    Dim i As Long

    SendPutFile f, Encrypted

    For i = 0 To f.Packets - 1
        SendFilePacket f, i, Encrypted
    Next
End Sub

Public Function ResumeFiles(ByVal SendFilesXML As String) As Boolean
    Dim Doc As New DOMDocument
    Dim SessionAttribute As String
    Dim Segs

    If Not Doc.loadXML(SendFilesXML) Then Exit Function

    Dim elmSendFiles As IXMLDOMElement
    Set elmSendFiles = Doc.childNodes(0)

    SessionAttribute = elmSendFiles.getAttribute("session")
    Segs = Split(SessionAttribute, ":")
    Assert (UBound(Segs) - LBound(Segs) + 1) >= 2, _
           "session attribute should be in format name:key", LOCATION

    Name = Base64ToString(Segs(0))
    SharedKey = Base64ToString(Segs(1))

    Dim elmFile As IXMLDOMElement
    Dim elmStatus As PacketStatusConstants
    Dim i As Integer
    For i = 0 To elmSendFiles.childNodes.length - 1
        Set elmFile = elmSendFiles.childNodes(i)
        elmStatus = Val(elmFile.getAttribute("status"))
        If elmStatus <> pktTransferred Then
            Dim f As New File
            f.FullName = elmFile.getAttribute("fullname")
            f.Path = elmFile.getAttribute("path")

            SendFile f
        End If
    Next
End Function

Private Sub SendPutFile(ByVal f As File, Optional ByVal Encrypted As Boolean = False)
    Dim Pkt As Packet
    ' FileInfo(long id, long size, long pkt_size, char[20], string, fullname)
    Set Pkt = MakePacket(NC_PUTFILE, Encrypted, 0, _
                         f.GUID, f.Size, f.PacketSize, f.Checksum, f.FullName)
    If Encrypted Then Set Pkt.Key = m_SharedKey
    SendPacket Pkt
End Sub

Private Sub SendFilePacket(ByVal f As File, ByVal PacketIndex As Long, _
                          Optional ByVal Encrypted As Boolean = False)
    Dim Pkt As Packet
    Dim PacketSize As Long
    Dim PacketData
    Dim PacketChk As Long

    PacketSize = f.GetPacketSize(PacketIndex)
    PacketData = f.GetPacketData(PacketIndex)
    PacketChk = CalcChecksum(PacketData)

    ' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
    Set Pkt = MakePacket(NC_FILEPACKET, Encrypted, 0, _
                         f.GUID, PacketIndex, PacketSize, PacketChk, PacketData)

    If Encrypted Then Set Pkt.Key = m_SharedKey
    SendPacket Pkt
End Sub

Public Sub SendInvite()
    SendSimplePacket NC_INVITE
End Sub

Friend Sub ProcessPacket(ByVal Pkt As Packet)
    Dim fid As String
    Dim f As File

    Select Case Pkt.Name
    Case NC_REGISTER
        ' Client.Register -> Server
    Case NC_UNREGISTER
        ' Client.Unregister -> Server
    Case NC_SETNAME
        m_PeerName = Pkt.Arg(0)
        If Pkt.Initiative Then
            SendSimplePacket NC_SETNAME, m_Name, False, Pkt.Reply
        End If
    Case NC_SETKEY
        Set m_PeerKey = New AsymCrypto
        m_PeerKey.PublicKey = Pkt.Arg(1)
        If Pkt.Initiative Then
            SendSimplePacket NC_SETKEY, m_Key.PublicKey, False, Pkt.Reply
        End If
    Case NC_SETSESSIONKEY
        m_SharedKey.Key = Pkt.Arg(1)
    Case NC_MESSAGE
        '
    Case NC_SCRIPT
        RunScript Pkt.Arg(1)
    Case NC_PUTFILE
        ' PutFile(long id, long size, long pkt_size, char[20], string fullname)
        ' Assert Pkt.ParametersCount >= 5
        If Pkt.Args >= 5 Then
            Set f = New File
           ' f.GUID = Pkt.Parameter(0)
           ' f.Checksum = Pkt.Parameter(3)
           ' f.FullName = Pkt.Parameter(4)
            ' Size, PacketSize
           ' f.Init Val(Pkt.Parameter(1)), Val(Pkt.Parameter(2))
        End If
    Case NC_CANCEL
        ' Cancel(long id)
        '
    Case NC_FILEPACKET
        ' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
        '
    Case NC_INVITE
        ' This should be happened to client,
        ' when Client.Invite -> Server, the Server should spawn a client-connection
        ' to connect back to the peer server in the source client.
    End Select
End Sub

' Impl.
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
'    Set m_Socket = New Socket
End Sub

Private Sub IClientEvents_Connect()
    RaiseEvent OnConnect
    Register
    Name = m_Name
    Key = m_Key
    SharedKey = m_SharedKey
    SendTouch
End Sub

Private Sub IClientEvents_Disconnect(ByVal Reason As DisconnectReasonConstants)
    RaiseEvent OnDisconnect(Reason)
    ' ??
    ' Unregister
End Sub

Private Sub IClientEvents_RecvBytes(Bytes() As Byte, UnrecvBytes As Long)
    Dim Pkt As Packet
    Dim Cancel As Boolean

    Set Pkt = ParsePacket(Bytes)

    RaiseEvent OnPreRecvPacket(Pkt, Cancel)
    If Cancel Then Exit Sub

    ProcessPacket Pkt

    RaiseEvent OnRecvPacket(Pkt)
End Sub

'Private Sub IClientEvents_SentBytes(Bytes() As Byte, ByVal PartialId As Long, ByVal PartialStart As Long, ByVal PartialSize As Long)
'End Sub
