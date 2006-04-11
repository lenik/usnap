VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ForceCast"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function ByteOf(var) As Byte
    If Not IsNull(var) Then ByteOf = CByte(var)
End Function

Public Function IntegerOf(var) As Integer
    If Not IsNull(var) Then IntegerOf = CInt(var)
End Function

Public Function LongOf(var) As Long
    If Not IsNull(var) Then LongOf = CLng(var)
End Function

Public Function SingleOf(var) As Single
    If Not IsNull(var) Then SingleOf = CSng(var)
End Function

Public Function DoubleOf(var) As Double
    If Not IsNull(var) Then DoubleOf = CDbl(var)
End Function

Public Function StringOf(var) As String
    If Not IsNull(var) Then StringOf = CStr(var)
End Function

Public Function BooleanOf(var) As Boolean
    If Not IsNull(var) Then BooleanOf = CBool(var)
End Function

Public Function DateOf(var) As Date
    If Not IsNull(var) Then DateOf = CDate(var)
End Function

Public Function CurrencyOf(var) As Currency
    If Not IsNull(var) Then CurrencyOf = CCur(var)
End Function

Public Function ObjectOf(var) As Object
    If IsObject(var) Then Set ObjectOf = var
End Function

Public Function VariantOf(var) As Variant
    If Not IsNull(var) Then LC.Assign VariantOf, var
End Function
