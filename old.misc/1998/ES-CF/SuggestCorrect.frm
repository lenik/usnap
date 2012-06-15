VERSION 5.00
Begin VB.Form frmSuggestCorrect
   Caption         =   "建议及更正"
   ClientHeight    =   5745
   ClientLeft      =   2115
   ClientTop       =   1755
   ClientWidth     =   6555
   BeginProperty Font
      Name            =   "宋体"
      Size            =   9
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "SuggestCorrect.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   5745
   ScaleWidth      =   6555
   Begin VB.CommandButton cmdExit
      Caption         =   "&X 放弃"
      Height          =   315
      Left            =   3960
      TabIndex        =   7
      Top             =   60
      Width           =   1035
   End
   Begin VB.TextBox txtCaption
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   840
      TabIndex        =   3
      Top             =   420
      Width           =   5415
   End
   Begin VB.TextBox txtContext
      ForeColor       =   &H00FF0000&
      Height          =   4275
      Left            =   840
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   2
      Text            =   "SuggestCorrect.frx":030A
      Top             =   780
      Width           =   5415
   End
   Begin VB.TextBox txtAddition
      ForeColor       =   &H00800000&
      Height          =   315
      Left            =   840
      TabIndex        =   1
      Top             =   5160
      Width           =   5415
   End
   Begin VB.CommandButton cmdSubmit
      Caption         =   "&S 提交"
      Height          =   315
      Left            =   5160
      TabIndex        =   0
      Top             =   60
      Width           =   1095
   End
   Begin VB.Label lblCaption
      AutoSize        =   -1  'True
      Caption         =   "简要:"
      ForeColor       =   &H00404000&
      Height          =   180
      Left            =   240
      TabIndex        =   6
      Top             =   480
      Width           =   450
   End
   Begin VB.Label lblContext
      AutoSize        =   -1  'True
      Caption         =   "内容:"
      ForeColor       =   &H00404000&
      Height          =   180
      Left            =   240
      TabIndex        =   5
      Top             =   840
      Width           =   450
   End
   Begin VB.Label lblAddition
      AutoSize        =   -1  'True
      Caption         =   "附注:"
      Height          =   180
      Left            =   240
      TabIndex        =   4
      Top             =   5220
      Width           =   450
   End
End
Attribute VB_Name = "frmSuggestCorrect"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdExit_Click()
    Me.Hide
End Sub

Private Sub cmdSubmit_Click()
    Dim F As Integer
    F = FreeFile
    Dim FName As String
    FName = SaveDir + SuggestDir + GenID + Left(Trim(TStr(txtCaption)), 4)
    Open FName For Append As #F
        PrintHead F
        Print #F, lblCaption + Space + txtCaption
        Print #F, lblContext
        Print #F, "---- ---- ---- ---- ---- ----"
        Print #F, txtContext
        Print #F, "---- ---- ---- ---- ---- ----"
        PrintEnd F
    Close #F
    Me.Hide
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
