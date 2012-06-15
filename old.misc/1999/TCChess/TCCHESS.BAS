Attribute VB_Name = "modTCChess"

Global strGameName As String

Type Point
    X As Integer
    Y As Integer
End Type

' 表示法
    Type NodeExpression
        nArea As Integer
        nNode As Integer
    End Type
    Type ButtonExpression
        nArea As Integer
        nButton As Integer
    End Type

' 棋子
    Global Const MAXBUTTONCLASS = 64                ' 最多兵马种类数
        ' 一般nPower和nMovement全0, nMovement关联TWay.nWaste
        Global Const BCS_KERNEL = 1                 ' 核心子
        Global Const BCS_BOMB = 2                   ' 同归于尽
        Global Const BCS_SPY = 8                    ' 侦探
        Type TButtonClass
            Name As String
            nImportant As Integer                   ' 权数
            nPower As Integer
            nMovement As Integer
            Style As Long
        End Type

        Global ButtonClass(MAXBUTTONCLASS) As TButtonClass  ' 各种棋子

    Global Const MAXBUTTONS = 128                   ' 某区域最多兵马数  + 1
        Type TButton
            bInitialized As Boolean                 ' 游戏开始时已放入棋盘
            Class As Integer                        ' 该棋子所属种类, 关联TButtonClass[]
            ParkNode As NodeExpression              ' 占据领土, 丢弃棋子只需在棋盘上去掉将该棋子
        End Type

' 路线
    Global Const MAXLINKCLASS = 64                  ' 最多通道类型数
        Type TLinkClass
            nWaste As Integer
        End Type

        Global TLinkClass(MAXLINKCLASS) As TLinkClass   ' 各种铁路, 河流等

    Global Const MAXNODELINKS = 16                  ' 结点引出最大路线数
        Type TLink
            nDirection As Integer                   ' 路线方向
            bOwner As Boolean                       ' 路线属主, 遍历用
            bValid As Boolean                       ' 有效连线, 默认TRUE
            DestNode As NodeExpression              ' 连接至结点索引
            lClass As Integer                       ' 路线类别
        End Type

' 结点
    Global Const MAXNODES = 256                     ' 区域内最多领土数
        Global Const NS_DUPLICATABLE = 1            ' 可叠加驻留
        Global Const NS_PROTECT = 2                 ' 保护营地
        Global Const NS_KILL = 4                    ' 死穴
        Global Const NS_FALLINTO = 8                ' 死胡同
        'GLOBAL CONST
        Type TNode
        ' 静态参数
            Style As Long                           ' 结点风格
            nHaveLinks As Integer                   ' 连线数
            Links(MAXNODELINKS) As TLink            ' 连向结点
            Left As Single                          ' 棋纸占位
            Top As Single
            Width As Single
            Height As Single
        ' 动态数据
            bStayButton As Boolean                  ' 表征有效
            StayButton As ButtonExpression          ' 驻留兵马
        End Type

' 静态参数
    Global Const MAXAREAS = 16                  ' 最多区域数        + 1
        Enum SortStyle
            SSFixed = 0
            SSArrangable = 1
            SSRandom = 3
        End Enum

        Type TArea
            Name As String

            nHaveNodes As Integer           ' 拥有领土数
            Nodes(MAXNODES) As TNode        ' 结点描述
            nCurNode As Integer             ' 当前活动领土

            nHaveButtons As Integer         ' 拥有兵马数
            Buttons(MAXBUTTONS) As TButton  ' 兵马数据
            nCurButton As Integer           ' 当前活动兵马

            bPlayable As Boolean
            Sortable As SortStyle
            Color As Long                   ' 棋子颜色 = 0 表示隐含
            Points As Integer               ' 拥有点数
        End Type

    Global nHaveAreas As Integer, Areas(MAXAREAS) As TArea, nCurArea As Integer
    Global nTurningWaste As Integer

