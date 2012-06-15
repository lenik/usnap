Attribute VB_Name = "modFingerRegister"
Option Explicit

Declare Function Register Lib "Register" (ByVal id As String, ByVal regid As String) As Boolean
Declare Function RegisterVal Lib "Register" (ByVal id As String) As Long

Public Function GetRegisterVal(ByVal id As String) As String
        GetRegisterVal = lt_s.saveAscizString(RegisterVal(id), False)
End Function
