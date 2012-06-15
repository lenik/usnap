VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "PersonPO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public name
Public birthday
Public sex

Public Property Get Age()
    Age = DateDiff("yyyy", birthday, Now)
End Property

Public Property Get EnglishSex() As String
    Select Case LCase(CStr(sex))
    Case "f"
    Case "female"
    Case "Ů"
    Case "false"
        EnglishSex = "f"
    Case Else
        EnglishSex = "m"
    End Select
End Property
