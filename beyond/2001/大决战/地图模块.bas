Attribute VB_Name = "地图模块"
Option Explicit

Public Enum 格子类型
        未定义 = 0
        平地
        草地
        山丘
        湖泊
End Enum

Public Const 最大宽 = 256
Public Const 最大高 = 128

Private Const 最大分配地图格子数 As Integer = 1024
Public 已定义地图格子数 As Integer
Public 已定义地图格子(0 To 最大分配地图格子数 - 1) As New 地图格子
Private 已初始化地图格子 As Boolean

Public 主地图 As 地图

Public Sub 初始化地图格子()
        With 已定义地图格子(未定义)
                .可栖息 = False
                .可行走 = False
                .可扎营 = False
                .消耗移动力 = -1
        End With
        With 已定义地图格子(平地)
                .可栖息 = True
                .可行走 = True
                .可扎营 = True
                .消耗移动力 = 1
        End With
        With 已定义地图格子(草地)
                .可栖息 = True
                .可行走 = True
                .可扎营 = False
                .消耗移动力 = 2
        End With
        With 已定义地图格子(山丘)
                .可栖息 = False
                .可行走 = True
                .可扎营 = False
                .消耗移动力 = 3
        End With
        With 已定义地图格子(湖泊)
                .可栖息 = False
                .可行走 = False
                .可扎营 = False
                .消耗移动力 = 1
        End With
        已定义地图格子数 = 4
End Sub
Public Property Get 格子类(ByVal 格子类型 As 格子类型) As 地图格子
        If Not 已初始化地图格子 Then
                初始化地图格子
                已初始化地图格子 = True
        End If
        Set 格子类 = 已定义地图格子(格子类型)
End Property
