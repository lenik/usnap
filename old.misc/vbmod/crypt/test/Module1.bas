Attribute VB_Name = "Module1"
Option Explicit

Public dig As New Digest

Public Function hex8(ByVal n As Long) As String
    hex8 = Right("00000000" & Hex(n), 8)
End Function

Public Function md5(ByVal str As String) As String
    Dim a As Long, b As Long, c As Long, d As Long
    dig.MD5_String str, a, b, c, d
    md5 = hex8(a) & "-" & hex8(b) & "-" & hex8(c) & "-" & hex8(d)
End Function

'       d41d8cd98f00b204e9800998ecf8427e
' a     0cc175b9c0f1b6a831c399e269772661
