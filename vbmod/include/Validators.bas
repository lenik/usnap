Attribute VB_Name = "Validators"
Option Explicit

Public Sub ValidatePort(ByVal txtPort As String, Cancel As Boolean)
    Cancel = True
    If Not IsNumeric(txtPort) Then
        MsgBox "�˿ڱ���Ϊ����", vbExclamation
        Exit Sub
    End If

    Dim Port
    Port = Val(txtPort)
    If Int(Port) <> Port Or Port < 1 Or Port > 10000 Then
        MsgBox "�˿ڱ���Ϊ 1-9999 ֮�������", vbExclamation
        Exit Sub
    End If

    Cancel = False
End Sub
