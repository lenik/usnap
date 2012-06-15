VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "直线, 矩形和圆"
   ClientHeight    =   4995
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6075
   LinkTopic       =   "Form1"
   ScaleHeight     =   4995
   ScaleWidth      =   6075
   StartUpPosition =   3  '窗口缺省
   Begin VB.HScrollBar sV
      Height          =   270
      LargeChange     =   5
      Left            =   1170
      Max             =   100
      Min             =   1
      TabIndex        =   7
      Top             =   3885
      Value           =   15
      Width           =   4635
   End
   Begin VB.CommandButton cmdMakeFace
      Caption         =   "&F 眼睛嘴巴"
      Height          =   495
      Left            =   180
      TabIndex        =   9
      Top             =   5100
      Width           =   5655
   End
   Begin VB.CommandButton cmdSwitch
      Caption         =   "&S 切换"
      Height          =   495
      Left            =   180
      TabIndex        =   8
      Top             =   4365
      Width           =   5655
   End
   Begin VB.CommandButton shape
      Caption         =   "&C 圆"
      Height          =   555
      Index           =   2
      Left            =   420
      TabIndex        =   4
      ToolTipText     =   "右键改变顺序"
      Top             =   3120
      Width           =   1095
   End
   Begin VB.CommandButton shape
      Caption         =   "&R 矩形"
      Height          =   555
      Index           =   1
      Left            =   420
      TabIndex        =   3
      ToolTipText     =   "右键改变顺序"
      Top             =   2040
      Width           =   1095
   End
   Begin VB.CommandButton shape
      Caption         =   "&L 直线"
      Height          =   555
      Index           =   0
      Left            =   420
      TabIndex        =   2
      ToolTipText     =   "右键改变顺序"
      Top             =   1020
      Width           =   1095
   End
   Begin VB.PictureBox pic
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   2655
      Left            =   1680
      ScaleHeight     =   175
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   251
      TabIndex        =   5
      Top             =   1020
      Width           =   3795
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "&V 速度"
      Height          =   180
      Left            =   195
      TabIndex        =   6
      Top             =   3915
      Width           =   540
   End
   Begin VB.Line Line1
      BorderColor     =   &H00FFFFFF&
      Index           =   1
      X1              =   120
      X2              =   5880
      Y1              =   855
      Y2              =   855
   End
   Begin VB.Line Line2
      BorderColor     =   &H00C00000&
      BorderWidth     =   3
      Index           =   2
      X1              =   300
      X2              =   180
      Y1              =   3120
      Y2              =   3660
   End
   Begin VB.Line Line2
      BorderColor     =   &H00C00000&
      BorderWidth     =   3
      Index           =   1
      X1              =   60
      X2              =   180
      Y1              =   3120
      Y2              =   3660
   End
   Begin VB.Line Line2
      BorderColor     =   &H00C00000&
      BorderWidth     =   3
      Index           =   0
      X1              =   180
      X2              =   180
      Y1              =   1020
      Y2              =   3660
   End
   Begin VB.Line Line1
      Index           =   0
      X1              =   120
      X2              =   5880
      Y1              =   840
      Y2              =   840
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "谢继雷/桃壳软件 2001.3 中国浙江   ...交作业..."
      ForeColor       =   &H00808080&
      Height          =   180
      Left            =   240
      TabIndex        =   1
      Top             =   540
      Width           =   4140
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "直线, 矩形和圆的后端分散转换算法"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00008000&
      Height          =   240
      Left            =   240
      TabIndex        =   0
      Top             =   180
      Width           =   4095
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'
' 直线, 矩形和圆
'

' 状态变量
        Dim shapeID As Integer                  ' 当前显示的图形号
        Dim bDowned As Integer, xDown As Double, yDown As Double

        Private lineM(0 To 1) As POINT
        Private rectM(0 To 3) As POINT
        Private circleM(0 To 100) As POINT

