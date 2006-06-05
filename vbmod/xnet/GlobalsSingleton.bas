Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public G As New Globals

Public Function XnetConnect(ByVal ServerHost As String, _
                            Optional ByVal ServerPort As Integer = DEFAULT_PORT) As Client
    Dim h As Long
'    Dim s As New Socket
'
'    s.Connect

    Dim Client As New Client
    'client.setsocket h,sd

    Set XnetConnect = Client
End Function
