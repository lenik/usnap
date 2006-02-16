VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Layout"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Const MAX_CHILDREN = 256

Dim HasChild(MAX_CHILDREN, 1) As Object
Dim HasChildSize As Integer

Dim lo As New LowX.COM

Public Sub InitializeCoordinates(containerObject As Object)
    Dim child As Object
    For Each child In containerObject
        If lo.HasProperty(child, "Container") Then
            HasChildSize = HasChildSize + 1
            Assert HasChildSize < MAX_CHILDREN
        End If
    Next
End Sub

Public Sub Relayout()
    '
    ' Not implemented, yet.
    '
End Sub
