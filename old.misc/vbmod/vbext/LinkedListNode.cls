VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "LinkedListNode"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Data As Variant
Private m_PrevNode As LinkedListNode
Private m_NextNode As LinkedListNode

Property Get m_Prev() As LinkedListNode
    Set m_Prev = m_PrevNode
End Property
Property Set m_Prev(ByVal newval As LinkedListNode)
    Set m_PrevNode = newval
End Property
Property Get m_Next() As LinkedListNode
    Set m_Next = m_NextNode
End Property
Property Set m_Next(ByVal newval As LinkedListNode)
    Set m_NextNode = newval
End Property

Public Property Get Data() As Variant
Attribute Data.VB_UserMemId = 0
    LC.Assign Data, m_Data
End Property
Public Property Let Data(ByVal newval As Variant)
    LC.Assign m_Data, newval
End Property

Public Property Get Prev() As LinkedListNode
    Set Prev = m_Prev
End Property
Public Property Set Prev(ByVal newval As LinkedListNode)
    If Not m_Prev Is Nothing Then
        Set m_Prev.m_Next = Nothing
    End If
    If Not newval Is Nothing Then
        Set newval.m_Next = Me
    End If
    Set m_Prev = newval
End Property

Public Property Get Next_() As LinkedListNode
    Set Next_ = m_Next
End Property
Public Property Set Next_(ByVal newval As LinkedListNode)
    If Not m_Next Is Nothing Then
        Set m_Next.m_Prev = Nothing
    End If
    If Not newval Is Nothing Then
        Set newval.m_Prev = Me
    End If
    Set m_Next = newval
End Property

Public Property Get First() As LinkedListNode
    Set First = Me
    While Not First.m_Prev Is Nothing
        Set First = First.m_Prev
    Wend
End Property

Public Property Get Last() As LinkedListNode
    Set Last = Me
    While Not Last.m_Next Is Nothing
        Set Last = Last.m_Next
    Wend
End Property

Public Function Detach() As LinkedListNode
    If Not m_Prev Is Nothing Then
        Set m_Prev.m_Next = m_Next
        Set Detach = m_Prev
    Else
        Set Detach = m_Next
    End If

    If Not m_Next Is Nothing Then
        Set m_Next.m_Prev = m_Prev
    End If

    Set m_Prev = Nothing
    Set m_Next = Nothing
End Function

Public Sub InsertBefore(ByVal Node As LinkedListNode)
    If Not m_Prev Is Nothing Then
        Set m_Prev.m_Next = Node
    End If
    Set Node.m_Prev = m_Prev
    Set Node.m_Next = Me
    Set m_Prev = Node
End Sub

Public Sub InsertAfter(ByVal Node As LinkedListNode)
    If Not m_Next Is Nothing Then
        Set m_Next.m_Prev = Node
    End If
    Set Node.m_Next = m_Next
    Set Node.m_Prev = Me
    Set m_Next = Node
End Sub

Public Property Get CountBefore() As Integer
    Dim n As LinkedListNode
    CountBefore = 0
    Set n = m_Prev
    While Not n Is Nothing
        CountBefore = CountBefore + 1
        Set n = n.m_Prev
    Wend
End Property

Public Property Get CountAfter() As Integer
    Dim n As LinkedListNode
    CountAfter = 0
    Set n = m_Next
    While Not n Is Nothing
        CountAfter = CountAfter + 1
        Set n = n.m_Next
    Wend
End Property

Public Property Get Count() As Integer
    Count = CountBefore + 1 + CountAfter
End Property
