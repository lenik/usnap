VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 1  'vbSimpleBound
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "EasyText"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

' 控制变量
        Private drawDCpic As PictureBox
        Private drawDC As Long, sceneDC As Long, SceneBakDC As Long
        ' OnShow表示实际上是否在现
        Private OnShow As Boolean

' A:接口内部变量
        ' IsVisible表示是否要求可视
        Private IsVisible As Boolean
        ' 绘制位置
        Private px As Single, py As Single
        ' 光标位置
        Private Crow As Integer, Ccol As Integer
        Public ShowCaret As Boolean

' B:特效文字数组
        Private Const MaxCount = 4
        Private text(0 To MaxCount - 1) As New EasyChar
        Private ItemNum As Long
        Private ItemMax As Long
        Private LineMax As Integer

        Public Function TTT(ByVal Index As Integer): Set TTT = text(Index): End Function
' Control Group
        Public Property Get drawPic() As PictureBox: Set drawPic = drawDCpic: End Property
        Public Property Let drawPic(newPic As PictureBox)
                Set drawDCpic = newPic
                drawDC = IIf(drawDCpic Is Nothing, 0, drawDCpic.hdc)
        End Property
        Public Property Get hSceneDC() As Long: hSceneDC = sceneDC: End Property
        Public Property Let hSceneDC(ByVal newDC As Long)
                Hide
                sceneDC = newDC
                Show
        End Property
        Public Property Get hSceneBakDC() As Long: hSceneBakDC = SceneBakDC: End Property
        Public Property Let hSceneBakDC(ByVal newDC As Long)
                SceneBakDC = newDC
        End Property

' Group A
        Public Property Get Visible() As Boolean
                Visible = IsVisible
        End Property
        Public Property Let Visible(ByVal newVisible As Boolean)
                Dim shouldRefresh As Boolean
                shouldRefresh = IsVisible <> newVisible
                IsVisible = newVisible
                If shouldRefresh Then Refresh
        End Property
        Public Property Get X() As Single: X = px: End Property
        Public Property Let X(ByVal newx As Single)
                If px <> newx Then
                        Hide
                        px = newx
                        RecalcPos
                        Show
                End If
        End Property
        Public Property Get Y() As Single: Y = py: End Property
        Public Property Let Y(ByVal newy As Single)
                If py <> newy Then
                        Hide
                        py = newy
                        RecalcPos
                        Show
                End If
        End Property

        Public Property Get Row() As Integer: Row = Crow: End Property
        Public Property Let Row(ByVal newRow As Integer)
                If newRow < 0 Then newRow = 0
                If newRow > MaxRow Then newRow = MaxRow
                Crow = newRow
        End Property
        Public Property Get Col() As Integer: Col = Ccol: End Property
        Public Property Let Col(ByVal newCol As Integer)
                If newCol < 0 Then newCol = 0
                If newCol > MaxCol(Row) Then newCol = MaxCol(Row)
                Ccol = newCol
        End Property

