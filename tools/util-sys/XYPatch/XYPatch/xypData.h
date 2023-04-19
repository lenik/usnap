
// XYPatch data file i/o

LPCTSTR xypSign			= "翔宇打补丁专家补丁文件1.00"

// entry prefix
LPCTSTR xypDir			= "目录:";
LPCTSTR xypDir_			= "目录结束";
LPCTSTR xypArt			= "文档:";
LPCTSTR xypArt_			= "文档结束";

LPCTSTR xypPatch		= "补丁:";
LPCTSTR xypPatch_		= "补丁结束";

// patch format  [00A95C70[/生命值][/1000[bWd][tF]][/1.0]] ...

LPCTSTR xypEnd			= "全部结束";

LPCTSTR xypDataInline	= "内嵌数据";
LPCTSTR xypDataInline_	= "内嵌数据结束";

Global Const XYPatchFile = "翔宇补丁.txt"

Type FileError
    Error As Boolean
    LineNo As Integer
    Message As String
End Type

Type NodeType
    Name As String
    Text As String
    Icon As Integer
    IconSelect As Integer
    IconExpanded As Integer
End Type

Enum DataType
    dtSubdirectory = &H44   'D' sub Directory
    dtText = &H54           'T' Text
    dtPatch = &H23          '#' Patch
End Enum

Type TagData
    DataType As DataType
    Version As Integer
    Src As String
End Type

Type PatchType
    Address As Long         ' 进程偏移地址
    VarName As String       ' 显示名称
    Value As Long           ' 初始值
        VarLength As String ' 变量长度 (byte单位) (B, W, D)
        Locked As String    ' 锁定状态 ('T', 'F')
    Version As String
    ProcessId As Long       ' 连接进程
End Type

Dim TEnumWindowsList As ComboBox

Function GenPatchText(pPatch As PatchType) As String
    GenPatchText = Hex(pPatch.Address) + "/"
    If pPatch.VarName <> "" Then
        GenPatchText = GenPatchText + pPatch.VarName
    End If
    If pPatch.Value <> 0 Then
        GenPatchText = GenPatchText + "/" + LTrim(Str(pPatch.Value))
        If pPatch.VarLength <> "" Then
            Select Case pPatch.VarLength
                Case "1"
                    GenPatchText = GenPatchText + "B"
                Case "2"
                    GenPatchText = GenPatchText + "W"
                Case "4"
                    GenPatchText = GenPatchText + "D"
            End Select
            If pPatch.Locked <> "" Then
                GenPatchText = GenPatchText + pPatch.Locked
            End If
        End If
    End If
    If pPatch.Version <> "" Then
        GenPatchText = GenPatchText + "/" + pPatch.VarLength
    End If
    GenPatchText = XYPatchLL + GenPatchText + XYPatchLR
End Function

Function GetTag(ByVal Src As String) As TagData
    GetTag.DataType = Asc(Left(Src, 1))
    GetTag.Version = Asc(Mid(Src, 2, 1))
    GetTag.Src = Right(Src, Len(Src) - 2)
End Function

Function SetTag(tdTag As TagData) As String
    SetTag = Chr(tdTag.DataType) + Chr(tdTag.Version) + tdTag.Src
End Function

