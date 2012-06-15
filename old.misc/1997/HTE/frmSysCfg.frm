VERSION 5.00
Begin VB.Form frmSysCfg
   BorderStyle     =   1  'Fixed Single
   Caption         =   "系统配置"
   ClientHeight    =   2250
   ClientLeft      =   45
   ClientTop       =   270
   ClientWidth     =   6375
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2250
   ScaleWidth      =   6375
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command1
      Caption         =   "保存配置并退出"
      Height          =   615
      Left            =   3960
      TabIndex        =   3
      Top             =   1560
      Width           =   1455
   End
   Begin VB.CommandButton Command2
      Caption         =   "取消"
      Height          =   1335
      Left            =   5160
      TabIndex        =   4
      Top             =   720
      Width           =   735
   End
   Begin VB.PictureBox Picture1
      AutoSize        =   -1  'True
      BorderStyle     =   0  'None
      Height          =   480
      Left            =   5280
      Picture         =   "frmSysCfg.frx":0000
      ScaleHeight     =   480
      ScaleWidth      =   480
      TabIndex        =   2
      Top             =   240
      Width           =   480
   End
   Begin VB.TextBox txtSP
      BeginProperty Font
         Name            =   "Arial Black"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   450
      Left            =   1680
      TabIndex        =   1
      Top             =   240
      Width           =   3375
   End
   Begin VB.Label LastPath
      Height          =   255
      Left            =   480
      TabIndex        =   5
      Top             =   1440
      Width           =   2655
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "系统路径"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   300
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   1200
   End
End
Attribute VB_Name = "frmSysCfg"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim PathLoc As Long
Dim t As Integer
  t = RegCreateKey(HKEY_CLASSES_ROOT, "Top Croak\HTE\Software", PathLoc)
  If t <> ERROR_SUCCESS Then MsgBox "注册表注册错误!", vbOKOnly, "注册表错误": Me.Hide
  RegSetValueEx PathLoc, "System Path", 0, REG_SZ, LastPath, Len(LastPath)
  RegCloseKey PathLoc
  Me.Hide
End Sub
Private Sub Command2_Click()
  Me.Hide
End Sub
Private Sub Picture1_Click()
  frmDir.Show 1
  txtSP.Text = LastPath.Caption
End Sub