' Group B
        Public Property Get Count() As Integer
                Count = ItemNum
        End Property
        Public Property Let MaxItems(ByVal newMax As Long)
                ItemMax = newMax
                If ItemNum > ItemMax Then SetSize ItemMax
        End Property
        Public Property Get TextL() As String
                Dim i As Integer
                TextL = ""
                For i = 0 To Count
                        TextL = TextL & text(i).Content & vbNewLine
                Next
        End Property
        Public Property Get TextNL() As String
                Dim i As Integer
                TextNL = ""
                For i = 0 To Count - 1
                        TextNL = TextNL & text(i).Content
                Next
        End Property
        Public Function GetChar(ByVal Index As Integer) As EasyChar: Set GetChar = IIf(Index < ItemNum, text(Index), Nothing): End Function
        Public Function SetChar(ByVal Index As Integer, NewChar As EasyChar, recalc As Boolean) As Boolean
                SetChar = False
                If Index > ItemNum Then
                        If Not SetSize(Index + 1) Then Exit Function
                End If
                copyEChar text(Index), NewChar
                text(Index).SetOwnerText Me, Index
                If recalc Then RecalcPos Index
                SetChar = True
        End Function

        Public Function AppendChar(NewChar As EasyChar, Optional ByVal recalc As Boolean = True) As Boolean
                If Not SetSize(ItemNum + 1) Then Exit Function
                SetChar ItemNum - 1, NewChar, recalc
                AppendChar = True
        End Function
        Public Function InsertChar(ByVal insertindex As Integer, NewChar As EasyChar, Optional ByVal recalc As Boolean = True) As Boolean
                Dim i As Long
                InsertChar = True
                If insertindex >= ItemNum Then
                        InsertChar = SetSize(insertindex + 1)
                        If Not InsertChar Then Exit Function
                Else
                        InsertChar = SetSize(ItemNum + 1)
                        If InsertChar Then
                                For i = ItemNum - 1 To insertindex + 1 Step -1
                                        InsertChar = InsertChar And MoveChar(i - 1, i)
                                Next
                        Else
                                Exit Function
                        End If
                End If
                InsertChar = InsertChar And SetChar(insertindex, NewChar, recalc)
        End Function
        Public Function DeleteChar(ByVal deleteindex As Integer) As Boolean
                Dim i As Long
                DeleteChar = False
                If deleteindex < 0 Or deleteindex >= ItemNum Then Exit Function

                text(deleteindex).Destroy
                ' 对象内存处理
                        Set text(deleteindex) = New EasyChar
                        For i = deleteindex + 1 To ItemNum - 1
                                MoveChar i, i - 1
                        Next
                        ItemNum = ItemNum - 1
                If deleteindex < ItemNum Then Changed deleteindex
                DeleteChar = True
        End Function
        Public Function DeleteAll() As Boolean
                Dim HasError As Boolean
                Dim i As Long
                HasError = True
                For i = ItemNum - 1 To 0 Step -1
                        HasError = HasError And DeleteChar(i)
                Next
                DeleteAll = HasError
        End Function

