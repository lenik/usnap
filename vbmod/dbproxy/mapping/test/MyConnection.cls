VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MyConnection"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private WithEvents m_Raw As ADODB.Connection
Attribute m_Raw.VB_VarHelpID = -1

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

Private Sub Class_Initialize()
    Set m_Raw = New Connection
End Sub

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
