Attribute VB_Name = "Presets"
Option Explicit

Private Const MAX_PRESETS               As Integer = 100

Public g_CursorTypes(0 To MAX_PRESETS) As CursorTypeEnum
Public g_LockTypes(0 To MAX_PRESETS) As LockTypeEnum

Private m_Initialized As Boolean

Public Sub Initialize()
    If m_Initialized Then Exit Sub

    g_CursorTypes(qtRead) = adOpenForwardOnly
    g_CursorTypes(qtEdit) = adOpenForwardOnly
    g_CursorTypes(qtForEach) = adOpenForwardOnly
    g_CursorTypes(qtBrowse) = adOpenKeyset
    g_CursorTypes(qtBrowseAndEdit) = adOpenKeyset
    g_CursorTypes(qtSnapshot) = adOpenStatic
    g_CursorTypes(qtDirectAccess) = adOpenDynamic
    g_CursorTypes(qtStatistics) = adOpenKeyset
    g_CursorTypes(qtUpdateRedundants) = adOpenForwardOnly
    g_CursorTypes(qtBatchUpdate) = adOpenForwardOnly
    g_CursorTypes(qtBatchUpdateBi) = adOpenKeyset

    g_LockTypes(qtRead) = adLockReadOnly
    g_LockTypes(qtEdit) = adLockPessimistic
    g_LockTypes(qtForEach) = adLockReadOnly
    g_LockTypes(qtBrowse) = adLockReadOnly
    g_LockTypes(qtBrowseAndEdit) = adLockPessimistic
    g_LockTypes(qtSnapshot) = adLockReadOnly
    g_LockTypes(qtDirectAccess) = adLockOptimistic
    g_LockTypes(qtStatistics) = adLockReadOnly
    g_LockTypes(qtUpdateRedundants) = adLockOptimistic
    g_LockTypes(qtBatchUpdate) = adLockBatchOptimistic
    g_LockTypes(qtBatchUpdateBi) = adLockBatchOptimistic
End Sub
