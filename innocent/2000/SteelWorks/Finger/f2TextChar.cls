VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "EasyChar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
' 控制属性
        ' OwnerText 用于向上传递动作
        Private m_OwnerText As EasyText
        ' CID 表示实例号(相对于OwnerText)
        Private m_CID As Long
        ' DrawPic 表示画的图片设备 (实际上这个内部变量并未使用, 而是直接通过m_OwnerText.drawDCpic
        Private m_DrawPic As PictureBox

        ' CharExtent表示理论上的大小, DrawExtent表示实际上画出来的大小
        Private m_CharExtent As SIZEL
        Private m_DrawExtent As SIZEL

' A:对这些属性的修改有可能导致大小的改变, 故需要将变动反映到Text
        Private m_Content As String
        Private m_DrawContent As String

        Private m_FontName As String
        Private m_FontSize As Single
        Private m_FontBold As Boolean
        Private m_FontItalic As Boolean
        Private m_FontUnderline As Boolean
        Private m_FontStrikethrough As Boolean

        Private m_Break As Boolean

' B:对这些属性的修改只会改变显示效果, 可以直接在本级实现
        Private m_ForeColor As Long
        Private m_BackColor As Long

        Private m_HasGradient As Boolean
        Private m_GradientC1 As Long
        Private m_GradientC2 As Long
        Private m_GradientDirection As Long
        Private m_GradientLoop As Single

        ' 辅助坐标
        Public m_AuxX As Single, m_AuxY As Single
        Public m_AuxOnDraw As Boolean

        Private m_LineSpace As Single

' Control Group
        Public Property Get OwnerText() As EasyText
                Set OwnerText = m_OwnerText
        End Property
        Public Property Get CID() As Long: CID = m_CID: End Property
        Public Property Let CID(ByVal newLong As Long): m_CID = newLong: End Property
        Public Function SetOwnerText(et As EasyText, ByVal CID As Long) As Boolean
                SetOwnerText = False

                Set m_OwnerText = et
                m_CID = CID
                If et Is Nothing Then
                        Set m_DrawPic = Nothing
                Else
                        Set m_DrawPic = m_OwnerText.drawPic
                        RecalcCharExtent
                End If
                SetOwnerText = True
        End Function

        Public Property Get mlen() As Long: mlen = Len(Content): End Property
        Public Property Get alen() As Long: alen = getStringLengthA(Content): End Property
        Public Function RecalcCharExtent() As Boolean
                Dim r As Boolean
                Dim Extent As SIZEL
                Static callTime As Long
                With m_DrawPic.Font
                        If .Name <> m_FontName Then .Name = m_FontName
                        If .Size <> m_FontSize Then .Size = m_FontSize
                        If .Bold <> m_FontBold Then .Bold = m_FontBold
                        If .Italic <> m_FontItalic Then .Italic = m_FontItalic
                        If .Underline <> m_FontUnderline Then .Underline = m_FontUnderline
                        If .Strikethrough <> m_FontStrikethrough Then .Strikethrough = m_FontStrikethrough
                End With
                r = GetTextExtentPoint32(m_DrawPic.hdc, m_Content, alen, pAny(Extent))
                If r Then
                        m_CharExtent = Extent
                        If Extent.cy = 0 Then
                                r = GetTextExtentPoint32(m_DrawPic.hdc, "H", 1, pAny(Extent))
                                If r Then m_CharExtent.cy = Extent.cy
                        End If
                End If
                RecalcCharExtent = r

                callTime = callTime + 1
                'frmMain.lblExtentCall = callTime
        End Function
        ' 前n个字符的宽度
        Public Function nWidth(ByVal Num As Integer) As Single
                Dim r As Boolean
                Dim Extent As SIZEL
                nWidth = TextWidth
                If Num <= mlen Then
                        r = GetTextExtentPoint32(m_DrawPic.hdc, Left(Content, Num), MLen2ALen(Content, Num), pAny(Extent))
                        If r Then nWidth = Extent.cx
                End If
        End Function
        ' 定宽截至前n个字符
        Public Function WidthN(ByVal xWidth As Single) As Integer
                Dim r As Boolean
                Dim Extent As SIZEL
                Dim nFit As Long
                WidthN = 0
                r = GetTextExtentExPoint(m_DrawPic.hdc, Content, alen, xWidth, nFit, 0, pAny(Extent))
                If r Then WidthN = ALen2MLen(Content, nFit)
        End Function
        Public Property Get TextWidth() As Single: TextWidth = m_CharExtent.cx: End Property
        Public Property Get TextHeight() As Single: TextHeight = m_CharExtent.cy: End Property
        Public Property Get width() As Single: width = m_CharExtent.cx: End Property
        Public Property Get height() As Single: height = m_CharExtent.cy + m_LineSpace: End Property

