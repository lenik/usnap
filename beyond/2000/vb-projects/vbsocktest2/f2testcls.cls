VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "cc"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private aec(0 To 1) As New EasyChar
Public Sub setaec(ByVal index As Integer, ec As EasyChar)
        copyEChar aec(index), ec
End Sub

Private Sub Class_Initialize()
        MsgBox "CC_Init"
End Sub

Private Sub Class_Terminate()
        MsgBox "CC_Term"
End Sub
