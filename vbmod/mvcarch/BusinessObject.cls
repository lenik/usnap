VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BusinessObject"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Event Load(PO, Chapter, Parameter)
Event Save(PO, Chapter, Parameter)
Event Convert(PO, Chapter, Parameter)

Public Enum CommonChapterConstants
    ccDefault = 0
    ccBegin = &H80000001
    ccEnd
    ccMove                  ' Parameter: prev next first last
End Enum

Public Sub Load(PO As PlainObject, Optional ByVal Chapter As CommonChapterConstants, Optional Parameter)
End Sub

Public Sub Save(PO As PlainObject, Optional ByVal Chapter As CommonChapterConstants, Optional Parameter)
End Sub

Public Sub Convert(PO As PlainObject, Optional ByVal Chapter As CommonChapterConstants, Optional Parameter)
End Sub
