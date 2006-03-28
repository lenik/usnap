VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Patterns"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public SubjectInSQL As New RegExp

Private Sub Class_Initialize()
    SubjectInSQL.IgnoreCase = True
    SubjectInSQL.MultiLine = False
    SubjectInSQL.Pattern = "\bselect\s+.*?\s+from\s+(\w+|(`.*?`)|(\[.*\]))"
End Sub

Public Function GetSubject(ByVal SQL As String) As String
    Dim matches As MatchCollection
    Set matches = SubjectInSQL.Execute(SQL)
    If matches.Count > 0 Then
        Dim subs As SubMatches
        Set subs = matches(0).SubMatches
        GetSubject = subs(0)
    End If
End Function
