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

Private Const LOCATION                  As String = "VBExt::Globals"

Public Enum ReferenceTypeConstants
    vbxStrongReference = 0              ' Place-holder, por faciligi
    vbxSoftReference                    ' Used for memory-sensitive caches
    vbxWeakReference                    ' Used for canonicalizing mappings
End Enum

Public Enum ErrorOptionConstants
    vbxNonThrow = 1
    'vbxResumable = 2
    vbxAbortable = 4
End Enum

Private Sub Class_Initialize()
    InitializeGlobals
End Sub

Public Property Get Application() As Configuration
    Set Application = g_Configuration
End Property

Public Property Get InstPrefix() As String
    InstPrefix = GlobalsSingleton.InstPrefix
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
Public Sub Assert(X, Optional msg, Optional loc)
    If Not g_DebugMode Then Exit Sub
    If IsObject(X) Then
        If Not X Is Nothing Then Exit Sub
    End If
    If Not X Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = "Unknown (" & App.path & ")"
        Err.Raise ERR_ASSERT, loc, STR_ASSERT_FAILURE & msg _
                  & vbNewLine & vbNewLine & STR_LOCATION & ": " & loc
    End If
End Sub

' COPY GlobalsSingleton.Warning
Public Sub Warning(X, Optional msg, Optional loc)
    If Not g_DebugMode Then Exit Sub
    If IsObject(X) Then
        If Not X Is Nothing Then Exit Sub
    End If
    If Not X Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = "Unknown (" & App.path & ")"
        Err.Raise ERR_WARNING, loc, STR_WARNING & msg _
                  & vbNewLine & vbNewLine & STR_LOCATION & ": " & loc
    End If
End Sub

' COPY GlobalsSingleton.Unexpected
Public Sub Unexpected(Optional msg, Optional loc)
    If IsMissing(msg) Then msg = "" Else msg = ": " & msg
    If IsMissing(loc) Then loc = "Unknown (" & App.path & ")"
    Err.Raise ERR_UNEXPECTED, loc, STR_UNEXPECTED & msg
End Sub

Public Function Fatal(ByVal ErrID As Long, _
                      Optional ByVal msg As String, _
                      Optional ByVal loc As String, _
                      Optional ByVal Options As ErrorOptionConstants, _
                      Optional HelpFile, _
                      Optional HelpContext) As VbMsgBoxResult
    If msg <> "" Then msg = ": " & msg
    If loc = "" Then loc = "Unknown (" & App.path & ")"

    If Options And vbxNonThrow Then
        Dim buttons As Long
        If Options And vbxAbortable Then
            buttons = vbAbortRetryIgnore
            buttons = buttons Or vbCritical
        Else
            buttons = vbRetryCancel
            buttons = buttons Or vbExclamation
        End If

        Fatal = MsgBox(STR_FATAL_ERROR & ": " & ErrID & vbNewLine _
                        & vbNewLine _
                        & STR_DESCRIPTION & msg & vbNewLine _
                        & vbNewLine _
                        & STR_LOCATION & ": " & loc, _
                       buttons, STR_FATAL_ERROR, HelpFile, HelpContext)

        If Fatal = vbAbort Then
            ' DispatchSystemEvent SystemEvents.TERM
            ' End
        End If
    Else
        Err.Raise ErrID, loc, STR_FATAL_ERROR & msg _
                  & vbNewLine & vbNewLine & STR_LOCATION & ": " & loc, _
                  HelpFile, HelpContext
    End If
End Function

Public Sub FatalIf(X)
    If IsObject(X) Then
        If Not X Is Nothing Then Exit Sub
    Else
        If X Then Exit Sub
    End If
End Sub

Public Function FindControl(ByVal outer As Object, ByVal Key) As Object
    Set FindControl = RuntimeControls.FindControl(outer, Key)
End Function

Public Function FindControls(ByVal outer As Object) As Map
    Set FindControls = RuntimeControls.FindControls(outer)
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
    SystemEvents.RegisterSystemEventListener Name, listener
End Sub

Public Sub UnregisterSystemEventListener(ByVal Name As String)
    SystemEvents.UnregisterSystemEventListener Name
End Sub

Public Property Get LC() As LowXRuntime.Component
    Set LC = Typedefs.LC
End Property
Public Property Get LD() As LowXRuntime.Debugger
    Set LD = Typedefs.LD
End Property
Public Property Get LE() As LowXRuntime.Execute
    Set LE = Typedefs.LE
End Property
Public Property Get LK() As LowXRuntime.Call
    Set LK = Typedefs.LK
End Property
Public Property Get LM() As LowXRuntime.Memory
    Set LM = Typedefs.LM
End Property
Public Property Get LP() As LowXRuntime.Pointer
    Set LP = Typedefs.LP
End Property
Public Property Get LR() As LowXRuntime.RawDataType
    Set LR = Typedefs.LR
End Property
Public Property Get LS() As LowXRuntime.String
    Set LS = Typedefs.LS
End Property
Public Property Get LV() As LowXRuntime.Vtbl
    Set LV = Typedefs.LV
End Property
Public Property Get LW() As LowXRuntime.Window
    Set LW = Typedefs.LW
End Property
Public Property Get LX() As LowXRuntime.PseudoControl
    Set LX = Typedefs.LX
End Property
Public Property Get LXDefault() As LowXRuntime.PseudoControlSetting
    Set LXDefault = Typedefs.LXDefault
End Property
Public Property Get FSO() As Scripting.FileSystemObject
    Set FSO = Typedefs.FSO
End Property
