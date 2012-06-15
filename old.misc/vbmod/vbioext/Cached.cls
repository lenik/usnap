VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Cached"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function LoadPicture(Optional FileName, Optional Size, Optional ColorDepth, Optional X, Optional Y) As IPictureDisp
    ' if reftable(filename).get
    Set LoadPicture = VB.LoadPicture(FileName, Size, ColorDepth, X, Y)
End Function

Public Function LoadFile() As String
    LoadFile
End Function
