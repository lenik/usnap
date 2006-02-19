VERSION 5.00
Begin VB.UserControl StateControl
   BackStyle       =   0  'Transparent
   ClientHeight    =   720
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   720
   InvisibleAtRuntime=   -1  'True
   PropertyPages   =   "StateControl.ctx":0000
   ScaleHeight     =   48
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   48
   Begin VB.PictureBox picIcon
      AutoSize        =   -1  'True
      BorderStyle     =   0  'None
      Height          =   240
      Left            =   240
      ScaleHeight     =   16
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   16
      TabIndex        =   1
      Top             =   180
      Visible         =   0   'False
      Width           =   240
   End
   Begin VB.Label lblTitle
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "State"
      Height          =   195
      Left            =   135
      TabIndex        =   0
      Top             =   420
      Width           =   390
   End
   Begin VB.Shape shpOutline
      BackColor       =   &H00FFFFFF&
      FillColor       =   &H8000000F&
      Height          =   720
      Left            =   0
      Top             =   0
      Width           =   720
   End
End
Attribute VB_Name = "StateControl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Attribute VB_Ext_KEY = "PropPageWizardRun" ,"Yes"
Option Explicit
Option Base 0

Private Const LOCATION = "MVCArch::StateControl"
Private Const MAX_COMMANDS = 32
Private Const DEFAULT_TRANSPARENT = False
Private Const DEFAULT_BACKCOLOR = &HFFFFFF
Private Const DEFAULT_FORECOLOR = &H0&
Private Const DEFAULT_BORDERWIDTH = 1
Private Const DEFAULT_BORDERSTYLE = vbBSSolid
Private Const DEFAULT_FONTNAME = "Courier New"
Private Const DEFAULT_FONTSIZE = 9
Private Const DEFAULT_FONTBOLD = False
Private Const DEFAULT_FONTITALIC = False

Public Enum StateStyleConstants
    stateNormal = 0
    stateInternal                       ' No stop
    stateUser                           ' The first user style
End Enum

Private Type StyleInfoType
    Transparent As Boolean
    BackColor As Long
    ForeColor As Long
    BorderWidth As Integer
    BorderStyle As BorderStyleConstants
    FontName As String
    FontSize As Integer
    FontBold As Boolean
    FontItalic As Boolean
    Icon As IPictureDisp
End Type

Public Enum MethodConstants
    methodGoto = 0
    methodCall
End Enum

Private Type StateCommandType
    Name As String                      ' The name will be passed as "message" to Process event
    Default As Boolean                  ' Default command
    Target As String                    ' Target state name
    Method As MethodConstants           ' How to jump into target state
    Visible As Boolean                  ' Button visible
    Title As String                     ' Button text
    Icon As IPictureDisp                ' Button icon
End Type

Private m_Style As StateStyleConstants
Private m_Command(MAX_COMMANDS - 1) As StateCommandType
Private m_Commands As Integer
Private m_Base As String                ' Share the base(StateControl)'s m_Commands

Implements StateObject

Public Event Enter(ByVal PreviousState As StateObject)
Public Event Leave(ByVal NextState As StateObject)
Public Event Process(ByVal Message, Parameters, NextState As StateObject)

Private Function BuiltinState(Style As StateStyleConstants) As StyleInfoType
    With BuiltinState
        ' Default properties
        .Transparent = DEFAULT_TRANSPARENT
        .FontName = DEFAULT_FONTNAME
        .FontSize = DEFAULT_FONTSIZE
        .FontBold = DEFAULT_FONTBOLD
        .FontItalic = DEFAULT_FONTITALIC
        .BackColor = DEFAULT_BACKCOLOR  ' vbWhite
        .ForeColor = DEFAULT_FORECOLOR  ' vbBlack
        .BorderStyle = DEFAULT_BORDERSTYLE
        .BorderWidth = DEFAULT_BORDERWIDTH
        Select Case Style
        Case stateNormal
            .BorderStyle = vbBSSolid
        Case stateInternal
            .BorderStyle = vbBSDot
            .BackColor = &HCCCCCC       ' vbGray
            .FontItalic = True
        Case stateUser
            .BackColor = &HFF0000       ' vbBlue
        End Select
    End With
End Function

