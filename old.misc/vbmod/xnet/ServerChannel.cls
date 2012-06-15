VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ServerChannel"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::ServerChannel"

Private m_ServerSocket As IServerSocket
Private m_ClientId As Long

Implements Channel

Sub Init(ByVal ServerSocket As IServerSocket, ByVal ClientId As Long)
    Set m_ServerSocket = ServerSocket
    m_ClientId = ClientId
End Sub

Private Sub CheckId()
    ' if not (m_ClientId in m_ServerSocket.Clients ) then ...
End Sub

Private Sub Channel_SendBytes(Bytes() As Byte, Optional ByVal Offset As Long = 0&, Optional ByVal Size As Long = -1&, Optional ByVal PartialId As Long = -1&, Optional ByVal Async As Boolean = False)
    Assert Not m_ServerSocket Is Nothing, "Not Initialized", LOCATION
    CheckId
    m_ServerSocket.SendBytes m_ClientId, Bytes, Offset, Size, PartialId, Async
End Sub

Private Property Get Channel_SentBytes() As Long
    Assert Not m_ServerSocket Is Nothing, "Not Initialized", LOCATION
    CheckId
    Channel_SentBytes = m_ServerSocket.SentBytes(m_ClientId)
End Property

Private Property Get Channel_UnsentBytes() As Long
    Assert Not m_ServerSocket Is Nothing, "Not Initialized", LOCATION
    CheckId
    Channel_UnsentBytes = m_ServerSocket.UnsentBytes(m_ClientId)
End Property

Private Sub Channel_ForgetSent()
    Assert Not m_ServerSocket Is Nothing, "Not Initialized", LOCATION
    CheckId
    m_ServerSocket.ForgetSent m_ClientId
End Sub
