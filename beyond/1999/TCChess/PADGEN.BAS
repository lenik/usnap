Attribute VB_Name = "modPadGen"

Option Explicit
Option Base 0

' 辅助 TNode
Type NodeRect
    Index As Integer                ' nsPaint 所用
    Color As Long                   ' nsPaint 所用
    adjust As Boolean               ' 调节之中
    adjX As Single
    adjY As Single
End Type

' 辅助 TArea
Type TPGVar
    Name As String                  ' 输出变量名
    GName As String                 ' 描述
    nNumberFirst As Integer
    SOwn As TNode                   ' 大矩形
    AOwn As NodeRect                ' 辅助大矩形
    ANodes(MAXNODES) As NodeRect    ' 辅助矩形
End Type

Global PGVar(MAXAREAS) As TPGVar

Enum ToActive
    NoActive = 0
    GenerateNodes = 1
    OpArea = 2
    OpNode = 3
    OpLine = 5
    GetSize = 6
End Enum

Enum AlignType
    atLeftTop = 0
    atTop = 1
    atRightTop = 2
    atLeft = 3
    atMiddle = 4
    atRight = 5
    atLeftBottom = 6
    atBottom = 7
    atRightBottom = 8
End Enum

Global bFixSize As Boolean, nFixWidth As Single, nFixHeight As Single
Global MouseActive As ToActive, DoActive As Boolean

' 定制固定矩形
Global nsRectSize As TNode, varRectSize As NodeRect
' 象征矩形
Global nsFigure As TNode, varFigure As NodeRect, bFigureHide As Boolean
Global nLastArea As Integer, nLastNode As Integer
' 标号排列方式
Global Varrange As Boolean
' 伴随自动生成横直线
Global bAutoHVLines As Boolean
' 鼠标按下微量偏移值
Global oLeft As Single, oTop As Single
' 连线辅助变量
Global bDrawLine As Boolean, lLastP1 As Point, lLastP2 As Point

Global Const LineColor = &HFF00FF

Sub initPGVar()
    Dim i As Integer, j As Integer
    Randomize Timer
    nHaveAreas = 1
    nCurArea = 0
    For i = 0 To MAXAREAS
        PGVar(i).Name = "Var" + LTrim(Str(i))
        PGVar(i).GName = "第" + LTrim(Str(i)) + "方"
        Areas(i).nHaveNodes = 33
        Areas(i).nCurNode = 0
        PGVar(i).nNumberFirst = 0
        PGVar(i).AOwn.adjust = False
        PGVar(i).AOwn.Index = i
        PGVar(i).AOwn.Color = &HFF0000 + i
        For j = 0 To MAXNODES
            PGVar(i).ANodes(j).Index = j
            PGVar(i).ANodes(j).Color = &HFF0000 + Int(Rnd * &H80) * &H100 + Int(Rnd * &H80)
            PGVar(i).ANodes(j).adjust = False
        Next
    Next
End Sub

Sub FigureShow()
    If bFigureHide Then
        frmPadGen.imgBack.Line (nsFigure.Left, nsFigure.Top)-Step(nsFigure.Width, nsFigure.Height), Not varFigure.Color, B
        bFigureHide = False
    End If
End Sub
Sub FigureHide()
    If Not bFigureHide Then
        frmPadGen.imgBack.Line (nsFigure.Left, nsFigure.Top)-Step(nsFigure.Width, nsFigure.Height), Not varFigure.Color, B
        bFigureHide = True
    End If
End Sub

' 作结点连线
Sub lPaint(ns1 As TNode, ns2 As TNode)
    Dim p1 As Point, p2 As Point
    RectBridge ns1, ns2, p1, p2
    picPaint.Line (p1.X, p1.Y)-(p2.X, p2.Y), LineColor
End Sub
' 通过结点表示法作连线
Sub nsPaintNExp(ns As TNode, NExp As NodeExpression)
    lPaint ns, Areas(NExp.nArea).Nodes(NExp.nNode)
End Sub
' 作结点所有引出连线
Sub nsPaintLinks(ns As TNode)
    Dim i As Integer
    For i = 0 To ns.nHaveLinks
        If LinkExists(ns, ns.Links(i).DestNode) Then nsPaintNExp ns, ns.Links(i).DestNode
    Next
End Sub
Function nsAddLink(NExpA As NodeExpression, NExpB As NodeExpression) As Boolean
    nsAddLink = AddNodeLink(NExpA, NExpB)
    If nsAddLink Then nsPaintNExp theNode(NExpA), NExpB
End Function
Function nsDelLink(NExpA As NodeExpression, NExpB As NodeExpression) As Boolean
    nsDelLink = DelNodeLink(NExpA, NExpB)
    If nsDelLink Then nsPaintNExp theNode(NExpA), NExpB
End Function
