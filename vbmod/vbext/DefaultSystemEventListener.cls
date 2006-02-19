VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "DefaultSystemEventListener"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_RefCollectLoop As Integer

Implements SystemEventListener

Private Sub Class_Initialize()
    m_RefCollectLoop = MAX_REFTYPE
End Sub

Private Sub SystemEventListener_Handler(ByVal e As SystemEventConstants, Parameters As Variant)
    Select Case e
    Case vbxMemoryLow
        ' Collect 1 ref, each time.
        g_Ref(m_RefCollectLoop).Collect
        m_RefCollectLoop = m_RefCollectLoop - 1
        If m_RefCollectLoop < 0 Then m_RefCollectLoop = MAX_REFTYPE
    Case vbxNetworkConnected
        '
    Case vbxNetworkDisconnected
        '
    End Select
End Sub
