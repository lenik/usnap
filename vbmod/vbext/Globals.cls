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

Const ERR_ASSERT             As Integer = -1
Const ERR_WARNING            As Integer = -2
Const ERR_UNEXPECTED         As Integer = -3

Public Application As New Configuration
Public Config As Object
Public DebugMode As Boolean
Public ReleaseMode As Boolean

Private LE As New LowXRuntime.Execute

Private Declare Function GetModuleHandle Lib "kernel32" Alias "GetModuleHandleA" (ByVal lpModuleName As String) As Long

Private Sub Class_Initialize()
    DebugMode = CheckIDE
    ReleaseMode = Not DebugMode

    InitializationsToTry
    Set Config = Application.Accessor
End Sub

Private Sub InitializationsToTry()
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
    Application.HomeDirectory = "::" & dir
    Application.Name = base
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

Private Property Get RootFile() As String
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

Public Sub Assert(x, Optional msg, Optional loc)
    If ReleaseMode Then Exit Sub
    If IsObject(x) Then
        If Not x Is Nothing Then Exit Sub
    End If
    If Not x Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.path
        Err.Raise ERR_ASSERT, loc, "Assert Failure" & msg
    End If
End Sub

Public Sub Warning(x, Optional msg, Optional loc)
    If ReleaseMode Then Exit Sub
    If IsObject(x) Then
        If Not x Is Nothing Then Exit Sub
    End If
    If Not x Then
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
