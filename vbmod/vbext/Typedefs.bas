Attribute VB_Name = "Typedefs"
Option Explicit

Public Type Position
    x0 As Double
    y0 As Double
    x1 As Double
    y1 As Double
End Type

Public Enum TypeConstants
    TextType = 0
    FileType
    SubType
End Enum

Public LC As New LowXRuntime.Component
Public FSO As New Scripting.FileSystemObject
Public G As New Globals

Public Function ParseType(typeval) As TypeConstants
    On Error GoTo x
    ParseType = TextType
    Select Case LCase(typeval)
    Case "file"
        ParseType = FileType
    Case "sub"
        ParseType = SubType
    End Select
    Exit Function
x:
End Function
