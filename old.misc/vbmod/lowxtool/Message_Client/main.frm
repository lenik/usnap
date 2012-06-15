VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "VB消息支持扩展"
   ClientHeight    =   2910
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6210
   LinkTopic       =   "Form1"
   ScaleHeight     =   2910
   ScaleWidth      =   6210
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1
      Caption         =   "&A关于VB底层扩展"
      Height          =   450
      Left            =   3630
      TabIndex        =   12
      Top             =   2265
      Width           =   2190
   End
   Begin VB.OptionButton opt1
      Caption         =   "新的消息处理"
      Height          =   315
      Index           =   1
      Left            =   2565
      TabIndex        =   11
      Top             =   1650
      Width           =   2520
   End
   Begin VB.OptionButton opt1
      Caption         =   "原始消息处理"
      Height          =   315
      Index           =   0
      Left            =   2550
      TabIndex        =   10
      Top             =   1260
      Value           =   -1  'True
      Width           =   2520
   End
   Begin VB.TextBox txtCounter
      Height          =   390
      Left            =   3255
      TabIndex        =   9
      Text            =   "0"
      Top             =   645
      Width           =   1980
   End
   Begin VB.Label lblInfo
      AutoSize        =   -1  'True
      Caption         =   "鼠标移动次数"
      Height          =   180
      Index           =   4
      Left            =   2610
      TabIndex        =   8
      Top             =   360
      Width           =   1080
   End
   Begin VB.Label iLparam
      AutoSize        =   -1  'True
      Caption         =   "---"
      Height          =   180
      Left            =   1635
      TabIndex        =   7
      Top             =   2100
      Width           =   270
   End
   Begin VB.Label lblInfo
      AutoSize        =   -1  'True
      Caption         =   "长参数"
      Height          =   180
      Index           =   3
      Left            =   495
      TabIndex        =   6
      Top             =   2115
      Width           =   540
   End
   Begin VB.Label iWparam
      AutoSize        =   -1  'True
      Caption         =   "---"
      Height          =   180
      Left            =   1635
      TabIndex        =   5
      Top             =   1590
      Width           =   270
   End
   Begin VB.Label lblInfo
      AutoSize        =   -1  'True
      Caption         =   "短参数"
      Height          =   180
      Index           =   2
      Left            =   495
      TabIndex        =   4
      Top             =   1605
      Width           =   540
   End
   Begin VB.Label iWnd
      AutoSize        =   -1  'True
      Caption         =   "---"
      Height          =   180
      Left            =   1650
      TabIndex        =   3
      Top             =   1095
      Width           =   270
   End
   Begin VB.Label lblInfo
      AutoSize        =   -1  'True
      Caption         =   "窗口"
      Height          =   180
      Index           =   1
      Left            =   510
      TabIndex        =   2
      Top             =   1110
      Width           =   360
   End
   Begin VB.Label iMessage
      AutoSize        =   -1  'True
      Caption         =   "---"
      Height          =   180
      Left            =   1665
      TabIndex        =   1
      Top             =   615
      Width           =   270
   End
   Begin VB.Label lblInfo
      AutoSize        =   -1  'True
      Caption         =   "消息"
      Height          =   180
      Index           =   0
      Left            =   525
      TabIndex        =   0
      Top             =   630
      Width           =   360
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        ltp.About
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        txtCounter.Text = str(Val(txtCounter.Text) + 1)
End Sub

Private Sub opt1_Click(Index As Integer)
        If opt1(0) Then
                lte.VCatchMessage Me.hWnd, ltp.Vpf(AddressOf 恢复回调)
        ElseIf opt1(1) Then
                lte.VCatchMessage Me.hWnd, ltp.Vpf(AddressOf modMessage.处理进程交换回调)
        End If
End Sub
