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
    DirName = GlobalsSingleton.DirName(Path)
End Function

Public Function BaseName(ByVal Path As String) As String
    BaseName = GlobalsSingleton.BaseName(Path)
End Function

Public Function MakeParents(ByVal Path As String) As Integer
    MakeParents = GlobalsSingleton.MakeParents(Path)
End Function

Public Function MakeDirectories(ByVal Path As String) As Integer
    MakeDirectories = GlobalsSingleton.MakeDirectories(Path)
End Function

Public Function BrowseForFolder(Optional ByVal Title As String, _
                                Optional ByVal hWndParent As Long = 0) As String
    BrowseForFolder = GlobalsSingleton.BrowseForFolder(Title, hWndParent)
End Function
