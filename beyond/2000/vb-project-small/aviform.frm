VERSION 5.00
Begin VB.Form Form1
   Caption         =   "c"
   ClientHeight    =   3735
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5880
   LinkTopic       =   "Form1"
   ScaleHeight     =   3735
   ScaleWidth      =   5880
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "restart"
      Height          =   255
      Left            =   4800
      TabIndex        =   10
      Top             =   2280
      Width           =   975
   End
   Begin VB.CommandButton Command3
      Caption         =   "close"
      Enabled         =   0   'False
      Height          =   375
      Index           =   8
      Left            =   4920
      TabIndex        =   9
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   "pause"
      Enabled         =   0   'False
      Height          =   375
      Index           =   7
      Left            =   4320
      TabIndex        =   8
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   ">>|"
      Enabled         =   0   'False
      Height          =   375
      Index           =   6
      Left            =   3720
      TabIndex        =   7
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   ">"
      Enabled         =   0   'False
      Height          =   375
      Index           =   5
      Left            =   3120
      TabIndex        =   6
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   "[]"
      Enabled         =   0   'False
      Height          =   375
      Index           =   4
      Left            =   2520
      TabIndex        =   5
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   "<"
      Enabled         =   0   'False
      Height          =   375
      Index           =   3
      Left            =   1920
      TabIndex        =   4
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   "|<<"
      Enabled         =   0   'False
      Height          =   375
      Index           =   2
      Left            =   1320
      TabIndex        =   3
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   "play"
      Enabled         =   0   'False
      Height          =   375
      Index           =   1
      Left            =   720
      TabIndex        =   2
      Top             =   3120
      Width           =   615
   End
   Begin VB.CommandButton Command3
      Caption         =   "open"
      Height          =   375
      Index           =   0
      Left            =   120
      TabIndex        =   1
      Top             =   3120
      Width           =   615
   End
   Begin VB.PictureBox Picture1
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   2655
      Left            =   720
      ScaleHeight     =   2625
      ScaleWidth      =   4185
      TabIndex        =   0
      Top             =   240
      Width           =   4215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim returnstr As String * 128

Private Sub Command1_Click()
    mciExecute "close AVI"
End Sub

Private Sub Command3_Click(Index As Integer)
    Select Case Index
    Case 0
        avifile = "z:\t.avi"
        e = mciSendString("open " + avifile + " type avivideo alias AVI", returnstr, 128, 0)
        If e = 0 Then
            For i = 1 To 8: Command3(i).Enabled = True: Next
            Command3(0).Enabled = False
            r = mciExecute("set AVI time format frames")
            e = mciSendString("status AVI length", returnstr, 128, 0)
            tal = Val(Left(returnstr, InStr(1, returnstr, Chr$(0)) - 1))
            r = mciExecute("window AVI handle" + Str(Picture1.hWnd))
            r = mciExecute("cue AVI to 0")
        End If
    Case 1
        mciExecute "play AVI"
    Case 2
        mciExecute "seek AVI to start"
    Case 3
        mciExecute "step AVI reverse by 1"
    Case 4
        mciExecute "stop AVI"
    Case 5
        mciExecute "step AVI by 1"
    Case 6
        mciExecute "seek AVI to end"
    Case 7
        e = mciSendString("status AVI mode", returnstr, 128, 0)
        If Left(returnstr, InStr(1, returnstr, Chr(0)) - 1) = "playing" Then
            mciExecute "pause AVI"
        ElseIf Left(returnstr, InStr(1, returnstr, Chr(0)) - 1) = "paused" Then
            mciExecute "play AVI"
        End If
    Case 8
        mciExecute "close AVI"
        For i = 1 To 8: Command3(i).Enabled = False: Next
        Command3(0).Enabled = True



    End Select
End Sub
