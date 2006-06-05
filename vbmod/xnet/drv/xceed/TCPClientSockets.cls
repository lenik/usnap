VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TCPClientSockets"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "XnetXceed::Clients"

Private WithEvents m_Slots As slots
Attribute m_Slots.VB_VarHelpID = -1

Public Property Get Size() As Long
    Size = m_Slots.Size
End Property

Public Function Index2Slot(ByVal Index As Long) As Long
    Index2Slot = m_Slots.Index2Slot(Index)
End Function

Public Property Get FindClient(ByVal c As TCPClientSocket) As Long
    Dim i As Long
    Dim slots As Vector
    Dim Slot As Long
    Set slots = m_Slots.SortSlots
    For i = 0 To slots.Size - 1
        Slot = slots(i)
        If m_Slots.Slot(Slot) Is c Then
            FindClient = Slot
            Exit Property
        End If
    Next
    FindClient = -1
End Property

Public Property Get FindSocket(ByVal s As XceedWinsockLib.ConnectionOrientedSocket) As Long
    Dim c As TCPClientSocket
    Dim i As Long
    Dim slots As Vector
    Dim Slot As Long
    Set slots = m_Slots.SortSlots
    For i = 0 To slots.Size - 1
        Slot = slots(i)
        Set c = m_Slots.Slot(Slot)
        If Not c Is Nothing Then
            If c.Socket Is s Then
                FindSocket = Slot
                Exit Property
            End If
        End If
    Next
    FindSocket = -1
End Property

Public Property Get Slot(ByVal s As Long) As TCPClientSocket
    Assert s >= 0 And s < m_Slots.slots, "index out of bound", LOCATION
    Set Slot = m_Slots.Slot(s)
End Property

Public Property Set Slot(ByVal s As Long, ByVal newval As TCPClientSocket)
    Assert s >= 0 And s < m_Slots.slots, "index out of bound", LOCATION
    Set m_Slots.Slot(s) = newval
End Property

Public Property Get Item(ByVal Index As Long) As TCPClientSocket
    Assert Index >= 0 And Index < m_Slots.Size, "index out of bound", LOCATION
    Set Item = m_Slots.Item(Index)
End Property

Public Property Set Item(ByVal Index As Long, ByVal newval As TCPClientSocket)
    Assert Index >= 0 And Index < m_Slots.Size, "index out of bound", LOCATION
    Set m_Slots.Item(Index) = newval
End Property

Public Function Add(ByVal c As TCPClientSocket) As Long
    Add = m_Slots.Add(c)
End Function

Public Sub Remove(ByVal Slot As Long)
    m_Slots.Remove Slot
End Sub

Private Sub Class_Initialize()
    Set m_Slots = New slots
End Sub

Private Sub m_Slots_Create(ByVal Slot As Long, ByVal Param As Variant, NewVar As Variant)
    Set NewVar = Param
End Sub

Private Sub m_Slots_Remove(ByVal Slot As Long)
    '
End Sub