' Group A
        Public Property Get Content() As String: Content = m_Content: End Property
        Public Property Let Content(ByVal newString As String)
                m_Content = newString
                sizeChanged
        End Property
        Public Property Get Font() As String: Font = m_FontName: End Property
        Public Property Let Font(ByVal newString As String)
                m_FontName = newString
                sizeChanged
        End Property
        Public Property Get Size() As Single: Size = m_FontSize: End Property
        Public Property Let Size(ByVal newSingle As Single)
                m_FontSize = newSingle
                sizeChanged
        End Property
        Public Property Get Bold() As Boolean: Bold = m_FontBold: End Property
        Public Property Let Bold(ByVal newBoolean As Boolean)
                m_FontBold = newBoolean
                sizeChanged
        End Property
        Public Property Get Italic() As Boolean: Italic = m_FontItalic: End Property
        Public Property Let Italic(ByVal newBoolean As Boolean)
                m_FontItalic = newBoolean
                sizeChanged
        End Property
        Public Property Get Underline() As Boolean: Underline = m_FontUnderline: End Property
        Public Property Let Underline(ByVal newBoolean As Boolean)
                m_FontUnderline = newBoolean
                sizeChanged
        End Property
        Public Property Get Strikethrough() As Boolean: Strikethrough = m_FontStrikethrough: End Property
        Public Property Let Strikethrough(ByVal newBoolean As Boolean)
                m_FontStrikethrough = newBoolean
                sizeChanged
        End Property
        Public Property Get Break() As Boolean: Break = m_Break: End Property
        Public Property Let Break(ByVal newBoolean As Boolean)
                m_Break = newBoolean
                sizeChanged
        End Property

' Group B
        Public Property Get ForeColor() As Long: ForeColor = m_ForeColor: End Property
        Public Property Let ForeColor(ByVal newLong As Long)
                m_ForeColor = newLong
                colorChanged
        End Property
        Public Property Get BackColor() As Long: BackColor = m_BackColor: End Property
        Public Property Let BackColor(ByVal newLong As Long)
                m_BackColor = newLong
                colorChanged
        End Property
        Public Property Get HasGradient() As Boolean: HasGradient = m_HasGradient: End Property
        Public Property Let HasGradient(ByVal newBoolean As Boolean)
                m_HasGradient = newBoolean
                colorChanged
        End Property
        Public Property Get GradientC1() As Long: GradientC1 = m_GradientC1: End Property
        Public Property Let GradientC1(ByVal newLong As Long)
                m_GradientC1 = newLong
                colorChanged
        End Property
        Public Property Get GradientC2() As Long: GradientC2 = m_GradientC2: End Property
        Public Property Let GradientC2(ByVal newLong As Long)
                m_GradientC2 = newLong
                colorChanged
        End Property
        Public Property Get GradientDirection() As Long: GradientDirection = m_GradientDirection: End Property
        Public Property Let GradientDirection(ByVal newLong As Long)
                m_GradientDirection = newLong
                colorChanged
        End Property
        Public Property Get GradientLoop() As Single: GradientLoop = m_GradientLoop: End Property
        Public Property Let GradientLoop(ByVal newSingle As Single)
                m_GradientLoop = newSingle
                colorChanged
        End Property

        Public Property Get DrawExtentW() As Long: DrawExtentW = m_DrawExtent.cx: End Property
        Public Property Let DrawExtentW(ByVal newLong As Long)
                m_DrawExtent.cx = newLong
        End Property

        Public Property Get DrawExtentH() As Long: DrawExtentH = m_DrawExtent.cy: End Property
        Public Property Let DrawExtentH(ByVal newLong As Long)
                m_DrawExtent.cy = newLong
        End Property

        Public Property Get DrawContent() As String: DrawContent = m_DrawContent: End Property
        Public Property Let DrawContent(ByVal newString As String)
                m_DrawContent = newString
        End Property

