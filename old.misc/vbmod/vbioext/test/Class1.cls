VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Class1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private WithEvents sl As Slots
Attribute sl.VB_VarHelpID = -1

Public Sub tt2()
    sl.Add "0-hello"
    sl.Add "1-world"
    sl.Remove 0
    sl.Add "0-newhello"
    sl.Add "2-append"
    sl.Add "3-newapp"
    sl.Remove 1
    sl.Add "1-newworld"
    sl.Add "2-xyz"
End Sub

Private Sub Class_Initialize()
    Set sl = New Slots
End Sub

Private Sub sl_Create(ByVal Slot As Long, ByVal Param As Variant, NewVar As Variant)
    Dim x As New Collection
    x.Add Param & "_1"
    x.Add Param & "_2"
    x.Add Param & "_3"
    Set NewVar = x
End Sub

Private Sub sl_Remove(ByVal Slot As Long)
    '
End Sub
