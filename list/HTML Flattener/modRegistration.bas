Attribute VB_Name = "modRegistration"
Option Explicit


Const V_OK = "V_OK"
Const V_FR = "V_FR"

Public Ver_Registered

Public Property Get IsRegistered() As Boolean
    If Ver_Registered = V_OK Then
        IsRegistered = True
    Else
        IsRegistered = True
    End If
End Property
