Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public Protocols As New Protocols
Public AddressManager As New AddressManager
Public SocketFactory As New SocketFactory

Public LicenseManager_WSL As New XceedWinsockLib.LicenseManager

Public G As New Globals

Public Null_SessionEvents As New SessionEvents

Public Function Base64ToString(ByVal Base64 As String, _
                               Optional ByVal RawMode As Boolean = True) As String
    Dim b64 As New Base64
    b64.SetBase64 Base64
    If RawMode Then
        Base64ToString = b64.GetStringB
    Else
        Base64ToString = b64.GetString
    End If
End Function

Public Function StringToBase64(ByVal s, _
                               Optional ByVal RawMode As Boolean = True) As String
    Dim b64 As New Base64
    If RawMode Then
        b64.SetStringB s
    Else
        b64.SetString s
    End If
    StringToBase64 = b64.GetBase64
End Function

Public Function ScriptEval(ByVal lang As String, ByVal script As String) As String
    '
    Err.Raise 0, "Not implemented"
End Function

