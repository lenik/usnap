VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmPadGen
   Caption         =   "桃壳棋风 棋盘生成"
   ClientHeight    =   5265
   ClientLeft      =   1725
   ClientTop       =   2805
   ClientWidth     =   8625
   LinkTopic       =   "Form1"
   ScaleHeight     =   5265
   ScaleWidth      =   8625
   Begin VB.Frame frameBatch
      Caption         =   "批量自动生成"
      ForeColor       =   &H00C00000&
      Height          =   1935
      Left            =   120
      TabIndex        =   2
      Top             =   60
      Width           =   8445
      Begin VB.TextBox txtInfo
         Appearance      =   0  'Flat
         BackColor       =   &H00D0FFFF&
         BorderStyle     =   0  'None
         ForeColor       =   &H00800000&
         Height          =   1665
         Left            =   3915
         Locked          =   -1  'True
         MultiLine       =   -1  'True
         TabIndex        =   37
         Top             =   195
         Width           =   1815
      End
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
         Left            =   5790
         TabIndex        =   32
         Top             =   1440
         Width           =   2565
      End
      Begin VB.HScrollBar vscrl
         Height          =   240
         Left            =   6630
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
         Left            =   5790
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
      Begin VB.Label lblPos
         AutoSize        =   -1  'True
         Caption         =   "<12> 120,219: 2314x330"
         ForeColor       =   &H00404000&
         Height          =   180
         Left            =   1020
         TabIndex        =   36
         Top             =   1170
         Width           =   1980
      End
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "选择变量"
         ForeColor       =   &H00404000&
         Height          =   180
         Left            =   5790
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
         DrawMode        =   7  'Invert
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
      X1              =   8400
      X2              =   8790
      Y1              =   4980
      Y2              =   5460
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
   Begin VB.Menu mnuTest
      Caption         =   "&T测试"
   End
End
Attribute VB_Name = "frmPadGen"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Option Base 0

