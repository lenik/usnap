Attribute VB_Name = "modGraph"
Option Explicit

' ֱ��, ���κ�Բ�ĺ�˷�ɢת���㷨
'
'       ͼ�������ͼ��ת���е�һ�ּ�����
'       �����ͼ��ת���Ӵ������Ͽ��Է�Ϊ����, һ����ǰ��ת��,
'           ǰ��ת����ָ��ͼ��ĵ���������δ����֮ǰ���Ѿ���ת��,
'           ����˵��ֱ�ߵ���תת��, ͨ����ֱ�߷���f1������ת�任
'           ������ֱ�߷���f2����һ���Ǻ��ת��, ���ת����ָ��ͼ
'           �����������֪������¶�ͼ�����ת���������ͼ��M ��
'           ת, ���Խ�ͼ��M �и��������ת����
'       ���������¼����ͼ��ת��������Ϊ�Ǻ��ת��������������
'           ������ͼ��ķ��̶����Խ���ǰ��ת���ġ�ͼ��������Ǻ�
'           ��ת����
'       ���Ƶ������ͼ������е�һ�ּ���������������ͼ���еĹ���
'           ���Ƶ��λ�ù�ϵ���в�ֵ����, ������ɱ��ζ�����
'       ��ɢת����л���������һ�ֿ��Ƶ�����㷨, ����ȥ���ڽ���
'           �صĸ��ٴ�������������ʵ�ַ�������ɢת����Ҫ����
'           ��ͼ�������ͬ��Ŀ�Ŀ��Ƶ㡣

' ͼ�����ӿ�
        Public pic As PictureBox

' ͼ����ʾ����
        Type POINT
                X As Double
                Y As Double
        End Type
        Type POINTR             ' ������
                Pr As Integer   ' ����������
                Po As Integer   ' ������������
        End Type

        Public sStep As Double  ' ��ֵ���

' ��ɢת��
        ' ŷ����¾���
        Private Function Edistance(a As POINT, b As POINT) As Double
                Edistance = Sqr((b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y))
        End Function
        ' ��ɢת��
        '       fromNodes()     Դͼ����Ƶ�
        '       nFromNodes      Դͼ����Ƶ���
        '       toNodes()       Ŀ��ͼ����Ƶ�
        '       nToNodes        Ŀ��ͼ����Ƶ���
        Public Function RTrans(fromNodes() As POINT, _
                          ByVal nFromNodes As Integer, _
                          toNodes() As POINT, _
                          ByVal nToNodes As Integer) As Boolean
                Dim rTable(0 To 255) As POINTR, rUsed As Integer        ' ������
                Dim i As Integer, ii As Integer, iii As Integer         ' ѭ������
                Dim s As Double, sNear As Double, sNearI As Integer     ' �����ҳ��������
                Dim bExisted As Boolean
                Dim Pr As POINT, Po As POINT, Plast As POINT
                Dim slider As Double                                    ' ��ֵ��(������: [0,1])

                RTrans = False
                If nFromNodes < 0 Or nFromNodes > 255 Then Exit Function
                If nToNodes < 0 Or nToNodes > 255 Then Exit Function

                ' ���������
                rUsed = 0
                        ' 1. �ҳ���Ŀ����Ƶ������Դ���Ƶ�
                        For i = 0 To nToNodes - 1
                                rTable(rUsed).Pr = i
                                rTable(rUsed).Po = -1
                                sNear = -1
                                For ii = 0 To nFromNodes - 1
                                        s = Edistance(fromNodes(ii), toNodes(i))
                                        If s < sNear Or sNear < 0 Then
                                                sNear = s
                                                sNearI = ii
                                        End If
                                Next
                                If sNear >= 0 Then rTable(rUsed).Po = sNearI
                                rUsed = rUsed + 1
                        Next
                        ' 2. �ҳ������Դ���Ƶ��Ӧ����Դ���Ƶ������Ŀ����Ƶ�
                        For i = 0 To nFromNodes - 1
                                bExisted = False
                                For ii = 0 To rUsed - 1
                                        If rTable(ii).Po = i Then
                                                bExisted = True
                                                Exit For
                                        End If
                                Next
                                If Not bExisted Then
                                        rTable(rUsed).Po = i
                                        rTable(rUsed).Pr = -1
                                        sNear = -1
                                        For ii = 0 To nToNodes - 1
                                                s = Edistance(fromNodes(i), toNodes(ii))
                                                If s < sNear Or sNear < 0 Then
                                                        sNear = s
                                                        sNearI = ii
                                                End If
                                        Next
                                        If sNear >= 0 Then rTable(rUsed).Pr = sNearI
                                        rUsed = rUsed + 1
                                End If
                        Next
                ' ��ֵ����
                        slider = 0
                        Do While slider <= 1.001
                                pic.Cls
                                For i = 0 To rUsed
                                        Pr = toNodes(rTable(i Mod rUsed).Pr)
                                        Po = fromNodes(rTable(i Mod rUsed).Po)
                                        Pr.X = slider * Pr.X + (1 - slider) * Po.X
                                        Pr.Y = slider * Pr.Y + (1 - slider) * Po.Y
                                        If i = 0 Then
                                                pic.PSet (Pr.X, Pr.Y)
                                        Else
                                                pic.Line (Plast.X, Plast.Y)-(Pr.X, Pr.Y)
                                        End If
                                        Plast = Pr
                                Next
                                pic.Refresh
                                DoEvents
                                slider = slider + IIf(sStep <= 0.001, 0.001, sStep)
                        Loop
        End Function
