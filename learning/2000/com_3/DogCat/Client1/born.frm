VERSION 5.00
Begin VB.Form born
   Caption         =   "cat born from dog"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton bornDog
      Caption         =   "click to born a dog"
      Height          =   390
      Index           =   0
      Left            =   285
      TabIndex        =   0
      Top             =   300
      Width           =   2550
   End
End
Attribute VB_Name = "born"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public rootDog As New CaDog

Dim Dog(100) As CaDog

Private Sub bornDog_Click(Index As Integer)
        Set Dog(Index) = rootDog.bornDog
        If Dog(Index) Is Nothing Then
                MsgBox "born nothing ?!"
                Exit Sub
        End If
        Dog(Index).shout
        Load bornDog(Index + 1)
        bornDog(Index + 1).Top = bornDog(Index).Top + bornDog(Index).Height + 100
        bornDog(Index + 1).Left = bornDog(Index).Left
        bornDog(Index + 1).Width = bornDog(Index).Width
        bornDog(Index + 1).Height = bornDog(Index).Height
        bornDog(Index + 1).Visible = True
End Sub
