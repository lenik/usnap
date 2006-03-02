VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MyRecordset"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private WithEvents m_Raw As ADODB.Recordset
Attribute m_Raw.VB_VarHelpID = -1
Private LC As New LowXRuntime.Component

Implements ADOMapping.IRecordset

Event EndOfRecordset(fMoreData As Boolean, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event FetchComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event FetchProgress(ByVal Progress As Long, ByVal MaxProgress As Long, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event FieldChangeComplete(ByVal cFields As Long, ByVal Fields As Variant, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event MoveComplete(ByVal adReason As ADODB.EventReasonEnum, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event RecordChangeComplete(ByVal adReason As ADODB.EventReasonEnum, ByVal cRecords As Long, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event RecordsetChangeComplete(ByVal adReason As ADODB.EventReasonEnum, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event WillChangeField(ByVal cFields As Long, ByVal Fields As Variant, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event WillChangeRecord(ByVal adReason As ADODB.EventReasonEnum, ByVal cRecords As Long, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event WillChangeRecordset(ByVal adReason As ADODB.EventReasonEnum, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
Event WillMove(ByVal adReason As ADODB.EventReasonEnum, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)

Private Sub Class_Initialize()
    Set m_Raw = New ADODB.Recordset
End Sub

Private Property Let IRecordset_AbsolutePage(ByVal RHS As ADODB.PositionEnum_Param)
    m_Raw.AbsolutePage = RHS
End Property

Private Property Get IRecordset_AbsolutePage() As ADODB.PositionEnum_Param
    IRecordset_AbsolutePage = m_Raw.AbsolutePage
End Property

Private Property Let IRecordset_AbsolutePosition(ByVal RHS As ADODB.PositionEnum_Param)
    m_Raw.AbsolutePosition = RHS
End Property

Private Property Get IRecordset_AbsolutePosition() As ADODB.PositionEnum_Param
    IRecordset_AbsolutePosition = m_Raw.AbsolutePosition
End Property

Private Property Get IRecordset_ActiveCommand() As Object
    Set IRecordset_ActiveCommand = m_Raw.ActiveCommand
End Property

Private Property Set IRecordset_ActiveConnection(ByVal RHS As Object)
    Set m_Raw.ActiveConnection = RHS
End Property

Private Property Let IRecordset_ActiveConnection(ByVal RHS As Variant)
    LC.Assign m_Raw.ActiveConnection, RHS
End Property

Private Property Get IRecordset_ActiveConnection() As Variant
    Set IRecordset_ActiveConnection = m_Raw.ActiveConnection
End Property

Private Sub IRecordset_AddNew(Optional ByVal FieldList As Variant, Optional ByVal Values As Variant)
    m_Raw.AddNew FieldList, Values
End Sub

Private Property Get IRecordset_BOF() As Boolean
    IRecordset_BOF = m_Raw.EOF
End Property

Private Property Let IRecordset_Bookmark(ByVal RHS As Variant)
    LC.Assign m_Raw.Bookmark, RHS
End Property

Private Property Get IRecordset_Bookmark() As Variant
    LC.Assign IRecordset_Bookmark, m_Raw.Bookmark
End Property

Private Property Let IRecordset_CacheSize(ByVal RHS As Long)
    m_Raw.CacheSize = RHS
End Property

Private Property Get IRecordset_CacheSize() As Long
    IRecordset_CacheSize = m_Raw.CacheSize
End Property

Private Sub IRecordset_Cancel()
    m_Raw.Cancel
End Sub

Private Sub IRecordset_CancelBatch(Optional ByVal AffectRecords As ADODB.AffectEnum = 3&)
    m_Raw.CancelBatch AffectRecords
End Sub

Private Sub IRecordset_CancelUpdate()
    m_Raw.CancelUpdate
End Sub

Private Function IRecordset_Clone(Optional ByVal LockType As ADODB.LockTypeEnum = -1&) As ADODB.Recordset
    Set IRecordset_Clone = m_Raw.Clone(LockType)
End Function

Private Sub IRecordset_Close()
    m_Raw.Close
End Sub

Private Property Let IRecordset_Collect(ByVal Index As Variant, ByVal RHS As Variant)
    m_Raw.Collect(Index) = RHS
End Property

Private Property Get IRecordset_Collect(ByVal Index As Variant) As Variant
    IRecordset_Collect = m_Raw.Collect(Index)
End Property

Private Function IRecordset_CompareBookmarks(ByVal Bookmark1 As Variant, ByVal Bookmark2 As Variant) As ADODB.CompareEnum
    IRecordset_CompareBookmarks = m_Raw.CompareBookmarks(Bookmark1, Bookmark2)
End Function

Private Property Let IRecordset_CursorLocation(ByVal RHS As ADODB.CursorLocationEnum)
    m_Raw.CursorLocation = RHS
End Property

Private Property Get IRecordset_CursorLocation() As ADODB.CursorLocationEnum
    IRecordset_CursorLocation = m_Raw.CursorLocation
End Property

Private Property Let IRecordset_CursorType(ByVal RHS As ADODB.CursorTypeEnum)
    m_Raw.CursorType = RHS
End Property

Private Property Get IRecordset_CursorType() As ADODB.CursorTypeEnum
    IRecordset_CursorType = m_Raw.CursorType
End Property

Private Property Let IRecordset_DataMember(ByVal RHS As String)
    m_Raw.DataMember = RHS
End Property

Private Property Get IRecordset_DataMember() As String
    IRecordset_DataMember = m_Raw.DataMember
End Property

Private Property Set IRecordset_DataSource(ByVal RHS As Object)
    Set m_Raw.DataSource = RHS
End Property

Private Property Get IRecordset_DataSource() As Object
    Set IRecordset_DataSource = m_Raw.DataSource
End Property

Private Sub IRecordset_Delete(Optional ByVal AffectRecords As ADODB.AffectEnum = 1&)
    m_Raw.Delete AffectRecords
End Sub

Private Property Get IRecordset_EditMode() As ADODB.EditModeEnum
    IRecordset_EditMode = m_Raw.EditMode
End Property

Private Property Get IRecordset_EOF() As Boolean
    IRecordset_EOF = m_Raw.EOF
End Property

Private Property Get IRecordset_Fields() As ADODB.Fields
    Set IRecordset_Fields = m_Raw.Fields
End Property

Private Property Let IRecordset_Filter(ByVal RHS As Variant)
    m_Raw.Filter = RHS
End Property

Private Property Get IRecordset_Filter() As Variant
    LC.Assign IRecordset_Filter, m_Raw.Filter
End Property

Private Sub IRecordset_Find(ByVal Criteria As String, Optional ByVal SkipRecords As Long = 0&, Optional ByVal SearchDirection As ADODB.SearchDirectionEnum = 1&, Optional ByVal Start As Variant)
    m_Raw.Find Criteria, SkipRecords, SearchDirection, Start
End Sub

Private Function IRecordset_GetRows(Optional ByVal Rows As Long = -1&, Optional ByVal Start As Variant, Optional ByVal Fields As Variant) As Variant
    IRecordset_GetRows = m_Raw.GetRows(Rows, Start, Fields)
End Function

Private Function IRecordset_GetString(Optional ByVal StringFormat As ADODB.StringFormatEnum = 2&, Optional ByVal NumRows As Long = -1&, Optional ByVal ColumnDelimeter As String = "", Optional ByVal RowDelimeter As String = "", Optional ByVal NullExpr As String = "") As String
    IRecordset_GetString = m_Raw.GetString(StringFormat, NumRows, ColumnDelimeter, RowDelimeter, NullExpr)
End Function

Private Property Let IRecordset_Index(ByVal RHS As String)
    m_Raw.Index = RHS
End Property

Private Property Get IRecordset_Index() As String
    IRecordset_Index = m_Raw.Index
End Property

Private Property Let IRecordset_LockType(ByVal RHS As ADODB.LockTypeEnum)

End Property

Private Property Get IRecordset_LockType() As ADODB.LockTypeEnum
    IRecordset_LockType = m_Raw.LockType
End Property

Private Property Let IRecordset_MarshalOptions(ByVal RHS As ADODB.MarshalOptionsEnum)
    m_Raw.MarshalOptions = RHS
End Property

Private Property Get IRecordset_MarshalOptions() As ADODB.MarshalOptionsEnum
    IRecordset_MarshalOptions = m_Raw.MarshalOptions
End Property

Private Property Let IRecordset_MaxRecords(ByVal RHS As Long)
    m_Raw.MaxRecords = RHS
End Property

Private Property Get IRecordset_MaxRecords() As Long
    IRecordset_MaxRecords = m_Raw.MaxRecords
End Property

Private Sub IRecordset_Move(ByVal NumRecords As Long, Optional ByVal Start As Variant)
    m_Raw.Move NumRecords, Start
End Sub

Private Sub IRecordset_MoveFirst()
    m_Raw.MoveFirst
End Sub

Private Sub IRecordset_MoveLast()
    m_Raw.MoveLast
End Sub

Private Sub IRecordset_MoveNext()
    m_Raw.MoveNext
End Sub

Private Sub IRecordset_MovePrevious()
    m_Raw.MovePrevious
End Sub

Private Function IRecordset_NextRecordset(Optional RecordsAffected As Variant) As ADODB.Recordset
    Set IRecordset_NextRecordset = m_Raw.NextRecordset(RecordsAffected)
End Function

Private Sub IRecordset_Open(Optional ByVal Source As Variant, Optional ByVal ActiveConnection As Variant, Optional ByVal CursorType As ADODB.CursorTypeEnum = -1&, Optional ByVal LockType As ADODB.LockTypeEnum = -1&, Optional ByVal Options As Long = -1&)
    m_Raw.Open Source, ActiveConnection, CursorType, LockType, Options
End Sub

Private Property Get IRecordset_PageCount() As Long
    IRecordset_PageCount = m_Raw.PageCount
End Property

Private Property Let IRecordset_PageSize(ByVal RHS As Long)
    m_Raw.PageSize = RHS
End Property

Private Property Get IRecordset_PageSize() As Long
    IRecordset_PageSize = m_Raw.PageSize
End Property

Private Property Get IRecordset_Properties() As ADODB.Properties
    Set IRecordset_Properties = m_Raw.Properties
End Property

Private Property Get IRecordset_RecordCount() As Long
    IRecordset_RecordCount = m_Raw.RecordCount
End Property

Private Sub IRecordset_Requery(Optional ByVal Options As Long = -1&)
    m_Raw.Requery Options
End Sub

Private Sub IRecordset_Resync(Optional ByVal AffectRecords As ADODB.AffectEnum = 3&, Optional ByVal ResyncValues As ADODB.ResyncEnum = 2&)
    m_Raw.Resync AffectRecords, ResyncValues
End Sub

Private Sub IRecordset_Save(Optional ByVal Destination As Variant, Optional ByVal PersistFormat As ADODB.PersistFormatEnum = 0&)
    m_Raw.Save Destination, PersistFormat
End Sub

Private Sub IRecordset_Seek(ByVal KeyValues As Variant, Optional ByVal SeekOption As ADODB.SeekEnum = 1&)
    m_Raw.Seek KeyValues, SeekOption
End Sub

Private Property Let IRecordset_Sort(ByVal RHS As String)
    m_Raw.Sort = RHS
End Property

Private Property Get IRecordset_Sort() As String
    IRecordset_Sort = m_Raw.Sort
End Property

Private Property Set IRecordset_Source(RHS As Variant)

End Property

Private Property Let IRecordset_Source(ByVal RHS As Variant)

End Property

Private Property Get IRecordset_Source() As Variant
    IRecordset_Source = m_Raw.Source
End Property

Private Property Get IRecordset_State() As Long
    IRecordset_State = m_Raw.State
End Property

Private Property Get IRecordset_Status() As Long
    IRecordset_Status = m_Raw.Status
End Property

Private Property Let IRecordset_StayInSync(ByVal RHS As Boolean)
    m_Raw.StayInSync = RHS
End Property

Private Property Get IRecordset_StayInSync() As Boolean
    IRecordset_StayInSync = m_Raw.StayInSync
End Property

Private Function IRecordset_Supports(ByVal CursorOptions As ADODB.CursorOptionEnum) As Boolean
    IRecordset_Supports = m_Raw.Supports(CursorOptions)
End Function

Private Sub IRecordset_Update(Optional ByVal Fields As Variant, Optional ByVal Values As Variant)
    m_Raw.Update Fields, Values
End Sub

Private Sub IRecordset_UpdateBatch(Optional ByVal AffectRecords As ADODB.AffectEnum = 3&)
    m_Raw.UpdateBatch AffectRecords
End Sub

Private Function IRecordset_xxClone() As ADODB.Recordset
    m_Raw.[_xClone]
End Function

Private Sub IRecordset_xxResync(Optional ByVal AffectRecords As ADODB.AffectEnum = 3&)
    m_Raw.[_xResync] AffectRecords
End Sub

Private Sub IRecordset_xxSave(Optional ByVal FileName As String = "", Optional ByVal PersistFormat As ADODB.PersistFormatEnum = 0&)
    m_Raw.[_xSave] FileName, PersistFormat
End Sub

Private Sub m_Raw_EndOfRecordset(fMoreData As Boolean, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent EndOfRecordset(fMoreData, adStatus, pRecordset)
End Sub

Private Sub m_Raw_FetchComplete(ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent FetchComplete(pError, adStatus, pRecordset)
End Sub

Private Sub m_Raw_FetchProgress(ByVal Progress As Long, ByVal MaxProgress As Long, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent FetchProgress(Progress, MaxProgress, adStatus, pRecordset)
End Sub

Private Sub m_Raw_FieldChangeComplete(ByVal cFields As Long, ByVal Fields As Variant, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent FieldChangeComplete(cFields, Fields, pError, adStatus, pRecordset)
End Sub

Private Sub m_Raw_MoveComplete(ByVal adReason As ADODB.EventReasonEnum, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent MoveComplete(adReason, pError, adStatus, pRecordset)
End Sub

Private Sub m_Raw_RecordChangeComplete(ByVal adReason As ADODB.EventReasonEnum, ByVal cRecords As Long, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent RecordChangeComplete(adReason, cRecords, pError, adStatus, pRecordset)
End Sub

Private Sub m_Raw_RecordsetChangeComplete(ByVal adReason As ADODB.EventReasonEnum, ByVal pError As ADODB.Error, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent RecordsetChangeComplete(adReason, pError, adStatus, pRecordset)
End Sub

Private Sub m_Raw_WillChangeField(ByVal cFields As Long, ByVal Fields As Variant, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent WillChangeField(cFields, Fields, adStatus, pRecordset)
End Sub

Private Sub m_Raw_WillChangeRecord(ByVal adReason As ADODB.EventReasonEnum, ByVal cRecords As Long, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent WillChangeRecord(adReason, cRecords, adStatus, pRecordset)
End Sub

Private Sub m_Raw_WillChangeRecordset(ByVal adReason As ADODB.EventReasonEnum, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent WillChangeRecordset(adReason, adStatus, pRecordset)
End Sub

Private Sub m_Raw_WillMove(ByVal adReason As ADODB.EventReasonEnum, adStatus As ADODB.EventStatusEnum, ByVal pRecordset As ADODB.Recordset)
    RaiseEvent WillMove(adReason, adStatus, pRecordset)
End Sub
