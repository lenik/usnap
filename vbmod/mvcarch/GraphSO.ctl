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
   ToolboxBitmap   =   "StateControl.ctx":001C
   Windowless      =   -1  'True
   Begin VB.Image imgIcon
      Height          =   360
      Left            =   180
      Stretch         =   -1  'True
      Top             =   120
      Visible         =   0   'False
      Width           =   360
   End
   Begin VB.Label lblTitle
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "State"
      Height          =   195
      Left            =   180
      TabIndex        =   0
      Top             =   480
      Width           =   390
   End
   Begin VB.Shape shpOutline
      BackColor       =   &H00FFFFFF&
      FillColor       =   &H8000000F&
      Height          =   720
      Left            =   0
      Shape           =   2  'Oval
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

Private Const LOCATION                  As String = "MVCArch::StateControl"
Private Const MAX_COMMANDS              As String = 32
Private Const DEFAULT_TRANSPARENT       As Boolean = False
Private Const DEFAULT_BACKCOLOR         As Long = &HFFFFFF
Private Const DEFAULT_FORECOLOR         As Long = &H0&
Private Const DEFAULT_BORDERWIDTH       As Integer = 1
Private Const DEFAULT_BORDERSTYLE       As Integer = vbBSSolid
Private Const DEFAULT_FONTNAME          As String = "Courier New"
Private Const DEFAULT_FONTSIZE          As Integer = 9
Private Const DEFAULT_FONTBOLD          As Boolean = False
Private Const DEFAULT_FONTITALIC        As Boolean = False
Private Const DEFAULT_TITLE             As String = "State"
Private Const DEFAULT_CONTROLLERNAME    As String = ""

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

Private Type StateCommandType
    Name As String                      ' The name will be passed as "message" to Process event
    Default As Boolean                  ' Default command
    TargetName As String                ' Target state name
    Method As MethodConstants           ' How to jump into TargetName state
    Visible As Boolean                  ' Button visible
    Title As String                     ' Button text
    Icon As IPictureDisp                ' Button icon
End Type

Private m_Style As StateStyleConstants
Private m_ControllerName As String      ' Owner controller name
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
        Set imgIcon.Picture = .Icon
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

Private Sub UserControl_HitTest(x As Single, Y As Single, HitResult As Integer)
    Dim a As Single, b As Single, z As Single
    Const FUZZY = 0.05
    a = ScaleWidth / 2
    b = ScaleHeight / 2
    z = ((x - a) / a) ^ 2 + ((Y - b) / b) ^ 2

    If z < 1 - FUZZY Then
        If shpOutline.BackStyle = vbTransparent Then
            HitResult = vbHitResultTransparent
        Else
            HitResult = vbHitResultHit
        End If
    ElseIf x > 1 + FUZZY Then
        HitResult = vbHitResultOutside
    Else
        HitResult = vbHitResultHit
    End If
End Sub

Private Sub UserControl_Resize()
    Redraw
    RedrawArrows
End Sub

Private Sub UserControl_Show()
    Redraw
    RedrawArrows
    RedrawButtons
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
    lblTitle.Caption = PropBag.ReadProperty("Title", DEFAULT_TITLE)
    m_ControllerName = PropBag.ReadProperty("ControllerName", DEFAULT_CONTROLLERNAME)
    m_Commands = PropBag.ReadProperty("Commands", 0)
    Dim i As Integer
    For i = 0 To m_Commands - 1
        With m_Command(i)
            .Name = PropBag.ReadProperty("Name_" & i)
            .TargetName = PropBag.ReadProperty("TargetName_" & i)
            .Title = PropBag.ReadProperty("Title_" & i)
            .Default = PropBag.ReadProperty("Default_" & i)
            .Method = PropBag.ReadProperty("Method_" & i)
            .Visible = PropBag.ReadProperty("Visible_" & i)
            Set .Icon = PropBag.ReadProperty("Icon_" & i, Nothing)
        End With
    Next
    m_Base = PropBag.ReadProperty("Base", "")
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
    PropBag.WriteProperty "Title", lblTitle.Caption
    PropBag.WriteProperty "ControllerName", m_ControllerName
    PropBag.WriteProperty "Commands", m_Commands
    Dim i As Integer
    For i = 0 To m_Commands - 1
        With m_Command(i)
            PropBag.WriteProperty "Name_" & i, .Name
            PropBag.WriteProperty "TargetName_" & i, .TargetName
            PropBag.WriteProperty "Title_" & i, .Title
            PropBag.WriteProperty "Default_" & i, .Default
            PropBag.WriteProperty "Method_" & i, .Method
            PropBag.WriteProperty "Visible_" & i, .Visible
            PropBag.WriteProperty "Icon_" & i, .Icon
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
    Set Icon = imgIcon.Picture
