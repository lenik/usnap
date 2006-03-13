VERSION 5.00
Begin VB.UserControl GraphCO_Bar_PropCmd
   ClientHeight    =   330
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   5865
   ScaleHeight     =   330
   ScaleWidth      =   5865
   Begin VB.TextBox txtParameters
      Height          =   315
      Left            =   1680
      TabIndex        =   3
      ToolTipText     =   "Command Name"
      Top             =   0
      Width           =   3735
   End
   Begin VB.TextBox txtMessage
      Height          =   315
      Left            =   840
      TabIndex        =   2
      Text            =   "ok"
      ToolTipText     =   "Command Name"
      Top             =   0
      Width           =   795
   End
   Begin VB.CommandButton cmdRemove
      Caption         =   "X"
      Height          =   255
      Left            =   5460
      TabIndex        =   1
      ToolTipText     =   "Remove"
      Top             =   60
      Width           =   315
   End
   Begin VB.TextBox txtTitle
      Height          =   315
      Left            =   0
      TabIndex        =   0
      Text            =   "&Next"
      ToolTipText     =   "Command Name"
      Top             =   0
      Width           =   795
   End
End
Attribute VB_Name = "GraphCO_Bar_PropCmd"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION = "MVCArch::GraphCO_Bar_PropCmd"

Private m_EventLock As Integer

Event Changed()
Event Remove()

Private Sub LockEvent()
    m_EventLock = m_EventLock + 1
End Sub
Private Sub UnlockEvent()
    m_EventLock = m_EventLock - 1
    Assert m_EventLock >= 0, "Unlock without lock", LOCATION
End Sub

Private Sub cmdRemove_Click()
    If m_EventLock Then Exit Sub
    RaiseEvent Remove
End Sub

Private Sub txtMessage_Change()
    If m_EventLock Then Exit Sub
    RaiseEvent Changed
End Sub

Private Sub txtParameters_Change()
    If m_EventLock Then Exit Sub
    RaiseEvent Changed
End Sub

Private Sub txtTitle_Change()
    If m_EventLock Then Exit Sub
    RaiseEvent Changed
End Sub

Public Property Get Title() As String
    Title = txtTitle.Text
End Property
Public Property Let Title(ByVal newval As String)
    txtTitle.Text = newval
End Property

Public Property Get Message() As String
    Message = txtMessage.Text
End Property
Public Property Let Message(ByVal newval As String)
    txtMessage.Text = newval
End Property

Public Property Get Parameters() As String
    Parameters = txtParameters.Text
End Property
Public Property Let Parameters(ByVal newval As String)
    txtParameters.Text = newval
End Property
