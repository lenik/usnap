VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "地图范围"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private 格子类型表(0 To 最大宽 - 1, 0 To 最大高 - 1) As 格子类型
Private 动态格子表(0 To 最大宽 - 1, 0 To 最大高 - 1) As New 动态格子

Private 内部范围边界宽 As Long, 内部范围边界高 As Long
Private 内部中心横坐标 As Long, 内部中心纵坐标 As Long

Public Property Get 范围边界宽() As Long
        范围边界宽 = 内部范围边界宽
End Property
Public Property Get 范围边界高() As Long
        范围边界高 = 内部范围边界高
End Property
Public Property Let 范围边界宽(ByVal nw As Long)
        If nw >= 0 And nw <= 最大宽 Then
                内部范围边界宽 = nw
        Else
                Err.Raise -1, , "宽度超出最大值: " & 最大宽
        End If
End Property
Public Property Let 范围边界高(ByVal nh As Long)
        If nh >= 0 And nh <= 最大高 Then
                内部范围边界高 = nh
        Else
                Err.Raise -1, , "高度超出最大值: " & 最大高
        End If
End Property

Public Property Get 范围左边界() As Long
        范围左边界 = -内部中心横坐标
End Property
Public Property Get 范围右边界() As Long
        范围右边界 = (内部范围边界宽 - 1) - 内部中心横坐标
End Property
Public Property Get 范围上边界() As Long
        范围上边界 = -内部中心纵坐标
End Property
Public Property Get 范围下边界() As Long
        范围下边界 = (内部范围边界高 - 1) - 内部中心纵坐标
End Property

Public Property Get 中心横坐标() As Long
        中心横坐标 = 内部中心横坐标
End Property
Public Property Get 中心纵坐标() As Long
        中心纵坐标 = 内部中心纵坐标
End Property
Public Property Let 中心横坐标(ByVal nX As Long)
        If nX >= 0 And nX < 内部范围边界宽 Then
                内部中心横坐标 = nX
        Else
                Err.Raise -2, , "中心坐标不再范围边界内"
        End If
End Property
Public Property Let 中心纵坐标(ByVal nY As Long)
        If nY >= 0 And nY < 内部范围边界高 Then
                内部中心纵坐标 = nY
        Else
                Err.Raise -2, , "中心坐标不再范围边界内"
        End If
End Property

Public Property Get 格子类型(ByVal x As Long, ByVal y As Long) As 格子类型
        Dim sx As Long, sy As Long
        sx = 中心横坐标 + x
        sy = 中心纵坐标 + y
        If sx < 0 Or sx >= 范围边界宽 Or sy < 0 Or sy >= 范围边界高 Then
                Err.Raise -1, , "格子坐标出界"
        Else
                格子类型 = 格子类型表(sx, sy)
        End If
End Property
Public Property Let 格子类型(ByVal x As Long, ByVal y As Long, ByVal 新格子类型 As 格子类型)
        Dim sx As Long, sy As Long
        sx = 中心横坐标 + x
        sy = 中心纵坐标 + y
        If sx < 0 Or sx >= 范围边界宽 Or sy < 0 Or sy >= 范围边界高 Then
                Err.Raise -1, , "格子坐标出界"
        Else
                格子类型表(sx, sy) = 新格子类型
        End If
End Property

Public Sub 设置全部格子类型(ByVal 新格子类型 As 格子类型)
        Dim x As Long, y As Long
        For x = 0 To 内部范围边界宽 - 1
                For y = 0 To 内部范围边界高 - 1
                        格子类型表(x, y) = 新格子类型
                Next
        Next
End Sub

Public Property Get 动态格子(ByVal x As Long, ByVal y As Long) As 动态格子
        Dim sx As Long, sy As Long
        sx = 中心横坐标 + x
        sy = 中心纵坐标 + y
        If sx < 0 Or sx >= 范围边界宽 Or sy < 0 Or sy >= 范围边界高 Then
                Err.Raise -1, , "格子坐标出界"
        Else
                Set 动态格子 = 动态格子表(sx, sy)
        End If
End Property

Public Property Get 可栖息(ByVal x As Long, ByVal y As Long) As Boolean
        Dim sx As Long, sy As Long
        sx = 中心横坐标 + x
        sy = 中心纵坐标 + y
        可栖息 = 已定义地图格子(格子类型表(sx, sy)).可栖息
End Property
Public Property Get 可行走(ByVal x As Long, ByVal y As Long) As Boolean
        Dim sx As Long, sy As Long
        sx = 中心横坐标 + x
        sy = 中心纵坐标 + y
        可行走 = 已定义地图格子(格子类型表(sx, sy)).可行走
End Property
Public Property Get 可扎营(ByVal x As Long, ByVal y As Long) As Boolean
        Dim sx As Long, sy As Long
        sx = 中心横坐标 + x
        sy = 中心纵坐标 + y
        可扎营 = 已定义地图格子(格子类型表(sx, sy)).可扎营
End Property
Public Property Get 消耗移动力(ByVal x As Long, ByVal y As Long) As Boolean
        Dim sx As Long, sy As Long
        sx = 中心横坐标 + x
        sy = 中心纵坐标 + y
        消耗移动力 = 已定义地图格子(格子类型表(sx, sy)).消耗移动力
End Property

Public Function 预制范围特征(ByVal 范围宽度 As Long, ByVal 范围高度 As Long, ByVal 特征描述_使用ai字串 As String) As Boolean
        预制范围特征 = False
        On Error GoTo er
        范围边界宽 = 范围宽度
        范围边界高 = 范围高度

        ReDim t(0 To 范围宽度 - 1, 0 To 范围高度 - 1) As Integer
        Dim at As New LowXTool.Array
        at.InitArray2i t, 特征描述_使用ai字串

        预制范围特征 = True
        Exit Function
er:
        Err.Raise Err.Number, Err.Source, Err.Description
End Function
