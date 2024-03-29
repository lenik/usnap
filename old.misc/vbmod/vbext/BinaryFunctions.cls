VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BinaryFunctions"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function Base64ToString(ByVal Base64 As String, _
                               Optional ByVal RawMode As Boolean = False) As String
    If Left(Base64, 1) = "'" Then
        Base64ToString = Mid(Base64, 2)
        Exit Function
    End If

    Dim b64 As New Base64
    b64.SetBase64 Base64
    If RawMode Then
        Base64ToString = b64.GetStringB
    Else
        Base64ToString = b64.GetString
    End If
End Function

Public Function StringToBase64(ByVal s, _
                               Optional ByVal RawMode As Boolean = False) As String
    Dim b64 As New Base64
    If RawMode Then
        b64.SetStringB s
    Else
        b64.SetString s
    End If
    StringToBase64 = b64.GetBase64
End Function

Public Function HexToString(ByVal Hex As String, _
                            Optional ByVal RawMode As Boolean = False) As String
    If Left(Hex, 1) = "'" Then
        HexToString = Mid(Hex, 2)
        Exit Function
    End If

    Dim b64 As New Base64
    b64.SetHex Hex
    If RawMode Then
        HexToString = b64.GetStringB
    Else
        HexToString = b64.GetString
    End If
End Function

Public Function StringToHex(ByVal s, _
                            Optional ByVal RawMode As Boolean = False, _
                            Optional ByVal Separator As String = "") As String
    Dim b64 As New Base64
    If RawMode Then
        b64.SetStringB s
    Else
        b64.SetString s
    End If
    StringToHex = b64.GetHex(Separator)
End Function
