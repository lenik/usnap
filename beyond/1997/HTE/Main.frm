VERSION 5.00
Begin VB.Form Main
   Caption         =   "���༦��"
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
      ToolTipText     =   "Ӣ��汾"
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
         Name            =   "����"
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
      Caption         =   "&F�ļ�"
      Begin VB.Menu mnuFOpen
         Caption         =   "���ļ�"
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuFOpenas
         Caption         =   "�����ʹ��ļ�"
      End
      Begin VB.Menu mnuFS
         Caption         =   "����"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuExit
         Caption         =   "�˳�"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu mnuChange
      Caption         =   "&T��������"
      Begin VB.Menu mnuCT
         Caption         =   "��ͨ��"
         Index           =   0
      End
      Begin VB.Menu mnuCT
         Caption         =   "���༦"
         Index           =   1
      End
      Begin VB.Menu mnuCT
         Caption         =   "�����Զ���"
         Index           =   2
      End
   End
   Begin VB.Menu mnuH
      Caption         =   "&H����"
      Begin VB.Menu mnuHI
         Caption         =   "����"
         Shortcut        =   {F1}
      End
      Begin VB.Menu mnuIS
         Caption         =   "-"
      End
      Begin VB.Menu mnuHA
         Caption         =   "���ں��༦��"
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
        lblHpjw = "���༦��"
        Language = verEnglish: cmdToEngVer_Click
    Case verEnglish:
        lblHpjw = "Hyper Text Eyry"
        Language = verChinese: cmdToEngVer_Click
    Case Else
        MsgBox "ϵͳ���Դ���", vbRetryCancel, "ϵͳ����"
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
