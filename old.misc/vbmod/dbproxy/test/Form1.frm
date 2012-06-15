VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   4950
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6600
   LinkTopic       =   "Form1"
   ScaleHeight     =   4950
   ScaleWidth      =   6600
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkAlwaysMat
      Caption         =   "&Always Using Matrix"
      Height          =   315
      Left            =   300
      TabIndex        =   9
      Top             =   4320
      Width           =   2055
   End
   Begin VB.TextBox edtCols
      Height          =   375
      Left            =   4680
      TabIndex        =   8
      Text            =   "2"
      Top             =   180
      Width           =   1335
   End
   Begin VB.CheckBox chkCols
      Caption         =   "&Cols"
      Height          =   255
      Left            =   3660
      TabIndex        =   7
      Top             =   240
      Value           =   1  'Checked
      Width           =   855
   End
   Begin VB.TextBox edtRows
      Height          =   375
      Left            =   1320
      TabIndex        =   6
      Text            =   "2"
      Top             =   180
      Width           =   1335
   End
   Begin VB.CheckBox chkRows
      Caption         =   "&Rows"
      Height          =   255
      Left            =   300
      TabIndex        =   5
      Top             =   240
      Value           =   1  'Checked
      Width           =   855
   End
   Begin VB.CommandButton cmdQuery
      Caption         =   "&Query"
      Height          =   435
      Left            =   4800
      TabIndex        =   4
      Top             =   4320
      Width           =   1275
   End
   Begin VB.TextBox result
      Height          =   2415
      Left            =   1200
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      TabIndex        =   3
      Top             =   1620
      Width           =   4815
   End
   Begin VB.TextBox sql
      Height          =   495
      Left            =   1200
      TabIndex        =   1
      Text            =   "select 1, 2, 3 union select 5, 6, 7"
      Top             =   780
      Width           =   4815
   End
   Begin VB.Label Label2
      Caption         =   "Result: "
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1620
      Width           =   795
   End
   Begin VB.Label Label1
      Caption         =   "SQL: "
      Height          =   435
      Left            =   240
      TabIndex        =   0
      Top             =   840
      Width           =   735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'dim conn as New
Private Sub cmdQuery_Click()
    Dim v As Variant
    If chkRows Then
        If chkCols Then
            v = conn.QueryValue(sql.Text, edtRows, edtCols, chkAlwaysMat.Value)
        Else
            v = conn.QueryValue(sql.Text, edtRows, , chkAlwaysMat.Value)
        End If
    Else
        If chkCols Then
            v = conn.QueryValue(sql.Text, , edtCols, chkAlwaysMat.Value)
        Else
            v = conn.QueryValue(sql.Text, , , chkAlwaysMat.Value)
        End If
    End If
    result = DumpVariant(v)
End Sub

Private Sub edtCols_Validate(Cancel As Boolean)
    If Not IsNumeric(edtCols) Then
        MsgBox "must be a number"
        Cancel = True
    End If
End Sub

Private Sub edtRows_Validate(Cancel As Boolean)
    If Not IsNumeric(edtRows) Then
        MsgBox "must be a number"
        Cancel = True
    End If
End Sub

Private Sub Form_Load()
    If DebugMode Then
        Application.Name = "Test_Link"
        Application.HomeDirectory = App.Path
        Application.Reload
    End If
    'Set conn = DBConnect("DRIVER={SQL Server};SERVER=192.168.0.253;UID=sa;PWD=kelingbarcode;Database=ZBGZGLXT")
    'Set conn = DBConnect("DRIVER={Microsoft Access Driver (*.mdb)};" _
                        & "DBQ=C:\.radiko\.miaj\sandbox\mydoc\1.mdb")

    Set conn = DBConnect("Provider=Microsoft.Jet.OLEDB.4.0;" _
                       & "Data Source='C:\.radiko\.miaj\sandbox\mydoc\1.mdb';" _
                       & "Persist Security Info=False")
End Sub
