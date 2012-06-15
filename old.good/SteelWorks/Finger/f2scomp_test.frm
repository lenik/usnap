VERSION 5.00
Begin VB.Form Form1
   Caption         =   "模糊比较算法测试"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6750
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   6750
   StartUpPosition =   3  '窗口缺省
   Begin VB.CheckBox chkAnsi
      Caption         =   "ANSI代码"
      Height          =   315
      Left            =   3960
      TabIndex        =   15
      Top             =   1680
      Width           =   1875
   End
   Begin VB.TextBox Text2
      Height          =   270
      Left            =   4590
      TabIndex        =   10
      Text            =   "4"
      Top             =   2835
      Width           =   1215
   End
   Begin VB.TextBox Text1
      Height          =   270
      Left            =   4590
      TabIndex        =   9
      Text            =   "10"
      Top             =   2475
      Width           =   1215
   End
   Begin VB.TextBox robj
      ForeColor       =   &H00000080&
      Height          =   270
      Left            =   1155
      Locked          =   -1  'True
      TabIndex        =   4
      TabStop         =   0   'False
      Top             =   960
      Width           =   4680
   End
   Begin VB.TextBox rref
      ForeColor       =   &H00000080&
      Height          =   315
      Left            =   1170
      Locked          =   -1  'True
      TabIndex        =   3
      TabStop         =   0   'False
      Top             =   195
      Width           =   4650
   End
   Begin VB.CommandButton chk
      Caption         =   "比较"
      Height          =   315
      Left            =   3975
      TabIndex        =   2
      Top             =   2025
      Width           =   1815
   End
   Begin VB.TextBox obj
      Height          =   315
      Left            =   1155
      TabIndex        =   1
      Text            =   "Hello, very one."
      Top             =   1260
      Width           =   4695
   End
   Begin VB.TextBox ref
      Height          =   315
      Left            =   1155
      TabIndex        =   0
      Text            =   "hello, every one!"
      Top             =   555
      Width           =   4680
   End
   Begin VB.Line Line6
      BorderColor     =   &H00FF00FF&
      X1              =   1020
      X2              =   180
      Y1              =   1440
      Y2              =   1440
   End
   Begin VB.Line Line5
      BorderColor     =   &H00FF00FF&
      X1              =   1080
      X2              =   180
      Y1              =   720
      Y2              =   720
   End
   Begin VB.Line Line4
      BorderColor     =   &H00FF00FF&
      X1              =   180
      X2              =   180
      Y1              =   1560
      Y2              =   720
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "输入串"
      Height          =   180
      Left            =   60
      TabIndex        =   14
      Top             =   1620
      Width           =   540
   End
   Begin VB.Line Line3
      X1              =   420
      X2              =   1080
      Y1              =   1080
      Y2              =   1080
   End
   Begin VB.Line Line2
      X1              =   420
      X2              =   1140
      Y1              =   360
      Y2              =   360
   End
   Begin VB.Line Line1
      X1              =   420
      X2              =   420
      Y1              =   180
      Y2              =   1080
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "集成环境"
      Height          =   180
      Index           =   0
      Left            =   60
      TabIndex        =   13
      Top             =   60
      Width           =   720
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "广度"
      Height          =   180
      Left            =   3975
      TabIndex        =   12
      Top             =   2520
      Width           =   360
   End
   Begin VB.Label 深度
      AutoSize        =   -1  'True
      Caption         =   "深度"
      Height          =   180
      Left            =   3975
      TabIndex        =   11
      Top             =   2910
      Width           =   360
   End
   Begin VB.Label r
      Height          =   300
      Index           =   3
      Left            =   255
      TabIndex        =   8
      Top             =   2790
      Width           =   1575
   End
   Begin VB.Label r
      Height          =   300
      Index           =   2
      Left            =   270
      TabIndex        =   7
      Top             =   2475
      Width           =   1575
   End
   Begin VB.Label r
      Height          =   300
      Index           =   1
      Left            =   300
      TabIndex        =   6
      Top             =   2160
      Width           =   1575
   End
   Begin VB.Label r
      Height          =   300
      Index           =   0
      Left            =   315
      TabIndex        =   5
      Top             =   1845
      Width           =   1575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub chk_Click()
        Dim cr As COMPRESULT

        cr = FuzzyComp(ref.Text, obj.Text, chkAnsi)
        If cr.right >= 0 Then
                r(0) = "正确 " & cr.right
                r(1) = "错误" & cr.wrong
                r(2) = "多余 " & cr.extra
                r(3) = "缺少 " & cr.lost
                rref = cr.resultRef
                robj = cr.resultObj
        End If
End Sub

Private Sub obj_Change()
        chk_Click
End Sub

Private Sub ref_Change()
        chk_Click
End Sub

Private Sub Text1_Change()
        SetDepth val(Text1)
End Sub

Private Sub Text2_Change()
        SetSame val(Text2)
End Sub
