VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ConfigEntry"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

' Id/Name mappnig
Public Id As Long

' Entry type: string, sub, file, etc.
Public Type_ As Integer

' Belongs to which section
Public Section As String

' Value
Private m_Value As Variant


Public Sub ParseValue(ByVal Type_, ByVal valstr As Variant)
    Me.Type_ = Type_
    LC.Assign Value, valstr
End Sub

Public Property Get Value() As Variant
    If IsObject(Value) Then
        ' Is Dynamic Property?
        ' <EXT...>
        Exit Property
    End If
    LC.Assign Value, m_Value
End Property

Public Property Let Value(ByVal newval As Variant)
    LC.Assign m_Value, newval
End Property
