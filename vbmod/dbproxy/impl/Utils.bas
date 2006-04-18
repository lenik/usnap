Attribute VB_Name = "Utils"
Option Explicit

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
