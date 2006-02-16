Attribute VB_Name = "FundamentalFunctions"
Option Explicit

Public Sub Assert(x, Optional msg, Optional loc)
#If G_DEBUG = 1 Then
    If IsObject(x) Then
        If Not x Is Nothing Then Exit Sub
    End If
    If Not x Then
        If IsMissing(msg) Then msg = "" Else msg = ": " & msg
        If IsMissing(loc) Then loc = App.Path
        Err.Raise ERR_ASSERT, loc, "Assert Failure" & msg
    End If
#End If
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
