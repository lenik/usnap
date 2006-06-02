VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ConnectonEvents"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Sub OnConnect()

End Sub
Public Sub OnDisconnect()

End Sub

Public Sub OnPreRecvPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)

End Sub
Public Sub OnRecvPacket(ByVal Pkt As Packet)

End Sub

Public Sub OnPreSendPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)

End Sub
Public Sub OnSentPacket(ByVal Pkt As Packet)

End Sub
