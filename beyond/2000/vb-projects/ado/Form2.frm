VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "MSFLXGRD.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3765
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4965
   LinkTopic       =   "Form1"
   ScaleHeight     =   3765
   ScaleWidth      =   4965
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text2
      Height          =   1695
      Left            =   120
      MultiLine       =   -1  'True
      TabIndex        =   4
      Text            =   "Form2.frx":0000
      Top             =   120
      Width           =   4575
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   615
      Left            =   2400
      TabIndex        =   3
      Top             =   1920
      Width           =   2295
   End
   Begin VB.CheckBox Check1
      Caption         =   "Check1"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   3240
      Width           =   3615
   End
   Begin VB.TextBox Text1
      DataField       =   "f3"
      DataSource      =   "Data1"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   1920
      Width           =   1335
   End
   Begin MSFlexGridLib.MSFlexGrid MSFlexGrid1
      Bindings        =   "Form2.frx":0006
      Height          =   375
      Left            =   4080
      TabIndex        =   0
      Top             =   3240
      Width           =   735
      _ExtentX        =   1296
      _ExtentY        =   661
      _Version        =   393216
   End
   Begin VB.Data Data1
      Caption         =   "Data1"
      Connect         =   "Access"
      DatabaseName    =   "X:\temp\11.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   375
      Left            =   240
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   2  'Snapshot
      RecordSource    =   "a"
      Top             =   2760
      Width           =   4095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Check1_Click()
    Timer1.Enabled = Check1
End Sub

Private Sub Command1_Click()
    Dim a As String, i
    Data1.Recordset.MoveFirst
    Text2 = ""
    a = ""
    For i = 0 To Data1.Recordset.Fields.Count - 1
        a = a & Data1.Recordset.Fields(i).Name & vbTab
    Next
    Text2 = Text2 + a + vbNewLine
    While Not Data1.Recordset.EOF
        a = ""
        For i = 0 To Data1.Recordset.Fields.Count - 1
            a = a & Data1.Recordset(i).Value & vbTab
        Next
        a = a & vbNewLine
        Text2 = Text2 + a
        Data1.Recordset.MoveNext
    Wend
End Sub

Private Sub Form_Click()
    Data1.Recordset.Filter = "f3<1000"
    Data1.Recordset.Requery
    Data1.UpdateControls
    Data1.Refresh
    MSFlexGrid1.Refresh
End Sub
