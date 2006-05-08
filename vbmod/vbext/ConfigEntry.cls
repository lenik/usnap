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

Public Enum ConfigEntryTypeConstants
    cetText = 0
    cetFile
    cetSub
End Enum

' Id/Name mappnig
Private m_Id As Long

' Entry type: string, sub, file, etc.
Private m_Type As ConfigEntryTypeConstants

' Belongs to which section
Private m_Section As String

' Entry Value
Private m_Value As Variant


Sub InitEntry(ByVal Id As Long, ByVal Section As String)
    m_Id = Id
    m_Section = Section
End Sub

Public Sub ParseValue(ByVal Type_ As ConfigEntryTypeConstants, ByVal valstr As Variant)
    Select Case Type_
    Case cetText
        '
    Case cetFile
        valstr = FSO.BuildPath(g_Configuration.HomeDirectory, valstr)
        valstr = FSO.GetAbsolutePathName(valstr)
    Case cetSub
        '
    End Select
    m_Type = Type_
    LC.Assign m_Value, valstr
End Sub

Public Property Get Id() As Long
    Id = m_Id
End Property

Public Property Let Id(ByVal newval As Long)
    m_Id = newval
End Property

Public Property Get Type_() As ConfigEntryTypeConstants
    Type_ = m_Type
End Property

Public Property Get Section() As String
    Section = m_Section
End Property

Public Property Get value() As Variant
Attribute value.VB_UserMemId = 0
    If IsObject(value) Then
        ' Is Dynamic Property?
        ' <EXT...>
        Exit Property
    End If
    LC.Assign value, m_Value
End Property

Public Property Let value(ByVal newval As Variant)
    LC.Assign m_Value, newval
End Property
