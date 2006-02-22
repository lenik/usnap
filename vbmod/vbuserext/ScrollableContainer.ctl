VERSION 5.00
Begin VB.UserControl ScrollableContainer
   BackStyle       =   0  'Transparent
   ClientHeight    =   2070
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   2415
   ControlContainer=   -1  'True
   ScaleHeight     =   2070
   ScaleWidth      =   2415
   ToolboxBitmap   =   "ScrollableContainer.ctx":0000
   Begin VB.PictureBox FillCorner
      BorderStyle     =   0  'None
      Height          =   255
      Left            =   2100
      ScaleHeight     =   255
      ScaleWidth      =   255
      TabIndex        =   2
      TabStop         =   0   'False
      Top             =   1740
      Width           =   255
   End
   Begin VB.HScrollBar hs
      Height          =   255
      Left            =   0
      Min             =   -32767
      TabIndex        =   1
      TabStop         =   0   'False
      Top             =   1740
      Value           =   -32767
      Width           =   2115
   End
   Begin VB.VScrollBar vs
      Height          =   1755
      Left            =   2100
      Min             =   -32767
      TabIndex        =   0
      TabStop         =   0   'False
      Top             =   0
      Value           =   -32767
      Width           =   255
   End
End
Attribute VB_Name = "ScrollableContainer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBUserExt::ScrollableContainer"
Private Const MAXVAL                    As Single = 1E+38
Private Const SCROLL_MIN                As Single = -32767
Private Const SCROLL_MAX                As Single = 32767
Private Const DENOM_MIN                 As Single = 1#      ' avoid divide by zero

Private Const DEFAULT_STATICLAYOUT      As Boolean = True
Private Const DEFAULT_PADLEFT           As Single = 0
Private Const DEFAULT_PADTOP            As Single = 0
Private Const DEFAULT_PADRIGHT          As Single = 0
Private Const DEFAULT_PADBOTTOM         As Single = 0
Private Const DEFAULT_BORDERLEFT        As Single = MAXVAL  ' Freq. used value: 0
Private Const DEFAULT_BORDERTOP         As Single = MAXVAL  ' Freq. used value: 0
Private Const DEFAULT_BORDERRIGHT       As Single = -MAXVAL ' Freq. used value: ScaleWidth
Private Const DEFAULT_BORDERBOTTOM      As Single = -MAXVAL ' Freq. used value: ScaleHeight
Private Const DEFAULT_HSMALLCHANGE      As Single = 1
Private Const DEFAULT_HLARGECHANGE      As Single = 10
Private Const DEFAULT_VSMALLCHANGE      As Single = 1
Private Const DEFAULT_VLARGECHANGE      As Single = 10

Private m_StaticLayout As Boolean
Private m_PadLeft As Single
Private m_PadTop As Single
Private m_PadRight As Single
Private m_PadBottom As Single
Private m_BorderLeft As Single
Private m_BorderTop As Single
Private m_BorderRight As Single
Private m_BorderBottom As Single
Private m_HSmallChange As Single
Private m_HLargeChange As Single
Private m_VSmallChange As Single
Private m_VLargeChange As Single

Private m_ExtX0 As Single
Private m_ExtY0 As Single
Private m_ExtX1 As Single
Private m_ExtY1 As Single
Private m_RangeH As Single
Private m_RangeV As Single

Private m_EventLock As Integer

