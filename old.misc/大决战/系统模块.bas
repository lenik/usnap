Attribute VB_Name = "ϵͳģ��"
Option Explicit

Public ������� As New LowXTool.Array
Public ָ����� As New LowXTool.Pointer
Public �ִ����� As New LowXTool.String

Public Sub Main()
        ��ʼ��ϵͳ

        Dim wi As WINDOWINFO
        Load ������
        GetWindowInfo ������.hWnd, wi
        wi.rcClient.Left = wi.rcClient.Left + ������.����.Left
        wi.rcClient.Top = wi.rcClient.Top + ������.����.Top
        wi.rcClient.Right = wi.rcClient.Left + ������.����.Width
        wi.rcClient.Bottom = wi.rcClient.Top + ������.����.Height
        ClipCursor wi.rcClient
        ������.Show 1
        �˳�ϵͳ
End Sub

Public Sub ��ʼ��ϵͳ()
        ��ͼģ��.��ʼ����ͼ����

        Set ��ͼģ��.����ͼ = ����ģ��.��������ͼ
        With ��ͼģ��.����ͼ
                Set .ͼ�α�ʾ = New ͼ�α�ʾ
                .������߽� = 0
                .�����ϱ߽� = 0
                .������� = 20
                .�����߶� = 10
        End With
End Sub

Public Sub �˳�ϵͳ()
        ClipCursor_ 0
End Sub