Public Function redraw(Optional ByVal force As Boolean = False) As Boolean
        Static callTime As Long
        If m_OwnerText Is Nothing Then Exit Function
        RecalcCharExtent
        If m_DrawExtent.cx <> m_CharExtent.cx Or _
                m_DrawExtent.cy <> m_CharExtent.cy Or _
                m_DrawContent <> m_Content Or _
                force Then
                ClearChar
                PaintChar
        End If
        callTime = callTime + 1
        'frmMain.lblPaintCall = callTime
End Function
Public Function PaintChar() As Boolean
        Static callTime As Long
        'If Not m_AuxOnDraw Then
                PaintChar = Paint
                m_AuxOnDraw = True
        'End If
        callTime = callTime + 1
        'frmMain.lblPaintCall = callTime
End Function
Public Function ClearChar() As Boolean
        Static callTime As Long
        ClearChar = True
        If m_AuxOnDraw Then
                ClearChar = m_OwnerText.Load(m_AuxX, m_AuxY, m_DrawExtent.cx, m_DrawExtent.cy)
                m_AuxOnDraw = False
        End If
        callTime = callTime + 1
        'frmMain.lblClearCall = callTime
End Function
Public Function Paint(Optional ByVal X As Single = -1, Optional ByVal Y As Single = -1) As Boolean
        Dim DOFX As Boolean
        Dim sceneDC As Long

        If m_OwnerText Is Nothing Then Exit Function
        sceneDC = m_OwnerText.hSceneDC
        Paint = True

        If X = -1 Then X = m_AuxX
        If Y = -1 Then Y = m_AuxY

        Paint = m_OwnerText.Save(X, Y, m_CharExtent.cx, m_CharExtent.cy)

        DOFX = True
        If DOFX Then
                ' 后端效果
                        'm_DrawPic.BackColor = BackColor And &HFFFFFF
                        If HasGradient Then
                                FIIA &HAAFF&
                                Paint = BitBltGradient(m_DrawPic.hdc, 0, 0, TextWidth - 1, TextHeight - 1, _
                                        GradientC1, GradientC2, Not GradientDirection)
                                FIIA &HFF&
                        End If
                        Paint = Paint And BitBltAlphaSimple( _
                                sceneDC, X, Y, TextWidth, TextHeight, m_DrawPic.hdc, 0, 0, _
                                dwShr(BackColor, 24))
                ' 文字输出
                        Dim IForeColor As Long, IBackColor As Long
                        IForeColor = ForeColor And &HFFFFFF
                        m_DrawPic.ForeColor = IForeColor
                        IBackColor = ForeColor Xor &HFFFFFF
                        BitBltColor m_DrawPic.hdc, 0, 0, TextWidth, TextHeight, IBackColor
                        TextOut m_DrawPic.hdc, 0, 0, m_Content, alen
                        m_DrawContent = m_Content
                        Paint = Paint And BitBltAlphaMerge( _
                                sceneDC, X, Y, TextWidth, TextHeight, _
                                m_DrawPic.hdc, 0, 0, _
                                dwShr(ForeColor, 24), IBackColor Or &H1000000)

                ' 前端效果

        Else
                TextOut frmMain.picBack.hdc, X, Y, m_Content, alen
        End If
        m_DrawExtent = m_CharExtent
End Function

Public Sub Destroy()
        ClearChar
        SetOwnerText Nothing, 0
End Sub

Private Sub sizeChanged()
        Exit Sub
        If m_OwnerText Is Nothing Then Exit Sub
        m_OwnerText.Changed m_CID
End Sub
Private Sub colorChanged()
        Exit Sub
        redraw
End Sub

Private Sub Class_Initialize()
        Set m_OwnerText = Nothing
        ' A
                Content = "EasyChar"

                m_FontName = "宋体"
                m_FontSize = 14
                m_FontBold = False
                m_FontItalic = False
                m_FontUnderline = False
                m_FontStrikethrough = False

                m_Break = False

        ' B
                m_ForeColor = &HFFFFFFFF
                m_BackColor = 0

                m_HasGradient = False
                m_GradientC1 = 0
                m_GradientC2 = 0
                m_GradientDirection = 0
                m_GradientLoop = 1

                m_AuxX = 0
                m_AuxY = 0
                m_AuxOnDraw = False

                m_LineSpace = 16

        If debugClass Then MsgBox "EasyChar " & Content & ": Class_Init"
End Sub
Private Sub Class_Terminate()
        If debugClass Then MsgBox "EasyChar " & Content & ": Class_Terminate"
End Sub
