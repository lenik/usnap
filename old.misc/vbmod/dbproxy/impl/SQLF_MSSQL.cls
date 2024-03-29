VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SQLF_MSSQL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "DBProxy::SQLF_MSSQL"

Implements SQLFunctions

Private Function SQLFunctions_Concat(ParamArray args_() As Variant) As String
    Dim args
    args = ParamArrayToArray(args_)

    Dim l As Integer
    Dim r As Integer
    Dim i As Integer
    l = LBound(args)
    r = UBound(args)
    Assert r > l, "Concat at least 2 arguments", LOCATION
    For i = l To r
        If i > l Then SQLFunctions_Concat = SQLFunctions_Concat & " + "
        SQLFunctions_Concat = SQLFunctions_Concat & args(i)
    Next
End Function

Private Function SQLFunctions_Left(ByVal F As String, ByVal Length As Integer) As String
    SQLFunctions_Left = SQLF_Default.Left(F, Length)
End Function

Private Function SQLFunctions_LTrim(ByVal F As String) As String
    SQLFunctions_LTrim = SQLF_Default.LTrim(F)
End Function

Private Function SQLFunctions_Mid(ByVal F As String, ByVal start As Integer, Optional ByVal Length As Variant) As String
    SQLFunctions_Mid = SQLF_Default.Mid(F, start, Length)
End Function

Private Function SQLFunctions_PadLeft(ByVal F As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = "0") As String
    SQLFunctions_PadLeft = SQLF_Default.PadLeft(F, Length, PadChar)
End Function

Private Function SQLFunctions_PadRight(ByVal F As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = " ") As String
    SQLFunctions_PadRight = SQLF_Default.PadRight(F, Length, PadChar)
End Function

Private Function SQLFunctions_QuoteDate(ByVal date_ As Date) As String
    SQLFunctions_QuoteDate = SQLF_Default.QuoteDate(date_)
End Function

Private Function SQLFunctions_QuoteDateTime(ByVal date_ As Date) As String
    SQLFunctions_QuoteDateTime = SQLF_Default.QuoteDateTime(date_)
End Function

Private Function SQLFunctions_QuoteName(ByVal F As String) As String
    SQLFunctions_QuoteName = "[" & F & "]"
End Function

Private Function SQLFunctions_QuoteString(ByVal F As String) As String
    SQLFunctions_QuoteString = SQLF_Default.QuoteString(F)
End Function

Private Function SQLFunctions_QuoteTime(ByVal time_ As Date) As String
    SQLFunctions_QuoteTime = SQLF_Default.QuoteTime(time_)
End Function

Private Function SQLFunctions_Right(ByVal F As String, ByVal Length As Integer) As String
    SQLFunctions_Right = SQLF_Default.Right(F, Length)
End Function

Private Function SQLFunctions_RTrim(ByVal F As String) As String
    SQLFunctions_RTrim = SQLF_Default.RTrim(F)
End Function

Private Function SQLFunctions_Trim(ByVal F As String) As String
    SQLFunctions_Trim = "LTRIM(RTRIM(" & F & "))"
End Function

Private Function SQLFunctions_IsTrue(ByVal F As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = 2&) As String
    SQLFunctions_IsTrue = SQLF_Default.IsTrue(F, WhatIfNull)
End Function

Private Function SQLFunctions_IsFalse(ByVal F As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = 2&) As String
    SQLFunctions_IsFalse = SQLF_Default.IsFalse(F, WhatIfNull)
End Function

Private Function SQLFunctions_Weekday(ByVal F As String) As String
    SQLFunctions_Weekday = SQLF_Default.Weekday(F)
End Function

Private Function SQLFunctions_Year(ByVal F As String) As String
    SQLFunctions_Year = SQLF_Default.Year(F)
End Function

Private Function SQLFunctions_Month(ByVal F As String) As String
    SQLFunctions_Month = SQLF_Default.Month(F)
End Function

Private Function SQLFunctions_Day(ByVal F As String) As String
    SQLFunctions_Day = SQLF_Default.Day(F)
End Function

Private Function SQLFunctions_QuoteDB(ByVal F As String, Optional ByVal dbo) As String
    If IsMissing(dbo) Then dbo = ""
    SQLFunctions_QuoteDB = SQLF_Default.QuoteDB(F, dbo)
End Function

Private Function SQLFunctions_StrPos(ByVal F As String, ByVal pattern As String, Optional ByVal offset As Integer = -1) As String
    If offset = -1 Then
        SQLFunctions_StrPos = "charindex(" & pattern & ", " & F & ")"
    Else
        SQLFunctions_StrPos = "charindex(" & pattern & ", " & F & ", " & offset & ")"
    End If
End Function

Private Property Get SQLFunctions_ConstTrue() As String
    SQLFunctions_ConstTrue = "1"
End Property

Private Property Get SQLFunctions_ConstFalse() As String
    SQLFunctions_ConstFalse = SQLF_Default.ConstFalse
End Property

Private Function SQLFunctions_Switch(ByVal F As String, ParamArray Cases_() As Variant) As Variant
    Dim Cases
    Cases = ParamArrayToArray(Cases_)

    Dim max As Integer
    Dim i As Integer
    Dim SQL As String

    max = UBound(Cases)
    Assert max >= 1, "At least 1 case should be specified", LOCATION

    ' case F
    '    when C1 then X1
    '    when C2 then X2
    ' else Xx end
    SQL = "case " & F
    For i = 0 To max - 1 Step 2
        SQL = SQL & " when " & Cases(i) & " then " & Cases(i + 1)
    Next

    If Not (max And 1) Then
        SQL = SQL & " else " & Cases(max)
    End If
    SQL = SQL & " end"

    SQLFunctions_Switch = SQL
End Function
