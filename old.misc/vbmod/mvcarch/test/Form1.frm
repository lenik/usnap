VERSION 5.00
Begin VB.Form Form1
   Caption         =   "MVC Example"
   ClientHeight    =   4380
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7455
   LinkTopic       =   "Form1"
   ScaleHeight     =   4380
   ScaleWidth      =   7455
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   495
      Left            =   600
      TabIndex        =   11
      Top             =   2760
      Width           =   1395
   End
   Begin VB.TextBox day
      Height          =   315
      Left            =   3900
      TabIndex        =   10
      Text            =   "Text1"
      Top             =   1800
      Width           =   375
   End
   Begin VB.TextBox month
      Height          =   315
      Left            =   2940
      TabIndex        =   8
      Text            =   "Text1"
      Top             =   1800
      Width           =   435
   End
   Begin VB.TextBox year
      Height          =   315
      Left            =   1860
      TabIndex        =   6
      Text            =   "Text1"
      Top             =   1800
      Width           =   675
   End
   Begin VB.TextBox sex
      Height          =   315
      Left            =   1860
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   1260
      Width           =   1935
   End
   Begin VB.TextBox txtName
      Height          =   315
      Left            =   1860
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   780
      Width           =   2835
   End
   Begin VB.Label engsex
      Caption         =   "Label1"
      Height          =   255
      Left            =   3960
      TabIndex        =   12
      Top             =   1320
      Width           =   735
   End
   Begin VB.Label Label6
      AutoSize        =   -1  'True
      Caption         =   "day"
      Height          =   195
      Left            =   4380
      TabIndex        =   9
      Top             =   1860
      Width           =   255
   End
   Begin VB.Label Label5
      AutoSize        =   -1  'True
      Caption         =   "month"
      Height          =   195
      Left            =   3480
      TabIndex        =   7
      Top             =   1860
      Width           =   435
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      Caption         =   "year"
      Height          =   195
      Left            =   2580
      TabIndex        =   5
      Top             =   1860
      Width           =   300
   End
   Begin VB.Label Label3
      Caption         =   "Birthday"
      Height          =   315
      Left            =   600
      TabIndex        =   4
      Top             =   1800
      Width           =   975
   End
   Begin VB.Label Label2
      Caption         =   "Sex"
      Height          =   315
      Left            =   600
      TabIndex        =   2
      Top             =   1260
      Width           =   975
   End
   Begin VB.Label lblName
      Caption         =   "Name"
      Height          =   315
      Left            =   600
      TabIndex        =   0
      Top             =   780
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
