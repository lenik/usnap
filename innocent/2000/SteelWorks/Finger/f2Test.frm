VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "campoImage"
   ClientHeight    =   6210
   ClientLeft      =   4065
   ClientTop       =   345
   ClientWidth     =   8235
   LinkTopic       =   "Form1"
   ScaleHeight     =   414
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   549
   Begin VB.CommandButton Command7
      Caption         =   "Command7"
      Height          =   375
      Left            =   6720
      TabIndex        =   19
      Top             =   420
      Width           =   555
   End
   Begin VB.CommandButton Command6
      Caption         =   "save alpha"
      Height          =   495
      Left            =   60
      TabIndex        =   18
      Top             =   5160
      Width           =   615
   End
   Begin VB.VScrollBar a2
      Height          =   1755
      Left            =   60
      Max             =   255
      TabIndex        =   17
      Top             =   3300
      Value           =   255
      Width           =   555
   End
   Begin VB.VScrollBar a1
      Height          =   1755
      Left            =   60
      Max             =   255
      TabIndex        =   16
      Top             =   1500
      Width           =   555
   End
   Begin VB.TextBox Text2
      Height          =   615
      IMEMode         =   7  'DBCS ALPHABET
      Left            =   5160
      TabIndex        =   15
      Text            =   "Text2"
      Top             =   2580
      Width           =   1395
   End
   Begin VB.HScrollBar sh
      Height          =   375
      Left            =   240
      Max             =   255
      TabIndex        =   14
      Top             =   1080
      Width           =   3975
   End
   Begin VB.HScrollBar sa
      Height          =   315
      Left            =   660
      Max             =   255
      TabIndex        =   13
      Top             =   5700
      Width           =   3315
   End
   Begin VB.CommandButton Command5
      Caption         =   "Command5"
      Height          =   375
      Left            =   2700
      TabIndex        =   12
      Top             =   5220
      Width           =   1095
   End
   Begin VB.PictureBox picBack
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   495
      Left            =   4920
      ScaleHeight     =   465
      ScaleWidth      =   1185
      TabIndex        =   11
      Top             =   960
      Width           =   1215
   End
   Begin VB.PictureBox picText
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ClipControls    =   0   'False
      ForeColor       =   &H80000008&
      Height          =   825
      Left            =   4620
      ScaleHeight     =   53
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   182
      TabIndex        =   10
      Top             =   5100
      Width           =   2760
   End
   Begin VB.CommandButton Command4
      Caption         =   "Command4"
      Height          =   795
      Left            =   5280
      TabIndex        =   9
      Top             =   3540
      Width           =   795
   End
   Begin VB.CommandButton Command3
      Caption         =   "Command3"
      Height          =   735
      Left            =   5400
      TabIndex        =   8
      Top             =   1800
      Width           =   735
   End
   Begin VB.VScrollBar s2
      Height          =   1515
      Left            =   4680
      Max             =   256
      TabIndex        =   7
      Top             =   3240
      Width           =   495
   End
   Begin VB.VScrollBar s1
      Height          =   1395
      Left            =   4680
      Max             =   256
      TabIndex        =   6
      Top             =   1500
      Width           =   495
   End
   Begin VB.TextBox Text1
      Height          =   795
      Left            =   120
      MultiLine       =   -1  'True
      TabIndex        =   0
      Text            =   "f2Test.frx":0000
      Top             =   60
      Width           =   3915
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   375
      Left            =   1560
      TabIndex        =   5
      Top             =   5220
      Width           =   1035
   End
   Begin VB.PictureBox p2
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H008080FF&
      ForeColor       =   &H80000008&
      Height          =   1815
      Left            =   660
      Picture         =   "f2Test.frx":0006
      ScaleHeight     =   119
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   263
      TabIndex        =   4
      Top             =   3240
      Width           =   3975
   End
   Begin VB.PictureBox p1
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   1650
      Left            =   660
      MousePointer    =   3  'I-Beam
      Picture         =   "f2Test.frx":12EB
      ScaleHeight     =   108
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   264
      TabIndex        =   3
      Top             =   1500
      Width           =   3990
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   615
      Left            =   4140
      TabIndex        =   2
      Top             =   60
      Width           =   1815
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Label1"
      Height          =   180
      Left            =   780
      TabIndex        =   1
      Top             =   5340
      Width           =   540
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub a1_Change()
        FIIA dwAdd(&H1000000 * 0, dwAdd(dwShl(a1.Value, 8), a2.Value))
