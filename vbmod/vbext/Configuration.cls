VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Configuration"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Private Const LOCATION = "VBExt::Configuration"
Private Const EXTNAME = ".cfg"
Private Const DISPID_BASE = 1024

Private m_Path As String
Private m_EntryName As Map
Private m_EntryId As Map
Private m_NextId As Integer

Implements IDynamicObject

' IDynamicObject::DynamicIndex
Private Function IDynamicObject_DynamicIndex(ByVal name As String) As Long
    Dim ce
    LC.Assign ce, m_EntryName.Item(name)
    If Not IsNull(ce) Then IDynamicObject_DynamicIndex = ce.id
End Function

' IDynamicObject::DynamicInvoke
Private Function IDynamicObject_DynamicInvoke(ByVal itype As InvokeType, ByVal methodIndex As Long, parameters As Variant) As Variant
    Dim ce
    LC.Assign ce, m_EntryId.Item(methodIndex)
    G.Assert Not IsNull(ce)

    Select Case itype
    Case InvokeMethod
        ' ??
    Case InvokePropertyGet
        IDynamicObject_DynamicInvoke = ce.Value
    Case InvokePropertyPut
        ce.Value = parameters(0)
    Case InvokePropertyPutRef
        Set ce.Value = parameters(0)
    End Select
    Exit Function
NotExist:
    G.Unexpected
End Function

' Impl Utilities

Private Sub SetEntry(name, ce)
    If ce.id = 0 Then
        ce.id = m_NextId
        m_NextId = m_NextId + 1
    End If
    m_EntryName.Item(name) = ce
    m_EntryId.Item(ce.id) = ce
End Sub

Private Function RemoveEntry(name) As Boolean
    Dim ce
    LC.Assign ce, m_EntryName.Item(name)
    If Not IsNull(ce) Then
        m_EntryName.Remove name
        m_EntryId.Remove ce.id
        RemoveEntry = True
    End If
End Function

Private Sub LoadConfig(ByVal Path As String)
    Dim xmldoc As New DOMDocument
    If Not xmldoc.Load(Path & EXTNAME) Then
        Err.Raise ERR_CANT_LOAD_CONFIG, LOCATION, "无法装载配置文件: " & Path & EXTNAME
    End If

    ' /Entries/ConfigEntry
    Dim nodelist As IXMLDOMNodeList
    Set nodelist = xmldoc.selectNodes("/Entries/Entry")

    Dim i As Integer
    For i = 0 To nodelist.length - 1
        Dim node As IXMLDOMNode
        Dim name As String
        Dim type_ As TypeConstants
        Dim Value As String
        Dim j As Integer
        Dim ce

        Set node = nodelist.Item(i)
        name = Empty
        type_ = TextType
        Value = Empty
        For j = 0 To node.Attributes.length - 1
            With node.Attributes(j)
                Select Case .nodeName
                Case "Name"
                    name = .nodeValue
                Case "Type"
                    type_ = ParseType(.nodeValue)
                Case "Value"
                    Value = .nodeValue
                End Select
            End With
        Next

        If Not IsEmpty(name) Then
            Set ce = New ConfigEntry
            ce.ParseValue type_, Value
            SetEntry name, ce
        End If

        If type_ = SubType Then
            Dim subfile As String
            subfile = Path & "_" & Value
            If Not FSO.FileExists(subfile & EXTNAME) Then
                Err.Raise ERR_SUB_NOT_EXIST, LOCATION, "子配置文件 " & subfile & EXTNAME & " 不存在"
            End If
            LoadConfig subfile
        End If
    Next
End Sub

Public Property Get Path() As String
    Path = m_Path
End Property

Public Property Let Path(ByVal newpath As String)
    If Left(newpath, 2) = "::" Then
        newpath = Mid(newpath, 3)
        On Error Resume Next
    End If
    m_Path = newpath
    Reload
End Property

Public Sub Reload()
    Set m_EntryId = New Map
    Set m_EntryName = New Map
    m_NextId = DISPID_BASE

    LoadConfig m_Path
End Sub

Public Property Get Item(name)
    Dim ce
    LC.Assign ce, m_EntryName.Item(name)
    If Not IsNull(ce) Then LC.Assign Item, ce.Value
End Property

Public Property Let Item(name, Value)
    Dim ce
    LC.Assign ce, m_EntryName.Item(name)
    If IsNull(ce) Then
        Set ce = New ConfigEntry
        LC.Assign ce.Value, Value
        SetEntry name, ce
    Else
        ce.Value = Value
    End If
End Property

Public Sub Remove(ByVal name As String)
    RemoveEntry name
End Sub

Public Property Get Names() As Collection
    Set Names = m_EntryName.KeySet
End Property

Public Function Accessor() As Object
    Set Accessor = LC.ImplementDynamicObject(Me)
End Function
