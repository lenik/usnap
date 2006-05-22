Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public Protocols As New Protocols
Public AddressManager As New AddressManager
Public SocketFactory As New SocketFactory

Public LicenseManager_WSL As New XceedWinsockLib.LicenseManager

Public HASH_HAVAL As New XceedEncryptionLib.XceedHavalHashingMethod
Public HASH_SHA1 As New XceedEncryptionLib.XceedSHAHashingMethod

Public G As New Globals

Public Null_SessionEvents As New SessionEvents

Public Function ScriptEval(ByVal lang As String, ByVal script As String, _
                           Optional ByVal Ret As Boolean = False) As Variant
    Dim sc As New ScriptControl
    sc.Language = lang
    On Error GoTo x
    If Ret Then
        ScriptEval = sc.Eval(script)
    Else
        sc.ExecuteStatement script
    End If
    On Error GoTo 0
    Exit Function
x:
    Set ScriptEval = Err
End Function

Public Function MapFind(ByVal Map As VBExt.Map, ByVal ValuePattern As Variant) As Variant
    ' Assert Not Map Is Nothing
    If Map Is Nothing Then Exit Function

    Dim finder As New KeyFinder

    LC.Assign finder.ValuePattern, ValuePattern

    Map.Walk finder

    If finder.Found Then
        LC.Assign MapFind, finder.FoundKey
    End If
End Function

Public Function MapFind_SD(ByVal Map As VBExt.Map, ByVal sd As XceedWinsockLib.ConnectionOrientedSocket) As String
    ' Assert Not Map Is Nothing
    If Map Is Nothing Then Exit Function

    Dim finder As New KeyFinder_SD

    LC.Assign finder.sd, sd

    Map.Walk finder

    If finder.Found Then
        MapFind_SD = finder.FoundKey
    End If
End Function

Public Function FileHash(ByVal Path As String) As String
    Dim h As New XceedEncryptionLib.XceedHashing
    Dim sha1 As New XceedEncryptionLib.XceedSHAHashingMethod
    h.License LICENSE_XC_ENCRYPT

    Set h.HashingMethod = sha1
    h.ReadFile Path, 0, 0, efpHash, True

    FileHash = Replace(StringToBase64(sha1.HashValue), " ", "")
End Function
