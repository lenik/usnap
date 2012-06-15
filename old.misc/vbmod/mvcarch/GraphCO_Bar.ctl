VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#28.0#0"; "vbuserext.ocx"
Begin VB.UserControl GraphCO_Bar
   Alignable       =   -1  'True
   ClientHeight    =   510
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   7485
   PropertyPages   =   "GraphCO_Bar.ctx":0000
   ScaleHeight     =   34
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   499
   Begin VB.CommandButton Button
      Caption         =   "Button"
      Height          =   315
      Index           =   0
      Left            =   6240
      TabIndex        =   0
      Top             =   120
      Visible         =   0   'False
      Width           =   1035
   End
   Begin VB.Label StatusText
      AutoSize        =   -1  'True
      Caption         =   "Controller Status Bar"
      Height          =   195
      Left            =   600
      TabIndex        =   2
      Top             =   180
      Width           =   1440
   End
   Begin VBUserExt.Animate StatusIcon
      Height          =   360
      Left            =   120
      TabIndex        =   1
      Top             =   60
      Width           =   360
      _ExtentX        =   635
      _ExtentY        =   635
      Looped          =   -1  'True
   End
End
Attribute VB_Name = "GraphCO_Bar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "MVCArch::GraphCO_Bar"

Private Const MAX_BUTTONS               As Integer = 16
Private Const MIN_BUTTON_WIDTH          As Integer = 30

Private Const DEFAULT_MARGINLEFT        As Integer = 5
Private Const DEFAULT_MARGINRIGHT       As Integer = 10
Private Const DEFAULT_MARGINTOP         As Integer = 2
Private Const DEFAULT_MARGINBOTTOM      As Integer = 2
Private Const DEFAULT_PADDING           As Integer = 3
Private Const DEFAULT_STRETCH           As Boolean = True
Private Const DEFAULT_ICONSIZE          As Integer = 24
Private Const DEFAULT_ICONINFO          As String = ","
Private Const DEFAULT_TEXT              As String = "Controller Status Bar"

Private m_Context As Object
Private m_ControllerName As String
Private m_Controller As GraphCO

Private m_MarginLeft As Single
Private m_MarginRight As Single
Private m_MarginTop As Single
Private m_MarginBottom As Single

Private m_Padding As Single             ' Between buttons
Private m_MinTextSize As Single         ' Min size of status text panel
Private m_Stretch As Boolean            ' Stretch text font and icon picture

Private WithEvents Ker As FastAlgLib.SAOT
Attribute Ker.VB_VarHelpID = -1

Property Get KerInfo() As String
    Dim i As Integer
    For i = 0 To Ker.SlotAllocated - 1
        KerInfo = KerInfo & Ker.FindSlot(i) & " "
    Next
End Property

Public Property Get IconInfo() As String
    IconInfo = StatusIcon.PackedSteps
End Property
Public Property Let IconInfo(ByVal newval As String)
    StatusIcon.PackedSteps = newval
    PropertyChanged "IconInfo"
End Property

Public Property Get Text() As String
    Text = StatusText.Caption
End Property
Public Property Let Text(ByVal newval As String)
    StatusText.Caption = newval
    PropertyChanged "Text"
End Property

Public Function AddCommand(ByVal cmd As StateObjectCommand) As Integer
    With Button(Ker.SlotAdd)
        .Caption = cmd.Title
        .Tag = cmd.Name
        'Set .Picture = cmd.Icon
    End With
    Layout
End Function

Public Sub RemoveCommand(ByVal Index As Integer)
    Ker.SlotRemove Index
    Layout
End Sub

Public Sub ResetCommand()
    Ker.Clear
End Sub

Private Sub Layout()
    If m_Stretch Then
        StatusIcon.Left = m_MarginLeft
        StatusIcon.Top = m_MarginTop
        StatusIcon.Height = ScaleHeight - StatusIcon.Top * 2
        StatusIcon.Width = StatusIcon.Height
        StatusText.Left = StatusIcon.Left + StatusIcon.Width + m_Padding
        StatusText.FontSize = (StatusIcon.Height - m_MarginTop - m_MarginBottom) * 0.75
        StatusText.Top = (ScaleHeight - StatusText.Height) / 2
    Else
        StatusIcon.Left = m_MarginLeft
        StatusIcon.Top = (ScaleHeight - StatusIcon.Height) / 2
        StatusText.Left = StatusIcon.Left + StatusIcon.Width + m_Padding
        StatusText.Top = (ScaleHeight - StatusText.Height) / 2
    End If

    If Ker.Size = 0 Then Exit Sub

    Const TAB_LAST = 10000
    Dim slots() As Long
    Dim BtnWidth As Single
    Dim i As Integer
    Dim iPrev As Integer
    slots = Ker.SortSlots
    BtnWidth = (ScaleWidth - (StatusText.Left + StatusText.Width + m_Padding) _
                - m_MarginRight) / Ker.Size - m_Padding
    If BtnWidth < MIN_BUTTON_WIDTH Then BtnWidth = MIN_BUTTON_WIDTH

    iPrev = slots(0)
    Button(iPrev).Left = ScaleWidth - m_MarginRight - BtnWidth
    Button(iPrev).Width = BtnWidth
    For i = 1 To Ker.Size - 1
        With Button(slots(i))
            If .Visible Then
                .Left = Button(iPrev).Left - BtnWidth - m_Padding
                .Width = BtnWidth
                .TabIndex = TAB_LAST
                iPrev = i
            End If
        End With
    Next
