Attribute VB_Name = "modProxyMsg"

Public oldproc As Long

Public Function proxywndproc(ByVal hWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
        Dim text As String * 100
        Dim callnext As Boolean

        callnext = True

        Select Case Msg
        Case WM_COMMAND
                Select Case wParam
                Case 2
                        MsgBox "PPP"
                        callnext = False
                End Select

        Case WM_NCPAINT
                Dim hdc As Long
                hdc = GetDCEx(hWnd, wParam, DCX_WINDOW)

                FillRgn hdc, wParam, GetStockObject(WHITE_BRUSH)
                Ellipse hdc, 0, 0, 100, 30

        '        callnext = False
        Case WM_PAINT
                'callnext = False
        End Select

        If callnext Then
                proxywndproc = CallWindowProc(oldproc, hWnd, Msg, wParam, lParam)
        End If
End Function
