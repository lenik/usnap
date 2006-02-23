VERSION 5.00
Begin VB.UserControl ControllerControl
   ClientHeight    =   720
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   720
   InvisibleAtRuntime=   -1  'True
   Picture         =   "ControllerControl.ctx":0000
   ScaleHeight     =   720
   ScaleWidth      =   720
   ToolboxBitmap   =   "ControllerControl.ctx":74F2
   Windowless      =   -1  'True
End
Attribute VB_Name = "ControllerControl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION = "MVCArch::ControllerControl"

Private m_Ref As Siblings
Private m_StartState As String

Implements ControllerObject

Public Event Started(InitState As StateObject)
Public Event Ended(ByVal LastState As StateObject)
Public Event Enter(ByVal PreviousState As StateObject, ByVal CurrentState As StateObject)
Public Event Leave(ByVal CurrentState As StateObject, NextState As StateObject)

Private Function ControllerObject_Process(ByVal Message As Variant, Parameters As Variant) As Boolean
    ControllerObject_Process = Process(Message, Parameters)
End Function

Private Sub ControllerObject_RegisterCommand(ByVal Name As String, ByVal Title As String)
    RegisterCommand Name, Title
End Sub

Private Sub ControllerObject_ResetCommands()
    ResetCommands
End Sub

Private Sub ControllerObject_Start()
    Start
End Sub

Private Property Get ControllerObject_State() As StateObject
    Set ControllerObject_State = State
End Property

Public Sub Start()
    Dim State As StateObject
    Set State = UserControl.ContainedControls
    RaiseEvent Started(Nothing)
End Sub

Public Function Process(ByVal Message, Parameters) As Boolean
End Function

Public Property Get State() As StateObject
End Property

Public Sub RegisterCommand(ByVal Name As String, ByVal Title As String)
End Sub

Public Sub ResetCommands()
End Sub

Private Sub InitReferences()
    m_Ref = New Siblings
    m_Ref.SetIndexed UserControl.ContainedControls, "(Parent Form)"
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    ' read...
    ' init references
End Sub

Private Sub UserControl_Resize()
    Width = 720
    Height = 720
End Sub
