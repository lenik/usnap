VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5160
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8460
   LinkTopic       =   "Form1"
   ScaleHeight     =   5160
   ScaleWidth      =   8460
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdTest
      Caption         =   "Test"
      Height          =   1095
      Left            =   600
      TabIndex        =   12
      Top             =   3720
      Width           =   1455
   End
   Begin VB.OptionButton optSelected
      Height          =   375
      Index           =   3
      Left            =   480
      TabIndex        =   11
      Top             =   3000
      Width           =   555
   End
   Begin VB.TextBox txtValue
      Height          =   375
      Index           =   3
      Left            =   1260
      TabIndex        =   10
      Top             =   3000
      Width           =   3195
   End
   Begin VB.OptionButton optSelected
      Height          =   375
      Index           =   2
      Left            =   480
      TabIndex        =   9
      Top             =   2340
      Width           =   555
   End
   Begin VB.TextBox txtValue
      Height          =   375
      Index           =   2
      Left            =   1260
      TabIndex        =   8
      Top             =   2340
      Width           =   3195
   End
   Begin VB.OptionButton optSelected
      Height          =   375
      Index           =   1
      Left            =   480
      TabIndex        =   7
      Top             =   1680
      Width           =   555
   End
   Begin VB.TextBox txtValue
      Height          =   375
      Index           =   1
      Left            =   1260
      TabIndex        =   6
      Top             =   1680
      Width           =   3195
   End
   Begin VB.OptionButton optSelected
      Height          =   375
      Index           =   0
      Left            =   480
      TabIndex        =   5
      Top             =   1020
      Width           =   555
   End
   Begin VB.TextBox txtValue
      Height          =   375
      Index           =   0
      Left            =   1260
      TabIndex        =   4
      Top             =   1020
      Width           =   3195
   End
   Begin VB.CommandButton cmdRemove
      Caption         =   "&Remove"
      Height          =   375
      Left            =   2940
      TabIndex        =   3
      Top             =   4440
      Width           =   735
   End
   Begin VB.CommandButton cmdAdd
      Caption         =   "&Add"
      Height          =   375
      Left            =   3900
      TabIndex        =   1
      Top             =   4440
      Width           =   735
   End
   Begin VB.ListBox lstData
      Height          =   3375
      Left            =   5340
      TabIndex        =   0
      Top             =   1020
      Width           =   2355
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Internal Data Structure"
      Height          =   195
      Left            =   5100
      TabIndex        =   2
      Top             =   660
      Width           =   1605
   End
   Begin VB.Line Line1
      X1              =   4920
      X2              =   4920
      Y1              =   300
      Y2              =   4860
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
