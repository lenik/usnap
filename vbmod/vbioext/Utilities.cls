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

Public m_Base64 As New BinaryLib.base64

Public Function ReadTextFile(ByVal Path As String, Optional ByVal Default As String) As String
    Dim ts As TextStream
    Set ts = FSO.OpenTextFile(Path, ForReading, False)
    If ts Is Nothing Then
        ReadTextFile = Default
    Else
        ReadTextFile = ts.ReadAll
    End If
End Function

Public Function ReadBinaryFile(ByVal Path As String, Optional ByVal Default As String) As String
    On Error GoTo fail
    m_Base64.ReadFile Path
    ReadBinaryFile = m_Base64.GetBase64
    Exit Function
fail:
    ReadBinaryFile = Default
End Function

Public Function TextToBinary(ByVal text As String, Optional ByVal encoding As String = "gb2312") As String
    m_Base64.SetString text, encoding
    TextToBinary = m_Base64.GetBase64
End Function

Public Function BinaryToText(ByVal base64 As String, Optional ByVal encoding As String = "gb2312") As String
    m_Base64.SetBase64 base64
    BinaryToText = m_Base64.GetString(encoding)
End Function

Public Function BinaryToPicture(ByVal base64 As String, Optional Size, Optional ColorDepth, Optional X, Optional Y) As StdPicture
    Dim temppath As String
    temppath = Application.TemporaryPath("pic")
    m_Base64.SetBase64 base64
    m_Base64.WriteFile temppath
    Set BinaryToPicture = LoadPicture(temppath, Size, ColorDepth, X, Y)
    FSO.DeleteFile temppath, True
End Function

Public Function ArraySize(ByRef a)
    If IsEmpty(a) Then
        ArraySize = 0
    Else
        ArraySize = UBound(a) - LBound(a) + 1
    End If
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
    Dim Size As Long
    Size = ArraySize(Bytes)

    ' Assert Start >= 0 And Start <= Size

    If Length <= 0 Then
        Exit Function
    End If

    If Length >= Size Then
        If VarType(Bytes) = vbArray + vbByte Then
            LeftBytes = Bytes
            Exit Function
        End If
        Length = Size
    End If

    ReDim Partial(0 To Length - 1) As Byte
    Dim i As Long
    For i = 0 To Length - 1
        Partial(i) = Bytes(i)
    Next
    LeftBytes = Partial
End Function

Public Function MidBytes(ByRef Bytes, ByVal Start As Long)  ' Start based at 0
    Dim Size As Long
    Size = ArraySize(Bytes)

    ' Assert Start >= 0 And Start <= Size

    If Start < 0 Then
        If VarType(Bytes) = vbArray + vbByte Then
            MidBytes = Bytes
            Exit Function
        End If
        Start = 0
    End If

    If Start >= Size Then
        Exit Function
    End If

    ReDim Remains(0 To Size - Start - 1) As Byte
    Dim i As Long
    For i = Start To Size - 1
        Remains(i - Start) = Bytes(i)
    Next
    MidBytes = Remains
End Function
