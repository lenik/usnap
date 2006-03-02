VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3750
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6630
   LinkTopic       =   "Form1"
   ScaleHeight     =   3750
   ScaleWidth      =   6630
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   675
      Left            =   300
      TabIndex        =   2
      Top             =   660
      Width           =   1275
   End
   Begin VB.TextBox connstr
      Height          =   315
      Left            =   300
      TabIndex        =   1
      Text            =   "DRIVER={MySQL ODBC 3.51 Driver};SERVER=localhost;DATABASE=mysql;UID=root;PWD=l.;OPTION=3"
      Top             =   180
      Width           =   6015
   End
   Begin VB.ListBox List1
      Height          =   2010
      Left            =   1320
      TabIndex        =   0
      Top             =   1440
      Width           =   3615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public conn As Connection

Private Sub Command1_Click()
    Dim rs As Recordset

    conn.Open connstr.Text

    Set rs = conn.OpenSchema(adSchemaTables)
    List1.Clear
    While Not rs.EOF
        List1.AddItem rs!TABLE_NAME
        rs.MoveNext
        DoEvents
    Wend
    rs.Clone

    conn.Close
End Sub

Private Sub Form_Load()
    Set conn = ExportConnection(New MyConnection)
End Sub
