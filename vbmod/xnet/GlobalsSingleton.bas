Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public Function XnetConnect(ByVal RemoteHost As String, _
                            Optional ByVal RemotePort As Integer = DEFAULT_PORT) As Client
    Dim h As Long
'    Dim s As New Socket
'
'    s.Connect

    Dim Client As New Client
    'client.setsocket h,sd

    Set XnetConnect = Client
End Function
