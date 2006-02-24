VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Reference"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
Option Base 0

' Tag Class

Public Property Get Ref(ByVal Name As String) As Object
Attribute Ref.VB_Description = "Dereference"
Attribute Ref.VB_UserMemId = 0
End Property

Public Property Let Ref(ByVal Name As String, ByVal newval As Object)
End Property

Public Sub Collect()
End Sub
