VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Packet"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::Packet"
Private Const KSEGS                     As Long = 2

Private m_Segs As New XnetCodec.Statement

Private m_Name As String
Private m_Encrypted As Boolean
Private m_Sequence As Integer

Private m_SharedKey As SymCrypto

' Raw Statement
' ----------------------------------------------------------------------------

Property Get Statement() As Statement
    Set Statement = m_Segs
End Property

Property Set Statement(ByVal st As Statement)
    Set m_Segs = st
End Property

Public Property Get Segment(ByVal Index As Long) As Variant
    CheckArg Index - KSEGS
    Segment = m_Segs.Item(Index)
End Property

Public Property Let Segment(ByVal Index As Long, ByVal newval As Variant)
    MakeArg Index - KSEGS
    m_Segs.Item(Index) = newval
End Property

Public Property Get StringSegment(ByVal Index As Long) As String
    CheckArg Index - KSEGS
    StringSegment = BytesToString(m_Segs.TypedItem(Index, sitBytes))
End Property

Public Property Let StringSegment(ByVal Index As Long, ByVal newval As String)
    MakeArg Index - KSEGS
    m_Segs.Item(Index) = StringToBytes(newval)
End Property

Public Property Get Args() As Long
    Args = m_Segs.Count - KSEGS
End Property

Public Property Let Args(ByVal newval As Long)
    MakeArg newval + 1
End Property

Public Property Get ArgOf(ByVal Index As Integer, _
                          Optional ByVal AsType As StatementItemTypeConstants = 0) As Variant
    ArgOf = m_Segs.TypedItem(KSEGS + Index, AsType)
End Property

Public Property Get Arg(ByVal Index As Long) As String
    CheckArg Index
    Arg = m_Segs.TypedItem(KSEGS + Index, sitString)
End Property

Public Property Let Arg(ByVal Index As Long, ByVal newval As String)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get ByteArg(ByVal Index As Long) As Byte
    CheckArg Index
    ByteArg = m_Segs.TypedItem(KSEGS + Index, sitByte)
End Property

Public Property Let ByteArg(ByVal Index As Long, ByVal newval As Byte)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get IntArg(ByVal Index As Long) As Integer
    CheckArg Index
    IntArg = m_Segs.TypedItem(KSEGS + Index, sitInt)
End Property

Public Property Let IntArg(ByVal Index As Long, ByVal newval As Integer)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get LongArg(ByVal Index As Long) As Long
    CheckArg Index
    LongArg = m_Segs.TypedItem(KSEGS + Index, sitLong)
End Property

Public Property Let LongArg(ByVal Index As Long, ByVal newval As Long)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get SingleArg(ByVal Index As Long) As Single
    CheckArg Index
    SingleArg = m_Segs.TypedItem(KSEGS + Index, sitSingle)
End Property

Public Property Let SingleArg(ByVal Index As Long, ByVal newval As Single)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get DoubleArg(ByVal Index As Long) As Double
    CheckArg Index
    DoubleArg = m_Segs.TypedItem(KSEGS + Index, sitDouble)
End Property

Public Property Let DoubleArg(ByVal Index As Long, ByVal newval As Double)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get BytesArg(ByVal Index As Long) As Byte()
    CheckArg Index
    BytesArg = m_Segs.TypedItem(KSEGS + Index, sitBytes)
End Property

Public Property Let BytesArg(ByVal Index As Long, ByRef newval() As Byte)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get IntsArg(ByVal Index As Long) As Integer()
    CheckArg Index
    IntsArg = m_Segs.TypedItem(KSEGS + Index, sitInts)
End Property

Public Property Let IntsArg(ByVal Index As Long, ByRef newval() As Integer)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get LongsArg(ByVal Index As Long) As Long()
    CheckArg Index
    LongsArg = m_Segs.TypedItem(KSEGS + Index, sitLongs)
End Property

Public Property Let LongsArg(ByVal Index As Long, ByRef newval() As Long)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get SinglesArg(ByVal Index As Long) As Single()
    CheckArg Index
    SinglesArg = m_Segs.TypedItem(KSEGS + Index, sitSingles)
