VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BaseFunctions"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBExt::BaseFunctions"

' Predicates

Public Function Test(var) As Boolean
    If IsObject(var) Then
        Test = Not var Is Nothing
    ElseIf IsArray(var) Then
        Test = UBound(var) >= LBound(var)
    Else
        Test = CBool(var)
    End If
End Function

Public Function StringP(var) As Boolean
    StringP = VarType(var) = vbString
End Function

Public Function NumberP(var) As Boolean
    Select Case VarType(var)
    Case vbByte, vbDecimal, vbDouble, vbInteger, vbLong, vbSingle
        NumberP = True
    End Select
End Function

' Common Functions

Public Function Min(arg1, ParamArray args())
    Min = Variants.Min(arg1, args)
End Function

Public Function Max(arg1, ParamArray args())
    Max = Variants.Max(arg1, args)
End Function

Public Function Avg(arg1, ParamArray args())
    Avg = Variants.Avg(arg1, args)
End Function

Public Function AvgG(arg1, ParamArray args())
    AvgG = Variants.AvgG(arg1, args)
End Function

' Hashcode

Public Function Hashcode(v As Variant) As Long
    Hashcode = Variants.Hashcode(v)
End Function

' Type Parser

Public Function ParseMap(ByVal str As String) As VBExt.Map
    Set ParseMap = Typedefs.ParseMap(str)
End Function

' ParamArray Fixes

Public Function ParamArrayToArray(ParamArray params_()) As Variant()
    Dim Params
    Params = params_(0)
    Dim l As Integer
    l = LBound(Params)
    If l = UBound(Params) Then
        If TypeName(Params(l)) = "Variant()" Then
            ParamArrayToArray = Params(l)
            Exit Function
        End If
    End If
    ParamArrayToArray = Params
End Function

' File System

Public Function DirName(ByVal Path As String) As String
    Dim pos As Integer
    pos = Max(InStrRev(Path, "\"), InStrRev(Path, "/"))

    If pos > 0 Then
        DirName = Left(Path, pos - 1)
    Else
        DirName = "."
    End If
End Function

Public Function BaseName(ByVal Path As String) As String
    Dim pos As Integer
    pos = Max(InStrRev(Path, "\"), InStrRev(Path, "/"))

    If pos > 0 Then
        BaseName = Mid(Path, pos + 1)
    Else
        BaseName = Path
    End If
End Function
