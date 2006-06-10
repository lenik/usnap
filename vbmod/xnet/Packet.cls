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

Private m_Name As String
Private m_Encrypted As Boolean
Private m_Sequence As Integer

' Variants.
'   Byte(): Raw Data
'   String: Str/StrB is determined by RawMode
Private m_Parameters

Private m_SharedKey As SymCrypto

Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Name = newval
End Property

Public Property Get Sequence() As Integer
    Sequence = m_Sequence
End Property

Public Property Let Sequence(ByVal newval As Integer)
    m_Sequence = newval
End Property

Public Property Get Initiative() As Boolean
    Initiative = m_Sequence Mod 2 = 0
End Property

Public Property Get Reply() As Long
    Reply = m_Sequence + 1
End Property

Public Property Get Parameters()
    Parameters = m_Parameters
End Property

Public Property Let Parameters(ByVal newval)
    m_Parameters = newval
End Property

Public Property Get ParametersCount() As Long
    ParametersCount = UBound(m_Parameters) + 1
End Property

Public Property Get Parameter(ByVal Index As Integer)
    Parameter = m_Parameters(Index)
End Property

Public Property Let Parameter(ByVal Index As Integer, ByVal newval)
    m_Parameters(Index) = newval
End Property

Public Property Get Encrypted() As Boolean
    Encrypted = m_Encrypted
End Property

Public Property Let Encrypted(ByVal newval As Boolean)
    If Not newval Then
        m_Encrypted = False
        Exit Property
    End If
    Assert Not m_SharedKey Is Nothing, _
        "Cannot enable encryption without session key. ", LOCATION
    m_Encrypted = True
End Property

Public Property Get Key() As SymCrypto
    Set Key = m_SharedKey
End Property

Public Property Set Key(ByVal newval As SymCrypto)
    Set m_SharedKey = newval
End Property

Public Function Encode() As Byte()
    Dim i As Integer
    Dim l As Integer
    Dim u As Integer
    Dim Param As String
    Dim bb As New ByteBuffer

    bb.WriteByte IIf(Encrypted, "X", "N")
    bb.WriteBytes StringToBytes(Name)
    bb.WriteByte 32 ' SP
    bb.WriteBytes StringToBytes(Sequence)

    u = UBound(m_Parameters)
    For i = 0 To u
        If VarType(m_Parameters(i)) = vbArray + vbByte Then
            Param = BytesToStringB(m_Parameters(i))
        Else
            Param = m_Parameters(i)
            If Not m_Encrypted Then Param = Quote(Param)
            Param = StringToBytes(Param)
        End If
        If m_Encrypted Then
            Param = m_SharedKey.EncryptMessage(Param, True)
            Param = StringToBytes(Param)
        End If
        bb.WriteByte 32 'SP
        bb.WriteBytes StringBToBytes(Param)
    Next

    bb.WriteByte 10 'LN
    Encode = bb.getbytes
End Function

Public Function Decode(ByRef Bytes() As Byte, _
                       Optional ByVal MaxParams As Integer = 10) As Packet
    Dim s As String
    Dim Segs
    Dim i As Integer
    Dim l As Integer
    Dim u As Integer
    Dim nsegs As Integer
    Dim nparams As Integer
    Dim Param As String

    s = Bytes

    Do While Len(s) > 0
        Select Case Asc(Right(s, 1))
        Case 13     ' \r
        Case 10     ' \n
        Case 9      ' \t
        Case 32     ' SP
        Case 59     ' ; (not in Base64)
        Case Else
            Exit Do
        End Select
        s = Left(s, Len(s) - 1)
    Loop

    ' CmdName Seq P0 P1 .. Pn
    Segs = Split(s, Sep, MaxParams + 2)

    l = LBound(Segs)
    u = UBound(Segs)
    nsegs = u - l + 1

    Select Case Left(Segs(l), 1)
    Case "X"
        m_Encrypted = True
    Case "N"
        ' normal
        m_Encrypted = False
    End Select
    m_Name = Mid(Segs(l), 2)

    If nsegs > 1 Then m_Sequence = Val(Segs(l + 1))

    nparams = nsegs - 2
    ' Assert nparams >= 0
    If nparams < 0 Then nparams = 0

    ReDim m_Parameters(-1 To nparams - 1)
    For i = l + 2 To u
        Param = Segs(i)
        If m_Encrypted Then
            m_Parameters(i - l - 2) = m_SharedKey.DecryptMessage(Param)
        Else
            m_Parameters(i - l - 2) = Param
        End If
    Next

    Set DecodeString = Me
End Function

Public Sub Send(ByVal Socket As IClientSocket)
    Socket.SendBytes Encode
End Sub
