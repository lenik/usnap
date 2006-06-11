VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Network"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_Driver As ISocketDriver

Property Set Driver(ByVal newval As ISocketDriver)
    Assert Not newval Is Nothing
    Set m_Driver = newval
End Property

Public Function Bind(ByVal LocalAddress As String) As Server
    Dim s As New Server
    Set s.Driver = m_Driver
    If s.Bind(LocalAddress) Then
        Set Bind = s
    End If
End Function

Public Function Connect(ByVal RemoteAddress As String) As Client
    Dim c As New Client
    Set c.Driver = m_Driver
    If c.Connect(RemoteAddress) Then
        Set Connect = c
    End If
End Function

'Public Property Get Commands() As CommandsClient
    ' Not impl.
'End Property
