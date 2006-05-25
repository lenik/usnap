VERSION 5.00
Begin VB.Form C_Start
   Caption         =   "Start"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnClient
      Caption         =   "&Client"
      Height          =   735
      Left            =   1680
      TabIndex        =   1
      Top             =   1560
      Width           =   1515
   End
   Begin VB.CommandButton btnServer
      Caption         =   "&Server"
      Height          =   735
      Left            =   1680
      TabIndex        =   0
      Top             =   600
      Width           =   1515
   End
End
Attribute VB_Name = "C_Start"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub btnServer_Click()
    C_Server.Show
    Unload Me
End Sub

Private Sub btnClient_Click()
    C_Client.Show
    Unload Me
End Sub
