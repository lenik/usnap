VERSION 5.00
Begin VB.Form frmSelfIntro
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "自我介绍"
   ClientHeight    =   3870
   ClientLeft      =   1380
   ClientTop       =   1755
   ClientWidth     =   6165
   BeginProperty Font
      Name            =   "宋体"
      Size            =   9
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "SelfIntro.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3870
   ScaleWidth      =   6165
   ShowInTaskbar   =   0   'False
   Begin VB.TextBox txtVal
      Enabled         =   0   'False
      Height          =   315
      Index           =   15
      Left            =   0
      TabIndex        =   42
      TabStop         =   0   'False
      Top             =   3000
      Visible         =   0   'False
      Width           =   195
   End
   Begin VB.TextBox txtVal
      Enabled         =   0   'False
      Height          =   315
      Index           =   4
      Left            =   0
      TabIndex        =   41
      TabStop         =   0   'False
      Top             =   1620
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.TextBox txtVal
      Enabled         =   0   'False
      Height          =   285
      Index           =   2
      Left            =   0
      TabIndex        =   40
      TabStop         =   0   'False
      Top             =   1020
      Visible         =   0   'False
      Width           =   195
   End
   Begin VB.CommandButton cmdReset
      Caption         =   "&C复位"
      Height          =   315
      Left            =   3900
      TabIndex        =   39
      Top             =   3540
      Width           =   915
   End
   Begin VB.CommandButton cmdExit
      Caption         =   "&X返回"
      Height          =   315
      Left            =   4920
      TabIndex        =   38
      Top             =   3540
      Width           =   975
   End
   Begin VB.ComboBox cboAgree
      ForeColor       =   &H00FF0000&
      Height          =   300
      ItemData        =   "SelfIntro.frx":030A
      Left            =   2400
      List            =   "SelfIntro.frx":0314
      Style           =   2  'Dropdown List
      TabIndex        =   37
      Top             =   3000
      Width           =   1335
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   14
      Left            =   2400
      TabIndex        =   35
      Text            =   "."
      Top             =   2700
      Width           =   3495
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   13
      Left            =   4500
      TabIndex        =   33
      Text            =   ".写几篇好文章"
      Top             =   2280
      Width           =   1395
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   255
      Index           =   12
      Left            =   4140
      TabIndex        =   31
      Text            =   ".好动"
      Top             =   1980
      Width           =   1755
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   11
      Left            =   4140
      TabIndex        =   29
      Text            =   ".为国争光"
      Top             =   1620
      Width           =   1755
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   10
      Left            =   3420
      TabIndex        =   27
      Text            =   ".开车"
      Top             =   1320
      Width           =   2475
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   9
      Left            =   3960
      TabIndex        =   25
      Text            =   ".忠诚"
      Top             =   1020
      Width           =   1935
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   8
      Left            =   3420
      TabIndex        =   23
      Text            =   ".仗势欺人, 不给别人面子"
      Top             =   660
      Width           =   2475
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   7
      Left            =   3420
      TabIndex        =   21
      Text            =   ".讲义气, 讲文明, 有责任心"
      Top             =   360
      Width           =   2475
   End
   Begin VB.TextBox txtDay
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   2280
      TabIndex        =   14
      Text            =   "27"
      Top             =   1620
      Width           =   375
   End
   Begin VB.TextBox txtMonth
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   1620
      TabIndex        =   12
      Text            =   "04"
      Top             =   1620
      Width           =   375
   End
   Begin VB.TextBox txtYear
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   720
      TabIndex        =   10
      Text            =   "1982"
      Top             =   1620
      Width           =   615
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   6
      Left            =   720
      TabIndex        =   19
      Text            =   ".外语"
      Top             =   2280
      Width           =   2355
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   5
      Left            =   720
      TabIndex        =   17
      Text            =   ".吟诗作画"
      Top             =   1980
      Width           =   2355
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   3
      Left            =   720
      TabIndex        =   8
      Text            =   ".18"
      Top             =   1320
      Width           =   855
   End
   Begin VB.ComboBox cboSex
      ForeColor       =   &H00FF0000&
      Height          =   300
      ItemData        =   "SelfIntro.frx":0326
      Left            =   720
      List            =   "SelfIntro.frx":0330
      Style           =   2  'Dropdown List
      TabIndex        =   6
      Top             =   1020
      Width           =   855
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   1
      Left            =   720
      TabIndex        =   4
      Text            =   ".黑香蕉"
      Top             =   660
      Width           =   855
   End
   Begin VB.TextBox txtVal
      ForeColor       =   &H00FF0000&
      Height          =   270
      Index           =   0
      Left            =   720
      TabIndex        =   2
      Text            =   ".谢继雷"
      Top             =   360
      Width           =   855
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "(以 ""."" 号开头将不记入)"
      ForeColor       =   &H00000080&
      Height          =   180
      Left            =   1140
      TabIndex        =   43
      Top             =   120
      Width           =   2070
   End
   Begin VB.Line Line1
      BorderColor     =   &H00808080&
      BorderStyle     =   6  'Inside Solid
      Index           =   6
      X1              =   120
      X2              =   5985
      Y1              =   3480
      Y2              =   3480
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "希望我将你介绍给大家么?"
      ForeColor       =   &H00404000&
      Height          =   180
      Index           =   15
      Left            =   240
      TabIndex        =   36
      Top             =   3060
      Width           =   2070
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你对东晖文学站的评价:"
      ForeColor       =   &H00404000&
      Height          =   180
      Index           =   14
      Left            =   240
      TabIndex        =   34
      Top             =   2760
      Width           =   1890
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你目前的打算:"
      ForeColor       =   &H000040C0&
      Height          =   180
      Index           =   13
      Left            =   3240
      TabIndex        =   32
      Top             =   2340
      Width           =   1170
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你的性格:"
      ForeColor       =   &H000040C0&
      Height          =   180
      Index           =   12
      Left            =   3240
      TabIndex        =   30
      Top             =   2040
      Width           =   810
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你的理想:"
      ForeColor       =   &H000040C0&
      Height          =   180
      Index           =   11
      Left            =   3240
      TabIndex        =   28
      Top             =   1680
      Width           =   810
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你最喜欢的职业:"
      ForeColor       =   &H0080FFFF&
      Height          =   180
      Index           =   10
      Left            =   1800
      TabIndex        =   26
      Top             =   1380
      Width           =   1350
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你认为做人的基本守则是:"
      ForeColor       =   &H0080FFFF&
      Height          =   180
      Index           =   9
      Left            =   1800
      TabIndex        =   24
      Top             =   1080
      Width           =   2070
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你最讨厌怎样的人?"
      ForeColor       =   &H0080FFFF&
      Height          =   180
      Index           =   8
      Left            =   1800
      TabIndex        =   22
      Top             =   720
      Width           =   1530
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "你最喜欢怎样的人?"
      ForeColor       =   &H0080FFFF&
      Height          =   180
      Index           =   7
      Left            =   1800
      TabIndex        =   20
      Top             =   420
      Width           =   1530
   End
   Begin VB.Label lblDay
      AutoSize        =   -1  'True
      Caption         =   "日"
      ForeColor       =   &H00004000&
      Height          =   180
      Left            =   2700
      TabIndex        =   15
      Top             =   1680
      Width           =   180
   End
   Begin VB.Label lblMonth
      AutoSize        =   -1  'True
      Caption         =   "月"
      ForeColor       =   &H00004000&
      Height          =   180
      Left            =   2040
      TabIndex        =   13
      Top             =   1680
      Width           =   180
   End
   Begin VB.Label lblYear
      AutoSize        =   -1  'True
      Caption         =   "年"
      ForeColor       =   &H00004000&
      Height          =   180
      Left            =   1380
      TabIndex        =   11
      Top             =   1680
      Width           =   180
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "生日:"
      ForeColor       =   &H00404000&
      Height          =   180
      Index           =   4
      Left            =   240
      TabIndex        =   9
      Top             =   1680
      Width           =   450
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "特长:"
      ForeColor       =   &H00800080&
      Height          =   180
      Index           =   6
      Left            =   240
      TabIndex        =   18
      Top             =   2340
      Width           =   450
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "爱好:"
      ForeColor       =   &H00800080&
      Height          =   180
      Index           =   5
      Left            =   240
      TabIndex        =   16
      Top             =   2040
      Width           =   450
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "年龄:"
      ForeColor       =   &H00404000&
      Height          =   180
      Index           =   3
      Left            =   240
      TabIndex        =   7
      Top             =   1380
      Width           =   450
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "性别:"
      ForeColor       =   &H00404000&
      Height          =   180
      Index           =   2
      Left            =   240
      TabIndex        =   5
      Top             =   1080
      Width           =   450
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "别名:"
      ForeColor       =   &H00404000&
      Height          =   180
      Index           =   1
      Left            =   240
      TabIndex        =   3
      Top             =   720
      Width           =   450
   End
   Begin VB.Label lblLabel
      AutoSize        =   -1  'True
      Caption         =   "姓名:"
      ForeColor       =   &H00404000&
      Height          =   180
      Index           =   0
      Left            =   240
      TabIndex        =   1
      Top             =   420
      Width           =   450
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "自我介绍"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00404040&
      Height          =   210
      Left            =   60
      TabIndex        =   0
      Top             =   120
      Width           =   840
   End
   Begin VB.Line Line1
      BorderColor     =   &H00FFFFFF&
      BorderWidth     =   2
      Index           =   7
      X1              =   120
      X2              =   5970
      Y1              =   3480
      Y2              =   3480
   End
