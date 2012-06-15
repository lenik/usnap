VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   4110
   ClientLeft      =   1800
   ClientTop       =   2685
   ClientWidth     =   7110
   LinkTopic       =   "Form1"
   ScaleHeight     =   4110
   ScaleWidth      =   7110
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   945
      Left            =   2700
      TabIndex        =   2
      Top             =   2130
      Width           =   2130
   End
   Begin VB.TextBox Text2
      Height          =   720
      Left            =   3375
      TabIndex        =   1
      Text            =   "Text2"
      Top             =   840
      Width           =   2280
   End
   Begin VB.TextBox Text1
      Height          =   735
      Left            =   915
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   780
      Width           =   1335
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Dim c1 As Long, c2 As Long
        c1 = Val(Text1.Text)
        c2 = Val(Text2.Text)
        Command1.Caption = CeLIColorRgb24Plus(c1, c2)
End Sub
