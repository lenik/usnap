Attribute VB_Name = "Module1"
Option Explicit

Public Sub tt1()

    Dim a(-1 To 3) As Long
    Dim b() As Long

    a(1) = 123
    a(2) = 234
    a(3) = 345

    b = a
End Sub

Public Sub tt2()
    Dim f As New Xnet.File
    f.Path = "X:\tt2"
    f.Init 25, 10
    'MsgBox f.Packets

    f.PutPacket f.NextPacketInQueue, "hello, world"
    f.PutPacket f.NextPacketInQueue, "0123456789ABCDEFGHIJKLMN"
    f.PutPacket f.NextPacketInQueue, "0123456789ABCDEFGHIJKLMN"

    Dim i As Long
    i = f.NextPacketInQueue
End Sub

Public Function tt4(ByVal decraw As Boolean, encraw As Boolean)
    Dim sk As New SymCrypto
    sk.Key = "123"

    Dim kt As New Packet
    Set kt.Key = sk

    'tt4 = kt.Decode("XMSG 0 Hello, world!", 1, , decraw).Encode(, encraw)
End Function
