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

Public Event OnPreConnect(ByVal RemoteAddress As String, ByRef Reject As Boolean)
Public Event OnConnect()
Public Event OnDisconnect(ByVal Reason As DisconnectReasonConstants)

Implements IServerEvents

Property Set Driver(ByVal newval As ISocketDriver)
    Set m_Driver = newval
End Property

Function Bind(ByVal LocalAddress As String) As Boolean
    Assert Not m_Driver Is Nothing, "Not Initialized", LOCATION

    Set m_ServerSocket = m_Driver.Bind(LocalAddress, Me)
    Bind = Not m_ServerSocket Is Nothing
End Function

Private Sub IServerEvents_Request(ByVal RemoteAddress As String, Reject As Boolean)
    RaiseEvent OnPreConnect(RemoteAddress, Reject)
End Sub

Private Sub IServerEvents_Connect(ByVal Id As Long, Data As Variant)

End Sub

Private Sub IServerEvents_Disconnect(ByVal Id As Long, ByVal Reason As DisconnectReasonConstants, Data As Variant)

End Sub

Private Sub IServerEvents_RecvBytes(ByVal Id As Long, Bytes() As Byte, UnrecvBytes As Long)

End Sub

Private Sub IServerEvents_SentBytes(ByVal Id As Long, ByVal Size As Long, ByVal PartialId As Long, ByVal PartialOffset As Long, ByVal PartialRemain As Long)

End Sub
