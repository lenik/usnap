VERSION 5.00
Begin VB.Form frmRotateOption
   Caption         =   "设置旋转角度"
   ClientHeight    =   1725
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3300
   LinkTopic       =   "Form1"
   ScaleHeight     =   1725
   ScaleWidth      =   3300
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1
      Caption         =   "确定"
      Height          =   375
      Left            =   1920
      TabIndex        =   3
      Top             =   1260
      Width           =   1275
   End
   Begin VB.OptionButton opt270
      Caption         =   "旋转270度"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1080
      Width           =   1575
   End
   Begin VB.OptionButton opt180
      Caption         =   "旋转180度"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   660
      Width           =   1575
   End
   Begin VB.OptionButton opt90
      Caption         =   "旋转90度"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Value           =   -1  'True
      Width           =   1575
   End
End
Attribute VB_Name = "frmRotateOption"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Me.Hide
End Sub
