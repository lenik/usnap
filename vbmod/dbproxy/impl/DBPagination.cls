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

Private Const DEFAULT_PAGESIZE          As Integer = 100
Private Const DEFAULT_IDFIELD           As String = "id"

Public Function QueryPaged(ByVal Conn As DBConnection, _
                           ByVal SQL As String, _
                           Optional ByVal QueryType As QueryTypeConstants = 0, _
                           Optional ByVal PageSize As Integer = -1, _
                           Optional ByVal PageNo As Integer = 0, _
                           Optional ByVal Subject As String = "", _
                           Optional ByVal IdField As String = "")
    If PageSize = -1 Then
        PageSize = Config.DBPageSize
        If IsEmpty(PageSize) Then PageSize = DEFAULT_PAGESIZE
    End If

    Assert PageSize > 0, "Illegal Page Size", LOCATION

    Dim Caching As Boolean
    Dim s As String
    Dim var As Variant
    Dim records As Long

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
        s = "select vol, idf from _dbproxy_subj where name='" & Subject & "'"
        var = Conn.QueryValue(s, 1, 2)
        If IdField = "" Then
            IdField = var(0)
            If IdField = "" Then IdField = DEFAULT_IDFIELD
        End If
        records = CLng(var(1))
        If records = 0 Then
            records = Conn.QueryValue("select count(*) from " & SQLF.QuoteName(Subject))
        End If
    End If

End Function
