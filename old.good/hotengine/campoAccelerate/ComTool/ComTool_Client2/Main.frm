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
      Height          =   675
      Left            =   1545
      TabIndex        =   0
      Top             =   1680
      Width           =   1335
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Dim dog As New CaDog
        Dim cat As New CaCat
        dog.shout

        Dim sdog As New CaComToolLib.CaCSimulator
        sdog.simulate dog
        sdog.shout
        sdog.simulate cat
        sdog.shout
        sdog.simulate Nothing
        Set sdog = Nothing
End Sub