' 自动行处理
        Public Function AL_InsertBreak(Optional ByVal Refresh As Boolean = True) As Boolean
                AL_InsertBreak = True
                If Not InsertChar(Crow + 1, text(Crow), False) Then
                        If MaxRow < ItemNum - 1 Then
                                DeleteChar ItemNum - 1
                                AL_InsertBreak = InsertChar(Crow + 1, text(Crow), False)
                        Else
                                AL_InsertBreak = False
                        End If
                End If
                If AL_InsertBreak Then
                        text(Crow).Content = Left(text(Crow).Content, Ccol)
                        text(Crow).Break = True
                        text(Crow + 1).Content = Mid(text(Crow + 1).Content, Ccol + 1)
                        text(Crow + 1).m_AuxOnDraw = False
                        RecalcPos Crow + 1, True
                        Crow = Crow + 1
                        Ccol = 0
                        If Refresh Then AL_InsertBreak = AL_InsertBreak And AL_Refresh(-1, Crow)
                End If
        End Function
        Public Function AL_RemoveBreak(ByVal Index As Long, Optional ByVal Refresh As Boolean = True) As Boolean
                AL_RemoveBreak = True
                If Index < ItemNum - 1 Then
                        text(Index).Content = text(Index).Content & text(Index + 1).Content
                        AL_RemoveBreak = DeleteChar(Index + 1)
                End If
                If Refresh Then AL_RemoveBreak = AL_Refresh(-1, Index)
        End Function
        Public Function AL_InsertContent(ByVal Index As Integer, ByVal offset As Integer, ByVal Content As String, Optional ByVal Refresh As Boolean = True) As Boolean
                With text(Index)
                        .Content = Left(.Content, offset) & Content & Mid(.Content, offset + 1)
                End With
                AL_InsertContent = True
                If Refresh Then AL_InsertContent = AL_Refresh(-1, Index, True)
        End Function
        Public Function AL_AppendContent(ByVal Content As String, Optional ByVal Refresh As Boolean = True) As Boolean
                AL_AppendContent = AL_InsertContent(ItemNum - 1, text(ItemNum - 1).mlen, Refresh)
        End Function
        Public Function AL_DeleteContent(ByVal Index As Integer, ByVal offset As Integer, Optional ByVal nContent As Integer = 1, Optional ByVal Refresh As Boolean = True) As Boolean
                Dim nContentLeft As Integer
                Dim r As Boolean
                r = True
                nContentLeft = nContent
                Do While nContentLeft > 0
                        With text(Index)
                                If nContentLeft > .mlen - offset And ItemNum > 1 Then
                                        .Content = Left(.Content, offset)
                                        nContentLeft = nContentLeft - (.mlen - offset)
                                        ' 如果有下一行, 把下一行的文本连接到本行, 删除下行
                                        If Index + 1 < ItemNum Then
                                                .Content = .Content & text(Index + 1).Content
                                                .Break = text(Index + 1).Break
                                                r = r And DeleteChar(Index + 1)
                                        Else
                                                nContentLeft = 0
                                        End If
                                Else
                                        .Content = Left(.Content, offset) & Mid(.Content, offset + nContentLeft + 1)
                                        nContentLeft = 0
                                End If
                        End With
                Loop
                If Refresh Then AL_DeleteContent = AL_DeleteContent And AL_Refresh(-1, Index)
        End Function
        Public Function AL_DeleteLeft() As Boolean
                If Ccol <= 0 Then
                        If Crow > 0 Then
                                AL_DeleteLeft = AL_RemoveBreak(Crow - 1, True)
                                If AL_DeleteLeft Then
                                        Crow = Crow - 1
                                        Ccol = MaxCol(Crow)
                                End If
                        Else
                                Ccol = 0
                        End If
                Else
                        AL_DeleteLeft = AL_DeleteContent(Crow, Ccol - 1)
                        Ccol = Ccol - 1
                End If
        End Function
        Public Function AL_DeleteRight() As Boolean
                If Ccol >= MaxCol(Crow) Then
                        If Crow < ItemNum - 1 Then AL_DeleteRight = AL_RemoveBreak(Crow)
                Else
                        AL_DeleteRight = AL_DeleteContent(Crow, Ccol)
                End If
        End Function
        Public Function AL_AllocContent(ByVal Content As String, ByVal maxRows As Integer, Optional template_ec As EasyChar = Nothing, Optional LeftContent As String) As Boolean
                Dim ec As EasyChar
                If template_ec Is Nothing Then Set template_ec = template_FingerChar
                Set ec = New EasyChar
                copyEChar ec, template_ec

                AL_AllocContent = DeleteAll
                ec.Content = Content
                AL_AllocContent = AL_AllocContent And AppendChar(ec)
                AL_AllocContent = AL_AllocContent And AL_Refresh(maxRows, 0, True, LeftContent)
        End Function

        Public Function AL_Refresh(ByVal maxRows As Integer, Optional ByVal fromindex As Long = 0, Optional ByVal breakChar As Boolean = False, Optional LeftContent As String) As Boolean
                Static callTime As Long
                Dim ec As EasyChar
                Dim P As Integer        ' 当前列举字符位置
                Dim nIgnore As Integer  ' 表示从p开始忽略的字符数
                Dim c As String         ' 当前获取字符
                Dim la As Integer       ' ANSI长度, 用于分割行
                Dim lm As Integer       ' MBCS长度, 用于列举字符
                Dim w As Integer        ' 当前行宽度, 用于分割行
                Dim cw As Integer       ' 当前字符宽度, 用于分割行
                Dim shouldBreak As Boolean
                Dim shouldRefresh As Boolean
                Dim InsertTo As Long
                Dim r As Boolean

                If maxRows = -1 Then maxRows = MaxCount
                Set ec = text(fromindex)
                P = 1: w = 0
                la = ec.alen: lm = ec.mlen
                InsertTo = fromindex + 1
                r = True
                shouldBreak = False

                Do While ItemNum <= maxRows And Not ec Is Nothing
                        If P > lm Then Exit Do
                        c = Mid(ec.Content, P, 1)

                        cw = getStringLengthA(c)
                        If w + cw > LineMax Then shouldBreak = True: nIgnore = 0
                        If breakChar Then
                                If Asc(c) = 13 Then shouldBreak = True: nIgnore = 2
                        End If
                        If shouldBreak Then
                                ' 把本行剩余字符(从p开始)搬到下一行(忽略nIgnore个字符)
                                Dim LeftChars As String
                                LeftChars = Mid(ec.Content, P + nIgnore)
                                ec.Content = Left(ec.Content, P - 1)
                                ec.Break = True

                                If InsertTo < ItemNum Then
                                        Set ec = text(InsertTo)
                                ElseIf ItemNum < maxRows And InsertTo <= ItemNum Then
                                        AppendChar ec
                                        Set ec = text(InsertTo)
                                        ec.Content = ""
                                Else
                                        Set ec = Nothing
                                End If

                                If Not ec Is Nothing Then
                                        ec.Content = LeftChars & ec.Content
                                        la = ec.alen: lm = ec.mlen
                                        InsertTo = InsertTo + 1
                                        P = 0
                                        w = 0
                                        cw = 0
                                        shouldBreak = False
                                        shouldRefresh = True
                                Else
                                        LeftContent = LeftChars
                                End If
                        End If
                        P = P + 1
                        w = w + cw
                Loop
                If shouldRefresh Then r = r And RecalcPos(fromindex)
                AL_Refresh = r
                If Not ec Is Nothing Then LeftContent = Mid(ec.Content, P)
