Attribute VB_Name = "Module2"
Option Explicit

Function f1()
    Dim bytes(1 To 10) As Byte
    Dim b As Byte
    Dim i
    For i = 1 To 10
        bytes(i) = 100 + i
    Next
    b = 99

    f2 b
    f3 bytes
End Function

Function f2(b As Byte)
    b = b - 1
End Function

Function f3(ba() As Byte)
    ba(1) = ba(2) + ba(1)
End Function
