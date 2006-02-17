VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ViewObjectAdapter"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION = "MVCArch::PlainObjectAdapter"

Private m_PO As Object
Private m_Dirty As Boolean

Implements IDynamicObject

Private Function IDynamicObject_DynamicIndex(ByVal name As String) As Long

End Function

Private Function IDynamicObject_DynamicInvoke(ByVal itype As LowXRuntime.InvokeType, ByVal methodIndex As Long, Parameters As Variant) As Variant

End Function
