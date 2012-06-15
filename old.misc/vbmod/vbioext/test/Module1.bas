Attribute VB_Name = "Module1"
Option Explicit

Public Function tt1() As String

    Dim b1() As Byte
    Dim b2() As Byte
    b1 = StrConv("Hello,world", vbFromUnicode)
    b2 = StrConv("ÄãºÃ£¬ÖÐ¹ú", vbFromUnicode)

    bytscpy b2, 2, b1, 0, 4

    tt1 = StrConv(b2, vbUnicode)
End Function

Public Sub tt2()
    Dim c As New Class1
    c.tt2
End Sub