'Event Declarations:
Event Click() 'MappingInfo=UserControl,UserControl,-1,Click
Attribute Click.VB_Description = "Occurs when the user presses and then releases a mouse button over an object."
Event DblClick() 'MappingInfo=UserControl,UserControl,-1,DblClick
Attribute DblClick.VB_Description = "Occurs when the user presses and releases a mouse button and then presses and releases it again over an object."
Event KeyDown(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyDown
Attribute KeyDown.VB_Description = "Occurs when the user presses a key while an object has the focus."
Event KeyPress(KeyAscii As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyPress
Attribute KeyPress.VB_Description = "Occurs when the user presses and releases an ANSI key."
Event KeyUp(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyUp
Attribute KeyUp.VB_Description = "Occurs when the user releases a key while an object has the focus."
Event MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseDown
Attribute MouseDown.VB_Description = "Occurs when the user presses the mouse button while an object has the focus."
Event MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseMove
Attribute MouseMove.VB_Description = "Occurs when the user moves the mouse."
Event MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseUp
Attribute MouseUp.VB_Description = "Occurs when the user releases the mouse button while an object has the focus."

Private Sub LockEvent()
    m_EventLock = m_EventLock + 1
End Sub
Private Sub UnlockEvent()
    m_EventLock = m_EventLock - 1
    Assert m_EventLock >= 0, "Unlock without lock", LOCATION
End Sub

Private Property Get PosX() As Single
    PosX = (hs.Value - SCROLL_MIN) / (SCROLL_MAX - SCROLL_MIN)
    PosX = (PosX) * m_RangeH
End Property
Private Property Let PosX(ByVal newval As Single)
    If m_RangeH < DENOM_MIN Then Exit Property
    newval = (newval / m_RangeH) * (SCROLL_MAX - SCROLL_MIN) + SCROLL_MIN
    If newval < SCROLL_MIN Then newval = SCROLL_MIN
    If newval > SCROLL_MAX Then newval = SCROLL_MAX
    If hs.Value <> CInt(newval) Then
        LockEvent
        hs.Value = newval
        UnlockEvent
    End If
End Property
Private Property Get PosY() As Single
    PosY = (vs.Value - SCROLL_MIN) / (SCROLL_MAX - SCROLL_MIN)
    PosY = (PosY) * m_RangeV
End Property
Private Property Let PosY(ByVal newval As Single)
    If m_RangeV < DENOM_MIN Then Exit Property
    newval = (newval / m_RangeV) * (SCROLL_MAX - SCROLL_MIN) + SCROLL_MIN
    If newval < SCROLL_MIN Then newval = SCROLL_MIN
    If newval > SCROLL_MAX Then newval = SCROLL_MAX
    If vs.Value <> CInt(newval) Then
        LockEvent
        vs.Value = newval
        UnlockEvent
    End If
End Property

Private Property Get ViewPosX() As Single
    ViewPosX = -m_ExtX0
End Property
Private Property Get ViewPosY() As Single
    ViewPosY = -m_ExtY0
End Property

Private Sub UpdateScrollBars()
    On Error Resume Next
    Dim k As Single
    If hs.Visible Then
        hs.Top = ScaleHeight - hs.Height
        hs.Width = ScaleWidth - IIf(vs.Visible, vs.Width, 0)
        hs.ZOrder
    End If
    If vs.Visible Then
        vs.Left = ScaleWidth - vs.Width
        vs.Height = ScaleHeight - IIf(hs.Visible, hs.Height, 0)
        vs.ZOrder
    End If
    FillCorner.Visible = hs.Visible And vs.Visible
    If FillCorner.Visible Then
        FillCorner.Left = hs.Width
        FillCorner.Top = vs.Height
        FillCorner.ZOrder
    End If

    If m_RangeH > DENOM_MIN Then
        PosX = -m_ExtX0

        k = m_HSmallChange / m_RangeH * (SCROLL_MAX - SCROLL_MIN)
        If k < 1 Then k = 1
        If k > SCROLL_MAX Then k = SCROLL_MAX
        hs.SmallChange = k

        k = m_HLargeChange / m_RangeH * (SCROLL_MAX - SCROLL_MIN)
        If k < 1 Then k = 1
        If k > SCROLL_MAX Then k = SCROLL_MAX
        hs.LargeChange = k
    End If

    If m_RangeV > DENOM_MIN Then
        PosY = -m_ExtY0

        k = m_VSmallChange / m_RangeV * (SCROLL_MAX - SCROLL_MIN)
        If k < 1 Then k = 1
        If k > SCROLL_MAX Then k = SCROLL_MAX
        vs.SmallChange = k

        k = m_VLargeChange / m_RangeV * (SCROLL_MAX - SCROLL_MIN)
        If k < 1 Then k = 1
        If k > SCROLL_MAX Then k = SCROLL_MAX
        vs.LargeChange = k
    End If
End Sub

Private Sub GetBound(x0 As Single, y0 As Single, x1 As Single, y1 As Single)
    Dim ctrl As Object
    If ContainedControls.Count = 0 Then
        x0 = m_ExtX0
        y0 = m_ExtY0
        x1 = m_ExtX1
        y1 = m_ExtY1
    Else
        x0 = MAXVAL
        y0 = MAXVAL
        x1 = -MAXVAL
        y1 = -MAXVAL
        For Each ctrl In ContainedControls
            If ctrl.Left < x0 Then x0 = ctrl.Left
            If ctrl.Top < y0 Then y0 = ctrl.Top
            If ctrl.Left + ctrl.Width > x1 Then x1 = ctrl.Left + ctrl.Width
            If ctrl.Top + ctrl.Height > y1 Then y1 = ctrl.Top + ctrl.Height
        Next
        Assert x0 <> MAXVAL And y0 <> MAXVAL And x1 <> -MAXVAL And y1 <> -MAXVAL
    End If
End Sub

Public Sub RecalcBounds()
    Dim x0 As Single
    Dim y0 As Single
    Dim x1 As Single
    Dim y1 As Single
    Dim AddLeft As Single
    Dim AddTop As Single
    Dim AddRight As Single
    Dim AddBottom As Single
    GetBound x0, y0, x1, y1
    x0 = x0 - m_PadLeft
    y0 = y0 - m_PadTop
    x1 = x1 + m_PadTop
    y1 = y1 + m_PadBottom

    If x0 > 0 Then x0 = 0
    If y0 > 0 Then y0 = 0
    If x1 < ScaleWidth Then x1 = ScaleWidth
    If y1 < ScaleHeight Then y1 = ScaleHeight

    If x0 > m_BorderLeft Then AddRight = x0 - m_BorderLeft
    If y0 > m_BorderTop Then AddBottom = y0 - m_BorderTop
    If x1 < m_BorderRight Then AddLeft = m_BorderRight - x1
    If y1 < m_BorderBottom Then AddTop = m_BorderBottom - y1
    x0 = x0 - AddLeft
    y0 = y0 - AddTop
    x1 = x1 + AddRight
    y1 = y1 + AddBottom

    ' If not changed.
    If x0 = m_ExtX0 And y0 = m_ExtY0 And x1 = m_ExtX1 And y1 = m_ExtY1 Then Exit Sub

    ' Assert X1 - X0 >= ScaleWidth
    ' Assert Y1 - Y0 >= ScaleHeight
    m_RangeH = x1 - x0 - ScaleWidth
    m_RangeV = y1 - y0 - ScaleHeight
    ' Assert m_RangeH >= 0
    ' Assert m_RangeV >= 0

    hs.Visible = m_RangeH > 0
    vs.Visible = m_RangeV > 0

    m_ExtX0 = x0
    m_ExtY0 = y0
    m_ExtX1 = x1
    m_ExtY1 = y1

    UpdateScrollBars
End Sub

Private Sub Scroll()
    Dim deltaX As Single
    Dim deltaY As Single
    Dim ctrl As Object
    Dim updateScrollBar As Boolean

    deltaX = PosX - ViewPosX
    deltaY = PosY - ViewPosY

    If deltaX <> 0 Then
        For Each ctrl In ContainedControls
            ctrl.Left = ctrl.Left - deltaX
        Next
        updateScrollBar = True
    End If
    If deltaY <> 0 Then
        For Each ctrl In ContainedControls
            ctrl.Top = ctrl.Top - deltaY
        Next
        updateScrollBar = True
    End If
    If deltaX <> 0 Or deltaY <> 0 Then RecalcBounds
End Sub

Private Sub UserControl_Paint()
    If m_EventLock Then Exit Sub
    If m_StaticLayout And Ambient.UserMode Then Exit Sub
    RecalcBounds
End Sub

Private Sub UserControl_Resize()
    If m_EventLock Then Exit Sub
    RecalcBounds
End Sub

Private Sub hs_Change()
    If m_EventLock Then Exit Sub
    Scroll
End Sub
Private Sub hs_Scroll()
    If m_EventLock Then Exit Sub
    Scroll
End Sub
Private Sub vs_Change()
    If m_EventLock Then Exit Sub
    Scroll
End Sub
Private Sub vs_Scroll()
    If m_EventLock Then Exit Sub
    Scroll
End Sub

Public Property Get StaticLayout() As Boolean
    StaticLayout = m_StaticLayout
End Property
Public Property Let StaticLayout(ByVal newval As Boolean)
    m_StaticLayout = newval
End Property

Public Property Get PadLeft() As Single
    PadLeft = m_PadLeft
End Property
Public Property Let PadLeft(ByVal newval As Single)
    m_PadLeft = newval
    RecalcBounds
End Property
Public Property Get PadTop() As Single
    PadTop = m_PadTop
End Property
Public Property Let PadTop(ByVal newval As Single)
    m_PadTop = newval
    RecalcBounds
End Property
Public Property Get PadRight() As Single
    PadRight = m_PadRight
End Property
Public Property Let PadRight(ByVal newval As Single)
    m_PadRight = newval
    RecalcBounds
End Property
Public Property Get PadBottom() As Single
    PadBottom = m_PadBottom
End Property
Public Property Let PadBottom(ByVal newval As Single)
    m_PadBottom = newval
    RecalcBounds
End Property
Public Property Get BorderLeft() As Single
    BorderLeft = m_BorderLeft
End Property
Public Property Let BorderLeft(ByVal newval As Single)
    m_BorderLeft = newval
    RecalcBounds
End Property
Public Property Get BorderTop() As Single
    BorderTop = m_BorderTop
End Property
Public Property Let BorderTop(ByVal newval As Single)
    m_BorderTop = newval
    RecalcBounds
End Property
Public Property Get BorderRight() As Single
    BorderRight = m_BorderRight
End Property
Public Property Let BorderRight(ByVal newval As Single)
    m_BorderRight = newval
    RecalcBounds
End Property
Public Property Get BorderBottom() As Single
    BorderBottom = m_BorderBottom
End Property
Public Property Let BorderBottom(ByVal newval As Single)
    m_BorderBottom = newval
    RecalcBounds
End Property

Public Property Get HSmallChange() As Single
    HSmallChange = m_HSmallChange
End Property
Public Property Let HSmallChange(ByVal newval As Single)
    m_HSmallChange = newval
    UpdateScrollBars
End Property
Public Property Get HLargeChange() As Single
    HLargeChange = m_HLargeChange
End Property
Public Property Let HLargeChange(ByVal newval As Single)
    m_HLargeChange = newval
    UpdateScrollBars
End Property
Public Property Get VSmallChange() As Single
    VSmallChange = m_VSmallChange
End Property
Public Property Let VSmallChange(ByVal newval As Single)
    m_VSmallChange = newval
    UpdateScrollBars
End Property
Public Property Get VLargeChange() As Single
    VLargeChange = m_VLargeChange
End Property
Public Property Let VLargeChange(ByVal newval As Single)
    m_VLargeChange = newval
    UpdateScrollBars
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ActiveControl
Public Property Get ActiveControl() As Object
Attribute ActiveControl.VB_Description = "Returns the control that has focus."
    Set ActiveControl = UserControl.ActiveControl
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Appearance
Public Property Get Appearance() As Integer
Attribute Appearance.VB_Description = "Returns/sets whether or not an object is painted at run time with 3-D effects."
    Appearance = UserControl.Appearance
End Property

Public Property Let Appearance(ByVal New_Appearance As Integer)
    UserControl.Appearance() = New_Appearance
    PropertyChanged "Appearance"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,BackColor
Public Property Get BackColor() As OLE_COLOR
Attribute BackColor.VB_Description = "Returns/sets the background color used to display text and graphics in an object."
    BackColor = UserControl.BackColor
End Property

Public Property Let BackColor(ByVal New_BackColor As OLE_COLOR)
    UserControl.BackColor() = New_BackColor
    PropertyChanged "BackColor"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,BackStyle
Public Property Get BackStyle() As Integer
Attribute BackStyle.VB_Description = "Indicates whether a Label or the background of a Shape is transparent or opaque."
    BackStyle = UserControl.BackStyle
End Property

Public Property Let BackStyle(ByVal New_BackStyle As Integer)
    UserControl.BackStyle() = New_BackStyle
    PropertyChanged "BackStyle"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,BorderStyle
Public Property Get BorderStyle() As Integer
Attribute BorderStyle.VB_Description = "Returns/sets the border style for an object."
    BorderStyle = UserControl.BorderStyle
End Property

Public Property Let BorderStyle(ByVal New_BorderStyle As Integer)
    UserControl.BorderStyle() = New_BorderStyle
    PropertyChanged "BorderStyle"
End Property

Private Sub UserControl_Click()
    'If m_EventLock Then Exit Sub
    RaiseEvent Click
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Controls
Public Property Get Controls() As Object
Attribute Controls.VB_Description = "A collection whose elements represent each control on a form, including elements of control arrays. "
    Set Controls = UserControl.Controls
End Property

Private Sub UserControl_DblClick()
    'If m_EventLock Then Exit Sub
    RaiseEvent DblClick
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Enabled
Public Property Get Enabled() As Boolean
Attribute Enabled.VB_Description = "Returns/sets a value that determines whether an object can respond to user-generated events."
    Enabled = UserControl.Enabled
End Property

Public Property Let Enabled(ByVal New_Enabled As Boolean)
    UserControl.Enabled() = New_Enabled
    PropertyChanged "Enabled"
End Property

Private Sub UserControl_KeyDown(KeyCode As Integer, Shift As Integer)
    'If m_EventLock Then Exit Sub
    RaiseEvent KeyDown(KeyCode, Shift)
End Sub

Private Sub UserControl_KeyPress(KeyAscii As Integer)
    'If m_EventLock Then Exit Sub
    RaiseEvent KeyPress(KeyAscii)
End Sub

Private Sub UserControl_KeyUp(KeyCode As Integer, Shift As Integer)
    'If m_EventLock Then Exit Sub
    RaiseEvent KeyUp(KeyCode, Shift)
End Sub

Private Sub UserControl_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    'If m_EventLock Then Exit Sub
    RaiseEvent MouseDown(Button, Shift, x, y)
End Sub


'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,MouseIcon
Public Property Get MouseIcon() As Picture
Attribute MouseIcon.VB_Description = "Sets a custom mouse icon."
    Set MouseIcon = UserControl.MouseIcon
End Property

Public Property Set MouseIcon(ByVal New_MouseIcon As Picture)
    Set UserControl.MouseIcon = New_MouseIcon
    PropertyChanged "MouseIcon"
End Property

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
    'If m_EventLock Then Exit Sub
    'Parent.Caption = X & "," & Y
    RaiseEvent MouseMove(Button, Shift, x, y)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,MousePointer
Public Property Get MousePointer() As Integer
Attribute MousePointer.VB_Description = "Returns/sets the type of mouse pointer displayed when over part of an object."
    MousePointer = UserControl.MousePointer
End Property

Public Property Let MousePointer(ByVal New_MousePointer As Integer)
    UserControl.MousePointer() = New_MousePointer
    PropertyChanged "MousePointer"
End Property

Private Sub UserControl_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
    'If m_EventLock Then Exit Sub
    RaiseEvent MouseUp(Button, Shift, x, y)
End Sub

Private Sub UserControl_InitProperties()
    m_StaticLayout = DEFAULT_STATICLAYOUT
    m_PadLeft = DEFAULT_PADLEFT
    m_PadTop = DEFAULT_PADTOP
    m_PadRight = DEFAULT_PADRIGHT
    m_PadBottom = DEFAULT_PADBOTTOM
    m_BorderLeft = DEFAULT_BORDERLEFT
    m_BorderTop = DEFAULT_BORDERTOP
    m_BorderRight = DEFAULT_BORDERRIGHT
    m_BorderBottom = DEFAULT_BORDERBOTTOM
    m_HSmallChange = UserControl.ScaleX(DEFAULT_HSMALLCHANGE, vbPixels, UserControl.ScaleMode)
    m_HLargeChange = UserControl.ScaleX(DEFAULT_HLARGECHANGE, vbPixels, UserControl.ScaleMode)
    m_VSmallChange = UserControl.ScaleY(DEFAULT_VSMALLCHANGE, vbPixels, UserControl.ScaleMode)
    m_VLargeChange = UserControl.ScaleY(DEFAULT_VLARGECHANGE, vbPixels, UserControl.ScaleMode)
    m_ExtX0 = 0
    m_ExtY0 = 0
    m_ExtX1 = ScaleWidth
    m_ExtY1 = ScaleHeight
End Sub

'Load property values from storage
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    m_StaticLayout = PropBag.ReadProperty("StaticLayout", DEFAULT_STATICLAYOUT)
    m_PadLeft = PropBag.ReadProperty("PadLeft", DEFAULT_PADLEFT)
    m_PadTop = PropBag.ReadProperty("PadTop", DEFAULT_PADTOP)
    m_PadRight = PropBag.ReadProperty("PadRight", DEFAULT_PADRIGHT)
    m_PadBottom = PropBag.ReadProperty("PadBottom", DEFAULT_PADBOTTOM)
    m_BorderLeft = PropBag.ReadProperty("BorderLeft", DEFAULT_BORDERLEFT)
    m_BorderTop = PropBag.ReadProperty("BorderTop", DEFAULT_BORDERTOP)
    m_BorderRight = PropBag.ReadProperty("BorderRight", DEFAULT_BORDERRIGHT)
    m_BorderBottom = PropBag.ReadProperty("BorderBottom", DEFAULT_BORDERBOTTOM)
    m_HSmallChange = PropBag.ReadProperty("HSmallChange", UserControl.ScaleX(DEFAULT_HSMALLCHANGE, vbPixels, UserControl.ScaleMode))
    m_HLargeChange = PropBag.ReadProperty("HLargeChange", UserControl.ScaleX(DEFAULT_HLARGECHANGE, vbPixels, UserControl.ScaleMode))
    m_VSmallChange = PropBag.ReadProperty("VSmallChange", UserControl.ScaleY(DEFAULT_VSMALLCHANGE, vbPixels, UserControl.ScaleMode))
    m_VLargeChange = PropBag.ReadProperty("VLargeChange", UserControl.ScaleY(DEFAULT_VLARGECHANGE, vbPixels, UserControl.ScaleMode))
    m_ExtX0 = PropBag.ReadProperty("ExtX0", 0)
    m_ExtY0 = PropBag.ReadProperty("ExtY0", 0)
    m_ExtX1 = PropBag.ReadProperty("ExtX1", ScaleWidth)
    m_ExtY1 = PropBag.ReadProperty("ExtY1", ScaleHeight)

    UserControl.Appearance = PropBag.ReadProperty("Appearance", 1)
    UserControl.BackColor = PropBag.ReadProperty("BackColor", &H8000000F)
    UserControl.BackStyle = PropBag.ReadProperty("BackStyle", 1)
    UserControl.BorderStyle = PropBag.ReadProperty("BorderStyle", 0)
    UserControl.Enabled = PropBag.ReadProperty("Enabled", True)
    Set MouseIcon = PropBag.ReadProperty("MouseIcon", Nothing)
    UserControl.MousePointer = PropBag.ReadProperty("MousePointer", 0)
End Sub

'Write property values to storage
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    Call PropBag.WriteProperty("StaticLayout", m_StaticLayout, DEFAULT_STATICLAYOUT)
    Call PropBag.WriteProperty("PadLeft", m_PadLeft, DEFAULT_PADLEFT)
    Call PropBag.WriteProperty("PadTop", m_PadTop, DEFAULT_PADTOP)
    Call PropBag.WriteProperty("PadRight", m_PadRight, DEFAULT_PADRIGHT)
    Call PropBag.WriteProperty("PadBottom", m_PadBottom, DEFAULT_PADBOTTOM)
    Call PropBag.WriteProperty("BorderLeft", m_BorderLeft, DEFAULT_BORDERLEFT)
    Call PropBag.WriteProperty("BorderTop", m_BorderTop, DEFAULT_BORDERTOP)
    Call PropBag.WriteProperty("BorderRight", m_BorderRight, DEFAULT_BORDERRIGHT)
    Call PropBag.WriteProperty("BorderBottom", m_BorderBottom, DEFAULT_BORDERBOTTOM)
    Call PropBag.WriteProperty("HSmallChange", m_HSmallChange, UserControl.ScaleX(DEFAULT_VSMALLCHANGE, vbPixels, UserControl.ScaleMode))
    Call PropBag.WriteProperty("HLargeChange", m_HLargeChange, UserControl.ScaleX(DEFAULT_HLARGECHANGE, vbPixels, UserControl.ScaleMode))
    Call PropBag.WriteProperty("VSmallChange", m_VSmallChange, UserControl.ScaleY(DEFAULT_VSMALLCHANGE, vbPixels, UserControl.ScaleMode))
    Call PropBag.WriteProperty("VLargeChange", m_VLargeChange, UserControl.ScaleY(DEFAULT_VLARGECHANGE, vbPixels, UserControl.ScaleMode))
    Call PropBag.WriteProperty("ExtX0", m_ExtX0, 0)
    Call PropBag.WriteProperty("ExtY0", m_ExtY0, 0)
    Call PropBag.WriteProperty("ExtX1", m_ExtX1, ScaleWidth)
    Call PropBag.WriteProperty("ExtY1", m_ExtY1, ScaleHeight)

    Call PropBag.WriteProperty("Appearance", UserControl.Appearance, 1)
    Call PropBag.WriteProperty("BackColor", UserControl.BackColor, &H8000000F)
    Call PropBag.WriteProperty("BackStyle", UserControl.BackStyle, 1)
    Call PropBag.WriteProperty("BorderStyle", UserControl.BorderStyle, 0)
    Call PropBag.WriteProperty("Enabled", UserControl.Enabled, True)
    Call PropBag.WriteProperty("MouseIcon", MouseIcon, Nothing)
    Call PropBag.WriteProperty("MousePointer", UserControl.MousePointer, 0)
End Sub
