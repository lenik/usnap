Attribute VB_Name = "Validators"
Option Explicit

Public Sub ValidatePort(ByVal txtPort As String, Cancel As Boolean)
    Cancel = True
    If Not IsNumeric(txtPort) Then
        MsgBox "端口必须为数字", vbExclamation
        Exit Sub
    End If

    Dim Port
    Port = Val(txtPort)
    If Int(Port) <> Port Or Port < 1 Or Port > 10000 Then
        MsgBox "端口必须为 1-9999 之间的整性", vbExclamation
        Exit Sub
    End If

    Cancel = False
End Sub
