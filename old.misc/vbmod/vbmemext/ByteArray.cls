VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ByteArray"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Private Const LOCATION                  As String = "VBMemExt::ByteArray"
Private Const PRESKIP                   As Long = 1

' The element(0) is not used.

Private m_Array() As Byte

Public Property Get Length() As Long
    Length = UBound(m_Array)
End Property

Public Property Let Length(ByVal newval As Long)
    Assert newval >= 0, "Invalid length", LOCATION
    ReDim Preserve m_Array(0 To newval + PRESKIP - 1)
End Property

Public Property Get Item(ByVal Index As Long) As Byte
    Assert Index >= 0 And Index < Length, "Index out of bounds", LOCATION
    Item = m_Array(PRESKIP + Index)
End Property

Public Property Let Item(ByVal Index As Long, ByVal newval As Byte)
    Assert Index >= 0 And Index < Length, "Index out of bounds", LOCATION
    m_Array(PRESKIP + Index) = newval
End Property

Public Function CopyFrom(ByRef Src() As Byte, _
                         Optional ByVal SrcOffset As Long = -LONG_MAX, _
                         Optional ByVal Offset As Long = 0, _
                         Optional ByVal Bytes As Long = LONG_MAX, _
                         Optional ByVal Extend As Boolean = True) As ByteArray
    If SrcOffset = -LONG_MAX Then SrcOffset = LBound(Src)
    If Bytes = LONG_MAX Then Bytes = UBound(Src) - SrcOffset + 1
    Assert SrcOffset >= LBound(Src) And SrcOffset + Bytes - 1 <= UBound(Src), _
           "src index out of bounds", LOCATION
    Assert Offset >= 0, "index out of bounds", LOCATION
    Assert Bytes >= 0, "invalid size", LOCATION

    Dim ExtLength As Long
    ExtLength = Offset + Bytes

    If Extend Then
        If ExtLength > Length Then Length = ExtLength
    Else
        Assert ExtLength <= Length, "index out of bounds", LOCATION
    End If

    Set CopyFrom = Me

    Dim i As Long
    For i = 0 To Bytes - 1
        m_Array(PRESKIP + Offset + i) = Src(SrcOffset + i)
    Next
End Function

Public Function CopyTo(ByRef Dest() As Byte, _
                       Optional ByVal DestOffset As Long = -LONG_MAX, _
                       Optional ByVal Offset As Long = 0, _
                       Optional ByVal Bytes As Long = LONG_MAX) As ByteArray
    If DestOffset = -LONG_MAX Then DestOffset = LBound(Dest)
    If Bytes = LONG_MAX Then Bytes = Length - Offset
    Assert DestOffset >= LBound(Dest) And DestOffset + Bytes - 1 <= UBound(Dest), _
           "dest index out of bounds", LOCATION
    Assert Offset >= 0 And Offset + Bytes <= Length, "index out of bounds", LOCATION
    Assert Bytes >= 0, "invalid size", LOCATION

    Set CopyTo = Me

    Dim i As Long
    For i = 0 To Bytes - 1
        Dest(DestOffset + i) = m_Array(PRESKIP + Offset + i)
    Next
End Function

Public Function Append(ByRef Src() As Byte, _
                       Optional ByVal SrcOffset As Long = -LONG_MAX, _
                       Optional ByVal Bytes As Long = LONG_MAX) As ByteArray
    If SrcOffset = -LONG_MAX Then SrcOffset = LBound(Src)
    If Bytes = LONG_MAX Then Bytes = UBound(Src) - SrcOffset + 1
    Assert SrcOffset >= LBound(Src) And SrcOffset + Bytes - 1 <= UBound(Src), _
           "src index out of bounds", LOCATION
    Assert Bytes >= 0, "invalid size", LOCATION

    Set Append = Me

    If Bytes = 0 Then Exit Function

    CopyFrom Src, SrcOffset, Length, Bytes, True
End Function

