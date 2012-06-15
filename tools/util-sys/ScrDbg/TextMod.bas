Attribute VB_Name = "modText"
Option Explicit
Option Base 0

Const RegKey = "Software\热带草原软件\编程\工具\脚本调试器\2.0"

Type ScriptVBA
    Collection As VBA.Collection
    ErrObject As VBA.ErrObject
End Type

Public Sub Main()
    Load ScriptForm
    Load frmAbout
    ScriptForm.initEnv
    readInitFiles
    ScriptForm.Show
End Sub

Public Function getp(textObj As TextBox, ByVal line As Long, ByVal column As Long) As Long
    Dim ls
    Dim i
    Dim HasCR As Boolean
    HasCR = True
    ls = Split(textObj.text, Chr(13) & Chr(10), , vbTextCompare)
    If UBound(ls) < 2 Then
        HasCR = False
        ls = Split(textObj.text, vbNewLine, , vbTextCompare)
    End If
    getp = 0
    If line > UBound(ls) Then line = UBound(ls) + 1
    line = line - 1 ' base 0
    For i = 0 To line - 1
        getp = getp + Len(ls(i)) + IIf(HasCR, 2, 1)
    Next
    getp = getp + column
    If getp < 0 Then getp = 0
    If getp > Len(textObj.text) Then getp = Len(textObj.text)
End Function

Public Function saveInitFiles(ByVal oneFile As String) As Boolean
    Dim result As Long

    saveInitFiles = True
    HKEY_SPECROOT = RegKey
    result = RegSetVal("启动文件", "", oneFile)
    If result <> 0 Then
        MsgBox "无法设置环境."
        saveInitFiles = False
    End If
End Function

Public Function readInitFiles() As Boolean
    Dim result
    Dim bufstr As String * 1024
    readInitFiles = True
    HKEY_SPECROOT = RegKey
    result = RegGetVal("启动文件", "", bufstr)
    If Not regErrored(result) Then ScriptForm.execScriptFile Trim(bufstr)
End Function