End Property
Public Property Let Icon(ByVal newval As IPictureDisp)
    Set imgIcon.Picture = newval
    imgIcon.Visible = Not newval Is Nothing
    Redraw                              ' position
End Property

Private Property Get Controller() As ControllerObject
    On Error GoTo NotExisted
    Set Controller = UserControl.ParentControls(m_ControllerName)
NotExisted:
End Property

Public Property Get Commands() As Integer
    Commands = m_Commands
End Property
Public Property Let Commands(ByVal newval As Integer)
    Assert newval <= MAX_COMMANDS
    If newval < m_Commands Then
        m_Commands = newval             ' Quickly removes
        RedrawArrows
        RedrawButtons
    End If
End Property

Public Property Get CommandName(ByVal Index As Integer) As String
Attribute CommandName.VB_ProcData.VB_Invoke_Property = "PropertyPage1"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandName = m_Command(Index).Name
End Property
Public Property Let CommandName(ByVal Index As Integer, ByVal newval As String)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Name = newval
End Property

Public Property Get CommandDefault(ByVal Index As Integer) As Boolean
Attribute CommandDefault.VB_ProcData.VB_Invoke_Property = "PropertyPage1"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandDefault = m_Command(Index).Default
End Property
Public Property Let CommandDefault(ByVal Index As Integer, ByVal newval As Boolean)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Default = newval
    RedrawArrows
    RedrawButtons
End Property

Public Property Get CommandTargetName(ByVal Index As Integer) As String
Attribute CommandTargetName.VB_ProcData.VB_Invoke_Property = "PropertyPage1"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandTargetName = m_Command(Index).TargetName
End Property
Public Property Let CommandTargetName(ByVal Index As Integer, ByVal newval As String)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).TargetName = newval
    RedrawArrows
End Property

Private Property Get CommandTarget(ByVal Index As Integer) As Object
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    On Error GoTo NotExisted
    Set CommandTarget = Siblings.Objects.Item(m_Command(Index).TargetName)
NotExisted:
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
Attribute CommandVisible.VB_ProcData.VB_Invoke_Property = "PropertyPage1"
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    CommandVisible = m_Command(Index).Visible
End Property
Public Property Let CommandVisible(ByVal Index As Integer, ByVal newval As Boolean)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    m_Command(Index).Visible = newval
    RedrawButtons
End Property

Public Property Get CommandTitle(ByVal Index As Integer) As String
Attribute CommandTitle.VB_ProcData.VB_Invoke_Property = "PropertyPage1"
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

