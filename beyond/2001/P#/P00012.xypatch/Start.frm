VERSION 5.00
Begin VB.Form frmStart
   BackColor       =   &H00C0E0FF&
   Caption         =   "吾乃游戏大师也!"
   ClientHeight    =   4245
   ClientLeft      =   1605
   ClientTop       =   2940
   ClientWidth     =   6645
   Icon            =   "Start.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4245
   ScaleWidth      =   6645
   Begin VB.CommandButton Command1
      Caption         =   "..&Bye..bye.."
      Height          =   375
      Index           =   1
      Left            =   5100
      TabIndex        =   7
      Top             =   3540
      Width           =   1095
   End
   Begin VB.CommandButton Command1
      Caption         =   "&Go!!!"
      Default         =   -1  'True
      Height          =   375
      Index           =   0
      Left            =   3780
      TabIndex        =   6
      Top             =   3540
      Width           =   1095
   End
   Begin VB.PictureBox Picture1
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   2505
      Left            =   375
      Picture         =   "Start.frx":030A
      ScaleHeight     =   2505
      ScaleWidth      =   3150
      TabIndex        =   5
      Top             =   1440
      Width           =   3150
   End
   Begin VB.TextBox txtIntro
      Appearance      =   0  'Flat
      BackColor       =   &H00C0E0FF&
      BorderStyle     =   0  'None
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   1845
      Left            =   3750
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   2
      Text            =   "Start.frx":4ECA
      Top             =   1500
      Width           =   2685
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "谢继雷/桃壳软件 1999.8.22"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF8080&
      Height          =   180
      Left            =   4185
      TabIndex        =   4
      Top             =   1155
      Width           =   2250
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "XY-Patch 版本 0.01a"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   180
      Left            =   4185
      TabIndex        =   3
      Top             =   930
      Width           =   1710
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      BorderStyle     =   1  'Fixed Single
      Caption         =   "  桃 壳 软 件 - 畅 通 游 戏 界 !  "
      BeginProperty Font
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF8080&
      Height          =   300
      Left            =   450
      TabIndex        =   1
      Top             =   405
      Width           =   4140
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "翔 宇 打 补 丁 专 家"
      BeginProperty Font
         Name            =   "楷体_GB2312"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   285
      Left            =   960
      TabIndex        =   0
      Top             =   960
      Width           =   3000
   End
End
Attribute VB_Name = "frmStart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click(Index As Integer)
  If Index = 1 Then End
  Me.Hide
  frmMain.Show
End Sub