Function EnumPatch(Src As String, Optional Restart As Boolean = False) As PatchType
    Static lSrc As String, pSrc As Integer
    Dim p As Integer, p2 As Integer
    If Restart Then pSrc = 1

    EnumPatch.Address = 0   ' 表示枚举完了
    EnumPatch.VarName = "未命名"
    EnumPatch.VarLength = "2"
    EnumPatch.Value = 0
    EnumPatch.Locked = "F"
    EnumPatch.Version = "0"

    p = InStr(pSrc, Src, XYPatchLL)
    p2 = InStr(pSrc, Src, XYPatchLR)

    If p > 0 And p2 > p Then
        pSrc = p2 + 1
        lSrc = TrimF(Mid(Src, p + 1, p2 - p - 1))
        EnumPatch.Address = GetNum(lSrc, 16)
        lSrc = Trim(Right(lSrc, Len(lSrc) - InStr(1, lSrc, "/")))
        If Len(lSrc) > 0 Then
            p = InStr(1, lSrc, "/") - 1
            If p < 0 Then p = Len(lSrc)
            EnumPatch.VarName = Left(lSrc, p)
            If p = Len(lSrc) Then p = p + 1
            lSrc = Trim(Right(lSrc, Len(lSrc) - p - 1))
            lSrc = LTrim(lSrc)
        End If
        If Len(lSrc) > 0 Then
            EnumPatch.Value = GetNum(lSrc)
            lSrc = LTrim(lSrc)
        End If
        If Len(lSrc) > 0 Then
            Select Case UCase(Left(lSrc, 1))
            Case "B"
                EnumPatch.VarLength = 1
            Case "W"
                EnumPatch.VarLength = 2
            Case "D"
                EnumPatch.VarLength = 4
            End Select
            lSrc = LTrim(Right(lSrc, Len(lSrc) - 1))
        End If
        If Len(lSrc) > 0 Then
            EnumPatch.Locked = UCase(Left(lSrc, 1))
            lSrc = LTrim(Right(lSrc, Len(lSrc) - 1))
        End If
        p = InStr(1, lSrc, "/")
        lSrc = LTrim(Right(lSrc, Len(lSrc) - p))
        If Len(lSrc) > 0 Then
            p = InStr(1, lSrc, "/") - 1
            If p < 0 Then p = Len(lSrc)
            EnumPatch.Version = Left(lSrc, p)
        End If
    End If
End Function

Function GetNum(ByRef Src As String, Optional Ordix As Integer = 10) As Long
    Dim c As String * 1, RSrc As String, i As Integer
    Const NTable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    GetNum = 0: RSrc = ""

    ' 取出有效数字
    For i = 1 To Len(Src)
        c = Mid(Src, i, 1)
        If InStr(1, Left(NTable, Ordix), UCase(c)) = 0 Then
            Exit For
        Else
            RSrc = RSrc + UCase(c)
        End If
    Next
    Src = Right(Src, Len(Src) - i + 1)

    ' 转换成数字
    If Ordix = 10 Then
        GetNum = Val(RSrc)
    Else
        For i = 1 To Len(RSrc)
            c = Mid(RSrc, i, 1)
            GetNum = GetNum * Ordix + InStr(1, NTable, c) - 1
        Next
    End If
End Function

Function TrimF(s As String) As String
    TrimF = Trim(s)
    Do While Left(TrimF, 1) = Chr(9)
        TrimF = Right(TrimF, Len(TrimF) - 1)
    Loop
End Function

Sub ErrorRunning(feFileError As FileError, nFile As Integer)
    If feFileError.LineNo = 0 Then
        MsgBox feFileError.Message, vbOK, "运行时发生错误"
    Else
        MsgBox XYSign + Chr(10) + "第" + Str(feFileError.LineNo) + "行错误: " + Chr(10) + feFileError.Message, vbOKOnly
    End If
    Close #nFile
    'End
End Sub

Function IsA(Parent As String, Child As String, Optional Start As Integer = 1) As Boolean
    IsA = False
    If Mid(Parent, Start, Len(Child)) = Child Then IsA = True
End Function

Function GetNode(LineText As String, Optional Start As Integer = 6) As NodeType
    Dim i As Integer
    Dim s As String

    GetNode.Icon = 0
    GetNode.Text = ""
    i = Start

        s = Right(LineText, Len(LineText) - i)
        i = InStr(1, s, ",", vbTextCompare)
        If i < 1 Then GetNode.Name = TrimF(s): Exit Function
        GetNode.Name = TrimF(Left(s, i - 1))

        s = Right(s, Len(s) - i)
        i = InStr(1, s, ",", vbTextCompare)
        If i < 1 Then GetNode.Text = TrimF(s): Exit Function
        GetNode.Text = TrimF(Left(s, i - 1))

        s = Right(s, Len(s) - i)
        i = InStr(1, s, ",", vbTextCompare)
        If i < 1 Then
            GetNode.Icon = Val(TrimF(s))
            GetNode.IconSelect = GetNode.Icon
            GetNode.IconExpanded = GetNode.IconSelect
            Exit Function
        End If
        GetNode.Icon = Val(TrimF(Left(s, i - 1)))
        GetNode.IconSelect = GetNode.Icon
        GetNode.IconExpanded = GetNode.IconSelect

        s = Right(s, Len(s) - i)
        i = InStr(1, s, ",", vbTextCompare)
        If i < 1 Then
            GetNode.IconSelect = Val(TrimF(s))
            GetNode.IconExpanded = GetNode.IconSelect
            Exit Function
        End If
        GetNode.IconSelect = Val(TrimF(Left(s, i - 1)))
        GetNode.IconExpanded = GetNode.IconSelect

        s = Right(s, Len(s) - i)
        GetNode.IconExpanded = Val(TrimF(s))

