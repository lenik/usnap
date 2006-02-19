VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ControllerObject"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

' Tag Class

Public Event Started(InitState As StateObject)
Public Event Ended(ByVal LastState As StateObject)
Public Event Enter(ByVal PreviousState As StateObject, ByVal CurrentState As StateObject)
Public Event Leave(ByVal CurrentState As StateObject, NextState As StateObject)

Public Sub Start()
    RaiseEvent Started(Nothing)
End Sub

' Return False for termination
Public Function Process(ByVal Message, Parameters) As Boolean
    Process = False
End Function

Public Property Get State() As StateObject
    Set State = Nothing
End Property

Public Sub RegisterCommand(ByVal Name As String, ByVal Title As String)
End Sub

Public Sub ResetCommands()
End Sub
