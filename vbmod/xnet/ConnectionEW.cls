VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ConnectionEW"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private WithEvents m_Connection As Connection
Attribute m_Connection.VB_VarHelpID = -1
Private m_ConnectionEvents As ConnectionEvents

' m_Connection Wrappers
' ----------------------------------------------------------------------------
Public Property Get Socket() As IClientSocket
    Set Socket = m_Connection.Socket
End Property

Public Property Get LocalHost() As String
    LocalHost = m_Connection.LocalHost
End Property

Public Property Let LocalHost(ByVal newval As String)
    m_Connection.LocalHost = newval
End Property

Public Property Get LocalPort() As Long
    LocalPort = m_Connection.LocalPort
End Property

Public Property Let LocalPort(ByVal newval As Long)
    m_Connection.LocalPort = newval
End Property

Public Property Get ServerHost() As String
    ServerHost = m_Connection.ServerHost
End Property

Public Property Get ServerHostIP() As String
    ServerHostIP = m_Connection.ServerHostIP
End Property

Public Property Get ServerPort() As Long
    ServerPort = m_Connection.ServerPort
End Property

Public Property Get User()
    If IsObject(m_Connection.User) Then
        Set User = m_Connection.User
    Else
        User = m_Connection.User
    End If
End Property

Public Property Get Tag() As String
    Tag = m_Connection.Tag
End Property

Public Property Let Tag(ByVal newval As String)
    m_Connection.Tag = newval
End Property

Public Property Let User(ByVal newval)
    m_Connection.User = newval
End Property

Public Property Set User(ByVal newval)
    Set m_Connection.User = newval
End Property

' Connection Attributes
' ----------------------------------------------------------------------------
Public Property Get Name() As String
    Name = m_Connection.Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Connection.Name = newval
End Property

Public Property Get PeerName() As String
    PeerName = m_Connection.PeerName
End Property

Public Property Get Key() As AsymCrypto
    Set Key = m_Connection.Key
End Property

Public Property Set Key(ByVal newval As AsymCrypto)
    m_Connection.Key = newval
End Property

Public Property Get PeerKey() As AsymCrypto
    Set PeerKey = m_Connection.PeerKey
End Property

Public Property Get SharedKey() As String
    SharedKey = m_Connection.SharedKey
End Property

Public Property Let SharedKey(ByVal newval As String)
    m_Connection.SharedKey = newval
End Property

' Made Connection
' ----------------------------------------------------------------------------
Public Sub Connect(ByVal ServerHost As String, _
                   Optional ByVal ServerPort As Long = DEFAULT_PORT)
    m_Connection.Connect ServerHost, ServerPort
End Sub

Public Sub Accept(ByVal requestID As Long)
    m_Connection.Accept requestID
End Sub

' Sending
' ----------------------------------------------------------------------------
Public Sub SendPacket(ByVal Pkt As Packet)
    m_Connection.SendPacket Pkt
End Sub

Public Sub SendMessage(ByVal Message As String, _
                       Optional ByVal Encrypted As Boolean = False)
    m_Connection.SendMessage Message, Encrypted
End Sub

' Interface
' ----------------------------------------------------------------------------
Public Sub Initialize(ByVal ConnectionEvents As ConnectionEvents)
    Set m_ConnectionEvents = ConnectionEvents
End Sub

Private Sub Class_Initialize()
    Set m_Connection = New Connection
End Sub

Private Sub m_Connection_OnConnect()
    m_ConnectionEvents.OnConnect
End Sub

Private Sub m_Connection_OnDisconnect()
    m_ConnectionEvents.OnDisconnect
End Sub

Private Sub m_Connection_OnPreRecvPacket(ByVal Pkt As Packet, Cancel As Boolean)
    m_ConnectionEvents.OnPreRecvPacket Pkt, Cancel
End Sub

Private Sub m_Connection_OnPreSendPacket(ByVal Pkt As Packet, Cancel As Boolean)
    m_ConnectionEvents.OnPreSendPacket Pkt, Cancel
End Sub

Private Sub m_Connection_OnRecvPacket(ByVal Pkt As Packet)
    m_ConnectionEvents.OnRecvPacket Pkt
End Sub

Private Sub m_Connection_OnSentPacket(ByVal Pkt As Packet)
    m_ConnectionEvents.OnSentPacket Pkt
End Sub
