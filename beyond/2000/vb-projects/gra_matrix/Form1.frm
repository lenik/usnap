VERSION 5.00
Begin VB.Form Form1
   Appearance      =   0  'Flat
   BackColor       =   &H80000005&
   Caption         =   "Form1"
   ClientHeight    =   4170
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5430
   LinkTopic       =   "Form1"
   ScaleHeight     =   4170
   ScaleWidth      =   5430
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   435
      Left            =   4215
      TabIndex        =   9
      Top             =   105
      Width           =   1125
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   8
      Left            =   4695
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   8
      Top             =   3585
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   7
      Left            =   4230
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   7
      Top             =   3585
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   6
      Left            =   3765
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   6
      Top             =   3585
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   5
      Left            =   4695
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   5
      Top             =   3150
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   4
      Left            =   4230
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   4
      Top             =   3150
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   3
      Left            =   3765
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   3
      Top             =   3150
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   2
      Left            =   4695
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   2
      Top             =   2715
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   1
      Left            =   4230
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   1
      Top             =   2715
      Width           =   480
   End
   Begin VB.PictureBox pk
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Index           =   0
      Left            =   3765
      ScaleHeight     =   420
      ScaleWidth      =   450
      TabIndex        =   0
      Top             =   2715
      Width           =   480
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Function ktoy(k) As Double
        ktoy = k / K_range + 0.5
        ktoy = ktoy * area / u_w
End Function
Public Function ktox(k) As Double
        ktox = k / K_range + 0.5
        ktox = ktox * area
        ktox = ktox - Int(ktox / u_w) * u_w
End Function

Public Function xytok(X, Y) As Double
        xytok = (Y * u_w + X) / area - 0.5
        xytok = xytok * K_range
End Function

Public Sub update()
        Dim i, ki
        For i = 0 To 8
                ki = k(Int(i / 3), i Mod 3)
                pk(i).Cls
                pk(i).Line (ktox(ki), ktoy(ki))-(ktox(ki) + 1, ktoy(ki) + 1), &HFF&, BF
        Next
End Sub

Public Sub redraw()
        Dim i, dx, dy
        Cls
        For i = 0 To nps - 1
                dx = ps(i).X / ps(i).k
                dy = ps(i).Y / ps(i).k
                dx = dx + Width / 2
                dy = dy + Height / 2
                If i = 0 Then
                        PSet (dx, dy), 0
                Else
                        Line -(dx, dy), 0
                End If
        Next
        For i = 0 To nps - 1
                ps2(i).X = ps(i).X * k(0, 0) + ps(i).Y * k(0, 1) + ps(i).k * k(0, 2)
                ps2(i).Y = ps(i).X * k(1, 0) + ps(i).Y * k(1, 1) + ps(i).k * k(1, 2)
                ps2(i).k = ps(i).X * k(2, 0) + ps(i).Y * k(2, 1) + ps(i).k * k(2, 2)
                dx = ps2(i).X / ps2(i).k
                dy = ps2(i).Y / ps2(i).k
                dx = dx + Width / 2 + 50
                dy = dy + Height / 2 + 50
                If i = 0 Then
                        PSet (dx, dy), &HFF0000
                Else
                        Line -(dx, dy), &HFF0000
                End If
        Next
End Sub

Private Sub Command1_Click()
        update
        redraw
End Sub

Private Sub Form_Load()
        u_w = pk(0).Width
        u_h = pk(0).Height
        area = u_w * u_h
        k(0, 0) = 1
        k(1, 1) = 1
        k(2, 2) = 1
        init
        update
        redraw
End Sub

Private Sub pk_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim kk As Double
        kk = xytok(X, Y)
        k(Int(Index / 3), Index Mod 3) = kk
        pk(Index).ToolTipText = kk
        update
        redraw
End Sub

Private Sub pk_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If Button And vbLeftButton Then
                pk_MouseDown Index, Button, Shift, X, Y
        End If
End Sub
