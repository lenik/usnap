VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "小人物"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Event 地图位置改变()

' 简单属性
        Public 有生命 As Boolean
        Public 当前生命值 As Integer

        Public 可以移动 As Boolean
        Public 初始移动力 As Integer
        Public 当前移动力 As Integer

        Public 可以生产 As Boolean
        Public 初始生产力 As Integer
        Public 当前生产力 As Integer

        Public 可以运输 As Boolean
        Public 初始运输力 As Integer
        Public 当前运输力 As Integer


' 复杂属性
        Private 内部位于地图 As 地图
        Private 内部当前地图位置横坐标 As Integer
        Private 内部当前地图位置纵坐标 As Integer

        Public Property Get 位于地图() As 地图
                Set 位于地图 = 内部位于地图
        End Property
        Public Property Get 当前地图位置横坐标() As Long
                If 内部位于地图 Is Nothing Then
                        Err.Raise -1, , "类属地图未定义"
                Else
                        当前地图位置横坐标 = 内部当前地图位置横坐标
                End If
        End Property
        Public Property Get 当前地图位置纵坐标() As Long
                If 位于地图 Is Nothing Then
                        Err.Raise -1, , "类属地图未定义"
                Else
                        当前地图位置纵坐标 = 内部当前地图位置纵坐标
                End If
        End Property
        Public Property Let 位于地图(新地图 As 地图)
                If 新地图 Is Nothing Then
                        内部当前地图位置横坐标 = 0
                        内部当前地图位置纵坐标 = 0
                        RaiseEvent 地图位置改变
                Else
                        Set 内部位于地图 = 新地图
                        If 当前地图位置横坐标 >= 新地图.宽度 Or 当前地图位置纵坐标 >= 新地图.高度 Then
                                If 当前地图位置横坐标 >= 新地图.宽度 Then 当前地图位置横坐标 = 新地图.宽度 - 1
                                If 当前地图位置纵坐标 >= 新地图.高度 Then 当前地图位置纵坐标 = 新地图.高度 - 1
                                RaiseEvent 地图位置改变
                        End If
                End If
        End Property
        Public Property Let 当前地图位置横坐标(ByVal nX As Long)
                If 位于地图 Is Nothing Then
                        Err.Raise -1, , "类属地图未定义"
                Else
                        If 内部当前地图位置横坐标 <> nX Then
                                内部当前地图位置横坐标 = nX
                                RaiseEvent 地图位置改变
                        End If
                End If
        End Property
        Public Property Let 当前地图位置纵坐标(ByVal nY As Long)
                If 位于地图 Is Nothing Then
                        Err.Raise -1, , "类属地图未定义"
                Else
                        If 内部当前地图位置纵坐标 <> nY Then
                                内部当前地图位置纵坐标 = nY
                                RaiseEvent 地图位置改变
                        End If
                End If
        End Property
