VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Globals"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Sub ShowResources(Optional ByVal Hidden As Boolean = False)
    Resources.Visible = Not Hidden
End Sub

Public Function XnetConnect(ByVal RemoteHost As String, _
                            Optional ByVal RemotePort As Integer = DEFAULT_PORT) As Client
    Set XnetConnect = GlobalsSingleton.XnetConnect(RemoteHost, RemotePort)
End Function

Public Property Get XnetCommands() As CommandsClient

End Property