End
Attribute VB_Name = "frmSelfIntro"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Function Gen() As String
    Dim p As Integer
    Dim Valid As Boolean
    cboSex_Change
    cboAgree_Change
    txtYear_Change

    Gen = ""
    Valid = True
    For p = 0 To 15
        If txtVal(p).Visible = True Then
            Valid = IIf(Left(txtVal(p), 1) <> ".", True, False)
        End If
        If Valid = True Then
            Gen = Gen + lblLabel(p) + Space + txtVal(p) + NewLine
        End If
    Next

End Function

Private Sub cboAgree_Change()
    txtVal(15) = cboAgree.Text
End Sub

Private Sub cboAgree_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtVal(0).SetFocus
End Sub

Private Sub cboSex_Change()
    txtVal(2).Text = cboSex.Text
End Sub

Private Sub cboSex_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtVal(3).SetFocus
End Sub

Private Sub cmdExit_Click()
    Intro = Gen
    Me.Hide
End Sub

Private Sub cmdReset_Click()
    Dim p As Integer
    For p = 0 To 15
        txtVal(p) = ""
    Next
    cboSex.ListIndex = 0
    txtYear = "": txtMonth = "": txtDay = ""
    cboAgree.ListIndex = 0
End Sub

Private Sub Form_Activate()
    txtVal(0).SetFocus
