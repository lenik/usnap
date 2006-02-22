VERSION 5.00
Begin VB.UserControl AuxiliaryShape
   BackStyle       =   0  'Transparent
   CanGetFocus     =   0   'False
   ClientHeight    =   1290
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1380
   ScaleHeight     =   1290
   ScaleWidth      =   1380
   ToolboxBitmap   =   "AuxiliaryShape.ctx":0000
   Begin VB.Shape Body
      Height          =   615
      Left            =   360
      Top             =   420
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Shape ControlBox
      Height          =   195
      Index           =   3
      Left            =   540
      Top             =   60
      Visible         =   0   'False
      Width           =   195
   End
   Begin VB.Shape ControlBox
      Height          =   195
      Index           =   2
      Left            =   780
      Top             =   60
      Visible         =   0   'False
      Width           =   195
   End
   Begin VB.Shape ControlBox
      Height          =   195
      Index           =   1
      Left            =   60
      Top             =   60
      Visible         =   0   'False
      Width           =   195
   End
   Begin VB.Shape ControlBox
      Height          =   195
      Index           =   0
      Left            =   300
      Top             =   60
      Visible         =   0   'False
      Width           =   195
   End
End
Attribute VB_Name = "AuxiliaryShape"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
' TODO
'   - can't move the control itself (change .left/.top properties)
'   - the hDC of windowless control is useless.

Option Explicit
Option Base 0

Public Enum AuxiliaryShapeConstants
    shapePoint = 0                      ' 1-cb (control-box)
    shapeHorizontalLine                 ' 1-cb cover the line
    shapeVerticalLine                   ' 1-cb cover the line
    shapeLine                           ' 2-cb
    shapeRectangle                      ' 4-cb of corners
    shapeOval                           ' 4-cb of corners of bounding box
    shapeCircle                         ' 4-cb of corners of bounding box
End Enum

Public Enum BoxSizeConstants
    boxsizeMedium = 0
    boxsizeSmall
    boxsizeLarge
End Enum

Private Const LOCATION                  As String = "VBUserExt::AuxiliaryShape"
Private Const MAX_CONTROL_BOX           As Integer = 3
Private Const BOX_POINT                 As Integer = 0
Private Const BOX_HLINE                 As Integer = 0
Private Const BOX_VLINE                 As Integer = 0
Private Const BOX_LINE_S                As Integer = 0
Private Const BOX_LINE_E                As Integer = 1
Private Const BOX_RECT_LT               As Integer = 0
Private Const BOX_RECT_RB               As Integer = 1
Private Const BOX_OVAL_LT               As Integer = 0
Private Const BOX_OVAL_RB               As Integer = 1
Private Const BOX_CIRCLE_C              As Integer = 0
Private Const BOX_CIRCLE_R              As Integer = 1
Private Const BOXSIZE_SMALL             As Integer = 3
Private Const BOXSIZE_MEDIUM            As Integer = 5
Private Const BOXSIZE_LARGE             As Integer = 10

Private Const HIT_NONE                  As Integer = -1

Private Const POINT_SIZE                As Single = 3
Private Const HLINE_SIZE                As Single = 1
Private Const VLINE_SIZE                As Single = 1

Private Const DEFAULT_SHAPE             As Integer = shapeRectangle
Private Const DEFAULT_BOXSIZE           As Integer = boxsizeMedium

Private m_Shape As AuxiliaryShapeConstants
Private m_BoxSize As Single             ' ScaleMode dependent
'Private m_BoxX(MAX_CONTROL_BOX) As Single
'Private m_BoxY(MAX_CONTROL_BOX) As Single
Private m_DownIndex As Integer
Private m_DownX As Single
Private m_DownY As Single

Public Property Get Shape() As AuxiliaryShapeConstants
    Shape = m_Shape
