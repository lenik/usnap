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

Public Configuration As New Configuration
Public Config As Object

Private LE As New LowXRuntime.Execute

Private Sub Class_Initialize()
    InitializationsToTry
    Set Config = Configuration.Accessor
End Sub

Private Sub InitializationsToTry()
    On Error Resume Next
    Configuration.Path = "::" & RootFile
End Sub

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
    If IsObject(x) Then
        If Not x Is Nothing Then Exit Sub
    End If
    If Not x Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.Path
        Err.Raise ERR_ASSERT, loc, "Assert Failure" & msg
    End If
End Sub

Public Sub Warning(x, Optional msg, Optional loc)
    If IsObject(x) Then
        If Not x Is Nothing Then Exit Sub
    End If
    If Not x Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.Path
        Err.Raise ERR_WARNING, loc, "Assert Failure" & msg
    End If
End Sub

Public Sub Unexpected(Optional msg, Optional loc)
    If IsMissing(msg) Then msg = "" Else msg = ": " & msg
    If IsMissing(loc) Then loc = App.Path
    Err.Raise ERR_UNEXPECTED, loc, "Unexpected" & msg
End Sub
