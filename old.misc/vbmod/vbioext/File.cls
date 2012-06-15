VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "File"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBIOExt::File"

Public Enum FileAccessConstants
    fileLogging
    fileConfigure
    fileRead
    fileWrite
    fileAppend
End Enum

Private m_fp As Long
Private m_bin As Boolean

Public Function Open_(ByVal Path As String, Optional ByVal BinaryMode As Boolean = False) As Boolean
    m_fp = CreateFile(Path, , , ByVal 0&, , , 0)
    Open_ = m_fp = INVALID_HANDLE_VALUE
End Function

Public Function Close_() As Long
    CloseHandle m_fp
    m_fp =
End Function

Private Sub Class_Initialize()
    m_fp = INVALID_HANDLE_VALUE
End Sub

Private Sub Class_Terminate()
    Close_
End Sub
