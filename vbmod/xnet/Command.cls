VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Command"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::Command"

Private m_Name As String
Private m_Sequence As Integer
Private m_Parameters

Private m_Encrypted As Boolean
Private m_Key As KeyExchange

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
    Assert m_Key, "Cannot enable encryption without keys. ", LOCATION
    m_Encrypted = True
End Property

Public Property Get Key() As KeyExchange
    Set Key = m_Key
End Property

Public Property Set Key(ByVal newval As KeyExchange)
    Set m_Key = newval
End Property

Public Function Encode(Optional ByVal sep As String = " ") As String
    Dim i As Integer
    Dim l As Integer
    Dim u As Integer
    Dim Params As String

    Encode = IIf(Encrypted, "X", "N") & Name & Sequence

    l = LBound(m_Parameters)
    u = UBound(m_Parameters)
    If Encrypted Then
        For i = l To u
            Encode = Encode & sep & m_Key.EncryptMessage(m_Parameters(i))
        Next
    Else
        For i = l To u
            If i = u Then
                Encode = Encode & sep & m_Parameters(i)
            Else
                Encode = Encode & sep & Quote(m_Parameters(i))
            End If
        Next
    End If
    Encode = Encode & vbNewLine
End Function

Public Function Decode(ByVal s As String, Optional ByVal MaxParams As Integer = 1, _
                       Optional sep As String = " ") As Command
    Do While Len(s) > 0
        Select Case Asc(Right(s, 1))
        Case 13
        Case 10
        Case 9
        Case 32
        Case Else
            Exit Do
        End Select
        s = Left(s, Len(s) - 1)
    Loop

    Dim Segs
    Segs = Split(s, sep, MaxParams + 1)

    Dim i As Integer
    Dim l As Integer
    Dim u As Integer

    l = LBound(m_Parameters)
    u = UBound(m_Parameters)

    Set Decode = Me
End Function