l2:
                callTime = callTime + 1
                'frmMain.lblPaintCall = callTime
        End Function

' 高级接口
        Public Function Refresh() As Boolean
                Dim i As Integer
                If Visible Then
                        For i = 0 To ItemNum - 1
                                text(i).redraw
                        Next
                        OnShow = True
                        SetCaret
                End If
        End Function
        ' 成员发生改变
        Public Function Changed(ByVal CID As Long) As Boolean
                Dim i As Long
                RecalcPos CID, True
        End Function

' 位置处理
        Public Function MaxRow() As Integer
                MaxRow = ItemNum - 1
        End Function
        Public Function MaxCol(ByVal nRow As Integer) As Integer
                MaxCol = text(nRow).mlen
        End Function
        ' 获得里指定纵坐标最接近的行
        Public Function GetNearestRow(ByVal posY As Single) As Integer
                Dim Ri As Integer
                GetNearestRow = -1
                For Ri = 0 To MaxRow
                        With text(Ri)
                                If posY >= .m_AuxY And posY < .m_AuxY + .height Then
                                        GetNearestRow = Ri
                                        Exit For
                                End If
                        End With
                Next
                If GetNearestRow < 0 Then
                        If posY < Y Then GetNearestRow = 0 Else GetNearestRow = MaxRow
                End If
        End Function
        Public Function GetNearestCol(ByVal nRow As Integer, ByVal posX As Single) As Integer
                GetNearestCol = text(nRow).WidthN(posX - X)
        End Function
        ' 根据行列值设置光标
        Public Function SetCaret() As Boolean
                If ShowCaret Then
                        With text(Row)
                                SetCaret = SetCaretPos(.m_AuxX + .nWidth(Col), .m_AuxY)
                        End With
                End If
        End Function
        ' 根据光标设置行列值
        Public Function SetRowCol(ByVal caretX As Single, ByVal caretY As Single) As Boolean
                Row = GetNearestRow(caretY)
                Col = GetNearestCol(Row, caretX)
                SetCaret
        End Function

        Public Function moveLeft() As Boolean
                moveLeft = True
                If Ccol > 0 Then
                        Ccol = Ccol - 1
                Else
                        If Crow > 0 Then
                                Crow = Crow - 1
                                Ccol = MaxCol(Crow)
                        Else
                                moveLeft = False
                        End If
                End If
        End Function
        Public Function moveRight() As Boolean
                moveRight = True
                If Ccol < MaxCol(Crow) Then
                        Ccol = Ccol + 1
                Else
                        If Crow < MaxRow Then
                                Crow = Crow + 1
                                If MaxCol(Crow - 1) > 1 Then
                                        Ccol = Ccol Mod (MaxCol(Crow - 1) - 1)
                                Else
                                        Ccol = 0
                                End If
                        Else
                                moveRight = False
                        End If
                End If
        End Function
        Public Function moveUp() As Boolean
                moveUp = True
                If Crow > 0 Then
                        Crow = Crow - 1
                        If Ccol > MaxCol(Crow) Then
                                Ccol = MaxCol(Crow)
                        End If
                Else
                        moveUp = False
                End If
        End Function
        Public Function moveDown() As Boolean
                moveDown = True
                If Crow < MaxRow Then
                        Crow = Crow + 1
                        If Ccol > MaxCol(Crow) Then
                                Ccol = MaxCol(Crow)
                        End If
                Else
                        moveDown = False
                End If
        End Function

