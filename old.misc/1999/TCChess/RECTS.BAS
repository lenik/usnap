Attribute VB_Name = "modRects"

Global Const Hmargin = 30
Global Const Vmargin = 30

Global picPaint As PictureBox
Global picText As PictureBox

Sub nsPaint(ns As TNode, var As NodeRect)
    Dim px As Single, py As Single, tw As Single, th As Single
    Dim pstr As String

    picPaint.Line (ns.Left, ns.Top)-Step(ns.Width, ns.Height), Not var.Color, B
        pstr = LTrim(Str(var.Index + 1))
        'pstr = LTrim(Str(var.Index + 1)) + "(" + Str(ns.Left) + "," + Str(ns.Top) + ")[" + Str(ns.Width) + "," + Str(ns.Height) + "]"
        px = picText.ScaleX(IIf(ns.Width < 0, ns.Left + ns.Width, ns.Left), vbTwips, vbPixels)
        py = picText.ScaleY(IIf(ns.Height < 0, ns.Top + ns.Height, ns.Top), vbTwips, vbPixels)
        tw = picText.ScaleX(picText.TextWidth(pstr), vbTwips, vbPixels)
        th = picText.ScaleY(picText.TextHeight(pstr), vbTwips, vbPixels)
        BitBlt picText.hdc, 0, 0, tw, th, 0, 0, 0, BLACKNESS
        picText.ForeColor = Not var.Color And &HFFFFFF
        TextOut picText.hdc, 0, 0, pstr, Len(pstr)
    BitBlt picPaint.hdc, px + 1, py + 1, tw, th, picText.hdc, 0, 0, SRCINVERT
    nsPaintLinks ns
End Sub
Sub nsColor(ns As TNode, var As NodeRect, nColor As Long)
    nsPaint ns, var
    var.Color = nColor
    nsPaint ns, var
End Sub
Sub nsMove(ns As TNode, var As NodeRect, nLeft As Single, nTop As Single)
    nsPaint ns, var
    ns.Left = nLeft: ns.Top = nTop
    nsPaint ns, var
End Sub
Sub nsSize(ns As TNode, var As NodeRect, nWidth As Single, nHeight As Single)
    nsPaint ns, var
    ns.Width = nWidth: ns.Height = nHeight
    nsPaint ns, var
End Sub
Function nsInside(ns As TNode, var As NodeRect, X As Single, Y As Single) As Long
    Dim halfw As Single, halfh As Single
    halfw = ns.Width / 2: halfh = ns.Height / 2
    If ns.Width < 0 Then
        nsPaint ns, var
        ns.Left = ns.Left + ns.Width
        ns.Width = -ns.Width
        nsPaint ns, var
    End If
    If ns.Height < 0 Then
        nsPaint ns, var
        ns.Top = ns.Top + ns.Height
        ns.Height = -ns.Height
        nsPaint ns, var
    End If
    If ns.Left < X And X < ns.Left + ns.Width And ns.Top < Y And Y < ns.Top + ns.Width Then
        nsInside = (halfw - Abs(ns.Left + halfw - X)) * (halfh - Abs(ns.Top + halfh - Y))
    Else
        nsInside = 0
    End If
End Function

Sub nsPaintMargin(ns As TNode, var As NodeRect, bWithNum As Boolean)
    Dim SW As Integer, SH As Integer
    SW = Sgn(ns.Width): If SW = 0 Then SW = 1
    SH = Sgn(ns.Height): If SH = 0 Then SH = 1
    ns.Left = ns.Left - SW * Hmargin
    ns.Width = ns.Width + 2 * SW * Hmargin
    ns.Top = ns.Top - SH * Vmargin
    ns.Height = ns.Height + 2 * SH * Vmargin
    If bWithNum Then
        nsPaint ns, PGVar(nIndex).AOwn
    Else
        picPaint.Line (ns.Left, ns.Top)-Step(ns.Width, ns.Height), Not var.Color, B
    End If
    ns.Left = ns.Left + SW * Hmargin
    ns.Width = ns.Width - 2 * SW * Hmargin
    ns.Top = ns.Top + SH * Vmargin
    ns.Height = ns.Height - 2 * SH * Vmargin