End Property
Public Property Let Shape(ByVal newval As AuxiliaryShapeConstants)
    m_Shape = newval

    Dim boxes As Integer
    Select Case m_Shape
    Case shapePoint
        boxes = 1
        Body.Shape = vbShapeCircle
        Body.Width = POINT_SIZE
        Body.Height = POINT_SIZE
    Case shapeHorizontalLine
        boxes = 2
        Body.Shape = vbShapeRectangle
        Body.Height = HLINE_SIZE
        Body.Left = m_BoxSize
    Case shapeVerticalLine
        boxes = 2
        Body.Shape = vbShapeRectangle
        Body.Width = VLINE_SIZE
        Body.Top = m_BoxSize
    Case shapeLine
        boxes = 2
        Body.Shape = vbShapeRectangle   ' TODO...
    Case shapeRectangle
        boxes = 2
        Body.Shape = vbShapeRectangle
    Case shapeOval
        boxes = 2
        Body.Shape = vbShapeOval
    Case shapeCircle
        boxes = 2
        Body.Shape = vbShapeCircle
    End Select

    Dim i As Integer
    For i = 0 To MAX_CONTROL_BOX
        ControlBox(i).Visible = i < boxes
    Next

    RefreshBody
End Property

Public Property Get BoxSize() As BoxSizeConstants
    Dim pixsize As Integer
    pixsize = PixelX(m_BoxSize)
    If pixsize <= BOXSIZE_SMALL Then
        BoxSize = boxsizeSmall
    ElseIf pixsize <= BOXSIZE_MEDIUM Then
        BoxSize = boxsizeMedium
    Else
        BoxSize = boxsizeLarge
    End If
End Property
Public Property Let BoxSize(ByVal newval As BoxSizeConstants)
    Dim pixsize As Integer
    Select Case newval
    Case boxsizeSmall
        pixsize = BOXSIZE_SMALL
    Case boxsizeMedium
        pixsize = BOXSIZE_MEDIUM
    Case boxsizeLarge
        pixsize = BOXSIZE_LARGE
    End Select
    m_BoxSize = UserControl.ScaleX(pixsize, vbPixels, UserControl.ScaleMode)
    UserControl.Refresh
End Property

Private Property Get m_BoxX(ByVal index As Integer) As Single
    m_BoxX = ControlBox(index).Left + ControlBox(index).Width / 2
End Property
Private Property Let m_BoxX(ByVal index As Integer, ByVal newval As Single)
    ControlBox(index).Left = newval - ControlBox(index).Width / 2
End Property
Private Property Get m_BoxY(ByVal index As Integer) As Single
    m_BoxY = ControlBox(index).Top + ControlBox(index).Height / 2
End Property
Private Property Let m_BoxY(ByVal index As Integer, ByVal newval As Single)
    ControlBox(index).Top = newval - ControlBox(index).Height / 2
End Property

