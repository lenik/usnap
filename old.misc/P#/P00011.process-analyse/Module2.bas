Attribute VB_Name = "modprocess"

Option Explicit

Public Processes(1000) As PROCESSENTRY32, nProcesses As Long

' ��ȡ�����б�
' ��ȡϵͳ���������е����н��̲����浽Processes�����С�
Public Sub GetProcesses()
        Dim h As Long, i As Long
        Dim b As Boolean
        Dim pe As PROCESSENTRY32
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)

        ' Len(pe)��һ��������˵��PROCESSENTRY32�ĳ����м����ֽ�
        pe.dwSize = Len(pe)
        i = 1
        ' ��ȡ�����е�һ�����̵���Ϣ������pe�С��������false��˵�������в����ڽ��̡�
        b = Process32First(h, pe)
        Do While b
                ' ����ȡ�Ľ�����Ϣ���浽������
                Processes(i) = pe

                i = i + 1

                ' ��ȡ��һ�����̵���Ϣ������Ѿ��������β�����򷵻�false
                b = Process32Next(h, pe)
        Loop
        ' i ����һ��������Ϣ��Ҫ���浽�����е�λ�ã����Խ�����ĿΪi-1
        nProcesses = i - 1

        ' �رտ���
        CloseHandle h
End Sub

' ���ݽ���ID���ؽ�����Ϣ�ṹ
Public Function GetProcess(pid) As PROCESSENTRY32
        Dim i
        ' �ӽ����������ҳ�����ID���ڸ���pid�Ľ���
        For i = 1 To nProcesses
                ' ���������i����Ԫ�Ľ���ID���ڸ�����pid
                If Processes(i).th32ProcessID = pid Then
                        ' �ҵ����򷵻ؽ��������е�i����Ԫ
                        GetProcess = Processes(i)
                        Exit Function
                End If
        Next
        ' ����0��ʾ�����ڸý���
        GetProcess.th32ProcessID = 0
End Function
