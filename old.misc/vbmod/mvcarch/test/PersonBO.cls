VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "PersonBO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const ccKillPerson = 1

Implements BusinessObject

Private Sub BusinessObject_Convert(PO As MVCArch.PlainObject, Optional ByVal Chapter As MVCArch.CommonChapterConstants, Optional Parameter As Variant)
    Select Case Chapter
    End Select
End Sub

Private Sub BusinessObject_Load(PO As MVCArch.PlainObject, Optional ByVal Chapter As MVCArch.CommonChapterConstants, Optional Parameter As Variant)
    Select Case Chapter
    Case Chapter = ccBegin

    End Select
End Sub

Private Sub BusinessObject_Save(PO As MVCArch.PlainObject, Optional ByVal Chapter As MVCArch.CommonChapterConstants, Optional Parameter As Variant)
    Select Case Chapter
    End Select
End Sub
