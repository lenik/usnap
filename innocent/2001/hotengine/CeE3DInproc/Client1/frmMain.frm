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
   Begin VB.CommandButton cmdCeE3DInproc_Client3
      Caption         =   "CeE3DInproc_Client&3"
      Height          =   585
      Left            =   240
      TabIndex        =   2
      Top             =   2355
      Width           =   4350
   End
   Begin VB.CommandButton cmdCeE3DInproc_Client2
      Caption         =   "CeE3DInproc_Client&2"
      Height          =   570
      Left            =   210
      TabIndex        =   1
      Top             =   1290
      Width           =   4350
   End
   Begin VB.CommandButton cmdCeE3DInproc_Client1
      Caption         =   "CeE3DInproc_Client&1"
      Height          =   570
      Left            =   225
      TabIndex        =   0
      Top             =   210
      Width           =   4335
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdCeE3DInproc_Client1_Click()
        modCeE3DInproc_Client1.CeE3DInproc_Client1
End Sub

Private Sub cmdCeE3DInproc_Client2_Click()
        modCeE3DInproc_Client2.CeE3DInproc_Client2
End Sub

Private Sub cmdCeE3DInproc_Client3_Click()
        frmCeE3DInproc_Client3.Show
End Sub

Private Sub Form_KeyPress(KeyAscii As Integer)
        Select Case UCase(Chr(KeyAscii))
        Case "1"
                cmdCeE3DInproc_Client1_Click
        Case "2"
                cmdCeE3DInproc_Client2_Click
        Case "3"
                cmdCeE3DInproc_Client3_Click
        End Select
End Sub
