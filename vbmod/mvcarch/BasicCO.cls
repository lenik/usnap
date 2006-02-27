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

Public Property Get State(ByVal name As String) As StateObject
End Property

' -o ControllerObject
Private Property Get ControllerObject_ActiveState() As StateObject
    ControllerObject_ActiveState = ActiveState
End Property

Private Property Get ControllerObject_State(ByVal name As String) As StateObject
    Set ControllerObject_State = State(name)
End Property

Private Function ControllerObject_Process(ByVal Message As Variant, Optional Parameters As Variant) As Boolean
    ControllerObject_Process = Process(Message, Parameters)
End Function

Private Sub ControllerObject_Start()
    Start
End Sub
