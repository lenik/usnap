VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   1995
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5550
   LinkTopic       =   "Form1"
   ScaleHeight     =   1995
   ScaleWidth      =   5550
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   8
      Left            =   4920
      TabIndex        =   8
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   7
      Left            =   4320
      TabIndex        =   7
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   6
      Left            =   3720
      TabIndex        =   6
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   5
      Left            =   3120
      TabIndex        =   5
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   4
      Left            =   2520
      TabIndex        =   4
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   3
      Left            =   1920
      TabIndex        =   3
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   2
      Left            =   1320
      TabIndex        =   2
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   1
      Left            =   720
      TabIndex        =   1
      Top             =   600
      Width           =   495
   End
   Begin VB.CommandButton cmdBut
      Caption         =   "1"
      Height          =   615
      Index           =   0
      Left            =   120
      TabIndex        =   0
      Top             =   600
      Width           =   495
   End
   Begin VB.Label lblCount
      Caption         =   "0"
      Height          =   495
      Left            =   3480
      TabIndex        =   9
      Top             =   1440
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Const MAXSTEPS = 10
Const BUTTONSNUM = 9

Private Sub cmdBut_Click(Index As Integer)
    For i = 0 To Index / 2
        t = cmdBut(i).Caption
        cmdBut(i).Caption = cmdBut(Index - i).Caption
        cmdBut(Index - i).Caption = t
    Next
    lblCount = Str(Val(lblCount) - 1)
    If judge Then
        If MsgBox("u win, again?", vbYesNo) = vbYes Then
            Form_Initialize
        Else
            End
        End If
    End If
    If Val(lblCount) <= 0 Then
        If MsgBox("u lost, again?", vbYesNo) = vbYes Then
            Form_Initialize
        Else
            End
        End If
    End If
End Sub

Private Sub Form_Initialize()
    Randomize Timer
    lblCount.Caption = Str(MAXSTEPS)
    For i = 1 To BUTTONSNUM
        cmdBut(i - 1).Caption = Str(i)
    Next
    For i = 1 To 10
        nn = Int(Rnd * BUTTONSNUM)
        t = cmdBut(0).Caption
        cmdBut(0).Caption = cmdBut(nn).Caption
        cmdBut(nn).Caption = t
    Next
End Sub

Private Function judge() As Boolean
    For i = 0 To BUTTONSNUM - 1
        If Val(cmdBut(i).Caption) <> i + 1 Then
            judge = False
            Exit Function
        End If
    Next
    judge = True
End Function
