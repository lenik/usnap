VERSION 5.00
Object = "{0E59F1D2-1FBE-11D0-8FF2-00A0D10038BC}#1.0#0"; "msscript.ocx"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form ScriptForm
   Caption         =   "Script调试器 2.00"
   ClientHeight    =   2310
   ClientLeft      =   165
   ClientTop       =   450
   ClientWidth     =   3885
   Icon            =   "ScriptForm.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   2310
   ScaleWidth      =   3885
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer scriptTimer
      Left            =   1920
      Top             =   1440
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   2400
      Top             =   1440
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
      DefaultExt      =   "js"
      DialogTitle     =   "打开/保存脚本文件"
      Filter          =   "VBScript Files|*.vbs|JavaScript files|*.js|Basic Sources|*.bas|Java Sources|*.java"
      Flags           =   1
      FontName        =   "宋体"
      FontSize        =   9
   End
   Begin MSScriptControlCtl.ScriptControl TheScript
      Left            =   2880
      Top             =   1440
      _ExtentX        =   1005
      _ExtentY        =   1005
      AllowUI         =   -1  'True
   End
   Begin VB.TextBox ScriptText
      Appearance      =   0  'Flat
      BackColor       =   &H8000000F&
      BorderStyle     =   0  'None
      Height          =   2295
      Left            =   0
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   0
      Width           =   3855
   End
   Begin VB.Menu mScript
      Caption         =   "&S脚本"
      Begin VB.Menu mmNew
         Caption         =   "&N新脚本"
         Shortcut        =   ^N
      End
      Begin VB.Menu mmSS
         Caption         =   "-"
      End
      Begin VB.Menu mmOpen
         Caption         =   "&O打开脚本"
         Shortcut        =   ^O
      End
      Begin VB.Menu mmSave
         Caption         =   "&S保存脚本"
         Shortcut        =   ^S
      End
      Begin VB.Menu mmSaveAs
         Caption         =   "&A另存脚本"
         Shortcut        =   ^W
      End
      Begin VB.Menu mmExit
         Caption         =   "&X退出"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu mDebug
      Caption         =   "&D调试"
      Begin VB.Menu mmRun
         Caption         =   "&R运行脚本"
         Shortcut        =   +{F5}
      End
      Begin VB.Menu mmStep
         Caption         =   "&T单步"
         Shortcut        =   {F8}
         Visible         =   0   'False
      End
      Begin VB.Menu mmTrace
         Caption         =   "&T跟踪"
         Shortcut        =   {F7}
         Visible         =   0   'False
      End
      Begin VB.Menu mmSD
         Caption         =   "-"
      End
      Begin VB.Menu mmVBScript
         Caption         =   "V&BScript"
         Checked         =   -1  'True
         Shortcut        =   ^V
      End
      Begin VB.Menu mmJavaScript
         Caption         =   "&JavaScript"
         Shortcut        =   ^J
      End
   End
   Begin VB.Menu mEnv
      Caption         =   "&V环境"
      Begin VB.Menu mmFont
         Caption         =   "&F设置字体"
         Shortcut        =   ^F
      End
      Begin VB.Menu mmColor
         Caption         =   "&C设置文字颜色"
         Shortcut        =   ^T
      End
      Begin VB.Menu mmColorBack
         Caption         =   "&G设置背景颜色"
         Shortcut        =   ^B
      End
      Begin VB.Menu mmSE
         Caption         =   "-"
      End
   End
   Begin VB.Menu mHelp
      Caption         =   "&H帮助"
      Begin VB.Menu mmAbout
         Caption         =   "&A关于"
      End
      Begin VB.Menu mmSH
         Caption         =   "-"
      End
      Begin VB.Menu mmInitFiles
         Caption         =   "&I设置启动文件"
      End
   End
End
Attribute VB_Name = "ScriptForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public bModified As Boolean
Public scrFileName As String

Public scriptToolA As New ActiveVBTool.ClassA
Public scriptToolB As New ActiveVBTool.ClassB

