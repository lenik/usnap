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
      Height          =   765
      Left            =   3015
      TabIndex        =   0
      Top             =   2205
      Width           =   1395
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim v As New OeTVariant
Private Sub Command1_Click()
        Dim x As Variant
        v.autoTypeConversion = False
        x = v.variant
End Sub
