Attribute VB_Name = "Module1"
Option Explicit

Public Sub TestList1()
    Dim l As New LinkedList
    l.Push 10                           ' 10
    l.Push 20                           ' 10 20
    l.Unshift 5                         ' 5 10 20
    Debug.Print l.Pop                   ' 20, 5 10
    Debug.Print l.Shift                 ' 5,  10
    Debug.Print l.Front                 ' 10, 10
    Debug.Print l.Back                  ' 10, 10
End Sub
