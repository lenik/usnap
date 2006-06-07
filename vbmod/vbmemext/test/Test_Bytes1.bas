Attribute VB_Name = "Test_Bytes1"
Option Explicit

Public Sub Main()
End Sub

Public Function t1()
    Dim a() As Byte
    Dim b() As Byte
    a = "Hello"
    b = a       ' Copy, not byref-linked.
    b(2) = 0    ' "d"
    MsgBox a(2)
End Function

Public Function t2()
    'Assert "国123" = StringToByteArray("中国123", "utf-8").Clone(3).ToString("utf-8")
    'assert "中1234国56" = StringToByteArray("中123").Append(StringToByteArray("4国56").Raw).ToString
End Function

Function bEcho(ByRef bIn() As Byte, ByRef bOut() As Byte) As Byte()
    bOut = bIn
    bOut(1) = 41
    bOut(2) = 42
    bOut(3) = 43
    bEcho = bIn
End Function

Public Sub t3()
    Dim b() As Byte
    Dim c() As Byte
    b = "Hello"
    MsgBox b(2)
    bEcho(b, c)(2) = 33
    c(2) = 44
    MsgBox b(2)

    ' So, everything is COPY !!
End Sub
