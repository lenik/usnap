VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 1  'vbSimpleBound
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "EasyTextEx"
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

' B:特效文字数组
        Private Const MAXCOUNT = 512
        Private Text(0 To MAXCOUNT) As New EasyChar
        Private ItemNum As Long
        Private LineMax As Integer

        Public Function TTT(ByVal index As Integer): Set TTT = Text(index): End Function
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
                Dim ShouldRefresh As Boolean
                ShouldRefresh = IsVisible <> newVisible
                IsVisible = newVisible
                If ShouldRefresh Then refresh
        End Property
        Public Property Get x() As Single: x = px: End Property
        Public Property Let x(ByVal newx As Single)
                If px <> newx Then
                        Hide
                        px = newx
                        RecalcPos
                        Show
                End If
        End Property
        Public Property Get y() As Single: y = py: End Property
        Public Property Let y(ByVal newy As Single)
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

        Public Function GetSel(selOffset As Integer) As Long
                Dim i As Integer, nCols As Integer
                Dim i0 As Integer
                GetSel = -1
                nCols = 0: i0 = GetRowFirst(Row)
                If i0 < 0 Then Exit Function
                ' 找出当前行中列所处的位置
                For i = GetRowFirst(Row) To ItemNum - 1
                        If Col - nCols < Text(i).MLen Then
                                GetSel = i
                                If Not IsNull(selOffset) Then selOffset = Col - nCols
                                Exit For
                        End If
                        nCols = nCols + Text(i).MLen
                        If Text(i).Break Then Exit For
                Next
        End Function
        Public Property Get Sel() As Integer
                Dim selOff As Integer
                Sel = GetSel(selOff)
        End Property

' Group B
        Public Property Get Count() As Integer
                Count = ItemNum
        End Property
        Public Function GetChar(ByVal index As Integer) As EasyChar: Set GetChar = IIf(index < ItemNum, Text(index), Nothing): End Function
        Public Function SetChar(ByVal index As Integer, NewChar As EasyChar) As Boolean
                SetChar = False
                If index > ItemNum Then
                        If Not SetSize(index + 1) Then Exit Function
                End If
                copyEChar Text(index), NewChar
                Text(index).SetOwnerText Me, index
                RecalcPos index
                SetChar = True
        End Function

        Public Function AppendChar(NewChar As EasyChar) As Boolean
                If Not SetSize(ItemNum + 1) Then Exit Function
                SetChar ItemNum - 1, NewChar
                AppendChar = True
        End Function
        Public Function InsertChar(ByVal insertindex As Integer, NewChar As EasyChar) As Boolean
                Dim i As Long
                If insertindex >= ItemNum Then
                        If Not SetSize(insertindex + 1) Then Exit Function
                Else
                        For i = ItemNum - 1 To insertindex + 1 Step -1
                                MoveChar i - 1, i
                        Next
                End If
                InsertChar = SetChar(insertindex, NewChar)
        End Function
        Public Function DeleteChar(ByVal deleteindex As Integer) As Boolean
                Dim i As Long
                DeleteChar = False
                If deleteindex < 0 Or deleteindex >= ItemNum Then Exit Function

                ClearChar deleteindex
                Text(deleteindex).Destroy
                ' 对象内存处理
                        Set Text(deleteindex) = New EasyChar
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

