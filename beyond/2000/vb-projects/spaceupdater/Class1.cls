VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "DiskSpace"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit


' 根据制定path更新空间描述cache。在每个文件夹下建立 _info.ini
' _info.ini不计入空间描述，但计入目录本身的空间描述。
Public Function UpdateSpace(path) As Boolean
        Dim fso As New FileSystemObject

        UpdateSpace = False
        If fso.FolderExists(path) Then
                Dim fo As Folder
                Set fo = fso.GetFolder(path)
                UpdateSpace = UpdateFolder(fo, -1)
        End If
End Function

Public Function UpdateFolder(d, ByVal nest As Long) As Double
        UpdateFolder = True

        Dim sf As File, sd As Folder
        Dim tot As Double, dtot As Double

        For Each sf In d.Files
                If LCase(sf.Name) <> "_dirinfo.ini" Then
                        tot = tot + sf.Size
                Else
                        dtot = sf.Size
                End If
        Next

        If nest <> 0 Then
                For Each sd In d.SubFolders
                        tot = tot + UpdateFolder(sd, nest - 1)
                Next
        End If

        dtot = dtot + tot
        UpdateFolder = dtot
End Function
