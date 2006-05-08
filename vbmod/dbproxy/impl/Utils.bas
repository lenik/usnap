Attribute VB_Name = "Utils"
Option Explicit
Option Base 0

Public Function GuessDialect(ByVal ConnectionString As String) As String
    Dim Driver As String
    Dim Dialect As String
    Dim i As Integer
    Dim j As Integer

    i = InStr(ConnectionString, "::")
    If i > 3 Then                       ' At least 3 chars
        GuessDialect = LCase(Left(ConnectionString, i - 1))
        Exit Function
    End If

    i = InStr(LCase(ConnectionString), "driver=")
    If i > 0 Then
        ' ^driver=... or ;driver=...
        If i <> 1 Then
            If Mid(ConnectionString, i - 1, 1) <> ";" Then
                GoTo NoDriver
            End If
        End If
        Driver = Mid(ConnectionString, i + 7)
        If Left(Driver, 1) = "{" Then
            j = InStr(Driver, "}")
            If j > 0 Then Driver = Mid(Driver, 2, j - 2)
        Else
            j = InStr(Driver, ";")
            If j > 0 Then Driver = Mid(Driver, 1, j - 1)
        End If
    End If

    Select Case LCase(Driver)
    ' AS-400
    Case "client access odbc driver (32-bit)"
        Dialect = "as400"
    ' Access
    Case "microsoft access driver (*.mdb)"
        Dialect = "access"
    ' dBase
    Case "microsoft dbase driver (*.dbf)"
        Dialect = "dbase"
    ' Excel
    Case "microsoft excel driver (*.xls)"
        Dialect = "excel"
    ' MySQL
    Case "mysql", "mysql odbc 3.51 driver"
        Dialect = "mysql"
    ' Oracle
    Case "microsoft odbc for oracle", "microsoft odbc driver for oracle"
        Dialect = "oracle"
    ' Paradox
    Case "microsoft paradox driver (*.db)"
        Dialect = "paradox"
    ' Microsoft SQL Server
    Case "sql server"
        Dialect = "mssql"
    ' Sybase
    Case "sybase system 11", "intersolv 3.10 32-bit sybase", _
         "openlink lite for sql server (unicode) [6.0]", _
         "openlink lite for sql server [6.0]"
        Dialect = "sybase"
    ' Sybase Anywhere
    Case "sybase sql anywhere 5.0"
        Dialect = "asa"
    ' Text
    Case "microsoft text driver (*.txt; *.csv)"
        Dialect = "text"
    ' FoxPro
    Case "microsoft visual foxpro driver"
        Dialect = "foxpro"
    End Select

    If Dialect = "" Then GoTo NoDriver
    GuessDialect = Dialect
    Exit Function

NoDriver:
    GuessDialect = "unknown"
End Function

Public Function ParamArrayToArray(ParamArray params_()) As Variant()
    Dim Params
    Params = params_(0)
    Dim l As Integer
    l = LBound(Params)
    If l = UBound(Params) Then
        If TypeName(Params(l)) = "Variant()" Then
            ParamArrayToArray = Params(l)
            Exit Function
        End If
    End If
    ParamArrayToArray = Params
End Function

