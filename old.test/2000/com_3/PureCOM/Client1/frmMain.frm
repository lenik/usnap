VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   660
      Left            =   1590
      TabIndex        =   0
      Top             =   1545
      Width           =   1545
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public WithEvents x As CaPureDog

Private Sub Command1_Click()
        Dim y As New CaPureDog
        Dim z As CaPureDog
        Set z = y
        Set x = y
        'z.shout
        x.shout
End Sub

Private Sub x_onBitten()
        MsgBox "onBitten"
End Sub
