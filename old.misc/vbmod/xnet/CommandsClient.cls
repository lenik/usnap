VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CommandsClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_Port As Long
'
'Public Property Get Client(ByVal ServerHost As String) As Client
'    Set Client = Connect(ServerHost, m_Port)
'End Property

Public Property Get Port() As Long
    Port = m_Port
End Property

Public Property Let Port(ByVal newval As Long)
    m_Port = newval
End Property

Public Sub SendMessage(ByVal ServerHost As String, ByVal Message As String)
    'Client(ServerHost).SendMessage Message
End Sub

'public function
Private Sub Class_Initialize()
    m_Port = DEFAULT_PORT
End Sub
