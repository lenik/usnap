Attribute VB_Name = "modMyWndProc"

' WndprocStacks 中每个元素仍为 Collection, 且结构为:
' Key:
'       hWnd            Collection 对应 hWnd
'       <num>           栈中次序, 0..Collection.Count-2

Private WndprocStacks As New Collection

Private ShareInt As Long

Public Function switchproc(ByVal currentwndproc As Long) As Long
        WndprocStack.Add currentwndproc
        oldwndproc = currentwndproc
        switchproc = pFunc(AddressOf ProxyWndProc)
End Function

Public Function unswitchproc(ByVal currentwndproc As Long) As Long
        unswitchproc = oldwndproc
End Function

Public Function InstallWndProc(ByVal hWnd As Long, ByVal newproc As Long, Optional ByVal install_at_back As Boolean = False) As Boolean
        Dim cws As Collection   ' correspond_wndproc_stack
        Dim i As Collection

        InstallWndProc = False

        'Set cws = WndprocStacks(Trim(hWnd))
        For Each i In WndprocStacks
                If i("hWnd") = hWnd Then
                        Set cws = i
                        Exit For
                End If
        Next

        If cws Is Nothing Then
                Set cws = New Collection
                cws.Add hWnd, "hWnd"
        End If

        cws.Add newproc, Trim(cws.Count - 1)
        WndprocStacks.Add cws, Trim(cws("hWnd"))

        InstallWndProc = True
End Function

Public Function UninstallWndProc(ByVal hWnd As Long) As Boolean
        Dim cws As Collection
        If Not WndprocStacks(Trim(hWnd)) Is Nothing Then

End Function

Public Function ProxyWndProc( _
        ByVal hWnd As Long, _
        ByVal message As Long, _
        ByVal wParam As Long, _
        ByVal lParam As Long) As Long

        Dim proxied As Boolean
        proxied = False

        Select Case message
        Case WM_COMMAND
                frmMain.List1.AddItem "w:" & wParam & "l:" & lParam
                Select Case wParam
                Case 2:
                        proxied = True
                        MsgBox "哈哈，已经被我控制了！"
                End Select
        Case WM_NCPAINT
                'proxied = True
        End Select

        If Not proxied Then
                ProxyWndProc = chainMessage( _
                                oldwndproc, _
                                hWnd, _
                                message, _
                                wParam, _
                                lParam)
        End If
End Function
