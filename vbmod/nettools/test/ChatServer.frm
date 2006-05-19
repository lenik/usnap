VERSION 5.00
Begin VB.Form ChatServer
   Caption         =   "Server"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2
      Caption         =   "Stop"
      Height          =   555
      Left            =   300
      TabIndex        =   1
      Top             =   1200
      Width           =   1035
   End
   Begin VB.CommandButton Command1
      Caption         =   "Start"
      Height          =   615
      Left            =   360
      TabIndex        =   0
      Top             =   360
      Width           =   975
   End
End
Attribute VB_Name = "ChatServer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public svc As New NetTools.Service

Private Sub Form_Load()
    svc.Name = "ChatSvr"
End Sub