Private Property Get PointX() As Single:                PointX = m_BoxX(BOX_POINT):     End Property
Private Property Get PointY() As Single:                PointY = m_BoxY(BOX_POINT):     End Property
Private Property Let PointX(ByVal newval As Single):    m_BoxX(BOX_POINT) = newval:     End Property
Private Property Let PointY(ByVal newval As Single):    m_BoxY(BOX_POINT) = newval:     End Property
Private Property Get HLineY() As Single:                HLineY = m_BoxY(BOX_HLINE):     End Property
Private Property Let HLineY(ByVal newval As Single):    m_BoxY(BOX_HLINE) = newval:     End Property
Private Property Get VLineX() As Single:                VLineX = m_BoxX(BOX_VLINE):     End Property
Private Property Let VLineX(ByVal newval As Single):    m_BoxX(BOX_VLINE) = newval:     End Property
Private Property Get LineSX() As Single:                LineSX = m_BoxX(BOX_LINE_S):    End Property
Private Property Get LineSY() As Single:                LineSY = m_BoxY(BOX_LINE_S):    End Property
Private Property Let LineSX(ByVal newval As Single):    m_BoxX(BOX_LINE_S) = newval:    End Property
Private Property Let LineSY(ByVal newval As Single):    m_BoxY(BOX_LINE_S) = newval:    End Property
Private Property Get LineEX() As Single:                LineEX = m_BoxX(BOX_LINE_E):    End Property
Private Property Get LineEY() As Single:                LineEY = m_BoxY(BOX_LINE_E):    End Property
Private Property Let LineEX(ByVal newval As Single):    m_BoxX(BOX_LINE_E) = newval:    End Property
Private Property Let LineEY(ByVal newval As Single):    m_BoxY(BOX_LINE_E) = newval:    End Property
Private Property Get RectLTX() As Single:               RectLTX = m_BoxX(BOX_RECT_LT):  End Property
Private Property Get RectLTY() As Single:               RectLTY = m_BoxY(BOX_RECT_LT):  End Property
Private Property Let RectLTX(ByVal newval As Single):   m_BoxX(BOX_RECT_LT) = newval:   End Property
Private Property Let RectLTY(ByVal newval As Single):   m_BoxY(BOX_RECT_LT) = newval:   End Property
Private Property Get RectRBX() As Single:               RectRBX = m_BoxX(BOX_RECT_RB):  End Property
Private Property Get RectRBY() As Single:               RectRBY = m_BoxY(BOX_RECT_RB):  End Property
Private Property Let RectRBX(ByVal newval As Single):   m_BoxX(BOX_RECT_RB) = newval:   End Property
Private Property Let RectRBY(ByVal newval As Single):   m_BoxY(BOX_RECT_RB) = newval:   End Property
Private Property Get OvalLTX() As Single:               OvalLTX = m_BoxX(BOX_OVAL_LT):  End Property
Private Property Get OvalLTY() As Single:               OvalLTY = m_BoxY(BOX_OVAL_LT):  End Property
Private Property Let OvalLTX(ByVal newval As Single):   m_BoxX(BOX_OVAL_LT) = newval:   End Property
Private Property Let OvalLTY(ByVal newval As Single):   m_BoxY(BOX_OVAL_LT) = newval:   End Property
Private Property Get OvalRBX() As Single:               OvalRBX = m_BoxX(BOX_OVAL_RB):  End Property
Private Property Get OvalRBY() As Single:               OvalRBY = m_BoxY(BOX_OVAL_RB):  End Property
Private Property Let OvalRBX(ByVal newval As Single):   m_BoxX(BOX_OVAL_RB) = newval:   End Property
Private Property Let OvalRBY(ByVal newval As Single):   m_BoxY(BOX_OVAL_RB) = newval:   End Property
Private Property Get CircleCX() As Single:              CircleCX = m_BoxX(BOX_CIRCLE_C): End Property
Private Property Get CircleCY() As Single:              CircleCY = m_BoxY(BOX_CIRCLE_C): End Property
Private Property Let CircleCX(ByVal newval As Single):  m_BoxX(BOX_CIRCLE_C) = newval:  End Property
Private Property Let CircleCY(ByVal newval As Single):  m_BoxY(BOX_CIRCLE_C) = newval:  End Property
Private Property Get CircleRX() As Single:              CircleRX = m_BoxX(BOX_CIRCLE_R): End Property
Private Property Get CircleRY() As Single:              CircleRY = m_BoxY(BOX_CIRCLE_R): End Property
Private Property Let CircleRX(ByVal newval As Single):  m_BoxX(BOX_CIRCLE_R) = newval:  End Property
Private Property Let CircleRY(ByVal newval As Single):  m_BoxY(BOX_CIRCLE_R) = newval:  End Property

Private Function EucDist(ByVal x0 As Single, ByVal y0 As Single, ByVal x1 As Single, ByVal y1 As Single) As Single
    EucDist = Sqr((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1))
End Function

Private Function Min(x As Single, y As Single)
    Min = IIf(x < y, x, y)
End Function
Private Function Max(x As Single, y As Single)
    Max = IIf(x > y, x, y)
End Function

Private Function RightDist(ByVal x0 As Single, ByVal y0 As Single, ByVal x1 As Single, ByVal y1 As Single) As Single
    RightDist = Max(Abs(x0 - x1), Abs(y0 - y1))
End Function

Private Function HTAnd(ByVal a As Integer, ByVal b As Integer)
    Select Case a
    Case vbHitResultOutside
        HTAnd = vbHitResultOutside
    Case vbHitResultClose
        If b = vbHitResultOutside Then
            HTAnd = vbHitResultOutside
        Else
            HTAnd = vbHitResultClose
        End If
    Case vbHitResultTransparent
        If b = vbHitResultOutside Then
            HTAnd = vbHitResultOutside
        ElseIf b = vbHitResultClose Then
            HTAnd = vbHitResultClose
        Else
            HTAnd = vbHitResultTransparent
        End If
    Case vbHitResultHit
        HTAnd = b
    End Select
End Function

Private Function HTOr(ByVal a As Integer, ByVal b As Integer)
    Select Case a
    Case vbHitResultOutside
        HTOr = b
    Case vbHitResultClose
        If b = vbHitResultHit Then
            HTOr = vbHitResultHit
        ElseIf b = vbHitResultTransparent Then
            HTOr = vbHitResultTransparent
        Else
            HTOr = vbHitResultClose
        End If
    Case vbHitResultTransparent
        If b = vbHitResultHit Then
            HTOr = vbHitResultHit
        Else
            HTOr = vbHitResultTransparent
        End If
    Case vbHitResultHit
        HTOr = vbHitResultHit
    End Select
