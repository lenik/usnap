VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "图形表示"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public 表示设备 As Long

Public Sub 绘制格子(ByVal 格子类型 As 格子类型, ByVal 设备格子坐标x As Single, ByVal 设备格子坐标y As Single, Optional ByVal 刷新设备 As Boolean = False)
        Dim 绘制宽度 As Single, 绘制高度 As Single
        Dim 设备坐标x As Single, 设备坐标y As Single
        Dim 绘制偏移x As Single, 绘制偏移y As Single

        绘制宽度 = 16
        绘制高度 = 16
        设备坐标x = 设备格子坐标x * 16
        设备坐标y = 设备格子坐标y * 16
        绘制偏移x = 0
        绘制偏移y = 0

        If 设备格子坐标x < 0 Then
                '绘制宽度
        End If

        Dim 切片索引 As Integer
        Dim 切片x As Integer, 切片y As Integer
                切片索引 = 0
                Select Case 格子类型
                Case 平地: 切片索引 = 0
                Case 草地: 切片索引 = 1
                Case 山丘: 切片索引 = 3
                Case 湖泊: 切片索引 = 2
                End Select
                切片x = (切片索引 Mod 4) * 16
                切片y = (Int(切片索引 / 4)) * 16
        '主窗体.格子切片.GraphicCell(切片索引).Render 主窗体.场景.hdc, _
                设备坐标x, 设备坐标y, 绘制宽度, 绘制高度, _
                绘制偏移x, 绘制偏移y, 绘制宽度, 绘制高度, _
                Null
        BitBlt 主窗体.场景.hdc, _
                设备坐标x, 设备坐标y, 绘制宽度, 绘制高度, _
                主窗体.格子切片.hdc, 切片x + 绘制偏移x, 切片y + 绘制偏移y, _
                SRCCOPY
End Sub
