Attribute VB_Name = "Module1"
Option Explicit

Enum qztype
        �� = 0
        �ױ�
        ����
        �׳�
        ����
        ����
        ��ʿ
        �׽�
        �ڱ�
        ����
        �ڳ�
        ����
        ����
        ��ʿ
        �ڽ�
End Enum

Public qp(1 To 10, 1 To 9) As qztype
Public qp1(1 To 10, 1 To 9) As qztype
Public qp2(1 To 10, 1 To 9) As qztype


Public ��ǰѡ��
Public ��Ϸģʽ
Public ����

Public Sub swap(X, Y)
        Dim z
        z = X
        X = Y
        Y = z
End Sub

Public Function �׷�(q As qztype) As Boolean
        If q = �ױ� Or q = �׳� Or q = �׽� Or q = ���� Or q = ���� Or q = ��ʿ Or q = ���� Then
                �׷� = True
        Else
                �׷� = False
        End If
End Function

Public Function �ڷ�(q As qztype) As Boolean
        If q = �ڱ� Or q = �ڳ� Or q = �ڽ� Or q = ���� Or q = ���� Or q = ��ʿ Or q = ���� Then
                �ڷ� = True
        Else
                �ڷ� = False
        End If
End Function

' ����(x1,y1)��(x2,y2)���ƶ��Ƿ�Ϸ�
Public Function isvalid(x1, y1, x2, y2) As Boolean
        Dim qz1 As qztype, qz2 As qztype
        isvalid = False
        qz1 = qp(y1, x1)
        qz2 = qp(y2, x2)
        If qz1 = �� Then Exit Function

        If �׷�(qz1) And �׷�(qz2) Then Exit Function
        If �ڷ�(qz1) And �ڷ�(qz2) Then Exit Function

        Select Case qz1
        Case �ױ�
                ' �����ܵ���
                If y2 > y1 Then Exit Function
                ' ��û�й��ӽ�ǰ���ܺ�����
                If y1 > 5 And x2 <> x1 Then Exit Function
                ' һ�β�������������һ������
                If Abs(y1 - y2) > 1 Or Abs(x1 - x2) > 1 Then Exit Function
                ' ����ͬʱ�����������
                If Abs(x1 - x2) > 0 And Abs(y1 - y2) > 0 Then Exit Function
        Case �ڱ�
                If y2 < y1 Then Exit Function
                If y1 <= 5 And x2 <> x1 Then Exit Function
                If Abs(y1 - y2) > 1 Or Abs(x1 - x2) > 1 Then Exit Function
                If Abs(x1 - x2) > 0 And Abs(y1 - y2) > 0 Then Exit Function
        Case ����, ����
                ' ��ֻ����ֱ��
                If Abs(y1 - y2) <> 0 And Abs(x1 - x2) <> 0 Then Exit Function
                ' �����������
                If qp(y2, x2) = �� Then
                        ' �������������������
                        If ��·�谭��Ŀ(x1, y1, x2, y2) > 0 Then Exit Function
                Else
                        ' ����������������һ����
                        If ��·�谭��Ŀ(x1, y1, x2, y2) <> 1 Then Exit Function
                End If
        Case �׳�, �ڳ�
                ' ��ֻ����ֱ��
                If Abs(y1 - y2) <> 0 And Abs(x1 - x2) <> 0 Then Exit Function
                ' ����������
                If ��·�谭��Ŀ(x1, y1, x2, y2) > 0 Then Exit Function
        Case ����, ����
                ' ��ֻ������
                If Abs(x1 - x2) = 2 And Abs(y1 - y2) = 1 Then
                ElseIf Abs(x1 - x2) = 1 And Abs(y1 - y2) = 2 Then
                Else
                        Exit Function
                End If
                ' ��������һ����һб,�������ϲ���������
                If Abs(x1 - x2) > Abs(y1 - y2) Then
                        ' ����Ǻ������
                        If qp(y1, (x1 + x2) / 2) <> �� Then Exit Function
                Else
                        ' ������������
                        If qp((y1 + y2) / 2, x1) <> �� Then Exit Function
                End If
        Case ����
                ' ��ֻ������
                If Abs(x1 - x2) <> 2 Or Abs(y1 - y2) <> 2 Then Exit Function
                ' ��������
                If ��·�谭��Ŀ(x1, y1, x2, y2) > 0 Then Exit Function
                ' ��ֻ�������̵�һ�벿�ֻ
                If y2 < 6 Then Exit Function
        Case ����
                If Abs(x1 - x2) <> 2 Or Abs(y1 - y2) <> 2 Then Exit Function
                If ��·�谭��Ŀ(x1, y1, x2, y2) > 0 Then Exit Function
                If y2 > 5 Then Exit Function
        Case ��ʿ
                ' ʿֻ����һ��б��
                If Abs(x1 - x2) <> 1 Or Abs(y1 - y2) <> 1 Then Exit Function
                ' ʿֻ����3x3�ĸ�������
                If x2 < 4 Or x2 > 6 Or y2 < 8 Then Exit Function
        Case ��ʿ
                If Abs(x1 - x2) <> 1 Or Abs(y1 - y2) <> 1 Then Exit Function
                If x2 < 4 Or x2 > 6 Or y2 > 3 Then Exit Function
        Case �׽�
                ' ��ֻ����һ��ֱ��
                If Abs(x1 - x2) = 1 And Abs(y1 - y2) = 0 Then
                ElseIf Abs(x1 - x2) = 0 And Abs(y1 - y2) = 1 Then
                Else
                        Exit Function
                End If
                ' ��ֻ����3x3�ĸ�������
                If x2 < 4 Or x2 > 6 Or y2 < 8 Then Exit Function
        Case �ڽ�
                If Abs(x1 - x2) = 1 And Abs(y1 - y2) = 0 Then
                ElseIf Abs(x1 - x2) = 0 And Abs(y1 - y2) = 1 Then
                Else
                        Exit Function
                End If
                If x2 < 4 Or x2 > 6 Or y2 > 3 Then Exit Function
        End Select

        isvalid = True
