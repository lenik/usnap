Attribute VB_Name = "Variants"
Option Explicit

Private Const LOCATION                  As String = "VBExt::Variants"

Public HC As New Hashcode

' Common Functions

Public Function Min(arg1, ParamArray args())
    Dim i As Integer
    Min = arg1
    For i = LBound(args) To UBound(args)
        If args(i) < Min Then Min = args(i)
    Next
End Function

Public Function Max(arg1, ParamArray args())
    Dim i As Integer
    Max = arg1
    For i = LBound(args) To UBound(args)
        If args(i) > Max Then Max = args(i)
    Next
End Function

Public Function Avg(arg1, ParamArray args())
    Dim i As Integer
    Avg = arg1
    For i = LBound(args) To UBound(args)
        Avg = Avg + args(i)
    Next
    Avg = Avg / (UBound(args) - LBound(args) + 2)
End Function

Public Function AvgG(arg1, ParamArray args())
    Dim i As Integer
    Assert arg1 > 0, "Parameters of AvgG must be positive numbers", LOCATION
    AvgG = Log(arg1)
    For i = LBound(args) To UBound(args)
        Assert args(i) > 0, "Parameters of AvgG must be positive numbers", LOCATION
        AvgG = AvgG + Log(args(i))
    Next
    AvgG = AvgG / (UBound(args) - LBound(args) + 2)
    AvgG = Exp(AvgG)
End Function

Public Function Hashcode(ByVal var As Variant) As Long
    Hashcode = HC.hcVariant(var)
End Function
