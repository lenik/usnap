VERSION 5.00
Begin VB.Form frmviewt
   Caption         =   "进程中的一个线程分析"
   ClientHeight    =   2490
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4155
   LinkTopic       =   "Form2"
   ScaleHeight     =   2490
   ScaleWidth      =   4155
   StartUpPosition =   3  'Windows Default
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "线程ID:"
      Height          =   180
      Index           =   0
      Left            =   240
      TabIndex        =   11
      Top             =   240
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "拥有者进程ID:"
      Height          =   180
      Index           =   1
      Left            =   240
      TabIndex        =   10
      Top             =   600
      Width           =   1170
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "使用计数:"
      Height          =   180
      Index           =   2
      Left            =   240
      TabIndex        =   9
      Top             =   960
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "基本特权等级:"
      Height          =   180
      Index           =   3
      Left            =   240
      TabIndex        =   8
      Top             =   1320
      Width           =   1170
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "增量特权等级:"
      Height          =   180
      Index           =   4
      Left            =   240
      TabIndex        =   7
      Top             =   1680
      Width           =   1170
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "标志:"
      Height          =   180
      Index           =   5
      Left            =   240
      TabIndex        =   6
      Top             =   2040
      Width           =   450
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   0
      Left            =   1440
      TabIndex        =   5
      Top             =   240
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   1
      Left            =   1440
      TabIndex        =   4
      Top             =   600
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   2
      Left            =   1440
      TabIndex        =   3
      Top             =   960
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   3
      Left            =   1440
      TabIndex        =   2
      Top             =   1320
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   4
      Left            =   1440
      TabIndex        =   1
      Top             =   1680
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   5
      Left            =   1440
      TabIndex        =   0
      Top             =   2040
      Width           =   90
   End
End
Attribute VB_Name = "frmviewt"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
