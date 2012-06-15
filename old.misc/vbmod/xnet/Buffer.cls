VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Buffer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_InputBuffer As New InputBuffer

Public Sub AddBytes(ByRef B() As Byte)
    m_InputBuffer.AddBytes B
End Sub

Public Property Get PacketReady() As Boolean
    PacketReady = m_InputBuffer.StatementReady
End Property

Public Function NextPacket() As Packet
    If PacketReady Then
        Dim st As Statement
        Set st = m_InputBuffer.GetStatement

        Set NextPacket = New Packet
        Set NextPacket.Statement = st
    End If
End Function

Public Property Get QueuedBytes() As Long
    QueuedBytes = m_InputBuffer.UnreadSize
End Property

Public Property Get ProcessedBytes() As Long
    ProcessedBytes = m_InputBuffer.UsedSize - m_InputBuffer.UnreadSize
End Property

Property Get AllocatedBytes() As Long
    AllocatedBytes = m_InputBuffer.AllocatedSize
End Property
