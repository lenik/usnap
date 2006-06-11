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

Private m_Segs As XnetCodec.Statement

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
    AssertGE Index + 1
    Segment = m_Segs.Item(Index)
End Property

Public Property Let Segment(ByVal Index As Long, ByVal newval As Variant)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get Args() As Long
    Args = m_Segs.Count
End Property

Public Property Let Args(ByVal newval As Long)
    MakeEQ newval
End Property

Public Property Get ArgOf(ByVal Index As Integer, _
                          Optional ByVal AsType As StatementItemTypeConstants = 0) As Variant
    ArgOf = m_Segs.TypedItem(Index, AsType)
End Property

Public Property Get Arg(ByVal Index As Long) As String
    AssertGE Index + 1
    Arg = m_Segs.TypedItem(Index, sitString)
End Property

Public Property Let Arg(ByVal Index As Long, ByVal newval As String)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get ByteArg(ByVal Index As Long) As Byte
    AssertGE Index + 1
    ByteArg = m_Segs.TypedItem(Index, sitByte)
End Property

Public Property Let ByteArg(ByVal Index As Long, ByVal newval As Byte)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get IntArg(ByVal Index As Long) As Integer
    AssertGE Index + 1
    IntArg = m_Segs.TypedItem(Index, sitInt)
End Property

Public Property Let IntArg(ByVal Index As Long, ByVal newval As Integer)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get LongArg(ByVal Index As Long) As Long
    AssertGE Index + 1
    LongArg = m_Segs.TypedItem(Index, sitLong)
End Property

Public Property Let LongArg(ByVal Index As Long, ByVal newval As Long)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get SingleArg(ByVal Index As Long) As Single
    AssertGE Index + 1
    SingleArg = m_Segs.TypedItem(Index, sitSingle)
End Property

Public Property Let SingleArg(ByVal Index As Long, ByVal newval As Single)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get DoubleArg(ByVal Index As Long) As Double
    AssertGE Index + 1
    DoubleArg = m_Segs.TypedItem(Index, sitDouble)
End Property

Public Property Let DoubleArg(ByVal Index As Long, ByVal newval As Double)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get BytesArg(ByVal Index As Long) As Byte()
    AssertGE Index + 1
    BytesArg = m_Segs.TypedItem(Index, sitBytes)
End Property

Public Property Let BytesArg(ByVal Index As Long, ByRef newval() As Byte)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get IntsArg(ByVal Index As Long) As Integer()
    AssertGE Index + 1
    IntsArg = m_Segs.TypedItem(Index, sitInts)
End Property

Public Property Let IntsArg(ByVal Index As Long, ByRef newval() As Integer)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get LongsArg(ByVal Index As Long) As Long()
    AssertGE Index + 1
    LongsArg = m_Segs.TypedItem(Index, sitLongs)
End Property

Public Property Let LongsArg(ByVal Index As Long, ByRef newval() As Long)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get SinglesArg(ByVal Index As Long) As Single()
    AssertGE Index + 1
    SinglesArg = m_Segs.TypedItem(Index, sitSingles)
End Property

Public Property Let SinglesArg(ByVal Index As Long, ByRef newval() As Single)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

Public Property Get DoublesArg(ByVal Index As Long) As Double()
    AssertGE Index + 1
    DoublesArg = m_Segs.TypedItem(Index, sitDoubles)
End Property

Public Property Let DoublesArg(ByVal Index As Long, ByRef newval() As Double)
    MakeGE Index + 1
    m_Segs.Item(Index) = newval
End Property

' Xnet Std Protocol / String-Ver
' ----------------------------------------------------------------------------
Public Property Get Encrypted() As Boolean
    Encrypted = Left(Arg(0), 1) = "X"
End Property

Public Property Let Encrypted(ByVal newval As Boolean)
    If newval Then
        Assert Not m_SharedKey Is Nothing, _
            "Cannot enable encryption without session key. ", LOCATION
    End If
    Arg(0) = IIf(newval, "X", "N") & Mid(Arg(0), 2)
End Property

Public Property Get Name() As String
    Name = Mid(Arg(0), 2)
End Property

Public Property Let Name(ByVal newval As String)
    Arg(0) = IIf(Encrypted, "X", "N") & newval
End Property

Public Property Get Sequence() As Long
    Sequence = Val(Arg(1))
End Property

Public Property Let Sequence(ByVal newval As Long)
    Arg(1) = newval
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

' Encoding
' ----------------------------------------------------------------------------
Public Function Encode() As Byte()
    Encode = m_Segs.Encode
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

Public Sub Send(ByVal Socket As IClientSocket)
    Socket.SendBytes Encode
End Sub

' Internals
' ----------------------------------------------------------------------------

Sub AssertGE(ByVal c As Long)
    Assert m_Segs.Count >= c, _
           "Internal state not fulfilled, the segments count is less than " & c, _
           LOCATION
End Sub

Sub MakeGE(ByVal c As Long)
    While m_Segs.Count < c
        m_Segs.Add 0&
    Wend
End Sub

Sub MakeEQ(ByVal c As Long)
    While m_Segs.Count < c
        m_Segs.Add 0&
    Wend
    While m_Segs.Count > c
        m_Segs.Remove m_Segs.Count - 1
    Wend
End Sub