End Sub

Private Sub Form_Load()
    cboSex.ListIndex = 0
    cboAgree.ListIndex = 0
End Sub

Private Sub txtDay_Change()
    txtYear_Change
End Sub

Private Sub txtDay_GotFocus()
    txtDay.SelStart = 0
    txtDay.SelLength = Len(txtDay)
End Sub

Private Sub txtDay_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtVal(5).SetFocus
End Sub

Private Sub txtMonth_Change()
    txtYear_Change
End Sub

Private Sub txtMonth_GotFocus()
    txtMonth.SelStart = 0
    txtMonth.SelLength = Len(txtMonth)
End Sub

Private Sub txtMonth_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtDay.SetFocus
End Sub

Private Sub txtVal_GotFocus(Index As Integer)
    txtVal(Index).SelStart = 0
    txtVal(Index).SelLength = Len(txtVal(Index))
End Sub

Private Sub txtVal_KeyPress(Index As Integer, KeyAscii As Integer)
    Dim NI As Integer
    If Chr(KeyAscii) = Enter Then
        NI = (Index + 1) Mod txtVal.Count
        Select Case NI
            Case 2: cboSex.SetFocus
            Case 4: txtYear.SetFocus
            Case 15: cboAgree.SetFocus
            Case Else: txtVal(NI).SetFocus
        End Select
    End If
End Sub

Private Sub txtYear_Change()
    txtVal(4) = txtYear + lblYear + txtMonth + lblMonth + txtDay + lblDay
End Sub

Private Sub txtYear_GotFocus()
    txtYear.SelStart = 0
    txtYear.SelLength = Len(txtYear)
End Sub

Private Sub txtYear_KeyPress(KeyAscii As Integer)
    If Chr(KeyAscii) = Enter Then txtMonth.SetFocus
End Sub
