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
        Private Const MAXCOUNT = 5
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
                If ShouldRefresh Then Refresh
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

' 自动行处理
        Public Function AL_InsertBreak(ByVal index As Long, ByVal offset As Integer, Optional ByVal Refresh As Boolean = True) As Boolean
                AL_InsertBreak = InsertChar(index + 1, Text(index))
                If AL_InsertBreak Then
                        Text(index).Content = Left(Text(index).Content, offset)
                        Text(index).Break = True
                        Text(index + 1).Content = Mid(Text(index + 1).Content, offset + 1)
                        If Refresh Then AL_InsertBreak = AL_InsertBreak And AL_Refresh(-1, index + 1)
                End If
        End Function
        Public Function AL_RemoveBreak(ByVal index As Long, Optional ByVal combineModification As Boolean = True, Optional ByVal Refresh As Boolean = True) As Boolean
                If combineModification Then
                        If index + 1 < ItemNum Then Text(index).Content = Text(index + 1).Content
                Else
                        Text(index).Break = False
                End If
                AL_RemoveBreak = True
                If Refresh Then AL_RemoveBreak = AL_Refresh(-1, index)
        End Function
        Public Function AL_InsertContent(ByVal index As Integer, ByVal offset As Integer, ByVal Content As String, Optional ByVal Refresh As Boolean = True) As Boolean
                With Text(index)
                        .Content = Left(.Content, offset) & Content & Mid(.Content, offset + 1)
                End With
                AL_InsertContent = True
                If Refresh Then AL_InsertContent = AL_Refresh(-1, index, True)
        End Function
        Public Function AL_AppendContent(ByVal Content As String, Optional ByVal Refresh As Boolean = True) As Boolean
                AL_AppendContent = AL_InsertContent(ItemNum - 1, Text(ItemNum - 1).mlen, Refresh)
        End Function
        Public Function AL_DeleteContent(ByVal index As Integer, ByVal offset As Integer, Optional ByVal nContent As Integer = 1, Optional ByVal Refresh As Boolean = True) As Boolean
                Dim nContentLeft As Integer
                Dim r As Boolean
                r = True
                nContentLeft = nContent
                Do While nContentLeft > 0
                        With Text(index)
                                If nContentLeft > .mlen - offset And ItemNum > 1 Then
                                        .Content = Left(.Content, offset)
                                        nContentLeft = nContentLeft - (.mlen - offset)
                                        ' 如果有下一行, 把下一行的文本连接到本行, 删除下行
                                        If index + 1 < ItemNum Then
                                                .Content = .Content & Text(index + 1).Content
                                                .Break = Text(index + 1).Break
                                                r = r And DeleteChar(index + 1)
                                        Else
                                                nContentLeft = 0
                                        End If
                                Else
                                        .Content = Left(.Content, offset) & Mid(.Content, offset + nContentLeft + 1)
                                        nContentLeft = 0
                                End If
                        End With
                Loop
                If Refresh Then AL_DeleteContent = AL_DeleteContent And AL_Refresh(-1, index)
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
                Dim p As Integer        ' 当前列举字符位置
                Dim nIgnore As Integer  ' 表示从p开始忽略的字符数
                Dim c As String         ' 当前获取字符
                Dim la As Integer       ' ANSI长度, 用于分割行
                Dim lm As Integer       ' MBCS长度, 用于列举字符
                Dim w As Integer        ' 当前行宽度, 用于分割行
                Dim cw As Integer       ' 当前字符宽度, 用于分割行
                Dim shouldBreak As Boolean
                Dim InsertTo As Long
                Dim r As Boolean

                If maxRows = -1 Then maxRows = MAXCOUNT
                Set ec = Text(fromindex)
                p = 1: w = 0
                la = ec.alen: lm = ec.mlen
                InsertTo = fromindex + 1
                r = True
                Do While ItemNum <= maxRows And Not ec Is Nothing
                        If p > lm Then Exit Do
                        c = Mid(ec.Content, p, 1)

                        cw = getStringLengthA(c)
                        If w + cw > LineMax Then shouldBreak = True: nIgnore = 0
                        If breakChar Then
                                If Asc(c) = 13 Then shouldBreak = True: nIgnore = 1
                        End If
                        If shouldBreak Then
                                ' 把本行剩余字符(从p开始)搬到下一行(忽略nIgnore个字符)
                                Dim LeftChars As String
                                LeftChars = Mid(ec.Content, p + nIgnore)
                                ec.Content = Left(ec.Content, p - 1)
                                ec.Break = True

                                If InsertTo < ItemNum Then
                                        Set ec = Text(InsertTo)
                                ElseIf ItemNum < maxRows Then
                                        AppendChar ec
                                        Set ec = Text(InsertTo)
                                        ec.Content = ""
                                Else
                                        Set ec = Nothing
                                End If

                                If Not ec Is Nothing Then
                                        ec.Content = LeftChars & ec.Content
                                        la = ec.alen: lm = ec.mlen
                                        InsertTo = InsertTo + 1
                                        p = 0
                                        w = 0
                                        cw = 0
                                        shouldBreak = False
                                End If
                        End If
                        p = p + 1
                        w = w + cw
                Loop
                AL_Refresh = r
        End Function