' 修饰副插入与合并行
        Public Function CombineRow(ByVal nRow As Integer) As Boolean
                Dim Ci As Integer
                Ci = GetRowFirst(nRow)
                CombineRow = False
                If Ci > 0 Then
                        CombineRow = True
                        Do While Ci < ItemNum - 1
                                If Text(Ci).Break Then Exit Do
                                Text(Ci).Content = Text(Ci).Content & Text(Ci + 1).Content
                                Text(Ci).Break = Text(Ci + 1).Break
                                Ci = Ci + 1
                        Loop
                End If
        End Function
        Public Function InsertModificationI(ByVal index As Long, ByVal offset As Integer, ByVal Length As Integer, modificationReferer As EasyChar) As Boolean
                Dim r As Boolean
                Dim oContent As String, oLength As Integer
                oContent = Text(index).Content
                oLength = Len(oContent)
                If offset = 0 Then
                        If Length >= oLength Then
                                r = copyEChar(Text(index), modificationReferer)
                                If r Then Text(index).Content = oContent
                        Else
                                ' length < oLength
                                r = InsertChar(index, modificationReferer)
                                If r Then
                                        Text(index).Content = Left(oContent, Length)
                                        Text(index + 1).Content = right(oContent, oLength - Length)
                                End If
                        End If
                Else
                        r = InsertChar(index + 1, modificationReferer)
                        If r Then
                                Text(index + 1).Break = Text(index).Break
                                Text(index).Break = False
                                If offset + Length - 1 >= oLength - 1 Then
                                        Text(index).Content = Left(oContent, offset - 1)
                                        Text(index + 1).Content = Mid(oContent, offset)
                                Else
                                        ' offset + length < oLength
                                        r = r And InsertChar(index + 2, Text(index))
                                        If r Then
                                                Text(index + 2).Break = Text(index + 1).Break
                                                Text(index + 1).Break = False
                                                Text(index).Content = Left(oContent, offset - 1)
                                                Text(index + 1).Content = Mid(oContent, offset, Length)
                                                Text(index + 2).Content = Mid(oContent, offset + Length)
                                        End If
                                End If
                        End If
                End If

                InsertModificationI = r
        End Function
        Public Function InsertModification(ByVal nRow As Integer, ByVal nCol As Integer, ByVal Length As Integer, modificationReferer As EasyChar) As Boolean
                Dim index As Long
                Dim offset As Integer
                index = GetColFirst(nRow, nCol)
                InsertModification = False
                If index >= 0 Then
                        offset = nCol - GetPrefixCol(index)
                        InsertModification = InsertModificationI(index, offset, Length, modificationReferer)
                End If
        End Function