End Function

Public Function ��·�谭��Ŀ(ByVal x1, ByVal y1, ByVal x2, ByVal y2) As Long
        Dim X, Y

        ��·�谭��Ŀ = 0

        If x1 = x2 And y1 <> y2 Then
                ' ����
                If y1 > y2 Then swap y1, y2
                For Y = y1 + 1 To y2 - 1
                        If qp(Y, x1) <> �� Then ��·�谭��Ŀ = ��·�谭��Ŀ + 1
                Next
        ElseIf x1 <> x2 And y1 = y2 Then
                ' ����
                If x1 > x2 Then swap x1, x2
                For X = x1 + 1 To x2 - 1
                        If qp(y1, X) <> �� Then ��·�谭��Ŀ = ��·�谭��Ŀ + 1
                Next
        Else
                ' б��
                For X = x1 To x2 Step Sgn(x2 - x1)
                        Y = Int((y2 - y1) / (x2 - x1) * X + (y1 * x2 - y2 * x1) / (x2 - x1))
                        If qp(Y, X) <> �� Then ��·�谭��Ŀ = ��·�谭��Ŀ + 1
                Next
                If qp(y1, x1) <> �� Then ��·�谭��Ŀ = ��·�谭��Ŀ - 1
                If qp(y2, x2) <> �� Then ��·�谭��Ŀ = ��·�谭��Ŀ - 1
        End If
End Function

Public Sub init()
        Dim X, Y
        For Y = 1 To 10
                For X = 1 To 9
                        qp(Y, X) = ��
                Next
        Next
        qp(10, 1) = �׳�
        qp(10, 2) = ����
        qp(10, 3) = ����
        qp(10, 4) = ��ʿ
        qp(10, 5) = �׽�
        qp(10, 6) = ��ʿ
        qp(10, 7) = ����
        qp(10, 8) = ����
        qp(10, 9) = �׳�
        qp(8, 2) = ����
        qp(8, 8) = ����
        qp(7, 1) = �ױ�
        qp(7, 3) = �ױ�
        qp(7, 5) = �ױ�
        qp(7, 7) = �ױ�
        qp(7, 9) = �ױ�

        qp(1, 1) = �ڳ�
        qp(1, 2) = ����
        qp(1, 3) = ����
        qp(1, 4) = ��ʿ
        qp(1, 5) = �ڽ�
        qp(1, 6) = ��ʿ
        qp(1, 7) = ����
        qp(1, 8) = ����
        qp(1, 9) = �ڳ�
        qp(3, 2) = ����
        qp(3, 8) = ����
        qp(4, 1) = �ڱ�
        qp(4, 3) = �ڱ�
        qp(4, 5) = �ڱ�
        qp(4, 7) = �ڱ�
        qp(4, 9) = �ڱ�
End Sub
