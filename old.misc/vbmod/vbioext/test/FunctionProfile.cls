VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "FunctionProfile"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_init_time As Double

Private Sub Class_Initialize()
    m_init_time = Timer
End Sub

Private Sub Class_Terminate()
    Dim cost As Double
    cost = Timer - m_init_time
    Debug.Print "Cost " & Int(cost * 1000) & "ms"
End Sub
