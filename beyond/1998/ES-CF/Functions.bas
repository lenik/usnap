Attribute VB_Name = "modFunctions"
Option Explicit

Function GenN(S As String) As Integer
    Dim p As Integer, t As Long
    t = 0
    For p = 1 To Len(S)
        t = t + Abs(Asc(Mid(S, p, 1)))
    Next
    GenN = t Mod 100
End Function

Function ToStr(n As Integer, Length As Integer) As Integer
    Dim l As Integer
    ToStr = Trim(Str(n))
    If Len(ToStr) > Length Then
        ToStr = Right(ToStr, Length)
    Else:
        l = Length - Len(ToStr)
        If l > 0 Then ToStr = String(l, "0")
    End If
End Function

Function GenID() As String
    Dim i As Integer
    i = GenN(frmMain.txtClass01) + GenN(frmMain.txtClass02)
    GenID = Trim(Str(frmMain.cboSubject.ListIndex))
    GenID = GenID + ToStr(i, 2)
End Function

Function TStr(S As String) As String
    TStr = S
End Function

Sub PrintHead(F As Integer)
    Print #F, "--------------------------------------------------------------" + NewLine
    Print #F, "    数据产生: 东晖文学站 投稿指南    版权所有:桃壳软件/谢继雷" + NewLine
    Print #F, "--------------------------------------------------------------" + NewLine

    Print #F, "时间: " + Str(Date) + Space + Str(Time)
    Print #F, frmMain.lblSubject + Space + frmMain.cboSubject.Text
    Print #F, frmMain.lblContributor + Space + frmMain.txtClass01 + frmMain.txtClass02 + Space + frmMain.txtContributor
    Print #F, frmMain.lblLeave + Space + frmMain.txtLeave + NewLine

    If Trim(Intro) <> "" Then
        Print #F, "作者简介:"
        Print #F, Intro + NewLine
    End If
End Sub

Sub PrintEnd(F As Integer)
    Print #F, "----结束------------------------------------------------------" + NewLine
End Sub
