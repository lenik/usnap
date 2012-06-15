VERSION 5.00
Begin VB.Form frmPlane
   Caption         =   "plane crash"
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
      Height          =   1035
      Left            =   1890
      TabIndex        =   0
      Top             =   1725
      Width           =   1935
   End
End
Attribute VB_Name = "frmPlane"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'Public WithEvents plane As CaPlane

Private Sub Command1_Click()
        Dim x As New CaPlane
        x.fly
End Sub

Private Sub plane_onCrashed()
        MsgBox "Oh! crashed!"
End Sub
