VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Globals"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Private Const LOCATION = "VBExt::Globals"

Public Enum ReferenceTypeConstants
    vbxStrongReference = 0              ' Place-holder, por faciligi
    vbxSoftReference                    ' Used for memory-sensitive caches
    vbxWeakReference                    ' Used for canonicalizing mappings
End Enum

Private Sub Class_Initialize()
    InitializeGlobals
End Sub

Public Property Get Application() As Configuration
    Set Application = g_Configuration
End Property

Public Property Get Config() As Object
    Set Config = g_Config
End Property

Public Property Get DebugMode() As Boolean
    DebugMode = g_DebugMode
End Property

Public Property Get ReleaseMode() As Boolean
    ReleaseMode = Not g_DebugMode
End Property

' COPY GlobalsSingleton.Assert
Public Sub Assert(x, Optional msg, Optional loc)
    If Not g_DebugMode Then Exit Sub
    If IsObject(x) Then
        If Not x Is Nothing Then Exit Sub
    End If
    If Not x Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.path
        Err.Raise ERR_ASSERT, loc, "Assert Failure" & msg
    End If
End Sub

' COPY GlobalsSingleton.Warning
Public Sub Warning(x, Optional msg, Optional loc)
    If Not g_DebugMode Then Exit Sub
    If IsObject(x) Then
        If Not x Is Nothing Then Exit Sub
    End If
    If Not x Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.path
        Err.Raise ERR_WARNING, loc, "Assert Failure" & msg
    End If
End Sub

' COPY GlobalsSingleton.Unexpected
Public Sub Unexpected(Optional msg, Optional loc)
    If IsMissing(msg) Then msg = "" Else msg = ": " & msg
    If IsMissing(loc) Then loc = App.path
    Err.Raise ERR_UNEXPECTED, loc, "Unexpected" & msg
End Sub

Public Function FindControl(ByVal outer As Object, ByVal key) As Object
    Set FindControl = GlobalsSingleton.FindControl(outer, key)
End Function

Public Function FindControls(ByVal outer As Object) As Map
    Set FindControls = GlobalsSingleton.FindControls(outer)
End Function

Public Property Get Ref(ByVal RefType As ReferenceTypeConstants, ByVal Name As String) As Object
    Set Ref = GlobalsSingleton.GetRef(RefType, Name)
End Property

Public Property Let Ref(ByVal RefType As ReferenceTypeConstants, ByVal Name As String, ByVal newval As Object)
    GlobalsSingleton.PutRef RefType, Name, newval
End Property

Public Sub GarbageCollect()
    GlobalsSingleton.GarbageCollect
End Sub

Public Sub RegisterSystemEventListener(ByVal Name As String, ByVal listener As SystemEventListener)
    GlobalsSingleton.RegisterSystemEventListener Name, listener
End Sub

Public Sub UnregisterSystemEventListener(ByVal Name As String)
    GlobalsSingleton.UnregisterSystemEventListener Name
End Sub
