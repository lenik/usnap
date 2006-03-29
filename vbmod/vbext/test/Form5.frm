VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Config test #2"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1
      Height          =   2010
      Left            =   540
      TabIndex        =   2
      Top             =   840
      Width           =   3675
   End
   Begin VB.CommandButton Command2
      Caption         =   "users"
      Height          =   555
      Left            =   1620
      TabIndex        =   1
      Top             =   120
      Width           =   1155
   End
   Begin VB.CommandButton Command1
      Caption         =   "prefix"
      Height          =   555
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1395
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    MsgBox InstPrefix
End Sub

Private Sub Command2_Click()
    Dim rs As Recordset
    Set rs = DBConnect.Execute("select * from user")
    List1.Clear
    While Not rs.EOF
        List1.AddItem rs!host & " - " & rs!user & " - " & rs!Password
        rs.MoveNext
    Wend
End Sub

Private Sub Form_Load()
    If DebugMode Then
        Caption = "In Debug Mode!"
        application.Name = App.EXEName
        application.HomeDirectory = "C:\.lokaj\zbmis\module\vbext\test"
        application.Reload
    Else
        Caption = "In Release Mode"
    End If

    config.test = 123

    'Dim app2, cfg2
    'Set app2 = DBProxy.DBApplication
    'Set cfg2 = DBProxy.DBConfig
End Sub
