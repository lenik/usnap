VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "XmlTool01"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Const FONT_LITIRAL = "COLOR=""#000000"" STYLE=""font-weight:bold"""
Const FONT_SYMBOL = "COLOR=""#0000FF"""
Const FONT_IDENTIFIER = "COLOR=""#AA4040"""
Const FONT_INVALID = "COLOR=""#FF0000"""

Const CHAR_LT = "<FONT COLOR=""#0000FF"">&lt;</FONT>"
Const CHAR_GT = "<FONT COLOR=""#0000FF"">&gt;</FONT>"

Public WithEvents m_Xml As DOMDocument
Attribute m_Xml.VB_VarHelpID = -1

Private m_XmlView As String

Public Property Get XmlView() As String
    XmlView = m_XmlView
End Property

Public Function MakeXmlView() As String
    Dim r As String
    Dim i As Integer

    r = "<HTML><HEAD><TITLE>Xml结构视图</TITLE>"
    r = r & "<META GENERATOR=""XmlTool01"">"
    r = r & "</HEAD>"
    r = r & "<BODY><FONT name=""宋体"">"

    r = r & "<P><H2>XML结构视图</H2></P>"

    For i = 0 To m_Xml.childNodes.length - 1
        r = r & "<DL>"
        r = r & MakeXmlView1(m_Xml.childNodes(i))
        r = r & "</DL>"
    Next

    r = r & "</FONT></BODY></HTML>"

    m_XmlView = r
    MakeXmlView = r
End Function

Public Function MakeXmlView1(node As IXMLDOMNode) As String
    Dim i As Integer
    Dim r As String

    r = ""
    Select Case node.nodeType
    Case NODE_INVALID
        r = MakeInvalid("!Invalid!")
    Case NODE_ELEMENT
        ' <eleName attr...> ... </eleName>
        r = CHAR_LT & MakeIdentifier(node.baseName)
            For i = 0 To node.Attributes.length - 1
                r = r & " " & MakeXmlView1(node.Attributes(i))
            Next
        r = r & CHAR_GT

        For i = 0 To node.childNodes.length - 1
            r = r & "<DL>"
                r = r & MakeXmlView1(node.childNodes(i))
            r = r & "</DL>"
        Next

        r = r & CHAR_LT & MakeSymbol("/") & MakeIdentifier(node.baseName) & CHAR_GT
    Case NODE_ATTRIBUTE
        r = MakeHashView(node.nodeName, node.nodeValue)
    Case NODE_TEXT
        r = MakeLitiral(node.Text)
    Case NODE_PROCESSING_INSTRUCTION
        r = MakeSymbol("&lt;?xml " & node.Text & "?&gt;")
    End Select
    MakeXmlView1 = r
End Function

Public Function MakeHashView(ByVal hName As String, ByVal hVal As String) As String
    MakeHashView = MakeIdentifier(hName) & MakeSymbol("=""") & MakeLitiral(hVal) & MakeSymbol("""")
End Function

Private Function MakeLitiral(ByVal str As String) As String
    MakeLitiral = "<FONT " & FONT_LITIRAL & ">" & str & "</FONT>"
End Function
Private Function MakeSymbol(ByVal str As String) As String
    MakeSymbol = "<FONT " & FONT_SYMBOL & ">" & str & "</FONT>"
End Function
Private Function MakeIdentifier(ByVal str As String) As String
    MakeIdentifier = "<FONT " & FONT_IDENTIFIER & ">" & str & "</FONT>"
End Function
Private Function MakeInvalid(ByVal str As String) As String
    MakeInvalid = "<FONT " & FONT_INVALID & ">" & str & "</FONT>"
End Function

Private Sub Class_Initialize()
    Set m_Xml = New DOMDocument
End Sub

Private Sub Class_Terminate()
    Set m_Xml = Nothing
End Sub