End Function

Function CheckNode(Node As NodeType, NodeClass As String) As FileError
    Dim n As Integer

    CheckNode.Error = False

    If Node.Icon < 1 Or Node.IconSelect < 1 Or Node.IconExpanded < 1 Then
        CheckNode.Error = True
        CheckNode.Message = "类型" + Str(Node.Icon) + Str(Node.IconSelect) + Str(Node.IconExpanded) + "没找到!"
        Exit Function
    End If

    If NodeClass = XYArt Or NodeClass = XYPatch Then
        If IsA(Node.Text, XYFileRefer) Then
            n = FreeFile
            On Error GoTo FileReferError
            Open Right(Node.Text, Len(Node.Text) - Len(XYFileRefer)) For Input As #n
            Close #n
        End If
    End If

Exit Function

FileReferError:
    CheckNode.Error = True
    CheckNode.Message = "打开引用文件" + Right(Node.Text, Len(Node.Text) - Len(XYFileRefer)) + "错误: " + Err.Description

End Function

Function ReadDir(FN As String, tvTreeView As TreeView) As FileError
    Dim l As Integer    ' Line No
    Dim s As String     ' Line string
    Dim n As Integer    ' FreeFile
    Dim AllWell As Boolean

    Dim NodeDesc As NodeType
    Dim CurNode As Node, NewNode As Node
    Dim ts As String    ' temp string

    Dim td As TagData
    td.Version = Asc(" ")

    ReadDir.Error = False
    AllWell = False

On Error GoTo openerror

    n = FreeFile
    Open FN For Input As #n

