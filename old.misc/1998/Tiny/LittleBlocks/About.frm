VERSION 5.00
Begin VB.Form frmAbout
   Caption         =   "����С��ľ"
   ClientHeight    =   2775
   ClientLeft      =   1380
   ClientTop       =   3150
   ClientWidth     =   4800
   Icon            =   "About.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   2775
   ScaleWidth      =   4800
   StartUpPosition =   1  '����������
   Begin VB.CommandButton Command1
      Caption         =   "&X ����"
      BeginProperty Font
         Name            =   "����"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   240
      TabIndex        =   8
      Top             =   2160
      Width           =   1635
   End
   Begin VB.Label Label8
      AutoSize        =   -1  'True
      Caption         =   "http://dansei.yeah.net"
      ForeColor       =   &H00004000&
      Height          =   195
      Left            =   660
      TabIndex        =   7
      Top             =   1020
      Width           =   1590
   End
   Begin VB.Label Label7
      AutoSize        =   -1  'True
      Caption         =   "dansei@163.net"
      ForeColor       =   &H00004000&
      Height          =   195
      Left            =   660
      TabIndex        =   6
      Top             =   1380
      Width           =   1170
   End
   Begin VB.Label Label6
      Caption         =   "�����ϲ�������Ϸ��ĸ���һ�ſ�Ƭ, лл!"
      ForeColor       =   &H00FF8080&
      Height          =   495
      Left            =   2460
      TabIndex        =   5
      Top             =   1320
      Width           =   2055
   End
   Begin VB.Label Label5
      AutoSize        =   -1  'True
      Caption         =   "���� PRESENT"
      ForeColor       =   &H00404040&
      Height          =   180
      Left            =   3360
      TabIndex        =   4
      Top             =   120
      Width           =   1080
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      Caption         =   "����: л����, 1999.3.18"
      BeginProperty Font
         Name            =   "����"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   210
      Left            =   2160
      TabIndex        =   3
      Top             =   2340
      Width           =   2415
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "�ҿ����"
      BeginProperty Font
         Name            =   "����"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   210
      Left            =   3720
      TabIndex        =   2
      Top             =   2040
      Width           =   840
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "��������õ�Windows�µĶ�ά��ľ!"
      BeginProperty Font
         Name            =   "����"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   240
      Left            =   360
      TabIndex        =   1
      Top             =   600
      Width           =   4155
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "��ȸ��С �����ȫ"
      BeginProperty Font
         Name            =   "����"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00404080&
      Height          =   285
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2430
   End
End
Attribute VB_Name = "frmAbout"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Me.Hide
End Sub

Private Sub Form_Load()

End Sub
