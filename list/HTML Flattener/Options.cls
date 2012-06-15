VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Options"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False


Public OutSameDir As Boolean
Public OutDir As String              ' if not OutSameDir

Public NameDefault As Boolean
Public NameSrc As String           ' if not default, reg-ex src
Public NameDst As String           ' if not default, reg-ex dst

Public Backup As Boolean

Public IncludeTitle As Boolean
Public ScreenWidth As Integer
Public TitleAlignment As AlignmentConstants
Public TitleFormat As String

Public Variables As New Collection



Public Function GetOutputPath(srcPath As String) As String

End Function


Public Sub PrepareWrite(dstPath As String)

End Sub


Public Function VariableExpand(script As String) As String


End Function
