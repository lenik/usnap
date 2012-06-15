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

Function System256ToDecimal(Byt) As String
    Const MEG_BASE As Long = 1000000

    Dim n As Long
    n = UBound(Byt) + 1

    ' n/2.5 is appx. allocation
    ReDim Meg(0 To 1 + Int(n / 2.5)) As Long
    Dim m As Long
    m = UBound(Meg)

    ' Byt       High..Low
    ' Meg       Low..High

    Dim i As Long
    Dim j As Long

    For i = 0 To n - 1
        For j = 0 To m - 1
            Meg(j) = Meg(j) * 256
        Next
        Meg(0) = Meg(0) + Byt(i)

        ' normalize
        Dim mCarry As Long
        For j = 0 To m - 1
            Meg(j) = Meg(j) + mCarry
            mCarry = Int(Meg(j) / MEG_BASE)
            Meg(j) = Meg(j) Mod MEG_BASE
        Next
    Next

    Dim buf As String
    For j = m - 1 To 0 Step -1
        If buf <> "" Or Meg(j) <> 0 Then
            If buf = "" Then
                buf = Meg(j)
            Else
                buf = buf & Right("00000" & Meg(j), 6)
            End If
        End If
    Next

    If buf = "" Then buf = "0"
    System256ToDecimal = buf
End Function

Public Function CalcChecksum(ByVal Data As Variant, _
                             Optional ByVal InNumber As Boolean = True, _
                             Optional ByVal Length As Integer = 8) As String
    Dim h As New XceedEncryptionLib.XceedHashing
    h.License LICENSE_XC_ENCRYPT

    Dim sha1 As New XceedEncryptionLib.XceedSHAHashingMethod
    'sha1.HashSize = 160
    Set h.HashingMethod = sha1

    h.Hash Data, True

    Dim bin As New Base64
    If InNumber Then
        CalcChecksum = Left(System256ToDecimal(sha1.HashValue), Length)
    Else
        bin.SetStringB sha1.HashValue
        CalcChecksum = Left(bin.GetBase64, Length)
    End If
End Function

Public Sub RunScript(ByVal Script As String, _
                     Optional ByVal Language As String = "javascript")
    On Error Resume Next
    Dim scr As New ScriptControl
    scr.Language = Language
    scr.ExecuteStatement Script
End Sub