End Sub

Private Property Get Context() As Object
    If m_Context Is Nothing Then Set m_Context = Parent
    Set Context = m_Context
End Property

Private Property Get Controller() As GraphCO
    If m_Controller Is Nothing Then
        Set m_Controller = FindController(Context, m_ControllerName)
    End If
    Set Controller = m_Controller
End Property

Private Sub Button_Click(Index As Integer)
    Controller.Process Button(Index).Tag
End Sub

Private Sub Ker_Add(ByVal slot As Long, ByVal Index As Long)
    On Error GoTo AlreadyLoaded
    Load Button(slot)
AlreadyLoaded:
    Button(slot).Visible = True
End Sub

Private Sub Ker_Remove(ByVal slot As Long, ByVal Index As Long)
    On Error GoTo NotLoaded
    Button(slot).Visible = False
NotLoaded:
End Sub

Public Property Get MarginLeft() As Single
    MarginLeft = m_MarginLeft
End Property
Public Property Let MarginLeft(ByVal newval As Single)
    m_MarginLeft = newval
    PropertyChanged "MarginLeft"
    Layout
End Property

Public Property Get MarginRight() As Single
    MarginRight = m_MarginRight
End Property
Public Property Let MarginRight(ByVal newval As Single)
    m_MarginRight = newval
    PropertyChanged "MarginRight"
    Layout
End Property

Public Property Get MarginTop() As Single
    MarginTop = m_MarginTop
End Property
Public Property Let MarginTop(ByVal newval As Single)
    m_MarginTop = newval
    PropertyChanged "MarginTop"
    Layout
End Property

Public Property Get MarginBottom() As Single
    MarginBottom = m_MarginBottom
End Property
Public Property Let MarginBottom(ByVal newval As Single)
    m_MarginBottom = newval
    PropertyChanged "MarginBottom"
    Layout
End Property

Public Property Get Padding() As Single
    Padding = m_Padding
End Property
Public Property Let Padding(ByVal newval As Single)
    m_Padding = newval
    PropertyChanged "Padding"
    Layout
End Property

Public Property Get MinTextSize() As Single
    MinTextSize = m_MinTextSize
End Property
Public Property Let MinTextSize(ByVal newval As Single)
    m_MinTextSize = newval
    PropertyChanged "MinTextSize"
    Layout
End Property

Public Property Get Stretch() As Boolean
    Stretch = m_Stretch
End Property
Public Property Let Stretch(ByVal newval As Boolean)
    m_Stretch = newval
    PropertyChanged "Stretch"
    Layout
End Property

Public Property Get Appearance() As Integer
Attribute Appearance.VB_Description = "Returns/sets whether or not an object is painted at run time with 3-D effects."
    Appearance = UserControl.Appearance
End Property
Public Property Let Appearance(ByVal New_Appearance As Integer)
    UserControl.Appearance() = New_Appearance
    PropertyChanged "Appearance"
End Property

Public Property Get FontUnderline() As Boolean
Attribute FontUnderline.VB_Description = "Returns/sets underline font styles."
    FontUnderline = StatusText.FontUnderline
End Property
Public Property Let FontUnderline(ByVal newval As Boolean)
    StatusText.FontUnderline = newval
    Dim i As Integer
    For i = 0 To Ker.Size - 1
        Button(Ker.FindIndex(i)).FontUnderline = newval
    Next
    PropertyChanged "FontUnderline"
End Property

Public Property Get FontStrikethru() As Boolean
    FontStrikethru = StatusText.FontStrikethru
End Property
Public Property Let FontStrikethru(ByVal newval As Boolean)
    StatusText.FontStrikethru = newval
    Dim i As Integer
    For i = 0 To Ker.Size - 1
        Button(Ker.FindIndex(i)).FontStrikethru = newval
    Next
    PropertyChanged "FontStrikethru"
End Property

Public Property Get FontSize() As Single
    FontSize = StatusText.FontSize
End Property
Public Property Let FontSize(ByVal newval As Single)
    StatusText.FontSize = newval
    Dim i As Integer
    For i = 0 To Ker.Size - 1
        Button(Ker.FindIndex(i)).FontSize = newval
    Next
    PropertyChanged "FontSize"
End Property

Public Property Get FontName() As String
Attribute FontName.VB_Description = "Specifies the name of the font that appears in each row for the given level."
    FontName = StatusText.FontName
End Property
Public Property Let FontName(ByVal newval As String)
    StatusText.FontName = newval
    Dim i As Integer
    For i = 0 To Ker.Size - 1
        Button(Ker.FindIndex(i)).FontName = newval
    Next
    PropertyChanged "FontName"