End Function

Private Function HitObject(x As Single, y As Single) As Integer
    HitObject = HIT_NONE
    Select Case m_Shape
    Case shapePoint
        If RightDist(x, y, PointX, PointY) < m_BoxSize Then HitObject = BOX_POINT
    Case shapeHorizontalLine
        If Abs(y - HLineY) < m_BoxSize Then
            If Abs(x - m_BoxSize) < m_BoxSize And Abs(x - (ScaleWidth - m_BoxSize) < m_BoxSize) Then
                HitObject = BOX_HLINE
            End If
        End If
    Case shapeVerticalLine
        If Abs(x - VLineX) < m_BoxSize Then
            If Abs(y - m_BoxSize) < m_BoxSize And Abs(y - (ScaleHeight - m_BoxSize) < m_BoxSize) Then
                HitObject = BOX_VLINE
            End If
        End If
    Case shapeLine
        If RightDist(x, y, LineSX, LineSY) < m_BoxSize Then
            HitObject = BOX_LINE_S
        ElseIf RightDist(x, y, LineEX, LineEY) < m_BoxSize Then
            HitObject = BOX_LINE_E
        End If
    Case shapeRectangle
        If RightDist(x, y, RectLTX, RectLTY) < m_BoxSize Then
            HitObject = BOX_RECT_LT
        ElseIf RightDist(x, y, RectRBX, RectRBY) < m_BoxSize Then
            HitObject = BOX_RECT_RB
        End If
    Case shapeOval
        If RightDist(x, y, OvalLTX, OvalLTY) < m_BoxSize Then
            HitObject = BOX_OVAL_LT
        ElseIf RightDist(x, y, OvalRBX, OvalRBY) < m_BoxSize Then
            HitObject = BOX_OVAL_RB
        End If
    Case shapeCircle
        If RightDist(x, y, CircleCX, CircleCY) < m_BoxSize Then
            HitObject = BOX_CIRCLE_C
        ElseIf RightDist(x, y, CircleRX, CircleRY) < m_BoxSize Then
            HitObject = BOX_CIRCLE_R
        End If
    End Select
End Function

Private Sub UserControl_HitTest(x As Single, y As Single, HitResult As Integer)
    If HitObject(x, y) <> HIT_NONE Then
        HitResult = vbHitResultOutside
    Else
        HitResult = vbHitResultHit
    End If
End Sub

Private Sub UserControl_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    Dim hit As Integer
    hit = HitObject(x, y)
    If hit = HIT_NONE Then Exit Sub
    m_DownIndex = hit
    m_DownX = x - m_BoxX(m_DownIndex)
    m_DownY = y - m_BoxY(m_DownIndex)
End Sub

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
    If m_DownIndex = HIT_NONE Then Exit Sub
    Dim RelX As Single
    Dim RelY As Single
    RelX = x - m_BoxX(m_DownIndex)
    RelY = y - m_BoxY(m_DownIndex)
    m_BoxX(m_DownIndex) = m_BoxX(m_DownIndex) + (RelX - m_DownX)
    m_BoxY(m_DownIndex) = m_BoxY(m_DownIndex) + (RelY - m_DownY)
End Sub

Private Sub UserControl_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
    m_DownIndex = HIT_NONE
End Sub

Private Function PixelX(ByVal scaled As Single) As Integer
    PixelX = ScaleX(scaled, UserControl.ScaleMode, vbPixels)
End Function
Private Function PixelY(ByVal scaled As Single) As Integer
    PixelY = ScaleY(scaled, UserControl.ScaleMode, vbPixels)
End Function

