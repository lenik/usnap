VERSION 5.00
Begin VB.UserControl GraphSO
   BackStyle       =   0  'Transparent
   ClientHeight    =   720
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   720
   PropertyPages   =   "GraphSO.ctx":0000
   ScaleHeight     =   48
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   48
   ToolboxBitmap   =   "GraphSO.ctx":0017
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
Attribute VB_Name = "GraphSO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Attribute VB_Ext_KEY = "PropPageWizardRun" ,"Yes"
Option Explicit
Option Base 0

Private Const LOCATION                  As String = "MVCArch::StateControl"
Private Const MAX_COMMANDS              As String = 32
Private Const MIN_WIDTH                 As Integer = 24
Private Const MIN_HEIGHT                As Integer = 24
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
    BackColor As OLE_COLOR
    ForeColor As OLE_COLOR
    BorderWidth As Integer
    BorderStyle As BorderStyleConstants
    FontName As String
    FontSize As Integer
    FontBold As Boolean
    FontItalic As Boolean
    Icon As IPictureDisp
End Type

Private m_Context As Object
Private m_This As Object
Private m_Controller As GraphCO
Private m_Shown As Boolean
Private m_Style As StateStyleConstants
Private m_ControllerName As String      ' Owner controller name
Private m_Command(MAX_COMMANDS) As New StateObjectCommand
Private m_Commands As Integer
Private m_BaseName As String            ' Share the base(StateControl)'s m_Commands
Private m_BaseState As GraphSO

Implements StateObject

Public Event Enter(ByVal PreviousState As StateObject)
Public Event Leave(ByVal NextState As StateObject)
Public Event Process(ByVal Message, Parameters, NextState As StateObject)

Private Sub StateObject_Enter(ByVal PreviousState As StateObject)
    Enter PreviousState
End Sub

Private Sub StateObject_Leave(ByVal NextState As StateObject)
    Leave NextState
End Sub

Private Function StateObject_Process(ByVal Message As Variant, Optional Parameters As Variant) As StateObject
    Set StateObject_Process = Process(Message, Parameters)
End Function

Public Sub Enter(ByVal PreviousState As GraphSO)
    RaiseEvent Enter(PreviousState)
End Sub

Public Sub Leave(ByVal NextState As GraphSO)
    RaiseEvent Leave(NextState)
End Sub

Public Function Process(ByVal Message, Optional Parameters) As GraphSO
    Dim i As Integer
    Dim cmd As StateObjectCommand
    Dim defcmd As StateObjectCommand

    Set Process = Me
    For i = 0 To m_Commands - 1
        If m_Command(i).Name = Message Then
            Set cmd = m_Command(i)
            Exit For
        End If
        If m_Command(i).Default Then
            Set defcmd = m_Command(i)
        End If
    Next

    If cmd Is Nothing And defcmd Is Nothing Then
        ' Command undefined -> terminate by default
        Set Process = Nothing
    Else
        ' Command defined -> using defined by default
        If cmd Is Nothing Then Set cmd = defcmd
        If cmd.Method = methodCall Then
            Controller.PushState Me
        End If
        Set Process = cmd.Target(m_Context)
    End If

    RaiseEvent Process(Message, Parameters, Process)

    If Process Is Nothing Then
        ' Pop stack if stack isn't empty
        Set Process = Controller.PopState
    End If
End Function

Public Property Get Context()
    If m_Context Is Nothing Then Set m_Context = Parent
    Set Context = m_Context
End Property

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

Public Property Get BackColor() As OLE_COLOR
    BackColor = shpOutline.BackColor
End Property
Public Property Let BackColor(ByVal newval As OLE_COLOR)
    shpOutline.BackColor = newval
    'redraw
End Property

Public Property Get ForeColor() As OLE_COLOR
    ' or shpOutline.BorderColor
    ForeColor = lblTitle.ForeColor
End Property
Public Property Let ForeColor(ByVal newval As OLE_COLOR)
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

Private Property Get BaseState() As GraphSO
    If m_BaseState Is Nothing Then
        If m_BaseName = "" Then Exit Property
        On Error GoTo NotExist
        Set m_BaseState = FindControl(Context, m_BaseName)
    End If
    Set BaseState = m_BaseState
NotExist:
End Property

Private Property Get Controller() As GraphCO
    If m_Controller Is Nothing Then
        Set m_Controller = FindController(Context, m_ControllerName)
    End If
    Set Controller = m_Controller
End Property

Public Property Get Commands() As Integer
    Commands = m_Commands
End Property
Public Property Let Commands(ByVal newval As Integer)
    Assert newval <= m_Commands
    If newval < m_Commands Then
        Dim i As Integer
        For i = newval To m_Commands
            Set m_Command(i) = Nothing
        Next
        m_Commands = newval

        RedrawArrows
        RedrawButtons
    End If
End Property

