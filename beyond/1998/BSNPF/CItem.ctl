VERSION 5.00
Begin VB.UserControl CItem
   ClientHeight    =   945
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1050
   PropertyPages   =   "CItem.ctx":0000
   ScaleHeight     =   945
   ScaleWidth      =   1050
   Begin VB.PictureBox Icon
      AutoSize        =   -1  'True
      Height          =   540
      Left            =   180
      ScaleHeight     =   480
      ScaleWidth      =   480
      TabIndex        =   1
      TabStop         =   0   'False
      Top             =   0
      Width           =   540
   End
   Begin VB.CommandButton Button
      Caption         =   "Item1"
      BeginProperty Font
         Name            =   "ËÎÌו"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   0
      TabIndex        =   0
      Top             =   600
      Width           =   975
   End
   Begin VB.Label lblCalcLen
      AutoSize        =   -1  'True
      BorderStyle     =   1  'Fixed Single
      Caption         =   "LEN-TESTING"
      BeginProperty Font
         Name            =   "ËÎÌו"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Left            =   60
      TabIndex        =   2
      Top             =   960
      Width           =   1050
   End
End
Attribute VB_Name = "CItem"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "PropPageWizardRun" ,"Yes"
'Event Declarations:
Event IClick() 'MappingInfo=Icon,Icon,-1,Click
Attribute IClick.VB_Description = "Occurs when the user presses and then releases a mouse button over an object."
Event MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=Icon,Icon,-1,MouseDown
Attribute MouseDown.VB_Description = "Occurs when the user presses the mouse button while an object has the focus."
Event MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=Icon,Icon,-1,MouseUp
Attribute MouseUp.VB_Description = "Occurs when the user releases the mouse button while an object has the focus."
Event MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single) 'MappingInfo=Icon,Icon,-1,MouseMove
Attribute MouseMove.VB_Description = "Occurs when the user moves the mouse."
Event CClick() 'MappingInfo=UserControl,UserControl,-1,Click
Attribute CClick.VB_Description = "Occurs when the user presses and then releases a mouse button over an object."
'Event Paint() 'MappingInfo=UserControl,UserControl,-1,Paint
Event Click() 'MappingInfo=Button,Button,-1,Click
Attribute Click.VB_Description = "Occurs when the user presses and then releases a mouse button over an object."
Event DblClick() 'MappingInfo=Icon,Icon,-1,DblClick
Attribute DblClick.VB_Description = "Occurs when the user presses and releases a mouse button and then presses and releases it again over an object."
Event DescChanged()
Attribute DescChanged.VB_Description = "Occured when evalating Desc var or after called ChangeDesc method."
'Default Property Values:
Const m_def_IconName = ""
Const m_def_Alias = ""
'Property Variables:
Dim m_IconName As String
Dim m_Alias As String

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
'MappingInfo=UserControl,UserControl,-1,ForeColor
Public Property Get ForeColor() As OLE_COLOR
Attribute ForeColor.VB_Description = "Returns/sets the foreground color used to display text and graphics in an object."
    ForeColor = UserControl.ForeColor
End Property

Public Property Let ForeColor(ByVal New_ForeColor As OLE_COLOR)
    UserControl.ForeColor() = New_ForeColor
    PropertyChanged "ForeColor"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,Enabled
Public Property Get Enabled() As Boolean
Attribute Enabled.VB_Description = "Returns/sets a value that determines whether an object can respond to user-generated events."
Attribute Enabled.VB_ProcData.VB_Invoke_Property = "Active"
    Enabled = UserControl.Enabled
End Property

Public Property Let Enabled(ByVal New_Enabled As Boolean)
    UserControl.Enabled() = New_Enabled
    PropertyChanged "Enabled"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=Button,Button,-1,Font
Public Property Get Font() As Font
Attribute Font.VB_Description = "Returns a Font object."
Attribute Font.VB_UserMemId = -512
    Set Font = Button.Font