' 自动行处理
        Public Function AL_InsertBreakI(ByVal index As Long, ByVal offset As Integer, Optional ByVal refresh As Boolean = True) As Boolean
                AL_InsertBreakI = InsertChar(index + 1, Text(index))
                If AL_InsertBreakI Then
                        Text(index).Content = Left(Text(index).Content, offset)
                        Text(index).Break = True
                        Text(index + 1).Content = Mid(Text(index + 1).Content, offset + 1)
                        If refresh Then AL_InsertBreakI = AL_InsertBreakI And AL_Refresh(-1, index + 1)
                End If
        End Function
        Public Function AL_InsertBreak(ByVal nRow As Integer, ByVal nCol As Integer, Optional ByVal refresh As Boolean = True) As Boolean
                Dim index As Long
                Dim offset As Integer
                index = GetColFirst(nRow, nCol)
                AL_InsertBreak = False
                If index >= 0 Then
                        offset = nCol - GetPrefixCol(index)
                        AL_InsertBreak = AL_InsertBreakI(index, offset, refresh)
                End If
        End Function
        Public Function AL_RemoveBreakI(ByVal index As Long, Optional ByVal combineModification As Boolean = True, Optional ByVal refresh As Boolean = True) As Boolean
                If combineModification Then
                        If index + 1 < ItemNum Then Text(index).Content = Text(index + 1).Content
                Else
                        Text(index).Break = False
                End If
                AL_RemoveBreakI = True
                If refresh Then AL_RemoveBreakI = AL_Refresh(-1, index)
        End Function
        Public Function AL_RemoveBreak(ByVal nRow As Integer, ByVal nCol As Integer, Optional ByVal combineModification As Boolean = True, Optional ByVal refresh As Boolean = True) As Boolean
                Dim index As Long
                index = GetColFirst(nRow, nCol)
                AL_RemoveBreak = False
                If index >= 0 Then AL_RemoveBreak = AL_RemoveBreakI(index, combineModification, refresh)
        End Function
        Public Function AL_InsertContentI(ByVal index As Integer, ByVal offset As Integer, ByVal Content As String, Optional ByVal refresh As Boolean = True) As Boolean
                With Text(index)
                        .Content = Left(.Content, offset) & Content & Mid(.Content, offset + 1)
                End With
                AL_InsertContentI = True
                If refresh Then AL_InsertContentI = AL_Refresh(-1, index, True)
        End Function
        Public Function AL_InsertContent(ByVal nRow As Integer, ByVal nCol As Integer, ByVal Content As String, Optional ByVal refresh As Boolean = True) As Boolean
                Dim index As Long
                Dim offset As Integer
                index = GetColFirst(nRow, nCol)
                AL_InsertContent = False
                If index >= 0 Then
                        offset = nCol - GetPrefixCol(index)
                        AL_InsertContent = AL_InsertContentI(index, offset, Content, refresh)
                End If
        End Function
        Public Function AL_AppendContent(ByVal Content As String, Optional ByVal refresh As Boolean = True) As Boolean
                AL_AppendContent = AL_InsertContentI(ItemNum - 1, Text(ItemNum - 1).MLen, refresh)
        End Function
        Public Function AL_DeleteContentI(ByVal index As Integer, ByVal offset As Integer, Optional ByVal nContent As Integer = 1, Optional ByVal refresh As Boolean = True) As Boolean
                Dim nContentLeft As Integer
                nContentLeft = nContent
                Do While nContentLeft > 0
                        If nContentLeft > Text(index).MLen Then
                                If Text(index).Break Then
                                        DeleteChar index
                                        nContentLeft = 0
                                Else
                                        nContentLeft = nContentLeft - Text(index).MLen
                                        offset = offset - Text(index).MLen
                                        DeleteChar index
                                End If
                        Else
                                With Text(index)
                                        .Content = Left(.Content, offset) & Mid(.Content, offset + nContentLeft + 1)
                                End With
                                nContentLeft = 0
                        End If
                Loop
        End Function
        Public Function AL_DeleteContent(ByVal nRow As Integer, ByVal nCol As Integer, Optional ByVal nContent As Integer = 1, Optional ByVal refresh As Boolean = True) As Boolean
                Dim index As Long
                Dim offset As Integer
                index = GetColFirst(nRow, nCol)
                AL_DeleteContent = False
                If index >= 0 Then
                        offset = nCol - GetPrefixCol(index)
                        AL_DeleteContent = AL_DeleteContentI(index, offset, nContent, refresh)
                End If
        End Function
        Public Function AL_AllocContent(ByVal Content As String, ByVal maxRows As Integer, Optional template_ec As EasyChar = Nothing) As Boolean
                Dim ec As EasyChar
                If template_ec Is Nothing Then Set template_ec = template_FingerChar
                Set ec = New EasyChar
                copyEChar ec, template_ec

                AL_AllocContent = DeleteAll
                ec.Content = Content
                AL_AllocContent = AL_AllocContent And AppendChar(ec)
                AL_AllocContent = AL_AllocContent And AL_Refresh(maxRows, 0, True)
        End Function

        Public Function AL_Refresh(ByVal maxRows As Integer, Optional ByVal fromindex As Long = 0, Optional ByVal breakChar As Boolean = False) As Boolean
                Dim ec As EasyChar
                Dim P As Integer        ' 当前列举字符位置
                Dim nIgnore As Integer  ' 表示从p开始忽略的字符数
                Dim c As String         ' 当前获取字符
                Dim la As Integer       ' ANSI长度, 用于分割行
                Dim lm As Integer       ' MBCS长度, 用于列举字符
                Dim w As Integer        ' 当前行宽度, 用于分割行
                Dim cw As Integer       ' 当前字符宽度, 用于分割行
                Dim nRows As Integer     ' 加入的行数
                Dim shouldBreak As Boolean
                Dim InsertTo As Long
                Dim r As Boolean

                If maxRows = -1 Then maxRows = MAXCOUNT
                Set ec = Text(fromindex)
                P = 1: w = 0
                la = ec.ALen: lm = ec.MLen
                InsertTo = fromindex + 1
                r = True
                Do While nRows <= maxRows
                        If P > lm Then Exit Do
                        c = Mid(ec.Content, P, 1)

                        cw = getStringLengthA(c)
                        If w + cw > LineMax Then shouldBreak = True: nIgnore = 0
                        If breakChar Then
                                If Asc(c) = 13 Then shouldBreak = True: nIgnore = 1
                        End If
                        If shouldBreak Then
                                ' 把本行剩余字符(从p开始)搬到下一行(忽略nIgnore个字符)
                                Dim LeftChars As String
                                LeftChars = Mid(ec.Content, P + nIgnore)
                                ec.Content = Left(ec.Content, P - 1)
                                ec.Break = True
                                If Row = GetWhichRow(ec.CID) Then
                                        If GetColFirst(Row, Col) = ec.CID Then
                                                If ec.MLen >= P - GetPrefixCol(ec.CID) Then
                                                End If
                                        End If
                                End If

                                If InsertTo >= ItemNum Then
                                        AppendChar ec
                                        Text(InsertTo).Content = ""
                                End If
                                Set ec = Text(InsertTo)
                                ec.Content = LeftChars & ec.Content
                                la = ec.ALen: lm = ec.MLen
                                InsertTo = InsertTo + 1
                                P = 0
                                w = 0
                                cw = 0
                                nRows = nRows + 1
                                shouldBreak = False
                        End If
                        P = P + 1
                        w = w + cw
                Loop
                AL_Refresh = r
        End Function

