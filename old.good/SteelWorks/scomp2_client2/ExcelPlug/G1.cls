VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "G1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public MagicNum As Long

Public s_tempfile As String
Public s_configfile As String
Public s_scoreplugfile As String        ' without extension name
Public s_algor As String
Public s_decor As String
Public s_score As String
Public n_w1 As Long
Public n_d1 As Long
Public n_fuzzy As Single
Public n_precise As Long

Public b_dllfile As Boolean
Public b_activexfile As Boolean

Public s_savetofile As String

Public code_scorelist As String
Public code_scorelist_num As Long

Public b_showExcelWindow As Boolean

Public Sub ClearCode()
        code_scorelist = ""
        code_scorelist_num = 0
End Sub
Public Function AddScore(ByVal objname As String, ByVal match As Long, ByVal unmatch As Long, ByVal extra As Long, ByVal lost As Long) As String
        AddScore = encodePart( _
                        encodePart(objname, "(") & _
                        encodePart(match, "(") & _
                        encodePart(unmatch, "(") & _
                        encodePart(extra, "(") & _
                        encodePart(lost, "("), _
                        "[")
        code_scorelist = code_scorelist & AddScore
        code_scorelist_num = code_scorelist_num + 1
End Function

Public Sub Generate()
        If MagicNum <> 54656368 Then Exit Sub

        On Error Resume Next

        Set book = CreateObject("Excel.Sheet")
        Set xapp = book.Application
        Set s = book.Worksheets(1)

        If b_showExcelWindow Then
                xapp.WindowState = xlNormal
                xapp.Windows(1).WindowState = xlMaximized
                DoEvents
        End If

        s.Activate
        Set vbc = book.VBProject.VBComponents.Add(vbext_ct_StdModule)

        AddCode

        xapp.OnKey "^%{H}", "hideThisObject"

        s.Name = "��ҳ"

                Set sh = s.Shapes.AddTextbox(msoTextOrientationHorizontal, 80, 15, 400, 33)
                        sh.Name = "��ҳ_��ʾ"
                        sh.TextFrame.Characters.Text = _
                                "������[������|һά������(�ϸ�Ԫ)|ģ�����Ƚ�|���ܽ���|Beta|�����Ƚ�]��������" & vbNewLine & _
                                "���ر���ʾ���밴Ctrl-Alt-H"
                        sh.TextFrame.Characters.Font.Size = 10
                        sh.TextFrame.Characters.Font.Color = &H8000&
                        sh.TextFrame.Characters(46).Font.Color = &H808080
                        sh.TextFrame.HorizontalAlignment = xlHAlignCenter
                        sh.Line.Visible = msoFalse
                        sh.Fill.Visible = msoFalse

                Set sh = s.Shapes.AddTextEffect(msoTextEffect9, "�� �� �� ��", "����", 48, msoFalse, msoFalse, 135, 135)
                        sh.Name = "��ҳ_����"
                Set sh = s.Shapes.AddTextbox(msoTextOrientationHorizontal, 320, 190, 85, 20)
                        sh.Name = "��ҳ_����2"
                        sh.TextFrame.Characters.Text = "�� �� �� �� ��"
                        sh.TextFrame.Characters.Font.Size = 10
                        sh.TextFrame.HorizontalAlignment = xlHAlignRight
                        sh.Line.Visible = msoFalse
                        sh.Fill.Visible = msoFalse

                Set sh = s.Shapes.AddTextbox(msoTextOrientationHorizontal, 75, 280, 200, 30)
                        sh.Name = "��ҳ_��Ȩ"
                        sh.TextFrame.Characters.Text = _
                                "��Ȩ���� (C)�ҿ����� 1997-2001" & vbNewLine & _
                                "Contact: dansei@126.com"
                        s.Hyperlinks.Add sh, "mailto:dansei@126.com?subject=Product(TK5W)?[��������]"
                        sh.TextFrame.Characters.Font.Size = 10
                        sh.TextFrame.Characters.Font.Color = &H606060
                        sh.TextFrame.Characters(23).Font.Color = &HFF0000
                        sh.TextFrame.Characters(23).Font.Underline = True
                        sh.Line.Visible = msoFalse
                        sh.Fill.Visible = msoFalse

        Set s = book.Worksheets.Add(, s)
        s.Name = "����"
                s.Columns("D:D").ColumnWidth = 43

                        s.Range("D5,D7,D9,D11,D13,D15,D17,D19,D21,D23").HorizontalAlignment = xlHAlignLeft
                        s.Range("D6,D8,D10,D12,D14,D16,D18,D20,D22,D24").HorizontalAlignment = xlHAlignRight

                        s.Range("D5").Characters.Text = "ģ���ļ�"
                        s.Range("D7").Characters.Text = "�����ļ�"
                        s.Range("D9").Characters.Text = "�Ʒֲ��"
                        s.Range("D11").Characters.Text = "ʹ���㷨"
                        s.Range("D13").Characters.Text = "���η�"
                        s.Range("D15").Characters.Text = "���"
                        s.Range("D17").Characters.Text = "���"
                        s.Range("D19").Characters.Text = "ģ����"
                        s.Range("D21").Characters.Text = "��ȷ��"

                        s.Range("D6").Characters.Text = s_tempfile
                        s.Range("D8").Characters.Text = s_configfile
                        If b_dllfile Or b_activexfile Then
                                s.Range("D10").Characters.Text = s_scoreplugfile
                        Else
                                s.Range("D10").Characters.Text = "��::" & s_score
                        End If
                        s.Range("D12").Characters.Text = s_algor
                        s.Range("D14").Characters.Text = s_decor
                        s.Range("D16").Characters.Text = n_d1
                        s.Range("D18").Characters.Text = n_w1
                        s.Range("D20").Characters.Text = n_fuzzy
                        s.Range("D22").Characters.Text = n_precise

                Set sh = s.Shapes.AddTextbox(msoTextOrientationHorizontal, 75, 20, 52, 330)
                        sh.Name = "����_�����"
                        sh.Line.Visible = msoFalse
                        sh.Fill.Visible = msoTrue
                        sh.Fill.ForeColor.RGB = &H996666
                        sh.Fill.BackColor.RGB = &HFFFFFF
                        sh.Fill.TwoColorGradient msoGradientVertical, 1

                Set sh = s.Shapes.AddShape(msoShapeBevel, 110, 20, 312, 30)
                        sh.Name = "����_����"
                        sh.TextFrame.Characters.Text = "����"
                        sh.TextFrame.HorizontalAlignment = xlHAlignCenter
                        sh.TextFrame.VerticalAlignment = xlVAlignCenter


        Set s = book.Worksheets.Add(, s)
        s.Name = "��ϸ����"
                s.Rows("1").RowHeight = 60

                Set sh = s.Shapes.AddTextEffect(msoTextEffect13, "�����Ƚ���ϸ����", "����", 36, msoFalse, msoFalse, 30, 12)
                        sh.Name = "����_����"
                        sh.Fill.Visible = msoTrue
                        sh.Fill.ForeColor.RGB = &HFF6633
                        sh.Fill.BackColor.RGB = &H800000
                        sh.Fill.TwoColorGradient msoGradientHorizontal, 1

                With s.Range("2:2")
                        .HorizontalAlignment = xlHAlignCenter
                        .Interior.Color = &HFFFFCC
                        .Interior.Pattern = xlSolid
                        .Font.Color = &HCC0000
                End With
                s.Range("G2").HorizontalAlignment = xlHAlignLeft
                s.Columns("G").ColumnWidth = 40

                s.Range("B2").Characters.Text = "��ȷ"
                s.Range("C2").Characters.Text = "����"
                s.Range("D2").Characters.Text = "����"
                s.Range("E2").Characters.Text = "ȱ��"
                s.Range("F2").Characters.Text = "�Ʒ�"
                s.Range("G2").Characters.Text = "Ŀ���ļ�"

                For i = 1 To code_scorelist_num
                        Dim one As String, rowno As Long
                        one = decodePart(code_scorelist, i, , "[")
                        rowno = i + 2
                        s.Range("B" & rowno).Formula = "=" & decodePart(one, 2, , "(")
                        s.Range("C" & rowno).Formula = "=" & decodePart(one, 3, , "(")
                        s.Range("D" & rowno).Formula = "=" & decodePart(one, 4, , "(")
                        s.Range("E" & rowno).Formula = "=" & decodePart(one, 5, , "(")
                        s.Range("F" & rowno).FormulaR1C1 = "=" & "ScoreMacro(RC[-4], RC[-3], RC[-2], RC[-1])"
                        s.Range("G" & rowno).Characters.Text = decodePart(one, 1, , "(")

                        DoEvents
                Next

        Set s = book.Worksheets.Add(, s)
        s.Name = "����"

        Set s = book.Worksheets.Add(, s)
        s.Name = "ĩҳ"
                Set sh = s.Shapes.AddTextbox(msoTextOrientationHorizontal, 160, 141, 220, 40)
                sh.TextFrame.Characters.Text = "л л ʹ �� !"
                sh.TextFrame.Characters.Font.Size = 10
                sh.TextFrame.HorizontalAlignment = xlHAlignCenter
                sh.Line.Visible = msoFalse
                sh.Fill.Visible = msoFalse

        book.Worksheets("��ҳ").Activate

        book.Close True, s_savetofile
        xapp.Quit

