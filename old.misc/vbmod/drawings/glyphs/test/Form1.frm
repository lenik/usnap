VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.Label Marker
      Appearance      =   0  'Flat
      BackColor       =   &H00FFC0C0&
      BorderStyle     =   1  'Fixed Single
      ForeColor       =   &H80000008&
      Height          =   195
      Index           =   1
      Left            =   3000
      TabIndex        =   1
      Top             =   2160
      Width           =   195
   End
   Begin VB.Label Marker
      Appearance      =   0  'Flat
      BackColor       =   &H00FFC0C0&
      BorderStyle     =   1  'Fixed Single
      ForeColor       =   &H80000008&
      Height          =   195
      Index           =   0
      Left            =   1020
      TabIndex        =   0
      Top             =   840
      Width           =   195
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim ox, oy

Private Sub Form_Paint()
    Redraw
End Sub

Private Sub Marker_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    ox = X
    oy = Y
End Sub

Private Sub Marker_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button And vbLeftButton Then
        With Marker(Index)
            .Left = .Left + X - ox
            .Top = .Top + Y - oy
        End With
        Redraw
    End If
End Sub

Sub Redraw()
    Dim x0, y0, x1, y1
    x0 = Marker(0).Left + Marker(0).Width
    y0 = Marker(0).Top + Marker(0).Height
    x1 = Marker(1).Left
    y1 = Marker(1).Top

    x0 = ScaleX(x0, ScaleMode, vbPixels)
    y0 = ScaleY(y0, ScaleMode, vbPixels)
    x1 = ScaleX(x1, ScaleMode, vbPixels)
    y1 = ScaleY(y1, ScaleMode, vbPixels)

    Cls
    Lines.Arrow Me.hDC, arrowNormalDbl, x0, y0, x1, y1
End Sub
