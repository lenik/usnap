VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "CeE3DInproc_Client1"
   ClientHeight    =   3345
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5100
   LinkTopic       =   "Form1"
   ScaleHeight     =   3345
   ScaleWidth      =   5100
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   945
      Left            =   630
      TabIndex        =   1
      Top             =   480
      Width           =   1545
   End
   Begin VB.CommandButton Command1
      Caption         =   "run"
      Height          =   780
      Left            =   3585
      TabIndex        =   0
      Top             =   2355
      Width           =   1350
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        e3dmain
End Sub
