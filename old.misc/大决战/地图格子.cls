VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "地图格子"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public 消耗移动力 As Integer

Public 可栖息 As Boolean
Public 可行走 As Boolean
Public 可扎营 As Boolean

' 显示界面
Public 图片 As String
Public Property Get hDC() As Long

End Property
