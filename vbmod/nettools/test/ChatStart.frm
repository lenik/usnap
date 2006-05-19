VERSION 5.00
Begin VB.Form ChatStart
   Caption         =   "Start"
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
      Height          =   735
      Left            =   1320
      TabIndex        =   1
      Top             =   1860
      Width           =   2235
   End
   Begin VB.CommandButton Command1
      Caption         =   "&Server"
      Height          =   795
      Left            =   1320
      TabIndex        =   0
      Top             =   360
      Width           =   1875
   End
End
Attribute VB_Name = "ChatStart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Hide
    ChatServer.Show
End Sub

Private Sub Command2_Click()
    Hide
    ChatCLient.Show
End Sub
