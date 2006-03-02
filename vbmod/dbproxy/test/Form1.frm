VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   4260
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5985
   LinkTopic       =   "Form1"
   ScaleHeight     =   4260
   ScaleWidth      =   5985
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdQuery
      Caption         =   "&Query"
      Height          =   435
      Left            =   4200
      TabIndex        =   4
      Top             =   3660
      Width           =   1275
   End
   Begin VB.TextBox result
      Height          =   1995
      Left            =   1140
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      TabIndex        =   3
      Top             =   1440
      Width           =   3795
   End
   Begin VB.TextBox sql
      Height          =   495
      Left            =   1140
      TabIndex        =   1
      Text            =   "select 1"
      Top             =   600
      Width           =   3795
   End
   Begin VB.Label Label2
      Caption         =   "Result: "
      Height          =   375
      Left            =   180
      TabIndex        =   2
      Top             =   1440
      Width           =   795
   End
   Begin VB.Label Label1
      Caption         =   "SQL: "
      Height          =   435
      Left            =   180
      TabIndex        =   0
      Top             =   660
      Width           =   735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim conn As DBConnection

'dim conn as New
Private Sub cmdQuery_Click()
    Dim v As Variant
    v = conn.QueryValue(sql.Text, 100, 5)
    result = DumpVariant(v)
End Sub

Private Sub Form_Load()
    Application.Name = "Test_Link"
    Application.HomeDirectory = App.Path
    Set conn = DBConnect
End Sub
