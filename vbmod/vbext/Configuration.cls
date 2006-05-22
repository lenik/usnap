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
Private m_EntryName As Map
Private m_EntryId As Map
Private m_NextId As Integer

Private m_TempDir As String

Implements IDynamicObject

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

Private Sub SetEntry(name, ce)
    If ce.Id = 0 Then
        ce.Id = m_NextId
        m_NextId = m_NextId + 1
    End If
    m_EntryName(name) = ce
    m_EntryId(ce.Id) = ce
End Sub

Private Function RemoveEntry(name) As Boolean
    Dim ce
    LC.Assign ce, m_EntryName(name)
    If Not IsNull(ce) Then
        m_EntryName.Remove name
        m_EntryId.Remove ce.Id
        RemoveEntry = True
    End If
End Function

Private Function AbsolutePath(ByVal SectionPath As String) As String
    AbsolutePath = m_HomeDir & "\" & m_Name & SectionPath & EXTNAME
End Function

Private Sub LoadConfig(ByVal Section As String)
    Dim Path As String
    Dim xmldoc As New DOMDocument

    Path = AbsolutePath(Section)
    If Not xmldoc.Load(Path) Then
        Err.Raise ERR_CANT_LOAD_CONFIG, LOCATION, _
            "无法装载配置文件: " & Path & vbNewLine _
            & xmldoc.parseError.reason
    End If

    ' /Entries/ConfigEntry
    Dim entrylist As IXMLDOMNodeList
    Set entrylist = xmldoc.selectNodes("/Entries/Entry")

    Dim i As Integer
    For i = 0 To entrylist.length - 1
        Dim elm As IXMLDOMElement
        Dim name As String
        Dim vtype As String
        Dim j As Integer
        Dim ce As ConfigEntry

        Set elm = entrylist(i)
        name = elm.getAttribute("Name")
        Assert name <> "", "Entry/@Name hasn'vtype specified", LOCATION

        vtype = LCase(FC.StringOf(elm.getAttribute("Type")))
        'Assert vtype = Trim(vtype)

        Set ce = New ConfigEntry
        ce.ParseValue elm, vtype
        ce.InitEntry 0, Section
        SetEntry name, ce

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

Public Property Get name() As String
    name = m_Name
End Property

Property Let name(ByVal newName As String)
    m_Name = newName
End Property

Public Property Get HomeDirectory() As String
    HomeDirectory = m_HomeDir
End Property

Public Property Let HomeDirectory(ByVal newHome As String)
    m_HomeDir = newHome
End Property

Public Sub Reload(Optional ByVal IgnoreErrors As Boolean = False)
    Set m_EntryId = New Map
    Set m_EntryName = New Map
    m_NextId = DISPID_BASE

    If IgnoreErrors Then On Error Resume Next
    LoadConfig ""
End Sub

Public Property Get Item(name)
Attribute Item.VB_UserMemId = 0
    Dim ce
    LC.Assign ce, m_EntryName(name)
    If Not IsNull(ce) Then LC.Assign Item, ce.Value
End Property

Public Property Let Item(name, Value)
    Dim ce
    LC.Assign ce, m_EntryName(name)
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
Private Function IDynamicObject_DynamicIndex(ByVal name As String) As Long
    Dim ce
    LC.Assign ce, m_EntryName(name)
    If IsNull(ce) Then
        ' Add null entry for dynamic adding properties
        Item(name) = Null
        LC.Assign ce, m_EntryName(name)
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
