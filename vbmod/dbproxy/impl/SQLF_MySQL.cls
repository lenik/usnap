VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SQLF_MySQL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Implements SQLFunctions

Private Function SQLFunctions_Concat(ParamArray args() As Variant) As String
    SQLFunctions_Concat = SQLF_Default.Concat(args)
End Function

Private Function SQLFunctions_Left(ByVal Name As String, ByVal Length As Integer) As String
    SQLFunctions_Left = SQLF_Default.Left(Name, Length)
End Function

Private Function SQLFunctions_Mid(ByVal Name As String, ByVal start As Integer, Optional ByVal Length As Variant) As String
    SQLFunctions_Mid = SQLF_Default.Mid(Name, start, Length)
End Function

Private Function SQLFunctions_PadLeft(ByVal Name As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = "0") As String
    SQLFunctions_PadLeft = SQLF_Default.PadLeft(Name, Length, PadChar)
End Function

Private Function SQLFunctions_PadRight(ByVal Name As String, Optional ByVal Length As Variant = 8, Optional ByVal PadChar As String = " ") As String
    SQLFunctions_PadRight = SQLF_Default.PadRight(Name, Length, PadChar)
End Function

Private Function SQLFunctions_QuoteDate(ByVal date_ As Date) As String
    SQLFunctions_QuoteDate = SQLF_Default.QuoteDate(date_)
End Function

Private Function SQLFunctions_QuoteDateTime(ByVal date_ As Date) As String
    SQLFunctions_QuoteDateTime = SQLF_Default.QuoteDateTime(date_)
End Function

Private Function SQLFunctions_QuoteName(ByVal Name As String) As String
    SQLFunctions_QuoteName = SQLF_Default.QuoteName(Name)
End Function

Private Function SQLFunctions_QuoteString(ByVal str As String) As String
    SQLFunctions_QuoteString = SQLF_Default.QuoteString(str)
End Function

Private Function SQLFunctions_QuoteTime(ByVal time_ As Date) As String
    SQLFunctions_QuoteTime = SQLF_Default.QuoteTime(time_)
End Function

Private Function SQLFunctions_Right(ByVal Name As String, ByVal Length As Integer) As String
    SQLFunctions_Right = SQLF_Default.Right(Name, Length)
End Function
