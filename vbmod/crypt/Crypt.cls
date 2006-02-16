VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MdbCrypt"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function EncryptMdb(ByVal path As String) As Boolean
    Dim f As Integer
    Dim key As Integer

    f = FreeFile

    ' 00 00 01 00 ... ==>
    ' DE AD xx xx ...       xx xx: key

    On Error GoTo x
    Open path For Binary As #f

    Close #f

    EncryptMdb = True
    Exit Function

x:
End Function

Public Function DecryptMdb(ByVal path As String) As Boolean

End Function
