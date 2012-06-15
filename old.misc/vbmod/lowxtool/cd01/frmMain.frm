VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   4245
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6255
   LinkTopic       =   "Form1"
   ScaleHeight     =   4245
   ScaleWidth      =   6255
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   1080
      Left            =   3990
      TabIndex        =   1
      Top             =   2340
      Width           =   2010
   End
   Begin MSComctlLib.TreeView TreeView1
      Height          =   3090
      Left            =   255
      TabIndex        =   0
      Top             =   195
      Width           =   2250
      _ExtentX        =   3969
      _ExtentY        =   5450
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
        Dim vdesc
        vdesc = "#53,File|4,FILE|1,1|1,2#4,Open|4,OPEN|2,16#5,Close#4,Exit#11,Edit#4,Copy"
        init_treenodes TreeView1.Nodes, Nothing, vdesc
End Sub
