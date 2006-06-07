VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ByteBuffer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBMemExt::ByteBuffer"

Private m_Bytar As New ByteArray
Private m_Size As Long
Private m_Delta As Long
Private m_ReadPos As Long

Public Property Get Bytar() As ByteArray
    Set Bytar = m_Bytar
End Property

Public Property Set Bytar(ByVal newval As ByteArray)
    Set m_Bytar = newval
End Property

Public Property Get AllocatedSize() As Long
    AllocatedSize = m_Bytar.Length
End Property

Public Property Get Size() As Long
    Size = m_Size
End Property

Private Sub ExtendSize(ByVal RequiredMin As Long)
    Assert RequiredMin >= 0, "invalid size", LOCATION
    If RequiredMin > m_Size Then
        Dim NewAlloc As Long
        NewAlloc = Align(RequiredMin, m_Delta)
        If NewAlloc > m_Bytar.Length Then
            If NewAlloc - m_Bytar.Length > m_Delta Then
                m_Delta = m_Delta * 2
            End If
            m_Bytar.Length = NewAlloc
        End If
    End If
End Sub

Public Property Get EOF() As Boolean
    EOF = m_ReadPos >= m_Size
End Property

Private Sub CheckRead(ByVal AdvanceBytes As Long)
    Assert m_ReadPos + AdvanceBytes <= m_Size, "Buffer Underflow", LOCATION
End Sub

Public Sub WriteByte(ByVal b As Byte)
    ExtendSize m_Size + 1
    m_Bytar.Item(m_Size) = b
    m_Size = m_Size + 1
End Sub

Public Sub WriteInt(ByVal i As Integer)
    Dim b0 As Byte
    Dim b1 As Byte
    b0 = i And &HFF
    b1 = Int(i / &H100)

    ExtendSize m_Size + 2
    m_Bytar.Item(m_Size) = b0
    m_Bytar.Item(m_Size + 1) = b1
    m_Size = m_Size + 2
End Sub

Public Sub WriteLong(ByVal l As Long)
    Dim b0 As Byte
    Dim b1 As Byte
    Dim b2 As Byte
    Dim b3 As Byte
    b0 = l And &HFF&
    l = Int(l / &H100&)
    b1 = l And &HFF&
    l = Int(l / &H100&)
    b2 = l And &HFF&
    l = Int(l / &H100&)
    b3 = l And &HFF&

    ExtendSize m_Size + 4
    m_Bytar.Item(m_Size) = b0
    m_Bytar.Item(m_Size + 1) = b1
    m_Bytar.Item(m_Size + 2) = b2
    m_Bytar.Item(m_Size + 3) = b3
    m_Size = m_Size + 4
End Sub

Public Sub WriteSingle(ByVal v As Single)
    WriteLong Float2Dword(v)
End Sub

Public Sub WriteDouble(ByVal v As Double)
    Dim Low As Long
    Dim High As Long
    Low = Double2Qword(v, High)
End Sub

Public Sub WriteBytes(ByRef Src() As Byte, _
                           Optional ByVal SrcOffset As Long = -LONG_MAX, _
                           Optional ByVal Bytes As Long = LONG_MAX)
    If SrcOffset = -LONG_MAX Then SrcOffset = LBound(Src)
    If Bytes = LONG_MAX Then Bytes = UBound(Src) - SrcOffset + 1
    Assert SrcOffset >= LBound(Src) And SrcOffset + Bytes - 1 <= UBound(Src), _
           "src index out of bounds", LOCATION
    Assert Bytes >= 0, "invalid size", LOCATION

    WriteLong Bytes
    m_Bytar.Append Src, SrcOffset, Bytes
End Sub

Public Sub WriteStringB(ByVal s As String)
    Dim b() As Byte
    b = s
    WriteBytes b
End Sub

Public Sub WriteString(ByVal s As String, _
                       Optional ByVal Charset As String = "")
    Dim bin As New Base64
    bin.SetString s, Charset
    WriteStringB bin.GetStringB
End Sub

Public Function ReadByte() As Byte
    CheckRead 1
    ReadByte = m_Bytar.Item(m_ReadPos)
    m_ReadPos = m_ReadPos + 1
End Function

Public Function ReadInt() As Integer
    CheckRead 2
    Dim b0 As Byte
    Dim b1 As Byte
    b0 = m_Bytar.Item(m_ReadPos)
    b1 = m_Bytar.Item(m_ReadPos + 1)
    ReadInt = b0 Or LR.Shift(b1, -8)
    m_ReadPos = m_ReadPos + 2
End Function

Public Function ReadLong() As Long
    CheckRead 4
    Dim b0 As Byte
    Dim b1 As Byte
    Dim b2 As Byte
    Dim b3 As Byte
    b0 = m_Bytar.Item(m_ReadPos)
    b1 = m_Bytar.Item(m_ReadPos + 1)
    b2 = m_Bytar.Item(m_ReadPos + 2)
    b3 = m_Bytar.Item(m_ReadPos + 3)
    ReadLong = b0 Or LR.Shift(b1, -8) Or LR.Shift(b2, -16) Or LR.Shift(b3, -24)
    m_ReadPos = m_ReadPos + 4
End Function

Public Function ReadSingle() As Single
    CheckRead 4
    Dim l As Long
    l = ReadLong
    ReadSingle = Dword2Float(l)
End Function

Public Function ReadDouble() As Double
    CheckRead 8
    Dim Low As Long
    Dim High As Long
    Low = ReadLong
    High = ReadLong
    ReadDouble = Qword2Double(Low, High)
End Function

Public Function ReadBytes() As Byte()
    Dim Bytes As Long
    Bytes = ReadLong

    CheckRead Bytes

    If Bytes = 0 Then
        ' ??
        Exit Function
    End If

    ReDim b(0 To Bytes - 1) As Byte
    m_Bytar.CopyTo b, 0, m_ReadPos, Bytes
    m_ReadPos = m_ReadPos + Bytes
End Function

Public Function ReadStringB() As String
    Dim b() As Byte
    b = ReadBytes
    ReadStringB = b
End Function

Public Function ReadString(Optional ByVal Charset As String = "") As String
    Dim bin As New Base64
    Dim s As String
    s = ReadStringB
    bin.SetStringB s
    If Charset = "" Then
        ReadString = bin.GetString
    Else
        ReadString = bin.GetString(Charset)
    End If
End Function

Private Sub Class_Initialize()
    m_Delta = 16
    m_ReadPos = 0
End Sub
