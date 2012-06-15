VERSION 5.00
Begin VB.Form frmEarthquake
   Caption         =   "earthquake"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton horse
      Caption         =   "horse"
      Height          =   645
      Left            =   690
      TabIndex        =   1
      Top             =   390
      Width           =   1530
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   675
      Left            =   1740
      TabIndex        =   0
      Top             =   1965
      Width           =   1395
   End
End
Attribute VB_Name = "frmEarthquake"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents cae As CaEarthquake
Attribute cae.VB_VarHelpID = -1

Private Sub cae_onQuake()
        MsgBox "Hello"
End Sub

Private Sub Command1_Click()
        Dim cc As New CaEarthquake
        Set cae = cc
        cae.quakeNow

End Sub

Private Sub horse_Click()
        'Dim h As New CaHorse
        Dim h As Object
        Set h = CreateObject("CampoAccelerate.CaHorse")
        h.run
        Set h = Nothing
End Sub
