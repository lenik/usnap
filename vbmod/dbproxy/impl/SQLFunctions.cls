VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SQLFunctions"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "SQLF_Default"

' @TAG-CLASS
' @DEFAULT-IMPLEMENTATION

Public Function QuoteName(ByVal Name As String) As String
    QuoteName = "`" & Name & "`"
End Function

Public Function QuoteString(ByVal str As String) As String
    QuoteString = "'" & Replace(str, "'", "''") & "'"
End Function

Public Function QuoteDate(ByVal date_ As Date) As String
    QuoteDate = "#" & Year(date_) & "-" & Month(date_) & "-" & Day(date_) & "#"
End Function

Public Function QuoteTime(ByVal time_ As Date) As String
    QuoteTime = "#" & Hour(time_) & ":" & Minute(time_) & ":" & Second(time_) & "#"
End Function

Public Function QuoteDateTime(ByVal date_ As Date) As String
    QuoteDateTime = "#" & Year(date_) & "-" & Month(date_) & "-" & Day(date_) _
                  & " " & Hour(date_) & ":" & Minute(date_) & ":" & Second(date_) & "#"
End Function

Public Function Concat(ParamArray args()) As String
    Dim l As Integer
    Dim r As Integer
    Dim i As Integer
    l = LBound(args)
    r = UBound(args)
    Assert r > l, "Concat at least 2 arguments", LOCATION
    Concat = "CONCAT("
    For i = l To r
        If i > l Then Concat = Concat & ","
        Concat = Concat & args(i)
    Next
    Concat = Concat & ")"
End Function

Public Function Mid(ByVal Name As String, ByVal start As Integer, Optional ByVal Length) As String
    Mid = "SUBSTRING(" & Name
    If Not IsMissing(start) Then Mid = Mid & "," & start
    If Not IsMissing(Length) Then Mid = Mid & "," & Length
    Mid = Mid & ")"
End Function

Public Function Left(ByVal Name As String, ByVal Length As Integer) As String
    Left = "LEFT(" & Name & "," & Length & ")"
End Function

Public Function Right(ByVal Name As String, ByVal Length As Integer) As String
    Right = "RIGHT(" & Name & "," & Length & ")"
End Function

Public Function PadLeft(ByVal Name As String, Optional ByVal Length = 8, Optional ByVal PadChar As String = "0") As String
    Dim PadTmpl As String
    PadTmpl = String(Length, PadChar)
    PadLeft = Right(Concat(QuoteString(PadTmpl), Name), Length)
End Function

Public Function PadRight(ByVal Name As String, Optional ByVal Length = 8, Optional ByVal PadChar As String = " ") As String
    Dim PadTmpl As String
    PadTmpl = String(Length, PadChar)
    PadRight = Left(Concat(Name, QuoteString(PadTmpl)), Length)
End Function
