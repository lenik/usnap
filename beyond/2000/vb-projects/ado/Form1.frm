VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5085
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7800
   LinkTopic       =   "Form1"
   ScaleHeight     =   5085
   ScaleWidth      =   7800
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox cmd
      Height          =   375
      Left            =   1320
      TabIndex        =   2
      Top             =   4560
      Width           =   6255
   End
   Begin VB.TextBox sql
      Height          =   375
      Left            =   1320
      TabIndex        =   1
      Top             =   4080
      Width           =   6255
   End
   Begin VB.TextBox txtrs
      BeginProperty Font
         Name            =   "ËÎÌו"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3855
      Left            =   0
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   120
      Width           =   7695
   End
   Begin VB.Label Label2
      Caption         =   "cmd"
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Top             =   4560
      Width           =   1095
   End
   Begin VB.Label Label1
      Caption         =   "query:"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   4080
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub sql_KeyPress(KeyAscii As Integer)
    Dim rs As ADODB.Recordset
    Dim s, i
    On Error GoTo sqle
    If KeyAscii <> 13 Then Exit Sub
    Set rs = CreateObject("ADODB.Recordset")
    rs.Open sql.Text, "DSN=hc_chat_v1_database", adOpenKeyset, adLockOptimistic
    For i = 0 To rs.Fields.Count - 1
        s = s & rs.Fields(i).Name & vbTab
    Next
    txtrs = s & vbNewLine

    rs.MoveLast
    While Not rs.BOF And Not rs.EOF
        s = ""
        For i = 0 To rs.Fields.Count - 1
            s = s & rs(i) & vbTab
        Next
        txtrs = txtrs & s & vbNewLine
        rs.MovePrevious
        'rs.MoveNext
        DoEvents
    Wend
    Set rs = Nothing
    Exit Sub
sqle:
    Resume Next

End Sub


Private Sub cmd_KeyPress(KeyAscii As Integer)
    Dim rs As ADODB.Connection
    On Error GoTo sqle
    If KeyAscii <> 13 Then Exit Sub

    Set rs = CreateObject("ADODB.Connection")
    rs.Open "DSN=hc_chat_v1_database"
    rs.Execute cmd.Text
    rs.Close
    Set rs = Nothing
    Exit Sub
sqle:
    Resume Next
End Sub
