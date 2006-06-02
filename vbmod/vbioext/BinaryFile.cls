VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BinaryFile"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBIOExt::BinaryFile"

Public Enum AccessModeConstants
    amRead = 0
    amEdit                              ' Read/Write, Create if not exist
    amCreate                            ' Write, Create always
    amWrite                             ' Write, Create if not exist
    amAppend
End Enum

Public Enum PositionRelativeConstants
    prBegin = 0                         ' FILE_BEGIN
    prCurrent = 1                       ' FILE_CURRENT
    prEnd = 2                           ' FILE_END
End Enum

Private m_Handle As Long
Private m_FileName As String
Private m_AccessMode As AccessModeConstants
Private m_LastErrorNum As Long
Private m_LastError As String
Private m_FileInfo As BY_HANDLE_FILE_INFORMATION

Private Declare Function CreateFile Lib "kernel32" Alias "CreateFileA" ( _
        ByVal lpFileName As String, ByVal dwDesiredAccess As Long, _
        ByVal dwShareMode As Long, ByVal lpSecurityAttributes As Long, _
        ByVal dwCreateDisposition As Long, ByVal dwFlagsAndAttributes As Long, _
        ByVal hTemplateFile As Long) As Long

Private Declare Function CloseHandle Lib "kernel32" (ByVal hObject As Long) As Boolean

Private Declare Function GetLastError Lib "kernel32" () As Long

Private Declare Function ReadFile Lib "kernel32" ( _
        ByVal hFile As Long, ByVal lpBuffer As Long, _
        ByVal nNumberOfBytesToRead As Long, ByRef lpNumberOfBytesRead As Long, _
        ByVal lpOverlapped As Long) As Boolean

Private Declare Function ReadFileS Lib "kernel32" Alias "ReadFile" ( _
        ByVal hFile As Long, ByVal lpBuffer As String, _
        ByVal nNumberOfBytesToRead As Long, ByRef lpNumberOfBytesRead As Long, _
        ByVal lpOverlapped As Long) As Boolean

Private Declare Function WriteFile Lib "kernel32" ( _
        ByVal hFile As Long, ByVal lpBuffer As Long, _
        ByVal nNumberOfBytesToWrite As Long, ByRef lpNumberOfBytesWritten As Long, _
        ByVal lpOverlapped As Long) As Boolean

Private Declare Function WriteFileS Lib "kernel32" Alias "WriteFile" ( _
        ByVal hFile As Long, ByVal lpBuffer As String, _
        ByVal nNumberOfBytesToWrite As Long, ByRef lpNumberOfBytesWritten As Long, _
        ByVal lpOverlapped As Long) As Boolean

Public Property Get FileName() As String
    FileName = m_FileName
End Property

Public Property Let FileName(ByVal newval As String)
    If IsOpened Then
        If MoveFile(m_FileName, newval) Then
            m_FileName = newval
        Else
            ' Cannot rename file when opened
            Err.Raise -1, , "Cannot rename file " & m_FileName & " to " & newval
        End If
    Else
        m_FileName = newval
    End If
End Property

Public Property Get LastError() As String
    If m_LastError = "" Then
        m_LastError = GetErrorString(m_LastErrorNum)
    End If
    LastError = m_LastError
End Property

Private Property Let LastErrorNum(ByVal newval As Long)
    If m_LastErrorNum <> newval Then
        m_LastErrorNum = newval
        m_LastError = ""
    End If
End Property

Public Property Get CurrentPosition() As Long
    Assert_IsOpened
    Dim l As Long
    Dim DistHigh As Long                ' Must be 0
    l = SetFilePointer(m_Handle, 0, DistHigh, FILE_CURRENT)
    If l = -1 Then LastErrorNum = GetLastError
    CurrentPosition = l
End Property

Public Function SetCurrentPosition(ByVal Position As Long, _
                                   Optional ByVal Relative As PositionRelativeConstants = 0) As Boolean
    Assert_IsOpened
    Dim l As Long
    Dim DistHigh As Long                ' Must be 0
    l = SetFilePointer(m_Handle, Position, DistHigh, Relative)
    If l = -1 Then LastErrorNum = GetLastError
    SetCurrentPosition = l <> -1
End Function

