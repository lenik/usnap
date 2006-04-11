Attribute VB_Name = "modImageMarks"
Option Explicit

Public Const ERRIMF_BASE = 3000


Enum IMPositionModeConstants
    BY_PIXEL
    BY_SCALE
End Enum

Type IMPosition
    Mode As IMPositionModeConstants
    Ref As String       ' reserved words: L R T B
    Value As Double
End Type



Public Function ParseIMF(ByVal imf As String)
    Dim blocks, lines, words
    Dim title As String
    Dim i As Integer, j As Integer
    Dim errmsg As String

    On Error GoTo x
    imf = Replace(imf, vbNewLine, " ")

    blocks = Split(imf, ";;")

    If Trim(blocks(0)) <> "IMF1.0" Then Err.Raise ERRIMF_BASE + CaErrArchitecture

    For i = 1 To UBound(blocks)
        lines = Split(blocks(i), ":", 2)

        errmsg = "Illegal Syntax: """ + blocks(i) + """"
        title = Trim(lines(0))
        lines = Split(lines(1), ";")

        For j = 0 To UBound(lines)
            words = Split(lines(j), ",")
            errmsg = "Illegal Statement: """ + lines(j) + """"

            Dim objname As String, objtype As String
            objname = Trim(words(0))
            objtype = Trim(words(1))

            Select Case objtype
            Case "rectangle"
            Case "round-rectangle"
            Case "ellipse"
            Case "polygon"
            Case "colorrange"
            Case "group"
            Case Else
                errmsg = "Illegal object type: " + objtype
                Err.Raise ERRIMF_BASE + CaErrParameter
            End Select
        Next

    Next

    Exit Function
x:
    Err.Raise Err.Number, Err.Source, errmsg, Err.HelpFile, Err.HelpContext
End Function
