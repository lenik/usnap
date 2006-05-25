Attribute VB_Name = "TestBF"
Option Explicit

Public Sub TA()
    Dim Path As String
    Dim bf As New BinaryFile
    Dim s As String
    s = "<CR" & vbCr & "LF" & vbLf & "CRLF" & vbCrLf & "END" & Chr(0) & ">"

    Path = "X:\testappend"
    If FSO.FileExists(Path) Then
        FSO.DeleteFile Path, True
        Assert Not FSO.FileExists(Path)
    End If

    'On Error GoTo X
    Assert bf.Open_(Path, amAppend)
    Assert bf.Write_(BU.StringToBytes("BytesA" & s))
    Assert bf.Close_

    Assert bf.Open_(Path, amAppend)
    Assert bf.WriteString("StringA" & s)
    Assert bf.Close_

    Assert bf.Open_(Path, amAppend)
    Assert bf.WriteStringB("StringB" & s)
    Assert bf.Close_

    Exit Sub
X:
    MsgBox bf.LastError
End Sub
