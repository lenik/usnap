VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{683364A1-B37D-11D1-ADC5-006008A5848C}#1.0#0"; "dhtmled.ocx"
Begin VB.Form frmMain
   Caption         =   "便利商店数据编译程序"
   ClientHeight    =   5505
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   5925
   LinkTopic       =   "Form1"
   ScaleHeight     =   5505
   ScaleWidth      =   5925
   StartUpPosition =   3  '窗口缺省
   Begin VB.Frame Frame1
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   0
      Visible         =   0   'False
      Width           =   5655
      Begin VB.TextBox txtPathName
         Height          =   270
         Left            =   0
         TabIndex        =   3
         Text            =   "about:blank"
         Top             =   0
         Width           =   4815
      End
      Begin VB.CommandButton cmdBrowse
         Caption         =   "&Browse"
         Height          =   255
         Left            =   4920
         TabIndex        =   2
         Top             =   0
         Width           =   735
      End
   End
   Begin DHTMLEDLibCtl.DHTMLEdit scrStructure
      Height          =   4335
      Left            =   120
      TabIndex        =   0
      Top             =   480
      Width           =   5655
      ActivateApplets =   0   'False
      ActivateActiveXControls=   0   'False
      ActivateDTCs    =   -1  'True
      ShowDetails     =   0   'False
      ShowBorders     =   0   'False
      Appearance      =   1
      Scrollbars      =   -1  'True
      ScrollbarAppearance=   1
      SourceCodePreservation=   -1  'True
      AbsoluteDropMode=   0   'False
      SnapToGrid      =   0   'False
      SnapToGridX     =   50
      SnapToGridY     =   50
      BrowseMode      =   -1  'True
      UseDivOnCarriageReturn=   0   'False
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   0
      Top             =   5040
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DefaultExt      =   "xml"
      Filter          =   "XML (*.xml)|*.xml|all files(*.*)|*.*||"
   End
   Begin VB.Menu mnuData
      Caption         =   "&F数据库"
      Begin VB.Menu mnuDataOpen
         Caption         =   "&O装入数据库"
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuSaveXML
         Caption         =   "&S存入解析XML"
      End
      Begin VB.Menu mnuDataS1
         Caption         =   "-"
      End
      Begin VB.Menu mnuExit
         Caption         =   "&X退出"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu mnuHelp
      Caption         =   "&H帮助"
      Begin VB.Menu mnuHelpAbout
         Caption         =   "&A关于"
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public desc As String

Public descType As descTypeEnum
Public xmlTool As New XmlTool01

Public Sub loadDocument(ByVal pathName As String)
    On Error GoTo err
    scrStructure.loadDocument pathName
    Exit Sub
err:
    MsgBox "couldn't load specified document. "
End Sub

Public Sub loadDatabase(ByVal pathName As String)
    Dim connect As New ADODB.Connection
    Dim r As New ADODB.Recordset

    On Error GoTo err

    r.Open "Select * from ClassMap", "DSN=Data1"
    'DSQ=" & pathName & ";Driver={Microsoft Visual Forpro Driver}"

    Dim fi As Integer
    desc = "<table><tr>"
    For fi = 0 To r.Fields.Count - 1
        desc = desc & "<td>" & r.Fields(fi).Name & "</td>"
    Next
    desc = desc & "</tr>"

    Do While Not r.EOF
        desc = desc & "<tr>"

            For fi = 0 To r.Fields.Count - 1
                desc = desc & "<td>" & r.Fields(fi).Value & "</td>"
            Next
        desc = desc & "</tr>"

        r.MoveNext
    Loop

    r.Close
    desc = desc & "</table>"

    refreshDesc
    Exit Sub
err:
    MsgBox "装入数据库时出错: " & vbNewLine & _
            "错误: " & Hex(err.Number) & "-" & err.Description & vbNewLine & _
            "LastDllError: " & Hex(err.LastDllError)
End Sub

Public Sub refreshDesc()

        On Error GoTo err

        desc = "<?xml version=""1.0""?>" & desc

        Select Case descType
        Case OriginalDatabase
            xmlTool.m_Xml.loadXML desc
            'xmlTool.m_Xml.parseError.errorCode
            xmlTool.MakeXmlView
            scrStructure.DocumentHTML = xmlTool.XmlView
        Case DatabaseStructure
        End Select
        Exit Sub
err:
    MsgBox "Error when XML2HTML: " & vbNewLine & _
            "错误: " & Hex(err.Number) & "-" & err.Description & vbNewLine & _
            "LastDllError: " & Hex(err.LastDllError)
End Sub

Private Sub cmdBrowse_Click()
    On Error GoTo err
    cd.ShowOpen
    txtPathName = cd.FileName
    txtPathname_KeyPress 13
    Exit Sub
err:
End Sub

Private Sub Form_Load()
    descType = OriginalDatabase
End Sub

Private Sub mnuDataOpen_Click()
    On Error GoTo err
    'cd.ShowOpen
    loadDatabase cd.FileName
    Exit Sub
err:
End Sub

Private Sub mnuExit_Click()
        End
End Sub

Private Sub mnuHelpAbout_Click()
    MsgBox "便利商店数据编译程序 R1", vbOKOnly, "关于"
End Sub

Private Sub mnuSaveXML_Click()
    On Error GoTo err
    cd.DialogTitle = "请选择保存的XML文件"
    cd.ShowSave

    xmlTool.m_Xml.save cd.FileName
    Exit Sub
err:
End Sub

Private Sub txtPathname_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
        loadDocument txtPathName.Text
        txtPathName.SelStart = 1
        txtPathName.SelLength = Len(txtPathName.Text)
    End If
End Sub
