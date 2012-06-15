VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Server"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::Server"

Private m_Driver As ISocketDriver
Private m_ServerSocket As IServerSocket

Private m_Name As String

' Id => MemberConnection
Private m_MC As New VBExt.Map

' Base Events
' ----------------------------------------------------------------------------
Public Event OnPreConnect(ByVal RemoteAddress As String, ByRef Reject As Boolean)
Public Event OnConnect(ByVal c As Connection)
Public Event OnDisconnect(ByVal c As Connection, ByVal Reason As DisconnectReasonConstants)

Public Event OnPreSendPacket(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnSentPacket(ByVal c As Connection, ByVal Pkt As Packet)
Public Event OnPreRecvPacket(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnRecvPacket(ByVal c As Connection, ByVal Pkt As Packet)
Public Event OnUnknownPacket(ByVal c As Connection, ByVal Pkt As Packet)

Public Event OnPreReceiveFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnReceivingFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnReceivingFileError(ByVal c As Connection, ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)
Public Event OnReceivedFile(ByVal c As Connection, ByVal f As Xnet.File)

Public Event OnSendingFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnSendingFileError(ByVal c As Connection, ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)
Public Event OnSentFile(ByVal c As Connection, ByVal f As Xnet.File)

Public Event OnFileHashing(ByVal c As Connection, ByVal f As Xnet.File, ByVal ProcessedSize As Long)
Public Event OnFileCanceled(ByVal c As Connection, ByVal f As Xnet.File)

' Protocol Events
' ----------------------------------------------------------------------------

' Register-ID is LocalAddress/Port
Public Event OnRegistered(ByVal c As Connection)
Public Event OnUnregistered(ByVal c As Connection)

Public Event OnSetName(ByVal c As Connection, ByVal PeerName As String)
Public Event OnSetKey(ByVal c As Connection)
Public Event OnSetSharedKey(ByVal c As Connection)
Public Event OnTouch(ByVal c As Connection)
Public Event OnMessage(ByVal c As Connection, ByVal Message As String)
Public Event OnSystem(ByVal c As Connection, ByVal Pkt As Packet)
Public Event OnGet(ByVal c As Connection, ByVal URI As String, ByRef Response As String)

Implements IServerEvents
Implements ConnectionEvents

' Exported
' ----------------------------------------------------------------------------
Public Property Get Connections() As Long
    Connections = m_ServerSocket.Clients
End Property

Public Property Get ConnectionId(ByVal Index As Long) As Long
    Dim Id As Long
    Id = m_ServerSocket.ClientId(Index)

    ' The client is removed, the member-connection should be removed, too
    ' Assert Not m_MC.Contain(Id)
    If Not m_MC.Contain(Id) Then Id = -1

    ConnectionId = Id
End Property

Public Property Get Connection(ByVal Id As Long) As Connection
    Assert Id >= 0, "Invalid Client Id", LOCATION
    Dim mc As MemberConnection
    Set mc = m_MC.Item(Id)
    If Not mc Is Nothing Then
        Set Connection = mc.Delegant
    End If
End Property

Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Let Name(ByVal Name As String)
    m_Name = Name
End Property

Public Sub Shutdown()
    Dim i As Long
    Dim Id As Long
    For i = m_ServerSocket.Clients - 1 To 0 Step -1
        Id = m_ServerSocket.ClientId(i)
        m_ServerSocket.Disconnect Id
    Next
    m_ServerSocket.Unbind
End Sub

' Friend API
' ----------------------------------------------------------------------------
Friend Property Set Driver(ByVal newval As ISocketDriver)
    Set m_Driver = newval
End Property

' see m_Driver.LastError if connect failed
Friend Function Bind(ByVal LocalAddress As String) As Boolean
    Assert Not m_Driver Is Nothing, "Not Initialized", LOCATION

    Set m_ServerSocket = m_Driver.Bind(LocalAddress, Me)
    Bind = Not m_ServerSocket Is Nothing
End Function

Friend Property Get MemberConnection(ByVal Id As Long) As MemberConnection
    ' Assert m_ServerSocket.ClientId(Id) <> -1
    If m_ServerSocket.ClientId(Id) = -1 Then Exit Property

    If m_MC.Contain(Id) Then
        Set MemberConnection = m_MC.Item(Id)
    End If
End Property

' IServerEvents
' ----------------------------------------------------------------------------
Private Sub IServerEvents_Request(ByVal RemoteAddress As String, Reject As Boolean)
    RaiseEvent OnPreConnect(RemoteAddress, Reject)
End Sub

Private Sub IServerEvents_Connect(ByVal Id As Long, Data As Variant)
    Dim ch As New ServerChannel
    ch.Init m_ServerSocket, Id

    Dim c As New Connection
    Set c.Channel = ch
    c.Name = m_Name
    c.Address = m_ServerSocket.LocalAddress
    c.PeerAddress = m_ServerSocket.RemoteAddress(Id)

    Dim mc As New MemberConnection
    Set mc.Delegant = c
    Set mc.EventSink = Me

    Set m_MC(Id) = mc

    RaiseEvent OnConnect(c)
End Sub

Private Sub IServerEvents_Disconnect(ByVal Id As Long, ByVal Reason As DisconnectReasonConstants, Data As Variant)
    Dim c As Connection
    Set c = Connection(Id)
    Assert Not c Is Nothing, "Connection Lost", LOCATION
    RaiseEvent OnDisconnect(c, Reason)
End Sub

Private Sub PreProcess(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
    ' Do Nothing.
End Sub

Private Sub PostProcess(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
    Select Case Pkt.Name
    Case NC_REGISTER
        Assert Pkt.Initiative
        RaiseEvent OnRegistered(c)
    Case NC_UNREGISTER
        Assert Pkt.Initiative
        RaiseEvent OnUnregistered(c)
    Case NC_SETNAME
        RaiseEvent OnSetName(c, c.PeerName)
    Case NC_SETKEY
        RaiseEvent OnSetKey(c)
    Case NC_SETSHAREDKEY
        RaiseEvent OnSetSharedKey(c)
    Case NC_TOUCH
        RaiseEvent OnTouch(c)
    Case NC_MESSAGE
        RaiseEvent OnMessage(c, Pkt.XArg(0))
    Case NC_SYSTEM
        RaiseEvent OnSystem(c, Pkt)
    End Select
End Sub

Private Sub IServerEvents_RecvBytes(ByVal Id As Long, Bytes() As Byte, UnrecvBytes As Long)
    Dim mc As MemberConnection
    Set mc = MemberConnection(Id)

    ' Just break the communication if the mc is removed.
    ' Assert Not mc Is Nothing, "Connection Lost", LOCATION
    If mc Is Nothing Then Exit Sub

    Dim c As Connection
    Set c = mc.Delegant

    Dim Pkt As Packet
    Dim Cancel As Boolean

    mc.Buffer.AddBytes Bytes
    While mc.Buffer.PacketReady
        Set Pkt = mc.Buffer.NextPacket

        Cancel = False
        RaiseEvent OnPreRecvPacket(c, Pkt, Cancel)
        If Not Cancel Then
            PreProcess c, Pkt, Cancel
            If Not Cancel Then
                c.RecvPacket Pkt
                PostProcess c, Pkt, Cancel
                If Not Cancel Then
                    RaiseEvent OnRecvPacket(c, Pkt)
                End If
            End If
        End If
    Wend
End Sub

Private Sub IServerEvents_SentBytes(ByVal Id As Long, ByVal Size As Long, ByVal PartialId As Long, ByVal PartialOffset As Long, ByVal PartialRemain As Long)
    ' The Xnet protocol is designed for support UDP small packets,
    ' so this progress info is not used.
End Sub

' ConnectionEvents Wrappers
' ----------------------------------------------------------------------------
Private Sub ConnectionEvents_OnPreSendPacket(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
    RaiseEvent OnPreSendPacket(c, Pkt, Cancel)
End Sub
Private Sub ConnectionEvents_OnSentPacket(ByVal c As Connection, ByVal Pkt As Packet)
    RaiseEvent OnSentPacket(c, Pkt)
End Sub
Private Sub ConnectionEvents_OnUnknownPacket(ByVal c As Connection, ByVal Pkt As Packet)
    RaiseEvent OnUnknownPacket(c, Pkt)
End Sub

Private Sub ConnectionEvents_OnPreReceiveFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)
    RaiseEvent OnPreReceiveFile(c, f, Cancel)
End Sub
Private Sub ConnectionEvents_OnReceivingFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)
    RaiseEvent OnReceivingFile(c, f, Cancel)
End Sub
Private Sub ConnectionEvents_OnReceivingFileError(ByVal c As Connection, ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)
    RaiseEvent OnReceivingFileError(c, f, ErrId, Cancel)
End Sub
Private Sub ConnectionEvents_OnReceivedFile(ByVal c As Connection, ByVal f As Xnet.File)
    RaiseEvent OnReceivedFile(c, f)
End Sub

Private Sub ConnectionEvents_OnSendingFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)
    RaiseEvent OnSendingFile(c, f, Cancel)
End Sub
Private Sub ConnectionEvents_OnSendingFileError(ByVal c As Connection, ByVal f As Xnet.File, ByVal ErrId As Long, Cancel As Boolean)
    RaiseEvent OnSendingFileError(c, f, ErrId, Cancel)
End Sub
Private Sub ConnectionEvents_OnSentFile(ByVal c As Connection, ByVal f As Xnet.File)
    RaiseEvent OnSentFile(c, f)
End Sub

Private Sub ConnectionEvents_OnFileHashing(ByVal c As Connection, ByVal f As Xnet.File, ByVal ProcessedSize As Long)
    RaiseEvent OnFileHashing(c, f, ProcessedSize)
End Sub
Private Sub ConnectionEvents_OnFileCanceled(ByVal c As Connection, ByVal f As Xnet.File)
    RaiseEvent OnFileCanceled(c, f)
End Sub

' Class
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
    m_Name = Secret
End Sub