' Returns -1 if fails
Public Property Get Size() As Long
    Assert_IsOpened
    Dim SizeHigh As Long
    Size = GetFileSize(m_Handle, SizeHigh)
    If Size = INVALID_FILE_SIZE Then LastErrorNum = GetLastError
End Property

Public Property Let Size(ByVal NewSize As Long)
    Dim AutoOpen As Boolean
    AutoOpen = Not IsOpened
    If AutoOpen Then Open_ m_FileName, amEdit
    'Assert_IsOpened

    Dim l As Long
    If SetCurrentPosition(NewSize) Then
        l = SetEndOfFile(m_Handle)
        If l = 0 Then LastErrorNum = GetLastError
    End If

    If AutoOpen Then Close_
End Property

Public Function RefreshFileInfo() As Boolean
    Assert_IsOpened
    RefreshFileInfo = GetFileInformationByHandle(m_Handle, m_FileInfo)
    If Not RefreshFileInfo Then LastErrorNum = GetLastError
End Function

Private Function AutoRefreshFileInfo() As Boolean
    AutoRefreshFileInfo = RefreshFileInfo
End Function

Public Property Get Attributes() As Long
    Assert_IsOpened
    AutoRefreshFileInfo
    Attributes = m_FileInfo.dwFileAttributes
End Property

Public Property Get CreationTime() As Date
    Assert_IsOpened
    AutoRefreshFileInfo
    CreationTime = m_FileInfo.ftCreationTime
End Property

Public Property Get LastAccessTime() As Date
    Assert_IsOpened
    LastAccessTime = m_FileInfo.ftLastAccessTime
End Property

Public Property Get LastWriteTime() As Date
    Assert_IsOpened
    LastWriteTime = m_FileInfo.ftLastWriteTime
End Property

Public Property Get FileSize() As Long
    Assert_IsOpened
    FileSize = m_FileInfo.nFileSizeLow
End Property

Public Property Get IsOpened() As Boolean
    IsOpened = m_Handle <> INVALID_HANDLE_VALUE
End Property

Private Sub Assert_IsOpened()
    Assert m_Handle <> INVALID_HANDLE_VALUE, _
           "File " & m_FileName & " hasn't been opened, yet", LOCATION
End Sub

Public Function Open_(Optional ByVal FileName, _
                      Optional ByVal AccessMode As AccessModeConstants = 0) As Boolean
    ' If IsOpened Then Close_
    Assert Not IsOpened, "File " & m_FileName & " hasn't been closed, yet", LOCATION

    Dim DesiredAccess As Long
    Dim ShareMode As Long
    Dim CreateDisposition As Long
    Dim FileFlags As Long
    DesiredAccess = AM2CFDA(AccessMode)
    ShareMode = AM2CFSM(AccessMode)
    CreateDisposition = AM2CFCD(AccessMode)
    FileFlags = AM2CFFF(AccessMode)

    If IsMissing(FileName) Then FileName = m_FileName

    Dim h As Long
    h = CreateFile(FileName, DesiredAccess, ShareMode, 0, CreateDisposition, _
                   FileFlags, 0)
    If h = INVALID_HANDLE_VALUE Then
        LastErrorNum = GetLastError
        Exit Function
    End If

    m_Handle = h
    m_FileName = FileName
    m_AccessMode = AccessMode

    If AccessMode = amAppend Then
        SetCurrentPosition 0, prEnd
    End If

    Open_ = True
End Function

Public Function Close_() As Boolean
    Assert_IsOpened
    ' If m_Handle = INVALID_HANDLE_VALUE Then Exit Function

    Close_ = CloseHandle(m_Handle)
    If Close_ Then
        m_Handle = INVALID_HANDLE_VALUE
    Else
        LastErrorNum = GetLastError
    End If
End Function

Public Function Read(ByVal Size As Long) As Byte()
    ReDim Buffer(0 To Size - 1) As Byte
    Dim cbRead As Long
    Dim b As Boolean
    'b = ReadFile(m_Handle, Buffer, Size, cbRead, Null)
    If b Then
        Read = Buffer
    End If
End Function

Public Function ReadString(ByVal AsciiChars As Long) As String
    ReadString = BU.BytesToString(Read(AsciiChars))
