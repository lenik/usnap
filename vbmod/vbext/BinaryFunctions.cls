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

Public Function HexToString(ByVal Hex As String, _
                            Optional ByVal RawMode As Boolean = True) As String
    Dim b64 As New Base64
    b64.sethex Hex
    If RawMode Then
        HexToString = b64.GetStringB
    Else
        HexToString = b64.GetString
    End If
End Function

Public Function StringToHex(ByVal s, _
                            Optional ByVal RawMode As Boolean = True) As String
    Dim b64 As New Base64
    If RawMode Then
        b64.SetStringB s
    Else
        b64.SetString s
    End If
    StringToHex = b64.gethex
End Function
