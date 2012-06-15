VERSION 5.00
Object = "{683364A1-B37D-11D1-ADC5-006008A5848C}#1.0#0"; "dhtmled.ocx"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form frmMain
   Caption         =   "XmlTool01_Client1 : XML结构查看器"
   ClientHeight    =   1980
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   5655
   LinkTopic       =   "Form1"
   ScaleHeight     =   1980
   ScaleWidth      =   5655
   StartUpPosition =   3  '窗口缺省
   Begin DHTMLEDLibCtl.DHTMLEdit htmlView
      Height          =   1095
      Left            =   600
      TabIndex        =   0
      Top             =   120
      Width           =   1215
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
      Top             =   120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
      DefaultExt      =   "xml"
      DialogTitle     =   "打开XML文档"
      Filter          =   "XML文档(*.xml)|*.xml|所有文件(*.*)|*.*"
   End
   Begin VB.Menu mnuMake
      Caption         =   "&Make Xml View"
   End
   Begin VB.Menu mnuExit
      Caption         =   "E&xit"
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public xmlTool As New XmlTool01

Private Sub Form_Resize()
    htmlView.Left = 0
    htmlView.Top = 0
    htmlView.Width = Me.Width - 100
    htmlView.Height = Me.Height - 700
End Sub

Private Sub mnuExit_Click()
    End
End Sub

Private Sub mnuMake_Click()
    On Error GoTo err
    cd.ShowOpen
    xmlTool.m_Xml.Load cd.FileName
    xmlTool.MakeXmlView

    htmlView.DocumentHTML = xmlTool.XmlView

    Exit Sub
err:
End Sub
