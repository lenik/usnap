VERSION 5.00
Begin VB.Form frmTest
   Caption         =   "≤‚ ‘¥∞"
   ClientHeight    =   3600
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6570
   LinkTopic       =   "Form1"
   ScaleHeight     =   3600
   ScaleWidth      =   6570
   StartUpPosition =   3  '¥∞ø⁄»± °
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   585
      Left            =   180
      TabIndex        =   1
      Top             =   2760
      Width           =   1275
   End
   Begin VB.PictureBox Picture1
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      DrawMode        =   7  'Invert
      ForeColor       =   &H80000008&
      Height          =   2325
      Left            =   150
      ScaleHeight     =   2295
      ScaleWidth      =   6015
      TabIndex        =   0
      Top             =   240
      Width           =   6045
   End
End
Attribute VB_Name = "frmTest"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Dim ns1 As TNode, ns2 As TNode
    Dim var1 As NodeRect, var2 As NodeRect
    Dim p1 As Point, p2 As Point
    Dim a As Single
    Dim dd As Long
    On Error Resume Next
Set picPaint = Picture1
var1.Color = &HFF0000
var2.Color = &HFF8000
    ns1.Left = Picture1.Width / 2
    ns1.Top = Picture1.Height / 2
    ns1.Width = Picture1.Width / 10
    ns1.Height = Picture1.Height / 10
    ns2.Width = ns1.Width
    ns2.Height = ns1.Height
    nsPaint ns1, var1
    nsPaint ns2, var2

    For a = 0 To 100 Step 0.01
        nsPaint ns2, var2
        ns2.Left = ns1.Left + Picture1.Width * Cos(a) / 4
        ns2.Top = ns1.Top + Picture1.Height * Sin(a) / 4
        nsPaint ns2, var2
            RectBridge ns1, ns2, p1, p2
            Picture1.Line (p1.X, p1.Y)-(p2.X, p2.Y), Int(Rnd * &H1000000)
            For dd = 0 To 200: DoEvents: Next
            'Picture1.Line (p1.X, p1.Y)-(p2.X, p2.Y), QBColor(2)
    Next
Set picPaint = frmPadGen.imgBack
End Sub
