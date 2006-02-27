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
    ' m_ActiveState = ...
    ' RaiseEvent Started(ActiveState)
End Sub

' Return False for termination
Public Function Process(ByVal Message, Optional Parameters) As Boolean
    ' Process = False
    ' RaiseEvent Ended(ActiveState)
End Function

Public Property Get ActiveState() As StateObject
End Property

Public Property Get State(ByVal name As String) As StateObject
End Property
