VERSION 5.00
Begin VB.UserControl ctlButton
   ClientHeight    =   2880
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   3840
   PropertyPages   =   "ctlBtn.ctx":0000
   ScaleHeight     =   2880
   ScaleWidth      =   3840
   Begin VB.PictureBox picButBack
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00C0FFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   444
      Left            =   480
      ScaleHeight     =   450
      ScaleWidth      =   975
      TabIndex        =   0
      Top             =   720
      Width           =   972
      Begin VB.Label lblButText
         Appearance      =   0  'Flat
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BackStyle       =   0  'Transparent
         Caption         =   "����A"
         BeginProperty Font
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   180
         Left            =   120
         TabIndex        =   1
         Top             =   120
         Width           =   504
      End
   End
End
Attribute VB_Name = "ctlButton"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False

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
Event MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseDown
Attribute MouseDown.VB_Description = "���û���ӵ�н���Ķ����ϰ�����갴ťʱ������"
Event MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseMove
Attribute MouseMove.VB_Description = "���û��ƶ����ʱ������"
Event MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single) 'MappingInfo=UserControl,UserControl,-1,MouseUp
Attribute MouseUp.VB_Description = "���û���ӵ�н���Ķ������ͷ���귢����"

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=lblButText,lblButText,-1,BackColor
Public Property Get BackColor() As OLE_COLOR
Attribute BackColor.VB_Description = "����/���ö������ı���ͼ�εı���ɫ��"
    BackColor = lblButText.BackColor
End Property

Public Property Let BackColor(ByVal New_BackColor As OLE_COLOR)
    lblButText.BackColor() = New_BackColor
    PropertyChanged "BackColor"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=lblButText,lblButText,-1,ForeColor
Public Property Get ForeColor() As OLE_COLOR
Attribute ForeColor.VB_Description = "����/���ö������ı���ͼ�ε�ǰ��ɫ��"
    ForeColor = lblButText.ForeColor
End Property

Public Property Let ForeColor(ByVal New_ForeColor As OLE_COLOR)
    lblButText.ForeColor() = New_ForeColor
    PropertyChanged "ForeColor"
End Property

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
'MappingInfo=lblButText,lblButText,-1,Font
Public Property Get Font() As Font
Attribute Font.VB_Description = "����һ�� Font ����"
Attribute Font.VB_UserMemId = -512
    Set Font = lblButText.Font
End Property

Public Property Set Font(ByVal New_Font As Font)
    Set lblButText.Font = New_Font
    PropertyChanged "Font"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=lblButText,lblButText,-1,BackStyle
Public Property Get BackStyle() As Integer
Attribute BackStyle.VB_Description = "ָ�� Label �� Shape �ı�����ʽ��͸���Ļ��ǲ�͸���ġ�"
    BackStyle = lblButText.BackStyle
End Property

Public Property Let BackStyle(ByVal New_BackStyle As Integer)
    lblButText.BackStyle() = New_BackStyle
    PropertyChanged "BackStyle"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=picButBack,picButBack,-1,BorderStyle
Public Property Get BorderStyle() As Integer
Attribute BorderStyle.VB_Description = "����/���ö���ı߿���ʽ��"
    BorderStyle = picButBack.BorderStyle
End Property

Public Property Let BorderStyle(ByVal New_BorderStyle As Integer)
    picButBack.BorderStyle() = New_BorderStyle
    PropertyChanged "BorderStyle"
End Property

'ע�⣡��Ҫɾ�����޸����б�ע�͵��У�
'MappingInfo=UserControl,UserControl,-1,Refresh
Public Sub Refresh()
Attribute Refresh.VB_Description = "ǿ����ȫ�ػ�һ������"
    UserControl.Refresh
End Sub

Private Sub lblButText_Click()
    RaiseEvent Click
End Sub

Private Sub lblButText_DblClick()
    RaiseEvent DblClick
End Sub

Private Sub lblButText_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseDown(Button, Shift, x, y)
End Sub

Private Sub lblButText_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseMove(Button, Shift, x, y)
End Sub

Private Sub lblButText_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseUp(Button, Shift, x, y)
End Sub

Private Sub picButBack_Click()
    RaiseEvent Click
End Sub

Private Sub picButBack_DblClick()
    RaiseEvent DblClick
End Sub

Private Sub picButBack_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseDown(Button, Shift, x, y)
End Sub

Private Sub picButBack_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseMove(Button, Shift, x, y)
End Sub

Private Sub picButBack_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseUp(Button, Shift, x, y)
End Sub

Private Sub picButBack_Resize()
    Dim x As Single, y As Single, w As Single, h As Single
    x = picButBack.Left: y = picButBack.Top
    w = picButBack.Width: h = picButBack.Height
    lblButText.AutoSize = False
    'if lblbuttext.Tag=PutH
    lblButText.Left = (w - lblButText.Width) / 2
    lblButText.Top = (h - lblButText.Height) / 2


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

Private Sub UserControl_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseDown(Button, Shift, x, y)
End Sub

Private Sub UserControl_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseMove(Button, Shift, x, y)
End Sub

Private Sub UserControl_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
    RaiseEvent MouseUp(Button, Shift, x, y)
End Sub

'�Ӵ������м�������ֵ
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)

    lblButText.BackColor = PropBag.ReadProperty("BackColor", &H80000005)
    lblButText.ForeColor = PropBag.ReadProperty("ForeColor", &HFF0000)
    UserControl.Enabled = PropBag.ReadProperty("Enabled", True)
    Set lblButText.Font = PropBag.ReadProperty("Font", Ambient.Font)
    lblButText.BackStyle = PropBag.ReadProperty("BackStyle", 0)
    picButBack.BorderStyle = PropBag.ReadProperty("BorderStyle", 0)
End Sub

Private Sub UserControl_Resize()
    picButBack_Resize
End Sub

'������ֵд���洢��
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)

    Call PropBag.WriteProperty("BackColor", lblButText.BackColor, &H80000005)
    Call PropBag.WriteProperty("ForeColor", lblButText.ForeColor, &HFF0000)
    Call PropBag.WriteProperty("Enabled", UserControl.Enabled, True)
    Call PropBag.WriteProperty("Font", lblButText.Font, Ambient.Font)
    Call PropBag.WriteProperty("BackStyle", lblButText.BackStyle, 0)
    Call PropBag.WriteProperty("BorderStyle", picButBack.BorderStyle, 0)
End Sub