Attribute VB_Name = "Module1"
Option Explicit

Enum qztype
        空 = 0
        白兵
        白炮
        白车
        白马
        白象
        白士
        白将
        黑兵
        黑炮
        黑车
        黑马
        黑象
        黑士
        黑将
End Enum

Public qp(1 To 10, 1 To 9) As qztype
Public qp1(1 To 10, 1 To 9) As qztype
Public qp2(1 To 10, 1 To 9) As qztype


Public 当前选手
Public 游戏模式
Public 步数

Public Sub swap(X, Y)
        Dim z
        z = X
        X = Y
        Y = z
End Sub

Public Function 白方(q As qztype) As Boolean
        If q = 白兵 Or q = 白车 Or q = 白将 Or q = 白马 Or q = 白炮 Or q = 白士 Or q = 白象 Then
                白方 = True
        Else
                白方 = False
        End If
End Function

Public Function 黑方(q As qztype) As Boolean
        If q = 黑兵 Or q = 黑车 Or q = 黑将 Or q = 黑马 Or q = 黑炮 Or q = 黑士 Or q = 黑象 Then
                黑方 = True
        Else
                黑方 = False
        End If
End Function

' 检测从(x1,y1)至(x2,y2)的移动是否合法
Public Function isvalid(x1, y1, x2, y2) As Boolean
        Dim qz1 As qztype, qz2 As qztype
        isvalid = False
        qz1 = qp(y1, x1)
        qz2 = qp(y2, x2)
        If qz1 = 空 Then Exit Function

        If 白方(qz1) And 白方(qz2) Then Exit Function
        If 黑方(qz1) And 黑方(qz2) Then Exit Function

        Select Case qz1
        Case 白兵
                ' 兵不能倒退
                If y2 > y1 Then Exit Function
                ' 在没有过河界前不能横向走
                If y1 > 5 And x2 <> x1 Then Exit Function
                ' 一次不能竖向或横向走一格以上
                If Abs(y1 - y2) > 1 Or Abs(x1 - x2) > 1 Then Exit Function
                ' 不能同时横向和竖向走
                If Abs(x1 - x2) > 0 And Abs(y1 - y2) > 0 Then Exit Function
        Case 黑兵
                If y2 < y1 Then Exit Function
                If y1 <= 5 And x2 <> x1 Then Exit Function
                If Abs(y1 - y2) > 1 Or Abs(x1 - x2) > 1 Then Exit Function
                If Abs(x1 - x2) > 0 And Abs(y1 - y2) > 0 Then Exit Function
        Case 白炮, 黑炮
                ' 炮只能走直线
                If Abs(y1 - y2) <> 0 And Abs(x1 - x2) <> 0 Then Exit Function
                ' 炮如果不吃子
                If qp(y2, x2) = 空 Then
                        ' 炮如果不吃子则不能跳子
                        If 道路阻碍数目(x1, y1, x2, y2) > 0 Then Exit Function
                Else
                        ' 炮如果吃子则必须跳一个子
                        If 道路阻碍数目(x1, y1, x2, y2) <> 1 Then Exit Function
                End If
        Case 白车, 黑车
                ' 车只能走直线
                If Abs(y1 - y2) <> 0 And Abs(x1 - x2) <> 0 Then Exit Function
                ' 车不能跳子
                If 道路阻碍数目(x1, y1, x2, y2) > 0 Then Exit Function
        Case 白马, 黑马
                ' 马只能走日
                If Abs(x1 - x2) = 2 And Abs(y1 - y2) = 1 Then
                ElseIf Abs(x1 - x2) = 1 And Abs(y1 - y2) = 2 Then
                Else
                        Exit Function
                End If
                ' 马走日先一竖再一斜,再竖向上不能有棋子
                If Abs(x1 - x2) > Abs(y1 - y2) Then
                        ' 如果是横向的日
                        If qp(y1, (x1 + x2) / 2) <> 空 Then Exit Function
                Else
                        ' 如果是竖向的日
                        If qp((y1 + y2) / 2, x1) <> 空 Then Exit Function
                End If
        Case 白象
                ' 象只能走田
                If Abs(x1 - x2) <> 2 Or Abs(y1 - y2) <> 2 Then Exit Function
                ' 象不能跳子
                If 道路阻碍数目(x1, y1, x2, y2) > 0 Then Exit Function
                ' 象只能在棋盘的一半部分活动
                If y2 < 6 Then Exit Function
        Case 黑象
                If Abs(x1 - x2) <> 2 Or Abs(y1 - y2) <> 2 Then Exit Function
                If 道路阻碍数目(x1, y1, x2, y2) > 0 Then Exit Function
                If y2 > 5 Then Exit Function
        Case 白士
                ' 士只能走一格斜线
                If Abs(x1 - x2) <> 1 Or Abs(y1 - y2) <> 1 Then Exit Function
                ' 士只能在3x3的格子中走
                If x2 < 4 Or x2 > 6 Or y2 < 8 Then Exit Function
        Case 黑士
                If Abs(x1 - x2) <> 1 Or Abs(y1 - y2) <> 1 Then Exit Function
                If x2 < 4 Or x2 > 6 Or y2 > 3 Then Exit Function
        Case 白将
                ' 将只能走一格直线
                If Abs(x1 - x2) = 1 And Abs(y1 - y2) = 0 Then
                ElseIf Abs(x1 - x2) = 0 And Abs(y1 - y2) = 1 Then
                Else
                        Exit Function
                End If
                ' 将只能在3x3的格子中走
                If x2 < 4 Or x2 > 6 Or y2 < 8 Then Exit Function
        Case 黑将
                If Abs(x1 - x2) = 1 And Abs(y1 - y2) = 0 Then
                ElseIf Abs(x1 - x2) = 0 And Abs(y1 - y2) = 1 Then
                Else
                        Exit Function
                End If
                If x2 < 4 Or x2 > 6 Or y2 > 3 Then Exit Function
        End Select

        isvalid = True
