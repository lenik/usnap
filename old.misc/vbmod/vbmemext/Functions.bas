Attribute VB_Name = "Functions"
Option Explicit

Public Function StringBToByteArray(ByVal s As String) As ByteArray
    Set StringBToByteArray = New ByteArray
    StringBToByteArray.InitStringB s
End Function

Public Function StringToByteArray(ByVal s As String, _
                                  Optional ByVal Charset As String = "") As ByteArray
    Set StringToByteArray = New ByteArray
    StringToByteArray.InitString s, Charset
End Function

Public Function BytesToByteArray(ByRef b() As Byte) As ByteArray
    Set BytesToByteArray = New ByteArray
    BytesToByteArray.CopyFrom b
End Function

Public Function Align(ByVal n As Long, ByVal d As Long)
    Assert n >= 0 And d > 0
    n = n + d - 1
    n = n - n Mod d
    Align = n
End Function

Public Function Float2Dword(ByVal s As Single) As Long
    Float2Dword = LR.FloatEncode(s)
End Function

Public Function Dword2Float(ByVal dw As Long) As Single
    Dword2Float = LR.FloatDecode(dw)
End Function

Public Function Double2Qword(ByVal d As Double, ByRef High As Long) As Long
    Double2Qword = LR.DoubleEncode(d, High)
End Function

Public Function Qword2Double(ByVal dwLow As Long, ByVal dwHigh As Long) As Double
    Qword2Double = LR.DoubleDecode(dwLow, dwHigh)
End Function