End Sub

Private Sub AddCode()
        Dim codes As String
' �Ʒַ���
        If b_dllfile Then
                codes = codes & _
                        "Declare Function score_for_stream_units_compare Lib """ & s_scoreplugfile & ".dll"" () As Single" & vbNewLine & _
                        "Public Function score(match, unmatch, extra, lost)" & vbNewLine & _
                        "       score = score_for_stream_units_compare(match, unmatch, extra, lost)" & vbNewLine & _
                        "End Function" & vbNewLine & vbNewLine
        ElseIf b_activexfile Then
                codes = codes & _
                        "Public m_scoreplug as Object" & vbNewLine & _
                        "Public Function score(match, unmatch, extra, lost)" & vbNewLine & _
                        "       If m_scoreplug Is Nothing Then Set m_scoreplug = CreateObject(""" & s_scoreplugfile & ".StreamUnitsComparePlugin"")" & vbNewLine & _
                        "       If Not m_scoreplug Is Nothing Then" & vbNewLine & _
                        "               score = m_scoreplug.Score(match, unmatch, extra, lost)" & vbNewLine & _
                        "               Exit Function" & vbNewLine & _
                        "       End If" & vbNewLine & _
                        "End Function" & vbNewLine & vbNewLine
        Else
                s_score = "��ȷ - (���� + ���� + ȱ��) * 5"
                codes = codes & _
                        "Public Function score(match, unmatch, extra, lost)" & vbNewLine & _
                        "       score   = match - (unmatch + extra + lost) * 5" & vbNewLine & _
                        "End Function" & vbNewLine & vbNewLine
        End If
                codes = codes & _
                "Public Function ScoreMacro(match, unmatch, extra, lost)" & vbNewLine & _
                "       ScoreMacro = score(match, unmatch, extra, lost)" & vbNewLine & _
                "       If ScoreMacro < 0 Then ScoreMacro = 0" & vbNewLine & _
                "End Function" & vbNewLine & vbNewLine
' ��������
                codes = codes & _
                "Public Sub hideThisObject()" & vbNewLine & _
                "       Selection.ShapeRange.Visible = False" & vbNewLine & _
                "End Sub" & vbNewLine & vbNewLine & _
                "Public Sub hideObjects()" & vbNewLine & _
                "       " & vbNewLine & _
                "End Sub" & vbNewLine & vbNewLine

        vbc.CodeModule.AddFromString codes
End Sub