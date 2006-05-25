Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public g_Cached As New Cached

Public PF As New PathFunctions

Public BU As New BinaryUtilities

Public Function GetErrorString(ByVal e As Long) As String
    Dim Buffer As String * 1024
    Dim l As Long
    l = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, e, 0, Buffer, 1024, 0)

    Dim z As Long
    z = InStr(Buffer, Chr(0))
    If z > 0 Then
        GetErrorString = Left(Buffer, z - 1)
    Else
        GetErrorString = Buffer
    End If
End Function
