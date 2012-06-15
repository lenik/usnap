Attribute VB_Name = "Tests"
Option Explicit

Public Function t2()
    Dim a() As Byte
    Dim b() As Byte
    Dim c As ByteArray
    a = "Hello"
    Set c = StringToByteArray(a)
End Function

Public Function t3()
    Dim a() As Byte
    Dim l As Long
    l = &H12345678
    ' syntax err.
    ' a = l
End Function

Public Function t4()
    Dim bb As New ByteBuffer
    bb.WriteByte 18 ' &h12
    bb.WriteInt 13398 '&H3456
    bb.WriteLong 2023406814 '&H789ABCDE
    bb.WriteLong -1412567295 '&HABCDEF01

    Dim b As Byte
    Dim i As Integer
    Dim l As Long
    b = bb.ReadByte
    i = bb.ReadInt
    l = bb.ReadLong

    ' Underflow
    b = bb.ReadByte
End Function
