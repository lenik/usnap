VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmPGVars
   Caption         =   "棋盘生成 参数变量"
   ClientHeight    =   5655
   ClientLeft      =   4035
   ClientTop       =   3015
   ClientWidth     =   7485
   LinkTopic       =   "Form1"
   ScaleHeight     =   5655
   ScaleWidth      =   7485
   Begin VB.TextBox txtGameName
      BorderStyle     =   0  'None
      BeginProperty Font
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   285
      Left            =   1350
      TabIndex        =   16
      Top             =   270
      Width           =   2565
   End
   Begin MSComDlg.CommonDialog cdColor
      Left            =   4560
      Top             =   2610
      _ExtentX        =   688
      _ExtentY        =   688
      _Version        =   393216
   End
   Begin VB.PictureBox pColor
      Appearance      =   0  'Flat
      BackColor       =   &H00C0FFFF&
      FillColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   252
      Left            =   3480
      ScaleHeight     =   225
      ScaleWidth      =   945
      TabIndex        =   13
      Top             =   2730
      Width           =   972
   End
   Begin VB.TextBox numVarsMax
      Height          =   315
      Left            =   1350
      TabIndex        =   0
      Text            =   "1"
      Top             =   915
      Width           =   4065
   End
   Begin VB.TextBox numRange
      Appearance      =   0  'Flat
      Height          =   345
      Index           =   1
      Left            =   1800
      TabIndex        =   9
      Top             =   3315
      Width           =   1215
   End
   Begin VB.TextBox numRange
      Appearance      =   0  'Flat
      Height          =   315
      Index           =   0
      Left            =   1800
      TabIndex        =   7
      Top             =   2715
      Width           =   1215
   End
   Begin VB.TextBox txtGName
      Appearance      =   0  'Flat
      Height          =   315
      Left            =   1800
      TabIndex        =   5
      Top             =   2115
      Width           =   2415
   End
   Begin VB.TextBox txtVarName
      Appearance      =   0  'Flat
      Height          =   300
      Left            =   1800
      TabIndex        =   3
      Top             =   1440
      Width           =   2535
   End
   Begin VB.VScrollBar vscrl
      Height          =   3375
      Left            =   240
      Max             =   0
      TabIndex        =   1
      Top             =   1410
      Width           =   495
   End
   Begin VB.CommandButton Command1
      Caption         =   "&O确定"
      Height          =   390
      Left            =   3975
      TabIndex        =   10
      Top             =   4650
      Width           =   1440
   End
   Begin VB.Label Label8
      AutoSize        =   -1  'True
      Caption         =   "题目"
      Height          =   180
      Left            =   270
      TabIndex        =   15
      Top             =   330
      Width           =   360
   End
   Begin VB.Label Label7
      AutoSize        =   -1  'True
      Caption         =   "该方颜色"
      Height          =   180
      Left            =   3480
      TabIndex        =   14
      Top             =   3090
      Width           =   720
   End
   Begin VB.Label Label5
      BackStyle       =   0  'Transparent
      Caption         =   "存储数据暂存于套装主程序中Areas[], 如需借此动态变化main中的棋盘, 忽略所有参数, 设好上下标差距, 变量数直接对应Areas[n]"
      Height          =   615
      Left            =   1080
      TabIndex        =   12
      Top             =   3930
      Width           =   4095
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      Caption         =   "最大变量数"
      Height          =   180
      Left            =   225
      TabIndex        =   11
      Top             =   990
      Width           =   900
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "下标"
      Height          =   180
      Left            =   1050
      TabIndex        =   8
      Top             =   3390
      Width           =   360
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "上标"
      Height          =   180
      Left            =   1050
      TabIndex        =   6
      Top             =   2790
      Width           =   360
   End
   Begin VB.Label fff
      Caption         =   "描述"
      Height          =   240
      Left            =   1050
      TabIndex        =   4
      Top             =   2190
      Width           =   390
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "变量名"
      Height          =   180
      Left            =   960
      TabIndex        =   2
      Top             =   1530
      Width           =   540
   End
End
Attribute VB_Name = "frmPGVars"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Option Base 0

Private Sub Command1_Click()
    Me.Hide
End Sub

Private Sub Form_Load()
    vscrl_Change
End Sub

Private Sub numRange_KeyPress(Index As Integer, KeyAscii As Integer)
    If KeyAscii > Asc("9") Then KeyAscii = 0
End Sub

Private Sub numVarsMax_Change()
    If (Val(numVarsMax.Text) > MAXAREAS) Then
        numVarsMax = LTrim(Str(MAXAREAS))
    End If
    ' 0 < nhaveareas <= maxareas
    If (Val(numVarsMax.Text) > 0) Then              ' 输入合法
        numVarsMax.ForeColor = &H80000008
        nHaveAreas = Val(numVarsMax.Text)
        vscrl.Max = nHaveAreas - 1
        frmPadGen.vscrl.Max = vscrl.Max
    Else
        numVarsMax.ForeColor = &HFF
    End If
End Sub

Private Sub numVarsMax_KeyPress(KeyAscii As Integer)
    If KeyAscii > Asc("9") Then KeyAscii = 0
End Sub

Private Sub pColor_Click()
    cdColor.ShowColor
    If Not cdColor.CancelError Then
        Areas(nCurArea).Color = cdColor.Color
        pColor.BackColor = cdColor.Color
    End If
End Sub

Private Sub txtGameName_Change()
    strGameName = txtGameName
End Sub

Private Sub txtVarName_Change()
    PGVar(nCurArea).Name = txtVarName.Text
End Sub

Private Sub txtGName_Change()
    PGVar(nCurArea).GName = txtGName.Text
End Sub

Private Sub numRange_Change(Index As Integer)
    ' 0 <= min <= max
    If Val(numRange(0).Text) < 0 Then numRange(0).Text = "0"
    If Val(numRange(1).Text) < Val(numRange(0).Text) Then numRange(1).Text = numRange(0).Text
    ' max - min < maxnodes
    If Val(numRange(1).Text) - Val(numRange(0).Text) + 1 > MAXNODES Then      ' 输入不合法
        numRange(1).Text = LTrim(Str(Val(numRange(0).Text) + MAXNODES - 1))
    End If

    If Val(numRange(Index).Text) >= 0 Then       ' 相对应文本框输入合法
        numRange(Index).ForeColor = &H80000008
        Select Case Index
            Case 0: PGVar(nCurArea).nNumberFirst = Val(numRange(0))
            Case 1: Areas(nCurArea).nHaveNodes = Val(numRange(1)) - PGVar(nCurArea).nNumberFirst + 1
        End Select
    Else
        numRange(Index).ForeColor = &HFF
    End If
End Sub

Private Sub vscrl_Change()
    nCurArea = vscrl.Value
    frmPadGen.vscrl.Value = nCurArea
    txtVarName = PGVar(nCurArea).Name
    txtGName = PGVar(nCurArea).GName
    numRange(0) = LTrim(Str(PGVar(nCurArea).nNumberFirst))
    numRange(1) = LTrim(Str(PGVar(nCurArea).nNumberFirst + Areas(nCurArea).nHaveNodes - 1))
    pColor.BackColor = Areas(nCurArea).Color
End Sub

Private Sub vscrl_Scroll()
    vscrl_Change
End Sub
