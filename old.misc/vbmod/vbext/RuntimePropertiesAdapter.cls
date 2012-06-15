VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "RuntimePropertiesAdapter"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "VBExt::RuntimePropertiesAdapter"

Private m_RecentUsedHashes As New Map
Private m_Impl As RuntimeProperties

Implements IDynamicObject

Private Function Hashcode(ByVal str As String) As Long
    Hashcode = Variants.Hashcode(str)
End Function

Private Function IDynamicObject_DynamicIndex(ByVal name As String) As Long
    IDynamicObject_DynamicIndex = Hashcode(name)
    m_RecentUsedHashes(IDynamicObject_DynamicIndex) = name
End Function

Private Function IDynamicObject_DynamicInvoke(ByVal Type_ As LowXRuntime.InvokeType, ByVal methodIndex As Long, parameters As Variant) As Variant
    Dim name As String
    name = m_RecentUsedHashes(methodIndex)

    Assert name <> "", "Invalid index/hash: " & methodIndex, LOCATION

    If Type_ = InvokePropertyGet Then
        IDynamicObject_DynamicInvoke = m_Impl.Item(name)
    ElseIf Type_ = InvokePropertyPut Then
        m_Impl.Item(name) = parameters(LBound(parameters))
    ElseIf Type_ = InvokePropertyPutRef Then
        Set m_Impl.Item(name) = parameters(LBound(parameters))
    Else
        Unexpected "Unsupported operation", LOCATION
    End If
End Function
