VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "地图"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

' 属性
        Private 内部宽度 As Long, 内部高度 As Long

        Private 格子表(0 To 最大宽 - 1, 0 To 最大高 - 1) As 格子类型

        Private 内部视区左边界 As Single
        Private 内部视区上边界 As Single
        Private 内部视区宽度 As Single
        Private 内部视区高度 As Single
        Public 图形表示 As 图形表示

' 地图大小
        Public Property Get 宽度() As Long
                宽度 = 内部宽度
        End Property
        Public Property Get 高度() As Long
                高度 = 内部高度
        End Property
        Public Property Let 宽度(ByVal nw As Long)
                If nw >= 0 And nw <= 最大宽 Then
                        内部宽度 = nw
                Else
                        Err.Raise -1, , "宽度超出最大值: " & 最大宽
                End If
        End Property
        Public Property Let 高度(ByVal nh As Long)
                If nh >= 0 And nh <= 最大高 Then
                        内部高度 = nh
                Else
                        Err.Raise -1, , "高度超出最大值: " & 最大高
                End If
        End Property

' 格子
        Public Property Get 格子(ByVal X As Long, ByVal Y As Long) As 格子类型
                If X < 0 Or X >= 内部宽度 Or Y < 0 Or Y >= 内部高度 Then
                        Err.Raise -1, , "格子坐标出界"
                Else
                        格子 = 格子表(X, Y)
                End If
        End Property
        Public Property Let 格子(ByVal X As Long, ByVal Y As Long, 设置格子 As 格子类型)
                If X < 0 Or X >= 内部宽度 Or Y < 0 Or Y >= 内部高度 Then
                        Err.Raise -1, , "格子坐标出界"
                Else
                        格子表(X, Y) = 设置格子
                End If
        End Property

' 视区
        Public Property Get 视区左边界() As Single
                视区左边界 = 内部视区左边界
        End Property
        Public Property Get 视区上边界() As Single
                视区上边界 = 内部视区上边界
        End Property
        Public Property Get 视区宽度() As Single
                视区宽度 = 内部视区宽度
        End Property
        Public Property Get 视区高度() As Single
                视区高度 = 内部视区高度
        End Property
        Public Property Let 视区左边界(ByVal nl As Single)
                内部视区左边界 = nl
        End Property
        Public Property Let 视区上边界(ByVal nt As Single)
                内部视区上边界 = nt
        End Property
        Public Property Let 视区宽度(ByVal nw As Single)
                内部视区宽度 = nw
        End Property
        Public Property Let 视区高度(ByVal nh As Single)
                内部视区高度 = nh
        End Property


