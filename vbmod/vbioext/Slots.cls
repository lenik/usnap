VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Slots"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBIOExt::Slots"

Private m_Slots As BasTypeLib.Vector
Private WithEvents m_Ker As FastAlgLib.SAOT
Attribute m_Ker.VB_VarHelpID = -1

Private m_Param As Variant

Public Event Create(ByVal Slot As Long, ByVal Param As Variant, _
                    ByRef NewVar As Variant)
Public Event Remove(ByVal Slot As Long)

Public Function Slot2Index(ByVal Slot As Long) As Long
    Slot2Index = m_Ker.FindSlot(Slot)
End Function

Public Function Index2Slot(ByVal Index As Long) As Long
    Index2Slot = m_Ker.FindIndex(Index)
End Function

Public Property Get Slots() As Long
    Slots = m_Slots.Size
End Property

Public Property Get Size() As Long
    Size = m_Ker.Size
End Property

Public Property Get Slot(ByVal s As Long) As Variant
    LC.Assign Slot, m_Slots.Item(s)
End Property

Public Property Let Slot(ByVal s As Long, ByVal newval As Variant)
    m_Slots.Item(s) = newval
End Property

Public Property Set Slot(ByVal s As Long, ByVal newval As Variant)
    Set m_Slots.Item(s) = newval
End Property

Public Property Get Item(ByVal Index As Long) As Variant
    LC.Assign Item, m_Slots.Item(Index2Slot(Index))
End Property

Public Property Let Item(ByVal Index As Long, ByVal newval As Variant)
    m_Slots.Item(Index2Slot(Index)) = newval
End Property

Public Property Set Item(ByVal Index As Long, ByVal newval As Variant)
    Set m_Slots.Item(Index2Slot(Index)) = newval
End Property

Public Function Add(ByVal Param As Variant) As Long
    LC.Assign m_Param, Param
    m_Ker.Append 1
    Add = Index2Slot(m_Ker.Size - 1)
End Function

Public Sub Remove(ByVal Slot As Long)
    m_Ker.SlotRemove Slot
End Sub

Public Sub Clear()
    m_Ker.Clear
End Sub

Public Function SortSlots() As Vector
    Dim vec As New Vector
    Dim sorted
    Dim i As Long
    sorted = m_Ker.SortSlots
    For i = 0 To m_Ker.Size - 1
        vec.Push sorted(i)
    Next
    Set SortSlots = vec
End Function

Public Property Get SlotStatus() As String
    Dim i As Long, j As Long
    SlotStatus = "[" & m_Ker.Size & "]"
    For i = 0 To m_Ker.SlotAllocated - 1
        j = m_Ker.FindSlot(i)
        SlotStatus = SlotStatus & "." & j
    Next
End Property

Public Property Get IndexStatus() As String
    Dim i As Long, j As Long
    Dim vec As Vector
    Set vec = SortSlots
    IndexStatus = "[" & vec.Size & "]"
    For i = 0 To vec.Size - 1
        IndexStatus = IndexStatus & "." & vec.Item(i)
    Next
End Property

Private Sub Class_Initialize()
    Set m_Slots = New BasTypeLib.Vector
    Set m_Ker = New FastAlgLib.SAOT
End Sub

Private Sub m_Ker_Add(ByVal Slot As Long, ByVal Index As Long)
    Dim NewVar As Variant
    RaiseEvent Create(Slot, m_Param, NewVar)

    If Slot >= m_Slots.Size Then
        m_Slots.Push NewVar
    Else
        LC.Assign m_Slots.Item(Slot), NewVar
    End If
End Sub

Private Sub m_Ker_Remove(ByVal Slot As Long, ByVal Index As Long)
    RaiseEvent Remove(Slot)
    m_Slots.Item(Slot) = Empty
End Sub
