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

' Id => MemberConnection
Private m_Connections As New VBExt.Map

' Base Events
' ----------------------------------------------------------------------------
Public Event OnPreConnect(ByVal RemoteAddress As String, ByRef Reject As Boolean)
Public Event OnConnect(ByVal c As Connection)
Public Event OnDisconnect(ByVal c As Connection, ByVal Reason As DisconnectReasonConstants)

Public Event OnPreSendPacket(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnSentPacket(ByVal c As Connection, ByVal Pkt As Packet)

Public Event OnPreRecvPacket(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnRecvPacket(ByVal c As Connection, ByVal Pkt As Packet)

Public Event OnPreReceiveFile(ByVal c As Connection, ByVal f As File, ByRef Cancel As Boolean)
Public Event OnReceivingFile(ByVal c As Connection, ByVal f As File, ByRef Cancel As Boolean)
Public Event OnReceivedFile(ByVal c As Connection, ByVal f As File)

Public Event OnSendingFile(ByVal c As Connection, ByVal f As File, ByRef Cancel As Boolean)
Public Event OnSentFile(ByVal c As Connection, ByVal f As File)

Public Event OnFileCanceled(ByVal c As Connection, ByVal f As File)

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

' Friend API
' ----------------------------------------------------------------------------
Property Set Driver(ByVal newval As ISocketDriver)
    Set m_Driver = newval
End Property

' see m_Driver.LastError if connect failed
Function Bind(ByVal LocalAddress As String) As Boolean
    Assert Not m_Driver Is Nothing, "Not Initialized", LOCATION

    Set m_ServerSocket = m_Driver.Bind(LocalAddress, Me)
    Bind = Not m_ServerSocket Is Nothing
End Function

Property Get MemberConnection(ByVal Id As Long) As MemberConnection
    ' ..
End Property

Property Get Connection(ByVal Id As Long) As Connection
    Set Connection = MemberConnection(Id).Delegant
End Property

Private Sub IServerEvents_Request(ByVal RemoteAddress As String, Reject As Boolean)
    RaiseEvent OnPreConnect(RemoteAddress, Reject)
End Sub

Private Sub IServerEvents_Connect(ByVal Id As Long, Data As Variant)
    Dim ch As New ServerChannel
    ch.Init m_ServerSocket, Id

    Dim c As New Connection
    Set c.Channel = New ServerChannel
    c.Address = m_ServerSocket.LocalAddress
    c.PeerAddress = m_ServerSocket.RemoteAddress(Id)

    Dim mc As New MemberConnection
    Set mc.Delegant = c
    Set mc.EventSink = Me

    Set m_Connections(Id) = mc

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
        Assert Not Pkt.Initiative
        RaiseEvent OnRegistered(c)
    Case NC_UNREGISTER
        Assert Not Pkt.Initiative
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
        RaiseEvent OnMessage(c, Pkt.XArg(1))
    Case NC_SYSTEM
        RaiseEvent OnSystem(c, Pkt)
    End Select
End Sub

Private Sub IServerEvents_RecvBytes(ByVal Id As Long, Bytes() As Byte, UnrecvBytes As Long)
    Dim mc As MemberConnection
    Set mc = MemberConnection(Id)
    Assert Not mc Is Nothing, "Connection Lost", LOCATION

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

Private Sub ConnectionEvents_OnPreSendPacket(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)
    RaiseEvent OnPreSendPacket(c, Pkt, Cancel)
End Sub
Private Sub ConnectionEvents_OnSentPacket(ByVal c As Connection, ByVal Pkt As Packet)
    RaiseEvent OnSentPacket(c, Pkt)
End Sub

Private Sub ConnectionEvents_OnPreReceiveFile(ByVal c As Connection, ByVal f As File, ByRef Cancel As Boolean)
    RaiseEvent OnPreReceiveFile(c, f, Cancel)
End Sub
Private Sub ConnectionEvents_OnReceivingFile(ByVal c As Connection, ByVal f As File, ByRef Cancel As Boolean)
    RaiseEvent OnReceivingFile(c, f, Cancel)
End Sub
Private Sub ConnectionEvents_OnReceivedFile(ByVal c As Connection, ByVal f As File)
    RaiseEvent OnReceivedFile(c, f)
End Sub

Private Sub ConnectionEvents_OnSendingFile(ByVal c As Connection, ByVal f As File, ByRef Cancel As Boolean)
    RaiseEvent OnSendingFile(c, f, Cancel)
End Sub
Private Sub ConnectionEvents_OnSentFile(ByVal c As Connection, ByVal f As File)
    RaiseEvent OnSentFile(c, f)
End Sub

Private Sub ConnectionEvents_OnFileCanceled(ByVal c As Connection, ByVal f As File)
    RaiseEvent OnFileCanceled(c, f)
End Sub
