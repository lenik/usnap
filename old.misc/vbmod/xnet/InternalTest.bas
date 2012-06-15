Attribute VB_Name = "InternalTest"
Option Explicit

Private Const LOCATION                  As String = "Xnet::InternalTest"

Public Function RemakePacket(ByVal Pkt As Packet) As Packet
    Dim b() As Byte
    Dim buf As New Buffer
    b = Pkt.Encode
    buf.AddBytes b
    Set RemakePacket = buf.NextPacket
    Assert Not buf.PacketReady, "Pkt encoding leaks", LOCATION
End Function
