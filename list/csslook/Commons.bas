Attribute VB_Name = "modCommons"
Option Explicit

Public FSO As New Scripting.FileSystemObject
Public HomeDir As String

Public StyleBegin As String
Public StyleEnd As String
Public PreviewHtml_Head As String
Public PreviewHtml_Init As String
Public PreviewHtml_Body As String

Public RegexCssEntry As New VBScript_RegExp_10.RegExp

Public CurrentFile As String
Public CurrentContent As String
Public LastEntries As String

Public Sub Main()
    Init
    Load frmCssLook

    frmCssLook.Show

    If Command <> "" Then
        Dim FileName As String
        FileName = Command
        If Left(FileName, 1) = """" Then FileName = Mid(FileName, 2)
        If Right(FileName, 1) = """" Then FileName = Left(FileName, Len(FileName) - 1)
        OpenCSS FileName
    End If
End Sub

Public Sub Init()
    Dim preview

    HomeDir = App.Path

    StyleBegin = _
        "<style type=""text/css"">" & vbNewLine & _
        "<!--" & vbNewLine
    StyleEnd = _
        vbNewLine & _
        "-->" & vbNewLine & _
        "</style>" & vbNewLine

    On Error GoTo x_ReadPreview
    preview = FSO.OpenTextFile(HomeDir & "\preview.htm").ReadAll
    preview = Replace(preview, "image.gif", HomeDir & "\image.gif")
    preview = Split(preview, "%%")
    PreviewHtml_Head = preview(0)
    PreviewHtml_Init = preview(1)
    PreviewHtml_Body = preview(2)
    On Error GoTo 0

    ' (  (  (.\w+)|(,\s*\w+)  ) \s*   )*\{
    RegexCssEntry.Pattern = "(((\.\w+)|(,\s*\w+))\s*)+\{"
    RegexCssEntry.Global = 1
    Exit Sub

x_ReadPreview:
    MsgBox "Can't read preview.htm or syntax error!" & vbNewLine & Err.Description, vbCritical
    End
End Sub

Public Sub OpenCSS(ByVal cssFile As String)

    On Error GoTo x_readcss
    CurrentContent = FSO.OpenTextFile(cssFile).ReadAll
    On Error GoTo 0

    CurrentFile = cssFile
    LoadCSS CurrentContent

    frmCssLook.Caption = "Css Look - " & cssFile
    Exit Sub

x_readcss:
    MsgBox "Can't read " & cssFile & "!" & vbNewLine & Err.Description, vbCritical
End Sub

Public Sub LoadCSS(content)
    Dim matches As MatchCollection
    Dim m As Match
    Dim i As Integer, j As Integer, k As Integer
    Dim styleNames
    Dim styleName As String
    Dim stylePreview As String
    Dim sampleText As String
    Dim previewHtml As String

    previewHtml = _
        PreviewHtml_Head & _
        StyleBegin & content & StyleEnd & _
        PreviewHtml_Init
    content = Replace(content, Chr(10), " ")    ' for regex-singleline
    content = Replace(content, Chr(13), "")     ' remove \r

    Set matches = RegexCssEntry.Execute(content)
    For i = 0 To matches.Count - 1
        Set m = matches.Item(i)
        styleNames = Split(Left(m.Value, Len(m.Value) - 1), ",")
        For j = 0 To UBound(styleNames)
            styleName = Trim(styleNames(j))
            If Left(styleName, 1) = "." Then
                styleName = Mid(styleName, 2)

                sampleText = ""
                For k = 1 To 4
                    sampleText = sampleText & "<span style='font-weight: bold'>" & styleName & "</span> sample "
                Next

                stylePreview = stylePreview & _
                    "<H3>Style: " & styleName & "</H3>" & _
                    "<DIV class=""" & styleName & """>" & sampleText & "</DIV><HR/>" & vbNewLine
            End If
        Next
    Next

    previewHtml = _
        previewHtml & _
        stylePreview & _
        PreviewHtml_Body

    frmCssLook.loadHtml previewHtml
End Sub
