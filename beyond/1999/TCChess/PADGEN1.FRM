VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmPadGen1
   Caption         =   "桃壳棋风 棋盘生成"
   ClientHeight    =   5400
   ClientLeft      =   1725
   ClientTop       =   2805
   ClientWidth     =   7485
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   ScaleHeight     =   5400
   ScaleWidth      =   7485
   Begin VB.Frame frameBatch
      Caption         =   "批量自动生成"
      ForeColor       =   &H00C00000&
      Height          =   1935
      Left            =   120
      TabIndex        =   2
      Top             =   60
      Width           =   6555
      Begin VB.CheckBox chkVArrange
         Caption         =   "直排"
         ForeColor       =   &H00400000&
         Height          =   225
         Left            =   1230
         Style           =   1  'Graphical
         TabIndex        =   35
         Top             =   840
         Width           =   795
      End
      Begin VB.CheckBox chkAutoHVLines
         Caption         =   "横竖路线"
         ForeColor       =   &H00400000&
         Height          =   225
         Left            =   2280
         Style           =   1  'Graphical
         TabIndex        =   34
         Top             =   840
         Width           =   1155
      End
      Begin VB.TextBox txtCurVar
         Appearance      =   0  'Flat
         BorderStyle     =   0  'None
         Height          =   225
         Left            =   3900
         TabIndex        =   32
         Top             =   1440
         Width           =   2565
      End
      Begin VB.HScrollBar vscrl
         Height          =   240
         Left            =   4740
         Max             =   0
         TabIndex        =   31
         Top             =   1200
         Width           =   1740
      End
      Begin VB.PictureBox Picture1
         BackColor       =   &H00E0E0E0&
         BorderStyle     =   0  'None
         Height          =   855
         Left            =   60
         ScaleHeight     =   855
         ScaleWidth      =   855
         TabIndex        =   20
         Top             =   1020
         Width           =   855
         Begin VB.CommandButton cmdDir
            Caption         =   "┘"
            Height          =   315
            Index           =   8
            Left            =   540
            TabIndex        =   29
            Top             =   480
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "↓"
            Height          =   252
            Index           =   7
            Left            =   300
            TabIndex        =   28
            Top             =   540
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "└"
            Height          =   252
            Index           =   6
            Left            =   60
            TabIndex        =   27
            Top             =   540
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "→"
            Height          =   252
            Index           =   5
            Left            =   540
            TabIndex        =   26
            Top             =   300
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "┼"
            Height          =   252
            Index           =   4
            Left            =   300
            TabIndex        =   25
            Top             =   300
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "←"
            Height          =   252
            Index           =   3
            Left            =   60
            TabIndex        =   24
            Top             =   300
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "┐"
            Height          =   252
            Index           =   2
            Left            =   540
            TabIndex        =   23
            Top             =   60
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "↑"
            Height          =   252
            Index           =   1
            Left            =   300
            TabIndex        =   22
            Top             =   60
            Width           =   252
         End
         Begin VB.CommandButton cmdDir
            Caption         =   "┌"
            Default         =   -1  'True
            Height          =   252
            Index           =   0
            Left            =   60
            TabIndex        =   21
            Top             =   60
            Width           =   252
         End
      End
      Begin VB.Frame Frame2
         Caption         =   "生成模版"
         ForeColor       =   &H00004000&
         Height          =   855
         Left            =   3900
         TabIndex        =   13
         Top             =   240
         Width           =   2535
         Begin VB.CheckBox chkNode_
            Caption         =   "尾缀"
            ForeColor       =   &H00400040&
            Height          =   255
            Left            =   1740
            TabIndex        =   19
            Top             =   180
            Width           =   675
         End
         Begin VB.ComboBox cboNodeTemp
            Height          =   300
            Left            =   540
            TabIndex        =   18
            Text            =   "普通"
            Top             =   180
            Width           =   1155
         End
         Begin VB.CheckBox chkWay_
            Caption         =   "尾缀"
            ForeColor       =   &H00400040&
            Height          =   255
            Left            =   1740
            TabIndex        =   16
            Top             =   480
            Width           =   675
         End
         Begin VB.ComboBox cboWayTemp
            Height          =   300
            Left            =   540
            TabIndex        =   14
            Text            =   "普通"
            Top             =   480
            Width           =   1155
         End
         Begin VB.Label Label5
            AutoSize        =   -1  'True
            Caption         =   "结点"
            ForeColor       =   &H00800080&
            Height          =   180
            Left            =   60
            TabIndex        =   17
            Top             =   240
            Width           =   360
         End
         Begin VB.Label Label4
            AutoSize        =   -1  'True
            Caption         =   "路线"
            ForeColor       =   &H00800080&
            Height          =   180
            Left            =   60
            TabIndex        =   15
            Top             =   540
            Width           =   360
         End
      End
      Begin VB.TextBox numRect
         Appearance      =   0  'Flat
         Height          =   255
         Index           =   0
         Left            =   1260
         TabIndex        =   9
         Top             =   540
         Width           =   855
      End
      Begin VB.TextBox numRect
         Appearance      =   0  'Flat
         Height          =   255
         Index           =   1
         Left            =   2280
         TabIndex        =   8
         Top             =   540
         Width           =   855
      End
      Begin VB.CommandButton cmdGenerate
         Caption         =   "截取"
         Height          =   252
         Left            =   3240
         TabIndex        =   7
         Top             =   540
         Width           =   615
      End
      Begin VB.CommandButton cmdGet
         Caption         =   "截取"
         Height          =   255
         Left            =   3240
         TabIndex        =   6
         Top             =   240
         Width           =   615
      End
      Begin VB.TextBox numSize
         Appearance      =   0  'Flat
         Height          =   270
         Index           =   1
         Left            =   2280
         TabIndex        =   5
         Top             =   240
         Width           =   855
      End
      Begin VB.TextBox numSize
         Appearance      =   0  'Flat
         Height          =   270
         Index           =   0
         Left            =   1260
         TabIndex        =   4
         Top             =   240
         Width           =   855
      End
      Begin VB.CheckBox chkUseFixRect
         Caption         =   "定制大小"
         ForeColor       =   &H00000040&
         Height          =   255
         Left            =   120
         TabIndex        =   3
         Top             =   240
         Width           =   1215
      End
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "选择变量"
         ForeColor       =   &H00404000&
         Height          =   180
         Left            =   3900
         TabIndex        =   33
         Top             =   1230
         Width           =   720
      End
      Begin VB.Label Label2
         AutoSize        =   -1  'True
         Caption         =   "X"
         Height          =   180
         Index           =   1
         Left            =   2160
         TabIndex        =   30
         Top             =   600
         Width           =   90
      End
      Begin VB.Label Label2
         AutoSize        =   -1  'True
         Caption         =   "X"
         Height          =   180
         Index           =   0
         Left            =   2160
         TabIndex        =   12
         Top             =   300
         Width           =   90
      End
      Begin VB.Label lblCurrentAlign
         Appearance      =   0  'Flat
         BackColor       =   &H00C0FFFF&
         BorderStyle     =   1  'Fixed Single
         ForeColor       =   &H80000008&
         Height          =   225
         Left            =   120
         TabIndex        =   11
         Top             =   600
         Width           =   225
      End
      Begin VB.Label Label1
         AutoSize        =   -1  'True
         Caption         =   "生成边界"
         ForeColor       =   &H00008000&
         Height          =   180
         Left            =   510
         TabIndex        =   10
         Top             =   570
         Width           =   720
      End
   End
   Begin VB.PictureBox imgBack
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      ClipControls    =   0   'False
      ForeColor       =   &H80000008&
      Height          =   2715
      Left            =   300
      ScaleHeight     =   2685
      ScaleWidth      =   6255
      TabIndex        =   0
      Top             =   2280
      Width           =   6285
      Begin VB.PictureBox imgText
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H00000000&
         BorderStyle     =   0  'None
         ForeColor       =   &H00FFFFC0&
         Height          =   555
         Left            =   120
         ScaleHeight     =   555
         ScaleWidth      =   2175
         TabIndex        =   1
         Top             =   60
         Visible         =   0   'False
         Width           =   2175
      End
      Begin MSComDlg.CommonDialog cdBackFile
         Left            =   120
         Top             =   1800
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
      End
   End
   Begin VB.Line lineRight
      X1              =   6810
      X2              =   7200
      Y1              =   3900
      Y2              =   4380
   End
   Begin VB.Menu mnuLoadBackground
      Caption         =   "&L装入背景"
   End
   Begin VB.Menu mnuControlVars
      Caption         =   "&V参数变量"
   End
   Begin VB.Menu mnuReturn
      Caption         =   "&R返回"
   End
