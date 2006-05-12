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
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Enum BoolBinOpCompMethodConstants
    boDontCare = 0
    boAnd
    boAndNot
    boOr
    boOrNot
    boXor
End Enum

Private Const LOCATION                  As String = "DBProxy::SQLF_Default"

' @TAG-CLASS
' @DEFAULT-IMPLEMENTATION

Public Function QuoteName(ByVal f As String) As String
    QuoteName = "`" & f & "`"
End Function

Public Function QuoteString(ByVal f As String) As String
    QuoteString = "'" & Replace(f, "'", "''") & "'"
End Function

Public Function QuoteDate(ByVal date_ As Date) As String
    QuoteDate = "date('" & Year(date_) & "-" & Month(date_) & "-" & Day(date_) & "')"
End Function

Public Function QuoteTime(ByVal time_ As Date) As String
    QuoteTime = "time('" & Hour(time_) & ":" & Minute(time_) & ":" & Second(time_) & "')"
End Function

Public Function QuoteDateTime(ByVal date_ As Date) As String
    QuoteDateTime = "datetime('" & Year(date_) & "-" & Month(date_) & "-" & Day(date_) _
                  & " " & Hour(date_) & ":" & Minute(date_) & ":" & Second(date_) & "')"
End Function

Public Function Concat(ParamArray args_()) As String
    Dim args
    args = ParamArrayToArray(args_)

    Dim l As Integer
    Dim r As Integer
    Dim i As Integer
    l = LBound(args)
    r = UBound(args)
    Assert r > l, "Concat at least 2 arguments", LOCATION
    Concat = "concat("
    For i = l To r
        If i > l Then Concat = Concat & ","
        Concat = Concat & args(i)
    Next
    Concat = Concat & ")"
End Function

Public Function Mid(ByVal f As String, ByVal start As Integer, Optional ByVal Length) As String
    Mid = "substring(" & f
    If Not IsMissing(start) Then Mid = Mid & "," & start
    If Not IsMissing(Length) Then Mid = Mid & "," & Length
    Mid = Mid & ")"
End Function

Public Function Left(ByVal f As String, ByVal Length As Integer) As String
    Left = "left(" & f & "," & Length & ")"
End Function

Public Function Right(ByVal f As String, ByVal Length As Integer) As String
    Right = "right(" & f & "," & Length & ")"
End Function

Public Function PadLeft(ByVal f As String, Optional ByVal Length = 8, Optional ByVal PadChar As String = "0") As String
    Dim PadTmpl As String
    PadTmpl = String(Length, PadChar)
    PadLeft = Right(Concat(QuoteString(PadTmpl), f), Length)
End Function

Public Function PadRight(ByVal f As String, Optional ByVal Length = 8, Optional ByVal PadChar As String = " ") As String
    Dim PadTmpl As String
    PadTmpl = String(Length, PadChar)
    PadRight = Left(Concat(f, QuoteString(PadTmpl)), Length)
End Function

Public Function LTrim(ByVal f As String) As String
    LTrim = "ltrim(" & f & ")"
End Function

Public Function RTrim(ByVal f As String) As String
    RTrim = "rtrim(" & f & ")"
End Function

Public Function Trim(ByVal f As String) As String
    Trim = "trim(" & f & ")"
End Function

Public Function IsTrue(ByVal f As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = boAndNot) As String
    IsTrue = BoolBinOpComp(f & "<>0", f & " is null", WhatIfNull)
End Function

Public Function IsFalse(ByVal f As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = boAndNot) As String
    IsFalse = BoolBinOpComp(f & "=0", f & " is null", WhatIfNull)
End Function

Public Function Year(ByVal f As String) As String
    Year = "year(" & f & ")"
End Function

Public Function Month(ByVal f As String) As String
    Month = "month(" & f & ")"
End Function

Public Function Day(ByVal f As String) As String
    Day = "day(" & f & ")"
End Function

' [0-6] for [Sunday-Saturday]
Public Function Weekday(ByVal f As String) As String
    Weekday = "weekday(" & f & ")" - 1
End Function

Public Function QuoteDB(ByVal f As String, Optional ByVal dbo) As String
    QuoteDB = "[" & f & "]."
    If Not IsMissing(dbo) Then
        QuoteDB = QuoteDB & dbo & "."
    End If
End Function

Public Function StrPos(ByVal f As String, ByVal pattern As String, Optional ByVal offset As Integer = -1) As String
    If offset = -1 Then
        StrPos = "charindex(" & pattern & ", " & f & ")"
    Else
        StrPos = "charindex(" & pattern & ", " & f & ", " & offset & ")"
    End If
End Function
