VERSION 5.00
Begin VB.Form Form2
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdMD5
      Caption         =   "&MD5"
      Height          =   615
      Left            =   600
      TabIndex        =   2
      Top             =   1440
      Width           =   1335
   End
   Begin VB.TextBox result
      Height          =   735
      Left            =   600
      TabIndex        =   1
      Text            =   "Text2"
      Top             =   2100
      Width           =   3495
   End
   Begin VB.TextBox msg
      Height          =   795
      Left            =   600
      TabIndex        =   0
      Text            =   "a"
      Top             =   480
      Width           =   3435
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdMD5_Click()
    result.Text = md5(msg.Text)
End Sub