End
Attribute VB_Name = "frmPadGen1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Option Base 0

' 定制固定矩形
Dim nsRectSize As TNodeStatic, varRectSize As NodeRect
' 标号排列方式
Dim Varrange As Boolean
' 伴随自动生成横直线
Dim bAutoHVLines As Boolean
' 鼠标按下微量偏移值
Dim oLeft As Single, oTop As Single
' 连线辅助变量
Dim bDrawLine As Boolean, bLining As Boolean, bLineOnNode As Boolean

' 线性矩形操作
    Private Sub nsMouseDown(ns As TNodeStatic, var As NodeRect, Button As Integer, Shift As Integer, X As Single, Y As Single)
        var.adjust = True
        If Button = vbLeftButton Then            ' Moving
            var.adjX = X - ns.Left: var.adjY = Y - ns.Top
        ElseIf Button = vbRightButton Then       ' Sizing
            nsMove ns, var, X, Y
        End If
    End Sub
    Private Sub nsMouseMove(ns As TNodeStatic, var As NodeRect, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If var.adjust Then
            If Button = vbLeftButton Then        ' Moving
                nsMove ns, var, X - var.adjX, Y - var.adjY
            ElseIf Button = vbRightButton Then   ' Sizing
                nsSize ns, var, X - ns.Left, Y - ns.Top
            End If
        End If
    End Sub
    Private Sub OwnMouseDown(nIndex As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        PGVar(nIndex).AOwn.adjust = True
        If Button = vbLeftButton Then            ' Moving
            PGVar(nIndex).AOwn.adjX = X - PGVar(nIndex).SOwn.Left
            PGVar(nIndex).AOwn.adjY = Y - PGVar(nIndex).SOwn.Top
        ElseIf Button = vbRightButton Then       ' Sizing
            PaintOwn nIndex
            PGVar(nIndex).SOwn.Left = X
            PGVar(nIndex).SOwn.Top = Y
            PaintOwn nIndex
        End If
    End Sub
    Private Sub OwnMouseMove(nIndex As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If PGVar(nIndex).AOwn.adjust Then
            If Button = vbLeftButton Then        ' Moving
                PaintOwn nIndex
                PGVar(nIndex).SOwn.Left = X - PGVar(nIndex).AOwn.adjX
                PGVar(nIndex).SOwn.Top = Y - PGVar(nIndex).AOwn.adjY
                PaintOwn nIndex
            ElseIf Button = vbRightButton Then   ' Sizing
                PaintOwn nIndex
                PGVar(nIndex).SOwn.Width = X - PGVar(nIndex).SOwn.Left
                PGVar(nIndex).SOwn.Height = Y - PGVar(nIndex).SOwn.Top
                PaintOwn nIndex
            End If
        End If
    End Sub
    Private Sub nsMouseUp(ns As TNodeStatic, var As NodeRect, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If Button = vbRightButton Then          ' Sizing
            If ns.Width < 0 Then ns.Left = ns.Left + ns.Width: ns.Width = -ns.Width
            If ns.Height < 0 Then ns.Top = ns.Top + ns.Height: ns.Height = -ns.Height
        End If
        var.adjust = False
    End Sub

Private Sub chkUseFixRect_Click()
    bFixSize = chkUseFixRect.Value
    chkUseFixRect.Caption = IIf(bFixSize, "浮动大小", "定制大小")
    numSize(0).Enabled = bFixSize
    numSize(1).Enabled = bFixSize
    Label2(1).Enabled = bFixSize
    cmdGet.Enabled = bFixSize
    If bFixSize Then numSize_Change 0
End Sub

' 批量小矩形生成
Private Sub cmdGenerate_Click(): If Val(numRect(0)) * Val(numRect(1)) > 0 Then MouseActive = GenerateNodes
End Sub
' 方向对齐
Private Sub cmdDir_Click(Index As Integer): lblCurrentAlign = cmdDir(Index).Caption: End Sub
' 获得定制小矩形
Private Sub cmdGet_Click(): MouseActive = GetSize: End Sub
' 横直切换
Private Sub chkVArrange_Click(): Varrange = chkVArrange: chkVArrange.Caption = IIf(Varrange, "横排", "直排"): End Sub

Private Sub Form_Load()
    Dim i As Integer, j As Integer
    Randomize Timer
    Varrange = False
    bFixSize = False
    nHaveAreas = 1
    nCurArea = 0
    For i = 0 To MAXAREAS
        PGVar(i).Name = "Var" + LTrim(Str(i))
        PGVar(i).GName = "第" + LTrim(Str(i)) + "方"
        Areas(i).nHaveNodes = 1
        Areas(i).nCurNode = 0
        PGVar(i).Min = 0
        PGVar(i).Max = 0
        PGVar(i).AOwn.adjust = False
        PGVar(i).AOwn.Index = i
        PGVar(i).AOwn.Color = &HFF0000 + i
        For j = 0 To MAXNODES
            PGVar(i).ANodes(j).Index = j
            PGVar(i).ANodes(j).Color = &HFF0000 + Int(Rnd * &H10000)
            PGVar(i).ANodes(j).adjust = False
        Next
    Next
End Sub

' 返回是否落在矩形上, 无落点矩形值为-1
Private Function GetRectOn(X As Single, Y As Single, nArea As Integer, nNode As Integer) As Boolean
    Dim i As Integer, j As Integer
    Dim S As Single, MaxSquare As Single, MaxSquareI As Integer, MaxSquareJ As Integer
    ' 准击大矩形
    MaxSquare = 0
    For i = 0 To nHaveAreas - 1
        S = nsInside(PGVar(i).SOwn, PGVar(i).AOwn, X, Y)
        If MaxSquare < S Then MaxSquare = S: MaxSquareI = i
    Next
    If MaxSquare > 0 Then
        nArea = MaxSquareI
        GetRectOn = True
        ' 任何域内准击小矩形 (域外无效, 提高速度用)
            MaxSquare = 0
            For i = 0 To Areas(nCurArea).nHaveNodes - 1
                S = nsInside(Areas(nCurArea).SNodes(i), PGVar(nCurArea).ANodes(i), X, Y)
                If MaxSquare < S Then MaxSquare = S: MaxSquareI = i
            Next
            If MaxSquare > 0 Then nNode = MaxSquareI Else nNode = -1
    Else
        ' 所有域外准击小矩形
        nArea = -1: nNode = -1
        For i = 0 To nHaveAreas - 1
            For j = 0 To Areas(j).nHaveNodes - 1
                S = nsInside(Areas(i).SNodes(j), PGVar(i).ANodes(j), X, Y)
                If MaxSquare < S Then MaxSquare = S: nArea = i: nNode = j
            Next
        Next
        GetRectOn = nNode > -1
    End If
End Function

' 主鼠标监控  -  按下
Private Sub imgBack_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    oLeft = X: oTop = Y
    Select Case MouseActive
    Case GenerateNodes
        PaintOwn nCurArea
        PGVar(nCurArea).SOwn.Left = X
        PGVar(nCurArea).SOwn.Top = Y
        PaintOwn nCurArea
        DoActive = True
    Case GetSize
        nsRectSize.Left = X
        nsRectSize.Top = Y
        nsPaint nsRectSize, varRectSize
        DoActive = True
    Case Else
        Dim i As Integer, j As Integer, bFindArea As Boolean
        Dim S As Single, MaxSquare As Single, MaxSquareI As Integer, MaxSquareJ As Integer
        ' Find the largest square mouse hits of the Areas[max1][max2]
        bFindArea = False
        For i = 0 To nHaveAreas - 1
            S = nsInside(PGVar(i).SOwn, PGVar(i).AOwn, X, Y)
            If MaxSquare < S Then MaxSquare = S: MaxSquareI = i
        Next
        If MaxSquare > 0 Then                   ' 落在一大矩形上
            MaxSquare = 0
            nCurArea = MaxSquareI
            bFindArea = True
        End If
        For i = 0 To Areas(nCurArea).nHaveNodes - 1
            S = nsInside(Areas(nCurArea).SNodes(i), PGVar(nCurArea).ANodes(i), X, Y)
            If MaxSquare < S Then MaxSquare = S: MaxSquareI = i
        Next
        If MaxSquare > 0 Then
            ' 大矩形所属又接触面最大的小矩形
            Areas(nCurArea).nCurNode = MaxSquareI
            MouseActive = OpNode
            nsMouseDown Areas(nCurArea).SNodes(MaxSquareI), PGVar(nCurArea).ANodes(MaxSquareI), Button, Shift, X, Y
            DoActive = True
        Else
            If bFindArea Then
                ' 落点大矩形
                MouseActive = OpArea
                OwnMouseDown nCurArea, Button, Shift, X, Y
                DoActive = True
            Else
                ' 既没找到最大小矩形, 又没落在大矩形上
                For j = 0 To nCurArea - 1
                    For i = 0 To Areas(j).nHaveNodes - 1
                        S = nsInside(Areas(j).SNodes(i), PGVar(j).ANodes(i), X, Y)
                        If MaxSquare < S Then MaxSquare = S: MaxSquareI = i: MaxSquareJ = j
                    Next
                Next
                For j = nCurArea + 1 To nHaveAreas - 1
                    For i = 0 To Areas(j).nHaveNodes - 1
                        S = nsInside(Areas(j).SNodes(i), PGVar(j).ANodes(i), X, Y)
                        If MaxSquare < S Then MaxSquare = S: MaxSquareI = i: MaxSquareJ = j
                    Next
                Next
                If MaxSquare > 0 Then
                    ' 落点大矩形外一小矩形
                    nCurArea = MaxSquareJ
                    Areas(nCurArea).nCurNode = MaxSquareI
                    MouseActive = OpNode
                    nsMouseDown Areas(nCurArea).SNodes(MaxSquareI), PGVar(nCurArea).ANodes(MaxSquareI), Button, Shift, X, Y
                    DoActive = True
                End If
            End If
        End If
    End Select
End Sub

' 主鼠标监控  -  移动
Private Sub imgBack_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Dim varWidth As Single, varHeight As Single
    varWidth = X - oLeft: varHeight = Y - oTop
    Dim nCurNode As Integer, nSelNode As Integer
    Dim nsParentRect As TNodeStatic
    If DoActive Then
        Select Case MouseActive
        Case GenerateNodes
            Dim i As Integer
            PaintOwn nCurArea
            PGVar(nCurArea).SOwn.Width = varWidth       ' 参考父矩形的高宽是有方向的
            PGVar(nCurArea).SOwn.Height = varHeight
            For i = 0 To Val(numRect(0)) * Val(numRect(1)) - 1
                    nsPaint Areas(nCurArea).SNodes(i), PGVar(nCurArea).ANodes(i)
            Next
            ArrangeRects PGVar(nCurArea).SOwn, Val(numRect(0)), Val(numRect(1)), Areas(nCurArea), Varrange
            For i = 0 To Val(numRect(0)) * Val(numRect(1)) - 1
                    nsPaint Areas(nCurArea).SNodes(i), PGVar(nCurArea).ANodes(i)
            Next
            PaintOwn nCurArea
        Case GetSize
            nsPaint nsRectSize, varRectSize
            nsRectSize.Width = varWidth
            nsRectSize.Height = varHeight
            numSize(0) = LTrim(Str(Abs(nsRectSize.Width)))
            numSize(1) = LTrim(Str(Abs(nsRectSize.Height)))
            nsPaint nsRectSize, varRectSize
        Case OpArea
            OwnMouseMove nCurArea, Button, Shift, X, Y
        Case OpNode
            nCurNode = Areas(nCurArea).nCurNode
            nsMouseMove Areas(nCurArea).SNodes(nCurNode), PGVar(nCurArea).ANodes(nCurNode), Button, Shift, X, Y
        End Select
    End If
End Sub

' 主鼠标监控  -  释放
Private Sub imgBack_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Dim nCurNode As Integer
    If DoActive Then
        Select Case MouseActive
        Case GetSize
            nsPaint nsRectSize, varRectSize
        Case OpArea
            nsMouseUp PGVar(nCurArea).SOwn, PGVar(nCurArea).AOwn, Button, Shift, X, Y
        Case OpNode
            nCurNode = Areas(nCurArea).nCurNode
            nsMouseUp Areas(nCurArea).SNodes(nCurNode), PGVar(nCurArea).ANodes(nCurNode), Button, Shift, X, Y
        End Select
        MouseActive = NoActive
        DoActive = False
    End If
End Sub

' 调入背景
Private Sub mnuLoadBackground_Click()
    On Error GoTo LBFError
    cdBackFile.ShowOpen
    If cdBackFile.CancelError = False Then
        imgBack.Picture = LoadPicture(cdBackFile.FileName)
        If imgBack.Left + imgBack.Width > lineRight.X1 Then
            frmPadGen.Width = imgBack.Left + imgBack.Width + 800
        Else
            frmPadGen.Width = lineRight.X1
        End If
        If imgBack.Top + imgBack.Height > lineRight.Y1 Then
            frmPadGen.Height = imgBack.Top + imgBack.Height + 800
        Else
            frmPadGen.Height = lineRight.Y1
        End If
    End If
    Exit Sub
LBFError:
    MsgBox "File format error"
    imgBack.Picture = Null
End Sub

' 有效检测
Private Sub numRect_KeyPress(Index As Integer, KeyAscii As Integer): If KeyAscii > Asc("9") Then KeyAscii = 0
End Sub
Private Sub numSize_KeyPress(Index As Integer, KeyAscii As Integer): If KeyAscii > Asc("9") Then KeyAscii = 0
End Sub
Private Sub numRect_Change(Index As Integer)
    Dim Range As Integer
    Range = Areas(nCurArea).nHaveNodes
    If Val(numRect(0)) * Val(numRect(1)) > Range Then
        numRect(Index) = LTrim(Str(Int((Range) / Val(numRect(1 - Index)))))
    End If
End Sub
Private Sub numSize_Change(Index As Integer)
    If bFixSize Then
        nFixWidth = Val(numSize(0))
        nFixHeight = Val(numSize(1))
    End If
End Sub

' 控制变量
Private Sub mnuControlVars_Click(): frmPGVars.Show: End Sub
' 变量选择
Private Sub vscrl_Scroll(): vscrl_Change: End Sub
Private Sub vscrl_Change()
    nCurArea = vscrl.Value
    frmPGVars.vscrl.Value = nCurArea
    txtCurVar = PGVar(nCurArea).GName + PGVar(nCurArea).Name + Str(PGVar(nCurArea).Min) + "," + Str(PGVar(nCurArea).Max)
End Sub
' 拉卷批量栏
Private Sub frameBatch_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Y < 200 Then
        Const frameheight = 1935
        If frameBatch.Tag = "Compressed" Then
            frameBatch.Height = frameheight
            frameBatch.Tag = "Uncompressed"
        Else
            frameBatch.Height = 200
            frameBatch.Tag = "Compressed"
        End If
        imgBack.Top = frameBatch.Top + frameBatch.Height + 100
        lineRight.Y1 = imgBack.Top + imgBack.Height + 500
    End If
End Sub

' 返回
Private Sub mnuReturn_Click(): Me.Hide: End Sub
