VERSION 5.00
Begin VB.Form frmviewm
   Caption         =   "���̵�ģ�����"
   ClientHeight    =   2820
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5445
   LinkTopic       =   "Form2"
   ScaleHeight     =   2820
   ScaleWidth      =   5445
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4
      Caption         =   "�����ý���"
      Height          =   375
      Left            =   3960
      TabIndex        =   0
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ģ��ID:"
      Height          =   180
      Index           =   0
      Left            =   240
      TabIndex        =   14
      Top             =   240
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "����ID:"
      Height          =   180
      Index           =   1
      Left            =   240
      TabIndex        =   13
      Top             =   960
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ʹ�ü���:"
      Height          =   180
      Index           =   2
      Left            =   240
      TabIndex        =   12
      Top             =   1320
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ģ����ʼ��ַ:"
      Height          =   180
      Index           =   3
      Left            =   240
      TabIndex        =   11
      Top             =   1680
      Width           =   1170
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ģ���С:"
      Height          =   180
      Index           =   4
      Left            =   240
      TabIndex        =   10
      Top             =   2040
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ģ����:"
      Height          =   180
      Index           =   5
      Left            =   240
      TabIndex        =   9
      Top             =   2400
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ģ������:"
      Height          =   180
      Index           =   6
      Left            =   240
      TabIndex        =   8
      Top             =   600
      Width           =   810
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   0
      Left            =   1440
      TabIndex        =   7
      Top             =   240
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   1
      Left            =   1440
      TabIndex        =   6
      Top             =   600
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   2
      Left            =   1440
      TabIndex        =   5
      Top             =   960
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   3
      Left            =   1440
      TabIndex        =   4
      Top             =   1320
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   4
      Left            =   1440
      TabIndex        =   3
      Top             =   1680
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   5
      Left            =   1440
      TabIndex        =   2
      Top             =   2040
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   6
      Left            =   1440
      TabIndex        =   1
      Top             =   2400
      Width           =   90
   End
End
Attribute VB_Name = "frmviewm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub Command4_Click()
        Dim pid
        pid = val("&H" & PI(2))

        ' ����һ������Ϊfrmviewp�Ĵ���
        Dim v As New frmviewp
        ' �ø�ģ���������� ��ʼ�������ֶ�
        v.init pid
        ' ��ʾ����
        v.Show
End Sub
