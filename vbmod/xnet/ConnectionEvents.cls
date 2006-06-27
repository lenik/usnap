VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ConnectionEvents"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Sub OnPreSendPacket(ByVal c As Connection, ByVal Pkt As Packet, ByRef Cancel As Boolean)

End Sub
Public Sub OnSentPacket(ByVal c As Connection, ByVal Pkt As Packet)

End Sub
Public Sub OnUnknownPacket(ByVal c As Connection, ByVal Pkt As Packet)

End Sub

Public Sub OnPreReceiveFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)

End Sub
Public Sub OnReceivingFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)

End Sub
Public Sub OnReceivingFileError(ByVal c As Connection, ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)

End Sub
Public Sub OnReceivedFile(ByVal c As Connection, ByVal f As Xnet.File)

End Sub

Public Sub OnSendingFile(ByVal c As Connection, ByVal f As Xnet.File, ByRef Cancel As Boolean)

End Sub
Public Sub OnSendingFileError(ByVal c As Connection, ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)

End Sub
Public Sub OnSentFile(ByVal c As Connection, ByVal f As Xnet.File)

End Sub

Public Sub OnFileHashing(ByVal c As Connection, ByVal f As Xnet.File, ByVal ProcessedSize As Long)

End Sub
Public Sub OnFileCanceled(ByVal c As Connection, ByVal f As Xnet.File)

End Sub