Private Function IsSpecified(ByVal s As String) As Boolean
    IsSpecified = Len(Trim(s)) <> 0
End Function

Private Sub initScript()
On Error Resume Next

    TheScript.AddObject "TheScript", TheScript

    TheScript.AddObject "ScriptScreen", VB.Screen
    TheScript.AddObject "ScriptPrinter", VB.Printer
    TheScript.AddObject "ScriptClip", Clipboard

    TheScript.AddObject "ScriptAbout", frmAbout

    TheScript.AddObject "ScriptForm", ScriptForm
    TheScript.AddObject "ScriptText", ScriptText
    TheScript.AddObject "ScriptTimer", scriptTimer
    TheScript.AddObject "ScriptCD", cd

    TheScript.AddObject "ScriptToolA", scriptToolA
    TheScript.AddObject "ScriptToolB", scriptToolB
End Sub

Private Sub newScript()
    ScriptText = ""
    scrFileName = ""
    bModified = False
End Sub

Private Sub openScript(openFile)
    Dim fn, ln, t, fileOpened
    On Error GoTo perr
    fn = FreeFile
    Open openFile For Input As #fn
    fileOpened = True
    While Not EOF(fn)
        Line Input #fn, ln
        t = t & ln & vbNewLine
    Wend
    Close #fn
    ScriptText = t
    scrFileName = openFile
    bModified = False
    Exit Sub
perr:
    If fileOpened Then Close #fn
    MsgBox "读取文件时发生了错误. 操作被取消"
End Sub

Private Sub saveScript(saveFile)
    Dim fn, fileOpened
    On Error GoTo perr
    fn = FreeFile
    Open saveFile For Output As #fn
    fileOpened = True
    Print #fn, ScriptText.text
    Close #fn
    scrFileName = saveFile
    bModified = False
    Exit Sub
perr:
    If fileOpened Then Close #fn
    MsgBox "写文件十分生了错误, 操作被取消"
End Sub

Public Sub execScriptFile(scriptFile)
    Dim fn, ln, t, fileOpened
    On Error GoTo perr
    fn = FreeFile
    Open scriptFile For Input As #fn
    fileOpened = True
    While Not EOF(fn)
        Line Input #fn, ln
        t = t & ln & vbNewLine
    Wend
    Close #fn
    TheScript.ExecuteStatement t
    Exit Sub
perr:
    If fileOpened Then Close #fn
End Sub

Private Sub Form_GotFocus()
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_GotFocus") Then TheScript.ExecuteStatement "ScriptForm_GotFocus"
End Sub

Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_KeyDown") Then TheScript.ExecuteStatement "ScriptForm_KeyDown " & KeyCode & ", " & Shift
End Sub

Private Sub Form_KeyPress(KeyAscii As Integer)
On Error Resume Next
    ScriptText_KeyPress KeyAscii
End Sub

Private Sub Form_KeyUp(KeyCode As Integer, Shift As Integer)
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_KeyUp") Then
        TheScript.ExecuteStatement "ScriptForm_KeyUp " & KeyCode & ", " & Shift
    End If
End Sub

Private Sub Form_Click()
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_Click") Then
        TheScript.ExecuteStatement "ScriptForm_Click"
    End If
End Sub

Private Sub Form_DblClick()
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_DblClick") Then
        TheScript.ExecuteStatement "ScriptForm_DblClick"
    End If
End Sub

Public Sub initEnv()
    initScript
    bModified = False
    scrFileName = ""
End Sub

Private Sub Form_LostFocus()
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_LostFocus") Then TheScript.ExecuteStatement "ScriptForm_LostFocus"
End Sub

Private Sub Form_MouseDown(Button As Integer, Shift As Integer, x As Single, Y As Single)
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_MouseDown") Then TheScript.ExecuteStatement "ScriptForm_MouseDown " & Button & ", " & Shift & ", " & x & ", " & Y
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, x As Single, Y As Single)
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_MouseMove") Then TheScript.ExecuteStatement "ScriptForm_MouseMove " & Button & ", " & Shift & ", " & x & ", " & Y
End Sub

