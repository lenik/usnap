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
Private m_EntryId As Collection
Private m_EntryName As Collection
Private m_NextId As Integer

Private LC As New LowXRuntime.Component
Private FSO As New Scripting.FileSystemObject

Implements IDynamicObject

' IDynamicObject::DynamicIndex
Private Function IDynamicObject_DynamicIndex(ByVal name As String) As Long
    Dim ent As Entry
    IDynamicObject_DynamicIndex = 0
    On Error GoTo notexist
    Set ent = m_EntryName(name)
    If Not ent Is Nothing Then
        IDynamicObject_DynamicIndex = ent.id
    End If
notexist:
End Function

' IDynamicObject::DynamicInvoke
Private Function IDynamicObject_DynamicInvoke(ByVal itype As InvokeType, ByVal methodIndex As Long, parameters As Variant) As Variant
    On Error GoTo notexist

    Dim ent As Entry
    Set ent = m_EntryId(CStr(methodIndex))
    G.Assert Not ent Is Nothing

    Select Case itype
    Case InvokeMethod
    Case InvokePropertyGet
        IDynamicObject_DynamicInvoke = ent.value
    Case InvokePropertyPut
        ent.value = parameters(0)
    Case InvokePropertyPutRef
        Set ent.value = parameters(0)
    End Select
    Exit Function
notexist:
    G.Unexpected
End Function

' Impl Utilities

Private Sub SetEntry(ent As Entry)
    On Error GoTo AddNew
    Set m_EntryId(CStr(ent.id)) = ent
    Set m_EntryName(ent.name) = ent
    Exit Sub
AddNew:
    ent.id = m_NextId
    m_NextId = m_NextId + 1
    m_EntryId.Add ent, CStr(ent.id)
    m_EntryName.Add ent, ent.name
End Sub

Private Sub RemoveEntry(ent As Entry)
    On Error Resume Next
    m_EntryId.Remove CStr(ent.id)
    m_EntryName.Remove ent.name
End Sub

Private Sub LoadConfig(ByVal Path As String)
    Dim xmldoc As New DOMDocument
    If Not xmldoc.Load(Path & EXTNAME) Then
        Err.Raise ERR_CANT_LOAD_CONFIG, LOCATION, "无法装载配置文件: " & Path & EXTNAME
    End If

    ' /Entries/Entry
    Dim nodelist As IXMLDOMNodeList
    Set nodelist = xmldoc.selectNodes("/Entries/Entry")

    Dim i As Integer
    For i = 0 To nodelist.length - 1
        Dim node As IXMLDOMNode
        Dim name As String
        Dim type_ As TypeConstants
        Dim value As String
        Dim j As Integer
        Dim ent As New Entry

        Set node = nodelist.Item(i)
        name = Empty
        type_ = TextType
        value = Empty
        For j = 0 To node.Attributes.length - 1
            With node.Attributes(j)
                Select Case .nodeName
                Case "Name"
                    name = .nodeValue
                Case "Type"
                    type_ = ParseType(.nodeValue)
                Case "Value"
                    value = .nodeValue
                End Select
            End With
        Next

        If Not IsEmpty(name) Then
            Set ent = New Entry
            ent.name = name
            ent.type_ = type_
            ent.ParseValue value
            SetEntry ent
        End If

        If type_ = SubType Then
            Dim subfile As String
            subfile = Path & "_" & value
            If Not FSO.FileExists(subfile & EXTNAME) Then
                Err.Raise ERR_SUB_NOT_EXIST, LOCATION, "子配置文件 " & subfile & EXTNAME & " 不存在"
            End If
            LoadConfig subfile
        End If
    Next
End Sub

' Public

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
    Set m_EntryId = New Collection
    Set m_EntryName = New Collection
    m_NextId = DISPID_BASE

    LoadConfig m_Path
End Sub

Public Property Get Item(name)
    On Error GoTo notexist
    Dim ent As Entry
    Set ent = m_EntryName(name)
    If Not ent Is Nothing Then Item = ent.value
notexist:
End Property

Public Property Let Item(name, value)
    On Error GoTo notexist
    Dim ent As Entry
    Set ent = m_EntryName(name)
    ent.value = value
    Exit Property

notexist:
    Set ent = New Entry
    ent.name = name
    ent.type_ = TextType
    ent.value = value
    SetEntry ent
End Property

Public Sub Remove(ByVal name As String)
    On Error GoTo notexist
    Dim ent As Entry
    Set ent = m_EntryName(name)
    If Not ent Is Nothing Then RemoveEntry ent
notexist:
End Sub

Public Property Get Names() As Collection
    Dim ent As Entry
    Set Names = New Collection
    For Each ent In m_EntryId
        Names.Add ent.name
    Next
End Property

Public Function Accessor() As Object
    Set Accessor = LC.ImplementDynamicObject(Me)
End Function
