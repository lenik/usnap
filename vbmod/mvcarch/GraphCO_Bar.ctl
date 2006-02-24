VERSION 5.00
Begin VB.UserControl StatusBarCO
   Alignable       =   -1  'True
   ClientHeight    =   555
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   7485
   InvisibleAtRuntime=   -1  'True
   ScaleHeight     =   555
   ScaleWidth      =   7485
   ToolboxBitmap   =   "StatusBarCO.ctx":0000
End
Attribute VB_Name = "StatusBarCO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION = "MVCArch::StatusBarCO"

Private m_Outer As Siblings
Private m_kCmd As New SAOT

Implements ControllerObject
Private WithEvents m_Impl As BasicCO
Attribute m_Impl.VB_VarHelpID = -1

Public Event Started(InitState As StateControl)
Public Event Ended(ByVal LastState As StateControl)
Public Event Enter(ByVal PreviousState As StateControl, ByVal CurrentState As StateControl)
Public Event Leave(ByVal CurrentState As StateControl, NextState As StateControl)

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

Public Sub AddCommand(ByVal Name As String, ByVal Title As String)
End Sub

Public Sub RemoveCommand(ByVal Name As String)
End Sub

Public Sub ResetCommand()
End Sub


' -o ControllerObject
Private Property Get ControllerObject_ActiveState() As StateObject
    Set ControllerObject_ActiveState = ActiveState
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


' <>- BasicCO
Private Sub m_Impl_Ended(ByVal LastState As StateObject)
    RaiseEvent Ended(LastState)
End Sub

Private Sub m_Impl_Enter(ByVal PreviousState As StateObject, ByVal CurrentState As StateObject)
    RaiseEvent Enter(PreviousState, CurrentState)
End Sub

Private Sub m_Impl_Leave(ByVal CurrentState As StateObject, NextState As StateObject)
    RaiseEvent Leave(CurrentState, NextState)
End Sub

Private Sub m_Impl_Started(InitState As StateObject)
    RaiseEvent Started(InitState)
End Sub
