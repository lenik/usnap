Attribute VB_Name = "Utilities"
Option Explicit

Public Function Quote(ByVal S As String) As String
    Quote = Replace(S, "\", "\\")
    Quote = Replace(S, " ", "\_")
End Function

' Todo:
'   Dequote(Quote("..\_..")) != "..\_.."
Public Function Dequote(ByVal S As String) As String
    Dequote = Replace(S, "\_", " ")
    Dequote = Replace(Dequote, "\\", "\")
End Function
