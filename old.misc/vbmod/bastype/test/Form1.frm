VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Test"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2
      Caption         =   "vector"
      Height          =   675
      Left            =   780
      TabIndex        =   1
      Top             =   1560
      Width           =   915
   End
   Begin VB.CommandButton Command1
      Caption         =   "stack"
      Height          =   735
      Left            =   660
      TabIndex        =   0
      Top             =   300
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

Function varinfo(x)
    If IsObject(x) Then
        varinfo = TypeName(x)
    ElseIf IsArray(x) Then
        varinfo = TypeName(x) & "(" & LBound(x) & "," & UBound(x)
    Else
        varinfo = CStr(x)
    End If
End Function

Private Sub Command1_Click()
    Dim x

    lst.push 20
    lst.push "hello"
    lst.push Nothing
    While lst.Size
        LC.Assign x, lst.shift
        MsgBox varinfo(x)
    Wend
End Sub

Private Sub Command2_Click()
    Dim vec As New Vector
    vec.push 10
    vec.Insert 1, 20
    vec.push "World"
    vec.push New Collection
    vec.push New List
    vec.push Nothing
    vec.Insert 2, "Hello"
    vec.Insert 0, -1


    Dim it As Iterator
    Dim x
    Set it = vec.Iterator
    While it.hasNext
        LC.Assign x, it.fetch
        MsgBox varinfo(x)
    Wend
End Sub
