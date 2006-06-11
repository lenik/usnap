VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MemberConnection"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

' I am delegatee
Private WithEvents m_Delegant As Connection
Attribute m_Delegant.VB_VarHelpID = -1
Private m_Buffer As New Buffer

Private m_EventSink As ConnectionEvents

Property Get Delegant() As Connection
    Set Delegant = m_Delegant
End Property

Property Set Delegant(ByVal newval As Connection)
    Set m_Delegant = newval
End Property

Property Get Buffer() As Buffer
    Set Buffer = m_Buffer
End Property

Property Set EventSink(ByVal newval As ConnectionEvents)
    Set m_EventSink = newval
End Property

Private Sub m_Delegant_OnPreReceiveFile(ByVal f As File, Cancel As Boolean)
    Call m_EventSink.OnPreReceiveFile(m_Delegant, f, Cancel)
End Sub

Private Sub m_Delegant_OnPreSendPacket(ByVal Pkt As Packet, Cancel As Boolean)
    Call m_EventSink.OnPreSendPacket(m_Delegant, Pkt, Cancel)
End Sub

Private Sub m_Delegant_OnReceivedFile(ByVal f As File)
    Call m_EventSink.OnReceivedFile(m_Delegant, f)
End Sub

Private Sub m_Delegant_OnReceivingFile(ByVal f As File, Cancel As Boolean)
    Call m_EventSink.OnReceivingFile(m_Delegant, f, Cancel)
End Sub

Private Sub m_Delegant_OnFileCanceled(ByVal f As File)
    Call m_EventSink.OnFileCanceled(m_Delegant, f)
End Sub

Private Sub m_Delegant_OnSendingFile(ByVal f As File, ByRef Cancel As Boolean)
    Call m_EventSink.OnSendingFile(m_Delegant, f, Cancel)
End Sub

Private Sub m_Delegant_OnSentFile(ByVal f As File)
    Call m_EventSink.OnSentFile(m_Delegant, f)
End Sub

Private Sub m_Delegant_OnSentPacket(ByVal Pkt As Packet)
    Call m_EventSink.OnSentPacket(m_Delegant, Pkt)
End Sub
