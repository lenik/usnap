VERSION 5.00
Object = "*\A工程2.vbp"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   6960
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8880
   LinkTopic       =   "Form1"
   ScaleHeight     =   6960
   ScaleWidth      =   8880
   StartUpPosition =   3  '窗口缺省
   Begin 工程2.ucBut Image2
      Height          =   300
      Left            =   960
      TabIndex        =   0
      Top             =   1080
      Width           =   450
      _ExtentX        =   794
      _ExtentY        =   529
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "司令"
      Picture         =   "4g.frx":0000
      AutoSize        =   0   'False
   End
   Begin VB.PictureBox Picture1
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   3615
      Left            =   1920
      Picture         =   "4g.frx":13EF
      ScaleHeight     =   3615
      ScaleWidth      =   4935
      TabIndex        =   1
      Top             =   600
      Width           =   4935
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim mm As Boolean, xx As Single, yy As Single, x1 As Single, y1 As Single

Private Sub Image1_Click()

End Sub

Private Sub Image2_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    mm = True: xx = Image2.Left - x1: yy = Image2.Top - y1
    x1 = X: y1 = Y

End Sub

Private Sub Image2_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If mm Then
        Image2.Left = xx + X: Image2.Top = yy + Y
        xx = Image2.Left - x1: yy = Image2.Top - y1
    End If

End Sub

Private Sub Image2_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    mm = Not mm
End Sub
