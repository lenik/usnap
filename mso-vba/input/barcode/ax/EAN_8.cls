VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "EAN_8"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const CHARSET                   As String = "0123456789"

Private Const DEFAULTFONT_A             As String = "0123456789"
Private Const DEFAULTFONT_B             As String = "ABCDEFGHIJ"
Private Const DEFAULTFONT_C             As String = "abcdefghij"
Private Const DEFAULTFONT_S             As String = "!"             ' Start/Stop Line
Private Const DEFAULTFONT_M             As String = "-"             ' Middle Line
Private Const DEFAULTFONT_N             As String = "#$%&'()*+,"    ' Human readable numbers

Implements IBuilder

Public Function Build(ByVal Message As String, Optional ByVal FontParam As String) As String
    Dim fontA As String
    Dim fontB As String
    Dim fontC As String
    Dim fontN As String
    Dim fontS As String
    Dim fontM As String

    If Len(Message) <> 7 Then Error errInvalidMessage
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

    Dim x7 As Integer
    Dim x6 As Integer
    Dim x5 As Integer
    Dim x4 As Integer
    Dim x3 As Integer
    Dim x2 As Integer
    Dim x1 As Integer
    Dim x0 As Integer
    x7 = Val(Mid(Message, 1, 1))
    x6 = Val(Mid(Message, 2, 1))
    x5 = Val(Mid(Message, 3, 1))
    x4 = Val(Mid(Message, 4, 1))
    x3 = Val(Mid(Message, 5, 1))
    x2 = Val(Mid(Message, 6, 1))
    x1 = Val(Mid(Message, 7, 1))

    Dim cx As Integer
    Dim cy As Integer
    Dim cz As Integer
    cx = x7 + x5 + x3 + x1
    cy = x6 + x4 + x2
    cz = 3 * cx + cy
    x0 = (10 - cz Mod 10) Mod 10

    Build = fontS _
          & At(fontA, x7) & At(fontA, x6) & At(fontA, x5) & At(fontA, x4) _
          & fontM _
          & At(fontC, x3) & At(fontC, x2) & At(fontC, x1) & At(fontC, x0) _
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
