VERSION 5.00
Begin VB.UserControl EasyChar_X
   AutoRedraw      =   -1  'True
   BackStyle       =   0  '͸��
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
'�¼�����:
Event Click() 'MappingInfo=UserControl,UserControl,-1,Click
Attribute Click.VB_Description = "���û���һ�������ϰ��²��ͷ���갴ťʱ������"
Event DblClick() 'MappingInfo=UserControl,UserControl,-1,DblClick
Attribute DblClick.VB_Description = "���û���һ�������ϰ��²��ͷ���갴ť���ٴΰ��²��ͷ���갴ťʱ������"
Event KeyDown(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyDown
Attribute KeyDown.VB_Description = "���û���ӵ�н���Ķ����ϰ��������ʱ������"
Event KeyPress(KeyAscii As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyPress
Attribute KeyPress.VB_Description = "���û����º��ͷ� ANSI ��ʱ������"
Event KeyUp(KeyCode As Integer, Shift As Integer) 'MappingInfo=UserControl,UserControl,-1,KeyUp
Attribute KeyUp.VB_Description = "���û���ӵ�н���Ķ������ͷż�ʱ������"
Event MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseDown
Attribute MouseDown.VB_Description = "���û���ӵ�н���Ķ����ϰ�����갴ťʱ������"
Event MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseMove
Attribute MouseMove.VB_Description = "���û��ƶ����ʱ������"
Event MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseUp
Attribute MouseUp.VB_Description = "���û���ӵ�н���Ķ������ͷ���귢����"
Event Change() 'MappingInfo=m,m,-1,Change
Attribute Change.VB_Description = "���ؼ����ݸı�ʱ������"
Event Paint() 'MappingInfo=UserControl,UserControl,-1,Paint
Attribute Paint.VB_Description = "���ƶ����Ŵ��¶��ͼƬ����κβ���ʱ������"
Event Resize() 'MappingInfo=UserControl,UserControl,-1,Resize
Attribute Resize.VB_Description = "����һ����ʾһ������ʱ��ı�һ������Ĵ�Сʱ������"


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
''ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
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
''ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
''MappingInfo=UserControl,UserControl,-1,ForeColor
'Public Property Get ForeColor() As OLE_COLOR
'        ForeColor = UserControl.ForeColor
'End Property
'
'Public Property Let ForeColor(ByVal New_ForeColor As OLE_COLOR)
'        UserControl.ForeColor() = New_ForeColor
'        PropertyChanged "ForeColor"
'End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,Enabled
Public Property Get Enabled() As Boolean
Attribute Enabled.VB_Description = "����/����һ��ֵ������һ�������Ƿ���Ӧ�û������¼���"
        Enabled = UserControl.Enabled
End Property

Public Property Let Enabled(ByVal New_Enabled As Boolean)
        UserControl.Enabled() = New_Enabled
        PropertyChanged "Enabled"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,Font
Public Property Get Font() As Font
        Set Font = UserControl.Font
End Property

Public Property Set Font(ByVal New_Font As Font)
        Set UserControl.Font = New_Font
        PropertyChanged "Font"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,BackStyle
Public Property Get BackStyle() As Integer
Attribute BackStyle.VB_Description = "ָ�� Label �� Shape �ı�����ʽ��͸���Ļ��ǲ�͸���ġ�"
        BackStyle = UserControl.BackStyle
End Property

Public Property Let BackStyle(ByVal New_BackStyle As Integer)
        UserControl.BackStyle() = New_BackStyle
        PropertyChanged "BackStyle"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,BorderStyle
Public Property Get BorderStyle() As Integer
Attribute BorderStyle.VB_Description = "����/���ö���ı߿���ʽ��"
        BorderStyle = UserControl.BorderStyle
End Property

Public Property Let BorderStyle(ByVal New_BorderStyle As Integer)
        UserControl.BorderStyle() = New_BorderStyle
        PropertyChanged "BorderStyle"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,Refresh
Public Sub Refresh()
Attribute Refresh.VB_Description = "ǿ����ȫ�ػ�һ������"
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

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,AutoRedraw
Public Property Get AutoRedraw() As Boolean
Attribute AutoRedraw.VB_Description = "����/���ô� graphics ������һ���־���λͼ�������"
        AutoRedraw = UserControl.AutoRedraw
End Property

Public Property Let AutoRedraw(ByVal New_AutoRedraw As Boolean)
        UserControl.AutoRedraw = New_AutoRedraw
        PropertyChanged "AutoRedraw"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=m,m,-1,AutoSize
Public Property Get AutoSize() As Boolean
Attribute AutoSize.VB_Description = "�����ؼ��Ƿ����Զ�������С����ʾ���е����ݡ�"
        AutoSize = m.AutoSize
End Property

Public Property Let AutoSize(ByVal New_AutoSize As Boolean)
        m.AutoSize() = New_AutoSize
        PropertyChanged "AutoSize"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,Cls
Public Sub Cls()
Attribute Cls.VB_Description = "������塢ͼ���ͼƬ����������ʱ���ɵ�ͼ�κ��ı���"
        UserControl.Cls
End Sub

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,DrawMode
Public Property Get DrawMode() As Integer
Attribute DrawMode.VB_Description = "������ graphics ������ Shape �� Line �ؼ����ʱ����ۡ�"
        DrawMode = UserControl.DrawMode
End Property

Public Property Let DrawMode(ByVal New_DrawMode As Integer)
        UserControl.DrawMode() = New_DrawMode
        PropertyChanged "DrawMode"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,DrawStyle
Public Property Get DrawStyle() As Integer
Attribute DrawStyle.VB_Description = "���� graphics �������ʱ��������ʽ��"
        DrawStyle = UserControl.DrawStyle
End Property

Public Property Let DrawStyle(ByVal New_DrawStyle As Integer)
        UserControl.DrawStyle() = New_DrawStyle
        PropertyChanged "DrawStyle"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,DrawWidth
Public Property Get DrawWidth() As Integer
Attribute DrawWidth.VB_Description = "����/���� graphics �������ʱ��������ȡ�"
        DrawWidth = UserControl.DrawWidth
End Property

Public Property Let DrawWidth(ByVal New_DrawWidth As Integer)
        UserControl.DrawWidth() = New_DrawWidth
        PropertyChanged "DrawWidth"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,FillColor
Public Property Get FillColor() As OLE_COLOR
Attribute FillColor.VB_Description = "����/���������״��Բ���ͷ�����ʹ�õ���ɫ��"
        FillColor = UserControl.FillColor
End Property

Public Property Let FillColor(ByVal New_FillColor As OLE_COLOR)
        UserControl.FillColor() = New_FillColor
        PropertyChanged "FillColor"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,FillStyle
Public Property Get FillStyle() As Integer
Attribute FillStyle.VB_Description = "����/����һ�� shape �ؼ��������ʽ��"
        FillStyle = UserControl.FillStyle
End Property

Public Property Let FillStyle(ByVal New_FillStyle As Integer)
        UserControl.FillStyle() = New_FillStyle
        PropertyChanged "FillStyle"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,HasDC
Public Property Get HasDC() As Boolean
Attribute HasDC.VB_Description = "�����Ƿ�Ϊ�ÿؼ�������Ψһ����ʾ�����ġ�"
        HasDC = UserControl.HasDC
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,hDC
Public Property Get hDC() As Long
Attribute hDC.VB_Description = "����һ�����(�� Microsoft Windows)��������豸�����ġ�"
        hDC = UserControl.hDC
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,hWnd
Public Property Get hWnd() As Long
Attribute hWnd.VB_Description = "����һ�������(from Microsoft Windows)һ������Ĵ��ڡ�"
        hWnd = UserControl.hWnd
End Property

Private Sub UserControl_Paint()
        RaiseEvent Paint
End Sub

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,Picture
Public Property Get Picture() As Picture
Attribute Picture.VB_Description = "����/���ÿؼ�����ʾ��ͼ�Ρ�"
        Set Picture = UserControl.Picture
End Property

Public Property Set Picture(ByVal New_Picture As Picture)
        Set UserControl.Picture = New_Picture
        PropertyChanged "Picture"
End Property

Private Sub UserControl_Resize()
        RaiseEvent Resize
End Sub

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,ScaleHeight
Public Property Get ScaleHeight() As Single
Attribute ScaleHeight.VB_Description = "����/���ö����ڲ��Ĵ�ֱ�����ĵ�λ����"
        ScaleHeight = UserControl.ScaleHeight
End Property

Public Property Let ScaleHeight(ByVal New_ScaleHeight As Single)
        UserControl.ScaleHeight() = New_ScaleHeight
        PropertyChanged "ScaleHeight"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,ScaleLeft
Public Property Get ScaleLeft() As Single
Attribute ScaleLeft.VB_Description = "����/���ö�����߽��ˮƽ���ꡣ"
        ScaleLeft = UserControl.ScaleLeft
End Property

Public Property Let ScaleLeft(ByVal New_ScaleLeft As Single)
        UserControl.ScaleLeft() = New_ScaleLeft
        PropertyChanged "ScaleLeft"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,ScaleMode
Public Property Get ScaleMode() As Integer
Attribute ScaleMode.VB_Description = "����/����һ��ֵ��ָʾ��ʹ�� graphics ������ɶ�λ�Ŀؼ�ʱ����������Ķ�����λ��"
        ScaleMode = UserControl.ScaleMode
End Property

Public Property Let ScaleMode(ByVal New_ScaleMode As Integer)
        UserControl.ScaleMode() = New_ScaleMode
        PropertyChanged "ScaleMode"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,ScaleTop
Public Property Get ScaleTop() As Single
Attribute ScaleTop.VB_Description = "����/���ö����ϱ߽�Ĵ�ֱ���ꡣ"
        ScaleTop = UserControl.ScaleTop
End Property

Public Property Let ScaleTop(ByVal New_ScaleTop As Single)
        UserControl.ScaleTop() = New_ScaleTop
        PropertyChanged "ScaleTop"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,ScaleWidth
Public Property Get ScaleWidth() As Single
Attribute ScaleWidth.VB_Description = "����/���ö����ڲ���ˮƽ������λ����"
        ScaleWidth = UserControl.ScaleWidth
End Property

Public Property Let ScaleWidth(ByVal New_ScaleWidth As Single)
        UserControl.ScaleWidth() = New_ScaleWidth
        PropertyChanged "ScaleWidth"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=m,m,-1,ToolTipText
Public Property Get ToolTipText() As String
Attribute ToolTipText.VB_Description = "����/���õ�����ڿؼ�����ͣʱ��ʾ���ı���"
        ToolTipText = m.ToolTipText
End Property

Public Property Let ToolTipText(ByVal New_ToolTipText As String)
        m.ToolTipText() = New_ToolTipText
        PropertyChanged "ToolTipText"
End Property

'Ϊ�û��ؼ���ʼ������
Private Sub UserControl_InitProperties()
        Set UserControl.Font = Ambient.Font
End Sub

'�Ӵ������м�������ֵ
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

'������ֵд���洢��
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
