VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Stream Compare"
   ClientHeight    =   4920
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6885
   LinkTopic       =   "Form1"
   ScaleHeight     =   4920
   ScaleWidth      =   6885
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox obj
      Height          =   1635
      Left            =   540
      TabIndex        =   3
      Text            =   "Text2"
      Top             =   1800
      Width           =   5835
   End
   Begin VB.TextBox ref
      Height          =   1575
      Left            =   540
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   120
      Width           =   5835
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "缺少："
      Height          =   180
      Index           =   3
      Left            =   60
      TabIndex        =   7
      Top             =   4500
      Width           =   540
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "多余："
      Height          =   180
      Index           =   2
      Left            =   60
      TabIndex        =   6
      Top             =   4200
      Width           =   540
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "错误："
      Height          =   180
      Index           =   1
      Left            =   60
      TabIndex        =   5
      Top             =   3900
      Width           =   540
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "正确："
      Height          =   180
      Index           =   0
      Left            =   60
      TabIndex        =   4
      Top             =   3600
      Width           =   540
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "dest"
      Height          =   180
      Left            =   60
      TabIndex        =   2
      Top             =   1800
      Width           =   360
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Src"
      Height          =   180
      Left            =   120
      TabIndex        =   0
      Top             =   180
      Width           =   270
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