' 高级接口
        Public Function refresh() As Boolean
                Hide
                Show
        End Function
        ' 成员发生改变
        Public Function Changed(ByVal CID As Long) As Boolean
                Dim i As Long
                Redraw CID, True
                RecalcPos CID + 1
                For i = CID + 1 To ItemNum - 1
                        Redraw i, False
                Next
        End Function
        Public Function Redraw(ByVal CID As Long, Optional ByVal RecalcExtent As Boolean = False) As Boolean
                ClearChar CID
                If IsVisible Then PaintChar CID, RecalcExtent
        End Function

' 位置处理
        Public Function MaxRow() As Integer
                MaxRow = GetWhichRow(ItemNum - 1)
        End Function
        Public Function MaxCol(ByVal nRow As Integer) As Integer
                MaxCol = Len(GetRowString(nRow)) - 1
        End Function
        Public Function GetRowString(ByVal nRow As Integer) As String
                Dim i As Integer
                i = GetRowFirst(nRow)
                GetRowString = ""
                If i >= 0 Then
                        Do While i < ItemNum
                                GetRowString = GetRowString & Text(i).Content
                                If Text(i).Break Then Exit Do
                                i = i + 1
                        Loop
                End If
        End Function
        ' 获取Row行第一个元素号
        Public Function GetRowFirst(ByVal whichRow As Integer) As Long
                Dim cr As Integer, i As Long
                i = 0: cr = 0
                Do While i < ItemNum
                        If cr = whichRow Then Exit Do
                        If Text(i).Break Then cr = cr + 1
                        i = i + 1
                Loop
                GetRowFirst = -1
                If cr = whichRow Then GetRowFirst = i
        End Function
        ' 获取元素所在行
        Public Function GetWhichRow(ByVal index As Long) As Integer
                Dim cr As Integer, i As Long
                i = 0: cr = 0
                ' 不包括(index), 因为(index)的断行标志不影响结果
                Do While i < index
                        If Text(i).Break Then cr = cr + 1
                        i = i + 1
                Loop
                GetWhichRow = cr
        End Function
        ' 获取Row行Col列第一个元素号(即所处的元素号)
        Public Function GetColFirst(ByVal nRow As Integer, ByVal whichCol As Integer) As Long
                Dim Ci As Integer
                Dim nCols As Integer
                GetColFirst = -1
                Ci = nRow
                Do While Ci < ItemNum
                        If nCols + Text(Ci).MLen >= whichCol Then
                                GetColFirst = Ci
                                Exit Do
                        End If
                        If Text(Ci).Break Then Exit Do
                        nCols = nCols + Text(Ci).MLen
                        Ci = Ci + 1
                Loop
        End Function
        ' 获取元素号的首字母对应列号
        Public Function GetPrefixCol(ByVal index As Long) As Integer
                Dim Ri As Integer, c As Integer
                Ri = GetWhichRow(index)
                GetPrefixCol = -1
                If Ri >= 0 Then
                        While Ri < index
                                c = c + Text(Ri).MLen
                        Wend
                        GetPrefixCol = c
                End If
        End Function
        ' 获取元素号的首字母对应整行的部分宽度
        Public Function GetPrefixWidth(ByVal index As Long) As Single
                Dim Ri As Integer, w As Single
                Ri = GetWhichRow(index)
                GetPrefixWidth = -1
                If Ri > 0 Then
                        While Ri < index
                                w = w + Text(Ri).width
                        Wend
                        GetPrefixWidth = w
                End If
        End Function
        ' 获得里指定纵坐标最接近的行
        Public Function GetNearestRow(ByVal posY As Single) As Integer
                Dim lastY As Single, lastRi As Integer
                Dim r As Integer, Ri As Integer
                lastY = Text(0).m_AuxY: lastRi = 0
                GetNearestRow = -1
                For r = 1 To MaxRow
                        Ri = GetRowFirst(r)
                        If Text(Ri).m_AuxY > posY And lastY <= posY Then
                                GetNearestRow = lastRi
                                Exit For
                        End If
                        lastY = Text(Ri).m_AuxY
                        lastRi = Ri
                Next
        End Function
        Public Function GetNearestCol(ByVal nRow As Integer, ByVal posX As Single) As Integer
                Dim lastX As Single, lastCi As Integer
                Dim Ci As Integer, nCols As Integer
                Dim Ri As Long
                Ri = GetRowFirst(nRow)
                lastX = Text(Ri).m_AuxX: lastCi = 0
                nCols = 0
                GetNearestCol = -1
                If Text(Ri).width >= posX - Text(Ri).m_AuxX + 1 Then
                        GetNearestCol = Text(Ri).WidthN(posX - Text(Ri).m_AuxX + 1)
                Else
                        For Ci = Ri + 1 To ItemNum - 1
                                If Text(Ci).m_AuxX > posX And lastX <= posX Then
                                        GetNearestCol = nCols - Text(lastCi).MLen + _
                                                Text(lastCi).WidthN(Text(Ci).m_AuxX - posX + 1)
                                        Exit For
                                End If
                                If Text(Ci).Break Then
                                        If GetNearestCol < 0 Then
                                                If posX > Text(Ci).m_AuxX Then Col = MaxCol(nRow) + 1
                                        End If
                                        Exit For
                                End If
                                nCols = nCols + Text(Ci).MLen
                                lastX = Text(Ci).m_AuxX
                                lastCi = Ci
                        Next
                End If
        End Function
        ' 根据行列值设置光标
        Public Function SetCaret() As Boolean
                Dim selOff As Integer
                Dim Si As Integer
                Si = GetSel(selOff)
                SetCaret = False
                If Si < 0 Then Exit Function
                With Text(GetSel(selOff))
                        SetCaret = SetCaretPos(.m_AuxX + .nWidth(selOff), .m_AuxY)
                        'frmMain.lblI = .m_AuxX + .nWidth(selOff) & ":" & .m_AuxY
                End With
        End Function
        ' 根据光标设置行列值
        Public Function SetRowCol(ByVal caretX As Single, ByVal caretY As Single) As Boolean
                Dim lastX As Single
                Dim nr As Long
                Dim i0 As Long, i As Long

                SetRowCol = False
                nr = GetNearestRow(caretY)
                If nr = -1 Then Exit Function
                Row = nr

                Col = GetNearestCol(Row, caretX)
        End Function

        Public Function moveLeft() As Boolean
                moveLeft = True
                If Ccol > 0 Then
                        Ccol = Ccol - 1
                Else
                        If Crow > 0 Then Crow = Crow - 1: Ccol = MaxCol(Crow) + 1 Else moveLeft = False
                End If

        End Function
        Public Function moveRight() As Boolean
                moveRight = True
                If Ccol <= MaxCol(Crow) Then
                        Ccol = Ccol + 1
                Else
                        If Crow < MaxRow Then Crow = Crow + 1: Ccol = 0 Else moveRight = False
                End If
        End Function
        Public Function moveUp() As Boolean
                moveUp = True
                If Crow > 0 Then
                        Crow = Crow - 1
                        If Ccol > MaxCol(Crow) Then Ccol = MaxCol(Crow) + 1
                Else
                        moveUp = False
                End If
        End Function
        Public Function moveDown() As Boolean
                moveDown = True
                If Crow < MaxRow Then
                        Crow = Crow + 1
                        If Ccol > MaxCol(Crow) Then Ccol = MaxCol(Crow) + 1
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

                ItemNum = 0
                LineMax = FC_LINEMAX

                Set drawDCpic = frmMain.picText
                drawDC = drawDCpic.hdc
                If debugClass Then MsgBox "EasyText: Class_Init"
        End Sub
        Private Sub Class_Terminate()
                Hide
                If debugClass Then MsgBox "EasyText: Class_Terminate"
        End Sub
