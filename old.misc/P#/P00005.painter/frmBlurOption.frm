VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmBlurOption
   Caption         =   "模糊参数"
   ClientHeight    =   1620
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   1620
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "确定"
      Height          =   375
      Left            =   3060
      TabIndex        =   3
      Top             =   1080
      Width           =   1335
   End
   Begin MSComctlLib.Slider sDepth
      Height          =   255
      Left            =   1140
      TabIndex        =   2
      Top             =   120
      Width           =   3315
      _ExtentX        =   5847
      _ExtentY        =   450
      _Version        =   393216
      Min             =   1
      Max             =   64
      SelStart        =   2
      TickFrequency   =   5
      Value           =   3
   End
   Begin MSComctlLib.Slider sLevel
      Height          =   255
      Left            =   1140
      TabIndex        =   4
      Top             =   600
      Width           =   3315
      _ExtentX        =   5847
      _ExtentY        =   450
      _Version        =   393216
      LargeChange     =   50
      Min             =   -127
      Max             =   127
      SelStart        =   4
      TickFrequency   =   20
      Value           =   4
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "混合程度"
      Height          =   195
      Left            =   180
      TabIndex        =   1
      Top             =   180
      Width           =   720
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "模糊程度"
      Height          =   195
      Left            =   180
      TabIndex        =   0
      Top             =   600
      Width           =   720
   End
End
Attribute VB_Name = "frmBlurOption"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Me.Hide
End Sub
