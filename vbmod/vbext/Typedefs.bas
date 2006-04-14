Attribute VB_Name = "Typedefs"
Option Explicit

Public Enum TypeConstants
    TextType = 0
    FileType
    SubType
End Enum

Public LC As New LowXRuntime.Component
Public LD As New LowXRuntime.Debugger
Public LE As New LowXRuntime.Execute
Public LK As New LowXRuntime.Call
Public LM As New LowXRuntime.Memory
Public LP As New LowXRuntime.Pointer
Public LR As New LowXRuntime.RawDataType
Public LS As New LowXRuntime.String
Public LV As New LowXRuntime.Vtbl
Public LW As New LowXRuntime.Window
Public LX As New LowXRuntime.PseudoControl
Public LXDefault As New LowXRuntime.PseudoControlSetting

Public FSO As New Scripting.FileSystemObject

Public Function ParseType(typeval) As TypeConstants
    On Error GoTo X
    ParseType = TextType
    Select Case LCase(typeval)
    Case "file"
        ParseType = FileType
    Case "sub"
        ParseType = SubType
    End Select
    Exit Function
X:
End Function
