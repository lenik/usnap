Attribute VB_Name = "Typedefs"
Option Explicit

Public LC As New LowXRuntime.Component

Public Function FindController(Outer, Optional ByVal Name) As GraphCO
    If IsMissing(Name) Or Name = "" Then
        If TypeName(Outer) = "GraphCO" Then
            Set FindController = Outer
        Else
            On Error GoTo NotExisted_Def
            Dim ctrls As Map
            Set ctrls = FindControls(Outer)
            For Each Name In ctrls.KeySet
                If TypeName(ctrls(Name)) = "GraphCO" Then
                    Set FindController = ctrls(Name)
                    Exit For
                End If
            Next
NotExisted_Def:
        End If
    Else
        On Error GoTo NotExited_Named
        Set FindController = FindControl(Outer, Name)
NotExited_Named:
    End If
End Function
