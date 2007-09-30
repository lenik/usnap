VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton obj
      Caption         =   "obj"
      Height          =   480
      Left            =   285
      TabIndex        =   1
      Top             =   345
      Width           =   1215
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   735
      Left            =   1470
      TabIndex        =   0
      Top             =   1380
      Width           =   1515
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public lxV As New LowXRuntime.Vtbl
Public ct As New CaComToolLib.CaCTools

Private Sub Command1_Click()

        Dim c
        c = ct.reference(obj)

        lxV.Bind obj

        c = ct.reference(obj)

        lxV.Unbind

        c = ct.reference(obj)

End Sub