' /////////////////////////////////////////////////////////////////////////////////
' 特效文字类底层实现
' A
        Private Sub Class_Initialize()
                OnShow = False
                Visible = False
                ShowCaret = False

                px = 10: py = 10
                Crow = 0: Ccol = 0

                ItemNum = 0
                LineMax = FC_LINEMAX
                ItemMax = MaxCount

                Set drawDCpic = frmMain.picText
                drawDC = drawDCpic.hdc
                If debugClass Then MsgBox "EasyText: Class_Init"
        End Sub
        Private Sub Class_Terminate()
                Dim i As Integer
                For i = 0 To Count - 1
                        text(i).Destroy
                        Set text(i) = Nothing
                Next
                Hide
                If debugClass Then MsgBox "EasyText: Class_Terminate"
        End Sub
' B
        Public Function SetSize(ByVal newCount As Long) As Boolean
                Dim i As Integer
                SetSize = True
                If newCount <= ItemMax Then
                        If newCount < ItemNum Then
                                For i = newCount To ItemNum - 1
                                        text(i).Destroy
                                Next
                        End If
                        ItemNum = newCount
                Else
                        SetSize = False
                End If
        End Function
        Private Function MoveChar(ByVal fromindex As Long, ByVal toindex As Long) As Boolean
                copyEChar text(toindex), text(fromindex)
                text(toindex).CID = toindex
                MoveChar = True
        End Function

' C
        Public Function RecalcPos(Optional ByVal startI As Long = 0, Optional ByVal redraw As Boolean = False) As Boolean
                Dim i As Long
                Dim traceY As Single
                Dim needRedraw As Boolean

                RecalcPos = True
                If startI >= ItemNum Then Exit Function

                traceY = py
                If startI > 0 Then traceY = text(startI - 1).m_AuxY + text(startI - 1).height

                For i = startI To ItemNum - 1
                        With text(i)
                                ' 重定位, 如果已经在现, 将它重画
                                        If .m_AuxX <> X Or .m_AuxY <> traceY Then
                                                needRedraw = .m_AuxOnDraw And redraw
                                                If needRedraw Then .ClearChar
                                                .m_AuxX = X
                                                .m_AuxY = traceY
                                                If needRedraw Then .PaintChar
                                        End If
                                ' 扫描累计
                                        traceY = traceY + .height
                        End With
                Next
        End Function
        Private Function Show() As Boolean: Show = IIf(Visible, Paint, Clear): End Function
        Private Function Hide() As Boolean: Hide = Clear: End Function
        Private Function Paint() As Boolean
                Dim i As Long
                OnShow = True
                If Not OnShow Then
                        Paint = True
                        For i = 0 To ItemNum - 1
                                Paint = Paint And text(i).PaintChar
                        Next
                        OnShow = True
                End If
        End Function
        Private Function Clear() As Boolean
                Dim i As Long
                Clear = True
                If OnShow Then
                        For i = 0 To ItemNum - 1
                                Clear = Clear And text(i).ClearChar
                        Next
                        OnShow = False
                End If
        End Function
' D
        Public Function Save(ByVal X As Long, ByVal Y As Long, ByVal w As Long, ByVal h As Long) As Boolean
                'Save = BitBlt(SceneBakDC, x, y, w, h, sceneDC, x, y, SRCCOPY)
        End Function
        Public Function Load(ByVal X As Long, ByVal Y As Long, ByVal w As Long, ByVal h As Long) As Boolean
                Load = BitBlt(sceneDC, X, Y, w, h, SceneBakDC, X, Y, SRCCOPY)
        End Function
