VERSION 5.00
Begin VB.Form Form1
   Caption         =   "属性生成"
   ClientHeight    =   3330
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5895
   LinkTopic       =   "Form1"
   ScaleHeight     =   3330
   ScaleWidth      =   5895
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox t
      Height          =   270
      Left            =   1140
      TabIndex        =   5
      Top             =   720
      Width           =   4695
   End
   Begin VB.TextBox d
      Height          =   2175
      Left            =   180
      MultiLine       =   -1  'True
      TabIndex        =   6
      Top             =   1080
      Width           =   5655
   End
   Begin VB.TextBox v
      Height          =   270
      Left            =   1140
      TabIndex        =   3
      Top             =   420
      Width           =   4695
   End
   Begin VB.TextBox p
      Height          =   270
      Left            =   1140
      TabIndex        =   1
      Top             =   120
      Width           =   4695
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Type"
      Height          =   180
      Index           =   2
      Left            =   180
      TabIndex        =   4
      Top             =   780
      Width           =   360
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Var"
      Height          =   180
      Index           =   1
      Left            =   180
      TabIndex        =   2
      Top             =   480
      Width           =   270
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Property"
      Height          =   180
      Index           =   0
      Left            =   180
      TabIndex        =   0
      Top             =   180
      Width           =   720
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim bFirstTime As Boolean

Public Function firstC(ByVal s As String) As String
        firstC = UCase(Left(s, 1))
        If Len(s) > 1 Then firstC = firstC & Mid(s, 2)
End Function

Sub Copy()
        If bFirstTime Then
                d = ""
                bFirstTime = False
        End If
        d = d & "Public Property Get " & p & "() as " & t & ":"
        d = d & p & " = " & v & ":"
        d = d & "End Property" & vbNewLine
        d = d & "Public Property Let " & p & "(ByVal " & "new" & firstC(t) & " As " & t & ")" & vbNewLine
        d = d & vbTab & v & " = " & "new" & firstC(t) & vbNewLine
        d = d & "End Property" & vbNewLine
        Clipboard.SetText d
End Sub

Private Sub d_GotFocus()
        d.SelStart = Len(d)
End Sub

Private Sub d_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then p.SetFocus
End Sub

Private Sub Form_Activate()
        If bFirstTime Then
                d = "the data in clipboard will be cleaned." & vbNewLine
                d = d & "---" & vbNewLine & Clipboard.GetText
        End If
        p.SetFocus
End Sub

Private Sub Form_Load()
        bFirstTime = True
End Sub

Private Sub Form_Resize()
        If Me.WindowState <> 0 Then Exit Sub
        If Width < 2000 Then Width = 2000
        If Height < 2000 Then Height = 2000
        p.Width = Width - 1500
        v.Width = Width - 1500
        t.Width = Width - 1500
        d.Width = Width - 500
        d.Height = Height - 1550
End Sub

Private Sub p_GotFocus()
        p.SelStart = 0: p.SelLength = Len(p)
End Sub
Private Sub v_GotFocus()
        v.SelStart = 0: v.SelLength = Len(v)
End Sub
Private Sub t_GotFocus()
        t.SelStart = 0: t.SelLength = Len(t)
End Sub

Private Sub p_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then v.SetFocus
End Sub
Private Sub v_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then t.SetFocus
End Sub
Private Sub t_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                d.SetFocus
                Copy
        End If
End Sub
