Attribute VB_Name = "modMessage"
Option Explicit

Public ltp As New LowXTool.Pointer
Public lte As New LowXTool.Executable

Public Const WM_KEYFIRST = &H100
Public Const WM_KEYDOWN = &H100
Public Const WM_KEYUP = &H101
Public Const WM_CHAR = &H102
Public Const WM_MOUSEFIRST = &H200
Public Const WM_MOUSEMOVE = &H200
Public Const WM_LBUTTONDOWN = &H201
Public Const WM_LBUTTONUP = &H202
Public Const WM_LBUTTONDBLCLK = &H203
Public Const WM_RBUTTONDOWN = &H204
Public Const WM_RBUTTONUP = &H205
Public Const WM_RBUTTONDBLCLK = &H206
Public Const WM_MBUTTONDOWN = &H207
Public Const WM_MBUTTONUP = &H208
Public Const WM_MBUTTONDBLCLK = &H209
Public Const WM_MOUSELAST = &H209

Public ����Ϣ���� As Long

Public Function ������̽����ص�(ByVal ����Ϣ������� As Long) As Long
        If ����Ϣ���� = 0 Then
                ' �������ع����
                ����Ϣ���� = ����Ϣ�������
        End If
        ������̽����ص� = ltp.Vpf(AddressOf ����Ϣ����)
End Function
Public Function �ָ��ص�(ByVal ����Ϣ������� As Long) As Long
        �ָ��ص� = ����Ϣ����
        ����Ϣ���� = 0
End Function

' ��Ϣ����������ϸ�ĸ�ʽ, �������Լ������
'       δ�������Ϣ���봫�ݸ���Ϣ������һ����Ϣ�������
'       ��ͬ����Ϣ�в�ͬ�ķ���ֵ,
'               ��һЩ��Ϣ����0��ʾ��Ϣ����ɹ�,
'               ����һЩ��Ϣ����0���ܱ�ʾ��Ϣ��Ҫ���´���
'       ���Ա��뷵�� ��Ϣ������һ����Ϣ������̵� ����ֵ
Public Function ����Ϣ����(ByVal hWnd As Long, ByVal message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
        Static ���ڴ����� As Boolean
        If Not ���ڴ����� Then
                ���ڴ����� = True
                With frmMain
                        .iWnd = hWnd
                        .iMessage = message
                        .iWparam = wParam
                        .iLparam = lParam
                End With
                ���ڴ����� = False
        End If
        Select Case message
        Case WM_MOUSEMOVE
                frmMain.txtCounter.Text = str(Val(frmMain.txtCounter.Text) - 1)
                ����Ϣ���� = 0
        Case Else
                ����Ϣ���� = lte.VChainMessage(����Ϣ����, hWnd, message, wParam, lParam)
        End Select
End Function
