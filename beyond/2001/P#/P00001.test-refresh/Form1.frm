VERSION 5.00
Begin VB.Form Form1
   Caption         =   "不停的刷新为什么不会闪烁"
   ClientHeight    =   3960
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5025
   LinkTopic       =   "Form1"
   ScaleHeight     =   3960
   ScaleWidth      =   5025
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3
      Caption         =   "stop"
      Height          =   615
      Left            =   3000
      TabIndex        =   4
      Top             =   2640
      Width           =   1215
   End
   Begin VB.CommandButton Command2
      Caption         =   "inf"
      Height          =   615
      Left            =   1680
      TabIndex        =   2
      Top             =   2640
      Width           =   1095
   End
   Begin VB.CommandButton Command1
      Caption         =   "1"
      Height          =   615
      Left            =   360
      TabIndex        =   1
      Top             =   2640
      Width           =   1095
   End
   Begin VB.PictureBox p
      AutoRedraw      =   -1  'True
      Height          =   2175
      Left            =   360
      ScaleHeight     =   2115
      ScaleWidth      =   3795
      TabIndex        =   0
      Top             =   360
      Width           =   3855
   End
   Begin VB.Label Label1
      Caption         =   "Label1"
      Height          =   255
      Left            =   360
      TabIndex        =   3
      Top             =   3360
      Width           =   3855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim b As Boolean

Private Sub Command1_Click()
    p.BackColor = QBColor(15)
    p.Refresh

End Sub

Private Sub Command2_Click()
    b = True
    Do While b
        Command1_Click
        DoEvents
        Label1 = Val(Label1) + 1
    Loop
End Sub

Private Sub Command3_Click()
    b = False
End Sub
