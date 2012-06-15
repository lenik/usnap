VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5070
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7290
   LinkTopic       =   "Form1"
   ScaleHeight     =   5070
   ScaleWidth      =   7290
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2
      Caption         =   "Remove"
      Height          =   735
      Left            =   960
      TabIndex        =   2
      Top             =   2100
      Width           =   1575
   End
   Begin VB.ListBox List1
      Height          =   2985
      Left            =   3480
      TabIndex        =   1
      Top             =   900
      Width           =   3195
   End
   Begin VB.CommandButton Command1
      Caption         =   "Add"
      Height          =   735
      Left            =   960
      TabIndex        =   0
      Top             =   900
      Width           =   1575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public allsd As New Collection

Private Sub Command1_Click()
    Dim sd As New Socket

    List1.AddItem "list1.ListCount+1"
End Sub
