VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BinaryUtilities"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBIOExt::BinaryUtilities"

Public Function ReadTextFile(ByVal Path As String, _
                             Optional ByVal Default As String) As String
    ReadTextFile = GlobalsSingleton.ReadTextFile(Path, Default)
End Function

Public Function ReadBinaryFile(ByVal Path As String, _
                               Optional ByVal Default As String) As String
    ReadBinaryFile = GlobalsSingleton.ReadBinaryFile(Path, Default)
End Function

Public Function TextToBinary(ByVal Text As String, _
                             Optional ByVal Encoding As String = "gb2312") As String
    TextToBinary = GlobalsSingleton.TextToBinary(Text, Encoding)
End Function

Public Function BinaryToText(ByVal base64 As String, _
                             Optional ByVal Encoding As String = "gb2312") As String
    BinaryToText = GlobalsSingleton.BinaryToText(base64, Encoding)
End Function

Public Function BinaryToPicture(ByVal base64 As String, _
                                Optional Size, Optional ColorDepth, _
                                Optional X, Optional Y) As StdPicture
    Set BinaryToPicture = GlobalsSingleton.BinaryToPicture(base64, Size, ColorDepth, X, Y)
End Function

Public Function ArraySize(ByRef a) As Long
    ArraySize = GlobalsSingleton.ArraySize(a)
End Function

Public Function StringToBytes(ByVal s As String) As Byte()
    s = StrConv(s, vbFromUnicode)
    StringToBytes = s
End Function

Public Function StringBToBytes(ByVal s As String) As Byte()
    StringBToBytes = s
End Function

Public Function BytesToString(ByVal Bytes) As String
    BytesToString = StrConv(Bytes, vbUnicode)
End Function

Public Function BytesToStringB(ByVal Bytes) As String
    BytesToStringB = Bytes
End Function

Public Function LeftBytes(ByRef Bytes, ByVal Length As Long)
    LeftBytes = GlobalsSingleton.LeftBytes(Bytes, Length)
End Function

Public Function MidBytes(ByRef Bytes, ByVal Start As Long) ' Start based at 0
    MidBytes = GlobalsSingleton.MidBytes(Bytes, Start)
End Function

Public Sub varscpy(ByRef dst, ByVal dstoff As Long, _
                   ByRef src, ByVal srcoff As Long, ByVal num As Long)
    GlobalsSingleton.varscpy dst, dstoff, src, srcoff, num
End Sub

Public Sub objscpy(ByRef dst, ByVal dstoff As Long, _
                   ByRef src, ByVal srcoff As Long, ByVal num As Long)
    Assert 0 <> (VarType(dst) And vbArray), "dst isn't an array"
    Assert 0 <> (VarType(src) And vbArray), "src isn't an array"
    Assert num >= 0, "invalid num of copy items", LOCATION
    Assert dstoff >= LBound(dst) And dstoff + num < UBound(dst), "dst-range out of bounds", LOCATION
    Assert srcoff >= LBound(src) And srcoff + num < UBound(src), "src-range out of bounds", LOCATION
    Dim i As Long
    For i = 0 To num - 1
        Set dst(dstoff + i) = src(srcoff + i)
    Next
End Sub

Public Sub bytscpy(ByRef dst() As Byte, ByVal dstoff As Long, _
                   ByRef src() As Byte, ByVal srcoff As Long, ByVal num As Long)
    varscpy dst, dstoff, src, srcoff, num
End Sub

Public Sub intscpy(ByRef dst() As Integer, ByVal dstoff As Long, _
                   ByRef src() As Integer, ByVal srcoff As Long, ByVal num As Long)
    varscpy dst, dstoff, src, srcoff, num
End Sub

Public Sub lngscpy(ByRef dst() As Long, ByVal dstoff As Long, _
                   ByRef src() As Long, ByVal srcoff As Long, ByVal num As Long)
    varscpy dst, dstoff, src, srcoff, num
End Sub

Public Sub sngscpy(ByRef dst() As Single, ByVal dstoff As Long, _
                   ByRef src() As Single, ByVal srcoff As Long, ByVal num As Long)
    varscpy dst, dstoff, src, srcoff, num
End Sub

Public Sub dblscpy(ByRef dst() As Double, ByVal dstoff As Long, _
                   ByRef src() As Double, ByVal srcoff As Long, ByVal num As Long)
    varscpy dst, dstoff, src, srcoff, num
End Sub