Private Sub Form_MouseUp(Button As Integer, Shift As Integer, x As Single, Y As Single)
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_MouseUp") Then TheScript.ExecuteStatement "ScriptForm_MouseUp " & Button & ", " & Shift & ", " & x & ", " & Y
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
On Error Resume Next
    If True = TheScript.Eval("Call_Form_QueryUnload") Then TheScript.ExecuteStatement "Form_QueryUnload " & Cancel & ", " & UnloadMode
    mmExit_Click
End Sub

Private Sub Form_Unload(Cancel As Integer)
On Error Resume Next
    If True = TheScript.Eval("Call_Form_Unload") Then TheScript.ExecuteStatement "Form_Unload " & Cancel
End Sub

Private Sub Form_Resize()
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptForm_Resize") Then
        TheScript.ExecuteStatement "ScriptForm_Resize"
    Else
        ScriptText.Width = ScriptForm.ScaleWidth
        ScriptText.Height = ScriptForm.ScaleHeight
    End If
End Sub

Private Sub mmAbout_Click()
On Error Resume Next
    frmAbout.Show 1
End Sub

Private Sub mmColor_Click()
    On Error GoTo perr
    cd.ShowColor
    ScriptText.ForeColor = cd.Color
perr:
End Sub

Private Sub mmColorBack_Click()
    On Error GoTo perr
    cd.ShowColor
    ScriptText.BackColor = cd.Color
    ScriptForm.BackColor = cd.Color
perr:
End Sub

Private Sub mmExit_Click()
    Dim r As VbMsgBoxResult
    If bModified Then
        r = MsgBox("脚本尚未存盘, 现在存盘么?", vbYesNoCancel)
        If r = vbYes Then
            mmSave_Click
            End
        ElseIf r = vbNo Then
            End
        End If
    Else
        End
    End If
End Sub

Private Sub mmFont_Click()
    On Error GoTo perr
    cd.ShowFont
    ScriptText.FontName = cd.FontName
    ScriptText.FontBold = cd.FontBold
    ScriptText.FontItalic = cd.FontItalic
    ScriptText.FontSize = cd.FontSize
    ScriptText.FontStrikethru = cd.FontStrikethru
    ScriptText.FontUnderline = cd.FontUnderline
perr:
End Sub

Private Sub mmInitFiles_Click()
On Error GoTo perr
    cd.ShowOpen
    saveInitFiles cd.FileName
    Exit Sub
perr:
End Sub

Private Sub mmNew_Click()
    Dim r As VbMsgBoxResult
    If bModified Then
        r = MsgBox("脚本尚未存盘, 现在存盘么?", vbYesNoCancel)
        If r = vbYes Then
            mmSave_Click
            newScript
        ElseIf r = vbNo Then
            newScript
        End If
    End If
End Sub

Private Sub mmOpen_Click()
    Dim r As VbMsgBoxResult
    On Error GoTo perr
    If bModified Then
        r = MsgBox("脚本尚未存盘, 现在存盘么?", vbYesNoCancel)
        If r = vbCancel Then Exit Sub
        If r = vbYes Then mmSave_Click
        If r = vbNo Then bModified = False
    End If
    If Not bModified Then
        cd.ShowOpen
        openScript cd.FileName
    End If
perr:
End Sub

Private Sub mmRun_Click()
    On Error Resume Next
    TheScript.ExecuteStatement ScriptText.text
    ScriptText.SetFocus
End Sub

Private Sub mmSave_Click()
    On Error GoTo perr
    If IsSpecified(scrFileName) Then
        saveScript scrFileName
    Else
        cd.ShowSave
        saveScript cd.FileName
    End If
perr:
End Sub

Private Sub mmSaveAs_Click()
    On Error GoTo perr
    cd.ShowSave
    saveScript cd.FileName
perr:
End Sub