End Property

Public Property Set Font(ByVal New_Font As Font)
    Set Button.Font = New_Font
    PropertyChanged "Font"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=UserControl,UserControl,-1,BackStyle
Public Property Get BackStyle() As Integer
Attribute BackStyle.VB_Description = "Indicates whether a Label or the background of a Shape is transparent or opaque."
Attribute BackStyle.VB_ProcData.VB_Invoke_Property = "Description"
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
Attribute BorderStyle.VB_ProcData.VB_Invoke_Property = "Description"
    BorderStyle = UserControl.BorderStyle
End Property

Public Property Let BorderStyle(ByVal New_BorderStyle As Integer)
    UserControl.BorderStyle() = New_BorderStyle
    PropertyChanged "BorderStyle"
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MemberInfo=5
Public Sub Refresh()
Attribute Refresh.VB_Description = "Make looking comfortabe."
    lblCalcLen.Font = Button.Font
    lblCalcLen.FontSize = Button.FontSize
    lblCalcLen.FontBold = Button.FontBold
    lblCalcLen.FontItalic = Button.FontItalic
    lblCalcLen.Caption = Button.Caption
    lblCalcLen.BorderStyle = 1
    Button.Width = lblCalcLen.Width
    Button.Height = lblCalcLen.Height

    If Button.Width > Icon.Width Then
      lblCalcLen.BorderStyle = 0
      lsplit = Int(Button.Width / (Icon.Width * 2)) + 1
      Button.Height = lblCalcLen.Height * lsplit + 6 * 15
      Button.Width = Button.Width / lsplit + 10
    End If
    Button.Width = Button.Width + 8 * 15

    If Button.Width < Icon.Width Then
      Icon.Left = 0
      Button.Left = (Icon.Width - Button.Width) / 2
      Width = Icon.Width
    Else
      Button.Left = 0
      Icon.Left = (Button.Width - Icon.Width) / 2
      Width = Button.Width
    End If
    Height = Button.Top + Button.Height

    If BorderStyle = 1 Then
      Width = Width + 4 * 15
      Height = Height + 4 * 15
    End If
End Sub

Private Sub Button_Click()
    RaiseEvent Click
End Sub

Private Sub Icon_DblClick()
    RaiseEvent DblClick
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=Icon,Icon,-1,hDC
Public Property Get hDC() As Long
Attribute hDC.VB_Description = "Returns a handle (from Microsoft Windows) to the object's device context."
    hDC = Icon.hDC
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=Button,Button,-1,Caption
Public Property Get Desc() As String
Attribute Desc.VB_Description = "Returns/sets the text displayed in an object's title bar or below an object's icon."
Attribute Desc.VB_ProcData.VB_Invoke_Property = "Description"
    Desc = Button.Caption
End Property

Public Property Let Desc(ByVal New_Desc As String)
    ChangeDesc New_Desc
End Property

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MemberInfo=14
Public Function ChangeDesc(Description As String) As Variant
Attribute ChangeDesc.VB_Description = "Change the description at the bottom of CItem object."
    Button.Caption() = Description
    Refresh
    RaiseEvent DescChanged
    PropertyChanged "Desc"
End Function

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=Icon,Icon,-1,BorderStyle
Public Property Get IconBorderStyle() As Integer
Attribute IconBorderStyle.VB_Description = "Returns/sets the border style for an object."
Attribute IconBorderStyle.VB_ProcData.VB_Invoke_Property = "Description"
    IconBorderStyle = Icon.BorderStyle
End Property

Public Property Let IconBorderStyle(ByVal New_IconBorderStyle As Integer)
    Icon.BorderStyle() = New_IconBorderStyle
    PropertyChanged "IconBorderStyle"
End Property

