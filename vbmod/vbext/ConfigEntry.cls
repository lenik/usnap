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
Private m_Type As String

' Belongs to which section
Private m_Section As String

' Entry Value
Private m_Value As Variant

' Variable Map
Private m_VarMap As Map

Sub InitEntry(ByVal Id As Long, ByVal Section As String, ByVal VarMap As Map)
    m_Id = Id
    m_Section = Section
    Set m_VarMap = VarMap
End Sub

Public Sub ParseValue(ByVal elm As IXMLDOMElement, ByVal vtype As String)
    Dim val As String
    Dim param As String
    Dim ParamMap As Map

    val = elm.getAttribute("Value")

    Select Case vtype
    Case "path"
        val = FSO.BuildPath(g_Configuration.HomeDirectory, val)
        val = FSO.GetAbsolutePathName(val)
        m_Value = val
    Case "sub"
        m_Value = val
    Case "runtime"
        ' provider= param="ident=" value=
        Dim providercls As String
        Dim provider As RuntimeEntryProvider
        providercls = elm.getAttribute("Provider")
        param = elm.getAttribute("Param")
        Set ParamMap = ParseMap(param)
        Set provider = CreateObject(providercls)
        provider.Initialize ParamMap, val
        Set m_Value = provider
    Case Else
        ' string
        m_Value = val
    End Select
    m_Type = vtype
End Sub

Public Property Get Id() As Long
    Id = m_Id
End Property

Public Property Let Id(ByVal newval As Long)
    m_Id = newval
End Property

Public Property Get Type_() As String
    Type_ = m_Type
End Property

Public Property Get Section() As String
    Section = m_Section
End Property

Public Property Get Value() As Variant
    If IsObject(Value) Then
        ' Is Dynamic Property?
        ' <EXT...>
        Exit Property
    End If
    If VarType(m_Value) = vbString Then
        Value = VarEvalMap(m_Value, m_VarMap)
    Else
        LC.Assign Value, m_Value
    End If
End Property

Public Property Let Value(ByVal newval As Variant)
    LC.Assign m_Value, newval
End Property

Public Property Set Value(ByVal newval As Variant)
    Set m_Value = newval
End Property
