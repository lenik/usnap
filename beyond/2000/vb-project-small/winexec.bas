Attribute VB_Name = "Module1"

Declare Function WinExec Lib "kernel32" (ByVal cmdline As String, ByVal nCmdShow As Long) As Long


Function What()
    What = "HAHAHA"
End Function