Public Function Insert(ByRef Src() As Byte, _
                       Optional ByVal SrcOffset As Long = -LONG_MAX, _
                       Optional ByVal Offset As Long = 0, _
                       Optional ByVal Bytes As Long = LONG_MAX) As ByteArray
    If SrcOffset = -LONG_MAX Then SrcOffset = LBound(Src)
    If Bytes = LONG_MAX Then Bytes = UBound(Src) - SrcOffset + 1
    Assert SrcOffset >= LBound(Src) And SrcOffset + Bytes - 1 <= UBound(Src), _
           "src index out of bounds", LOCATION
    Assert Offset >= 0, "index out of bounds", LOCATION
    Assert Bytes >= 0, "invalid size", LOCATION

    Set Insert = Me

    If Bytes = 0 Then Exit Function

    InsertNum Bytes, Offset

    CopyFrom Src, SrcOffset, Offset, Bytes, False
End Function

Public Function InsertNum(ByVal Bytes As Long, _
                          Optional ByVal Offset As Long = 0, _
                          Optional ByVal FillValue) As ByteArray
    Assert Bytes >= 0, "invalid size", LOCATION
    Assert Offset >= 0 And Offset <= Length

    Set InsertNum = Me

    If Bytes = 0 Then Exit Function

    Length = Length + Bytes

    Dim i As Long

    ' Move [Offset+Bytes, +Bytes] to [Offset, +Bytes]
    For i = Bytes - 1 To 0 Step -1
        m_Array(PRESKIP + Offset + Bytes + i) = m_Array(PRESKIP + Offset + i)
    Next

    ' Fill Values
    If Not IsMissing(FillValue) Then
        Dim FillByte As Byte
        FillByte = FillValue
        For i = 0 To Bytes - 1
            m_Array(PRESKIP + Offset + i) = FillByte
        Next
    End If
End Function

Public Function Clone(Optional ByVal Offset As Long = 0, _
                      Optional ByVal Bytes As Long = LONG_MAX) As ByteArray
    If Bytes = LONG_MAX Then Bytes = Length - Offset
    Assert Offset >= 0 And Offset < Length, "index out of bounds", LOCATION
    Assert Bytes >= 0 And Offset + Bytes <= Length, "invalid size", LOCATION

    Set Clone = New ByteArray

    Clone.Length = Bytes
    Clone.CopyFrom m_Array, PRESKIP + Offset, 0, Bytes, False
End Function

Public Property Get Raw() As Byte()
    ' @VB-BUG
    '   For 0-size array, this (0 to -1) will cause error.
    ReDim chopped(0 To Length - 1) As Byte
    CopyTo chopped
    Raw = chopped
End Property

Friend Property Get IRaw() As Byte()
    IRaw = m_Array
End Property

Public Function ToStringB() As String
    ToStringB = Raw
End Function

Public Function ToString(Optional ByVal Charset As String = "") As String
    Dim bin As New Base64
    bin.SetStringB ToStringB
    If Charset = "" Then
        ToString = bin.GetString
    Else
        ToString = bin.GetString(Charset)
    End If
End Function

Public Function ToHex() As String
    Dim bin As New Base64
    bin.SetStringB ToStringB
    ToHex = bin.GetHex
End Function

Public Function InitStringB(ByVal s As String) As ByteArray
    Dim b() As Byte
    b = s
    CopyFrom b
    Set InitStringB = Me
End Function

Public Function InitString(ByVal s As String, _
                           Optional ByVal Charset As String = "") As ByteArray
    Dim bin As New Base64
    If Charset = "" Then
        bin.SetString s
    Else
        bin.SetString s, Charset
    End If
    InitStringB bin.GetStringB
    Set InitString = Me
End Function

Public Function InitHex(ByVal s As String) As ByteArray
    Dim bin As New Base64
    bin.SetHex s
    InitStringB bin.GetStringB
    Set InitHex = Me
End Function

Public Function InitBase64(ByVal s As String) As ByteArray
    Dim bin As New Base64
    bin.SetBase64 s
    InitStringB bin.GetStringB
    Set InitBase64 = Me
End Function

Private Sub Class_Initialize()
    ReDim m_Array(0 To 0) As Byte
End Sub