' 高级接口
        Public Function Refresh() As Boolean
                Dim i As Integer
                For i = 0 To ItemNum - 1
                        redraw i, False
                Next
                SetCaret
        End Function
        ' 成员发生改变
        Public Function Changed(ByVal CID As Long) As Boolean
                Dim i As Long
                redraw CID, True
                RecalcPos CID + 1
                For i = CID + 1 To ItemNum - 1
                        redraw i, False
                Next
        End Function
        Public Function redraw(ByVal CID As Long, Optional ByVal RecalcExtent As Boolean = False) As Boolean
                ClearChar CID
                If IsVisible Then PaintChar CID, RecalcExtent
        End Function

' 位置处理
        Public Function MaxRow() As Integer
                MaxRow = ItemNum - 1
        End Function
        Public Function MaxCol(ByVal nRow As Integer) As Integer
                MaxCol = Text(nRow).mlen
        End Function
        ' 获得里指定纵坐标最接近的行
        Public Function GetNearestRow(ByVal posY As Single) As Integer
                Dim Ri As Integer
                GetNearestRow = -1
                For Ri = 0 To MaxRow
                        With Text(Ri)
                                If posY >= .m_AuxY And posY < .m_AuxY + .height Then
                                        GetNearestRow = Ri
                                        Exit For
                                End If
                        End With
                Next
                If GetNearestRow < 0 Then
                        If posY < y Then GetNearestRow = 0 Else GetNearestRow = MaxRow
                End If
        End Function
        Public Function GetNearestCol(ByVal nRow As Integer, ByVal posX As Single) As Integer
                GetNearestCol = Text(nRow).WidthN(posX - x)
        End Function
        ' 根据行列值设置光标
        Public Function SetCaret() As Boolean
                With Text(Row)
                        If ShowCaret Then SetCaret = SetCaretPos(.m_AuxX + .nWidth(Col), .m_AuxY)
                        'frmMain.lblI = "[" & Row & "," & Col & "] " & .m_AuxX + .nWidth(Col) & ":" & .m_AuxY
                End With
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
                        If Crow > 0 Then Crow = Crow - 1: Ccol = MaxCol(Crow) - 1 Else moveLeft = False
                End If
        End Function
        Public Function moveRight() As Boolean
                moveRight = True
                If Ccol < MaxCol(Crow) Then
                        Ccol = Ccol + 1
                Else
                        If Crow < MaxRow Then
                                Crow = Crow + 1
                                Ccol = Ccol Mod (MaxCol(Crow - 1) - 1)
                        Else
                                moveRight = False
                        End If
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
                ShowCaret = False

                px = 10: py = 10
                Crow = 0: Ccol = 0

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
                SetSize = True
                If newCount <= MAXCOUNT Then
                        ItemNum = newCount
                Else
                        SetSize = False
                End If
        End Function
        Private Function MoveChar(ByVal fromindex As Long, ByVal toindex As Long) As Boolean
                copyEChar Text(toindex), Text(fromindex)
                Text(toindex).CID = toindex
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
                Dim traceY As Single

                RecalcPos = True
                If startI >= ItemNum Then Exit Function

                traceY = py
                If startI > 0 Then traceY = Text(startI - 1).m_AuxY + Text(startI - 1).height

                For i = startI To ItemNum - 1
                        With Text(i)
                                ' 重定位, 如果已经在现, 将它重画
                                        If .m_AuxOnDraw Then ClearChar i
                                        .m_AuxX = x
                                        .m_AuxY = traceY
                                        If .m_AuxOnDraw Then PaintChar i
                                ' 扫描累计
                                        traceY = traceY + .height
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
        Public Function Save(ByVal x As Long, ByVal y As Long, ByVal w As Long, ByVal h As Long) As Boolean
                Save = BitBlt(SceneBakDC, x, y, w, h, sceneDC, x, y, SRCCOPY)
        End Function
        Public Function Load(ByVal x As Long, ByVal y As Long, ByVal w As Long, ByVal h As Long) As Boolean
                Load = BitBlt(sceneDC, x, y, w, h, SceneBakDC, x, y, SRCCOPY)
        End Function
