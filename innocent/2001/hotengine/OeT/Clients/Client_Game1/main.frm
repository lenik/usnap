VERSION 5.00
Begin VB.Form Form1
   Caption         =   "array test"
   ClientHeight    =   4695
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7470
   LinkTopic       =   "Form1"
   ScaleHeight     =   4695
   ScaleWidth      =   7470
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command3
      Caption         =   "Command3"
      Height          =   1425
      Left            =   105
      TabIndex        =   4
      Top             =   300
      Width           =   525
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   825
      Left            =   5475
      TabIndex        =   3
      Top             =   1650
      Width           =   915
   End
   Begin VB.CommandButton Command1
      Caption         =   "hashtest"
      Height          =   525
      Left            =   5190
      TabIndex        =   2
      Top             =   135
      Width           =   2145
   End
   Begin VB.ListBox List1
      Height          =   3300
      Left            =   885
      TabIndex        =   1
      Top             =   195
      Width           =   4215
   End
   Begin VB.TextBox t
      Height          =   540
      Index           =   0
      Left            =   900
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   3930
      Width           =   4215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public a As New OeTArray

Public Sub r()
        Dim i As Integer
        List1.Clear
        For i = 0 To a.Count - 1
                List1.AddItem a.member(i)
        Next
End Sub

Private Sub Command1_Click()
        hashtest.Show
End Sub

Private Sub Command2_Click()
        a.Clear
        r
End Sub

Private Sub Command3_Click()
        a.Add "Hello, world"
        a.Add "Oh, my god, who knock you"
        a.Add "I love you, china"
        a.Add "where is my key"
        a.Add "computer vs calcer"
        a.Add "all done"
        a.Add "everything seems ok"
        a.Add "hello, baby"
        r
End Sub

Private Sub Form_Load()
        Command3_Click
End Sub

Private Sub List1_DblClick()
        Dim ll As Long
        ll = a.Remove(List1.ListIndex, 1)
        r
End Sub

Private Sub t_KeyPress(Index As Integer, KeyAscii As Integer)
        Dim n As Integer
        If KeyAscii = 13 Then
                n = a.Count
                On Error Resume Next
                Load t(n)
                On Error GoTo 0
                t(n).Text = t(0).Text
                a.Add t(n).Text, IIf(List1.ListIndex >= 0, List1.ListIndex, -1)
                r
                t(0).Text = ""
                KeyAscii = 0
        End If
End Sub
