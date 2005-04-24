Attribute VB_Name = "modOptions"
Option Explicit


Public Type OPTIONS

    OutSameDir As Boolean
    OutDir As String            ' if not OutSameDir

    NameDefault As Boolean
    NameSrc As String           ' if not default, reg-ex src
    NameDst As String           ' if not default, reg-ex dst

    Backup As Boolean

    IncludeTitle As Boolean
    ScreenWidth As Integer
    TitleAlignment As AlignmentConstants
    TitleFormat As String

    Variables As New Collection

End Type



Public Function GetOutputPath(srcPath As String, opts As OPTIONS) As String

End Function


Public Sub PrepareWrite(dstPath As String, opts As OPTIONS)

End Sub


Public Function VariableExpand(script As String, opts As OPTIONS) As String


End Function
