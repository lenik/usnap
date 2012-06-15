VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "KeyFinder"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Implements VBExt.Iterator

Public Found As Boolean
Public FoundKey As Variant
Public ValuePattern As Variant

Private Function Iterator_Iterate(Key As Variant, Value As Variant) As Boolean
    If IsObject(ValuePattern) Then
        If IsObject(Value) Then
            If ValuePattern Is Value Then
                LC.Assign FoundKey, Key
                Found = True
                Iterator_Iterate = False
                Exit Function
            End If
        End If
    Else
        If Not IsObject(Value) Then
            On Error GoTo NotMatched
            If ValuePattern = Value Then
                LC.Assign FoundKey, Key
                Found = True
                Iterator_Iterate = False
                Exit Function
            End If
            On Error GoTo 0
        End If
    End If

NotMatched:
    Iterator_Iterate = True
End Function