Public Property Get Command(ByVal Index As Integer) As StateObjectCommand
    Assert Index >= 0 And Index < m_Commands
    Set Command = m_Command(Index)
End Property

Public Property Get Base() As String
    Base = m_BaseName
End Property
Public Property Let Base(ByVal newval As String)
    m_BaseName = newval
    'RedrawArrows
    RedrawButtons
End Property

Public Sub AddCommand(ByVal Name As String, ByVal TargetName As String, _
        Optional ByVal Title As String = "", _
        Optional ByVal Default As Boolean = False, _
        Optional ByVal Method As Integer = methodGoto, _
        Optional ByVal Grayed As Boolean = False, _
        Optional ByVal Visible As Boolean = True, _
        Optional ByVal Icon As IPictureDisp = Nothing)
    Assert m_Commands < MAX_COMMANDS, "Too many commands: a state object could have a maximum of " & MAX_COMMANDS & " commands at most", LOCATION
    Assert Method = methodGoto Or Method = methodCall
    Name = Trim(Name)
    Title = Trim(Title)
    If Title = "" Then Title = Name
    Set m_Command(m_Commands) = New StateObjectCommand
    With m_Command(m_Commands)
        .Name = Name                    ' The behavior of duplicated names is undefined.
        .TargetName = TargetName        ' Undefined TargetName will exit the controller (with exit-state = this)
        .Title = Title
        .Default = Default              ' More than 1 commands have default property set, then only one will be the default.
        .Method = Method
        .Grayed = Grayed
        .Visible = Visible
        .Icon = Icon
    End With
    m_Commands = m_Commands + 1
    RedrawArrows
    RedrawButtons
End Sub

Public Sub RemoveCommand(ByVal Index As Integer)
    Assert Index >= 0 And Index < m_Commands, "Index out of range", LOCATION
    Dim i As Integer
    For i = Index + 1 To m_Commands - 1
        Set m_Command(i - 1) = m_Command(i)
    Next
    m_Commands = m_Commands - 1
    Set m_Command(m_Commands) = Nothing
    RedrawArrows
    RedrawButtons
End Sub

Public Sub ResetCommand()
    m_Commands = 0
    RedrawArrows
    RedrawButtons
End Sub

Friend Sub SetCommands(cmdprops, sa As SAOT)
    Dim Slots() As Long
    Dim i As Integer
    Dim cmd As GraphSO_PropCmd
    Slots = sa.SortSlots
    Assert sa.size <= MAX_COMMANDS, "Too many commands", LOCATION
    For i = 0 To sa.size - 1
        Set cmd = cmdprops(Slots(i))
        Set m_Command(i) = New StateObjectCommand
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
    m_Commands = sa.size
    RedrawArrows
    RedrawButtons
    UserControl.PropertyChanged
End Sub

Public Property Get This() As Object
    If m_This Is Nothing Then
        Set m_This = FindControl(Context, Ambient.DisplayName)
    End If
    Set This = m_This
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
    If Controller Is Nothing Then Exit Sub
    Controller.Redraw
End Sub

Public Sub RedrawButtons()
    Dim i As Integer
    If Controller Is Nothing Then Exit Sub
    With Controller
        .ResetCommand
        For i = 0 To m_Commands - 1
            .AddCommand m_Command(i)
        Next
    End With
End Sub

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

    ' FIX: How to redraw...
    RedrawArrows
End Sub

Private Sub UserControl_Resize()
    If Not m_Shown Then Exit Sub
    If ScaleX(Width, vbTwips) < ScaleX(MIN_WIDTH, vbPixels) Then
        Width = ScaleX(MIN_WIDTH, vbPixels, vbTwips)
    End If
    If ScaleY(Height, vbTwips) < ScaleY(MIN_HEIGHT, vbPixels) Then
        Height = ScaleY(MIN_HEIGHT, vbPixels, vbTwips)
    End If
    Redraw
    RedrawArrows
End Sub

Private Sub UserControl_Show()
    Redraw
    RedrawArrows
    RedrawButtons
    m_Shown = True
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
        'Set m_Command(i) = PropBag.ReadProperty("Command_" & i, m_Command(i))
        With m_Command(i)
            .Name = PropBag.ReadProperty("Name_" & i)
            .TargetName = PropBag.ReadProperty("TargetName_" & i)
            .Title = PropBag.ReadProperty("Title_" & i)
            .Default = PropBag.ReadProperty("Default_" & i)
            .Method = PropBag.ReadProperty("Method_" & i)
            .Visible = PropBag.ReadProperty("Visible_" & i)
            .Icon = PropBag.ReadProperty("Icon_" & i, Nothing)
        End With
    Next
    m_BaseName = PropBag.ReadProperty("Base", "")
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
        'PropBag.WriteProperty "Command_" & i, m_Command(i)
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
    PropBag.WriteProperty "Base", m_BaseName
End Sub