End Property

Public Property Let SinglesArg(ByVal Index As Long, ByRef newval() As Single)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

Public Property Get DoublesArg(ByVal Index As Long) As Double()
    CheckArg Index
    DoublesArg = m_Segs.TypedItem(KSEGS + Index, sitDoubles)
End Property

Public Property Let DoublesArg(ByVal Index As Long, ByRef newval() As Double)
    MakeArg Index
    m_Segs.Item(KSEGS + Index) = newval
End Property

' Xnet Std Protocol / String-Ver
' ----------------------------------------------------------------------------
Public Property Get Encrypted() As Boolean
    CheckArg -2
    Encrypted = Left(StringSegment(0), 1) = "X"
End Property

Public Property Let Encrypted(ByVal newval As Boolean)
    MakeArg -2
    If newval Then
        Assert Not m_SharedKey Is Nothing, _
            "Cannot enable encryption without session key. ", LOCATION
    End If
    StringSegment(0) = IIf(newval, "X", "N") & Mid(StringSegment(0), 2)
End Property

Public Property Get Name() As String
    CheckArg -2
    Name = Mid(StringSegment(0), 2)
End Property
Public Property Let Name(ByVal newval As String)
    MakeArg -2

    StringSegment(0) = IIf(Encrypted, "X", "N") & newval
End Property

Public Property Get Sequence() As Long
    CheckArg -1
    Sequence = Val(StringSegment(1))
End Property

Public Property Let Sequence(ByVal newval As Long)
    MakeArg -1
    StringSegment(1) = CStr(newval)
End Property

Public Property Get Initiative() As Boolean
    Initiative = Sequence Mod 2 = 0
End Property

Public Property Get Reply() As Long
    Reply = Sequence + 1
End Property

Public Property Get Key() As SymCrypto
    Set Key = m_SharedKey
End Property

Public Property Set Key(ByVal newval As SymCrypto)
    Set m_SharedKey = newval
End Property

Public Property Get XArg(ByVal Index As Long) As String
    MakeArg Index
    XArg = BytesToString(m_Segs.TypedItem(KSEGS + Index, sitBytes))
    If m_Encrypted Then
        Assert Not m_SharedKey Is Nothing, "Key not set", LOCATION
        XArg = m_SharedKey.DecryptMessage(XArg, False)
    End If
End Property

Public Property Let XArg(ByVal Index As Long, ByVal newval As String)
    MakeArg Index
    If m_Encrypted Then
        Assert Not m_SharedKey Is Nothing, "Key not set", LOCATION
        newval = m_SharedKey.EncryptMessage(newval, False)
    End If
    m_Segs.Item(KSEGS + Index) = StringToBytes(newval)
End Property

' Encoding
' ----------------------------------------------------------------------------
Public Function Encode() As Byte()
    Encode = m_Segs.Encode
End Function

Public Function EncodeString() As String
    EncodeString = BytesToString(Encode)
End Function

Public Function EncodeStringB() As String
    EncodeStringB = BytesToStringB(Encode)
End Function

' Returns count of bytes has been decoded.
Public Function Decode(ByRef Bytes() As Byte) As Long
    Dim ib As New InputBuffer
    Dim InitSize As Long
    InitSize = UBound(Bytes) - LBound(Bytes) + 1
    ib.AddBytes Bytes
    If ib.StatementReady Then
        Set m_Segs = ib.GetStatement
    End If
    Decode = InitSize - ib.UnreadSize
End Function

Public Sub DropArg(ByVal Index As Long)
    CheckArg Index
    m_Segs.Remove KSEGS + Index
End Sub

' Internals
' ----------------------------------------------------------------------------
Private Sub CheckArg(ByVal Index As Long)
    Dim c As Long
    c = KSEGS + Index + 1
    Assert m_Segs.Count >= c, _
           "Internal state not fulfilled, the segments count is less than " & c, _
           LOCATION
End Sub

Private Sub MakeArg(ByVal Index As Long)
    Dim c As Long
    c = KSEGS + Index + 1
    While m_Segs.Count < c
        m_Segs.Add CByte(0)
    Wend
End Sub
