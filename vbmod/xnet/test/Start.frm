VERSION 5.00
Begin VB.Form Start
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2
      Caption         =   "&Client"
      Height          =   1515
      Left            =   2340
      TabIndex        =   1
      Top             =   840
      Width           =   1515
   End
   Begin VB.CommandButton Command1
      Caption         =   "&Server"
      Height          =   1515
      Left            =   540
      TabIndex        =   0
      Top             =   840
      Width           =   1455
   End
End
Attribute VB_Name = "Start"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Server.Show
    Unload Me
End Sub

Private Sub Command2_Click()
    Client.Show
    Unload Me
End Sub
