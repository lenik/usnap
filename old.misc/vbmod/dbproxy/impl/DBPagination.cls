VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "DBPagination"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "DBProxy::DBPagination"

Private Const CHUNK_SHRINK              As Integer = 10
Private Const CHUNK_PREFER              As Integer = 25
Private Const CHUNK_EXPAND              As Integer = 50
'private const CHUNK_C

Private Const DEFAULT_PAGESIZE          As Integer = CHUNK_PREFER
Private Const DEFAULT_IDFIELD           As String = "id"

Public Function QueryPaged(ByVal Conn As DBConnection, _
                           ByVal SQL As String, _
                           Optional ByVal QueryType As QueryTypeConstants = 0, _
                           Optional ByVal PageSize As Integer = -1, _
                           Optional ByVal PageNo As Integer = 0, _
                           Optional ByVal Subject As String = "", _
                           Optional ByVal IdField As String = "") As Recordset
    If PageSize = -1 Then
        PageSize = Config.DBPageSize
        If IsEmpty(PageSize) Then PageSize = DEFAULT_PAGESIZE
    End If

    Assert PageSize > 0, "Illegal Page Size", LOCATION

    Dim Caching As Boolean
    Dim s As String
    Dim var As Variant
    Dim records As Long
    Dim rs As Recordset

    ' The subject corresponds to table _dbproxy_subj, which contains stat info
    ' of the subject object.
    ' @DDL  create table _dbproxy_subj(
    ' @DDL      name varchar(100) not null primary key,
    ' @DDL      idf varchar(30) not null,
    ' @DDL      vol int not null)
    If Subject = "" Then
        ' Get subject from SQL statement, automatically
        ' - Subject may be a table name, view name, this will enable the cache
        '   functionality
        ' - Otherwise, the absolute moving is used, which results in low efficiency.
        Subject = Patterns.GetSubject(SQL)
    End If

    If Subject <> "" Then
        If Left(Subject, 1) = "`" Then Subject = Mid(Subject, 1, Len(Subject) - 2)
        If Left(Subject, 1) = "[" Then Subject = Mid(Subject, 1, Len(Subject) - 2)
        Caching = Subject <> ""
    End If

    If Caching Then
        ' 1, Get subject info
        s = "select vol, idf from _dbproxy_subj where name=" & SQLF.QuoteString(Subject)
        var = Conn.QueryValue(s, 1, 2)
        If IsEmpty(var) Then            ' Lazy create
            If Not Conn.IsTableExist("_dbproxy_subj") Then
                Conn.Update "create table _dbproxy_subj(" _
                          & "    name varchar(100) not null primary key," _
                          & "    idf varchar(30) not null," _
                          & "    vol int not null)"
            End If
            IdField = "id"
            records = Conn.QueryValue("select count(*) from " & SQLF.QuoteName(Subject))
            Conn.Update "insert into _dbproxy_subj(name, idf, vol) values(" _
                      & SQLF.QuoteString(Subject) _
                      & "," & SQLF.QuoteString(IdField) _
                      & ", " & records & ")"
        Else
            IdField = var(0)
            If IdField = "" Then IdField = DEFAULT_IDFIELD
            records = CLng(var(1))
            If records = 0 Then
                records = Conn.QueryValue("select count(*) from " & SQLF.QuoteName(Subject))
                If records <> 0 Then    ' Update cache
                    Conn.Update "update " & SQLF.QuoteName(Subject) & " set vol=" & records _
                              & "    where name=" & SQLF.QuoteString(Subject)
                End If
            End If
        End If

        ' 2, Get page info

    Else
        ' No caching, using absolute movement.
        Set rs = Conn.Query(SQL, QueryType)
        rs.Move PageSize * PageNo
    End If
    Set QueryPaged = rs
End Function