End Function

Public Function 道路阻碍数目(ByVal x1, ByVal y1, ByVal x2, ByVal y2) As Long
        Dim X, Y

        道路阻碍数目 = 0

        If x1 = x2 And y1 <> y2 Then
                ' 竖相
                If y1 > y2 Then swap y1, y2
                For Y = y1 + 1 To y2 - 1
                        If qp(Y, x1) <> 空 Then 道路阻碍数目 = 道路阻碍数目 + 1
                Next
        ElseIf x1 <> x2 And y1 = y2 Then
                ' 横向
                If x1 > x2 Then swap x1, x2
                For X = x1 + 1 To x2 - 1
                        If qp(y1, X) <> 空 Then 道路阻碍数目 = 道路阻碍数目 + 1
                Next
        Else
                ' 斜线
                For X = x1 To x2 Step Sgn(x2 - x1)
                        Y = Int((y2 - y1) / (x2 - x1) * X + (y1 * x2 - y2 * x1) / (x2 - x1))
                        If qp(Y, X) <> 空 Then 道路阻碍数目 = 道路阻碍数目 + 1
                Next
                If qp(y1, x1) <> 空 Then 道路阻碍数目 = 道路阻碍数目 - 1
                If qp(y2, x2) <> 空 Then 道路阻碍数目 = 道路阻碍数目 - 1
        End If
End Function

Public Sub init()
        Dim X, Y
        For Y = 1 To 10
                For X = 1 To 9
                        qp(Y, X) = 空
                Next
        Next
        qp(10, 1) = 白车
        qp(10, 2) = 白马
        qp(10, 3) = 白象
        qp(10, 4) = 白士
        qp(10, 5) = 白将
        qp(10, 6) = 白士
        qp(10, 7) = 白象
        qp(10, 8) = 白马
        qp(10, 9) = 白车
        qp(8, 2) = 白炮
        qp(8, 8) = 白炮
        qp(7, 1) = 白兵
        qp(7, 3) = 白兵
        qp(7, 5) = 白兵
        qp(7, 7) = 白兵
        qp(7, 9) = 白兵

        qp(1, 1) = 黑车
        qp(1, 2) = 黑马
        qp(1, 3) = 黑象
        qp(1, 4) = 黑士
        qp(1, 5) = 黑将
        qp(1, 6) = 黑士
        qp(1, 7) = 黑象
        qp(1, 8) = 黑马
        qp(1, 9) = 黑车
        qp(3, 2) = 黑炮
        qp(3, 8) = 黑炮
        qp(4, 1) = 黑兵
        qp(4, 3) = 黑兵
        qp(4, 5) = 黑兵
        qp(4, 7) = 黑兵
        qp(4, 9) = 黑兵
End Sub
