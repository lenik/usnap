VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   5715
   ClientLeft      =   1650
   ClientTop       =   1545
   ClientWidth     =   6390
   LinkTopic       =   "Form1"
   ScaleHeight     =   5715
   ScaleWidth      =   6390
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   1470
      Left            =   2370
      TabIndex        =   0
      Top             =   2895
      Width           =   2595
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Dim ce As CeE2DBase
        Set ce = CreateCeE2D(Me.hWnd)
        ce.Resolution 800, 600, 16
        ce.Resolution 0, 0, 0
End Sub
