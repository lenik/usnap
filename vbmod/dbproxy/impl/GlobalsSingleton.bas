Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Private m_SQLF As SQLFunctions

Public Property Get SQLF() As SQLFunctions
    If m_SQLF Is Nothing Then
        Select Case LCase(Config.dbdialect)
        Case "mysql"
            Set m_SQLF = New SQLF_MySQL
        Case "mssql"
            Set m_SQLF = New SQLF_MSSQL
        Case "access"
            Set m_SQLF = New SQLF_Access
        Case Else
            Set m_SQLF = SQLF_Default
        End Select
    End If
    Set SQLF = m_SQLF
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