' 结点表示法
Function theNode(ne As NodeExpression) As TNode: theNode = Areas(ne.nArea).Nodes(ne.nNode): End Function
Function ANode(theArea As Integer, theNode As Integer) As NodeExpression: ANode.nArea = theArea: ANode.nNode = theNode: End Function
' 棋子表示法
Function theButton(be As ButtonExpression) As TButton: theButton = Areas(be.nArea).Buttons(be.nButton): End Function
Function AButton(theArea As Integer, theButton As Integer) As ButtonExpression: AButton.nArea = theArea: AButton.nButton = theButton: End Function
' 结点表示法等效
Function EqualNExp(ne1 As NodeExpression, ne2 As NodeExpression) As Boolean: EqualNExp = (ne1.nArea = ne2.nArea) And (ne1.nNode = ne2.nNode): End Function
' 棋子表示法等效
Function EqualBExp(be1 As ButtonExpression, be2 As ButtonExpression) As Boolean: EqualBExp = (be1.nArea = be2.nArea) And (be1.nButton = be2.nButton): End Function

' 判断连线是否存在
Function LinkExists(ns As TNode, nDest As NodeExpression) As Boolean
    Dim i As Integer
    For i = 0 To ns.nHaveLinks - 1
        If EqualNExp(ns.Links(i).DestNode, nDest) Then LinkExists = True: Exit Function
    Next
    LinkExists = False
End Function
Function WhereLinkExists(ns As TNode, nDest As NodeExpression) As Integer
    Dim i As Integer
    For i = 0 To ns.nHaveLinks - 1
        If EqualNExp(ns.Links(i).DestNode, nDest) Then WhereLinkExists = i: Exit Function
    Next
    WhereLinkExists = -1
End Function

' 增加连线
Function AddNodeLink(NExpA As NodeExpression, NExpB As NodeExpression, Optional bDoubleSide As Boolean = True, Optional bAIsOwner As Boolean = True) As Boolean
    Dim bLinkB As Boolean
    Dim nA As TNode, nb As TNode
    nA = theNode(NExpA): nb = theNode(NExpB)
    ' 检测有效性
        AddNodeLink = Not (Not LinkExists(nA, NExpB) And nA.nHaveLinks >= MAXNODELINKS)
        bLinkB = Not (Not LinkExists(nb, NExpA) And nb.nHaveLinks >= MAXNODELINKS)
        AddNodeLink = AddNodeLink And bLinkB
        If Not AddNodeLink Then Exit Function
    ' 第一连线
        If Not LinkExists(nA, NExpB) Then
            nA.nHaveLinks = nA.nHaveLinks + 1
            nA.Links(nA.nHaveLinks - 1).bValid = True
            nA.Links(nA.nHaveLinks - 1).bOwner = bAIsOwner
            nA.Links(nA.nHaveLinks - 1).DestNode = NExpB
        End If
    ' 第二连线
        If LinkExists(nb, NExpA) Then
            nb.Links(WhereLinkExists(nb, NExpA)).bOwner = Not bAIsOwner
        Else
            nb.nHaveLinks = nb.nHaveLinks + 1
            nb.Links(nb.nHaveLinks - 1).bValid = bDoubleSide
            nb.Links(nb.nHaveLinks - 1).bOwner = Not bAIsOwner
            nb.Links(nb.nHaveLinks - 1).DestNode = NExpA
        End If
    ' 整理
        Areas(NExpA.nArea).Nodes(NExpA.nNode) = nA
        Areas(NExpB.nArea).Nodes(NExpB.nNode) = nb
End Function

' 删除连线
Function DelNodeLink(NExpA As NodeExpression, NExpB As NodeExpression) As Boolean
    Dim nA As TNode, nb As TNode
    Dim i As Integer
    nA = theNode(NExpA): nb = theNode(NExpB)
    ' 检测有效性
        DelNodeLink = LinkExists(nA, NExpB) And LinkExists(nb, NExpA)
    ' 删除第一连线
        For i = WhereLinkExists(nA, NExpB) + 1 To nA.nHaveLinks - 1
            nA.Links(i - 1) = nA.Links(i)
            nA.nHaveLinks = nA.nHaveLinks - 1
        Next
    ' 删除第二连线
        For i = WhereLinkExists(nb, NExpA) + 1 To nb.nHaveLinks - 1
            nb.Links(i - 1) = nb.Links(i)
            nb.nHaveLinks = nb.nHaveLinks - 1
        Next
    ' 整理
        Areas(NExpA.nArea).Nodes(NExpA.nNode) = nA
        Areas(NExpB.nArea).Nodes(NExpB.nNode) = nb
End Function
