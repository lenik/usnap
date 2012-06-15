Attribute VB_Name = "wndproc"

Public g_oldproc As Long
Public g_count As Long

Public Function switchProc(ByVal oldproc As Long) As Long
        g_oldproc = oldproc
        switchProc = pFunc(AddressOf newproc)
End Function

Public Function newproc(ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
        Dim nochain As Boolean
        Dim p As POINTAPI
        nochain = False
        newproc = 0
        Select Case Msg
        Case WM_NCMOUSEMOVE, WM_MOUSEMOVE
                GetCursorPos p
                frmMain.info(0) = p.X & "," & p.Y
        End Select
        If Not nochain And g_oldproc <> 0 Then
                newproc = chainMessage(g_oldproc, hWnd, Msg, wParam, lParam)
        End If
End Function