' 有效性检验
        Private Function 设置移动范围(设置范围 As 地图范围, ByVal 中心横坐标 As Long, ByVal 中心纵坐标 As Long, ByVal 总移动力 As Long, ByVal 剩余移动力 As Long)
                Dim 四周移动范围(0 To 3, 0 To 1) As Integer
                Dim 格子消耗移动力 As Long
                Dim 目标消耗移动力 As Long

                数组操作.InitArray2i 四周移动范围, "-1, 0; 1, 0; 0, -1; 0, 1"
                目标消耗移动力 = 总移动力 - 剩余移动力
                If 中心横坐标 >= 设置范围.范围左边界 And _
                        中心横坐标 <= 设置范围.范围右边界 And _
                        中心纵坐标 >= 设置范围.范围上边界 And _
                        中心纵坐标 <= 设置范围.范围下边界 Then

                        设置范围.动态格子(中心横坐标, 中心纵坐标).数据_消耗移动力 = 目标消耗移动力
                        格子消耗移动力 = 设置范围.消耗移动力(中心横坐标, 中心纵坐标)

                        Dim i As Integer
                        For i = 0 To 3
                                中心横坐标 = 中心横坐标 + 四周移动范围(i, 0)
                                中心纵坐标 = 中心纵坐标 + 四周移动范围(i, 1)

                                If 中心横坐标 >= 设置范围.范围左边界 And _
                                        中心横坐标 <= 设置范围.范围右边界 And _
                                        中心纵坐标 >= 设置范围.范围上边界 And _
                                        中心纵坐标 <= 设置范围.范围下边界 Then

                                        If 设置范围.可行走(中心横坐标, 中心纵坐标) Then
                                                Dim 到四周目标的剩余移动力 As Long
                                                Dim 到四周目标的消耗移动力 As Long
                                                到四周目标的剩余移动力 = 剩余移动力 - 格子消耗移动力
                                                到四周目标的消耗移动力 = 总移动力 - 到四周目标的剩余移动力
                                                If 到四周目标的消耗移动力 < 设置范围(中心横坐标, 中心纵坐标).消耗移动力 Then
                                                        设置移动范围 设置范围, 中心横坐标, 中心纵坐标, 总移动力, 到四周目标的剩余移动力
                                                End If
                                        End If
                                End If

                                ' 归位
                                中心横坐标 = 中心横坐标 - 四周移动范围(i, 0)
                                中心纵坐标 = 中心纵坐标 - 四周移动范围(i, 1)
                        Next
                End If
        End Function
        Public Function 获取可走范围(s As 小人物) As 地图范围
                Dim r As New 地图范围

                r.范围边界宽 = s.当前移动力 * 2 + 1
                r.范围边界高 = s.当前移动力 * 2 + 1
                r.中心横坐标 = s.当前移动力
                r.中心纵坐标 = s.当前移动力
                r.设置全部格子类型 未定义

                设置移动范围 r, s.当前地图位置横坐标, s.当前地图位置纵坐标, s.初始移动力, s.初始移动力
        End Function


' 图形表示
        Public Sub 绘制地图(Optional ByVal 指定表示 As 图形表示 = Nothing)
                Dim 需绘制左边界 As Long, 需绘制右边界 As Long
                Dim 需绘制上边界 As Long, 需绘制下边界 As Long
                Dim 绘制左偏移 As Single, 绘制上偏移 As Single

                If 指定表示 Is Nothing Then Set 指定表示 = 图形表示
                If 指定表示 Is Nothing Then
                        Err.Raise -1, , "未指定图形表示, 必须设置地图的图形表示属性, 或者在调用绘制地图方法时指定图形表示"
                End If

                需绘制左边界 = Int(内部视区左边界)
                需绘制右边界 = Int(内部视区左边界 + 内部视区宽度 - 1)
                If 需绘制左边界 < 0 Then 需绘制左边界 = 0
                If 需绘制左边界 >= 内部宽度 Then 需绘制左边界 = 内部宽度
                If 需绘制右边界 < 0 Then 需绘制右边界 = 0
                If 需绘制右边界 >= 内部宽度 Then 需绘制右边界 = 内部宽度

                需绘制上边界 = Int(内部视区上边界)
                需绘制下边界 = Int(内部视区上边界 + 内部视区高度 - 1)
                If 需绘制上边界 < 0 Then 需绘制上边界 = 0
                If 需绘制上边界 >= 内部高度 Then 需绘制上边界 = 内部高度
                If 需绘制下边界 < 0 Then 需绘制下边界 = 0
                If 需绘制下边界 >= 内部高度 Then 需绘制下边界 = 内部高度

                绘制左偏移 = 需绘制左边界 - 内部视区左边界
                绘制上偏移 = 需绘制上边界 - 内部视区上边界
                Dim i As Long, j As Long
                For i = 需绘制上边界 To 需绘制下边界
                        For j = 需绘制左边界 To 需绘制右边界
                                指定表示.绘制格子 格子表(j, i), _
                                        j - 需绘制左边界 + 绘制左偏移, _
                                        i - 需绘制上边界 + 绘制上偏移, _
                                        False
                        Next
                Next

        End Sub