' B
        Private Function SetSize(ByVal newCount As Long) As Boolean
                If newCount < MAXCOUNT Then ItemNum = newCount
                SetSize = True
        End Function
        Private Function MoveChar(ByVal fromindex As Long, ByVal toindex As Long) As Boolean
                Dim tChar As New EasyChar
                copyEChar tChar, Text(toindex)
                copyEChar Text(toindex), Text(fromindex)
                copyEChar Text(fromindex), tChar
                MoveChar = True
        End Function
' C1
        Private Function Show() As Boolean
                If Visible Then
                        Hide
                        Paint
                        OnShow = True
                Else
                        Hide
                        OnShow = False
                End If
        End Function
        Private Function Hide() As Boolean
                If OnShow Then
                        Clear
                        OnShow = False
                End If
        End Function
' C2
        Private Function RecalcPos(Optional ByVal startI As Long = 0) As Boolean
                Dim i As Long
                Dim traceX As Single, traceY As Single

                RecalcPos = True
                If startI >= ItemNum Then Exit Function

                traceX = px: traceY = py
                If startI > 0 Then
                        With Text(startI - 1)
                                traceY = .m_AuxY
                                If Not .Break Then
                                        traceX = .m_AuxX + .width
                                Else
                                        traceY = traceY + .height
                                End If
                        End With
                End If
                For i = startI To ItemNum - 1
                        With Text(i)
                                ' 重定位, 如果已经在现, 将它重画
                                        If .m_AuxOnDraw Then
                                                ClearChar i
                                        End If
                                        .m_AuxX = traceX: .m_AuxY = traceY
                                        If .m_AuxOnDraw Then
                                                PaintChar i
                                        End If
                                ' 扫描累计
                                        If Not .Break Then
                                                traceX = traceX + .width
                                        Else
                                                traceX = px
                                                traceY = traceY + .height
                                        End If
                        End With
                Next
        End Function
        Private Function PaintChar(ByVal i As Long, Optional ByVal RecalcExtent As Boolean = False) As Boolean
                Dim r As Boolean

                If RecalcExtent Then Text(i).RecalcCharExtent
                With Text(i)
                        If Not .m_AuxOnDraw Then
                                r = Save(.m_AuxX, .m_AuxY, .width, .height)
                                r = r And .Paint
                                .m_AuxOnDraw = True
                        End If
                End With
                PaintChar = r
        End Function
        Private Function ClearChar(ByVal i As Long) As Boolean
                ClearChar = True
                With Text(i)
                        If .m_AuxOnDraw Then
                                ClearChar = Load(.m_AuxX, .m_AuxY, .width, .height)
                                .m_AuxOnDraw = False
                        End If
                End With
        End Function
        Private Function Paint() As Boolean
                Dim i As Long
                Paint = True
                For i = 0 To ItemNum - 1
                        Paint = Paint And PaintChar(i)
                Next
        End Function
        Private Function Clear() As Boolean
                Dim i As Long
                Clear = True
                For i = 0 To ItemNum - 1
                        Clear = Clear And ClearChar(i)
                Next
        End Function
' D
        Private Function Save(ByVal x As Long, ByVal y As Long, ByVal w As Long, ByVal h As Long) As Boolean
                Save = BitBlt(SceneBakDC, x, y, w, h, sceneDC, x, y, SRCCOPY)
        End Function
        Private Function Load(ByVal x As Long, ByVal y As Long, ByVal w As Long, ByVal h As Long) As Boolean
                Load = BitBlt(sceneDC, x, y, w, h, SceneBakDC, x, y, SRCCOPY)
        End Function
