Attribute VB_Name = "modMessage"
Option Explicit

Public ltp As New LowXTool.Pointer
Public lte As New LowXTool.Executable

Public Const WM_KEYFIRST = &H100
Public Const WM_KEYDOWN = &H100
Public Const WM_KEYUP = &H101
Public Const WM_CHAR = &H102
Public Const WM_MOUSEFIRST = &H200
Public Const WM_MOUSEMOVE = &H200
Public Const WM_LBUTTONDOWN = &H201
Public Const WM_LBUTTONUP = &H202
Public Const WM_LBUTTONDBLCLK = &H203
Public Const WM_RBUTTONDOWN = &H204
Public Const WM_RBUTTONUP = &H205
Public Const WM_RBUTTONDBLCLK = &H206
Public Const WM_MBUTTONDOWN = &H207
Public Const WM_MBUTTONUP = &H208
Public Const WM_MBUTTONDBLCLK = &H209
Public Const WM_MOUSELAST = &H209

Public 旧消息处理 As Long

Public Function 处理进程交换回调(ByVal 旧消息处理进程 As Long) As Long
        If 旧消息处理 = 0 Then
                ' 避免错误回归调用
                旧消息处理 = 旧消息处理进程
        End If
        处理进程交换回调 = ltp.Vpf(AddressOf 新消息处理)
End Function
Public Function 恢复回调(ByVal 旧消息处理进程 As Long) As Long
        恢复回调 = 旧消息处理
        旧消息处理 = 0
End Function

' 消息处理进程有严格的格式, 最基本的约定如下
'       未处理的消息必须传递给消息链的下一个消息处理进程
'       不同的消息有不同的返回值,
'               有一些消息返回0表示消息处理成功,
'               尔另一些消息返回0可能表示消息需要重新处理
'       所以必须返回 消息链中下一个消息处理进程的 返回值
Public Function 新消息处理(ByVal hWnd As Long, ByVal message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
        Static 正在处理中 As Boolean
        If Not 正在处理中 Then
                正在处理中 = True
                With frmMain
                        .iWnd = hWnd
                        .iMessage = message
                        .iWparam = wParam
                        .iLparam = lParam
                End With
                正在处理中 = False
        End If
        Select Case message
        Case WM_MOUSEMOVE
                frmMain.txtCounter.Text = str(Val(frmMain.txtCounter.Text) - 1)
                新消息处理 = 0
        Case Else
                新消息处理 = lte.VChainMessage(旧消息处理, hWnd, message, wParam, lParam)
        End Select
End Function
