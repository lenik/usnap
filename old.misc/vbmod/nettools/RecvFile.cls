VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "RecvFile"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Public TrID As Long
Public ReqHashCode As String
Public ReqFileSize As Long

Public RemoteName As String
Public Category As String
Public IsEncrypted As Boolean

Private m_LocalPath As String
Public HashCode As String

Private m_CurrentSize As Long

Public Property Get LocalPath() As String
    LocalPath = m_LocalPath
End Property

Public Property Let LocalPath(ByVal newval As String)
    m_LocalPath = newval
    ' m_DeleteLocalAfterDone = False
End Property

Public Property Get CurrentSize() As Long
    CurrentSize = m_CurrentSize
End Property

' Rejects redundant bytes
Public Function Append(ByRef Bytes() As Byte)
    Dim Size As Long
    Size = ArraySize(Bytes)

    If ReqFileSize > 0 Then
        Assert m_CurrentSize <= ReqFileSize
        If m_CurrentSize + Size > ReqFileSize Then
            Size = ReqFileSize - m_CurrentSize
            Bytes = LeftBytes(Bytes, Size)
            Append = MidBytes(Bytes, Size)
        End If
    End If

    Dim f As New BinaryFile
    If f.Open_(m_LocalPath, amAppend) Then
        f.Write_ Bytes
        f.Close_
        m_CurrentSize = m_CurrentSize + Size
    End If

'    Dim f As Integer
'    f = FreeFile
'    Open m_LocalPath For Binary As #f
'
'    Dim raw As String
'    raw = BytesToString(Bytes)  'StrConv(Bytes, vbFromUnicode)
'
'    Put #f, , raw
'    m_CurrentSize = m_CurrentSize + Size
'    Close #f
End Function

Public Function EOF() As Boolean
    EOF = m_CurrentSize = ReqFileSize
End Function

Public Sub SetTemporaryPath(Optional ByVal ManuallySpecifiedTempPath As String)
    If ManuallySpecifiedTempPath <> "" Then
        m_LocalPath = ManuallySpecifiedTempPath
    Else
        m_LocalPath = Application.TemporaryPath
    End If
End Sub

Friend Sub UpdateHashCode()
    If FSO.FileExists(m_LocalPath) Then
        HashCode = FileHash(m_LocalPath)
    Else
        HashCode = ""
    End If
End Sub
