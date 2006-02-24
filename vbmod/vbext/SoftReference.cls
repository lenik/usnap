VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SoftReference"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Ref As New Map

Implements Reference

Private Property Let Reference_Ref(ByVal Name As String, ByVal rhs As Object)
    m_Ref(Name) = rhs
End Property

Private Property Get Reference_Ref(ByVal Name As String) As Object
    Dim v
    LC.Assign v, m_Ref(Name)
    If Not IsNull(v) Then
        Set Reference_Ref = v
    End If
End Property

Private Sub Reference_Collect()
    Set m_Ref = New Map
End Sub
