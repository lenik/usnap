VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   735
      Left            =   1620
      TabIndex        =   0
      Top             =   1260
      Width           =   1155
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim LC As New LowXRuntime.Component
Dim lst As New BasTypeLib.List

Private Sub Command1_Click()
    Dim x

    lst.push 20
    lst.push "hello"
    lst.push Nothing
    While lst.Size
        LC.Assign x, lst.shift
        If TypeName(x) = "Nothing" Then
            MsgBox "Nothing"
        Else
            MsgBox TypeName(x) & ":" & CStr(x)
        End If
    Wend
End Sub