' 线性矩形操作
    Private Sub nsMouseDown(ns As TNode, var As NodeRect, Button As Integer, Shift As Integer, X As Single, Y As Single)
        var.adjust = True
        If Button = vbLeftButton Then            ' Moving
            var.adjX = X - ns.Left: var.adjY = Y - ns.Top
        ElseIf Button = vbRightButton Then       ' Sizing
            nsMove ns, var, X, Y
        End If
    End Sub
    Private Sub nsMouseMove(ns As TNode, var As NodeRect, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If var.adjust Then
            If Button = vbLeftButton Then        ' Moving
                nsMove ns, var, X - var.adjX, Y - var.adjY
            ElseIf Button = vbRightButton Then   ' Sizing
                nsSize ns, var, X - ns.Left, Y - ns.Top
            End If
        End If
    End Sub
    Private Sub nsMouseUp(ns As TNode, var As NodeRect, Button As Integer, Shift As Integer, X As Single, Y As Single)
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

Private Sub initVars()
    ln = Chr(13)
    ctab = Chr(9)
    Varrange = False
    bFixSize = False
    bFigureHide = True
    varFigure.Color = &HC0C000
    varFigure.adjust = False
    initPGVar       ' 主盘数据初始化
End Sub
Private Sub Form_Load()
    Set picPaint = imgBack
    Set picText = imgText
    initVars
    imgBack.DrawMode = vbXorPen
    imgText.DrawMode = vbXorPen
End Sub

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
        Dim nArea As Integer, nNode As Integer
        If GetRectOn(X, Y, nArea, nNode) Then
            nCurArea = nArea
            If nNode = -1 Then
                MouseActive = OpArea
                OwnMouseDown nArea, Button, Shift, X, Y
                DoActive = True
            Else
                Areas(nArea).nCurNode = nNode
                nsMouseDown Areas(nArea).Nodes(nNode), PGVar(nArea).ANodes(nNode), Button, Shift, X, Y
                MouseActive = IIf(Shift And vbCtrlMask, OpLine, OpNode)
                DoActive = True
            End If
        End If
    End Select
End Sub

' 主鼠标监控  -  移动
Private Sub imgBack_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Dim varWidth As Single, varHeight As Single
    varWidth = X - oLeft: varHeight = Y - oTop
    Dim nCurNode As Integer, nSelNode As Integer
    Dim nsParentRect As TNode
    If DoActive Then
        lblPos = LTrim(Str(oTop))
        Select Case MouseActive
        Case GenerateNodes
            Dim i As Integer
            PaintOwn nCurArea
            PGVar(nCurArea).SOwn.Width = varWidth       ' 参考父矩形的高宽是有方向的
            PGVar(nCurArea).SOwn.Height = varHeight
            For i = 0 To Val(numRect(0)) * Val(numRect(1)) - 1
                    nsPaint Areas(nCurArea).Nodes(i), PGVar(nCurArea).ANodes(i)
            Next
            ArrangeRects PGVar(nCurArea).SOwn, Val(numRect(0)), Val(numRect(1)), Areas(nCurArea), Varrange
            For i = 0 To Val(numRect(0)) * Val(numRect(1)) - 1
                    nsPaint Areas(nCurArea).Nodes(i), PGVar(nCurArea).ANodes(i)
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
            nsMouseMove Areas(nCurArea).Nodes(nCurNode), PGVar(nCurArea).ANodes(nCurNode), Button, Shift, X, Y
        Case OpLine
            Dim nAnotherArea As Integer, nAnotherNode As Integer
            nCurNode = Areas(nCurArea).nCurNode
            If GetRectOn(X, Y, nAnotherArea, nAnotherNode) And nAnotherNode >= 0 Then
                Dim p1 As Point, p2 As Point
                RectBridge Areas(nCurArea).Nodes(nCurNode), Areas(nAnotherArea).Nodes(nAnotherNode), p1, p2
                If bDrawLine Then picPaint.Line (lLastP1.X, lLastP1.Y)-(lLastP2.X, lLastP2.Y), LineColor
                picPaint.Line (p1.X, p1.Y)-(p2.X, p2.Y), LineColor
                bDrawLine = True
                lLastP1.X = p1.X: lLastP1.Y = p1.Y
                lLastP2.X = p2.X: lLastP2.Y = p2.Y
            Else
                If bDrawLine Then
                    picPaint.Line (lLastP1.X, lLastP1.Y)-(lLastP2.X, lLastP2.Y), LineColor
                    bDrawLine = False
                End If
            End If
        End Select
    Else
        lblPos = "位置: " + LTrim(Str(X)) + "," + LTrim(Str(Y))
    End If

    ' 智能激活显示
    If Not DoActive Or DoActive And MouseActive = OpLine Then
        Dim nArea As Integer, nNode As Integer
        If GetRectOn(X, Y, nArea, nNode) Then
            FigureHide
            If nNode = -1 Then
                Dim SW As Integer, SH As Integer
                SW = Sgn(nsFigure.Width): If SW = 0 Then SW = 1
                SH = Sgn(nsFigure.Height): If SH = 0 Then SH = 1
                nsFigure.Left = PGVar(nArea).SOwn.Left - SW * Hmargin
                nsFigure.Top = PGVar(nArea).SOwn.Top - SH * Vmargin
                nsFigure.Width = PGVar(nArea).SOwn.Width + 2 * SW * Hmargin
                nsFigure.Height = PGVar(nArea).SOwn.Height + 2 * SH * Vmargin
            Else
                With Areas(nArea).Nodes(nNode)
                    nsFigure.Left = .Left
                    nsFigure.Top = .Top
                    nsFigure.Width = .Width
                    nsFigure.Height = .Height
                End With
            End If
            FigureShow
        Else
            FigureHide
        End If
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
            nsMouseUp Areas(nCurArea).Nodes(nCurNode), PGVar(nCurArea).ANodes(nCurNode), Button, Shift, X, Y
        Case OpLine
            Dim nAnotherArea As Integer, nAnotherNode As Integer
            nCurNode = Areas(nCurArea).nCurNode
            If bDrawLine Then
                picPaint.Line (lLastP1.X, lLastP1.Y)-(lLastP2.X, lLastP2.Y), LineColor
                bDrawLine = False
            End If
            If GetRectOn(X, Y, nAnotherArea, nAnotherNode) And nAnotherNode >= 0 Then
                If LinkExists(Areas(nCurArea).Nodes(nCurNode), ANode(nAnotherArea, nAnotherNode)) Then
                    nsDelLink ANode(nCurArea, nCurNode), ANode(nAnotherArea, nAnotherNode)
                Else
                    nsAddLink ANode(nCurArea, nCurNode), ANode(nAnotherArea, nAnotherNode)
                End If
            End If
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

Private Sub mnuTest_Click()
    frmTest.Show 1
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
    txtCurVar = PGVar(nCurArea).GName + PGVar(nCurArea).Name + Str(PGVar(nCurArea).nNumberFirst) + "," + Str(PGVar(nCurArea).nNumberFirst + Areas(nCurArea).nHaveNodes - 1)
    numRect_Change 1
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