Private Property Get StyleInfo() As StyleInfoType
    With StyleInfo
        .Transparent = Transparent
        .BackColor = BackColor
        .ForeColor = ForeColor
        .BorderStyle = BorderStyle
        .BorderWidth = BorderWidth
        .FontName = FontName
        .FontSize = FontSize
        .FontBold = FontBold
        .FontItalic = FontItalic
        Set .Icon = Icon
    End With
End Property

Private Property Let StyleInfo(info As StyleInfoType)
    With info
        shpOutline.BackStyle = IIf(.Transparent, vbTransparent, 1)
        shpOutline.BackColor = .BackColor
        shpOutline.BorderColor = .ForeColor
        shpOutline.BorderWidth = .BorderWidth
        shpOutline.BorderStyle = .BorderStyle
        lblTitle.ForeColor = .ForeColor
        lblTitle.FontName = .FontName
        lblTitle.FontSize = .FontSize
        lblTitle.FontBold = .FontBold
        lblTitle.FontItalic = .FontItalic
        Set picIcon.Picture = .Icon
    End With
End Property

Private Sub StateObject_Enter(ByVal PreviousState As StateObject)
    RaiseEvent Enter(PreviousState)
End Sub

Private Sub StateObject_Leave(ByVal NextState As StateObject)
    RaiseEvent Leave(NextState)
End Sub

Private Function StateObject_Process(ByVal Message As Variant, Parameters As Variant) As StateObject
    Set StateObject_Process = Me
    RaiseEvent Process(Message, Parameters, StateObject_Process)
End Function

Private Sub UserControl_Resize()
    Redraw
    RedrawArrows
End Sub

Private Sub UserControl_InitProperties()
    Style = stateNormal
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    Dim info As StyleInfoType
    With info
        .Transparent = PropBag.ReadProperty("Transparent", DEFAULT_TRANSPARENT)
        .FontName = PropBag.ReadProperty("FontName", DEFAULT_FONTNAME)
        .FontSize = PropBag.ReadProperty("FontSize", DEFAULT_FONTSIZE)
        .FontBold = PropBag.ReadProperty("FontBold", DEFAULT_FONTBOLD)
        .FontItalic = PropBag.ReadProperty("FontItalic", DEFAULT_FONTITALIC)
        .BackColor = PropBag.ReadProperty("BackColor", DEFAULT_BACKCOLOR)
        .ForeColor = PropBag.ReadProperty("ForeColor", DEFAULT_FORECOLOR)
        .BorderStyle = PropBag.ReadProperty("BorderStyle", DEFAULT_BORDERSTYLE)
        .BorderWidth = PropBag.ReadProperty("BorderWidth", DEFAULT_BORDERWIDTH)
        Set .Icon = PropBag.ReadProperty("Icon", Nothing)
    End With
    StyleInfo = info

    m_Commands = PropBag.ReadProperty("Commands", 0)
    Dim i As Integer
    For i = 0 To m_Commands - 1
        With m_Command(i)
            .Name = PropBag.ReadProperty("Name_" & i)
            .Target = PropBag.ReadProperty("Target_" & i)
            .Title = PropBag.ReadProperty("Title_" & i)
            .Default = PropBag.ReadProperty("Default_" & i)
            .Method = PropBag.ReadProperty("Method_" & i)
            .Visible = PropBag.ReadProperty("Visible_" & i)
            Set .Icon = PropBag.ReadProperty("Icon_" & i)
        End With
    Next
    m_Base = PropBag.ReadProperty("Base", "")
    Redraw
    RedrawArrows
    RedrawButtons
End Sub

Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    With StyleInfo
        PropBag.WriteProperty "Transparent", .Transparent
        PropBag.WriteProperty "FontName", .FontName
        PropBag.WriteProperty "FontSize", .FontSize
        PropBag.WriteProperty "FontItalic", .FontItalic
        PropBag.WriteProperty "BackColor", .BackColor
        PropBag.WriteProperty "ForeColor", .ForeColor
        PropBag.WriteProperty "BorderStyle", .BorderStyle
        PropBag.WriteProperty "BorderWidth", .BorderWidth
        PropBag.WriteProperty "Icon", .Icon
    End With

    PropBag.WriteProperty "Commands", m_Commands
    Dim i As Integer
    For i = 0 To m_Commands - 1
        With m_Command(i)
            PropBag.WriteProperty "Name_" & i, .Name
            PropBag.WriteProperty ".Target_" & i, .Target
            PropBag.WriteProperty ".Title_" & i, .Title
            PropBag.WriteProperty ".Default_" & i, .Default
            PropBag.WriteProperty ".Method_" & i, .Method
            PropBag.WriteProperty ".Visible_" & i, .Visible
            PropBag.WriteProperty ".Icon_" & i, .Icon
        End With
    Next
