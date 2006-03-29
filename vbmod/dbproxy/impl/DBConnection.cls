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

Public Enum QueryTypeConstants
    qtRead = 0                          ' openForwardOnly,  lockReadOnly
    qtEdit                              ' openForwardOnly,  lockPessimistic
    qtForEach                           ' openForwardOnly,  lockReadOnly
    qtBrowse                            ' openKeyset,       lockReadonly
    qtBrowseAndEdit                     ' openKeyset,       lockPessimistic
    qtSnapshot                          ' openStatic,       lockReadonly
    qtDirectAccess                      ' openDynamic,      lockOptimistic
    qtStatistics                        ' openKeyset,       lockReadonly
    qtUpdateRedundants                  ' openForwardOnly,  lockOptimistic
    qtBatchUpdate                       ' openForwardOnly,  lockBatchOptimistic
    qtBatchUpdateBi                     ' openKeyset,       lockBatchOptimistic
End Enum

Private WithEvents m_Raw As ADODB.Connection
Attribute m_Raw.VB_VarHelpID = -1
Private m_Exported As Connection

Private m_LockType As LockTypeEnum      ' Default lock type
Private m_CursorType As CursorTypeEnum  ' Default cursor type

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

Private Property Get Exported() As ADODB.Connection
    If m_Exported Is Nothing Then
        Set m_Exported = ExportConnection(Me)
    End If
    Set Exported = m_Exported
End Property

Public Property Get Connection() As ADODB.Connection
    Set Connection = Exported
End Property

Public Function Query(ByVal SQL As String, Optional ByVal QueryType As QueryTypeConstants = 0) As Recordset
    Set Query = New Recordset
    ' OPT: ExecuteOptionEnum
    Query.Open SQL, m_Raw, Presets.CursorType(QueryType), Presets.LockType(QueryType)
End Function

Public Function Update(ByVal SQL As String, Optional ByVal Options As Long = -1) As Long
    Dim records
    m_Raw.Execute SQL, records, Options
    Update = CLng(records)
End Function

Public Function QueryValue(ByVal SQL As String, Optional ByVal Rows, Optional ByVal Columns, Optional ByVal AlwaysMatrix As Boolean = False)
    Dim rs As Recordset
    Dim ScanCols As Integer
    Dim iRow As Integer
    Dim iCol As Integer
    Dim vec As Vector
    Dim i As Integer, j As Integer

    Set rs = m_Raw.Execute(SQL)

    ' Empty if N/A
    If rs.EOF Then Exit Function

    If IsMissing(Rows) Then
        If IsMissing(Columns) Then
            ' Scalar
            QueryValue = rs.Fields(0)
        Else
            ' QueryValue(SQL, , COLUMN)
            ' Y-Vector
            Columns = Int(Val(Columns))
            Assert Columns > 0
            If Columns >= rs.Fields.Count Then Exit Function

            Set vec = New Vector
            Do While Not rs.EOF
                vec.Push rs.Fields(Columns).value
                rs.MoveNext
            Loop

            ReDim yvec(0 To vec.Size - 1)
            For iRow = 0 To vec.Size - 1
                yvec(iRow) = vec(iRow)
            Next
            QueryValue = yvec
        End If
    Else
        Rows = Int(Val(Rows))
        Assert Rows >= 0
        If IsMissing(Columns) Then
            ' QueryValue(SQL, ROW, )
            ' X-Vector
            While Rows > 0 And Not rs.EOF
                rs.MoveNext
                Rows = Rows - 1
            Wend
            ' Empty if N/A
            If rs.EOF Then Exit Function

            ReDim xvec(0 To rs.Fields.Count - 1)
            For iCol = 0 To rs.Fields.Count - 1
                xvec(iCol) = rs.Fields(iCol).value
            Next
            QueryValue = xvec
        Else
            Assert Rows > 0

            Columns = Int(Val(Columns))
            Assert Columns > 0

            If (Rows > 1 And Columns > 1) Or AlwaysMatrix Then
                ' Matrix, Array(Fixed-Columns, ??) with empty cells if N/A
                ReDim mat(0 To Rows - 1, 0 To Columns - 1)
                ' Min(fields, columns)
                ScanCols = IIf(Columns > rs.Fields.Count, rs.Fields.Count, Columns)
                Do While Not rs.EOF
                    If iRow >= Rows Then Exit Do
                    For iCol = 0 To ScanCols - 1
                        mat(iRow, iCol) = rs.Fields(iCol).value
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
                        ' OPT  Only X could be redim, when dim Array(X, Y)
                        ' OPT  So not using Preserve keyword to make the copy faster.
                        ReDim mat2(0 To iRow - 1, 0 To Columns - 1)
                        For i = 0 To iRow - 1
                            For j = 0 To Columns - 1
                                mat2(i, j) = mat(i, j)
                            Next
                        Next
                        QueryValue = mat2
                    End If
                End If

                If IsEmpty(QueryValue) Then QueryValue = mat

            ElseIf Rows = 1 Then
                ' Column-Vector
                ReDim cvec(0 To Columns - 1)
                ' Min(fields, columns)
                ScanCols = IIf(Columns > rs.Fields.Count, rs.Fields.Count, Columns)
                For iCol = 0 To ScanCols - 1
                    cvec(iCol) = rs.Fields(iCol)
                Next
                QueryValue = cvec
            ElseIf Columns = 1 Then
                ' Row-Vector, Fixed-Array with empty cells if N/A
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
                Unexpected
            End If
        End If
    End If

    rs.Close
End Function

Public Function QueryToCache(ByVal SQL As String) As DBResultCache
    Dim rs As Recordset
    Dim c As New DBResultCache
    Set rs = m_Raw.Execute(SQL)
    While rs.EOF
        ' Save to cache...
        rs.MoveNext
    Wend
    rs.Close
    Set QueryToCache = c
End Function

Private Function IsInSchema(ByVal Schema As SchemaEnum, ByVal Name As String) As Boolean
    Dim rs As Recordset
    Set rs = m_Raw.OpenSchema(Schema, Name)
    IsInSchema = Not rs.EOF
End Function

Public Function IsTableExist(ByVal Name As String) As Boolean
    IsTableExist = IsInSchema(adSchemaTables, Name)
    ' If Not IsTableExist Then
End Function

' Privates

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
    m_Raw.CursorLocation = adUseClient
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
