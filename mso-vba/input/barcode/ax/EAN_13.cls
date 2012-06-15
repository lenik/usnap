VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "EAN_13"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const CHARSET                   As String = "0123456789"

Private Const DEFAULTFONT_A             As String = "0123456789"
Private Const DEFAULTFONT_B             As String = "ABCDEFGHIJ"
Private Const DEFAULTFONT_C             As String = "abcdefghij"
Private Const DEFAULTFONT_N             As String = "#$%&'()*+,"    ' Human readable numbers
Private Const DEFAULTFONT_S             As String = "!"             ' Start/Stop Line
Private Const DEFAULTFONT_M             As String = "-"             ' Middle Line

Implements IBuilder

Public Function Build(ByVal Message As String, Optional ByVal FontParam As String) As String
    Dim fontA As String
    Dim fontB As String
    Dim fontC As String
    Dim fontN As String
    Dim fontS As String
    Dim fontM As String

    If Len(Message) <> 12 Then Error errInvalidMessage
    If Not InCharset(Message, CHARSET) Then Error errInvalidMessage

    If Len(FontParam) >= 42 Then
        fontA = Mid(FontParam, 1, 10)
        fontB = Mid(FontParam, 11, 10)
        fontC = Mid(FontParam, 21, 10)
        fontN = Mid(FontParam, 31, 10)
        fontS = Mid(FontParam, 41, 1)
        fontM = Mid(FontParam, 42, 1)
    Else
        fontA = DEFAULTFONT_A
        fontB = DEFAULTFONT_B
        fontC = DEFAULTFONT_C
        fontN = DEFAULTFONT_N
        fontS = DEFAULTFONT_S
        fontM = DEFAULTFONT_M
    End If

    Dim xc As Integer
    Dim xb As Integer
    Dim xa As Integer
    Dim x9 As Integer
    Dim x8 As Integer
    Dim x7 As Integer
    Dim x6 As Integer
    Dim x5 As Integer
    Dim x4 As Integer
    Dim x3 As Integer
    Dim x2 As Integer
    Dim x1 As Integer
    Dim x0 As Integer
    xc = Val(Mid(Message, 1, 1))
    xb = Val(Mid(Message, 2, 1))
    xa = Val(Mid(Message, 3, 1))
    x9 = Val(Mid(Message, 4, 1))
    x8 = Val(Mid(Message, 5, 1))
    x7 = Val(Mid(Message, 6, 1))
    x6 = Val(Mid(Message, 7, 1))
    x5 = Val(Mid(Message, 8, 1))
    x4 = Val(Mid(Message, 9, 1))
    x3 = Val(Mid(Message, 10, 1))
    x2 = Val(Mid(Message, 11, 1))
    x1 = Val(Mid(Message, 12, 1))

    Dim cx As Integer
    Dim cy As Integer
    Dim cz As Integer
    cx = xb + x9 + x7 + x5 + x3 + x1
    cy = xc + xa + x8 + x6 + x4 + x2
    cz = 3 * cx + cy
    x0 = (10 - cz Mod 10) Mod 10

    Select Case xc
    Case 0                              ' AAAAAA
        Build = At(fontA, xb) & At(fontA, xa) & At(fontA, x9) & At(fontA, x8) & At(fontA, x7) & At(fontA, x6)
    Case 1                              ' AABABB
        Build = At(fontA, xb) & At(fontA, xa) & At(fontB, x9) & At(fontA, x8) & At(fontB, x7) & At(fontB, x6)
    Case 2                              ' AABBAB
        Build = At(fontA, xb) & At(fontA, xa) & At(fontB, x9) & At(fontB, x8) & At(fontA, x7) & At(fontB, x6)
    Case 3                              ' AABBBA
        Build = At(fontA, xb) & At(fontA, xa) & At(fontB, x9) & At(fontB, x8) & At(fontB, x7) & At(fontA, x6)
    Case 4                              ' ABAABB
        Build = At(fontA, xb) & At(fontB, xa) & At(fontA, x9) & At(fontA, x8) & At(fontB, x7) & At(fontB, x6)
    Case 5                              ' ABBAAB
        Build = At(fontA, xb) & At(fontB, xa) & At(fontB, x9) & At(fontA, x8) & At(fontA, x7) & At(fontB, x6)
    Case 6                              ' ABBBAA
        Build = At(fontA, xb) & At(fontB, xa) & At(fontB, x9) & At(fontB, x8) & At(fontA, x7) & At(fontA, x6)
    Case 7                              ' ABABAB
        Build = At(fontA, xb) & At(fontB, xa) & At(fontA, x9) & At(fontB, x8) & At(fontA, x7) & At(fontB, x6)
    Case 8                              ' ABABBA
        Build = At(fontA, xb) & At(fontB, xa) & At(fontA, x9) & At(fontB, x8) & At(fontB, x7) & At(fontA, x6)
    Case 9                              ' ABBABA
        Build = At(fontA, xb) & At(fontB, xa) & At(fontB, x9) & At(fontA, x8) & At(fontB, x7) & At(fontA, x6)
    End Select

    Build = At(fontN, xc) & fontS _
          & Build _
          & fontM _
          & At(fontC, x5) & At(fontC, x4) & At(fontC, x3) & At(fontC, x2) & At(fontC, x1) & At(fontC, x0) _
          & fontS
End Function

Public Function BuildWithUI() As String

End Function

' -o IBuidler

Private Function IBuilder_Build(ByVal Message As String, Optional ByVal FontParam As String) As String
    IBuilder_Build = Build(Message, FontParam)
End Function

Private Function IBuilder_BuildWithUI() As String
    IBuilder_BuildWithUI = BuildWithUI()
End Function
