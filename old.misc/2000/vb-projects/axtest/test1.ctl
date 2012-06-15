VERSION 5.00
Begin VB.UserControl test1
   ClientHeight    =   3600
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4800
   ScaleHeight     =   3600
   ScaleWidth      =   4800
   Begin VB.Label Label1
      Caption         =   "Hello"
      Height          =   480
      Left            =   135
      TabIndex        =   0
      Top             =   195
      Width           =   1110
   End
End
Attribute VB_Name = "test1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Sub Label1_Click()
        MsgBox "Hello"
End Sub
