VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Globals"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBUserExt::Globals"

Public Function CreateAnimateSteps(ParamArray args()) As AnimateStep
    If UBound(args) > LBound(args) Then
        Set CreateAnimateSteps = GlobalsSingleton.CreateAnimateSteps(Array(args))
    Else
        Set CreateAnimateSteps = GlobalsSingleton.CreateAnimateSteps(args(LBound(args)))
    End If
End Function
