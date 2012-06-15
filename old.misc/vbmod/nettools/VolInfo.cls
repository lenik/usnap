VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "VolInfo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "NetTools::VolInfo"

Private m_Name As String
Private m_Category As String
Private m_Segments As New BasTypeLib.Vector

Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Name = newval
End Property

Public Property Get Category() As String
    Category = m_Category
End Property

Public Property Let Category(ByVal newval As String)
    m_Category = newval
End Property

Public Property Get Segments() As Long
    Segments = m_Segments.Size
End Property

Public Property Get Segment(ByVal index As Long) As VolSegment
    Assert index >= LBound(m_Segments) And index <= UBound(m_Segments), _
        "Invalid segment index [" & index & "]", LOCATION
    Set Segment = m_Segments(index)
End Property

Public Property Get AvailableSegments(Optional ByVal GetCollection As Boolean = False) As Integer
    If GetCollection Then
        Set AvailableSegments = New Collection
    Else
        AvailableSegments = 0
    End If
    If IsEmpty(m_Segments) Then Exit Property

    Dim i As Integer
    For i = LBound(m_Segments) To UBound(m_Segments)
        If IsObject(m_Segments(i)) Then
            If GetCollection Then
                AvailableSegments.Add i
            Else
                AvailableSegments = AvailableSegments + 1
            End If
        End If
    Next
End Property

Public Property Get UnsentSegments(Optional ByVal GetCollection As Boolean = False) As Integer
    If GetCollection Then
        Set UnsentSegments = New Collection
    Else
        UnsentSegments = 0
    End If
    If IsEmpty(m_Segments) Then Exit Property

    Dim i As Integer
    For i = LBound(m_Segments) To UBound(m_Segments)
        If IsObject(m_Segments(i)) Then
            If Not m_Segments(i).Sent Then
                If GetCollection Then
                    UnsentSegments.Add i
                Else
                    UnsentSegments = UnsentSegments + 1
                End If
            End If
        End If
    Next
End Property

'<?xml verson="1.0" encoding="utf-8"?>
'<volinfo>
'    <name>
'    <category>
'    <segments>
'        <segment index= hash= sent=>
'    </segments>
'</volinfo>
Friend Function ParseXML(ByVal xmldoc As String) As Boolean
    Dim dom As New DOMDocument
    Dim elm As IXMLDOMElement

    On Error Resume Next
        dom.loadXML xmldoc
        ' If Err.Number <> 0 Then
    On Error GoTo 0

    Set elm = dom.documentElement
    Assert elm.tagName = "volinfo"

    m_Name = elm.selectSingleNode("name").Text
    m_Category = elm.selectSingleNode("category").Text

    Set elm = elm.selectSingleNode("segments")

    ReDim m_Segments(0 To elm.childNodes.Length - 1)
    Dim i As Integer
    For i = 0 To elm.childNodes.Length - 1
        Dim segnode As IXMLDOMElement
        Dim index As Integer
        Dim seg As New VolSegment
        Set segnode = elm.childNodes(i)
        index = segnode.getAttribute("index")
        seg.Hashcode = segnode.getAttribute("hash")
        seg.Sent = CBool(segnode.getAttribute("sent"))
        Set m_Segments(index) = seg
    Next

    ParseXML = True
End Function

Friend Function BuildXML() As String
    Dim segs As String


    BuildXML = "<?xml version='1.0' encoding='gb2312'?>" & vbNewLine & _
               "<volinfo>" & vbNewLine & _
               "  <name>" & m_Name & "</name>" & vbNewLine & _
               "  <category>" & m_Category & "</category>" & vbNewLine & _
               "  <segments>" & vbNewLine & _
               segs & _
               "  </segments>" & vbNewLine & _
               "</volinfo>"
End Function
