Attribute VB_Name = "modAlgUtil_1"

Public Function LogAB(ByVal a As Double, ByVal b As Double) As Double
    LogAB = Log(b) / Log(a)
End Function

Public Function Pow2(ByVal x As Long) As String
    Dim dv As Double
    Dim sv As String
    dv = 1.6 ^ x
    sv = Trim(Str(dv))

    Dim j As Integer
    Dim sl As String, sr As String

    j = InStr(sv, ".")
    If j > 0 Then
        sl = Left(sv, j - 1)
        sr = Mid(sv, j + 1)
        sr = sr & String(x - Len(sr), "0")
    Else
        sl = sv
        sr = String(x, "0")
    End If

    Pow2 = sl & sr
End Function
