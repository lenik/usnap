VERSION 5.00
Begin VB.Form frmGame
   Appearance      =   0  'Flat
   BackColor       =   &H80000005&
   Caption         =   "桃壳棋风游戏平台 - "
   ClientHeight    =   4596
   ClientLeft      =   48
   ClientTop       =   276
   ClientWidth     =   7848
   LinkTopic       =   "Form1"
   ScaleHeight     =   4596
   ScaleWidth      =   7848
   StartUpPosition =   3  '窗口缺省
   Begin VB.PictureBox Picture1
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   240
      Left            =   3600
      Picture         =   "Game.frx":0000
      ScaleHeight     =   240
      ScaleWidth      =   360
      TabIndex        =   0
      Top             =   1680
      Width           =   360
   End
   Begin VB.Image imgBoard
      Height          =   5760
      Left            =   0
      Picture         =   "Game.frx":139C
      Top             =   0
      Width           =   7680
   End
End
Attribute VB_Name = "frmGame"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Const strFormHeader = "桃壳棋风游戏平台 - "
Dim toMove As Boolean, ax As Single, ay As Single

Private Sub Picture1_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    toMove = True
    ax = x: ay = y
End Sub

Private Sub Picture1_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
    If toMove Then
        Picture1.Left = Picture1.Left + x - ax: Picture1.Top = Picture1.Top + y - ay
    End If
End Sub

Private Sub Picture1_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
    toMove = False
End Sub
