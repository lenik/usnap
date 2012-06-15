Attribute VB_Name = "GlobalsSingleton"
Option Explicit
Option Base 0

'
' Fix: GlobalsMultiUse DO NOT MAKE SINGLETON
'

Private Const LOCATION = "VBExt::Globals"
Private Const APPNAME = "Q"

Public Const ERR_ASSERT = -1
Public Const ERR_WARNING = -2
Public Const ERR_UNEXPECTED = -3

Public STR_ASSERT_FAILURE          As String
Public STR_WARNING                 As String
Public STR_UNEXPECTED              As String
Public STR_FATAL_ERROR             As String
Public STR_DESCRIPTION             As String
Public STR_LOCATION                As String

Public Const MAX_REFTYPE = 2

Public g_Configuration As New Configuration
Public g_Config As Object
Public g_DebugMode As Boolean

Public g_Digest As New Digest

Declare Function GetModuleHandle Lib "kernel32" Alias "GetModuleHandleA" (ByVal lpModuleName As String) As Long

Public g_Ref(MAX_REFTYPE) As Reference
Public g_IsInitialized As Boolean

Public g_Patterns As New Patterns

Public Sub InitializeGlobals()          ' SHOULD BE synchronized.
    If g_IsInitialized Then Exit Sub

    ' Init Constants
    STR_ASSERT_FAILURE = GetSetting(APPNAME, LOCATION, _
   "STR_ASSERT_FAILURE", "Assert Failure")

    STR_WARNING = GetSetting(APPNAME, LOCATION, _
   "STR_WARNING", "Warning")

    STR_UNEXPECTED = GetSetting(APPNAME, LOCATION, _
   "STR_UNEXPECTED", "Unexpected")

    STR_FATAL_ERROR = GetSetting(APPNAME, LOCATION, _
   "STR_FATAL_ERROR", "Fatal Error")

    STR_DESCRIPTION = GetSetting(APPNAME, LOCATION, _
   "STR_DESCRIPTION", "Description")

    STR_LOCATION = GetSetting(APPNAME, LOCATION, _
   "STR_LOCATION", "Location")

    ' ASSERT following
    g_DebugMode = CheckIDE

    Set g_Ref(vbxStrongReference) = New StrongReference
    Set g_Ref(vbxSoftReference) = New SoftReference
    Set g_Ref(vbxWeakReference) = New WeakReference

    RegisterSystemEventListener "Default", New DefaultSystemEventListener

    Load TimerSource

    ' TRY following
    Dim path As String
    Dim dir As String
    Dim base As String
    path = InstPrefix
    If InStr(path, "\") = 0 Then
        dir = "."
        base = path
    Else
        dir = Left(path, InStrRev(path, "\") - 1)
        base = Mid(path, InStrRev(path, "\") + 1)
    End If
    g_Configuration.HomeDirectory = dir
    g_Configuration.Name = base
    g_Configuration.Reload True

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

Public Property Get InstPrefix() As String
    Dim cl As String
    cl = LE.CommandLine

    If InStr(cl, Chr(0)) Then           ' string-before('\0')
        cl = Left(cl, InStr(cl, Chr(0)) - 1)
    End If

    If Left(cl, 1) = """" Then          ' match /^\"(.*?)\"/
        cl = Mid(cl, 2)
        If InStr(cl, """") > 0 Then cl = Left(cl, InStr(cl, """") - 1)
    ElseIf InStr(cl, " ") > 0 Then      ' string-before(' ')
        cl = Left(cl, InStr(cl, " ") - 1)
    ElseIf InStr(cl, Chr(9)) > 0 Then   ' string-before('\t')
        cl = Left(cl, InStr(cl, Chr(9)) - 1)
    End If

    InstPrefix = cl                       ' string-before(".exe")
    If LCase(Right(InstPrefix, 4)) = ".exe" Then
        InstPrefix = Left(InstPrefix, Len(InstPrefix) - 4)
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
        If IsMissing(loc) Then loc = "Unknown (" & App.path & ")"
        Err.Raise ERR_ASSERT, loc, STR_ASSERT_FAILURE & msg _
                  & vbNewLine & vbNewLine & STR_LOCATION & loc
    End If
End Sub

Public Sub Warning(X, Optional msg, Optional loc)
    If Not g_DebugMode Then Exit Sub
    If IsObject(X) Then
        If Not X Is Nothing Then Exit Sub
    End If
    If Not X Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = "Unknown (" & App.path & ")"
        Err.Raise ERR_WARNING, loc, STR_ASSERT_FAILURE & msg _
                  & vbNewLine & vbNewLine & STR_LOCATION & loc
    End If
End Sub

Public Sub Unexpected(Optional msg, Optional loc)
    If IsMissing(msg) Then msg = "" Else msg = ": " & msg
    If IsMissing(loc) Then loc = "Unknown (" & App.path & ")"
    Err.Raise ERR_UNEXPECTED, loc, STR_UNEXPECTED & msg _
              & vbNewLine & vbNewLine & STR_LOCATION & loc
End Sub

Public Function GetRef(ByVal RefType As ReferenceTypeConstants, ByVal Name As String) As Object
    Assert RefType >= 0 And RefType <= MAX_REFTYPE, "Invalid Reference Type", LOCATION
    Set GetRef = g_Ref(RefType).Ref(Name)
End Function

Public Function PutRef(ByVal RefType As ReferenceTypeConstants, ByVal Name As String, ByVal newval As Object)
    Assert RefType >= 0 And RefType <= MAX_REFTYPE, "Invalid Reference Type", LOCATION
    g_Ref(RefType).Ref(Name) = newval
End Function

Public Sub GarbageCollect()
    Dim i As Integer
    For i = 0 To MAX_REFTYPE            ' Strong references means what?? :-)
        g_Ref(i).Collect
    Next
End Sub
