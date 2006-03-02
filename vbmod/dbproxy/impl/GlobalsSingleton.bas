Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public Property Get Dict() As DBDict
    LC.Assign Dict, Ref(vbxSoftReference, "DBProxy::Dict")
    If IsNull(Dict) Then
        Set Dict = RebuildDict
        'Ref(vbxSoftReference, "DBProxy::Dict") = refDict
    End If
End Property

Public Function RebuildDict() As DBDict
    Dim conn
    'Set conn = DefaultConnection

    ' Dict tables...
End Function