Private Function SQLParseSQLF(ByVal SqlfExp As String, ByVal VarMap As VBExt.Map, ByVal SQLF As SQLFunctions) As String
    Dim lt As Integer
    Dim gt As Integer
    Dim name As String
    Dim Params

    lt = InStr(SqlfExp, "<")
    gt = InStr(SqlfExp, ">")
    name = Mid(SqlfExp, 1, lt - 1)
    Params = Mid(SqlfExp, lt + 1, gt - lt - 1)
    Params = Split(Params, ",")

    Select Case LCase(name)
    Case "concat"
        SQLParseSQLF = SQLF.Concat(Params)
    Case "left"
        SQLParseSQLF = SQLF.Left(Params(0), Params(1))
    Case "right"
        SQLParseSQLF = SQLF.Right(Params(0), Params(1))
    Case "mid"
        SQLParseSQLF = SQLF.Mid(Params(0), Params(1), Params(2))
    Case "padleft"
        If UBound(Params) > 3 Then
            SQLParseSQLF = SQLF.PadLeft(Params(0), Params(1), Params(2))
        ElseIf UBound(Params) > 2 Then
            SQLParseSQLF = SQLF.PadLeft(Params(0), Params(1))
        Else
            SQLParseSQLF = SQLF.PadLeft(Params(0))
        End If
    Case "padright"
        If UBound(Params) > 3 Then
            SQLParseSQLF = SQLF.PadRight(Params(0), Params(1), Params(2))
        ElseIf UBound(Params) > 2 Then
            SQLParseSQLF = SQLF.PadRight(Params(0), Params(1))
        Else
            SQLParseSQLF = SQLF.PadRight(Params(0))
        End If
    Case "quotedate"
        SQLParseSQLF = SQLF.QuoteDate(CDate(Params(0)))
    Case "quotetime"
        SQLParseSQLF = SQLF.QuoteTime(CDate(Params(0)))
    Case "quotedatetime"
        SQLParseSQLF = SQLF.QuoteDateTime(CDate(Params(0)))
    Case "quotestring"
        SQLParseSQLF = SQLF.QuoteString(Params(0))
    Case "quotename"
        SQLParseSQLF = SQLF.QuoteName(Params(0))
    Case "trim"
        SQLParseSQLF = SQLF.Trim(Params(0))
    Case "ltrim"
        SQLParseSQLF = SQLF.LTrim(Params(0))
    Case "rtrim"
        SQLParseSQLF = SQLF.RTrim(Params(0))
    Case Else
        SQLParseSQLF = name & "(" & Join(Params, ",") & ")"
    End Select
End Function

Public Function SQLParse(ByVal QuotedSQL As String, ByVal VarDef As String, ByVal SQLF As SQLFunctions) As String
    Dim VarMap As VBExt.Map
    Set VarMap = ParseMap(VarDef)

    Dim matches As MatchCollection
    Dim mat As Match
    Dim i As Integer
    Dim lastIndex As Long
    Dim seg As String
    Dim v

    Set matches = Patterns.RE_QSQL.Execute(QuotedSQL)
    lastIndex = 1

    For i = 0 To matches.Count - 1
        Set mat = matches(i)
        seg = mat.value
        SQLParse = SQLParse & Mid(QuotedSQL, lastIndex, mat.FirstIndex - lastIndex + 1)

        If Left(seg, 1) = "?" Then
            seg = SQLParseSQLF(Mid(seg, 2), VarMap, SQLF)
        ElseIf Left(seg, 1) = "$" Then
            v = VarMap.Item(Mid(seg, 2))
            If IsNull(v) Then
                v = Application.Item(Mid(seg, 2))
                If IsEmpty(v) Then v = Null
            End If
            If Not IsNull(v) Then
                seg = v
            End If
        Else
            Unexpected "The regexp should only match ?... or $..."
        End If
        SQLParse = SQLParse & seg
        lastIndex = mat.FirstIndex + 1 + mat.Length
    Next

    If lastIndex < Len((QuotedSQL)) Then
        SQLParse = SQLParse & Mid(QuotedSQL, lastIndex)
    End If
End Function

Public Function AddParenthesis(ByVal s As String) As String
    If Patterns.RE_OnlyWord.Test(s) Then
        AddParenthesis = s
    ElseIf Patterns.RE_InParenthesis.Test(s) Then
        AddParenthesis = s
    Else
        AddParenthesis = "(" & s & ")"
    End If
End Function

Public Function BoolBinOpComp(ByVal l As String, ByVal r As String, _
                              ByVal m As BoolBinOpCompMethodConstants) As String
    l = AddParenthesis(l)
    r = AddParenthesis(r)
    Select Case m
    Case boDontCare
        BoolBinOpComp = l
    Case boAnd
        BoolBinOpComp = "(" & l & " and " & r & ")"
    Case boAndNot
        BoolBinOpComp = "(" & l & " and not " & r & ")"
    Case boOr
        BoolBinOpComp = "(" & l & " or " & r & ")"
    Case boOrNot
        BoolBinOpComp = "(" & l & " or not " & r & ")"
    Case boXor
        BoolBinOpComp = "(" & l & " and not " & r & " or not " & l & " and " & r & ")"
    End Select
End Function