End Sub

Public Property Get Style() As StateStyleConstants
    Style = m_Style
End Property
Public Property Let Style(ByVal newval As StateStyleConstants)
    m_Style = newval
    StyleInfo = BuiltinState(newval)
    Redraw
    RedrawArrows
End Property

Public Property Get Transparent() As Boolean
    Transparent = shpOutline.BackStyle = vbTransparent
End Property
Public Property Let Transparent(ByVal newval As Boolean)
    shpOutline.BackStyle = IIf(newval, vbTransparent, 1) ' 1 == Opaque
    'redraw
End Property

Public Property Get Title() As String
    Title = lblTitle.Caption
End Property
Public Property Let Title(ByVal newval As String)
    lblTitle.Caption = newval
    Redraw                              ' position
End Property

Public Property Get BackColor() As Long
    BackColor = shpOutline.BackColor
End Property
Public Property Let BackColor(ByVal newval As Long)
    shpOutline.BackColor = newval
    'redraw
End Property

Public Property Get ForeColor() As Long
    ' or shpOutline.BorderColor
    ForeColor = lblTitle.ForeColor
End Property
Public Property Let ForeColor(ByVal newval As Long)
    lblTitle.ForeColor = newval
    shpOutline.BorderColor = newval
    Redraw                              ' title, border, arrow
    RedrawArrows
End Property

Private Property Get BorderWidth() As Integer
    BorderWidth = shpOutline.BorderWidth
End Property
Private Property Let BorderWidth(ByVal newval As Integer)
    shpOutline.BorderWidth = newval
    'redraw
End Property

Public Property Get BorderStyle() As BorderStyleConstants
    BorderStyle = shpOutline.BorderStyle
End Property
Public Property Let BorderStyle(ByVal newval As BorderStyleConstants)
    shpOutline.BorderStyle = newval
    'redraw
End Property

Public Property Get FontName() As String
    FontName = lblTitle.FontName
End Property
Public Property Let FontName(ByVal newval As String)
    lblTitle.FontName = newval
    Redraw                              ' position
End Property

Public Property Get FontSize() As Integer
    FontSize = lblTitle.FontSize
End Property
Public Property Let FontSize(ByVal newval As Integer)
    lblTitle.FontSize = newval
    Redraw                              ' position
End Property

Public Property Get FontBold() As Boolean
    FontBold = lblTitle.FontBold
End Property
Public Property Let FontBold(ByVal newval As Boolean)
    lblTitle.FontBold = newval
    Redraw                              ' position
End Property

Public Property Get FontItalic() As Boolean
    FontItalic = lblTitle.FontItalic
End Property
Public Property Let FontItalic(ByVal newval As Boolean)
    lblTitle.FontItalic = newval
    Redraw                              ' position
End Property

Public Property Get Icon() As IPictureDisp
    Set Icon = picIcon.Picture
End Property
Public Property Let Icon(ByVal newval As IPictureDisp)
    Set picIcon.Picture = newval
    picIcon.Visible = Not newval Is Nothing
    Redraw                              ' position
End Property

Public Property Get Commands() As Integer
    Commands = m_Commands
End Property
'Public Property Let Commands(ByVal newval As Integer)
'    Assert newval <= MAX_COMMANDS
'    m_Commands = newval
'End Property

Public Property Get CommandName(ByVal Index As Integer) As String
Attribute CommandName.VB_ProcData.VB_Invoke_Property = "Commands"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandName = m_Command(Index).Name
End Property
Public Property Let CommandName(ByVal Index As Integer, ByVal newval As String)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Name = newval
End Property

Public Property Get CommandDefault(ByVal Index As Integer) As Boolean
Attribute CommandDefault.VB_ProcData.VB_Invoke_Property = "Commands"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandDefault = m_Command(Index).Default
End Property
Public Property Let CommandDefault(ByVal Index As Integer, ByVal newval As Boolean)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Default = newval
    RedrawArrows
    RedrawButtons