'Load property values from storage
Private Sub UserControl_ReadProperties(PropBag As PropertyBag)

    UserControl.BackColor = PropBag.ReadProperty("BackColor", &H8000000F)
    UserControl.ForeColor = PropBag.ReadProperty("ForeColor", &H80000012)
    UserControl.Enabled = PropBag.ReadProperty("Enabled", True)
    Set Button.Font = PropBag.ReadProperty("Font", Ambient.Font)
    UserControl.BackStyle = PropBag.ReadProperty("BackStyle", 1)
    UserControl.BorderStyle = PropBag.ReadProperty("BorderStyle", 0)
    Button.Caption = PropBag.ReadProperty("Desc", "Item1")
    Icon.BorderStyle = PropBag.ReadProperty("IconBorderStyle", 1)
    Set Picture = PropBag.ReadProperty("Picture", Nothing)
    m_Alias = PropBag.ReadProperty("Alias", m_def_Alias)
    m_IconName = PropBag.ReadProperty("IconName", m_def_IconName)
End Sub

'Write property values to storage
Private Sub UserControl_WriteProperties(PropBag As PropertyBag)

    Call PropBag.WriteProperty("BackColor", UserControl.BackColor, &H8000000F)
    Call PropBag.WriteProperty("ForeColor", UserControl.ForeColor, &H80000012)
    Call PropBag.WriteProperty("Enabled", UserControl.Enabled, True)
    Call PropBag.WriteProperty("Font", Button.Font, Ambient.Font)
    Call PropBag.WriteProperty("BackStyle", UserControl.BackStyle, 1)
    Call PropBag.WriteProperty("BorderStyle", UserControl.BorderStyle, 0)
    Call PropBag.WriteProperty("Desc", Button.Caption, "Item1")
    Call PropBag.WriteProperty("IconBorderStyle", Icon.BorderStyle, 1)
    Call PropBag.WriteProperty("Picture", Picture, Nothing)
    Call PropBag.WriteProperty("Alias", m_Alias, m_def_Alias)
    Call PropBag.WriteProperty("IconName", m_IconName, m_def_IconName)
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MappingInfo=Icon,Icon,-1,Picture
Public Property Get Picture() As Picture
Attribute Picture.VB_Description = "Returns/sets a graphic to be displayed in a control."
    Set Picture = Icon.Picture
End Property

Public Property Set Picture(ByVal New_Picture As Picture)
    Set Icon.Picture = New_Picture
    PropertyChanged "Picture"
End Property
'''WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'''MemberInfo=14
''Public Function abcd() As Variant
''
''End Function
'Private Sub UserControl_Paint()
'    Refresh
'    RaiseEvent Paint
'End Sub
Private Sub UserControl_Click()
    Refresh
    RaiseEvent CClick
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MemberInfo=13,0,0,
Public Property Get Alias() As String
Attribute Alias.VB_Description = "For using by other objects."
    Alias = m_Alias
End Property

Public Property Let Alias(ByVal New_Alias As String)
    m_Alias = New_Alias
    PropertyChanged "Alias"
End Property

'Initialize Properties for User Control
Private Sub UserControl_InitProperties()
    m_Alias = m_def_Alias
    m_IconName = m_def_IconName
End Sub

'WARNING! DO NOT REMOVE OR MODIFY THE FOLLOWING COMMENTED LINES!
'MemberInfo=13,0,0,
Public Property Get IconName() As String
Attribute IconName.VB_Description = "Service for other objects.\r\n"
    IconName = m_IconName
End Property

Public Property Let IconName(ByVal New_IconName As String)
    m_IconName = New_IconName
    PropertyChanged "IconName"
End Property

Private Sub Icon_Click()
    RaiseEvent IClick
End Sub

Private Sub Icon_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseDown(Button, Shift, X, Y)
End Sub

Private Sub Icon_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseUp(Button, Shift, X, Y)
End Sub

Private Sub Icon_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    RaiseEvent MouseMove(Button, Shift, X, Y)
End Sub
