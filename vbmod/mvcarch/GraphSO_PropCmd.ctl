VERSION 5.00
Begin VB.UserControl StateControl_Command
   ClientHeight    =   345
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   5880
   ScaleHeight     =   23
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   392
   ToolboxBitmap   =   "StateControl_Command.ctx":0000
   Begin VB.TextBox txtName
      Height          =   315
      Left            =   0
      TabIndex        =   0
      Text            =   "Name"
      ToolTipText     =   "Command Name"
      Top             =   0
      Width           =   795
   End
   Begin VB.CommandButton cmdRemove
      Caption         =   "X"
      Height          =   255
      Left            =   5520
      TabIndex        =   6
      ToolTipText     =   "Remove"
      Top             =   60
      Width           =   315
   End
   Begin VB.ComboBox lstMethod
      Height          =   315
      ItemData        =   "StateControl_Command.ctx":0312
      Left            =   840
      List            =   "StateControl_Command.ctx":031C
      Style           =   2  'Dropdown List
      TabIndex        =   1
      ToolTipText     =   "Command Type"
      Top             =   0
      Width           =   795
   End
   Begin VB.CheckBox chkVisible
      Height          =   315
      Left            =   3600
      TabIndex        =   4
      ToolTipText     =   "Visible"
      Top             =   0
      Width           =   255
   End
   Begin VB.CheckBox chkDefault
      Height          =   315
      Left            =   3120
      TabIndex        =   3
      ToolTipText     =   "Default"
      Top             =   0
      Width           =   255
   End
   Begin VB.TextBox txtTitle
      Height          =   315
      Left            =   4080
      TabIndex        =   5
      Text            =   "Title"
      Top             =   0
      Width           =   1335
   End
   Begin VB.ComboBox lstTarget
      Height          =   315
      Left            =   1680
      Style           =   2  'Dropdown List
      TabIndex        =   2
      ToolTipText     =   "Target State"
      Top             =   0
      Width           =   1215
   End
End
Attribute VB_Name = "StateControl_Command"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION = "MVCArch::StateControl_Command"

Private m_Ref As ContainerObjects
Private m_Default As Boolean
Private m_EventLock As Integer

Event Changed()
Event Remove()
Event SetDefault()

Private Sub LockEvent()
    m_EventLock = m_EventLock + 1
End Sub
Private Sub UnlockEvent()
    m_EventLock = m_EventLock - 1
    Assert m_EventLock >= 0, "Unlock without lock", LOCATION
End Sub

Public Sub Initialize(Ref As ContainerObjects)
    Set m_Ref = Ref
    RefreshStateObjects
End Sub

Private Sub RefreshStateObjects()
    Dim Name
    lstTarget.Clear
    For Each Name In m_Ref.Objects.KeySet
        lstTarget.AddItem Name
    Next
End Sub

Private Sub chkDefault_Click()
    If m_EventLock Then Exit Sub
    Dim newval As Boolean
    newval = chkDefault.Value = vbChecked
    If m_Default <> newval Then
        RaiseEvent SetDefault
        RaiseEvent Changed
    End If
End Sub

Private Sub chkVisible_Click()
    If m_EventLock Then Exit Sub
    RaiseEvent Changed
End Sub

Private Sub cmdRemove_Click()
    If m_EventLock Then Exit Sub
    RaiseEvent Remove
End Sub

Private Sub lstMethod_Click()
    If m_EventLock Then Exit Sub
    RaiseEvent Changed
End Sub

Private Sub lstTarget_Click()
    If m_EventLock Then Exit Sub
    RaiseEvent Changed
End Sub

Private Sub txtName_Change()
    If m_EventLock Then Exit Sub
    RaiseEvent Changed
End Sub

Public Property Get CommandName() As String
    CommandName = txtName.Text
End Property

Public Property Let CommandName(ByVal newval As String)
    txtName.Text = CommandName
End Property

Public Property Get CommandMethod() As MethodConstants
    Select Case lstMethod.ListIndex
    Case 0
        CommandMethod = methodGoto
    Case 1
        CommandMethod = methodCall
    End Select
End Property

Public Property Let CommandMethod(ByVal newval As MethodConstants)
    Select Case newval
    Case methodGoto
        lstMethod.ListIndex = 0
    Case methodCall
        lstMethod.ListIndex = 1
    Case Else
        Assert False, "Illegal method", LOCATION
    End Select
End Property

Public Property Get CommandTarget() As String
    CommandTarget = lstTarget.Text
End Property

Public Property Let CommandTarget(ByVal newval As String)
    Dim i
    For i = 0 To lstTarget.ListCount - 1
        If LCase(newval) = LCase(lstTarget.List(i)) Then
            lstTarget.ListIndex = i
            Exit Property
        End If
    Next
    Assert False, "StateControl: " & newval & " isn't existed", LOCATION
End Property

Public Property Get CommandDefault() As Boolean
    CommandDefault = chkDefault.Value = vbChecked
End Property

Public Property Let CommandDefault(ByVal newval As Boolean)
    LockEvent
    chkDefault.Value = IIf(newval, vbChecked, vbUnchecked)
    UnlockEvent
End Property

Public Property Get CommandVisible() As Boolean
    CommandVisible = chkVisible.Value = vbChecked
End Property

Public Property Let CommandVisible(ByVal newval As Boolean)
    chkVisible.Value = IIf(newval, vbChecked, vbUnchecked)
End Property

Public Property Get CommandTitle() As String
    CommandTitle = txtTitle.Text
End Property

Public Property Let CommandTitle(ByVal newval As String)
    txtTitle.Text = newval
End Property
