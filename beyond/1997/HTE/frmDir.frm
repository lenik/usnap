VERSION 5.00
Begin VB.Form frmDir
   Caption         =   "ÏµÍ³Â·¾¶"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdCancel
      Caption         =   "l"
      Height          =   1095
      Index           =   5
      Left            =   3840
      TabIndex        =   8
      Top             =   1680
      Width           =   255
   End
   Begin VB.CommandButton cmdCancel
      Caption         =   "e"
      Height          =   1095
      Index           =   4
      Left            =   3600
      TabIndex        =   7
      Top             =   1680
      Width           =   255
   End
   Begin VB.CommandButton cmdCancel
      Caption         =   "c"
      Height          =   1095
      Index           =   3
      Left            =   3360
      TabIndex        =   6
      Top             =   1680
      Width           =   255
   End
   Begin VB.CommandButton cmdCancel
      Caption         =   "n"
      Height          =   1095
      Index           =   2
      Left            =   3120
      TabIndex        =   5
      Top             =   1680
      Width           =   255
   End
   Begin VB.CommandButton cmdCancel
      Caption         =   "a"
      Height          =   1095
      Index           =   1
      Left            =   2880
      TabIndex        =   4
      Top             =   1680
      Width           =   255
   End
   Begin VB.CommandButton cmdCancel
      Caption         =   "&C"
      Height          =   1095
      Index           =   0
      Left            =   2640
      TabIndex        =   3
      Top             =   1680
      Width           =   255
   End
   Begin VB.CommandButton cmdOK
      Caption         =   "&OK"
      Height          =   975
      Left            =   2160
      TabIndex        =   2
      Top             =   240
      Width           =   2415
   End
   Begin VB.DirListBox Dir1
      Height          =   2340
      Left            =   240
      TabIndex        =   1
      Top             =   600
      Width           =   1815
   End
   Begin VB.DriveListBox Drive1
      Height          =   300
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   1815
   End
End
Attribute VB_Name = "frmDir"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdCancel_Click(Index As Integer)
  Me.Hide
End Sub
Private Sub cmdOK_Click()
  frmSysCfg.LastPath.Caption = Dir1.Path
  Me.Hide
End Sub
Private Sub Drive1_Change()
  Dir1.Path = Drive1.Drive
End Sub
