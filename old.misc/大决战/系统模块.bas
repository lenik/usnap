Attribute VB_Name = "系统模块"
Option Explicit

Public 数组操作 As New LowXTool.Array
Public 指针操作 As New LowXTool.Pointer
Public 字串操作 As New LowXTool.String

Public Sub Main()
        初始化系统

        Dim wi As WINDOWINFO
        Load 主窗体
        GetWindowInfo 主窗体.hWnd, wi
        wi.rcClient.Left = wi.rcClient.Left + 主窗体.场景.Left
        wi.rcClient.Top = wi.rcClient.Top + 主窗体.场景.Top
        wi.rcClient.Right = wi.rcClient.Left + 主窗体.场景.Width
        wi.rcClient.Bottom = wi.rcClient.Top + 主窗体.场景.Height
        ClipCursor wi.rcClient
        主窗体.Show 1
        退出系统
End Sub

Public Sub 初始化系统()
        地图模块.初始化地图格子

        Set 地图模块.主地图 = 测试模块.创建主地图
        With 地图模块.主地图
                Set .图形表示 = New 图形表示
                .视区左边界 = 0
                .视区上边界 = 0
                .视区宽度 = 20
                .视区高度 = 10
        End With
End Sub

Public Sub 退出系统()
        ClipCursor_ 0
End Sub
