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


Public Function XnetConnect(ByVal RemoteHost As String, _
                            Optional ByVal RemotePort As Integer = DEFAULT_PORT) As Client
    Dim h As Long
    Dim s As New Socket

    s.Connect

    Dim Client As New Client
    'client.setsocket h,sd

    Set XnetConnect = Client

End Function
