Attribute VB_Name = "modGraph"
Option Explicit

' 直线, 矩形和圆的后端分散转换算法
'
'       图像变形是图形转换中的一种技术。
'       计算机图形转换从处理方法上可以分为两种, 一种是前端转换,
'           前端转换是指在图像的点阵坐标尚未生成之前就已经被转换,
'           比如说对直线的旋转转换, 通过对直线方程f1进行旋转变换
'           后生成直线方程f2。另一种是后端转换, 后端转换是指在图
'           像点阵坐标已知的情况下对图像进行转换。比如对图像M 旋
'           转, 可以将图像M 中各点乘以旋转矩阵。
'       大多数情况下计算机图形转换可以认为是后端转换。并不是所有
'           的描述图像的方程都可以进行前端转换的。图像变形总是后
'           端转换。
'       控制点变形是图像变形中的一种技术。它根据两幅图像中的关联
'           控制点的位置关系进行插值运算, 最后生成变形动画。
'       分散转换是谢继雷提出的一种控制点变形算法, 它略去了邻近像
'           素的跟踪处理因而极大简化了实现方法。分散转换不要求两
'           幅图像具有相同数目的控制点。

' 图像对象接口
        Public pic As PictureBox

' 图像显示数据
        Type POINT
                X As Double
                Y As Double
        End Type
        Type POINTR             ' 关联点
                Pr As Integer   ' 关联点索引
                Po As Integer   ' 被关联点索引
        End Type

        Public sStep As Double  ' 插值间隔

' 分散转换
        ' 欧几里德距离
        Private Function Edistance(a As POINT, b As POINT) As Double
                Edistance = Sqr((b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y))
        End Function
        ' 分散转换
        '       fromNodes()     源图像控制点
        '       nFromNodes      源图像控制点数
        '       toNodes()       目标图像控制点
        '       nToNodes        目标图像控制点数
        Public Function RTrans(fromNodes() As POINT, _
                          ByVal nFromNodes As Integer, _
                          toNodes() As POINT, _
                          ByVal nToNodes As Integer) As Boolean
                Dim rTable(0 To 255) As POINTR, rUsed As Integer        ' 关联表
                Dim i As Integer, ii As Integer, iii As Integer         ' 循环变量
                Dim s As Double, sNear As Double, sNearI As Integer     ' 用于找出最近距离
                Dim bExisted As Boolean
                Dim Pr As POINT, Po As POINT, Plast As POINT
                Dim slider As Double                                    ' 插值点(定义域: [0,1])

                RTrans = False
                If nFromNodes < 0 Or nFromNodes > 255 Then Exit Function
                If nToNodes < 0 Or nToNodes > 255 Then Exit Function

                ' 构造关联表
                rUsed = 0
                        ' 1. 找出离目标控制点最近的源控制点
                        For i = 0 To nToNodes - 1
                                rTable(rUsed).Pr = i
                                rTable(rUsed).Po = -1
                                sNear = -1
                                For ii = 0 To nFromNodes - 1
                                        s = Edistance(fromNodes(ii), toNodes(i))
                                        If s < sNear Or sNear < 0 Then
                                                sNear = s
                                                sNearI = ii
                                        End If
                                Next
                                If sNear >= 0 Then rTable(rUsed).Po = sNearI
                                rUsed = rUsed + 1
                        Next
                        ' 2. 找出多余的源控制点对应的离源控制点最近的目标控制点
                        For i = 0 To nFromNodes - 1
                                bExisted = False
                                For ii = 0 To rUsed - 1
                                        If rTable(ii).Po = i Then
                                                bExisted = True
                                                Exit For
                                        End If
                                Next
                                If Not bExisted Then
                                        rTable(rUsed).Po = i
                                        rTable(rUsed).Pr = -1
                                        sNear = -1
                                        For ii = 0 To nToNodes - 1
                                                s = Edistance(fromNodes(i), toNodes(ii))
                                                If s < sNear Or sNear < 0 Then
                                                        sNear = s
                                                        sNearI = ii
                                                End If
                                        Next
                                        If sNear >= 0 Then rTable(rUsed).Pr = sNearI
                                        rUsed = rUsed + 1
                                End If
                        Next
                ' 插值运算
                        slider = 0
                        Do While slider <= 1.001
                                pic.Cls
                                For i = 0 To rUsed
                                        Pr = toNodes(rTable(i Mod rUsed).Pr)
                                        Po = fromNodes(rTable(i Mod rUsed).Po)
                                        Pr.X = slider * Pr.X + (1 - slider) * Po.X
                                        Pr.Y = slider * Pr.Y + (1 - slider) * Po.Y
                                        If i = 0 Then
                                                pic.PSet (Pr.X, Pr.Y)
                                        Else
                                                pic.Line (Plast.X, Plast.Y)-(Pr.X, Pr.Y)
                                        End If
                                        Plast = Pr
                                Next
                                pic.Refresh
                                DoEvents
                                slider = slider + IIf(sStep <= 0.001, 0.001, sStep)
                        Loop
        End Function
