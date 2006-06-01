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

Public Name As String
Public Sequence As Integer
Public Parameters
Private m_Encrypted As Boolean
Private m_Key As KeyExchange

Public Function SetKey(ByVal k As KeyExchange) As Command
    Set m_Key = k
    Set SetKey = Me
End Function

Public Property Get Encrypted() As Boolean
    Encrypted = Not m_Key Is Nothing
End Property

Private Function Quote(ByVal s As String) As String
    Quote = Replace(s, "\", "\\")
    Quote = Replace(Quote, " ", "\_")
End Function

Private Function Dequote(ByVal s As String) As String
    Dequote = Replace(s, "\_", " ")
    Dequote = Replace(Dequote, "\\", "\")
End Function

Public Function Encode(Optional ByVal sep As String = " ") As String
    Dim i As Integer
    Dim l As Integer
    Dim u As Integer
    Dim Params As String

    Encode = IIf(Encrypted, "X", "N") & Name & Sequence

    l = LBound(Parameters)
    u = UBound(Parameters)
    If Encrypted Then
        For i = l To u
            Encode = Encode & sep & m_Key.EncryptMessage(Parameters(i))
        Next
    Else
        For i = l To u
            If i = u Then
                Encode = Encode & sep & Parameters(i)
            Else
                Encode = Encode & sep & Quote(Parameters(i))
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

    l = LBound(Parameters)
    u = UBound(Parameters)

    Set Decode = Me
End Function
