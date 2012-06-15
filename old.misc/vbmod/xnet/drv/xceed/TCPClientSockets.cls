VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MemberClients"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "XnetXceed::Connections"

' Slot<ConnectionId>
Private WithEvents m_Slots As VBIOExt.Slots
Attribute m_Slots.VB_VarHelpID = -1

Public Property Get Size() As Long
    Size = m_Slots.Size
End Property

Public Property Get Id(ByVal Index As Long) As Long
    Id = m_Slots.Index2Slot(Index)
End Property

' xCOS -> Connection Id
Public Property Get FindSocket(ByVal xCOS As XceedWinsockLib.ConnectionOrientedSocket) As Long
    Dim mc As MemberClient
    Dim i As Long
    Dim mcIndexed As Vector
    Dim mcSlot As Long
    Set mcIndexed = m_Slots.SortSlots
    For i = 0 To mcIndexed.Size - 1
        mcSlot = mcIndexed(i)
        Set mc = m_Slots.Slot(mcSlot)
        If Not mc Is Nothing Then
            'If mc.Socket Is xCOS Then
                FindSocket = mcSlot
                Exit Property
            'End If
        End If
    Next
    FindSocket = -1
End Property

Public Property Get Item(ByVal Id As Long) As MemberClient
    Assert Id >= 0 And Id < m_Slots.Slots, "Invalid Id", LOCATION
    Set Item = m_Slots.Slot(Id)
End Property

Public Property Set Item(ByVal Id As Long, ByVal newval As MemberClient)
    Assert Id >= 0 And Id < m_Slots.Slots, "Invalid Id", LOCATION
    Set m_Slots.Slot(Id) = newval
End Property

Public Function Add(ByVal mc As MemberClient) As Long
    Add = m_Slots.Add(mc)
End Function

Public Sub Remove(ByVal Slot As Long)
    m_Slots.Remove Slot
End Sub

Private Sub Class_Initialize()
    Set m_Slots = New Slots
End Sub

Private Sub m_Slots_Create(ByVal Slot As Long, ByVal Param As Variant, NewVar As Variant)
    ' Assert IsObject(Param)
    ' Assert Param instanceof MemberClient
    Set NewVar = Param
End Sub

Private Sub m_Slots_Remove(ByVal Slot As Long)
    '
End Sub