End Property

Public Property Get FontItalic() As Boolean
    FontItalic = StatusText.FontItalic
End Property
Public Property Let FontItalic(ByVal newval As Boolean)
    StatusText.FontItalic = newval
    Dim i As Integer
    For i = 0 To Ker.Size - 1
        Button(Ker.FindIndex(i)).FontItalic = newval
    Next
    PropertyChanged "FontItalic"
End Property

Public Property Get FontBold() As Boolean
    FontBold = StatusText.FontBold
End Property
Public Property Let FontBold(ByVal newval As Boolean)
    StatusText.FontBold = newval
    Dim i As Integer
    For i = 0 To Ker.Size - 1
        Button(Ker.FindIndex(i)).FontBold = newval
    Next
    PropertyChanged "FontBold"
End Property

Public Property Get Font() As StdFont
    Set Font = StatusText.Font
End Property
Public Property Set Font(ByVal newval As StdFont)
    Set StatusText.Font = newval
    Dim i As Integer
    For i = 0 To Ker.Size - 1
        Set Button(Ker.FindIndex(i)).Font = newval
    Next
    PropertyChanged "Font"
End Property

Private Sub UserControl_Initialize()
    Set Ker = New FastAlgLib.SAOT
End Sub

Private Sub UserControl_InitProperties()
    m_MarginLeft = DEFAULT_MARGINLEFT
    m_MarginRight = DEFAULT_MARGINRIGHT
    m_MarginTop = DEFAULT_MARGINTOP
    m_MarginBottom = DEFAULT_MARGINBOTTOM
    m_Padding = DEFAULT_PADDING
    m_Stretch = DEFAULT_STRETCH
    Layout
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    m_MarginLeft = PropBag.ReadProperty("MarginLeft", DEFAULT_MARGINLEFT)
    m_MarginRight = PropBag.ReadProperty("MarginRight", DEFAULT_MARGINRIGHT)
    m_MarginTop = PropBag.ReadProperty("MarginTop", DEFAULT_MARGINTOP)
    m_MarginBottom = PropBag.ReadProperty("MarginBottom", DEFAULT_MARGINBOTTOM)
    m_Padding = PropBag.ReadProperty("Padding", DEFAULT_PADDING)
    m_Stretch = PropBag.ReadProperty("Stretch", DEFAULT_STRETCH)
    IconInfo = PropBag.ReadProperty("IconInfo", DEFAULT_ICONINFO)
    Text = PropBag.ReadProperty("Text", DEFAULT_TEXT)

    UserControl.Appearance = PropBag.ReadProperty("Appearance", 1)
    FontUnderline = PropBag.ReadProperty("FontUnderline", UserControl.FontUnderline)
    FontStrikethru = PropBag.ReadProperty("FontStrikethru", UserControl.FontStrikethru)
    FontSize = PropBag.ReadProperty("FontSize", UserControl.FontSize)
    FontName = PropBag.ReadProperty("FontName", UserControl.FontName)
    FontItalic = PropBag.ReadProperty("FontItalic", UserControl.FontItalic)
    FontBold = PropBag.ReadProperty("FontBold", UserControl.FontBold)
    Set Font = PropBag.ReadProperty("Font", Ambient.Font)

    Layout
End Sub

Private Sub UserControl_Resize()
    Layout
End Sub

Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    Call PropBag.WriteProperty("MarginLeft", m_MarginLeft, DEFAULT_MARGINLEFT)
    Call PropBag.WriteProperty("MarginRight", m_MarginRight, DEFAULT_MARGINRIGHT)
    Call PropBag.WriteProperty("MarginTop", m_MarginTop, DEFAULT_MARGINTOP)
    Call PropBag.WriteProperty("MarginBottom", m_MarginBottom, DEFAULT_MARGINBOTTOM)
    Call PropBag.WriteProperty("Padding", m_Padding, DEFAULT_PADDING)
    Call PropBag.WriteProperty("Stretch", m_Stretch, DEFAULT_STRETCH)
    Call PropBag.WriteProperty("IconInfo", IconInfo, DEFAULT_ICONINFO)
    Call PropBag.WriteProperty("Text", Text, DEFAULT_TEXT)

    Call PropBag.WriteProperty("Appearance", UserControl.Appearance, 1)
    Call PropBag.WriteProperty("FontUnderline", StatusText.FontUnderline, UserControl.FontUnderline)
    Call PropBag.WriteProperty("FontStrikethru", StatusText.FontStrikethru, UserControl.FontStrikethru)
    Call PropBag.WriteProperty("FontSize", StatusText.FontSize, UserControl.FontSize)
    Call PropBag.WriteProperty("FontName", StatusText.FontName, UserControl.FontName)
    Call PropBag.WriteProperty("FontItalic", StatusText.FontItalic, UserControl.FontItalic)
    Call PropBag.WriteProperty("FontBold", StatusText.FontBold, UserControl.FontBold)
    Call PropBag.WriteProperty("Font", StatusText.Font, Ambient.Font)
End Sub
