Attribute VB_Name = "Module1"
Option Explicit

Public Function getdirinfo(s) As Collection
        Dim a, b, i
        Dim j As DirItem
        Dim o As New Collection

        ' �ϲ��ո�
        a = s
        a = Replace(a, vbTab, " ")
        b = Replace(a, "  ", " ")
        While a <> b
                a = b
                b = Replace(a, "  ", " ")
        Wend

        ' ���зָ�ÿ��Ŀ¼��
        a = Split(a, vbNewLine)

        For i = LBound(a) To UBound(a)
                ' ���ո�ָ�ÿ���ֶΣ�����ĸ��ֶ�
                b = Split(a(i), " ", 4)
                If UBound(b) = 3 Then
                        Set j = New DirItem
                        j.ddate = b(0)
                        j.dtime = b(1)
                        If Not IsNumeric(b(2)) Then
                                j.dsize = -1
                        Else
                                j.dsize = Val(b(2))
                        End If
                        j.dname = b(3)

                        o.Add j
                End If
        Next
        Set getdirinfo = o
End Function

Public Function pathconj(a, b) As String
        If Right(a, 1) = "\" Then
                If Left(b, 1) = "\" Then
                        pathconj = a & Mid(b, 2)
                Else
                        pathconj = a & b
                End If
        Else
                pathconj = a & "\" & b
        End If
End Function
