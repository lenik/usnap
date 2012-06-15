VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "LinkedList"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBExt::LinkedList"

Private m_Front As LinkedListNode
Private m_Back As LinkedListNode

Public Property Get Front()
    If Not m_Front Is Nothing Then
        LC.Assign Front, m_Front.Data
    End If
End Property

Public Property Get Back()
    If Not m_Back Is Nothing Then
        LC.Assign Back, m_Back.Data
    End If
End Property

Public Property Get Count() As Integer
    If Not m_Front Is Nothing Then
        Count = 1 + m_Front.CountAfter
    End If
End Property

Public Sub Push(ByVal var)
    Dim n As New LinkedListNode
    n.Data = var
    If m_Back Is Nothing Then
        Set m_Back = n
        Set m_Front = m_Back
    Else
        m_Back.InsertAfter n
        Set m_Back = m_Back.m_Next
    End If
End Sub

Public Sub Unshift(ByVal var)
    Dim n As New LinkedListNode
    n.Data = var
    If m_Front Is Nothing Then
        Set m_Front = n
        Set m_Back = m_Front
    Else
        m_Front.InsertBefore n
        Set m_Front = m_Front.m_Prev
    End If
End Sub

Public Function Pop()
    Assert Not m_Back Is Nothing, "No element to pop out", LOCATION
    LC.Assign Pop, m_Back.Data
    Set m_Back = m_Back.m_Prev
    If m_Back Is Nothing Then
        Set m_Front = Nothing
    Else
        Set m_Back.m_Next = Nothing
    End If
End Function

Public Function Shift()
    Assert Not m_Front Is Nothing, "No element to shift out", LOCATION
    LC.Assign Shift, m_Front.Data
    Set m_Front = m_Front.m_Next
    If m_Front Is Nothing Then
        Set m_Back = Nothing
    Else
        Set m_Front.m_Prev = Nothing
    End If
End Function

Public Sub Walk(ByVal it As Iterator)
    ' it.Iterate
End Sub
