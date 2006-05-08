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

Private Function SQLFunctions_Left(ByVal str As String, ByVal Length As Integer) As String
    SQLFunctions_Left = SQLF_Default.Left(str, Length)
End Function

Private Function SQLFunctions_LTrim(ByVal str As String) As String
    SQLFunctions_LTrim = SQLF_Default.LTrim(str)
End Function

Private Function SQLFunctions_Mid(ByVal str As String, ByVal start As Integer, Optional ByVal Length As Variant) As String
    SQLFunctions_Mid = SQLF_Default.Mid(str, start, Length)
End Function

Private Function SQLFunctions_PadLeft(ByVal str As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = "0") As String
    SQLFunctions_PadLeft = SQLF_Default.PadLeft(str, Length, PadChar)
End Function

Private Function SQLFunctions_PadRight(ByVal str As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = " ") As String
    SQLFunctions_PadRight = SQLF_Default.PadRight(str, Length, PadChar)
End Function

Private Function SQLFunctions_QuoteDate(ByVal date_ As Date) As String
    SQLFunctions_QuoteDate = SQLF_Default.QuoteDate(date_)
End Function

Private Function SQLFunctions_QuoteDateTime(ByVal date_ As Date) As String
    SQLFunctions_QuoteDateTime = SQLF_Default.QuoteDateTime(date_)
End Function

Private Function SQLFunctions_QuoteName(ByVal str As String) As String
    SQLFunctions_QuoteName = "[" & str & "]"
End Function

Private Function SQLFunctions_QuoteString(ByVal str As String) As String
    SQLFunctions_QuoteString = SQLF_Default.QuoteString(str)
End Function

Private Function SQLFunctions_QuoteTime(ByVal time_ As Date) As String
    SQLFunctions_QuoteTime = SQLF_Default.QuoteTime(time_)
End Function

Private Function SQLFunctions_Right(ByVal str As String, ByVal Length As Integer) As String
    SQLFunctions_Right = SQLF_Default.Right(str, Length)
End Function

Private Function SQLFunctions_RTrim(ByVal str As String) As String
    SQLFunctions_RTrim = SQLF_Default.RTrim(str)
End Function

Private Function SQLFunctions_Trim(ByVal str As String) As String
    SQLFunctions_Trim = "LTRIM(RTRIM(" & str & "))"
End Function

Private Function SQLFunctions_IsTrue(ByVal str As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = 2&) As String
    SQLFunctions_IsTrue = SQLF_Default.IsTrue(str, WhatIfNull)
End Function

Private Function SQLFunctions_IsFalse(ByVal str As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = 2&) As String
    SQLFunctions_IsFalse = SQLF_Default.IsFalse(str, WhatIfNull)
End Function

Private Function SQLFunctions_Weekday(ByVal str As String) As String
    SQLFunctions_Weekday = SQLF_Default.Weekday(str)
End Function

Private Function SQLFunctions_Year(ByVal str As String) As String
    SQLFunctions_Year = SQLF_Default.Year(str)
End Function

Private Function SQLFunctions_Month(ByVal str As String) As String
    SQLFunctions_Month = SQLF_Default.Month(str)
End Function

Private Function SQLFunctions_Day(ByVal str As String) As String
    SQLFunctions_Day = SQLF_Default.Day(str)
End Function

Public Function SQLFunctions_QuoteDB(ByVal str As String, Optional ByVal dbo) As String
    If IsMissing(dbo) Then dbo = ""
    SQLFunctions_QuoteDB = SQLF_Default.QuoteDB(str, dbo)
End Function
