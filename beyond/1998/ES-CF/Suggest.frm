VERSION 5.00
Begin VB.Form frmSuggest
   Caption         =   "文章"
   ClientHeight    =   5790
   ClientLeft      =   2145
   ClientTop       =   1995
   ClientWidth     =   6525
   BeginProperty Font
      Name            =   "宋体"
      Size            =   9
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   5790
   ScaleWidth      =   6525
   Begin VB.CommandButton cmdSubmit
      Caption         =   "&S 提交"
      Height          =   315
      Left            =   5100
      TabIndex        =   6
      Top             =   60
      Width           =   1095
   End
   Begin VB.TextBox txtAddition
      ForeColor       =   &H00800000&
      Height          =   315
      Left            =   780
      TabIndex        =   5
      Top             =   5160
      Width           =   5415
   End
   Begin VB.TextBox txtContext
      ForeColor       =   &H00FF0000&
      Height          =   4275
      Left            =   780
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   3
      Top             =   780
      Width           =   5415
   End
   Begin VB.TextBox txtCaption
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   780
      TabIndex        =   2
      Top             =   420
      Width           =   5415
   End
   Begin VB.Label lblAddition
      AutoSize        =   -1  'True
      Caption         =   "附注:"
      Height          =   180
      Left            =   180
      TabIndex        =   4
      Top             =   5220
      Width           =   450
   End
   Begin VB.Label lblContext
      AutoSize        =   -1  'True
      Caption         =   "文章:"
      ForeColor       =   &H00404000&
      Height          =   180
      Left            =   180
      TabIndex        =   1
      Top             =   840
      Width           =   450
   End
   Begin VB.Label lblCaption
      AutoSize        =   -1  'True
      Caption         =   "标题:"
      ForeColor       =   &H00404000&
      Height          =   180
      Left            =   180
      TabIndex        =   0
      Top             =   480
      Width           =   450
   End
End
Attribute VB_Name = "frmArticle"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub cmdSubmit_Click()
    Dim F As Integer
    F = FreeFile
    Dim FName As String
    FName = SaveDir + ArticleDir + GenID + Left(Trim(txtCaption), 4)
    Open FName For Append As #F
        PrintHead F
        Print #F, lblCaption + Space + txtCaption + NewLine
        Print #F, lblContext + NewLine
        Print #F, "---- ---- ---- ---- ---- ----" + NewLine
        Print #F, txtContext + NewLine
        Print #F, "---- ---- ---- ---- ---- ----" + NewLine
        PrintEnd F
    Close #F
End Sub

Private Sub Form_Resize()
    Const RMargin = 15 * 30
    Const DMargin = 15 * 30
    Const LSep = 15 * 8

    txtCaption.Width = Width - txtCaption.Left - RMargin
    txtContext.Width = txtCaption.Width
    txtAddition.Width = txtCaption.Width

    txtAddition.Top = Height - (txtAddition.Height * 2 + DMargin)
    lblAddition.Top = txtAddition.Top
    txtContext.Height = Height - txtContext.Top - (txtAddition.Height * 2 + DMargin) - LSep

End Sub

Private Sub txtAddition_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then cmdSubmit.SetFocus
End Sub


Private Sub txtCaption_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtContext.SetFocus
End Sub