' 切换
        Const shapeLine As Integer = 0
        Const shapeRect As Integer = 1
        Const shapeCircle As Integer = 2

        ' 切换函数
        Public Function SwitchTo(ByVal fromID As Integer, ByVal toID As Integer) As Boolean
                SwitchTo = True

                Select Case toID * 4 + fromID
                Case 0: SwitchTo = RTrans(lineM, 2, lineM, 2)
                Case 1: SwitchTo = RTrans(rectM, 4, lineM, 2)
                Case 2: SwitchTo = RTrans(circleM, 101, lineM, 2)
                Case 4: SwitchTo = RTrans(lineM, 2, rectM, 4)
                Case 5: SwitchTo = RTrans(rectM, 4, rectM, 4)
                Case 6: SwitchTo = RTrans(circleM, 101, rectM, 4)
                Case 8: SwitchTo = RTrans(lineM, 2, circleM, 101)
                Case 9: SwitchTo = RTrans(rectM, 4, circleM, 101)
                Case 10: SwitchTo = RTrans(circleM, 101, circleM, 101)
                End Select
        End Function

        Private Sub cmdSwitch_Click()
                Dim i As Integer
                Dim YMin As Double, YMinI As Integer, YMax As Double, YMaxI As Integer
                YMin = -1
                YMax = -1
                For i = 0 To 2
                        If shape(i).Top < YMin Or YMin < 0 Then YMin = shape(i).Top: YMinI = i
                        If shape(i).Top > shape(shapeID).Top Then
                                If shape(i).Top < YMax Or YMax < 0 Then
                                        YMax = shape(i).Top
                                        YMaxI = i
                                End If
                        End If
                Next
                If YMax >= 0 Then
                        MorphTo YMaxI
                Else
                        MorphTo YMinI
                End If
        End Sub

Private Sub MorphTo(ByVal toID)
        If toID = shapeID Then Exit Sub
        SwitchTo shapeID, toID
        shapeID = toID
End Sub

Private Sub cmdMakeFace_Click()
        Dim faceM(0 To 119) As POINT
        Dim i As Integer

        For i = 0 To 39
                faceM(i).X = Cos(6.28 * i / 39) * 20 + 70
                faceM(i).Y = Sin(6.28 * i / 39) * 20 + 40
        Next
        For i = 40 To 79
                faceM(i) = faceM(i - 40)
                faceM(i).X = 180 - faceM(i).X
        Next
        For i = 80 To 119
                faceM(i).X = Cos(3.14 * (i - 80) / 39) * 25 + 95
                faceM(i).Y = Sin(3.14 * (i - 80) / 39) * 12 + 70
        Next

        Select Case shapeID
        Case 0: RTrans lineM, 2, faceM, 120
        Case 1: RTrans rectM, 4, faceM, 120
        Case 2: RTrans circleM, 101, faceM, 120
        End Select
End Sub

Private Sub Form_Load()
        Dim i As Integer, a As Double

        shapeID = 0
        Set modGraph.pic = Me.pic
        sV_Change

        ' 初始化图形数据
                lineM(0).X = 40: lineM(0).Y = 120
                lineM(1).X = 200: lineM(1).Y = 40

                rectM(0).X = 19: rectM(0).Y = 17
                rectM(1).X = 226: rectM(1).Y = 17
                rectM(2).X = 226: rectM(2).Y = 151
                rectM(3).X = 19: rectM(3).Y = 151

                i = 0
                For a = 0 To 6.281 Step 6.28 / 100
                        circleM(i).X = Cos(a) * 100 + 120
                        circleM(i).Y = Sin(a) * 60 + 70
                        i = i + 1
                Next
End Sub

Private Sub shape_Click(Index As Integer)
        MorphTo Index
End Sub

Private Sub shape_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If Button And vbRightButton Then bDowned = True: xDown = X: yDown = Y
End Sub
Private Sub shape_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If bDowned Then
                shape(Index).Left = shape(Index).Left + X - xDown
                shape(Index).Top = shape(Index).Top + Y - yDown
        End If
End Sub
Private Sub shape_MouseUp(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If Button And vbRightButton Then bDowned = False
End Sub

Private Sub sV_Change()
        sStep = -Log((101 - sV.Value) / 100) / 10
End Sub

Private Sub sV_Scroll()
        sV_Change
End Sub
