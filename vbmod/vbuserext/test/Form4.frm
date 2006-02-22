VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#18.0#0"; "VBUserExt.ocx"
Begin VB.Form Form4
   Caption         =   "Form1"
   ClientHeight    =   4005
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5775
   LinkTopic       =   "Form1"
   ScaleHeight     =   4005
   ScaleWidth      =   5775
   StartUpPosition =   3  'Windows Default
   Begin VBUserExt.ScrollableContainer sc
      Height          =   2415
      Left            =   1200
      TabIndex        =   0
      Top             =   660
      Width           =   3375
      _extentx        =   5953
      _extenty        =   4260
      extx1           =   3975
      exty1           =   2415
      appearance      =   0
      backcolor       =   -2147483643
      borderstyle     =   1
      Begin VB.CommandButton Command2
         Caption         =   "Command2"
         Height          =   675
         Left            =   2940
         TabIndex        =   2
         Top             =   780
         Width           =   1035
      End
      Begin VB.CommandButton Command1
         Caption         =   "Command1"
         Height          =   795
         Left            =   120
         TabIndex        =   1
         Top             =   420
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

Private Sub Form_Resize()
    If WindowState = vbMinimized Then Exit Sub
    sc.Width = ScaleWidth - sc.Left * 2
    sc.Height = ScaleHeight - sc.Top * 2
End Sub

Private Sub sc_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    'Caption = X & "," & Y
End Sub
