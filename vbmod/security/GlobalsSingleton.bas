Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public Function ConnectPKIRegistry(ByVal ClientKey As String) As PKIRegistry
    Dim r As New PKIRegistry
    r.ClientKey = ClientKey
    Set ConnectPKIRegistry = r
End Function
