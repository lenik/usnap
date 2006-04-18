Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Private m_ConfigSQLF As SQLFunctions

Public Property Get SQLF(Optional ByVal Dialect As String) As SQLFunctions
    If Dialect = "" Then
        If m_ConfigSQLF Is Nothing Then
            Set m_ConfigSQLF = SQLF(Config.DBDialect)
        End If
        Set SQLF = m_ConfigSQLF
        Exit Property
    End If

    Select Case LCase(Dialect)
    Case "as400"
    Case "access"
        Set SQLF = New SQLF_Access
    Case "dbase"
    Case "excel"
    Case "mysql"
        Set SQLF = New SQLF_MySQL
    Case "oracle"
    Case "paradox"
    Case "mssql"
        Set SQLF = New SQLF_MSSQL
    Case "sybase"
        Set SQLF = New SQLF_Sybase
    Case "asa"
    Case "text"
    Case "foxpro"
    Case Else
        Set SQLF = SQLF_Default
    End Select
End Property

Public Property Get Dict() As DBDict
    LC.Assign Dict, Ref(vbxSoftReference, "DBProxy::Dict")
    If IsNull(Dict) Then
        Set Dict = RebuildDict
        'Ref(vbxSoftReference, "DBProxy::Dict") = refDict
    End If
End Property

Public Function RebuildDict() As DBDict
    Dim Conn
    'Set conn = DefaultConnection

    ' Dict tables...
End Function
