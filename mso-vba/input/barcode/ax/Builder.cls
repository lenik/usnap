VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Builder"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Enum BarcodeSystemConstants
    barCode39 = 0
    barEAN_8
    barEAN_13
    barEAN_128
    barUPC_A
    barUPC_B
    barUPC_C
    barUPC_D
    barUPC_E
    barCodebar
End Enum

Private m_EAN_8 As New EAN_8
Private m_EAN_13 As New EAN_13

Public Function BuildBarcode(ByVal Message As String, Optional ByVal System As BarcodeSystemConstants, Optional ByVal FontParam As String) As String
    If Message = "" Then
        Select Case System
        Case barCode39
        Case barEAN_8
            BuildBarcode = m_EAN_8.BuildWithUI()
        Case barEAN_13
            BuildBarcode = m_EAN_13.BuildWithUI()
        Case barEAN_128
        Case barUPC_A
        Case barUPC_B
        Case barUPC_C
        Case barUPC_D
        Case barUPC_E
        Case barCodebar
        End Select
    Else
        Select Case System
        Case barCode39
        Case barEAN_8
            BuildBarcode = m_EAN_8.Build(Message, FontParam)
        Case barEAN_13
            BuildBarcode = m_EAN_13.Build(Message, FontParam)
        Case barEAN_128
        Case barUPC_A
        Case barUPC_B
        Case barUPC_C
        Case barUPC_D
        Case barUPC_E
        Case barCodebar
        End Select
    End If
End Function
