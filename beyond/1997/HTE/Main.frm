VERSION 5.00
Begin VB.Form Main
   Caption         =   "烘培鸡窝"
   ClientHeight    =   5280
   ClientLeft      =   165
   ClientTop       =   450
   ClientWidth     =   7665
   LinkTopic       =   "Form1"
   ScaleHeight     =   5280
   ScaleWidth      =   7665
   StartUpPosition =   2  'CenterScreen
   Begin VB.PictureBox cmdToEngVer
      AutoSize        =   -1  'True
      BorderStyle     =   0  'None
      Height          =   495
      Left            =   2280
      ScaleHeight     =   495
      ScaleWidth      =   4875
      TabIndex        =   1
      ToolTipText     =   "英语版本"
      Top             =   360
      Width           =   4875
   End
   Begin VB.Label Label1
      Caption         =   "Label1"
      Height          =   1215
      Left            =   480
      TabIndex        =   2
      Top             =   1440
      Width           =   2055
   End
   Begin VB.Label lblHpjw
      AutoSize        =   -1  'True
      BeginProperty Font
         Name            =   "宋体"
         Size            =   18
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   360
      Left            =   480
      TabIndex        =   0
      Top             =   480
      Width           =   210
   End
   Begin VB.Menu mnuFile
      Caption         =   "&F文件"
      Begin VB.Menu mnuFOpen
         Caption         =   "打开文件"
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuFOpenas
         Caption         =   "按类型打开文件"
      End
      Begin VB.Menu mnuFS
         Caption         =   "保存"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuExit
         Caption         =   "退出"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu mnuChange
      Caption         =   "&T变异类型"
      Begin VB.Menu mnuCT
         Caption         =   "普通鸡"
         Index           =   0
      End
      Begin VB.Menu mnuCT
         Caption         =   "烘培鸡"
         Index           =   1
      End
      Begin VB.Menu mnuCT
         Caption         =   "电子自动鸡"
         Index           =   2
      End
   End
   Begin VB.Menu mnuH
      Caption         =   "&H帮助"
      Begin VB.Menu mnuHI
         Caption         =   "索引"
         Shortcut        =   {F1}
      End
      Begin VB.Menu mnuIS
         Caption         =   "-"
      End
      Begin VB.Menu mnuHA
         Caption         =   "关于烘培鸡窝"
      End
   End
End
Attribute VB_Name = "Main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

' Sys Requires
Dim Language As Integer
Const verChinese = 1, verEnglish = 2

Dim SysLoc$
Private Sub Form_Load()
  GetSystemEnv

  Language = verChinese
  Select Case Language
    Case verChinese:
        lblHpjw = "烘培鸡窝"
        Language = verEnglish: cmdToEngVer_Click
    Case verEnglish:
        lblHpjw = "Hyper Text Eyry"
        Language = verChinese: cmdToEngVer_Click
    Case Else
        MsgBox "系统语言错误", vbRetryCancel, "系统错误"
        End
  End Select
End Sub
Private Sub cmdToEngVer_Click()
  Language = 3 - Language
  If Language = verEnglish Then cmdToEngVer.Picture = LoadPicture("HTE\Images\Chines~1.jpg")
  If Language = verChinese Then cmdToEngVer.Picture = LoadPicture("HTE\Images\Englis~1.jpg")
End Sub
Private Sub mnuCT_Click(Index As Integer)
  mnuCT(0).Checked = False
  mnuCT(1).Checked = False
  mnuCT(2).Checked = False
  mnuCT(Index).Checked = True
End Sub
Private Sub mnuExit_Click()
  End
End Sub
