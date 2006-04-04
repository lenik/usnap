Attribute VB_Name = "Utils"
Option Explicit

Public g_Builder As New Builder

Public Function InCharset(ByVal Message As String, ByVal CHARSET As String) As Boolean
    Dim l As Integer
    Dim i As Integer
    l = Len(Message)
    For i = 1 To l
        If InStr(CHARSET, Mid(Message, i, 1)) <= 0 Then Exit Function
    Next
    InCharset = True
End Function

Public Function At(ByVal str As String, ByVal i As Integer) As String
    At = Mid(str, i + 1, 1)
End Function
