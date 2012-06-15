VERSION 5.00
Begin VB.UserControl ucBut
   ClientHeight    =   3420
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4590
   ScaleHeight     =   3420
   ScaleWidth      =   4590
   Begin VB.PictureBox picBack
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   2895
      Left            =   0
      ScaleHeight     =   2895
      ScaleWidth      =   4095
      TabIndex        =   0
      Top             =   0
      Width           =   4095
      Begin VB.Label lblText
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BackStyle       =   0  'Transparent
         Caption         =   "123"
         ForeColor       =   &H80000008&
         Height          =   2175
         Left            =   240
         TabIndex        =   1
         Top             =   240
         Width           =   3135
         WordWrap        =   -1  'True
      End
   End
End
Attribute VB_Name = "ucBut"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
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

Private Sub lblText_Click()
    RaiseEvent Click
End Sub

Private Sub picBack_Click()
    RaiseEvent Click
End Sub

Private Sub picBack_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseDown(Button, Shift, X, Y)
End Sub

Private Sub picBack_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseUp(Button, Shift, X, Y)
End Sub

Private Sub picBack_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseMove(Button, Shift, X, Y)
End Sub

Private Sub lblText_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseDown(Button, Shift, X, Y)
End Sub

Private Sub lblText_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseUp(Button, Shift, X, Y)
End Sub

Private Sub lblText_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseMove(Button, Shift, X, Y)
End Sub

Private Sub picBack_Resize()
    lblText.Width = picBack.Width * 0.8
    lblText.Left = picBack.Width * 0.1
    lblText.AutoSize = True
    If picBack.Width <= picBack.Height Then
        lblText.AutoSize = False
        lblText.Height = lblText.Height * 2.5
    End If
    lblText.Top = (picBack.Height - lblText.Height) / 2
    UserControl.Width = picBack.Width
    UserControl.Height = picBack.Height
End Sub
'
''注意！不要删除或修改下列被注释的行！
''MappingInfo=lblText,lblText,-1,BackColor
'Public Property Get BackColor() As OLE_COLOR
'    BackColor = lblText.BackColor
'End Property
'
'Public Property Let BackColor(ByVal New_BackColor As OLE_COLOR)
'    lblText.BackColor() = New_BackColor
'    PropertyChanged "BackColor"
'End Property
'
''注意！不要删除或修改下列被注释的行！
''MappingInfo=lblText,lblText,-1,ForeColor
'Public Property Get ForeColor() As OLE_COLOR
'    ForeColor = lblText.ForeColor
'End Property
'
'Public Property Let ForeColor(ByVal New_ForeColor As OLE_COLOR)
'    lblText.ForeColor() = New_ForeColor
'    PropertyChanged "ForeColor"
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
'MappingInfo=lblText,lblText,-1,Font
Public Property Get Font() As Font
Attribute Font.VB_Description = "返回一个 Font 对象。"
Attribute Font.VB_UserMemId = -512
    Set Font = lblText.Font
End Property

Public Property Set Font(ByVal New_Font As Font)
    Set lblText.Font = New_Font
    PropertyChanged "Font"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=lblText,lblText,-1,BackStyle
Public Property Get BackStyle() As Integer
Attribute BackStyle.VB_Description = "指出 Label 或 Shape 的背景样式是透明的还是不透明的。"
    BackStyle = lblText.BackStyle
End Property

Public Property Let BackStyle(ByVal New_BackStyle As Integer)
    lblText.BackStyle() = New_BackStyle
    PropertyChanged "BackStyle"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=picBack,picBack,-1,BorderStyle
Public Property Get BorderStyle() As Integer
Attribute BorderStyle.VB_Description = "返回/设置对象的边框样式。"
    BorderStyle = picBack.BorderStyle
End Property

Public Property Let BorderStyle(ByVal New_BorderStyle As Integer)
    picBack.BorderStyle() = New_BorderStyle
    PropertyChanged "BorderStyle"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=picBack,picBack,-1,Refresh
Public Sub Refresh()
Attribute Refresh.VB_Description = "强制完全重画一个对象。"
    picBack.Refresh
End Sub

Private Sub UserControl_Click()
    RaiseEvent Click
End Sub

Private Sub UserControl_DblClick()
    RaiseEvent DblClick
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
'MappingInfo=lblText,lblText,-1,Caption
Public Property Get Caption() As String
Attribute Caption.VB_Description = "返回/设置对象的标题栏中或图标下面的文本。"
    Caption = lblText.Caption