Private Sub RefreshBody()
    Select Case m_Shape
    Case shapePoint
        'DrawBox PointX, PointY
        Body.Left = PointX - Body.Width / 2
        Body.Top = PointY - Body.Height / 2
    Case shapeHorizontalLine
        'DrawBox m_BoxSize, HLineY
        'DrawBox ScaleWidth - m_BoxSize, HLineY
        Body.Top = HLineY - Body.Height / 2
        Body.Width = Max(ScaleWidth - Body.Left * 2, 0)
    Case shapeVerticalLine
        'DrawBox VLineX, m_BoxSize
        'DrawBox VLineX, ScaleHeight - m_BoxSize
        Body.Left = VLineX - Body.Width / 2
        Body.Height = Max(ScaleHeight - Body.Top * 2, 0)
    Case shapeLine
        'DrawBox LineSX, LineSY
        'DrawBox LineEX, LineEY
        Body.Left = LineSX
        Body.Top = LineSY
        Body.Width = Max(LineEX - LineSX, 0)
        Body.Height = Max(LineEY - LineSY, 0)
    Case shapeRectangle
        'DrawBox RectLTX, RectLTY
        'DrawBox RectRBX, RectRBY
        Body.Left = RectLTX
        Body.Top = RectLTY
        Body.Width = Max(RectRBX - RectLTX, 0)
        Body.Height = Max(RectRBY - RectLTY, 0)
    Case shapeOval
        'DrawBox OvalLTX, OvalLTY
        'DrawBox OvalRBX, OvalRBY
        Body.Left = OvalLTX
        Body.Top = OvalLTY
        Body.Width = Max(OvalRBX - OvalLTX, 0)
        Body.Height = Max(OvalRBY - OvalLTY, 0)
    Case shapeCircle
        'DrawBox CircleCX, CircleCY
        'DrawBox CircleRX, CircleRY
        Dim r As Single
        r = EucDist(CircleCX, CircleCY, CircleRX, CircleRY)
        Body.Left = CircleCX - r
        Body.Top = CircleCY - r
        Body.Width = 2 * r
        Body.Height = 2 * r
    End Select
End Sub

Private Sub UserControl_Resize()
    Select Case m_Shape
    Case shapePoint
        PointX = ScaleWidth / 2
        PointY = ScaleHeight / 2
    Case shapeHorizontalLine
        HLineY = ScaleHeight / 2
    Case shapeVerticalLine
        VLineX = ScaleWidth / 2
    Case shapeLine
        LineSX = Min(m_BoxSize, ScaleWidth)
        LineSY = Min(m_BoxSize, ScaleHeight)
        LineEX = Max(ScaleWidth - m_BoxSize, ScaleWidth)
        LineEY = Max(ScaleHeight - m_BoxSize, ScaleHeight)
    Case shapeRectangle
        RectLTX = Min(m_BoxSize, ScaleWidth)
        RectLTY = Min(m_BoxSize, ScaleHeight)
        RectRBX = Max(ScaleWidth - m_BoxSize, ScaleWidth)
        RectRBY = Max(ScaleHeight - m_BoxSize, ScaleHeight)
    Case shapeOval
        OvalLTX = Min(m_BoxSize, ScaleWidth)
        OvalLTY = Min(m_BoxSize, ScaleHeight)
        OvalRBX = Max(ScaleWidth - m_BoxSize, ScaleWidth)
        OvalRBY = Max(ScaleHeight - m_BoxSize, ScaleHeight)
    Case shapeCircle
        CircleCX = ScaleWidth / 2
        CircleCY = ScaleHeight / 2
        CircleRX = Min(CircleCX + Min(CircleCX, CircleCY), ScaleWidth)
        CircleRY = CircleCY
    End Select
    RefreshBody
End Sub

Private Sub UserControl_InitProperties()
    Shape = DEFAULT_SHAPE
    BoxSize = DEFAULT_BOXSIZE
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    Dim i As Integer
    For i = 0 To MAX_CONTROL_BOX
        m_BoxX(i) = PropBag.ReadProperty("BoxX_" & i, 0)
        m_BoxY(i) = PropBag.ReadProperty("BoxY_" & i, 0)
    Next
    Shape = PropBag.ReadProperty("Shape", DEFAULT_SHAPE)
    BoxSize = PropBag.ReadProperty("BoxSize", DEFAULT_BOXSIZE)
End Sub

Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    Dim i As Integer
    For i = 0 To MAX_CONTROL_BOX
        PropBag.WriteProperty "BoxX_" & i, m_BoxX(i), 0
        PropBag.WriteProperty "BoxY_" & i, m_BoxY(i), 0
    Next
    PropBag.WriteProperty "Shape", Shape, DEFAULT_SHAPE
    PropBag.WriteProperty "BoxSize", BoxSize, DEFAULT_BOXSIZE
End Sub
