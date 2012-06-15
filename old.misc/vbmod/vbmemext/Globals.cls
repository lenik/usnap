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

Public Function StringBToByteArray(ByVal s As String) As ByteArray
    StringBToByteArray = Functions.StringBToByteArray(s)
End Function

Public Function StringToByteArray(ByVal s As String, _
                                  Optional ByVal Charset As String = "") As ByteArray
    StringToByteArray = Functions.StringToByteArray(s, Charset)
End Function

Public Function BytesToByteArray(ByRef b() As Byte) As ByteArray
    BytesToByteArray = Functions.BytesToByteArray(b)
End Function
