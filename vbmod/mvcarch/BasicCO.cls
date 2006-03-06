VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BasicCO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION = "MVCArch::ControllerControl"

Private m_Context As Object
Private m_Initial As StateObject
Private m_Active As StateObject
Private m_Stack As New List

Implements ControllerObject
Public Event Started(InitState As StateObject)
Public Event Ended(ByVal lastState As StateObject)
Public Event Enter(ByVal PreviousState As StateObject, ByVal CurrentState As StateObject)
Public Event Leave(ByVal CurrentState As StateObject, NextState As StateObject)

Public Sub Start()
    RaiseEvent Started(m_Initial)
    SetState m_Initial
End Sub

Private Sub SetState(ByVal State As StateObject)
    ' No changes
    If State Is m_Active Then Exit Sub

    ' Concrete state -> New state
    If Not m_Active Is Nothing Then
        m_Active.Leave State
        RaiseEvent Leave(m_Active, State)
    End If

    Dim lastState As StateObject
    Set lastState = m_Active
    Set m_Active = State

    ' Old state -> Concrete state
    If Not m_Active Is Nothing Then
        m_Active.Enter lastState
        RaiseEvent Enter(lastState, m_Active)
    End If
End Sub

' Return False for termination
Public Function Process(ByVal Message, Optional Parameters) As Boolean
    Dim NextState As StateObject
    Set NextState = m_Active.Process(Message, Parameters)
    If NextState Is Nothing Then
        RaiseEvent Ended(m_Active)
    End If
    SetState NextState
    Process = Not NextState Is Nothing
End Function

Public Property Get InitialState() As StateObject
    Set InitialState = m_Initial
End Property
Public Property Set InitialState(ByVal newval As StateObject)
    Set m_Initial = newval
End Property

Public Property Get ActiveState() As StateObject
    Set ActiveState = m_Active
End Property

Public Property Get State(ByVal Name As String) As StateObject
    Dim ctrl As Object
    Set ctrl = FindControl(m_Context, Name)
    On Error GoTo NotAnSO
    Set State = ctrl
NotAnSO:
    ' Error ERR_NOT_AN_SO
End Property

' -o ControllerObject
Private Property Get ControllerObject_ActiveState() As StateObject
    ControllerObject_ActiveState = ActiveState
End Property

Private Property Get ControllerObject_InitialState() As StateObject
    Set ControllerObject_InitialState = InitialState
End Property

Private Property Set ControllerObject_InitialState(ByVal RHS As StateObject)
    Set InitialState = RHS
End Property

Private Function ControllerObject_PopState() As StateObject
    If m_Stack.size > 0 Then
        Set ControllerObject_PopState = m_Stack.pop
    End If
End Function

Private Sub ControllerObject_PushState(ByVal State As StateObject)
    m_Stack.push State
End Sub

Private Property Get ControllerObject_State(ByVal Name As String) As StateObject
    Set ControllerObject_State = State(Name)
End Property

Private Function ControllerObject_Process(ByVal Message As Variant, Optional Parameters As Variant) As Boolean
    ControllerObject_Process = Process(Message, Parameters)
End Function

Private Sub ControllerObject_Start()
    Start
End Sub
