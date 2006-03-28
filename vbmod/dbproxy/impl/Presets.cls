VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Presets"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const MAX_PRESETS               As Integer = 100

Private m_CursorTypes(0 To MAX_PRESETS) As CursorTypeEnum
Private m_LockTypes(0 To MAX_PRESETS) As LockTypeEnum

Public Property Get CursorType(ByVal QueryType As QueryTypeConstants) As CursorTypeEnum
    CursorType = m_CursorTypes(QueryType)
End Property

Public Property Get LockType(ByVal QueryType As QueryTypeConstants) As LockTypeEnum
    LockType = m_LockTypes(QueryType)
End Property

Private Sub Class_Initialize()
    m_CursorTypes(qtRead) = adOpenForwardOnly
    m_CursorTypes(qtEdit) = adOpenForwardOnly
    m_CursorTypes(qtForEach) = adOpenForwardOnly
    m_CursorTypes(qtBrowse) = adOpenKeyset
    m_CursorTypes(qtBrowseAndEdit) = adOpenKeyset
    m_CursorTypes(qtSnapshot) = adOpenStatic
    m_CursorTypes(qtDirectAccess) = adOpenDynamic
    m_CursorTypes(qtStatistics) = adOpenKeyset
    m_CursorTypes(qtUpdateRedundants) = adOpenForwardOnly
    m_CursorTypes(qtBatchUpdate) = adOpenForwardOnly
    m_CursorTypes(qtBatchUpdateBi) = adOpenKeyset

    m_LockTypes(qtRead) = adLockReadOnly
    m_LockTypes(qtEdit) = adLockPessimistic
    m_LockTypes(qtForEach) = adLockReadOnly
    m_LockTypes(qtBrowse) = adLockReadOnly
    m_LockTypes(qtBrowseAndEdit) = adLockPessimistic
    m_LockTypes(qtSnapshot) = adLockReadOnly
    m_LockTypes(qtDirectAccess) = adLockOptimistic
    m_LockTypes(qtStatistics) = adLockReadOnly
    m_LockTypes(qtUpdateRedundants) = adLockOptimistic
    m_LockTypes(qtBatchUpdate) = adLockBatchOptimistic
    m_LockTypes(qtBatchUpdateBi) = adLockBatchOptimistic
End Sub
