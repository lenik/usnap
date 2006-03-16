Attribute VB_Name = "GlobalsSingleton"
Option Explicit
Option Base 0

'
' Fix: GlobalsMultiUse DO NOT MAKE SINGLETON
'

Private Const LOCATION = "VBExt::Globals"

Public Const ERR_ASSERT = -1
Public Const ERR_WARNING = -2
Public Const ERR_UNEXPECTED = -3

Public Const MAX_REFTYPE = 2

Public g_Configuration As New Configuration
Public g_Config As Object
Public g_DebugMode As Boolean

Public g_Digest As New Digest

Public LE As New LowXRuntime.Execute

Declare Function GetModuleHandle Lib "kernel32" Alias "GetModuleHandleA" (ByVal lpModuleName As String) As Long

Public g_Ref(MAX_REFTYPE) As Reference
Public g_IsInitialized As Boolean

Public g_Cached As New Cached

Public Sub InitializeGlobals()          ' SHOULD BE synchronized.
    If g_IsInitialized Then Exit Sub

    ' ASSERT following
    g_DebugMode = CheckIDE

    Set g_Ref(vbxStrongReference) = New StrongReference
    Set g_Ref(vbxSoftReference) = New SoftReference
    Set g_Ref(vbxWeakReference) = New WeakReference

    RegisterSystemEventListener "Default", New DefaultSystemEventListener

    Load TimerSource

    ' TRY following
    On Error Resume Next
    Dim path As String
    Dim dir As String
    Dim base As String
    path = RootFile
    If InStr(path, "\") = 0 Then
        dir = "."
        base = path
    Else
        dir = Left(path, InStr(path, "\") - 1)
        base = Mid(path, InStr(path, "\") + 1)
    End If
    g_Configuration.HomeDirectory = "::" & dir
    g_Configuration.name = base
    Set g_Config = g_Configuration.Accessor

    g_IsInitialized = True
End Sub

Private Function CheckIDE() As Boolean
    Dim ModuleHandle As String
    Dim EnvVal As Variant
    Dim ReturnVal As Long
    Dim i As Long
    EnvVal = Array("vb.exe", "vb32.exe", "vb5.exe", "vb6.exe")
    For i = LBound(EnvVal) To UBound(EnvVal)
       ModuleHandle = EnvVal(i)
       ReturnVal = GetModuleHandle(ModuleHandle)
       If ReturnVal <> 0 Then
          CheckIDE = True
          Exit Function
       End If
    Next
End Function

Public Property Get RootFile() As String
    Dim cl As String
    cl = LE.CommandLine
    If InStr(cl, Chr(0)) Then cl = Left(cl, InStr(cl, Chr(0)) - 1)
    If Left(cl, 1) = """" Then
        cl = Mid(cl, 2)
        If InStr(cl, """") > 0 Then cl = Left(cl, InStr(cl, """") - 1)
    ElseIf InStr(cl, " ") > 0 Then
        cl = Left(cl, InStr(cl, " ") - 1)
    ElseIf InStr(cl, Chr(9)) > 0 Then
        cl = Left(cl, InStr(cl, Chr(9)) - 1)
    End If
    RootFile = cl
    If LCase(Right(RootFile, 4)) = ".exe" Then
        RootFile = Left(RootFile, Len(RootFile) - 4)
    End If
End Property

Public Function NameSerial(ByVal Name As String) As Long
    g_Digest.MD5_String Name, NameSerial
End Function

Public Sub Assert(X, Optional msg, Optional loc)
    If Not g_DebugMode Then Exit Sub
    If IsObject(X) Then
        If Not X Is Nothing Then Exit Sub
    End If
    If Not X Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.path
        Err.Raise ERR_ASSERT, loc, "Assert Failure" & msg
    End If
End Sub

Public Sub Warning(X, Optional msg, Optional loc)
    If Not g_DebugMode Then Exit Sub
    If IsObject(X) Then
        If Not X Is Nothing Then Exit Sub
    End If
    If Not X Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.path
        Err.Raise ERR_WARNING, loc, "Assert Failure" & msg
    End If
End Sub

Public Sub Unexpected(Optional msg, Optional loc)
    If IsMissing(msg) Then msg = "" Else msg = ": " & msg
    If IsMissing(loc) Then loc = App.path
    Err.Raise ERR_UNEXPECTED, loc, "Unexpected" & msg
End Sub

Public Function GetRef(ByVal RefType As ReferenceTypeConstants, ByVal name As String) As Object
    Assert RefType >= 0 And RefType <= MAX_REFTYPE, "Invalid Reference Type", LOCATION
    Set GetRef = g_Ref(RefType).Ref(name)
End Function

Public Function PutRef(ByVal RefType As ReferenceTypeConstants, ByVal name As String, ByVal newval As Object)
    Assert RefType >= 0 And RefType <= MAX_REFTYPE, "Invalid Reference Type", LOCATION
    g_Ref(RefType).Ref(name) = newval
End Function

Public Sub GarbageCollect()
    Dim i As Integer
    For i = 0 To MAX_REFTYPE            ' Strong references means what?? :-)
        g_Ref(i).Collect
    Next
End Sub

