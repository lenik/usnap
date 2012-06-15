VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "动态格子"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public 关联数据 As Variant

Public Property Get 数据_消耗移动力() As Long
        数据_消耗移动力 = CLng(关联数据)
End Property
Public Property Let 数据_消耗移动力(ByVal np As Long)
        关联数据 = np
End Property

Private Sub Class_Initialize()
        关联数据 = 0
End Sub
