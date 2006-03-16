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

Private m_Name As String
Private m_HomeDirectory As String
Private m_EntryName As Map
Private m_EntryId As Map
Private m_NextId As Integer

Implements IDynamicObject

' IDynamicObject::DynamicIndex
Private Function IDynamicObject_DynamicIndex(ByVal Name As String) As Long
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If Not IsNull(ce) Then IDynamicObject_DynamicIndex = ce.Id
End Function

' IDynamicObject::DynamicInvoke
Private Function IDynamicObject_DynamicInvoke(ByVal itype As InvokeType, ByVal methodIndex As Long, parameters As Variant) As Variant
    Dim ce
    LC.Assign ce, m_EntryId(methodIndex)
    Assert Not IsNull(ce)

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
    Unexpected
End Function

' Impl Utilities

Private Sub SetEntry(Name, ce)
    If ce.Id = 0 Then
        ce.Id = m_NextId
        m_NextId = m_NextId + 1
    End If
    m_EntryName(Name) = ce
    m_EntryId(ce.Id) = ce
End Sub

Private Function RemoveEntry(Name) As Boolean
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If Not IsNull(ce) Then
        m_EntryName.Remove Name
        m_EntryId.Remove ce.Id
        RemoveEntry = True
    End If
End Function

Private Function AbsolutePath(ByVal path As String) As String
    AbsolutePath = m_HomeDirectory & "\" & m_Name & path & EXTNAME
End Function

Private Sub LoadConfig(ByVal Section As String)
    Dim path As String
    Dim xmldoc As New DOMDocument

    path = AbsolutePath(Section)
    If Not xmldoc.Load(path) Then
        Err.Raise ERR_CANT_LOAD_CONFIG, LOCATION, "无法装载配置文件: " & path
    End If

    ' /Entries/ConfigEntry
    Dim nodelist As IXMLDOMNodeList
    Set nodelist = xmldoc.selectNodes("/Entries/Entry")

    Dim i As Integer
    For i = 0 To nodelist.length - 1
        Dim Node As IXMLDOMNode
        Dim Name As String
        Dim Type_ As TypeConstants
        Dim Value As String
        Dim j As Integer
        Dim ce

        Set Node = nodelist(i)
        Name = Empty
        Type_ = TextType
        Value = Empty
        For j = 0 To Node.Attributes.length - 1
            With Node.Attributes(j)
                Select Case .nodeName
                Case "Name"
                    Name = .nodeValue
                Case "Type"
                    Type_ = ParseType(.nodeValue)
                Case "Value"
                    Value = .nodeValue
                End Select
            End With
        Next

        If Not IsEmpty(Name) Then
            Set ce = New ConfigEntry
            ce.ParseValue Type_, Value
            ce.Section = Section
            SetEntry Name, ce
        End If

        If Type_ = SubType Then
            Dim SubSection As String
            Dim SubPath As String
            SubSection = Section & "_" & Value
            SubPath = AbsolutePath(SubSection)
            If Not FSO.FileExists(SubPath) Then
                Err.Raise ERR_SUB_NOT_EXIST, LOCATION, "子配置文件 " & SubPath & " 不存在"
            End If
            LoadConfig SubSection
        End If
    Next
End Sub

Public Property Get Name() As String
    Name = m_Name
End Property

Property Let Name(ByVal newName As String)
    m_Name = newName
End Property

Public Property Get HomeDirectory() As String
    HomeDirectory = m_HomeDirectory
End Property

Public Property Let HomeDirectory(ByVal newHome As String)
    If Left(newHome, 2) = "::" Then
        newHome = Mid(newHome, 3)
        On Error Resume Next
    End If
    m_HomeDirectory = newHome
    Reload
End Property

Public Sub Reload()
    Set m_EntryId = New Map
    Set m_EntryName = New Map
    m_NextId = DISPID_BASE

    LoadConfig ""
End Sub

Public Property Get Item(Name)
Attribute Item.VB_UserMemId = 0
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If Not IsNull(ce) Then LC.Assign Item, ce.Value
End Property

Public Property Let Item(Name, Value)
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If IsNull(ce) Then
        Set ce = New ConfigEntry
        LC.Assign ce.Value, Value
        SetEntry Name, ce
    Else
        ce.Value = Value
    End If
End Property

Public Sub Remove(ByVal Name As String)
    RemoveEntry Name
End Sub

Public Property Get Attributes() As Collection
    Set Attributes = m_EntryName.KeySet
End Property

Public Function Accessor() As Object
    Set Accessor = LC.ImplementDynamicObject(Me)
End Function
