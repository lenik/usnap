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
Private m_Id As Long

' Entry type: string, sub, file, etc.
Private m_Type As Integer

' Belongs to which section
Private m_Section As String

' Entry Value
Private m_Value As Variant


Sub InitEntry(ByVal Id As Long, ByVal Section As String)
    m_Id = Id
    m_Section = Section
End Sub

Public Sub ParseValue(ByVal Type_, ByVal valstr As Variant)
    m_Type = Type_
    LC.Assign m_Value, valstr
End Sub

Public Property Get Id() As Long
    Id = m_Id
End Property

Public Property Let Id(ByVal newval As Long)
    m_Id = newval
End Property

Public Property Get Type_() As Integer
    Type_ = m_Type
End Property

Public Property Get Section() As String
    Section = m_Section
End Property

Public Property Get Value() As Variant
Attribute Value.VB_UserMemId = 0
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
