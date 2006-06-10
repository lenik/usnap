VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Network"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_Driver As ISocketDriver

Public Property Get Commands() As CommandsClient
    ' Not impl.
End Property

Public Function Connect(ByVal RemoteAddress As String) As Client
    Dim h As Long
    Dim s As IClientSocket

    'set s=m_Driver
    's.Connect

    Dim Client As New Client
    'client.setsocket h,sd

    Set Connect = Client
End Function