End Function

Public Function ReadStringB(ByVal UnicodeChars As Long) As String
    ReadStringB = BU.BytesToStringB(Read(UnicodeChars * 2))
End Function

Public Function Write_(ByRef vaBytes, Optional ByVal Size As Long = -1) As Boolean
    Dim Bytes() As Byte
    Dim cbWritten As Long
    Bytes = vaBytes
    If Size = -1 Then Size = BU.ArraySize(Bytes)
    Write_ = WriteFile(m_Handle, LP.pByte(Bytes(0)), Size, cbWritten, 0)
    If Not Write_ Then LastErrorNum = GetLastError
End Function

Public Function WriteString(ByVal s As String, _
                            Optional ByVal AsciiChars As Long = -1) As Boolean
    Dim cbWritten As Long
    If AsciiChars = -1 Then AsciiChars = Len(StringToHex(s)) / 2
    WriteString = WriteFileS(m_Handle, s, AsciiChars, cbWritten, 0)
    If Not WriteString Then LastErrorNum = GetLastError
End Function

Public Function WriteStringB(ByVal s As String, _
                             Optional ByVal UnicodeChars As Long = -1) As Boolean
    Dim sp As Long
    sp = StrPtr(s)
    Dim cbWritten As Long
    If UnicodeChars = -1 Then UnicodeChars = Len(s)
    WriteStringB = WriteFile(m_Handle, sp, UnicodeChars * 2, cbWritten, 0)
    If Not WriteStringB Then LastErrorNum = GetLastError
End Function

Public Function Touch() As Boolean
    Dim AutoOpen As Boolean
    AutoOpen = Not IsOpened
    If AutoOpen Then Open_ m_FileName, amEdit

    Touch = WriteFile(m_Handle, Null, 0, Null, Null)
    If Not Touch Then LastErrorNum = GetLastError

    If AutoOpen Then Close_
End Function

' Convert AccessModeConstants to CreateFile/DesiredAccess
Private Function AM2CFDA(ByVal am As AccessModeConstants) As Long
    Select Case am
    Case amRead
        AM2CFDA = GENERIC_READ
    Case amEdit
        AM2CFDA = GENERIC_READ Or GENERIC_WRITE
    Case amCreate
        AM2CFDA = GENERIC_WRITE
    Case amWrite
        AM2CFDA = GENERIC_WRITE
    Case amAppend
        AM2CFDA = GENERIC_WRITE
    End Select
End Function

Private Function AM2CFSM(ByVal am As AccessModeConstants) As Long
    Select Case am
    Case amRead
        AM2CFSM = FILE_SHARE_WRITE
    Case amEdit
        AM2CFSM = 0
    Case amCreate
        AM2CFSM = FILE_SHARE_READ
    Case amWrite
        AM2CFSM = FILE_SHARE_READ
    Case amAppend
        AM2CFSM = FILE_SHARE_READ
    End Select
End Function

Private Function AM2CFCD(ByVal am As AccessModeConstants) As Long
    Select Case am
    Case amRead
        AM2CFCD = OPEN_EXISTING
    Case amEdit
        AM2CFCD = OPEN_ALWAYS
    Case amCreate
        AM2CFCD = CREATE_ALWAYS
    Case amWrite
        AM2CFCD = OPEN_ALWAYS
    Case amAppend
        AM2CFCD = OPEN_ALWAYS
    End Select
End Function

Private Function AM2CFFF(ByVal am As AccessModeConstants) As Long
    Select Case am
    Case amEdit
        AM2CFFF = FILE_ATTRIBUTE_NORMAL
    Case amCreate
        AM2CFFF = FILE_ATTRIBUTE_NORMAL
    Case amWrite
        AM2CFFF = FILE_ATTRIBUTE_NORMAL
    'case amWriteThrough
    '    AM2CFFF = FILE_ATTRIBUTE_NORMAL Or FILE_FLAG_WRITE_THROUGH
    Case amAppend
        AM2CFFF = FILE_ATTRIBUTE_NORMAL
    End Select
End Function

Private Sub Class_Initialize()
    m_Handle = INVALID_HANDLE_VALUE
End Sub

Private Sub Class_Terminate()
    If IsOpened Then Close_
End Sub