End Sub
Sub PaintOwn(nIndex As Integer)
    nsPaintMargin PGVar(nIndex).SOwn, PGVar(nIndex).AOwn, True
End Sub
Sub OwnMouseDown(nIndex As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
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
Sub OwnMouseMove(nIndex As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
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

Sub RectBridge(ns1 As TNode, ns2 As TNode, rp1 As Point, rp2 As Point)
    Dim cp1 As Point, cp2 As Point                  ' 两矩形矩心
    Dim hw1 As Integer, hh1 As Integer, hw2 As Integer, hh2 As Integer
                                                    ' 半宽高
    Dim dx As Integer, dy As Integer                ' 两矩心距离
    Dim k1 As Single, k2 As Single, k As Single
    Dim p1 As Point, p2 As Point                    ' 生成桥端点
    hw1 = ns1.Width / 2: hh1 = ns1.Height / 2
    hw2 = ns2.Width / 2: hh2 = ns2.Height / 2
    cp1.X = ns1.Left + hw1: cp1.Y = ns1.Top + hh1
    cp2.X = ns2.Left + hw2: cp2.Y = ns2.Top + hh2
    dx = cp2.X - cp1.X: dy = cp2.Y - cp1.Y
    If hw1 = 0 Or hw2 = 0 Then Exit Sub
    k1 = hh1 / hw1: k2 = hh2 / hw2

    If dx = 0 Then  ' 垂直
        p1.Y = cp1.Y + Sgn(dy) * hh1
        p1.X = cp1.X
        p2.Y = cp2.Y - Sgn(dy) * hh2
        p2.X = cp2.X
    Else
        k = dy / dx
    ' 计算ns1出离点
        If Abs(k) < k1 Then    ' 纵边出离
            p1.X = cp1.X + Sgn(dx) * hw1
            p1.Y = IIf(dx = 0, cp1.Y, cp1.Y + dy / Abs(dx) * hw1)
        Else
            p1.Y = cp1.Y + Sgn(dy) * hh1
            p1.X = cp1.X + dx / Abs(dy) * hh1
        End If
    ' 计算ns2出离点
        If Abs(k) < k2 Then    ' 纵边出离
            p2.X = cp2.X - Sgn(dx) * hw2
            p2.Y = cp2.Y - dy / Abs(dx) * hw2
        Else
            p2.Y = cp2.Y - Sgn(dy) * hh2
            p2.X = cp2.X - dx / Abs(dy) * hh2
        End If
    End If
    rp1.X = p1.X: rp1.Y = p1.Y
    rp2.X = p2.X: rp2.Y = p2.Y
End Sub

Sub ArrangeRects(ParentRect As TNode, PHNum As Integer, PVNum As Integer, ChildrenRects As TArea, VIndex As Boolean)
    Dim i As Integer, j As Integer
    Dim nUnitWidth As Single            ' 单位宽度 = 固定宽度 + 空隙宽度
    Dim nUnitHeight As Single           ' 单位高度 = 固定高度 + 空隙高度

    If bFixSize Then
        nUnitWidth = Sgn(ParentRect.Width) * ((Abs(ParentRect.Width) + (Abs(ParentRect.Width) - PHNum * nFixWidth) / (PHNum - 1)) / PHNum)
        nUnitHeight = Sgn(ParentRect.Height) * ((Abs(ParentRect.Height) + (Abs(ParentRect.Height) - PVNum * nFixHeight) / (PVNum - 1)) / PVNum)
    Else
        nUnitWidth = ParentRect.Width / PHNum
        nUnitHeight = ParentRect.Height / PVNum
    End If

    If VIndex Then  ' 垂直排列
        For i = 0 To PHNum - 1
            For j = 0 To PVNum - 1
                With ChildrenRects.Nodes(i * PVNum + j)
                    .Width = IIf(bFixSize, nFixWidth, Abs(nUnitWidth))
                    .Height = IIf(bFixSize, nFixHeight, Abs(nUnitHeight))
                    .Left = ParentRect.Left + nUnitWidth * i       ' nUnitWidth 方向敏感
                    .Top = ParentRect.Top + nUnitHeight * j       ' nUnitHeight 方向敏感
                    If Sgn(ParentRect.Width) < 0 Then .Left = .Left - .Width
                    If Sgn(ParentRect.Height) < 0 Then .Top = .Top - .Height
                End With
            Next
        Next
    Else ' 水平排列
        For i = 0 To PVNum - 1
            For j = 0 To PHNum - 1
                With ChildrenRects.Nodes(i * PHNum + j)
                    .Width = IIf(bFixSize, nFixWidth, Abs(nUnitWidth))
                    .Height = IIf(bFixSize, nFixHeight, Abs(nUnitHeight))
                    .Left = ParentRect.Left + nUnitWidth * j     ' nUnitWidth 方向敏感
                    .Top = ParentRect.Top + nUnitHeight * i       ' nUnitHeight 方向敏感
                    If Sgn(ParentRect.Width) < 0 Then .Left = .Left - .Width
                    If Sgn(ParentRect.Height) < 0 Then .Top = .Top - .Height
                End With
            Next
        Next
    End If
End Sub

' 返回是否落在矩形上, 无落点矩形值为-1
Function GetRectOn(X As Single, Y As Single, nArea As Integer, nNode As Integer) As Boolean
    Dim i As Integer, j As Integer
    Dim S As Single, MaxS As Single, MaxSI As Integer, MaxSJ As Integer
    ' 准击大矩形 (准击域)
    MaxS = 0
    For i = 0 To nHaveAreas - 1
        S = nsInside(PGVar(i).SOwn, PGVar(i).AOwn, X, Y)
        If MaxS < S Then MaxS = S: MaxSI = i
    Next
    If MaxS > 0 Then
        nArea = MaxSI
        GetRectOn = True
        ' 任何域内准击小矩形 (域外无效, 提高速度用)
            MaxS = 0
            For j = 0 To Areas(MaxSI).nHaveNodes - 1
                S = nsInside(Areas(MaxSI).Nodes(j), PGVar(MaxSI).ANodes(j), X, Y)
                If MaxS < S Then MaxS = S: MaxSJ = j
            Next
            If MaxS > 0 Then nNode = MaxSJ Else nNode = -1
    Else
        ' 当前域外当前域所属准击小矩形
        ' For i = nCurArea To nCurArea
            For j = 0 To Areas(nCurArea).nHaveNodes - 1
                S = nsInside(Areas(nCurArea).Nodes(j), PGVar(nCurArea).ANodes(j), X, Y)
                If MaxS < S Then MaxS = S: MaxSJ = j
            Next
        ' Next
        If MaxS > 0 Then
            nArea = nCurArea
            nNode = MaxSJ
            GetRectOn = True
        Else
            ' 所有域外准击小矩形
            For i = 0 To nCurArea - 1
                For j = 0 To Areas(i).nHaveNodes - 1
                    S = nsInside(Areas(i).Nodes(j), PGVar(i).ANodes(j), X, Y)
                    If MaxS < S Then MaxS = S: MaxSI = i: MaxSJ = j
                Next
            Next
            For i = nCurArea + 1 To nHaveAreas - 1
                For j = 0 To Areas(i).nHaveNodes - 1
                    S = nsInside(Areas(i).Nodes(j), PGVar(i).ANodes(j), X, Y)
                    If MaxS < S Then MaxS = S: MaxSI = i: MaxSJ = j
                Next
            Next
            If MaxS > 0 Then
                nArea = MaxSI
                nNode = MaxSJ
                GetRectOn = True
            Else
                nArea = -1
                nNode = -1
                GetRectOn = False
            End If  ' 判断除当前域外所有域内外存在准击小矩形
        End If  ' 判断当前域内外存在准击小矩形
    End If  ' 判断存在准击域
End Function
