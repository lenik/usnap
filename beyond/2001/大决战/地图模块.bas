Attribute VB_Name = "��ͼģ��"
Option Explicit

Public Enum ��������
        δ���� = 0
        ƽ��
        �ݵ�
        ɽ��
        ����
End Enum

Public Const ���� = 256
Public Const ���� = 128

Private Const �������ͼ������ As Integer = 1024
Public �Ѷ����ͼ������ As Integer
Public �Ѷ����ͼ����(0 To �������ͼ������ - 1) As New ��ͼ����
Private �ѳ�ʼ����ͼ���� As Boolean

Public ����ͼ As ��ͼ

Public Sub ��ʼ����ͼ����()
        With �Ѷ����ͼ����(δ����)
                .����Ϣ = False
                .������ = False
                .����Ӫ = False
                .�����ƶ��� = -1
        End With
        With �Ѷ����ͼ����(ƽ��)
                .����Ϣ = True
                .������ = True
                .����Ӫ = True
                .�����ƶ��� = 1
        End With
        With �Ѷ����ͼ����(�ݵ�)
                .����Ϣ = True
                .������ = True
                .����Ӫ = False
                .�����ƶ��� = 2
        End With
        With �Ѷ����ͼ����(ɽ��)
                .����Ϣ = False
                .������ = True
                .����Ӫ = False
                .�����ƶ��� = 3
        End With
        With �Ѷ����ͼ����(����)
                .����Ϣ = False
                .������ = False
                .����Ӫ = False
                .�����ƶ��� = 1
        End With
        �Ѷ����ͼ������ = 4
End Sub
Public Property Get ������(ByVal �������� As ��������) As ��ͼ����
        If Not �ѳ�ʼ����ͼ���� Then
                ��ʼ����ͼ����
                �ѳ�ʼ����ͼ���� = True
        End If
        Set ������ = �Ѷ����ͼ����(��������)
End Property
