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
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

' get the embedded func<...> with parameters in "<..>"
Public RE_VAR As New RegExp

' test if any space or punctuation in the string
Public RE_OnlyWord As New RegExp

' if '(' and ')' surrounds the string
Public RE_InParenthesis As New RegExp

Private Sub Class_Initialize()
    RE_VAR.Global = True
    RE_VAR.IgnoreCase = False
    RE_VAR.MultiLine = False
    RE_VAR.Pattern = "(\$\w+)|(\$\{[^\}]+\})"

    RE_OnlyWord.Global = False
    RE_OnlyWord.IgnoreCase = False
    RE_OnlyWord.MultiLine = False
    RE_OnlyWord.Pattern = "^\w+$"

    RE_InParenthesis.Global = False
    RE_InParenthesis.IgnoreCase = True
    RE_InParenthesis.MultiLine = True
    RE_InParenthesis.Pattern = "^\(.*\)$"
End Sub