Public Sub AddCommand(ByVal Name As String, ByVal TargetName As String, _
        Optional ByVal Title As String = "", _
        Optional ByVal Default As Boolean = False, _
        Optional ByVal Method As MethodConstants = methodGoto, _
        Optional ByVal Visible As Boolean = True, _
        Optional ByVal Icon As IPictureDisp = Nothing)
    Assert m_Commands < MAX_COMMANDS, "Too many commands: a state object could have a maximum of " & MAX_COMMANDS & " commands at most", LOCATION
    Assert Method = methodGoto Or Method = methodCall
    Name = Trim(Name)
    Title = Trim(Title)
    If Title = "" Then Title = Name
    With m_Command(m_Commands)
        .Name = Name                    ' The behavior of duplicated names is undefined.
        .TargetName = TargetName                ' Undefined TargetName will exit the controller (with exit-state = this)
        .Title = Title
        .Default = Default              ' More than 1 commands have default property set, then only one will be the default.
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
            .TargetName = m_Command(i).TargetName
            .Default = m_Command(i).Default
            .Method = m_Command(i).Method
            .Visible = m_Command(i).Visible
            Set .Icon = m_Command(i).Icon
        End With
    Next
    m_Commands = m_Commands - 1
    RedrawArrows
    RedrawButtons
End Sub

Public Sub ResetCommand()
    m_Commands = 0
    RedrawArrows
    RedrawButtons
End Sub

Friend Property Get Siblings() As Siblings
    Set Siblings = New Siblings
    Siblings.SetEnumed UserControl.Parent.Controls, UserControl.Parent.Name
End Property

Friend Sub SetCommands(cmdprop, sa As SAOT)
    Dim slots() As Long
    Dim i As Integer
    Dim cmd As StateControl_Command
    slots = sa.SortSlots
    Assert sa.Size <= MAX_COMMANDS, "Too many commands", LOCATION
    For i = 0 To sa.Size - 1
        Set cmd = cmdprop(slots(i))
        With m_Command(i)
            .Name = cmd.CommandName
            .TargetName = cmd.CommandTarget
            .Method = cmd.CommandMethod
            .Default = cmd.CommandDefault
            .Visible = cmd.CommandVisible
            .Title = cmd.CommandTitle
            '.Icon = cmd.CommandIcon
        End With
    Next
    m_Commands = sa.Size
    RedrawArrows
    RedrawButtons
    UserControl.PropertyChanged
End Sub

Private Property Get This() As Object
    For Each This In UserControl.ParentControls
        If This Is Me Then Exit Property
    Next
End Property
Public Property Get ThisName() As String
    If Not This Is Nothing Then ThisName = This.Name
End Property
Private Property Get ThisLeft() As Single
    If Not This Is Nothing Then ThisLeft = This.Left
End Property
Private Property Get ThisTop() As Single
    If Not This Is Nothing Then ThisTop = This.Top
End Property

Public Sub Redraw()
    shpOutline.Width = ScaleWidth
    shpOutline.Height = ScaleHeight
    lblTitle.Left = (ScaleWidth - lblTitle.Width) / 2
    imgIcon.Left = (ScaleWidth - imgIcon.Width) / 2
    If imgIcon.Visible Then
        Dim SEP_SPACE_Y As Integer
        SEP_SPACE_Y = 2 * Screen.TwipsPerPixelY
        imgIcon.Top = (ScaleHeight - (lblTitle.Height + imgIcon.Height + SEP_SPACE_Y)) / 2
        lblTitle.Top = imgIcon.Top + imgIcon.Height + SEP_SPACE_Y
    Else
        lblTitle.Top = (ScaleHeight - lblTitle.Height) / 2
    End If
End Sub

Public Sub RedrawArrows()
    ' Using outline'bordercolor to draw arrow-line
    ' Using title'forecolor to draw caption
    Dim hDC As Long
    Dim i As Integer
    Dim ct As Object
    Parent.Refresh
    hDC = GetDC(ContainerHwnd)
    With m_Command(i)
        For i = 0 To m_Commands - 1
            Set ct = CommandTarget(i)
            If Not ct Is Nothing Then
                Lines.Arrow hDC, IIf(.Method = methodGoto, arrowNormal, arrowNormalDbl), _
                    ThisLeft, ThisTop, CommandTarget(i).Left, CommandTarget(i).Top
            End If
        Next
    End With
    ReleaseDC ContainerHwnd, hDC
End Sub

Public Sub RedrawButtons()
    ' Notify parent controller
End Sub
