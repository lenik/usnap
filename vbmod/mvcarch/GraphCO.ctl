VERSION 5.00
Begin VB.UserControl GraphCO
   AutoRedraw      =   -1  'True
   ClientHeight    =   3600
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4800
   ControlContainer=   -1  'True
   EditAtDesignTime=   -1  'True
   InvisibleAtRuntime=   -1  'True
   ScaleHeight     =   3600
   ScaleWidth      =   4800
   ToolboxBitmap   =   "GraphCO.ctx":0000
End
Attribute VB_Name = "GraphCO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION = "MVCArch::GraphCO"

Private m_Context As Object
Private m_kCmd As New SAOT

Implements ControllerObject
Private WithEvents m_Impl As BasicCO
Attribute m_Impl.VB_VarHelpID = -1

Public Event Started(InitState As GraphSO)
Public Event Ended(ByVal LastState As GraphSO)
Public Event Enter(ByVal PreviousState As GraphSO, ByVal CurrentState As GraphSO)
Public Event Leave(ByVal CurrentState As GraphSO, NextState As GraphSO)

'
' <Favorite Box Copy>
'
Private Const MARGIN = 1
Private Const BORDER = 1
Private Const SHAPE_SIZE = 10
Private Const SHAPE_PAD = 2
Private Const TITLE_PAD = 5

Private Const DEFAULT_COLLAPSED = False
Private Const DEFAULT_TITLE = "Controller"
Private Const DEFAULT_EXPANDEDWIDTH = 100
Private Const DEFAULT_EXPANDEDHEIGHT = 100

Private m_Collapsed As Boolean
Private m_Title As String
Private m_TitleLen As Long

Private m_ExpandedWidth As Single
Private m_ExpandedHeight As Single
Private m_CollapsedWidth As Single
Private m_CollapsedHeight As Single

Private m_ShapeCollapsed(0 To 3) As POINTL
Private m_ShapeExpanded(0 To 3) As POINTL
' private m_Inverted As Boolean

Private Declare Function strlen Lib "kernel32" Alias "lstrlenA" (ByVal Str As String) As Long

