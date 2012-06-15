VERSION 5.00
Begin VB.Form frmDataSetup
   Appearance      =   0  'Flat
   BackColor       =   &H80000005&
   Caption         =   "模版数据设置"
   ClientHeight    =   3900
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5430
   ControlBox      =   0   'False
   Icon            =   "f2DataSetup.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   3900
   ScaleWidth      =   5430
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox txtData
      Appearance      =   0  'Flat
      Height          =   2655
      Left            =   240
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Text            =   "f2DataSetup.frx":0E42
      Top             =   1020
      Width           =   4935
   End
   Begin VB.Label Return
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "返回"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   180
      Left            =   4740
      MousePointer    =   10  'Up Arrow
      TabIndex        =   11
      Top             =   720
      Width           =   360
   End
   Begin VB.Label Generate
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "生成一堆文字"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   180
      Index           =   1
      Left            =   240
      MousePointer    =   10  'Up Arrow
      TabIndex        =   10
      Top             =   720
      Width           =   1080
   End
   Begin VB.Label Label1
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "。"
      ForeColor       =   &H80000008&
      Height          =   180
      Index           =   8
      Left            =   1380
      TabIndex        =   9
      Top             =   720
      Width           =   180
   End
   Begin VB.Label Generate
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "点记这里本程序自动"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   180
      Index           =   0
      Left            =   3480
      MousePointer    =   10  'Up Arrow
      TabIndex        =   8
      Top             =   420
      Width           =   1620
   End
   Begin VB.Label Label1
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "也可以"
      ForeColor       =   &H80000008&
      Height          =   180
      Index           =   6
      Left            =   2880
      TabIndex        =   7
      Top             =   420
      Width           =   540
   End
   Begin VB.Label Label1
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "来指定输入对照内容。"
      ForeColor       =   &H80000008&
      Height          =   180
      Index           =   5
      Left            =   1020
      TabIndex        =   6
      Top             =   420
      Width           =   1800
   End
   Begin VB.Label GetFromDisk
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "上的文件"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000C000&
      Height          =   180
      Index           =   1
      Left            =   240
      MousePointer    =   10  'Up Arrow
      TabIndex        =   5
      Top             =   420
      Width           =   720
   End
   Begin VB.Label GetFromDisk
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "读取磁盘"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000C000&
      Height          =   180
      Index           =   0
      Left            =   4380
      MousePointer    =   10  'Up Arrow
      TabIndex        =   4
      Top             =   120
      Width           =   720
   End
   Begin VB.Label Label1
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "或者通过"
      ForeColor       =   &H80000008&
      Height          =   180
      Index           =   2
      Left            =   3600
      TabIndex        =   3
      Top             =   120
      Width           =   720
   End
   Begin VB.Label ChangeDirect
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "直接改变文本框的内容"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF8080&
      Height          =   180
      Left            =   1740
      MousePointer    =   10  'Up Arrow
      TabIndex        =   2
      Top             =   120
      Width           =   1800
   End
   Begin VB.Label Label1
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "在这里您可以通过"
      ForeColor       =   &H80000008&
      Height          =   180
      Index           =   0
      Left            =   240
      TabIndex        =   1
      Top             =   120
      Width           =   1440
   End
End
Attribute VB_Name = "frmDataSetup"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim Status As Integer

Public Function Run() As String
        Dim lastText As String

        Status = 0
        frmDataSetup.Show

        lastText = txtData
        While Status = 0
                DoEvents
        Wend

        If Status = 2 Then txtData = lastText
        Run = txtData

        frmDataSetup.Hide
End Function

Private Sub ChangeDirect_Click()
        txtData.SelStart = 0
        txtData.SelLength = Len(txtData)
        txtData.SetFocus
End Sub

Private Sub Form_Load()
        Dim t As String
        t = GetSetting(FingerRoot, "申请者", "测试数据")
        If Len(t) > 0 Then
                txtData = t
        End If
End Sub

Private Sub Form_Resize()
        If width < 1000 Then Me.width = 1000
        txtData.width = Me.width - 615
        If height < 2000 Then Me.height = 2000
        txtData.height = Me.height - 1650
End Sub

Private Sub Form_Unload(Cancel As Integer)
        SaveSetting FingerRoot, "申请者", "测试数据", tempContent
End Sub

Private Sub Generate_Click(Index As Integer)
        Dim I
        Dim C As String

        For I = 1 To 4096
                C = C & Chr(Int(Rnd * 5000) + Asc("啊"))
                If Int(Rnd * 100) = 0 Then C = C & vbNewLine
        Next
        txtData = txtData & C
End Sub

Private Sub GetFromDisk_Click(Index As Integer)
        Dim F
        Dim S As String
        On Error GoTo E
        frmMain.cdMain.ShowOpen

        F = FreeFile
        Open frmMain.cdMain.FileName For Input As #F
                On Error GoTo e2
                txtData = ""

                While Not EOF(F)
                        Line Input #F, S
                        txtData = txtData & S & vbNewLine
                Wend
e2:
        Close #F
        Exit Sub
E:
End Sub

Private Sub Return_Click()
    Status = 1
End Sub
