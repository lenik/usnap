VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ClientChannel"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::ClientChannel"

Private m_ClientSocket As IClientSocket

Implements Channel

Sub Init(ByVal ClientSocket As IClientSocket)
    Set m_ClientSocket = ClientSocket
End Sub

Private Sub Channel_SendBytes(Bytes() As Byte, Optional ByVal Offset As Long = 0&, Optional ByVal Size As Long = -1&, Optional ByVal PartialId As Long = -1&, Optional ByVal Async As Boolean = False)
    Assert Not m_ClientSocket Is Nothing, "Not Initialized", LOCATION
    m_ClientSocket.SendBytes Bytes, Offset, Size, PartialId, Async
End Sub

Private Property Get Channel_SentBytes() As Long
    Assert Not m_ClientSocket Is Nothing, "Not Initialized", LOCATION
    Channel_SentBytes = m_ClientSocket.SentBytes
End Property

Private Property Get Channel_UnsentBytes() As Long
    Assert Not m_ClientSocket Is Nothing, "Not Initialized", LOCATION
    Channel_UnsentBytes = m_ClientSocket.UnsentBytes
End Property

Private Sub Channel_ForgetSent()
    Assert Not m_ClientSocket Is Nothing, "Not Initialized", LOCATION
    m_ClientSocket.ForgetSent
End Sub
