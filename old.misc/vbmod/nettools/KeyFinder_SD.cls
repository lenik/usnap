VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "KeyFinder_SD"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "NetTools::KeyFinder_SD"

Implements VBExt.Iterator

Public Found As Boolean
Public FoundKey As String
Public sd As XceedWinsockLib.ConnectionOrientedSocket

Private Function Iterator_Iterate(key As Variant, Value As Variant) As Boolean
    Dim s As Session

    Assert IsObject(Value), "value of sessions-map isn't an object", LOCATION

    Set s = Value
    Assert Not s Is Nothing

    If s.sd Is sd Then
        Found = True
        FoundKey = key
        Iterator_Iterate = False
        Exit Function
    End If

NotMatched:
    Iterator_Iterate = True
End Function
