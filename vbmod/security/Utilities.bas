Attribute VB_Name = "Utilities"
Option Explicit

Public Function CreatePKIEntity(ByVal PublicKey As String, ByVal PrivateKey As String) As PKIEntity
    Dim e As New PKIEntity
    e.PublicKey = PublicKey
    e.PrivateKey = PrivateKey
    Set CreatePKIEntity = e
End Function
