VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "PutFile"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "NetTools::PutFile"

Public RemoteName As String

Public Category As String

Public HashCode As String

Public IsEncrypted As Boolean

Public Done As Boolean

Private m_LocalPath As String
Private m_DeleteLocalAfterDone As Boolean

Public Property Get LocalPath() As String
    LocalPath = m_LocalPath
End Property

Public Property Let LocalPath(ByVal newval As String)
    m_LocalPath = newval
    m_DeleteLocalAfterDone = False
End Property

Public Sub SetTemporaryPath(Optional ByVal ManuallySpecifiedTempPath As String)
    If ManuallySpecifiedTempPath <> "" Then
        m_LocalPath = ManuallySpecifiedTempPath
    Else
        m_LocalPath = Application.TemporaryPath
    End If
End Sub

Public Property Get Size() As Long
    Size = FSO.GetFile(LocalPath).Size
End Property

Friend Sub UpdateHashCode()
    If FSO.FileExists(m_LocalPath) Then
        HashCode = FileHash(m_LocalPath)
    Else
        HashCode = ""
    End If
End Sub

Private Sub Class_Terminate()
    If m_DeleteLocalAfterDone Then
        FSO.DeleteFile LocalPath, True
    End If
End Sub
