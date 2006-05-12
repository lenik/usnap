VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SQLF_Sybase"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "DBProxy::SQLF_Sybase"

Implements SQLFunctions

Private Function SQLFunctions_Concat(ParamArray args() As Variant) As String
    SQLFunctions_Concat = SQLF_Default.Concat(args)
End Function

Private Function SQLFunctions_Left(ByVal f As String, ByVal Length As Integer) As String
    SQLFunctions_Left = SQLF_Default.Left(f, Length)
End Function

Private Function SQLFunctions_LTrim(ByVal f As String) As String
    SQLFunctions_LTrim = SQLF_Default.LTrim(f)
End Function

Private Function SQLFunctions_Mid(ByVal f As String, ByVal start As Integer, Optional ByVal Length As Variant) As String
    SQLFunctions_Mid = SQLF_Default.Mid(f, start, Length)
End Function

Private Function SQLFunctions_PadLeft(ByVal f As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = "0") As String
    SQLFunctions_PadLeft = SQLF_Default.PadLeft(f, Length, PadChar)
End Function

Private Function SQLFunctions_PadRight(ByVal f As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = " ") As String
    SQLFunctions_PadRight = SQLF_Default.PadRight(f, Length, PadChar)
End Function

Private Function SQLFunctions_QuoteDate(ByVal date_ As Date) As String
    SQLFunctions_QuoteDate = SQLFunctions_QuoteDateTime( _
        DateSerial(Year(date_), Month(date_), Day(date_)))
End Function

Private Function SQLFunctions_QuoteDateTime(ByVal date_ As Date) As String
    ' SQLFunctions_QuoteDateTime = "convert(DATETIME, " & SQLFunctions_QuoteString(date_) & ")"
    SQLFunctions_QuoteDateTime = SQLFunctions_QuoteString(date_)
End Function

Private Function SQLFunctions_QuoteName(ByVal f As String) As String
    SQLFunctions_QuoteName = "[" & f & "]"
End Function

Private Function SQLFunctions_QuoteString(ByVal f As String) As String
    SQLFunctions_QuoteString = SQLF_Default.QuoteString(f)
End Function

Private Function SQLFunctions_QuoteTime(ByVal time_ As Date) As String
    SQLFunctions_QuoteTime = SQLFunctions_QuoteDateTime( _
        TimeSerial(Hour(time_), Minute(time_), Second(time_)))
End Function

Private Function SQLFunctions_Right(ByVal f As String, ByVal Length As Integer) As String
    SQLFunctions_Right = SQLF_Default.Right(f, Length)
End Function

Private Function SQLFunctions_RTrim(ByVal f As String) As String
    SQLFunctions_RTrim = SQLF_Default.RTrim(f)
End Function

Private Function SQLFunctions_Trim(ByVal f As String) As String
    SQLFunctions_Trim = SQLF_Default.Trim(f)
End Function

Private Function SQLFunctions_IsTrue(ByVal f As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = 2&) As String
    SQLFunctions_IsTrue = SQLF_Default.IsTrue(f, WhatIfNull)
End Function

Private Function SQLFunctions_IsFalse(ByVal f As String, Optional ByVal WhatIfNull As BoolBinOpCompMethodConstants = 2&) As String
    SQLFunctions_IsFalse = SQLF_Default.IsFalse(f, WhatIfNull)
End Function

Private Function SQLFunctions_Weekday(ByVal f As String) As String
    SQLFunctions_Weekday = SQLF_Default.Weekday(f)
End Function

Private Function SQLFunctions_Year(ByVal f As String) As String
    SQLFunctions_Year = SQLF_Default.Year(f)
End Function

Private Function SQLFunctions_Month(ByVal f As String) As String
    SQLFunctions_Month = SQLF_Default.Month(f)
End Function

Private Function SQLFunctions_Day(ByVal f As String) As String
    SQLFunctions_Day = SQLF_Default.Day(f)
End Function

Public Function SQLFunctions_QuoteDB(ByVal f As String, Optional ByVal dbo) As String
    If IsMissing(dbo) Then dbo = ""
    SQLFunctions_QuoteDB = SQLF_Default.QuoteDB(f, dbo)
End Function

Private Function SQLFunctions_StrPos(ByVal f As String, ByVal pattern As String, Optional ByVal offset As Integer = -1) As String
    SQLFunctions_StrPos = SQLF_Default.StrPos(f, pattern, offset)
End Function
