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

Private WithEvents m_Socket As Socket
Attribute m_Socket.VB_VarHelpID = -1

Private m_Name As String
Private m_PeerName As String
Private m_Key As KeyExchange
Private m_PeerKey As KeyExchange

Public Event OnPreRecvPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnRecvPacket(ByVal Pkt As Packet)

Public Event OnPreSendPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnSentPacket(ByVal Pkt As Packet)

Public Property Get Socket() As Socket
    Set Socket = m_Socket
End Property

Public Property Get LocalIP() As String
    LocalIP = m_Socket.LocalIP
End Property

Public Property Let LocalIP(ByVal newval As String)
    Assert False, "Not supported", LOCATION
    'm_Socket.LocalIP = newval
End Property

Public Property Get LocalPort() As Long
    LocalPort = m_Socket.LocalPort
End Property

Public Property Let LocalPort(ByVal newval As Long)
    m_Socket.LocalPort = newval
End Property

Public Property Get RemoteHost() As String
    RemoteHost = m_Socket.RemoteHost
End Property

Public Property Get RemoteHostIP() As String
    RemoteHostIP = m_Socket.RemoteHostIP
End Property

Public Property Get RemotePort() As Long
    RemotePort = m_Socket.RemotePort
End Property

Public Property Get User()
    If IsObject(m_Socket.User) Then
        Set User = m_Socket.User
    Else
        User = m_Socket.User
    End If
End Property

Public Property Let User(ByVal newval)
    m_Socket.User = newval
End Property

Public Property Set User(ByVal newval)
    Set m_Socket.User = newval
End Property

Public Property Get Tag() As String
    Tag = m_Socket.Tag
End Property

Public Property Let Tag(ByVal newval As String)
    m_Socket.Tag = newval
End Property

Public Sub Connect(ByVal RemoteHost As String, _
                   Optional ByVal RemotePort As Long = DEFAULT_PORT)
    m_Socket.Connect RemoteHost, RemotePort
End Sub

Public Sub Accept(ByVal requestID As Long)
    m_Socket.Accept requestID
End Sub

Public Sub SendPacket(ByVal Pkt As Packet)
    Assert Not Pkt Is Nothing
    Pkt.Send m_Socket
End Sub

Public Sub SendMessage(ByVal Message As String, _
                       Optional ByVal Encrypted As Boolean = False)

    SendPacket MakePacket(NC_MESSAGE, Message).Send
End Sub

Public Sub SetName(ByVal NewName As String)
    m_Name = NewName
End Sub

Public Sub SetKey(ByVal k As KeyExchange)
    Set m_Key = k
End Sub

Private Sub Class_Initialize()
    Set m_Socket = New Socket
End Sub
