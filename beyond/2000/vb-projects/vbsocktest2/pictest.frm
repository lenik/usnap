VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   6630
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8415
   LinkTopic       =   "Form1"
   ScaleHeight     =   442
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   561
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.PictureBox pb
      AutoRedraw      =   -1  'True
      Height          =   495
      Left            =   7080
      ScaleHeight     =   29
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   29
      TabIndex        =   6
      Top             =   120
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.ComboBox cs
      Height          =   300
      ItemData        =   "pictest.frx":0000
      Left            =   0
      List            =   "pictest.frx":000A
      Style           =   2  'Dropdown List
      TabIndex        =   5
      Top             =   0
      Width           =   2415
   End
   Begin VB.HScrollBar x2
      Height          =   375
      Left            =   1020
      Max             =   255
      TabIndex        =   4
      Top             =   5640
      Width           =   5835
   End
   Begin VB.HScrollBar x1
      Height          =   375
      Left            =   1020
      Max             =   255
      TabIndex        =   3
      Top             =   300
      Width           =   5835
   End
   Begin VB.VScrollBar y2
      Height          =   4755
      Left            =   7020
      Max             =   255
      TabIndex        =   2
      Top             =   780
      Width           =   435
   End
   Begin VB.VScrollBar y1
      Height          =   4755
      Left            =   420
      Max             =   255
      TabIndex        =   1
      Top             =   780
      Width           =   435
   End
   Begin VB.PictureBox p
      AutoRedraw      =   -1  'True
      Height          =   4755
      Left            =   1020
      Picture         =   "pictest.frx":001B
      ScaleHeight     =   313
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   389
      TabIndex        =   0
      Top             =   780
      Width           =   5895
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Enum whichbitbltmode
        blur = 0
        brick
End Enum
Public bbm As whichbitbltmode

Public px, py, pw, ph
Public bDown As Boolean

Sub blur1()
End Sub
Sub blur2()
        BitBltBlur p.hdc, px, py, pw, ph, x2.Value * &H100 + y2.Value
End Sub

Sub brick1()
        FIBB_Var FI_SETVAL, FI_VAR_ALPHA1, x1.Value
        FIBB_Var FI_SETVAL, FI_VAR_ALPHA2, y1.Value
End Sub
Sub brick2()
        BitBltBrick p.hdc, px, py, pw, ph, x2.Value * &H100& + y2.Value
End Sub

Sub bitblt1()
        Select Case bbm
        Case blur: blur1
        Case brick: brick1
        End Select
        bitblt2
End Sub
Sub bitblt2()
        p.Cls
        Select Case bbm
        Case blur: blur2
        Case brick: brick2
        End Select
        p.Refresh
End Sub

Private Sub cs_Click()
        bbm = cs.ListIndex
End Sub

Private Sub p_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        px = X: py = Y
        bDown = True
        bitblt1
End Sub
Private Sub p_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        If bDown Then
                If Button And vbRightButton Then
                        pw = X - px + 1
                        ph = Y - py + 1
                Else
                        px = X
                        py = Y
                End If
                bitblt1
        End If
End Sub
Private Sub p_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
        If bDown Then bDown = False
End Sub

Private Sub x1_Change()
        bitblt1
End Sub
Private Sub y1_Change()
        bitblt1
End Sub
Private Sub x2_Change()
        bitblt2
End Sub

Private Sub y2_Change()
        bitblt2
End Sub

Private Sub Form_Load()
        bbm = brick
        px = 100
        py = 100
        pw = 100
        ph = 100
        pb.width = 640
        pb.height = 480
End Sub

Private Sub x1_Scroll(): x1_Change: End Sub
Private Sub y1_Scroll(): y1_Change: End Sub
Private Sub x2_Scroll(): x2_Change: End Sub
Private Sub y2_Scroll(): y2_Change: End Sub
