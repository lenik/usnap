VERSION 5.00
Begin VB.Form frmMain
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "东晖文学站 投稿指南"
   ClientHeight    =   3300
   ClientLeft      =   1155
   ClientTop       =   1725
   ClientWidth     =   5925
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3300
   ScaleWidth      =   5925
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton cmdNext
      Caption         =   "&N下一步"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   315
      Left            =   4740
      TabIndex        =   10
      Top             =   2760
      Width           =   975
   End
   Begin VB.TextBox txtLeave
      ForeColor       =   &H00FF8080&
      Height          =   285
      Left            =   1500
      TabIndex        =   9
      Top             =   2340
      Width           =   3735
   End
   Begin VB.TextBox txtClass02
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
      Height          =   315
      Left            =   1860
      TabIndex        =   5
      Text            =   "电脑"
      Top             =   1920
      Width           =   735
   End
   Begin VB.TextBox txtClass01
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
      Height          =   315
      Left            =   1500
      TabIndex        =   4
      Text            =   "98"
      Top             =   1920
      Width           =   375
   End
   Begin VB.CommandButton cmdSI
      Caption         =   "&I 自我介绍"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   315
      Left            =   4080
      TabIndex        =   7
      Top             =   1920
      Width           =   1155
   End
   Begin VB.TextBox txtContributor
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
      Height          =   315
      Left            =   2700
      TabIndex        =   6
      Text            =   "佚名"
      Top             =   1920
      Width           =   1275
   End
   Begin VB.ComboBox cboSubject
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
      Height          =   300
      ItemData        =   "Main.frx":030A
      Left            =   1500
      List            =   "Main.frx":031D
      Style           =   2  'Dropdown List
      TabIndex        =   2
      Top             =   1500
      Width           =   3735
   End
   Begin VB.Label Label9
      AutoSize        =   -1  'True
      Caption         =   "提示: 按下ALT键再按下划线字符快速选择, 按TAB键切换"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00404040&
      Height          =   180
      Left            =   180
      TabIndex        =   15
      Top             =   2820
      Width           =   4500
   End
   Begin VB.Label lblLeave
      AutoSize        =   -1  'True
      Caption         =   "&3留言:"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00808000&
      Height          =   225
      Left            =   420
      TabIndex        =   8
      Top             =   2340
      Width           =   690
   End
   Begin VB.Label lblContributor
      AutoSize        =   -1  'True
      Caption         =   "&2荐稿者:"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00808000&
      Height          =   225
      Left            =   420
      TabIndex        =   3
      Top             =   1920
      Width           =   915
   End
   Begin VB.Label Label6
      AutoSize        =   -1  'True
      Caption         =   "CONTRIBUTION FINGERPOST"
      ForeColor       =   &H00008000&
      Height          =   195
      Left            =   1740
      TabIndex        =   14
      Top             =   1200
      Width           =   2310
   End
   Begin VB.Label Label5
      AutoSize        =   -1  'True
      Caption         =   "作者: 谢继雷"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   180
      Left            =   3840
      TabIndex        =   13
      Top             =   480
      Width           =   1080
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      Caption         =   "[TOPCROAK] 桃壳软件"
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
      Height          =   180
      Left            =   3840
      TabIndex        =   12
      Top             =   240
      Width           =   1710
   End
   Begin VB.Label lblSubject
      AutoSize        =   -1  'True
      Caption         =   "&1主题:"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00808000&
      Height          =   225
      Left            =   420
      TabIndex        =   0
      Top             =   1500
      Width           =   690
   End
   Begin VB.Line Line1
      BorderColor     =   &H00808080&
      BorderStyle     =   6  'Inside Solid
      Index           =   1
      X1              =   180
      X2              =   5744
      Y1              =   2700
      Y2              =   2700
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "投稿指南"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004000&
      Height          =   315
      Left            =   2160
      TabIndex        =   11
      Top             =   780
      Width           =   1335
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "东 晖 文 学 站"
      BeginProperty Font
         Name            =   "楷体_GB2312"
         Size            =   24
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   495
      Left            =   180
      TabIndex        =   1
      Top             =   180
      Width           =   3510
   End
   Begin VB.Line Line1
      BorderColor     =   &H00FFFFFF&
      BorderWidth     =   2
      Index           =   0
      X1              =   180
      X2              =   5729
      Y1              =   2700
      Y2              =   2700
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Sub Init()
    Enter = Chr(13)
    NewLine = Chr(13) + Chr(10)

    SaveDir = "F:\Config\DongHui\Mail\"

    ArticleDir = "Article\"
    SuggestDir = "Suggest\"
    FriendDir = "Friend\"
    LetterDir = "Letter\"

    cboSubject.ListIndex = 0

End Sub

Private Sub cboSubject_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtClass01.SetFocus
End Sub

Private Sub cmdNext_Click()

    Head = lblSubject + Space + cboSubject.Text + NewLine
    Head = Head + lblContributor + Space + txtClass01 + txtClass02 + txtContributor + Enter
    Head = Head + lblLeave + Space + txtLeave

    Select Case cboSubject.ListIndex
        Case 0:
            frmArticle.Show 1
        Case 1, 2:
            frmSuggestCorrect.Show 1
        Case 3:
            frmFriend.Show 1
        Case 4:
            frmLetter.Show 1
    End Select
End Sub

Private Sub cmdSI_Click()
    frmSelfIntro.Show 1
End Sub

Private Sub Form_Load()
    Init
End Sub

Private Sub txtClass01_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtClass02.SetFocus
End Sub

Private Sub txtClass02_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtContributor.SetFocus
End Sub

Private Sub txtContributor_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtLeave.SetFocus
End Sub

Private Sub txtLeave_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then cmdNext.SetFocus
End Sub
