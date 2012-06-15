Attribute VB_Name = "modOutBoard"
Option Explicit
Global ln As String, ctab As String

Private Function OutNum(ByVal n As Long, Optional nFixLen As Integer = -1) As String
    OutNum = LTrim(Str(n))
    If nFixLen > 0 Then
        If nFixLen > Len(OutNum) Then OutNum = String(nFixLen - Len(OutNum), "0") + OutNum
    End If
End Function
Private Function OutHex(ByVal n As Long, Optional nFixLen As Integer = -1) As String
    OutHex = Hex(n)
    If nFixLen > 0 Then
        If nFixLen > Len(OutHex) Then OutHex = String(nFixLen - Len(OutHex), "0") + OutHex
    End If
    OutHex = "0x" + OutHex
End Function
Private Function OutBin(ByVal n As Long, Optional nFixLen As Integer = -1) As String
    Dim i As Long
    Dim bs As String
    While n > 0
        bs = IIf(n Mod 2, "1", "0") + bs
        n = n / 2
    Wend

End Function

Private Function OutBool(ByVal b As Boolean, Optional bComment As Boolean = True) As String
    OutBool = IIf(b, "1", "0")
    If bComment Then OutBool = OutBool + ctab + "; " + IIf(b, "True", "False")
End Function

'  ‰≥ˆ∆Â≈Ã ˝æ›
Function OutGame() As String
    OutGame = "[GAME]" + ln
    OutGame = OutGame + "NAME=" + strGameName + ln
    OutGame = OutGame + "CHESSBOARD=" + frmPadGen.cdBackFile.FileName + ln
End Function
Function OutChess() As String
    OutChess = "[CHESS]" + ln
    OutChess = OutChess + "AREASNUM=" + OutNum(nHaveAreas) + ln
    OutChess = OutChess + "TURNINGWASTE=" + OutNum(nTurningWaste) + ln
End Function

Function OutArea(nArea As Integer, Optional bSummary As Boolean = True) As String
    Dim i As Integer
    Dim ne As NodeExpression, be As ButtonExpression
    With Areas(nArea)
        OutArea = "[AREA" + OutNum(nArea) + "]" + ln
        OutArea = OutArea + "NAME=" + .Name + ln
        OutArea = OutArea + "COLOR=" + OutHex(.Color) + ln
        OutArea = OutArea + "PLAYABLE=" + OutBool(.bPlayable) + ln
        OutArea = OutArea + "SORTABLE=" + OutNum(.Sortable) + ln
        OutArea = OutArea + ln
        OutArea = OutArea + "NODESNUM=" + OutNum(.nHaveNodes) + ln
        If Not bSummary Then
            ne.nArea = nArea
            For i = 0 To .nHaveNodes - 1
                ne.nNode = i
                OutArea = OutArea + OutNode(ne)
            Next
            OutArea = OutArea + ln
        End If
        OutArea = OutArea + "BUTTONSNUM=" + OutNum(.nHaveButtons) + ln
        If Not bSummary Then
            be.nArea = nArea
            For i = 0 To .nHaveButtons - 1
                be.nButton = i
                OutArea = OutArea + OutButton(be)
            Next
            OutArea = OutArea + ln
        End If
    End With
End Function

Function OutNode(ne As NodeExpression) As String
    Dim n As TNode
    Dim nn As String
    n = theNode(ne)
    nn = "NODE" + OutNum(ne.nNode)
    OutNode = nn + "=" + OutNum(n.Left) + "," + OutNum(n.Top) + "," + OutNum(n.Width) + "," + OutNum(n.Height)
    OutNode = OutNode + "," + OutHex(n.Style)
End Function

Function OutButton(nb As ButtonExpression) As String

End Function
