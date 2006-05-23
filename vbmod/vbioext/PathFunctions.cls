VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "PathFunctions"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function DirName(ByVal Path As String) As String
    Dim pos As Integer
    pos = Max(InStrRev(Path, "\"), InStrRev(Path, "/"))

    If pos > 0 Then
        DirName = Left(Path, pos - 1)
    Else
        DirName = "."
    End If
End Function

Public Function BaseName(ByVal Path As String) As String
    Dim pos As Integer
    pos = Max(InStrRev(Path, "\"), InStrRev(Path, "/"))

    If pos > 0 Then
        BaseName = Mid(Path, pos + 1)
    Else
        BaseName = Path
    End If
End Function

Public Function MakeParents(ByVal Path As String) As Integer
    Dim i As Integer
    Dim Folder As String
    Dim Makes As Integer
    Dim Fails As Integer
    i = 0
    Do
        i = InStr(i + 1, Path, "\")
        If i <= 0 Then Exit Do
        Folder = Left(Path, i - 1)
        If Folder <> "" And Not FSO.FolderExists(Folder) Then
            On Error Resume Next
                FSO.CreateFolder Folder
            On Error GoTo 0
            If FSO.FolderExists(Folder) Then
                Makes = Makes + 1
            Else
                Fails = Fails + 1
            End If
        End If
    Loop

    If Makes = 0 And Fails > 0 Then
        MakeParents = -1
    Else
        MakeParents = Makes
    End If
End Function

Public Function MakeDirectories(ByVal Path As String) As Integer
    If Right(Path, 1) <> "\" Then
        Path = Path & "\"
    End If
    MakeDirectories = MakeParents(Path)
End Function
