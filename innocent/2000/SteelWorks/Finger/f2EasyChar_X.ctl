VERSION 5.00
Begin VB.UserControl EasyChar_X
   AutoRedraw      =   -1  'True
   BackStyle       =   0  '透明
   ClientHeight    =   2085
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3540
   PropertyPages   =   "f2EasyChar_X.ctx":0000
   ScaleHeight     =   139
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   236
   Begin VB.Label m
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "EasyChar"
      ForeColor       =   &H00000000&
      Height          =   180
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   720
   End
End
Attribute VB_Name = "EasyChar_X"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'事件声明:
Event Click() 'MappingInfo=UserControl,UserControl,-1,Click
Attribute Click.VB_Description = "当用户在一个对象上按下并释放鼠标按钮时发生。"
Event DblClick() 'MappingInfo=UserControl,UserControl,-1,DblClick
Attribute DblClick.VB_Description = "当用户在一个对象上按下并释放鼠标按钮后再次按下并释放鼠标按钮时发生。"
Event KeyDown(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyDown
Attribute KeyDown.VB_Description = "当用户在拥有焦点的对象上按下任意键时发生。"
Event KeyPress(KeyAscii As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyPress
Attribute KeyPress.VB_Description = "当用户按下和释放 ANSI 键时发生。"
Event KeyUp(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyUp
Attribute KeyUp.VB_Description = "当用户在拥有焦点的对象上释放键时发生。"
Event MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseDown
Attribute MouseDown.VB_Description = "当用户在拥有焦点的对象上按下鼠标按钮时发生。"
Event MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseMove
Attribute MouseMove.VB_Description = "当用户移动鼠标时发生。"
Event MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseUp
Attribute MouseUp.VB_Description = "当用户在拥有焦点的对象上释放鼠标发生。"
Event Change() 'MappingInfo=m,m,-1,Change
Attribute Change.VB_Description = "当控件内容改变时发生。"
Event Paint() 'MappingInfo=UserControl,UserControl,-1,Paint
Attribute Paint.VB_Description = "当移动、放大或露出图片框的任何部分时发生。"
Event Resize() 'MappingInfo=UserControl,UserControl,-1,Resize
Attribute Resize.VB_Description = "当第一次显示一个窗体时或改变一个对象的大小时发生。"


Private Sub m_Change()
        RaiseEvent Change
        UserControl.width = m.width
        UserControl.height = m.height
End Sub
Private Sub m_Click()
        UserControl_Click
End Sub
Private Sub m_DblClick()
        UserControl_DblClick
End Sub
Private Sub m_DragDrop(Source As Control, X As Single, Y As Single)
        UserControl_DragDrop Source, X, Y
End Sub
Private Sub m_DragOver(Source As Control, X As Single, Y As Single, State As Integer)
        UserControl_DragOver Source, X, Y, State
End Sub
Private Sub m_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        UserControl_MouseDown Button, Shift, X, Y
End Sub
Private Sub m_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        UserControl_MouseMove Button, Shift, X, Y
End Sub
Private Sub m_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
        UserControl_MouseUp Button, Shift, X, Y
End Sub
''注意！不要删除或修改下列被注释的行！
''MappingInfo=UserControl,UserControl,-1,BackColor
'Public Property Get BackColor() As OLE_COLOR
'        BackColor = UserControl.BackColor
'End Property
'
'Public Property Let BackColor(ByVal New_BackColor As OLE_COLOR)
'        UserControl.BackColor() = New_BackColor
'        PropertyChanged "BackColor"
'End Property
'
''注意！不要删除或修改下列被注释的行！
''MappingInfo=UserControl,UserControl,-1,ForeColor
'Public Property Get ForeColor() As OLE_COLOR
'        ForeColor = UserControl.ForeColor
'End Property
'
'Public Property Let ForeColor(ByVal New_ForeColor As OLE_COLOR)
'        UserControl.ForeColor() = New_ForeColor
'        PropertyChanged "ForeColor"
'End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,Enabled
Public Property Get Enabled() As Boolean
Attribute Enabled.VB_Description = "返回/设置一个值，决定一个对象是否响应用户生成事件。"
        Enabled = UserControl.Enabled
End Property

Public Property Let Enabled(ByVal New_Enabled As Boolean)
        UserControl.Enabled() = New_Enabled
        PropertyChanged "Enabled"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,Font
Public Property Get Font() As Font
        Set Font = UserControl.Font
End Property

Public Property Set Font(ByVal New_Font As Font)
        Set UserControl.Font = New_Font
        PropertyChanged "Font"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,BackStyle
Public Property Get BackStyle() As Integer
Attribute BackStyle.VB_Description = "指出 Label 或 Shape 的背景样式是透明的还是不透明的。"
        BackStyle = UserControl.BackStyle
End Property

Public Property Let BackStyle(ByVal New_BackStyle As Integer)
        UserControl.BackStyle() = New_BackStyle
        PropertyChanged "BackStyle"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,BorderStyle
Public Property Get BorderStyle() As Integer
Attribute BorderStyle.VB_Description = "返回/设置对象的边框样式。"
        BorderStyle = UserControl.BorderStyle
End Property

Public Property Let BorderStyle(ByVal New_BorderStyle As Integer)
        UserControl.BorderStyle() = New_BorderStyle
        PropertyChanged "BorderStyle"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,Refresh
Public Sub Refresh()
Attribute Refresh.VB_Description = "强制完全重画一个对象。"
        UserControl.Refresh
End Sub

Private Sub UserControl_Click()
        RaiseEvent Click
End Sub

Private Sub UserControl_DblClick()
        RaiseEvent DblClick
End Sub

Private Sub UserControl_DragDrop(Source As Control, X As Single, Y As Single)
        '
End Sub

Private Sub UserControl_DragOver(Source As Control, X As Single, Y As Single, State As Integer)
        '
End Sub

Private Sub UserControl_KeyDown(KeyCode As Integer, Shift As Integer)
        RaiseEvent KeyDown(KeyCode, Shift)
End Sub

Private Sub UserControl_KeyPress(KeyAscii As Integer)
        RaiseEvent KeyPress(KeyAscii)
End Sub

Private Sub UserControl_KeyUp(KeyCode As Integer, Shift As Integer)
        RaiseEvent KeyUp(KeyCode, Shift)
End Sub

Private Sub UserControl_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        RaiseEvent MouseDown(Button, Shift, X, Y)
End Sub

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        RaiseEvent MouseMove(Button, Shift, X, Y)
End Sub

Private Sub UserControl_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
        RaiseEvent MouseUp(Button, Shift, X, Y)
End Sub

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,AutoRedraw
Public Property Get AutoRedraw() As Boolean
Attribute AutoRedraw.VB_Description = "返回/设置从 graphics 方法到一个持久性位图的输出。"
        AutoRedraw = UserControl.AutoRedraw
End Property

Public Property Let AutoRedraw(ByVal New_AutoRedraw As Boolean)
        UserControl.AutoRedraw = New_AutoRedraw
        PropertyChanged "AutoRedraw"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=m,m,-1,AutoSize
Public Property Get AutoSize() As Boolean
Attribute AutoSize.VB_Description = "决定控件是否能自动调整大小以显示所有的内容。"
        AutoSize = m.AutoSize
End Property

Public Property Let AutoSize(ByVal New_AutoSize As Boolean)
        m.AutoSize() = New_AutoSize
        PropertyChanged "AutoSize"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,Cls
Public Sub Cls()
Attribute Cls.VB_Description = "清除窗体、图像或图片框中在运行时生成的图形和文本。"
        UserControl.Cls
End Sub

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,DrawMode
Public Property Get DrawMode() As Integer
Attribute DrawMode.VB_Description = "设置以 graphics 方法或 Shape 、 Line 控件输出时的外观。"
        DrawMode = UserControl.DrawMode
End Property

Public Property Let DrawMode(ByVal New_DrawMode As Integer)
        UserControl.DrawMode() = New_DrawMode
        PropertyChanged "DrawMode"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,DrawStyle
Public Property Get DrawStyle() As Integer
Attribute DrawStyle.VB_Description = "决定 graphics 方法输出时的线条样式。"
        DrawStyle = UserControl.DrawStyle
End Property

Public Property Let DrawStyle(ByVal New_DrawStyle As Integer)
        UserControl.DrawStyle() = New_DrawStyle
        PropertyChanged "DrawStyle"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,DrawWidth
Public Property Get DrawWidth() As Integer
Attribute DrawWidth.VB_Description = "返回/设置 graphics 方法输出时的线条宽度。"
        DrawWidth = UserControl.DrawWidth
End Property

Public Property Let DrawWidth(ByVal New_DrawWidth As Integer)
        UserControl.DrawWidth() = New_DrawWidth
        PropertyChanged "DrawWidth"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,FillColor
Public Property Get FillColor() As OLE_COLOR
Attribute FillColor.VB_Description = "返回/设置填充形状、圆环和方框所使用的颜色。"
        FillColor = UserControl.FillColor
End Property

Public Property Let FillColor(ByVal New_FillColor As OLE_COLOR)
        UserControl.FillColor() = New_FillColor
        PropertyChanged "FillColor"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,FillStyle
Public Property Get FillStyle() As Integer
Attribute FillStyle.VB_Description = "返回/设置一个 shape 控件的填充样式。"
        FillStyle = UserControl.FillStyle
End Property

Public Property Let FillStyle(ByVal New_FillStyle As Integer)
        UserControl.FillStyle() = New_FillStyle
        PropertyChanged "FillStyle"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,HasDC
Public Property Get HasDC() As Boolean
Attribute HasDC.VB_Description = "决定是否为该控件分配了唯一的显示上下文。"
        HasDC = UserControl.HasDC
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,hDC
Public Property Get hDC() As Long
Attribute hDC.VB_Description = "返回一个句柄(从 Microsoft Windows)到对象的设备上下文。"
        hDC = UserControl.hDC
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,hWnd
Public Property Get hWnd() As Long
Attribute hWnd.VB_Description = "返回一个句柄到(from Microsoft Windows)一个对象的窗口。"
        hWnd = UserControl.hWnd
End Property

Private Sub UserControl_Paint()
        RaiseEvent Paint
End Sub

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,Picture
Public Property Get Picture() As Picture
Attribute Picture.VB_Description = "返回/设置控件中显示的图形。"
        Set Picture = UserControl.Picture
End Property

Public Property Set Picture(ByVal New_Picture As Picture)
        Set UserControl.Picture = New_Picture
        PropertyChanged "Picture"
End Property

Private Sub UserControl_Resize()
        RaiseEvent Resize
End Sub

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,ScaleHeight
Public Property Get ScaleHeight() As Single
Attribute ScaleHeight.VB_Description = "返回/设置对象内部的垂直度量的单位数。"
        ScaleHeight = UserControl.ScaleHeight
End Property

Public Property Let ScaleHeight(ByVal New_ScaleHeight As Single)
        UserControl.ScaleHeight() = New_ScaleHeight
        PropertyChanged "ScaleHeight"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,ScaleLeft
Public Property Get ScaleLeft() As Single
Attribute ScaleLeft.VB_Description = "返回/设置对象左边界的水平坐标。"
        ScaleLeft = UserControl.ScaleLeft
End Property

Public Property Let ScaleLeft(ByVal New_ScaleLeft As Single)
        UserControl.ScaleLeft() = New_ScaleLeft
        PropertyChanged "ScaleLeft"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,ScaleMode
Public Property Get ScaleMode() As Integer
Attribute ScaleMode.VB_Description = "返回/设置一个值，指示当使用 graphics 方法或可定位的控件时，对象坐标的度量单位。"
        ScaleMode = UserControl.ScaleMode
End Property

Public Property Let ScaleMode(ByVal New_ScaleMode As Integer)
        UserControl.ScaleMode() = New_ScaleMode
        PropertyChanged "ScaleMode"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,ScaleTop
Public Property Get ScaleTop() As Single
Attribute ScaleTop.VB_Description = "返回/设置对象上边界的垂直坐标。"
        ScaleTop = UserControl.ScaleTop
End Property

Public Property Let ScaleTop(ByVal New_ScaleTop As Single)
        UserControl.ScaleTop() = New_ScaleTop
        PropertyChanged "ScaleTop"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=UserControl,UserControl,-1,ScaleWidth
Public Property Get ScaleWidth() As Single
Attribute ScaleWidth.VB_Description = "返回/设置对象内部的水平度量单位数。"
        ScaleWidth = UserControl.ScaleWidth
End Property

Public Property Let ScaleWidth(ByVal New_ScaleWidth As Single)
        UserControl.ScaleWidth() = New_ScaleWidth
        PropertyChanged "ScaleWidth"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=m,m,-1,ToolTipText
Public Property Get ToolTipText() As String
Attribute ToolTipText.VB_Description = "返回/设置当鼠标在控件上暂停时显示的文本。"
        ToolTipText = m.ToolTipText
End Property

Public Property Let ToolTipText(ByVal New_ToolTipText As String)
        m.ToolTipText() = New_ToolTipText
        PropertyChanged "ToolTipText"
End Property

'为用户控件初始化属性
Private Sub UserControl_InitProperties()
        Set UserControl.Font = Ambient.Font
End Sub

'从存贮器中加载属性值
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)

'        UserControl.BackColor = PropBag.ReadProperty("BackColor", &H8000000F)
        UserControl.ForeColor = PropBag.ReadProperty("ForeColor", &H80000012)
        UserControl.Enabled = PropBag.ReadProperty("Enabled", True)
        Set UserControl.Font = PropBag.ReadProperty("Font", Ambient.Font)
        UserControl.BackStyle = PropBag.ReadProperty("BackStyle", 0)
        UserControl.BorderStyle = PropBag.ReadProperty("BorderStyle", 0)
        UserControl.AutoRedraw = PropBag.ReadProperty("AutoRedraw", True)
        m.AutoSize = PropBag.ReadProperty("AutoSize", True)
        UserControl.DrawMode = PropBag.ReadProperty("DrawMode", 13)
        UserControl.DrawStyle = PropBag.ReadProperty("DrawStyle", 0)
        UserControl.DrawWidth = PropBag.ReadProperty("DrawWidth", 1)
        UserControl.FillColor = PropBag.ReadProperty("FillColor", &H0&)
        UserControl.FillStyle = PropBag.ReadProperty("FillStyle", 1)
        Set Picture = PropBag.ReadProperty("Picture", Nothing)
        UserControl.ScaleHeight = PropBag.ReadProperty("ScaleHeight", 139)
        UserControl.ScaleLeft = PropBag.ReadProperty("ScaleLeft", 0)
        UserControl.ScaleMode = PropBag.ReadProperty("ScaleMode", 3)
        UserControl.ScaleTop = PropBag.ReadProperty("ScaleTop", 0)
        UserControl.ScaleWidth = PropBag.ReadProperty("ScaleWidth", 236)
        m.ToolTipText = PropBag.ReadProperty("ToolTipText", "")
End Sub

'将属性值写到存储器
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)

'        Call PropBag.WriteProperty("BackColor", UserControl.BackColor, &H8000000F)
        Call PropBag.WriteProperty("ForeColor", UserControl.ForeColor, &H80000012)
        Call PropBag.WriteProperty("Enabled", UserControl.Enabled, True)
        Call PropBag.WriteProperty("Font", UserControl.Font, Ambient.Font)
        Call PropBag.WriteProperty("BackStyle", UserControl.BackStyle, 0)
        Call PropBag.WriteProperty("BorderStyle", UserControl.BorderStyle, 0)
        Call PropBag.WriteProperty("AutoRedraw", UserControl.AutoRedraw, True)
        Call PropBag.WriteProperty("AutoSize", m.AutoSize, True)
        Call PropBag.WriteProperty("DrawMode", UserControl.DrawMode, 13)
        Call PropBag.WriteProperty("DrawStyle", UserControl.DrawStyle, 0)
        Call PropBag.WriteProperty("DrawWidth", UserControl.DrawWidth, 1)
        Call PropBag.WriteProperty("FillColor", UserControl.FillColor, &H0&)
        Call PropBag.WriteProperty("FillStyle", UserControl.FillStyle, 1)
        Call PropBag.WriteProperty("Picture", Picture, Nothing)
        Call PropBag.WriteProperty("ScaleHeight", UserControl.ScaleHeight, 139)
        Call PropBag.WriteProperty("ScaleLeft", UserControl.ScaleLeft, 0)
        Call PropBag.WriteProperty("ScaleMode", UserControl.ScaleMode, 3)
        Call PropBag.WriteProperty("ScaleTop", UserControl.ScaleTop, 0)
        Call PropBag.WriteProperty("ScaleWidth", UserControl.ScaleWidth, 236)
        Call PropBag.WriteProperty("ToolTipText", m.ToolTipText, "")
End Sub
