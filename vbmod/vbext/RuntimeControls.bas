Attribute VB_Name = "RuntimeControls"
Option Explicit

Private Const LOCATION = "VBExt::RuntimeControls"

Public Function FindControl(ByVal outer As Object, ByVal key) As Object
    On Error GoTo NoDef
    Set FindControl = outer(key)
    Exit Function
NoDef:

    'On Error GoTo NoControls
    Set FindControl = CP_Controls_get(outer.Controls, key)
    If FindControl Is Nothing Then GoTo NoControls
    Exit Function
NoControls:

    On Error GoTo NotEnum
    Dim obj As Object
    For Each obj In outer
        If Not obj Is Nothing Then
            If LC.HasMember(obj, "Name") Then
                If obj.name = key Then
                    Set FindControl = obj
                    Exit Function
                End If
            ElseIf LC.HasMember(obj, "name") Then
                If obj.name = key Then
                    Set FindControl = obj
                    Exit Function
                End If
            End If
        End If
    Next
    Exit Function
NotEnum:

    Set FindControl = Nothing
End Function

Public Function FindControls(outer As Object) As Map
    On Error GoTo NotAMap
    Set FindControls = outer
    Exit Function
NotAMap:

    Set FindControls = New Map

    On Error GoTo NoControls
    Set outer = outer.Controls
    ' Yes, has controls
NoControls:

    Dim obj As Object

    On Error GoTo NotEnum
    For Each obj In outer
        If Not obj Is Nothing Then
            If LC.HasMember(obj, "Name") Then
                FindControls.Item(obj.name) = obj
            ElseIf LC.HasMember(obj, "name") Then
                FindControls.Item(obj.name) = obj
            End If
        End If
    Next
    Exit Function
NotEnum:

    On Error GoTo NoCount
    Dim i As Integer
    For i = 0 To outer.Count - 1
        If IsObject(outer(i)) Then
            Set obj = outer(i)
            If LC.HasMember(obj, "Name") Then
                FindControls.Item(obj.name) = obj
            ElseIf LC.HasMember(obj, "name") Then
                FindControls.Item(obj.name) = obj
            End If
        End If
    Next
    Exit Function
NoCount:

    Set FindControls = Nothing
End Function