End Property

Public Property Get CommandTarget(ByVal Index As Integer) As String
Attribute CommandTarget.VB_ProcData.VB_Invoke_Property = "Commands"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandTarget = m_Command(Index).Target
End Property
Public Property Let CommandTarget(ByVal Index As Integer, ByVal newval As String)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Target = newval
    RedrawArrows
End Property

Public Property Get CommandMethod(ByVal Index As Integer) As MethodConstants
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandMethod = m_Command(Index).Method
End Property
Public Property Let CommandMethod(ByVal Index As Integer, ByVal newval As MethodConstants)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Method = newval
    RedrawArrows
End Property

Public Property Get CommandVisible(ByVal Index As Integer) As Boolean
Attribute CommandVisible.VB_ProcData.VB_Invoke_Property = "Commands"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandVisible = m_Command(Index).Visible
End Property
Public Property Let CommandVisible(ByVal Index As Integer, ByVal newval As Boolean)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Visible = newval
    RedrawButtons
End Property

Public Property Get CommandTitle(ByVal Index As Integer) As String
Attribute CommandTitle.VB_ProcData.VB_Invoke_Property = "Commands"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandTitle = m_Command(Index).Title
End Property
Public Property Let CommandTitle(ByVal Index As Integer, ByVal newval As String)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Title = newval
    RedrawArrows
    RedrawButtons
End Property

Public Property Get CommandIcon(ByVal Index As Integer) As IPictureDisp
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    Set CommandIcon = m_Command(Index).Icon
End Property
Public Property Let CommandIcon(ByVal Index As Integer, ByVal newval As IPictureDisp)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    Set m_Command(Index).Icon = newval
    RedrawButtons
End Property

Public Property Get Base() As String
    Base = m_Base
End Property
Public Property Let Base(ByVal newval As String)
    m_Base = newval
    RedrawArrows
    RedrawButtons
End Property

Public Sub AddCommand(ByVal Name As String, ByVal Target As String, _
        Optional ByVal Title As String = "", _
        Optional ByVal Default As Boolean = False, _
        Optional ByVal Method As MethodConstants = methodGoto, _
        Optional ByVal Visible As Boolean = True, _
        Optional ByVal Icon As IPictureDisp = Nothing)
    Assert m_Commands < MAX_COMMANDS, "Too many commands: a state object could have a maximum of " & MAX_COMMANDS & " commands at most", LOCATION
    Name = Trim(Name)
    Title = Trim(Title)
    If Title = "" Then Title = Name
    With m_Command(m_Commands)
        .Name = Name
        .Target = Target
        .Title = Title
        .Default = Default
        .Method = Method
        .Visible = Visible
        Set .Icon = Icon
    End With
    m_Commands = m_Commands + 1
End Sub

Public Sub RemoveCommand(ByVal Index As Integer)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    Dim i As Integer
    For i = Index + 1 To m_Commands - 1
        With m_Command(i - 1)
            .Name = m_Command(i).Name
            .Title = m_Command(i).Title
            .Target = m_Command(i).Target
            .Default = m_Command(i).Default
            .Method = m_Command(i).Method
            .Visible = m_Command(i).Visible
            Set .Icon = m_Command(i).Icon
        End With
    Next
    m_Commands = m_Commands - 1
End Sub

Public Sub Redraw()
    shpOutline.Width = ScaleWidth
    shpOutline.Height = ScaleHeight
    lblTitle.Left = (ScaleWidth - lblTitle.Width) / 2
    picIcon.Left = (ScaleWidth - picIcon.Width) / 2
    If picIcon.Visible Then
        Dim SEP_SPACE_Y As Integer
        SEP_SPACE_Y = 3 * Screen.TwipsPerPixelY
        picIcon.Top = (ScaleHeight - (lblTitle.Height + picIcon.Height + SEP_SPACE_Y)) / 2
        lblTitle.Top = picIcon.Top + picIcon.Height + SEP_SPACE_Y
    Else
        lblTitle.Top = (ScaleHeight - lblTitle.Height) / 2
    End If
End Sub

Public Sub RedrawArrows()
    ' Using outline'bordercolor to draw arrow-line
    ' Using title'forecolor to draw caption
End Sub

Public Sub RedrawButtons()
    ' Notify parent controller
End Sub
