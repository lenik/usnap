VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3660
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5250
   LinkTopic       =   "Form1"
   ScaleHeight     =   3660
   ScaleWidth      =   5250
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   1455
      Left            =   2640
      TabIndex        =   2
      Top             =   1320
      Width           =   1995
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   435
      Left            =   2880
      TabIndex        =   1
      Top             =   420
      Width           =   1935
   End
   Begin MSComctlLib.TreeView TreeView1
      Height          =   2655
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2475
      _ExtentX        =   4366
      _ExtentY        =   4683
      _Version        =   393217
      Style           =   7
      Appearance      =   1
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        init_treenodes _
                TreeView1.Nodes, Nothing, _
                "(FILE(EDIT(COPY)(CUT))(OPEN)(CLOSE))(OPTIONS(GENERAL)(ADVANCE))"
                '"#32.FILE#13.EDIT#COPY#CUT#OPEN#CLOSE#23.OPTIONS#GENERAL#ADVANCE"
End Sub

Private Sub Command2_Click()
        TreeView1.Nodes.Clear
End Sub
