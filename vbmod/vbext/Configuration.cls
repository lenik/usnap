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
Private Const DISPID_BASE = 10001

Private m_Accessor As Object
Private m_Name As String
Private m_HomeDir As String

' Name => ConfigEntry
Private m_EntryName As New Map

' Id => ConfigEntry
Private m_EntryId As New Map

Private m_NextId As Integer

Private m_TempDir As String

Implements IDynamicObject
Implements Map

Private Sub Class_Initialize()
    Dim tempdir As String * 1000
    Dim l As Long
    l = GetTempPath(1000, tempdir)
    TemporaryDirectory = Left(tempdir, l)
End Sub

Public Property Get TemporaryDirectory() As String
    TemporaryDirectory = m_TempDir
End Property

Public Property Let TemporaryDirectory(ByVal newval As String)
    If Right(newval, 1) = "\" Or Right(newval, 1) = "/" Then
        newval = Left(newval, Len(newval) - 1)
    End If
    m_TempDir = newval
End Property

Public Function TemporaryPath(Optional ByVal Prefix As String) As String
    Dim tempfn As String * 1000
    Dim l As Long
    l = GetTempFileName(m_TempDir, Prefix, 0, tempfn)
    l = InStr(tempfn, Chr(0))
    If l > 0 Then
        TemporaryPath = Left(tempfn, l - 1)
    Else
        TemporaryPath = tempfn
    End If
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

Private Function AbsolutePath(ByVal SectionPath As String) As String
    AbsolutePath = m_HomeDir & "\" & m_Name & SectionPath & EXTNAME
End Function

Private Sub LoadConfig(ByVal Section As String)
    Dim path As String
    Dim xmldoc As New DOMDocument

    path = AbsolutePath(Section)
    If Not xmldoc.Load(path) Then
        Err.Raise ERR_CANT_LOAD_CONFIG, LOCATION, _
            "无法装载配置文件: " & path & vbNewLine _
            & xmldoc.parseError.reason
    End If

    ' /Entries/ConfigEntry
    Dim entrylist As IXMLDOMNodeList
    Set entrylist = xmldoc.selectNodes("/Entries/Entry")

    Dim i As Integer
    For i = 0 To entrylist.length - 1
        Dim elm As IXMLDOMElement
        Dim Name As String
        Dim vtype As String
        Dim j As Integer
        Dim ce As ConfigEntry

        Set elm = entrylist(i)
        Name = elm.getAttribute("Name")
        Assert Name <> "", "Entry/@Name hasn'vtype specified", LOCATION

        vtype = LCase(FC.StringOf(elm.getAttribute("Type")))
        'Assert vtype = Trim(vtype)

        Set ce = New ConfigEntry
        ce.ParseValue elm, vtype
        ce.InitEntry 0, Section, Me
        SetEntry Name, ce

        If vtype = "sub" Then
            Dim SubSection As String
            Dim SubPath As String
            SubSection = Section & "_" & ce.Value
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
    HomeDirectory = m_HomeDir
End Property

Public Property Let HomeDirectory(ByVal newHome As String)
    m_HomeDir = newHome
End Property

Public Sub Reload(Optional ByVal IgnoreErrors As Boolean = False)
    Map_Clear

    If IgnoreErrors Then On Error Resume Next
    LoadConfig ""
End Sub

Public Property Get Item(Name)
Attribute Item.VB_UserMemId = 0
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If Not IsNull(ce) Then
        LC.Assign Item, ce.Value
    Else
        Item = Null
    End If
End Property

Public Property Let Item(Name, Value)
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If IsNull(ce) Then
        Set ce = New ConfigEntry
        ce.InitEntry 0, "<*>", Me
        ce.Value = Value
        SetEntry Name, ce
    Else
        ce.Value = Value
    End If
End Property

Public Property Set Item(Name, Value)
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If IsNull(ce) Then
        Set ce = New ConfigEntry
        Set ce.Value = Value
        SetEntry Name, ce
    Else
        Set ce.Value = Value
    End If
End Property

Public Sub Remove(ByVal Name As String)
    RemoveEntry Name
End Sub

Public Property Get Attributes() As Collection
    Set Attributes = m_EntryName.KeySet
End Property

Public Function Accessor() As Object
    If m_Accessor Is Nothing Then
        Set m_Accessor = LC.ImplementDynamicObject(Me)
    End If
    Set Accessor = m_Accessor
End Function

' IDynamicObject::DynamicIndex
Private Function IDynamicObject_DynamicIndex(ByVal Name As String) As Long
    Dim ce
    LC.Assign ce, m_EntryName(Name)
    If IsNull(ce) Then
        ' Add null entry for dynamic adding properties
        Item(Name) = Null
        LC.Assign ce, m_EntryName(Name)
    End If
    IDynamicObject_DynamicIndex = ce.Id
End Function

' IDynamicObject::DynamicInvoke
Private Function IDynamicObject_DynamicInvoke(ByVal itype As InvokeType, ByVal methodIndex As Long, Parameters As Variant) As Variant
    Dim ce
    LC.Assign ce, m_EntryId(methodIndex)
    Assert Not IsNull(ce)

    Select Case itype
    Case InvokeMethod
        ' ??
    Case InvokePropertyGet
        IDynamicObject_DynamicInvoke = ce.Value
    Case InvokePropertyPut
        ce.Value = Parameters(0)
    Case InvokePropertyPutRef
        Set ce.Value = Parameters(0)
    End Select
    Exit Function
NotExist:
    Unexpected
End Function

Private Sub Map_Clear()
    Set m_EntryId = New Map
    Set m_EntryName = New Map
    m_NextId = DISPID_BASE
End Sub

Private Function Map_Contain(Key As Variant) As Boolean
    Map_Contain = m_EntryName.Contain(Key)
End Function

Private Property Get Map_Entries() As Collection
    Set Map_Entries = m_EntryName
End Property

Private Property Set Map_Item(Key As Variant, rhs As Variant)
    Set Item(Key) = rhs
End Property

Private Property Let Map_Item(Key As Variant, rhs As Variant)
    Item(Key) = rhs
End Property

Private Property Get Map_Item(Key As Variant) As Variant
    LC.Assign Map_Item, Item(Key)
End Property

Private Function Map_KeySet() As Collection
    Set Map_KeySet = m_EntryName.KeySet
End Function

Private Function Map_Remove(Key As Variant) As Boolean
    Remove Key
    Map_Remove = True
End Function

Private Property Get Map_Serialization() As String
    ' Map_Serialization
End Property

Private Function Map_Size() As Long
    Map_Size = m_EntryName.Size
End Function

Private Function Map_Values() As Variant
    Assert False, "Not Supported", LOCATION
    'Map_Values = m_EntryName.Values
End Function

Private Function Map_ValueSet() As Collection
    Assert False, "Not Supported", LOCATION
    'Set Map_ValueSet = m_EntryName.ValueSet
End Function

Private Function Map_Walk(it As Iterator) As Long
    Assert False, "Not Supported", LOCATION
    'Map_Walk = m_EntryName.Walk(it)
End Function
