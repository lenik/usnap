Attribute VB_Name = "Utils"
Option Explicit

Private m_TempPath As String

Public Sub Main()
    Startup
End Sub

Public Sub Startup()
    Dim buffer As String * 256
    Dim l As Long
    l = GetTempPath(256, buffer)
    m_TempPath = SzTrim(buffer)
End Sub

Public Function GetTemp(Optional ByVal Prefix As String = "iox") As String
    Dim buffer As String * 256
    Dim l As Long
    l = GetTempFileName(m_TempPath, Prefix, 0, buffer)
    GetTemp = SzTrim(buffer)
End Function

Public Function SzTrim(ByVal str As String) As String
    Dim i As Long
    i = InStr(str, Chr(0))
    If i > 0 Then
        SzTrim = Left(str, i - 1)
    Else
        SzTrim = str
    End If
End Function
