VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#19.0#0"; "VBUserExt.ocx"
Begin VB.Form Form4
   Caption         =   "ScrollableContainer #1"
   ClientHeight    =   1725
   ClientLeft      =   630
   ClientTop       =   840
   ClientWidth     =   4605
   LinkTopic       =   "Form1"
   ScaleHeight     =   1725
   ScaleWidth      =   4605
   Begin VBUserExt.ScrollableContainer sc
      Height          =   1335
      Left            =   120
      TabIndex        =   0
      Top             =   180
      Width           =   4155
      _ExtentX        =   7329
      _ExtentY        =   2355
      StaticLayout    =   0   'False
      PadLeft         =   100
      PadTop          =   100
      PadRight        =   100
      PadBottom       =   100
      BorderLeft      =   0
      BorderTop       =   0
      ExtX0           =   -800
      ExtY0           =   -380
      ExtX1           =   4255
      ExtY1           =   1435
      Appearance      =   0
      BackColor       =   -2147483643
      BorderStyle     =   1
      Begin VB.CommandButton Test
         Caption         =   "Test"
         Height          =   795
         Index           =   2
         Left            =   2520
         TabIndex        =   3
         Top             =   -180
         Width           =   1155
      End
      Begin VB.CommandButton Test
         Caption         =   "Test"
         Height          =   795
         Index           =   1
         Left            =   1860
         TabIndex        =   2
         Top             =   360
         Width           =   1155
      End
      Begin VB.CommandButton Test
         Caption         =   "Test"
         Height          =   795
         Index           =   0
         Left            =   -600
         TabIndex        =   1
         Top             =   -60
         Width           =   1155
      End
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim ox, oy

Private Sub Form_Resize()
    If WindowState = vbMinimized Then Exit Sub
    sc.Width = ScaleWidth - sc.Left * 2
    sc.Height = ScaleHeight - sc.Top * 2
End Sub

Private Sub Test_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    ox = X
    oy = Y
End Sub

Private Sub Test_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button And vbLeftButton Then
        With Test(Index)
            .Left = .Left + X - ox
            .Top = .Top + Y - oy
        End With
    End If
End Sub
