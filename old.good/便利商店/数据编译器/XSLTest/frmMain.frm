VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "XLS Test 1"
   ClientHeight    =   3825
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5175
   LinkTopic       =   "Form1"
   ScaleHeight     =   3825
   ScaleWidth      =   5175
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text1
      DataField       =   "Parent"
      DataSource      =   "xls1"
      Height          =   390
      Left            =   1470
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   1020
      Width           =   3270
   End
   Begin VB.Data xls1
      Caption         =   "XLS 1"
      Connect         =   "Lotus WK4;"
      DatabaseName    =   "Data1"
      DefaultCursorType=   0  '缺省游标
      DefaultType     =   2  '使用 ODBC
      Exclusive       =   0   'False
      Height          =   735
      Left            =   660
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "Class$"
      Top             =   2190
      Width           =   4020
   End
   Begin VB.TextBox txtName
      DataField       =   "Name"
      DataSource      =   "xls1"
      Height          =   360
      Left            =   1425
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   345
      Width           =   3285
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
