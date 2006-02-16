VERSION 5.00
Begin VB.Form Form3
   Caption         =   "Form1"
   ClientHeight    =   4350
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6690
   LinkTopic       =   "Form1"
   ScaleHeight     =   4350
   ScaleWidth      =   6690
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   735
      Left            =   3840
      TabIndex        =   2
      Top             =   540
      Width           =   1215
   End
   Begin VB.CommandButton Command1
      Caption         =   "Load config"
      Height          =   735
      Left            =   840
      TabIndex        =   1
      Top             =   600
      Width           =   1635
   End
   Begin VB.ListBox List1
      Height          =   2400
      Left            =   900
      TabIndex        =   0
      Top             =   1800
      Width           =   3975
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Dim name
    Dim value
    List1.Clear
    For Each name In configuration.Names
        value = configuration.Item(name)
        List1.AddItem name & " = " & value
    Next
End Sub

Private Sub Command2_Click()
    MsgBox config.runas
End Sub

Private Sub Form_Load()
    configuration.Path = App.Path & "\Test_Config"
End Sub
