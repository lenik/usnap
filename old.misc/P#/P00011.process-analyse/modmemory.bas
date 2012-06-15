Attribute VB_Name = "modmemory"
Option Explicit

' �����Ѷ��󣬷��ضѾ��
Declare Function HeapCreate Lib "kernel32" (ByVal flOptions As Long, ByVal dwInitialSize As Long, ByVal dwMaximumSize As Long) As Long
' ɾ���Ѷ��󣬲���hHeapָ���Ѿ��
Declare Function HeapDestroy Lib "kernel32" (ByVal hHeap As Long) As Boolean
' �ڶѶ����з����ڴ�ռ䣬���ط���ռ���ʼ��ַ
Declare Function HeapAlloc Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal dwBytes As Long) As Long
' ���·���(���е�)�ڴ�ռ�Ĵ�С
Declare Function HeapReAlloc Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal lpMem As Long, ByVal dwBytes As Long) As Long
' �ͷ�(���е�)�ڴ�
Declare Function HeapFree Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal lpMem As Long) As Boolean
' ����(���е�)�ڴ��С
Declare Function HeapSize Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal lpMem As Long) As Long

Public heap As Long
Public hstart As Long
Public hsize As Long

' �������֧�ַ��� HEAPMAXSIZE / 4 ��Ľ����ڴ�ռ�
' ������Ϊ�������ݵ�ÿһ��ǽ����ڴ��ֽڵĵ�ַ
Public Const MAXSIZE            As Long = 1000000
Public Const HEAPMAXSIZE        As Long = MAXSIZE * 4

' ���ӷ����㣬���ؼ���÷�������ҵ��ķ��Ϸ��������Ľ������
' hstart �����ڷ����ڴ����ʱ���棬sizeָ���û���Ĵ�С
' val �Ǳ��η����õ�ֵ���������ӻ�����ɾȥ����ֵ������val�ĵ�Ԫ
Public Function AddAnalyse(hProcess As Long, val As Byte) As Long
        Dim ua As Long, uv As Byte, i As Long, j As Long

        j = 0
        ' ���������е�ÿ����Ԫ
        For i = 0 To hsize / 4 - 1
                ua = returnLong(hstart, i * 4)

                Dim cread As Long
                ' ��ȡ����hProcess�е�ua��ַ��Ԫ��ֵ
                ReadProcessMemory hProcess, ua, uv, 1, cread

                If uv = val Then
                ' �����Ϸ��������ĵ�Ԫ�Ƶ���ߡ����ڽ��������������Ŀռ�
                        forceLong hstart, j * 4, ua
                        j = j + 1
                End If
        Next

        hsize = j * 4
End Function

' ������λ
Public Sub ResetAnalyse(hProcess As Long, start As Long, size As Long)
        Dim i As Long
        Dim pstart As Long, pend As Long

        ' ������Ѿ���������ɾ��
        If heap <> 0 Then HeapDestroy heap

        ' ���½���һ���µĶ�
        heap = HeapCreate(0, HEAPMAXSIZE, 0)

        ' Ҫ����Ŀռ�Ϊ��Ԫ��Ŀ��4��������ռ��е�ÿ����Ԫ���ڴ�ŵ�ַ
        hsize = size * 4
        ' �ڶ�heap�з���ռ�
        hstart = HeapAlloc(heap, 0, hsize)

        ' ���������ʧ�ܻ��߷���ռ�ʧ��
        If heap = 0 Or hstart = 0 Then
                MsgBox "�޷������㹻���ڴ����ڷ���"
                Exit Sub
        End If

        ' ��ʼ���ѿռ䣬�� start �� end ��ÿ����ַ����ѿռ��С�
        For i = 0 To size - 1
                forceNLong hstart, i, start + i
        Next
End Sub

' ��ȡ������������ط����������
Public Function GetAnalyse(hProcess As Long)
        ReDim r(0 To hsize / 4 - 1, 0 To 1) As Long
        Dim i As Long, cread As Long
        ' �оٶѿռ��е�ÿһ��
        For i = 0 To hsize / 4 - 1
                ' ��ÿһ��ĵ�ַ���ݷ�������r�ĵ�һ���±���
                r(i, 0) = returnLong(hstart, i * 4)
                Dim b As Byte
                ' ��ÿһ��ĵ�ַ���ݶ�Ӧ�Ľ����ڴ���ֵ��������ڶ����±���
                ReadProcessMemory hProcess, r(i, 0), b, 1, cread
                r(i, 1) = b
        Next
        ' ������ r ����
        GetAnalyse = r
End Function
