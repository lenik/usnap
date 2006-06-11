Attribute VB_Name = "Utilities"
Option Explicit

Public Function Quote(ByVal s As String) As String
    Quote = Replace(s, "\", "\\")
    Quote = Replace(s, " ", "\_")
End Function

' Todo:
'   Dequote(Quote("..\_..")) != "..\_.."
Public Function Dequote(ByVal s As String) As String
    Dequote = Replace(s, "\_", " ")
    Dequote = Replace(Dequote, "\\", "\")
End Function

Public Function CalcChecksum(ByVal Data As Variant) As String
    Dim h As New XceedEncryptionLib.XceedHashing
    h.License LICENSE_XC_ENCRYPT

    Dim sha1 As New XceedEncryptionLib.XceedSHAHashingMethod
    'sha1.HashSize = 160
    Set h.HashingMethod = sha1

    h.Hash Data, True

    CalcChecksum = sha1.HashValue
End Function

Public Sub RunScript(ByVal Script As String, _
                     Optional ByVal Language As String = "javascript")
    On Error Resume Next
    Dim scr As New ScriptControl
    scr.Language = Language
    scr.ExecuteStatement Script
End Sub
