Attribute VB_Name = "Module1"
Option Explicit

Public Function GetDimensions(a) As Integer
    On Error GoTo FinalDim
    Dim i As Integer
    Dim Ignore As Long
    For i = 1 To 61                     ' Max 60 dimensions SAFEARRAY can hold
        Ignore = LBound(a, i)
    Next
    Unexpected

FinalDim:
    GetDimensions = i - 1
End Function

Public Function DumpVariant(v As Variant, Optional ByVal indent As Integer = 0) As String
    Dim prefix As String
    prefix = String(indent * 2, " ")
    Dim buf As String
    Dim dims As Integer
    Dim i As Long, j As Long
    Dim o

    If IsArray(v) Then
        buf = TypeName(v)
        dims = GetDimensions(v)
        Select Case dims
        Case 1
            For i = LBound(v) To UBound(v)
                buf = buf & vbNewLine & prefix & "  " & i & ". " & DumpVariant(v(i), indent + 1)
            Next
        Case 2
            For i = LBound(v, 1) To UBound(v, 1)
                For j = LBound(v, 2) To UBound(v, 2)
                    buf = buf & vbNewLine & prefix & "  " & i & "/" & j & ". " & DumpVariant(v(i, j), indent + 1)
                Next
            Next
        Case Else
            buf = buf & vbNewLine & prefix & "  (HIGH DIMENSION ARRAY)"
        End Select
    Else
        Select Case TypeName(v)
        Case "Byte", "Short", "Integer", "Long", "Single", "Double", "Decimal"
            buf = TypeName(v) & ":" & CStr(v)
        Case "String", "Boolean", "Date"
            buf = TypeName(v) & ":" & CStr(v)
        Case "Collection"
            buf = TypeName(v)
            For Each o In v
                buf = buf & vbNewLine & prefix & "  - " & DumpVariant(o)
            Next
        Case Else
            buf = TypeName(v)
        End Select
    End If
    DumpVariant = DumpVariant & buf
End Function