Private Sub mmVBScript_Click()
On Error Resume Next
    mmVBScript.Checked = True
    mmJavaScript.Checked = False
    TheScript.Language = "VBScript"
    initScript
End Sub

Private Sub mmJavaScript_Click()
On Error Resume Next
    mmVBScript.Checked = False
    mmJavaScript.Checked = True
    TheScript.Language = "JavaScript"
    initScript
End Sub

Private Sub ScriptText_Change()
On Error Resume Next
    bModified = True
    If True = TheScript.Eval("Call_ScriptText_Change") Then TheScript.ExecuteStatement "ScriptText_Change"
End Sub

Private Sub ScriptText_Click()
    Form_Click
End Sub

Private Sub ScriptText_DblClick()
    Form_DblClick
End Sub

Private Sub ScriptText_GotFocus()
    Form_GotFocus
End Sub

Private Sub ScriptText_KeyDown(KeyCode As Integer, Shift As Integer)
On Error Resume Next
    Form_KeyDown KeyCode, Shift
    If Shift = 2 Then
        Select Case KeyCode
        Case 65 ' Ctrl-A
            ScriptText.SelStart = 0
            ScriptText.SelLength = Len(ScriptText)
        End Select
    End If
End Sub

Private Sub ScriptText_KeyPress(KeyAscii As Integer)
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptText_KeyPress") Then
        TheScript.ExecuteStatement "ScriptText_KeyPress " & KeyAscii
    Else
        Select Case KeyAscii
        Case 1  ' Ctrl-A
            ScriptText.SelStart = 0
            ScriptText.SelLength = Len(ScriptText)
        End Select
    End If
End Sub

Private Sub ScriptText_KeyUp(KeyCode As Integer, Shift As Integer)
On Error Resume Next
    Form_KeyUp KeyCode, Shift
End Sub

Private Sub ScriptText_LostFocus()
On Error Resume Next
    Form_LostFocus
End Sub

Private Sub ScriptText_MouseDown(Button As Integer, Shift As Integer, x As Single, Y As Single)
On Error Resume Next
    If Button And vbLeftButton Then
        If Shift And vbCtrlMask Then
            PopupMenu mDebug, , x, Y
        ElseIf Shift And vbAltMask Then
            PopupMenu mScript, , x, Y
        End If
    End If
    Form_MouseDown Button, Shift, x, Y
End Sub

Private Sub ScriptText_MouseMove(Button As Integer, Shift As Integer, x As Single, Y As Single)
On Error Resume Next
    Form_MouseMove Button, Shift, x, Y
End Sub

Private Sub ScriptText_MouseUp(Button As Integer, Shift As Integer, x As Single, Y As Single)
On Error Resume Next
    Form_MouseUp Button, Shift, x, Y
End Sub

Private Sub scriptTimer_Timer()
On Error Resume Next
    If True = TheScript.Eval("Call_ScriptTimer_Timer") Then TheScript.ExecuteStatement "ScriptTimer_Timer"
End Sub

Private Sub TheScript_Error()
On Error Resume Next
    Dim e As String
    Dim r As VbMsgBoxResult
    If TheScript.Tag = "E" Then
        TheScript.ExecuteStatement "TheScript_Error"
    Else
        e = "[" & TheScript.Error.Number & "] " & TheScript.Error.Description & vbNewLine & vbNewLine
        e = e & "错误发生在 第" & TheScript.Error.line & "行, 第" & TheScript.Error.column & "列: " & vbNewLine
        e = e & TheScript.Error.text
        r = MsgBox(e, vbExclamation Or vbMsgBoxHelpButton, TheScript.Error.Description, TheScript.Error.HelpFile, TheScript.Error.HelpContext)
        ScriptText.SelStart = getp(ScriptText, TheScript.Error.line, TheScript.Error.column)
    End If
End Sub

Private Sub TheScript_Timeout()
On Error Resume Next
    If True = TheScript.Eval("Call_TheScript_Timeout") Then TheScript.ExecuteStatement "TheScript_Timeout"
End Sub