'Event Declarations:
Event Click() 'MappingInfo=UserControl,UserControl,-1,Click
Event Show() 'MappingInfo=UserControl,UserControl,-1,Show
Event Resize() 'MappingInfo=UserControl,UserControl,-1,Resize
Event OLEStartDrag(Data As DataObject, AllowedEffects As Long) 'MappingInfo=UserControl,UserControl,-1,OLEStartDrag
Event OLESetData(Data As DataObject, DataFormat As Integer) 'MappingInfo=UserControl,UserControl,-1,OLESetData
Event OLEGiveFeedback(Effect As Long, DefaultCursors As Boolean) 'MappingInfo=UserControl,UserControl,-1,OLEGiveFeedback
Event OLEDragOver(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, x As Single, y As Single, State As Integer) 'MappingInfo=UserControl,UserControl,-1,OLEDragOver
Event OLEDragDrop(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,OLEDragDrop
Event OLECompleteDrag(Effect As Long) 'MappingInfo=UserControl,UserControl,-1,OLECompleteDrag
Event MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseUp
Event MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseMove
Event MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseDown
Event KeyUp(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyUp
Event KeyPress(KeyAscii As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyPress
Event KeyDown(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyDown
Event Hide() 'MappingInfo=UserControl,UserControl,-1,Hide
Event DblClick() 'MappingInfo=UserControl,UserControl,-1,DblClick


'
' Controller Impl.
'
Public Sub Start()
    ' m_ActiveState = ...
    ' RaiseEvent Started(ActiveState)
End Sub

' Return False for termination
Public Function Process(ByVal Message, Optional Parameters) As Boolean
    ' Process = False
    ' RaiseEvent Ended(ActiveState)
End Function

Public Property Get ActiveState() As GraphSO
End Property

Public Property Get State(ByVal name As String) As GraphSO
End Property

Public Function AddCommand(ByVal cmd As StateObjectCommand) As StateObjectCommand
End Function

Public Sub RemoveCommand(ByVal index As Integer)
End Sub

Public Sub ResetCommand()
End Sub

Private Property Get Context() As Object
    If m_Context Is Nothing Then Set m_Context = Parent
    Set Context = m_Context
End Property

Function PixelX(ByVal v As Single) As Integer
    PixelX = ScaleX(v, UserControl.ScaleMode, vbPixels)
End Function
Function PixelY(ByVal v As Single) As Integer
    PixelY = ScaleY(v, UserControl.ScaleMode, vbPixels)
End Function

Public Sub Redraw()
    UserControl.Cls
    RedrawIcon
    RedrawTitle
    RedrawArrows
    UserControl.Refresh
End Sub

Private Sub RedrawArrows()
    ' Using outline'bordercolor to draw arrow-line
    ' Using title'forecolor to draw caption

    If Context Is Nothing Then Exit Sub

    Dim ctrls As Map
    Dim name
    Dim obj As Object

    Set ctrls = FindControls(Context)

    For Each name In ctrls.KeySet
        Set obj = ctrls(name)
        If TypeName(obj) = "GraphSO" Then
            Dim so As GraphSO
            Dim i As Integer
            Dim ct As Object

            Set so = obj
            For i = 0 To so.Commands - 1
                With so.Command(i)
                If .Visible = True Then
                    Set ct = .Target(Context)
                    If Not ct Is Nothing Then
                        Dim x0 As Single, y0 As Single, x1 As Single, y1 As Single
                        Dim dx As Single, dy As Single
                        Dim a As Single, b As Single, p As Single
                        x0 = obj.Left + obj.Width / 2
                        y0 = obj.Top + obj.Height / 2
                        x1 = ct.Left + ct.Width / 2
                        y1 = ct.Top + ct.Height / 2

                        dx = x1 - x0
                        dy = y1 - y0
                        a = obj.Width / 2
                        b = obj.Height / 2
                        p = Sqr(dx * dx / a / a + dy * dy / b / b)
                        x0 = x0 + dx / p
                        y0 = y0 + dy / p

                        a = ct.Width / 2
                        b = ct.Height / 2
                        p = Sqr(dx * dx / a / a + dy * dy / b / b)
                        x1 = x1 - dx / p
                        y1 = y1 - dy / p

                        x0 = PixelX(x0)
                        y0 = PixelY(y0)
                        x1 = PixelX(x1)
                        y1 = PixelY(y1)

                        Me.ForeColor = so.ForeColor
                        Lines.Arrow hDC, IIf(so.Command(i).Method = methodGoto, arrowNormal, arrowNormalDbl), _
                                    x0, y0, x1, y1

                        Dim size As SIZEL
                        GetTextExtentPoint hDC, .Title, strlen(.Title), size

                        TextOut hDC, (x0 + x1) / 2 - size.cx / 2, (y0 + y1) / 2 - size.cy / 2, _
                                .Title, strlen(.Title)
                    End If
                End If
                End With
            Next
        End If
    Next
End Sub

' -o ControllerObject
Private Property Get ControllerObject_ActiveState() As StateObject
    Set ControllerObject_ActiveState = ActiveState
End Property

Private Property Get ControllerObject_State(ByVal name As String) As StateObject
    Set ControllerObject_State = State(name)
End Property

Private Function ControllerObject_AddCommand(ByVal cmd As StateObjectCommand) As Integer
    ControllerObject_AddCommand = AddCommand(cmd)
End Function

Private Function ControllerObject_Process(ByVal Message As Variant, Optional Parameters As Variant) As Boolean
    ControllerObject_Process = Process(Message, Parameters)
End Function

Private Sub ControllerObject_RemoveCommand(ByVal index As Integer)
    RemoveCommand index
End Sub

Private Sub ControllerObject_ResetCommand()
    ResetCommand
End Sub

Private Sub ControllerObject_Start()
    Start
End Sub


' <>- BasicCO
Private Sub m_Impl_Ended(ByVal LastState As StateObject)
    RaiseEvent Ended(LastState)
End Sub

Private Sub m_Impl_Enter(ByVal PreviousState As StateObject, ByVal CurrentState As StateObject)
    RaiseEvent Enter(PreviousState, CurrentState)
End Sub

Private Sub m_Impl_Leave(ByVal CurrentState As StateObject, NextState As StateObject)
    RaiseEvent Leave(CurrentState, NextState)
End Sub

Private Sub m_Impl_Started(InitState As StateObject)
    RaiseEvent Started(InitState)
End Sub

'
' <Favorite Box Copy>
'
Public Property Get Collapsed() As Boolean
    Collapsed = m_Collapsed
End Property
Public Property Let Collapsed(ByVal newval As Boolean)
    If m_Collapsed = newval Then Exit Property
    m_Collapsed = newval
    If m_Collapsed Then
        m_ExpandedWidth = Width
        m_ExpandedHeight = Height
        Width = m_CollapsedWidth
        Height = m_CollapsedHeight
    Else
        Width = m_ExpandedWidth
        Height = m_ExpandedHeight
    End If
    Redraw
End Property

Public Property Get Title() As String
    Title = m_Title
End Property
Public Property Let Title(ByVal newval As String)
    m_Title = newval
    m_TitleLen = strlen(m_Title)
    UserControl.Refresh
End Property

Sub InitShapes()
    Dim h As Single
    ' size * sqrt(3)/2
    h = SHAPE_SIZE * 0.866025403784439

    m_ShapeCollapsed(1).x = 0
    m_ShapeCollapsed(1).y = SHAPE_SIZE - 1
    m_ShapeCollapsed(2).x = h - 1
    m_ShapeCollapsed(2).y = SHAPE_SIZE / 2 - 1
    m_ShapeExpanded(1).x = SHAPE_SIZE - 1
    m_ShapeExpanded(1).y = 0
    m_ShapeExpanded(2).x = SHAPE_SIZE / 2 - 1
    m_ShapeExpanded(2).y = h - 1

    Dim i As Integer
    For i = 0 To 3
        m_ShapeCollapsed(i).x = m_ShapeCollapsed(i).x + MARGIN
        m_ShapeExpanded(i).x = m_ShapeExpanded(i).x + MARGIN
    Next
End Sub

Private Sub RedrawIcon()
    If m_Collapsed Then
        Polygon hDC, m_ShapeCollapsed(0), 3
    Else
        Polygon hDC, m_ShapeExpanded(0), 3
    End If
End Sub

Private Sub RedrawTitle()
    Dim size As SIZEL
    Dim l As Long
    Dim x As Long, y As Long
    l = GetTextExtentPoint(hDC, m_Title, m_TitleLen, size)
    x = MARGIN + SHAPE_SIZE + SHAPE_PAD
    y = 1
    l = TextOut(hDC, x, y, m_Title, m_TitleLen)
    MoveTo hDC, 0, y + size.cy
    LineTo hDC, ScaleWidth - 1, y + size.cy ' Underline
    m_CollapsedWidth = (x + size.cx + MARGIN + TITLE_PAD + BORDER) * Screen.TwipsPerPixelX
    m_CollapsedHeight = (y + size.cy + MARGIN + BORDER) * Screen.TwipsPerPixelY
End Sub

Private Sub UserControl_Initialize()
    InitShapes
End Sub

Private Sub UserControl_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    If y < SHAPE_SIZE * Screen.TwipsPerPixelY Then
        Collapsed = Not Collapsed
    End If
    RaiseEvent MouseDown(Button, Shift, x, y)
End Sub

Private Sub UserControl_InitProperties()
    m_Collapsed = DEFAULT_COLLAPSED
    m_ExpandedWidth = DEFAULT_EXPANDEDWIDTH
    m_ExpandedHeight = DEFAULT_EXPANDEDHEIGHT
    Title = DEFAULT_TITLE

    Set UserControl.Font = Ambient.Font
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    m_Collapsed = PropBag.ReadProperty("Collapsed", DEFAULT_COLLAPSED)
    m_ExpandedWidth = PropBag.ReadProperty("ExpandedWidth", DEFAULT_EXPANDEDWIDTH)
    m_ExpandedHeight = PropBag.ReadProperty("ExpandedHeight", DEFAULT_EXPANDEDHEIGHT)
    Title = PropBag.ReadProperty("Title", DEFAULT_TITLE)

    UserControl.Appearance = PropBag.ReadProperty("Appearance", 0)
    UserControl.BackStyle = PropBag.ReadProperty("BackStyle", 1)
    UserControl.BackColor = PropBag.ReadProperty("BackColor", &H80000005)
    UserControl.BorderStyle = PropBag.ReadProperty("BorderStyle", 1)
    UserControl.ClipBehavior = PropBag.ReadProperty("ClipBehavior", 1)
    UserControl.ClipControls = PropBag.ReadProperty("ClipControls", True)
    UserControl.ScaleWidth = PropBag.ReadProperty("ScaleWidth", 98)
    UserControl.ScaleTop = PropBag.ReadProperty("ScaleTop", 0)
    UserControl.ScaleLeft = PropBag.ReadProperty("ScaleLeft", 0)
    UserControl.ScaleHeight = PropBag.ReadProperty("ScaleHeight", 78)
    UserControl.ScaleMode = PropBag.ReadProperty("ScaleMode", 3)
    UserControl.RightToLeft = PropBag.ReadProperty("RightToLeft", False)
    Set Picture = PropBag.ReadProperty("Picture", Nothing)
    UserControl.OLEDropMode = PropBag.ReadProperty("OLEDropMode", 0)
    UserControl.MousePointer = PropBag.ReadProperty("MousePointer", 0)
    Set MouseIcon = PropBag.ReadProperty("MouseIcon", Nothing)
    Set MaskPicture = PropBag.ReadProperty("MaskPicture", Nothing)
    UserControl.MaskColor = PropBag.ReadProperty("MaskColor", -2147483633)
    UserControl.ForeColor = PropBag.ReadProperty("ForeColor", &H80000012)
    Set UserControl.Font = PropBag.ReadProperty("Font", Ambient.Font)
    UserControl.FillStyle = PropBag.ReadProperty("FillStyle", 1)
    UserControl.FillColor = PropBag.ReadProperty("FillColor", &H0&)
    UserControl.Enabled = PropBag.ReadProperty("Enabled", True)
    UserControl.DrawWidth = PropBag.ReadProperty("DrawWidth", 1)
    UserControl.DrawStyle = PropBag.ReadProperty("DrawStyle", 0)
    UserControl.DrawMode = PropBag.ReadProperty("DrawMode", 13)
End Sub

Private Sub UserControl_Resize()
    '' Doverb edit for design-mode
    'If Not Ambient.UserMode Then UserControl.DoVerb "EDIT"
    RaiseEvent Resize
End Sub

Private Sub UserControl_Show()
    RaiseEvent Show
End Sub

Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    PropBag.WriteProperty "Collapsed", m_Collapsed
    PropBag.WriteProperty "ExpandedWidth", m_ExpandedWidth
    PropBag.WriteProperty "ExpandedHeight", m_ExpandedHeight
    PropBag.WriteProperty "Title", m_Title

    Call PropBag.WriteProperty("Appearance", UserControl.Appearance, 0)
    Call PropBag.WriteProperty("BackStyle", UserControl.BackStyle, 1)
    Call PropBag.WriteProperty("BackColor", UserControl.BackColor, &H80000005)
    Call PropBag.WriteProperty("BorderStyle", UserControl.BorderStyle, 1)
    Call PropBag.WriteProperty("ClipBehavior", UserControl.ClipBehavior, 1)
    Call PropBag.WriteProperty("ClipControls", UserControl.ClipControls, True)
    Call PropBag.WriteProperty("ScaleWidth", UserControl.ScaleWidth, 98)
    Call PropBag.WriteProperty("ScaleTop", UserControl.ScaleTop, 0)
    Call PropBag.WriteProperty("ScaleMode", UserControl.ScaleMode, 3)
    Call PropBag.WriteProperty("ScaleLeft", UserControl.ScaleLeft, 0)
    Call PropBag.WriteProperty("ScaleHeight", UserControl.ScaleHeight, 78)
    Call PropBag.WriteProperty("RightToLeft", UserControl.RightToLeft, False)
    Call PropBag.WriteProperty("Picture", Picture, Nothing)
    Call PropBag.WriteProperty("OLEDropMode", UserControl.OLEDropMode, 0)
    Call PropBag.WriteProperty("MousePointer", UserControl.MousePointer, 0)
    Call PropBag.WriteProperty("MouseIcon", MouseIcon, Nothing)
    Call PropBag.WriteProperty("MaskPicture", MaskPicture, Nothing)
    Call PropBag.WriteProperty("MaskColor", UserControl.MaskColor, -2147483633)
    Call PropBag.WriteProperty("ForeColor", UserControl.ForeColor, &H80000012)
    Call PropBag.WriteProperty("Font", UserControl.Font, Ambient.Font)
    Call PropBag.WriteProperty("FillStyle", UserControl.FillStyle, 1)
    Call PropBag.WriteProperty("FillColor", UserControl.FillColor, &H0&)
    Call PropBag.WriteProperty("Enabled", UserControl.Enabled, True)
    Call PropBag.WriteProperty("DrawWidth", UserControl.DrawWidth, 1)
    Call PropBag.WriteProperty("DrawStyle", UserControl.DrawStyle, 0)
    Call PropBag.WriteProperty("DrawMode", UserControl.DrawMode, 13)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Appearance
Public Property Get Appearance() As Integer
    Appearance = UserControl.Appearance
End Property

Public Property Let Appearance(ByVal New_Appearance As Integer)
    UserControl.Appearance() = New_Appearance
    PropertyChanged "Appearance"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,BackStyle
Public Property Get BackStyle() As Integer
    BackStyle = UserControl.BackStyle
End Property

Public Property Let BackStyle(ByVal New_BackStyle As Integer)
    UserControl.BackStyle() = New_BackStyle
    PropertyChanged "BackStyle"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,BackColor
Public Property Get BackColor() As OLE_COLOR
    BackColor = UserControl.BackColor
End Property

Public Property Let BackColor(ByVal New_BackColor As OLE_COLOR)
    UserControl.BackColor() = New_BackColor
    PropertyChanged "BackColor"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,BorderStyle
Public Property Get BorderStyle() As Integer
    BorderStyle = UserControl.BorderStyle
End Property

Public Property Let BorderStyle(ByVal New_BorderStyle As Integer)
    UserControl.BorderStyle() = New_BorderStyle
    PropertyChanged "BorderStyle"
End Property

Private Sub UserControl_Click()
    RaiseEvent Click
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ClipBehavior
Public Property Get ClipBehavior() As Integer
    ClipBehavior = UserControl.ClipBehavior
End Property

Public Property Let ClipBehavior(ByVal New_ClipBehavior As Integer)
    UserControl.ClipBehavior() = New_ClipBehavior
    PropertyChanged "ClipBehavior"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ClipControls
Public Property Get ClipControls() As Boolean
    ClipControls = UserControl.ClipControls
End Property

Public Property Let ClipControls(ByVal New_ClipControls As Boolean)
    UserControl.ClipControls() = New_ClipControls
    PropertyChanged "ClipControls"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,TextWidth
Public Function TextWidth(ByVal Str As String) As Single
    TextWidth = UserControl.TextWidth(Str)
End Function

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,TextHeight
Public Function TextHeight(ByVal Str As String) As Single
    TextHeight = UserControl.TextHeight(Str)
End Function

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Size
Public Sub size(ByVal Width As Single, ByVal Height As Single)
    UserControl.size Width, Height
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ScaleY
Public Function ScaleY(ByVal Height As Single, Optional ByVal FromScale As Variant, Optional ByVal ToScale As Variant) As Single
    ScaleY = UserControl.ScaleY(Height, FromScale, ToScale)
End Function

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ScaleX
Public Function ScaleX(ByVal Width As Single, Optional ByVal FromScale As Variant, Optional ByVal ToScale As Variant) As Single
    ScaleX = UserControl.ScaleX(Width, FromScale, ToScale)
End Function

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ScaleWidth
Public Property Get ScaleWidth() As Single
    ScaleWidth = UserControl.ScaleWidth
End Property

Public Property Let ScaleWidth(ByVal New_ScaleWidth As Single)
    UserControl.ScaleWidth() = New_ScaleWidth
    PropertyChanged "ScaleWidth"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ScaleTop
Public Property Get ScaleTop() As Single
    ScaleTop = UserControl.ScaleTop
End Property

Public Property Let ScaleTop(ByVal New_ScaleTop As Single)
    UserControl.ScaleTop() = New_ScaleTop
    PropertyChanged "ScaleTop"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ScaleMode
Public Property Get ScaleMode() As ScaleModeConstants
    ScaleMode = UserControl.ScaleMode
End Property

Public Property Let ScaleMode(ByVal New_ScaleMode As ScaleModeConstants)
    UserControl.ScaleMode() = New_ScaleMode
    PropertyChanged "ScaleMode"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ScaleLeft
Public Property Get ScaleLeft() As Single
    ScaleLeft = UserControl.ScaleLeft
End Property

Public Property Let ScaleLeft(ByVal New_ScaleLeft As Single)
    UserControl.ScaleLeft() = New_ScaleLeft
    PropertyChanged "ScaleLeft"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ScaleHeight
Public Property Get ScaleHeight() As Single
    ScaleHeight = UserControl.ScaleHeight
End Property

Public Property Let ScaleHeight(ByVal New_ScaleHeight As Single)
    UserControl.ScaleHeight() = New_ScaleHeight
    PropertyChanged "ScaleHeight"
End Property

'The Underscore following "Scale" is necessary because it
'is a Reserved Word in VBA.
'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Scale
Public Sub Scale_(Optional x1 As Variant, Optional y1 As Variant, Optional X2 As Variant, Optional Y2 As Variant)
    UserControl.Scale (x1, y1)-(X2, Y2)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,RightToLeft
Public Property Get RightToLeft() As Boolean
    RightToLeft = UserControl.RightToLeft
End Property

Public Property Let RightToLeft(ByVal New_RightToLeft As Boolean)
    UserControl.RightToLeft() = New_RightToLeft
    PropertyChanged "RightToLeft"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Refresh
Public Sub Refresh()
    UserControl.Refresh
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Picture
Public Property Get Picture() As Picture
    Set Picture = UserControl.Picture
End Property

Public Property Set Picture(ByVal New_Picture As Picture)
    Set UserControl.Picture = New_Picture
    PropertyChanged "Picture"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,PaintPicture
Public Sub PaintPicture(ByVal Picture As Picture, ByVal x1 As Single, ByVal y1 As Single, Optional ByVal Width1 As Variant, Optional ByVal Height1 As Variant, Optional ByVal X2 As Variant, Optional ByVal Y2 As Variant, Optional ByVal Width2 As Variant, Optional ByVal Height2 As Variant, Optional ByVal Opcode As Variant)
    UserControl.PaintPicture Picture, x1, y1, Width1, Height1, X2, Y2, Width2, Height2, Opcode
End Sub

Private Sub UserControl_OLEStartDrag(Data As DataObject, AllowedEffects As Long)
    RaiseEvent OLEStartDrag(Data, AllowedEffects)
End Sub

Private Sub UserControl_OLESetData(Data As DataObject, DataFormat As Integer)
    RaiseEvent OLESetData(Data, DataFormat)
End Sub

Private Sub UserControl_OLEGiveFeedback(Effect As Long, DefaultCursors As Boolean)
    RaiseEvent OLEGiveFeedback(Effect, DefaultCursors)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,OLEDropMode
Public Property Get OLEDropMode() As Integer
    OLEDropMode = UserControl.OLEDropMode
End Property

Public Property Let OLEDropMode(ByVal New_OLEDropMode As Integer)
    UserControl.OLEDropMode() = New_OLEDropMode
    PropertyChanged "OLEDropMode"
End Property

Private Sub UserControl_OLEDragOver(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, x As Single, y As Single, State As Integer)
    RaiseEvent OLEDragOver(Data, Effect, Button, Shift, x, y, State)
End Sub

Private Sub UserControl_OLEDragDrop(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent OLEDragDrop(Data, Effect, Button, Shift, x, y)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,OLEDrag
Public Sub OLEDrag()
    UserControl.OLEDrag
End Sub

Private Sub UserControl_OLECompleteDrag(Effect As Long)
    RaiseEvent OLECompleteDrag(Effect)
End Sub

Private Sub UserControl_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseUp(Button, Shift, x, y)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,MousePointer
Public Property Get MousePointer() As Integer
    MousePointer = UserControl.MousePointer
End Property

Public Property Let MousePointer(ByVal New_MousePointer As Integer)
    UserControl.MousePointer() = New_MousePointer
    PropertyChanged "MousePointer"
End Property

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseMove(Button, Shift, x, y)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,MouseIcon
Public Property Get MouseIcon() As Picture
    Set MouseIcon = UserControl.MouseIcon
End Property

Public Property Set MouseIcon(ByVal New_MouseIcon As Picture)
    Set UserControl.MouseIcon = New_MouseIcon
    PropertyChanged "MouseIcon"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,MaskPicture
Public Property Get MaskPicture() As Picture
    Set MaskPicture = UserControl.MaskPicture
End Property

Public Property Set MaskPicture(ByVal New_MaskPicture As Picture)
    Set UserControl.MaskPicture = New_MaskPicture
    PropertyChanged "MaskPicture"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,MaskColor
Public Property Get MaskColor() As Long
    MaskColor = UserControl.MaskColor
End Property

Public Property Let MaskColor(ByVal New_MaskColor As Long)
    UserControl.MaskColor() = New_MaskColor
    PropertyChanged "MaskColor"
End Property

Private Sub UserControl_KeyUp(KeyCode As Integer, Shift As Integer)
    RaiseEvent KeyUp(KeyCode, Shift)
End Sub

Private Sub UserControl_KeyPress(KeyAscii As Integer)
    RaiseEvent KeyPress(KeyAscii)
End Sub

Private Sub UserControl_KeyDown(KeyCode As Integer, Shift As Integer)
    RaiseEvent KeyDown(KeyCode, Shift)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Image
Public Property Get Image() As Picture
    Set Image = UserControl.Image
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,hWnd
Public Property Get hWnd() As Long
    hWnd = UserControl.hWnd
End Property

Private Sub UserControl_Hide()
    RaiseEvent Hide
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,hDC
Public Property Get hDC() As Long
    hDC = UserControl.hDC
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ForeColor
Public Property Get ForeColor() As OLE_COLOR
    ForeColor = UserControl.ForeColor
End Property

Public Property Let ForeColor(ByVal New_ForeColor As OLE_COLOR)
    UserControl.ForeColor() = New_ForeColor
    PropertyChanged "ForeColor"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Font
Public Property Get Font() As Font
    Set Font = UserControl.Font
End Property

Public Property Set Font(ByVal New_Font As Font)
    Set UserControl.Font = New_Font
    PropertyChanged "Font"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,FillStyle
Public Property Get FillStyle() As FillStyleConstants
    FillStyle = UserControl.FillStyle
End Property

Public Property Let FillStyle(ByVal New_FillStyle As FillStyleConstants)
    UserControl.FillStyle() = New_FillStyle
    PropertyChanged "FillStyle"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,FillColor
Public Property Get FillColor() As OLE_COLOR
    FillColor = UserControl.FillColor
End Property

Public Property Let FillColor(ByVal New_FillColor As OLE_COLOR)
    UserControl.FillColor() = New_FillColor
    PropertyChanged "FillColor"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Enabled
Public Property Get Enabled() As Boolean
    Enabled = UserControl.Enabled
End Property

Public Property Let Enabled(ByVal New_Enabled As Boolean)
    UserControl.Enabled() = New_Enabled
    PropertyChanged "Enabled"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,DrawWidth
Public Property Get DrawWidth() As Integer
    DrawWidth = UserControl.DrawWidth
End Property

Public Property Let DrawWidth(ByVal New_DrawWidth As Integer)
    UserControl.DrawWidth() = New_DrawWidth
    PropertyChanged "DrawWidth"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,DrawStyle
Public Property Get DrawStyle() As DrawStyleConstants
    DrawStyle = UserControl.DrawStyle
End Property

Public Property Let DrawStyle(ByVal New_DrawStyle As DrawStyleConstants)
    UserControl.DrawStyle() = New_DrawStyle
    PropertyChanged "DrawStyle"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,DrawMode
Public Property Get DrawMode() As DrawModeConstants
    DrawMode = UserControl.DrawMode
End Property

Public Property Let DrawMode(ByVal New_DrawMode As DrawModeConstants)
    UserControl.DrawMode() = New_DrawMode
    PropertyChanged "DrawMode"
End Property

Private Sub UserControl_DblClick()
    RaiseEvent DblClick
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,ActiveControl
Public Property Get ActiveControl() As Object
    Set ActiveControl = UserControl.ActiveControl
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Controls
Public Property Get Controls() As Object
    Set Controls = UserControl.Controls
End Property