End Property

Public Property Let Caption(ByVal New_Caption As String)
    lblText.Caption() = New_Caption
    PropertyChanged "Caption"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=picBack,picBack,-1,Picture
Public Property Get Picture() As Picture
Attribute Picture.VB_Description = "返回/设置控件中显示的图形。"
    Set Picture = picBack.Picture
End Property

Public Property Set Picture(ByVal New_Picture As Picture)
    Set picBack.Picture = New_Picture
    PropertyChanged "Picture"
End Property

'从存贮器中加载属性值
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)

'    lblText.BackColor = PropBag.ReadProperty("BackColor", &H80000005)
'    lblText.ForeColor = PropBag.ReadProperty("ForeColor", &H80000008)
    UserControl.Enabled = PropBag.ReadProperty("Enabled", True)
    Set lblText.Font = PropBag.ReadProperty("Font", Ambient.Font)
    lblText.BackStyle = PropBag.ReadProperty("BackStyle", 0)
    picBack.BorderStyle = PropBag.ReadProperty("BorderStyle", 0)
    lblText.Caption = PropBag.ReadProperty("Caption", "123")
    Set Picture = PropBag.ReadProperty("Picture", Nothing)
    picBack.AutoSize = PropBag.ReadProperty("AutoSize", True)
    lblText.Alignment = PropBag.ReadProperty("Alignment", 0)
    lblText.ForeColor = PropBag.ReadProperty("TextFore", &H80000008)
    lblText.BackColor = PropBag.ReadProperty("TextBack", &H80000005)
End Sub

Private Sub UserControl_Resize()
    picBack_Resize
End Sub

'将属性值写到存储器
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)

'    Call PropBag.WriteProperty("BackColor", lblText.BackColor, &H80000005)
'    Call PropBag.WriteProperty("ForeColor", lblText.ForeColor, &H80000008)
    Call PropBag.WriteProperty("Enabled", UserControl.Enabled, True)
    Call PropBag.WriteProperty("Font", lblText.Font, Ambient.Font)
    Call PropBag.WriteProperty("BackStyle", lblText.BackStyle, 0)
    Call PropBag.WriteProperty("BorderStyle", picBack.BorderStyle, 0)
    Call PropBag.WriteProperty("Caption", lblText.Caption, "123")
    Call PropBag.WriteProperty("Picture", Picture, Nothing)
    Call PropBag.WriteProperty("AutoSize", picBack.AutoSize, True)
    Call PropBag.WriteProperty("Alignment", lblText.Alignment, 0)
    Call PropBag.WriteProperty("TextFore", lblText.ForeColor, &H80000008)
    Call PropBag.WriteProperty("TextBack", lblText.BackColor, &H80000005)
End Sub

'注意！不要删除或修改下列被注释的行！
'MappingInfo=picBack,picBack,-1,AutoSize
Public Property Get AutoSize() As Boolean
Attribute AutoSize.VB_Description = "决定控件是否能自动调整大小以显示所有的内容。"
    AutoSize = picBack.AutoSize
End Property

Public Property Let AutoSize(ByVal New_AutoSize As Boolean)
    picBack.AutoSize() = New_AutoSize
    PropertyChanged "AutoSize"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=lblText,lblText,-1,Alignment
Public Property Get Alignment() As Integer
Attribute Alignment.VB_Description = "返回/设置复选框或选项按钮、或一个控件的文本的对齐。"
    Alignment = lblText.Alignment
End Property

Public Property Let Alignment(ByVal New_Alignment As Integer)
    lblText.Alignment() = New_Alignment
    PropertyChanged "Alignment"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=lblText,lblText,-1,ForeColor
Public Property Get TextFore() As OLE_COLOR
Attribute TextFore.VB_Description = "返回/设置对象中文本和图形的前景色。"
    TextFore = lblText.ForeColor
End Property

Public Property Let TextFore(ByVal New_TextFore As OLE_COLOR)
    lblText.ForeColor() = New_TextFore
    PropertyChanged "TextFore"
End Property

'注意！不要删除或修改下列被注释的行！
'MappingInfo=lblText,lblText,-1,BackColor
Public Property Get TextBack() As OLE_COLOR
Attribute TextBack.VB_Description = "返回/设置对象中文本和图形的背景色。"
    TextBack = lblText.BackColor
End Property

Public Property Let TextBack(ByVal New_TextBack As OLE_COLOR)
    lblText.BackColor() = New_TextBack
    PropertyChanged "TextBack"
End Property
