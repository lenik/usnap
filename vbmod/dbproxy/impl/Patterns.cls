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

' get name of table/view
Private RE_SubjectInSQL As New RegExp

' get the embedded func<...> with parameters in "<..>"
Public RE_QSQL As New RegExp

' test if any space or punctuation in the string
Public RE_OnlyWord As New RegExp

' if '(' and ')' surrounds the string
Public RE_InParenthesis As New RegExp

Private Sub Class_Initialize()
    RE_SubjectInSQL.IgnoreCase = True
    RE_SubjectInSQL.MultiLine = False
    RE_SubjectInSQL.Pattern = "\bselect\s+.*?\s+from\s+(\w+|(`.*?`)|(\[.*\]))"

    RE_QSQL.Global = True
    RE_QSQL.IgnoreCase = False
    RE_QSQL.MultiLine = False
    RE_QSQL.Pattern = "(\?\w+<[^<>]*?>)|(\$\w+)"

    RE_OnlyWord.Global = False
    RE_OnlyWord.IgnoreCase = False
    RE_OnlyWord.MultiLine = False
    RE_OnlyWord.Pattern = "^\w+$"

    RE_InParenthesis.Global = False
    RE_InParenthesis.IgnoreCase = True
    RE_InParenthesis.MultiLine = True
    RE_InParenthesis.Pattern = "^\(.*\)$"
End Sub

Public Function GetSubject(ByVal SQL As String) As String
    Dim matches As MatchCollection
    Set matches = RE_SubjectInSQL.Execute(SQL)
    If matches.Count > 0 Then
        Dim subs As SubMatches
        Set subs = matches(0).SubMatches
        GetSubject = subs(0)
    End If
End Function