'        s2_Change
        sa_Change
End Sub

Private Sub a1_Scroll()
        a1_Change
End Sub

Private Sub a2_Change()
        a1_Change
End Sub

Private Sub a2_Scroll()
        a2_Change
End Sub

Private Sub Command1_Click()
        Dim i As Integer
        'Dim ec As New EasyChar
        'Dim X As New EasyText

        X.hSceneDC = p1.hDC
        X.hSceneBakDC = p2.hDC

        ec.Content = Text1
        ec.ForeColor = &H20FFFFFF
        ec.BackColor = &HCDFFFFFF
        ec.Size = 20
        ec.HasGradient = True
        ec.GradientC1 = &H0&
        ec.GradientC2 = &HFFFFFF
        X.AppendChar ec
        X.AppendChar ec
        X.AppendChar ec
        X.AppendChar ec
        X.AppendChar ec
        Set ec = Nothing

        X.X = 40
        X.Y = 0
        X.Visible = True
        X.GetChar(0).Content = "DD"
        X.Refresh
        p1.Refresh
        p2.Refresh
        MsgBox "X"
        X.DeleteAll
        p1.Refresh
        p2.Refresh

End Sub

Private Sub Command2_Click()
        'BitBltColor p1.hdc, 0, 0, 100, 80, &HFF00&, s1.Value
        Dim r
        'r = BitBltBlur(p2.hdc, 0, 0, 100, 80, &H1A0&)
        p2.Cls
        BitBltFn p2.hDC, 0, 0, 100, 80, 0, 0, 0, _
                        BITBLT_SIMPLE Or BITBLT_ONLYDEST, AddressOf BB_RedChannel, 0
        p2.Refresh
        picText.Refresh
End Sub

Private Sub Command3_Click()
        p1.Cls
End Sub

Private Sub Command4_Click()
        p2.Cls
End Sub

Private Sub Command5_Click()
        p1.Cls
        p2.Cls
        BitBltMul p2.hDC, 0, 0, 100, 100, &H5000
        BitBltSub p1.hDC, 0, 0, 100, 100, p2.hDC, 0, 0
        p1.Refresh
        p2.Refresh
End Sub

Private Sub Command6_Click()
        FIIA &HFF000000
End Sub

Private Sub Command7_Click()
        Form1.Show
End Sub

Private Sub p1_GotFocus()
        CreateCaret p1.hWnd, 0, 4, 13
End Sub

Private Sub s1_Change()
        p2.Cls
        BitBltAlphaV p2.hDC, 0, 0, 200, 70, p1.hDC, 0, 0, s1.Value, s2.Value
        p2.Refresh
End Sub

Private Sub s1_Scroll()
        s1_Change
End Sub

Private Sub s2_Change()
        p2.Cls
        BitBltAlphaV p2.hDC, 0, 0, 200, 70, p1.hDC, 0, 0, s1.Value, s2.Value
        p2.Refresh
End Sub

Private Sub s2_Scroll()
        s2_Change
End Sub

Private Sub sa_Change()
        Dim xx As Integer
        p2.Cls
        'BitBltBlur p2.hdc, 0, 0, 100, 100, sa.Value + &H100&
        'BitBltBrick p2.hdc, 0, 0, 130, 100, sa.Value * &H101&
        'BitBltAlphaSimple p2.hdc, 0, 0, 130, 100, p1.hdc, 0, 0, sa.Value
        BitBltGradient p2.hDC, 0, 0, 130, 100, &H0, &HFFFFFF, False
        p2.Refresh
End Sub

Private Sub sa_Scroll()
        sa_Change
End Sub

Private Sub sh_Scroll()
        sh_Change
End Sub
Private Sub sh_Change()
        p1.Cls
        p2.Cls
        BitBltMul p2.hDC, 0, 0, 100, 100, &H100& * (sh.Value + &H100)
        BitBltSub p1.hDC, 0, 0, 100, 100, p2.hDC, 0, 0
        p1.Refresh
        p2.Refresh
End Sub
