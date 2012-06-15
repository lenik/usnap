VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Ê£Óà¿Õ¼ä¼àÊÓÆ÷"
   ClientHeight    =   1440
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   3210
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   1440
   ScaleWidth      =   3210
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.DriveListBox Drive1
      Height          =   315
      Left            =   120
      TabIndex        =   3
      Top             =   720
      Width           =   1095
   End
   Begin VB.Timer Timer1
      Left            =   2520
      Top             =   600
   End
   Begin VB.HScrollBar HScroll1
      Height          =   255
      LargeChange     =   100
      Left            =   120
      Max             =   5000
      Min             =   1
      TabIndex        =   0
      Top             =   1080
      Value           =   100
      Width           =   3015
   End
   Begin VB.HScrollBar HScroll2
      Height          =   255
      Left            =   1560
      Max             =   5
      TabIndex        =   4
      Top             =   120
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "Label3"
      Height          =   195
      Left            =   120
      TabIndex        =   5
      Top             =   480
      Width           =   480
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "Label2"
      BeginProperty Font
         Name            =   "Arial"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   330
      Left            =   60
      TabIndex        =   2
      Top             =   60
      Width           =   870
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Label1"
      BeginProperty Font
         Name            =   "ËÎÌå"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   1320
      TabIndex        =   1
      Top             =   720
      Width           =   630
   End
   Begin VB.Menu mnuUnit
      Caption         =   "&Unit"
      Begin VB.Menu mnuByte
         Caption         =   "&Byte"
      End
      Begin VB.Menu mnuKilo
         Caption         =   "&Kilo"
      End
      Begin VB.Menu mnuMega
         Caption         =   "&Mega"
      End
      Begin VB.Menu mnuGiga
         Caption         =   "&Giga"
      End
   End
   Begin VB.Menu mnuPrecise
      Caption         =   "&Precise"
      Begin VB.Menu mnu0
         Caption         =   ".&0"
      End
      Begin VB.Menu mnu1
         Caption         =   ".&1"
      End
      Begin VB.Menu mnu2
         Caption         =   ".&2"
      End
      Begin VB.Menu mnu3
         Caption         =   ".&3"
      End
      Begin VB.Menu mnu4
         Caption         =   ".&4"
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim switch As Integer
Dim factor As Double
Dim factorC As String

Private Sub Drive1_Change()
    Me.Caption = "Ê£Óà¿Õ¼ä¼àÊÓÆ÷: " + Drive1.Drive
    HScroll1_Change
End Sub

Private Sub Form_Activate()
    Drive1_Change
End Sub

Private Sub Form_Load()
        factor = 1024
        factorC = "K"
        Label2.Tag = Str(Label2.Left)
        switch = 15
        precise = 2
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Y > HScroll2.Top And Y < HScroll2.Top + HScroll2.Height Then
        HScroll2.Visible = True
    Else
        HScroll2.Visible = False
    End If
End Sub

Private Sub HScroll1_Change()
    Label1 = Str(HScroll1) + "Î¢ÃëË¢ÐÂ"
    Timer1.Interval = HScroll1
End Sub

Private Sub Label1_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    HScroll2.Visible = False
End Sub

Private Sub Label2_Click()
    HScroll2.Visible = False
End Sub

Private Sub Label2_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Form_MouseMove Button, Shift, Label2.Left + X, Label2.Top + Y
End Sub

Private Sub mnu0_Click(): precise = 0: End Sub
Private Sub mnu1_Click(): precise = 1: End Sub
Private Sub mnu2_Click(): precise = 2: End Sub
Private Sub mnu3_Click(): precise = 3: End Sub
Private Sub mnu4_Click(): precise = 4: End Sub

Private Sub mnuByte_Click()
        factor = 1
        factorC = "B"
End Sub

Private Sub mnuGiga_Click()
        factor = 1073741824
        factorC = "G"
End Sub

Private Sub mnuKilo_Click()
        factor = 1024
        factorC = "K"
End Sub

Private Sub mnuMega_Click()
        factor = 1048576
        factorC = "M"
End Sub

Private Sub Timer1_Timer()
    Dim sperc As Long, bpers As Long, free1 As Long, total1 As Long
    Dim free2 As Double, total2 As Double
    GetDiskFreeSpace Left(Drive1.Drive, 2) + "\", sperc, bpers, free1, total1
    free2 = CDbl(free1) * bpers * sperc / factor
    total2 = CDbl(total1) * bpers * sperc / factor
    Label2 = pstr(free2) & factorC & "/" & pstr(total2) & factorC
    Label2.Left = Val(Label2.Tag) + switch * HScroll2
    Label3 = pstr(free2) & factorC
    switch = -switch
End Sub
