Attribute VB_Name = "����ģ��"
Option Explicit

' 66 * 16
Private Const ����ͼ��� = 66
Private Const ����ͼ�߶� = 16
Private Const ����ͼ As String = _
        "  ..........      ...  vvv     ..    ........................     " & _
        "    ..........    ..  v   vv    ..             ......    .....    " & _
        "   ..........      ..   v   v    .      ooooo       ...........   " & _
        "     ..........        v   vvv   .     o     oo   .....           " & _
        "   ....    .....         vv  vv   .    o       o     ......       " & _
        "    ...   v  ...          v  v     .    ooo   o   ......  ....    " & _
        "  ...    v  .....     .  v    v   ..       ooo  ....        ....  " & _
        "   ...    vv   ...    ..  vv v     ...        ...    v   ....     " & _
        " ...     v   ....    ....   v               ....      v   ....    " & _
        "  ....  v v   ............               ....        vv     ....  " & _
        "   .....   v  .....................       .......   v  v   ....   " & _
        " .....    v  ....               .......  ....          v     ...  " & _
        "  .......    ..    oooooooo       .........          vv  .....    " & _
        "     .......     oo        o        .......       vvv  v    ..    " & _
        "       ......      oooooooo           .........  v      v    ...  " & _
        "         ..                     .............     vvvvvv   ...    "

Public Function ��������ͼ() As ��ͼ
        Dim r As New ��ͼ
        Dim ��ǰ��ͼ�� As String
        Dim i As Integer, j As Integer
        r.��� = ����ͼ���
        r.�߶� = ����ͼ�߶�
        For j = 0 To r.�߶� - 1
                ��ǰ��ͼ�� = Mid(����ͼ, j * r.��� + 1, r.���)
                For i = 0 To r.��� - 1
                        Dim �������� As ��������

                        Select Case Mid(��ǰ��ͼ��, i + 1, 1)
                        Case " ": �������� = �ݵ�
                        Case ".": �������� = ƽ��
                        Case "v": �������� = ɽ��
                        Case "o": �������� = ����
                        End Select

                        r.����(i, j) = ��������
                Next
        Next
        Set ��������ͼ = r
End Function