On Error GoTo readerror

    l = 0

    ' Read Header
    Do While Not EOF(n)
        l = l + 1
        Line Input #n, s: s = TrimF(s)
        If s <> "" Then Exit Do
    Loop

    If Not IsA(XYSign, s) Then
        ReadDir.Error = True
        ReadDir.LineNo = l
        ReadDir.Message = "这不是" + XYSign + ". 请仔细检查. 抱歉!"
        Close #n
        Exit Function
    End If

    tvTreeView.Nodes.Clear
    Set CurNode = tvTreeView.Nodes.Add(, , "Root", "翔宇打补丁专家", 1, 2)
    CurNode.Expanded = True

    Do While Not EOF(n)
        l = l + 1
        Line Input #n, s: s = TrimF(s)
        If s <> "" Then
            If IsA(s, XYDir) Then
                ' 加入目录结点  目录:<目录名>,,<图标>,<选择>,[<展开>]
                NodeDesc = GetNode(s, Len(XYDir))
                ReadDir = CheckNode(NodeDesc, XYDir)
                If ReadDir.Error Then ErrorRunning ReadDir, n
                Set CurNode = tvTreeView.Nodes.Add(CurNode, tvwChild, , NodeDesc.Name, NodeDesc.Icon, NodeDesc.IconSelect)
                CurNode.ExpandedImage = NodeDesc.IconExpanded
            ElseIf IsA(s, XYDirX) Then
                If CurNode.FirstSibling.Key <> "Root" Then
                    Set CurNode = CurNode.Parent
                Else
                    ReadDir.Error = True
                    ReadDir.LineNo = l
                    ReadDir.Message = "目录嵌逃超界"
                    Close #n
                    Exit Function
                End If
            ElseIf IsA(s, XYArt) Then
                ' 加入档案  档案:<档案名>,<数据>,<图标>,[<选择>]
                td.DataType = dtText
                NodeDesc = GetNode(s, Len(XYArt))
                ReadDir = CheckNode(NodeDesc, XYArt)
                If ReadDir.Error Then ErrorRunning ReadDir, n
                Set NewNode = tvTreeView.Nodes.Add(CurNode, tvwChild, , NodeDesc.Name, NodeDesc.Icon, NodeDesc.IconSelect)
                ' 装入数据
                If IsA(NodeDesc.Text, XYDataInline) Then
                    ' 内嵌数据
                    td.Src = "-" + Chr(13) + Chr(10)
                    Do While Not EOF(n)
                        Line Input #n, ts
                        If IsA(ts, XYDataInlineX) Then Exit Do
                        td.Src = td.Src + Chr(13) + Chr(10) + ts
                    Loop
                Else
                    ' 以行之内数据或引用文件
                    td.Src = NodeDesc.Text
                End If
                NewNode.Tag = SetTag(td)
            ElseIf IsA(s, XYPatch) Then
                ' 加入补丁  补丁:<补丁名>,<补丁代码>,<图标>,[<选择>]
                td.DataType = dtPatch
                NodeDesc = GetNode(s, Len(XYPatch))
                ReadDir = CheckNode(NodeDesc, XYPatch)
                If ReadDir.Error Then ErrorRunning ReadDir, n
                Set NewNode = tvTreeView.Nodes.Add(CurNode, tvwChild, , NodeDesc.Name, NodeDesc.Icon, NodeDesc.IconSelect)
                ' 装入数据
                If IsA(NodeDesc.Text, XYDataInline) Then
                    ' 内嵌数据
                    Do While Not EOF(n)
                        Line Input #n, ts
                        If IsA(ts, XYDataInlineX) Then Exit Do
                        td.Src = td.Src + ts
                    Loop
                Else
                    ' 以行之内数据或引用文件
                    td.Src = NodeDesc.Text
                End If
                NewNode.Tag = SetTag(td)
            ElseIf IsA(s, XYEnd) Then
                AllWell = True
                Exit Do
            ElseIf False Then
                ReadDir.Error = True
                ReadDir.LineNo = l
                ReadDir.Message = "未知结点类型: " + Left(s, 4) + "..."
                Close #n
                Exit Function
            End If
        End If
    Loop

    Close #n

    ' 没发现结束标志
    If Not AllWell Then
        ReadDir.Error = True
        ReadDir.LineNo = l
        ReadDir.Message = "无结尾错误!"
        Exit Function
    End If

Exit Function

openerror:
    ReadDir.Error = True
    ReadDir.Message = "打开" + XYSign + "文件" + FN + "错误: " + Chr(10) + Err.Description
    Exit Function

readerror:
    ReadDir.Error = True
    ReadDir.Message = "读入" + XYSign + "文件" + FN + "错误: " + Chr(10) + Err.Description
    Close #n
    Exit Function

End Function

Sub RefreshValue()

End Sub

Function TEnumWindowProc(ByVal hWnd As Long, ByVal lParam As Long) As Boolean
    Dim TextBuf As String
    Dim nLength As Integer
    Dim nIndex As Long
    Dim dwThreadId As Long, dwProcessId As Long
    Dim hProcess As Long
    Dim nPriorityClass As Long

    If hWnd <> 0 Then
        nLength = GetWindowTextLength(hWnd)
        If nLength > 0 Then
            dwThreadId = GetWindowThreadProcessId(hWnd, dwProcessId)
            hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, False, dwProcessId)
            nPriorityClass = GetPriorityClass(hProcess)
            CloseHandle hProcess
            If nPriorityClass >= frmMain.sldPriority.Value Then
                TextBuf = String(nLength + 1, 0)
                GetWindowText hWnd, TextBuf, nLength + 1
                TextBuf = Hex(dwProcessId) & "/" & Hex(dwThreadId) & " " & TextBuf
                TEnumWindowsList.AddItem TextBuf
                TEnumWindowsList.ItemData(TEnumWindowsList.ListCount - 1) = dwProcessId
            End If
        End If
    End If
    TEnumWindowProc = True
End Function
Function TEnumProcess(cb As ComboBox) As Boolean
    Set TEnumWindowsList = cb
    TEnumWindowsList.Clear
    TEnumProcess = EnumWindows(AddressOf TEnumWindowProc, 0)
End Function
