VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Map"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Private m_Entries As Collection

Public Sub Clear()
    Set m_Entries = New Collection
End Sub

Public Function Size() As Long
    Size = m_Entries.Count
End Function

Public Function KeySet() As Collection
    Dim ent As Entry
    Set KeySet = New Collection
    For Each ent In m_Entries
        ' Assert no duplicated ent.key
        KeySet.Add ent.Key
    Next
End Function

Public Function Values()
    Dim n As Long
    Dim ent As Entry
    n = Size()
    Values = Empty
    If n = 0 Then Exit Function
    n = n - 1
    ReDim vlist(n)
    n = 0
    For Each ent In m_Entries
        LC.Assign vlist(n), ent.Value
        n = n + 1
    Next
    Values = vlist
End Function

Public Property Get Item(Key)
    Dim ent As Entry
    On Error GoTo NotExist
    Set ent = m_Entries(CStr(Key))
    LC.Assign Item, ent.Value
    Exit Property
NotExist:
    Item = Null
End Property

Public Property Let Item(Key, Value)
    Dim ent As Entry
    On Error GoTo NotExist
    Set ent = m_Entries(CStr(Key))
    ent.Value = Value
    Exit Property
NotExist:
    Set ent = New Entry
    ent.Key = Key
    ent.Value = Value
    m_Entries.Add ent, CStr(Key)
End Property

Public Function Contain(Key) As Boolean
    Dim ent As Entry
    On Error GoTo NotExist
    Set ent = m_Entries(CStr(Key))
    Contain = True
NotExist:
End Function

Public Function Remove(Key) As Boolean
    Dim ent  As Entry
    On Error GoTo NotExist
    Set ent = m_Entries(CStr(Key))
    m_Entries.Remove CStr(Key)
    Remove = True
NotExist:
End Function

Public Function Walk(it As Iterator) As Long
    Dim ent As Entry
    Walk = 0
    For Each ent In m_Entries
        If Not it.Iterate(ent.Key, ent.Value) Then
            Exit Function
        End If
        Walk = Walk + 1
    Next
End Function

Private Sub Class_Initialize()
    Clear
End Sub
