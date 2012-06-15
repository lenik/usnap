Attribute VB_Name = "modFingerText"
Option Explicit

Public paperDowned As Integer   ' 0:wait 1:canceled -1:downed

Public tempText As New EasyText, tempContent As String, LeftContent As String
Public validText As New EasyText, validResult As COMPRESULT, cResult As COMPRESULT
Public inputText As New EasyText, inputContent As String
Public template_FingerChar As New EasyChar

Public Const FC_LINEMAX = 52

Public Function encodeCompResult(cr As COMPRESULT) As String
        encodeCompResult = lt_s.encodePart("COMPRESULT") & _
                        lt_s.encodePart(cr.Right) & _
                        lt_s.encodePart(cr.wrong) & _
                        lt_s.encodePart(cr.extra) & _
                        lt_s.encodePart(cr.lost)
End Function
Public Function decodeCompResult(cr As String) As COMPRESULT
        If lt_s.decodePart(cr, 1) = "COMPRESULT" Then
                With decodeCompResult
                        .Right = lt_s.decodePart(cr, 2)
                        .wrong = lt_s.decodePart(cr, 3)
                        .extra = lt_s.decodePart(cr, 4)
                        .lost = lt_s.decodePart(cr, 5)
                End With
        End If
End Function

Public Sub PrepareText(Optional ByVal userGetData As Boolean = True)
        If userGetData Then tempContent = frmDataSetup.Run
        LeftContent = tempContent
        inputContent = ""
        validResult.extra = 0
        validResult.lost = 0
        validResult.Right = 0
        validResult.wrong = 0
        validResult.resultRef = ""
        validResult.resultObj = ""
        ContinueText
End Sub
Public Sub ContinueText()
        Dim I As Integer

        Dim maxi As Integer
        maxi = IIf(inputText.MaxRow < tempText.MaxRow, inputText.MaxRow, tempText.MaxRow)

        For I = 0 To maxi
                cResult = FuzzyComp(tempText.GetChar(I).Content, inputText.GetChar(I).Content, True)
                With validResult
                        .Right = .Right + cResult.Right
                        .wrong = .wrong + cResult.wrong
                        .extra = .extra + cResult.extra
                        .lost = .lost + cResult.lost
                End With
        Next

        If Trim(LeftContent) = "" Then
                If Mode = M_client Then
                        frmMessage.Run "正在自动交卷...", 2
                        If lt_s.decodePart(FN_TextIO(fingerServer.HostName, "FING #EARLY HANDUP"), 1) <> "OK" Then
                                MsgBox "无法连接到服务器!"
                        End If
                Else
                        bHandup = True
                End If
        End If
        tempText.AL_AllocContent LeftContent, 4, , LeftContent
        copyEText validText, tempText, True, False
        tempText.Visible = True
        tempText.Refresh

        validText.RecalcPos
        validText.Visible = True
        validText.Refresh

        inputContent = inputContent & inputText.TextNL

        inputText.MaxItems = tempText.Count
        inputText.SetSize 1
        inputText.GetChar(0).Content = ""
        inputText.Row = 0
        inputText.Col = 0
        inputText.Refresh

        If frmMain.picBack.AutoRedraw Then frmMain.picBack.Refresh
End Sub

Public Sub FingerPressed(KeyAscii As Integer)
        Dim Row As Integer
        'On Error Resume Next

        If Mode = M_Idle Then Exit Sub

        If KeyAscii = 13 Or KeyAscii = 8 Then Exit Sub
        If KeyAscii >= 32 Or KeyAscii < 0 Then
                With inputText
                        .AL_InsertContent .Row, .Col, Chr(KeyAscii), True
                        If .Row >= .MaxRow And Not .moveRight Then ContinueText: Exit Sub
                End With
        End If
        inputText.Refresh
        inputText.SetCaret
        Row = inputText.Row

        cResult = FuzzyComp( _
                tempText.GetChar(Row).Content, _
                inputText.GetChar(Row).Content)
        validText.GetChar(Row).Content = cResult.resultRef
        validText.GetChar(Row).redraw
        If frmMain.picBack.AutoRedraw Then frmMain.picBack.Refresh
End Sub
Public Sub FingerDown(KeyCode As Integer, Shift As Integer)
        Dim shouldRefresh As Boolean
        If Mode = M_Idle Then Exit Sub

        shouldRefresh = True
        With inputText
                Select Case KeyCode
                Case 13:
                        If .Row >= tempText.MaxRow Then
                                ContinueText
                        Else
                                .AL_InsertBreak
                        End If
                Case 38: .moveUp
                Case 40: .moveDown
                Case 37: .moveLeft
                Case 39: .moveRight
                Case 36: .Col = 0
                Case 35: .Col = .MaxCol(.Row) + 1
                Case 45 ' Insert
                        'inputText.AL_DeleteContent
                Case 46 'Delete
                        .AL_DeleteRight
                Case 8 'BackSpace
                        .AL_DeleteLeft
                Case Else
                        shouldRefresh = False
                End Select
        End With
        If shouldRefresh Then FingerPressed 0
End Sub
Public Sub FingerUp(KeyCode As Integer, Shift As Integer)
End Sub
