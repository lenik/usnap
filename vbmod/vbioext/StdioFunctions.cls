VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "StdioFunctions"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function fopen(ByVal FileName As String, ByVal Mode As String) As BinaryFile
    Dim f As New BinaryFile
    Dim am As AccessModeConstants
    Select Case LCase(Mode)
    Case "r", "rt", "rb", "br", "tr"
        am = amRead
    Case "w", "wt", "wb", "bw", "tw"
        am = amWrite
    Case "a", "at", "ab", "ba", "ta"
        am = amAppend
    End Select

    If f.Open_(FileName, am) Then
        Set fopen = f
    End If
End Function

Public Sub fclose(ByVal f As BinaryFile)
    f.Close_
End Sub

Public Function fseek(ByVal f As BinaryFile, ByVal Position As Long, _
                      ByVal Relative As PositionRelativeConstants) As Long
    fseek = f.CurrentPosition
    f.SetCurrentPosition Position, Relative
End Function

Public Function fread(ByVal f As BinaryFile, ByVal cbBytes As Long) As String
    fread = f.ReadString(cbBytes)
End Function

Public Function fwrite(ByVal f As BinaryFile, ByVal s As String) As Long
    fwrite = f.WriteStringB(s)
End Function
