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

Private m_Outer As Object
Private m_StartName As String
Private m_Cmd() As StateObjectCommand
Private WithEvents k_Cmd As SAOT
Attribute k_Cmd.VB_VarHelpID = -1

Public Event CommandChange()

Implements ControllerObject
Public Event Started(InitState As StateObject)
Public Event Ended(ByVal LastState As StateObject)
Public Event Enter(ByVal PreviousState As StateObject, ByVal CurrentState As StateObject)
Public Event Leave(ByVal CurrentState As StateObject, NextState As StateObject)

Public Sub Start()
    ' m_ActiveState = ...
    ' RaiseEvent Started(ActiveState)
End Sub

' Return False for termination
Public Function Process(ByVal Message, Parameters) As Boolean
    ' Process = False
    ' RaiseEvent Ended(ActiveState)
End Function

Public Property Get ActiveState() As StateObject
End Property

Public Property Get State(ByVal Name As String) As StateObject
End Property

Public Function AddCommand(ByVal Name As String, ByVal Title As String) As Integer
    Dim Index As Integer
    Dim slot As Integer
    Index = k_Cmd.Size
    k_Cmd.Append 1
    slot = k_Cmd.FindIndex(Index)
    With m_Cmd(slot)
        .Name = Name
        .Title = Title
    End With
    AddCommand = Index
End Function

Public Sub RemoveCommand(ByVal Index As String)
    k_Cmd.Remove Index
End Sub

Public Sub ResetCommand()
    k_Cmd.Clear
End Sub

Private Sub k_Cmd_Add(ByVal slot As Long, ByVal Index As Long)
    ReDim Preserve m_Cmd(0 To k_Cmd.SlotAllocated - 1)
    Set m_Cmd(slot) = New StateObjectCommand
    RaiseEvent CommandChange
End Sub

Private Sub k_Cmd_Remove(ByVal slot As Long, ByVal Index As Long)
    ReDim Preserve m_Cmd(0 To k_Cmd.SlotAllocated - 1)

End Sub

' -o ControllerObject
Private Property Get ControllerObject_ActiveState() As StateObject
    ControllerObject_ActiveState = ActiveState
End Property

Private Property Get ControllerObject_State(ByVal Name As String) As StateObject
    Set ControllerObject_State = State(Name)
End Property

Private Sub ControllerObject_AddCommand(ByVal Name As String, ByVal Title As String)
    AddCommand Name, Title
End Sub

Private Function ControllerObject_Process(ByVal Message As Variant, Parameters As Variant) As Boolean
    ControllerObject_Process = Process(Message, Parameters)
End Function

Private Sub ControllerObject_RemoveCommand(ByVal Name As String)
    RemoveCommand Name
End Sub

Private Sub ControllerObject_ResetCommand()
    ResetCommand
End Sub

Private Sub ControllerObject_Start()
    Start
End Sub
