VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "DBConnection"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Private WithEvents m_Raw As ADODB.Connection
Attribute m_Raw.VB_VarHelpID = -1
Private m_Exported As Connection

Private m_Filter As New DBSQLFilter

Implements ADOMapping.IConnection

Event BeginTransComplete(ByVal TransactionLevel As Long, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
Event CommitTransComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
Event ConnectComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
Event Disconnect(adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
Event ExecuteComplete(ByVal RecordsAffected As Long, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pCommand As ADODB.Command, ByVal pRecordset As ADODB.Recordset, ByVal pConnection As ADODB.Connection)
Event InfoMessage(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
Event RollbackTransComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
Event WillConnect(ConnectionString As String, UserID As String, Password As String, Options As Long, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
Event WillExecute(Source As String, CursorType As ADODB.CursorTypeEnum, LockType As ADODB.LockTypeEnum, Options As Long, adStatus As ADODB.EventStatusEnum, ByVal pCommand As ADODB.Command, ByVal pRecordset As ADODB.Recordset, ByVal pConnection As ADODB.Connection)

' New Features

Public Property Get Connection() As Connection
    If m_Exported Is Nothing Then
        Set m_Exported = ExportConnection(Me)
    End If
    Set Connection = m_Exported
End Property

Public Function Query(ByVal sql As String, Optional ByVal Options As Long = -1) As Recordset
    Dim records
    Set Query = m_Raw.Execute(sql, records, Options)
End Function

Public Function Update(ByVal sql As String, Optional ByVal Options As Long = -1) As Long
    Dim records
    m_Raw.Execute sql, records, Options
    Update = CLng(records)
End Function

Public Function QueryValue(ByVal sql As String, Optional ByVal Rows As Integer = 1, Optional ByVal Columns As Integer = 1)
    Dim rs As Recordset
    Dim Cols As Integer
    Dim iRow As Integer
    Dim iCol As Integer

    Assert Rows > 0 And Columns > 0

    Set rs = m_Raw.Execute(sql)

    If Rows = 1 And Columns = 1 Then
        If Not rs.EOF Then
            QueryValue = rs.Fields(0)
        End If
    ElseIf Rows > 1 And Columns > 1 Then
        ' Matrix
        ReDim mat(0 To Columns - 1, 0 To Rows - 1)
        ' Min(fields, columns)
        Cols = IIf(Columns > rs.Fields.Count, rs.Fields.Count, Columns)
        Do While Not rs.EOF
            If iRow >= Rows Then Exit Do
            For iCol = 0 To Cols - 1
                mat(iCol, iRow) = rs.Fields(iCol).value
            Next
            rs.MoveNext
            iRow = iRow + 1
        Loop
        ' Expect iRow == Rows
        If iRow < Rows Then
            If iRow = 0 Then
                ' QueryValue = Empty
                Exit Function
            Else
                ' Only rows could be redim.
                ReDim Preserve mat(0 To Columns - 1, 0 To iRow - 1)
            End If
        End If
        QueryValue = mat
    ElseIf Rows > 1 Then
        ' Row-Vector
        ReDim rvec(0 To Rows - 1)
        Do While Not rs.EOF
            If iRow >= Rows Then Exit Do
            rvec(iRow) = rs.Fields(0).value
            rs.MoveNext
            iRow = iRow + 1
        Loop
        ' Expect iRow == Rows
        If iRow < Rows Then
            If iRow = 0 Then
                ' QueryValue = Empty
                Exit Function
            Else
                ReDim Preserve rvec(0 To iRow - 1)
            End If
        End If
        QueryValue = rvec
    Else
        ' Column-Vector
        If Not rs.EOF Then
            ReDim cvec(0 To Columns - 1)
            ' Min(fields, columns)
            Cols = IIf(Columns > rs.Fields.Count, rs.Fields.Count, Columns)
            For iCol = 0 To Cols - 1
                cvec(iCol) = rs.Fields(iCol)
            Next
            QueryValue = cvec
        End If
    End If

    rs.Close
End Function

Public Function QueryToCache(ByVal sql As String) As DBResultCache
    Dim rs As Recordset
    Dim c As New DBResultCache
    Set rs = m_Raw.Execute(sql)
    While rs.EOF
        ' Save to cache...
        rs.MoveNext
    Wend
    rs.Close
    Set QueryToCache = c
End Function

' New Features Helpers

Private Sub Class_Initialize()
    Set m_Raw = New Connection
End Sub

'
' -o DBConnection
'
Public Property Let Attributes(ByVal RHS As Long)
    m_Raw.Attributes = RHS
End Property

Public Property Get Attributes() As Long
    Attributes = m_Raw.Attributes
End Property

Public Function BeginTrans() As Long
    BeginTrans = m_Raw.BeginTrans
End Function

Public Sub Cancel()
    m_Raw.Cancel
End Sub

Public Sub Recycle()
    m_Raw.Close
End Sub

Public Property Let CommandTimeout(ByVal RHS As Long)
    m_Raw.CommandTimeout = RHS
End Property

Public Property Get CommandTimeout() As Long
    CommandTimeout = m_Raw.CommandTimeout
End Property

Public Sub CommitTrans()
    m_Raw.CommitTrans
End Sub

Public Property Let ConnectionString(ByVal RHS As String)
    m_Raw.ConnectionString = RHS
End Property

Public Property Get ConnectionString() As String
    ConnectionString = m_Raw.ConnectionString
End Property

Public Property Let ConnectionTimeout(ByVal RHS As Long)
    m_Raw.ConnectionTimeout = RHS
End Property

Public Property Get ConnectionTimeout() As Long
    ConnectionTimeout = m_Raw.ConnectionTimeout
End Property

Public Property Let CursorLocation(ByVal RHS As ADODB.CursorLocationEnum)
    m_Raw.CursorLocation = RHS
End Property

Public Property Get CursorLocation() As ADODB.CursorLocationEnum
    CursorLocation = m_Raw.CursorLocation
End Property

Public Property Let DefaultDatabase(ByVal RHS As String)
    m_Raw.DefaultDatabase = RHS
End Property

Public Property Get DefaultDatabase() As String
    DefaultDatabase = m_Raw.DefaultDatabase
End Property

Public Property Get Errors() As ADODB.Errors
    Set Errors = m_Raw.Errors
End Property

Public Function Execute(ByVal CommandText As String, Optional RecordsAffected As Variant, Optional ByVal Options As Long = -1&) As ADODB.Recordset
    Set Execute = m_Raw.Execute(CommandText, RecordsAffected, Options)
End Function

Public Property Let IsolationLevel(ByVal RHS As ADODB.IsolationLevelEnum)
    m_Raw.IsolationLevel = RHS
End Property

Public Property Get IsolationLevel() As ADODB.IsolationLevelEnum
    IsolationLevel = m_Raw.IsolationLevel
End Property

Public Property Let Mode(ByVal RHS As ADODB.ConnectModeEnum)
    m_Raw.Mode = RHS
End Property

Public Property Get Mode() As ADODB.ConnectModeEnum
    Mode = m_Raw.Mode
End Property

Public Sub Allocate(Optional ByVal ConnectionString As String = "", Optional ByVal UserID As String = "", Optional ByVal Password As String = "", Optional ByVal Options As Long = -1&)
    m_Raw.Open ConnectionString, UserID, Password, Options
End Sub

Public Function OpenSchema(ByVal Schema As ADODB.SchemaEnum, Optional ByVal Restrictions As Variant, Optional ByVal SchemaID As Variant) As ADODB.Recordset
    Set OpenSchema = m_Raw.OpenSchema(Schema, Restrictions, SchemaID)
End Function

Public Property Get Properties() As ADODB.Properties
    Set Properties = m_Raw.Properties
End Property

Public Property Let Provider(ByVal RHS As String)
    m_Raw.Provider = RHS
End Property

Public Property Get Provider() As String
    Provider = m_Raw.Provider
End Property

Public Sub RollbackTrans()
    m_Raw.RollbackTrans
End Sub

Public Property Get State() As Long
    State = m_Raw.State
End Property

Public Property Get Version() As String
    Version = m_Raw.Version
End Property


'
' -o IConnection
'
Private Property Let IConnection_Attributes(ByVal RHS As Long)
    m_Raw.Attributes = RHS
End Property

Private Property Get IConnection_Attributes() As Long
    IConnection_Attributes = m_Raw.Attributes
End Property

Private Function IConnection_BeginTrans() As Long
    IConnection_BeginTrans = m_Raw.BeginTrans
End Function

Private Sub IConnection_Cancel()
    m_Raw.Cancel
End Sub

Private Sub IConnection_Close()
    m_Raw.Close
End Sub

Private Property Let IConnection_CommandTimeout(ByVal RHS As Long)
    m_Raw.CommandTimeout = RHS
End Property

Private Property Get IConnection_CommandTimeout() As Long
    IConnection_CommandTimeout = m_Raw.CommandTimeout
End Property

Private Sub IConnection_CommitTrans()
    m_Raw.CommitTrans
End Sub

Private Property Let IConnection_ConnectionString(ByVal RHS As String)
    m_Raw.ConnectionString = RHS
End Property

Private Property Get IConnection_ConnectionString() As String
    IConnection_ConnectionString = m_Raw.ConnectionString
End Property

Private Property Let IConnection_ConnectionTimeout(ByVal RHS As Long)
    m_Raw.ConnectionTimeout = RHS
End Property

Private Property Get IConnection_ConnectionTimeout() As Long
    IConnection_ConnectionTimeout = m_Raw.ConnectionTimeout
End Property

Private Property Let IConnection_CursorLocation(ByVal RHS As ADODB.CursorLocationEnum)
    m_Raw.CursorLocation = RHS
End Property

Private Property Get IConnection_CursorLocation() As ADODB.CursorLocationEnum
    IConnection_CursorLocation = m_Raw.CursorLocation
End Property

Private Property Let IConnection_DefaultDatabase(ByVal RHS As String)
    m_Raw.DefaultDatabase = RHS
End Property

Private Property Get IConnection_DefaultDatabase() As String
    IConnection_DefaultDatabase = m_Raw.DefaultDatabase
End Property

Private Property Get IConnection_Errors() As ADODB.Errors
    Set IConnection_Errors = m_Raw.Errors
End Property

Private Function IConnection_Execute(ByVal CommandText As String, Optional RecordsAffected As Variant, Optional ByVal Options As Long = -1&) As ADODB.Recordset
    Set IConnection_Execute = m_Raw.Execute(CommandText, RecordsAffected, Options)
End Function

Private Property Let IConnection_IsolationLevel(ByVal RHS As ADODB.IsolationLevelEnum)
    m_Raw.IsolationLevel = RHS
End Property

Private Property Get IConnection_IsolationLevel() As ADODB.IsolationLevelEnum
    IConnection_IsolationLevel = m_Raw.IsolationLevel
End Property

Private Property Let IConnection_Mode(ByVal RHS As ADODB.ConnectModeEnum)
    m_Raw.Mode = RHS
End Property

Private Property Get IConnection_Mode() As ADODB.ConnectModeEnum
    IConnection_Mode = m_Raw.Mode
End Property

Private Sub IConnection_Open(Optional ByVal ConnectionString As String = "", Optional ByVal UserID As String = "", Optional ByVal Password As String = "", Optional ByVal Options As Long = -1&)
    m_Raw.Open ConnectionString, UserID, Password, Options
End Sub

Private Function IConnection_OpenSchema(ByVal Schema As ADODB.SchemaEnum, Optional ByVal Restrictions As Variant, Optional ByVal SchemaID As Variant) As ADODB.Recordset
    Set IConnection_OpenSchema = m_Raw.OpenSchema(Schema, Restrictions, SchemaID)
End Function

Private Property Get IConnection_Properties() As ADODB.Properties
    Set IConnection_Properties = m_Raw.Properties
End Property

Private Property Let IConnection_Provider(ByVal RHS As String)
    m_Raw.Provider = RHS
End Property

Private Property Get IConnection_Provider() As String
    IConnection_Provider = m_Raw.Provider
End Property

Private Sub IConnection_RollbackTrans()
    m_Raw.RollbackTrans
End Sub

Private Property Get IConnection_State() As Long
    IConnection_State = m_Raw.State
End Property

Private Property Get IConnection_Version() As String
    IConnection_Version = m_Raw.Version
End Property

Private Sub m_Raw_BeginTransComplete(ByVal TransactionLevel As Long, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
    RaiseEvent BeginTransComplete(TransactionLevel, pError, adStatus, pConnection)
End Sub

Private Sub m_Raw_CommitTransComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
    RaiseEvent CommitTransComplete(pError, adStatus, pConnection)
End Sub

Private Sub m_Raw_ConnectComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
    RaiseEvent ConnectComplete(pError, adStatus, pConnection)
End Sub

Private Sub m_Raw_Disconnect(adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
    RaiseEvent Disconnect(adStatusCancel, pConnection)
End Sub

Private Sub m_Raw_ExecuteComplete(ByVal RecordsAffected As Long, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pCommand As ADODB.Command, ByVal pRecordset As ADODB.Recordset, ByVal pConnection As ADODB.Connection)
    RaiseEvent ExecuteComplete(RecordsAffected, pError, adStatus, pCommand, pRecordset, pConnection)
End Sub

Private Sub m_Raw_InfoMessage(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
    RaiseEvent InfoMessage(pError, adStatus, pConnection)
End Sub

Private Sub m_Raw_RollbackTransComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
    RaiseEvent RollbackTransComplete(pError, adStatusCancel, pConnection)
End Sub

Private Sub m_Raw_WillConnect(ConnectionString As String, UserID As String, Password As String, Options As Long, adStatus As ADODB.EventStatusEnum, ByVal pConnection As ADODB.Connection)
    RaiseEvent WillConnect(ConnectionString, UserID, Password, Options, adStatus, pConnection)
End Sub

Private Sub m_Raw_WillExecute(Source As String, CursorType As ADODB.CursorTypeEnum, LockType As ADODB.LockTypeEnum, Options As Long, adStatus As ADODB.EventStatusEnum, ByVal pCommand As ADODB.Command, ByVal pRecordset As ADODB.Recordset, ByVal pConnection As ADODB.Connection)
    RaiseEvent WillExecute(Source, CursorType, LockType, Options, adStatus, pCommand, pRecordset, pConnection)
End Sub