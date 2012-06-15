Attribute VB_Name = "Module1"
Option Explicit


Public Function gp(ByVal pos As String) As String
        Dim nLevels As Integer
        Dim CollPos As String
        Dim ObjName As String

        nLevels = val(decodePart(pos, 0))
        CollPos = pos
        ObjName = departPart(CollPos, nLevels)
        CollPos = Trim(nLevels - 1) & Mid(CollPos, decodePart(CollPos, 1, True))
        gp = CollPos
End Function
