VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "StrongReference"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Ref As New Collection

Implements Reference

Private Property Let Reference_Ref(ByVal Name As String, ByVal RHS As Object)

End Property

Private Property Get Reference_Ref(ByVal Name As String) As Object

End Property

Private Sub Reference_Collect()

End Sub