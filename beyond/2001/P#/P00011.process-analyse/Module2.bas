Attribute VB_Name = "modprocess"

Option Explicit

Public Processes(1000) As PROCESSENTRY32, nProcesses As Long

' 获取进程列表
' 获取系统中正在运行的所有进程并保存到Processes数组中。
Public Sub GetProcesses()
        Dim h As Long, i As Long
        Dim b As Boolean
        Dim pe As PROCESSENTRY32
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)

        ' Len(pe)是一个常数，说明PROCESSENTRY32的长度有几个字节
        pe.dwSize = Len(pe)
        i = 1
        ' 获取快照中第一个进程的信息，放入pe中。如果返回false则说明快照中不存在进程。
        b = Process32First(h, pe)
        Do While b
                ' 将获取的进程信息保存到数组中
                Processes(i) = pe

                i = i + 1

                ' 获取下一个进程的信息。如果已经到达快照尾部，则返回false
                b = Process32Next(h, pe)
        Loop
        ' i 是下一个进程信息将要保存到数组中的位置，所以进程数目为i-1
        nProcesses = i - 1

        ' 关闭快照
        CloseHandle h
End Sub

' 根据进程ID返回进程信息结构
Public Function GetProcess(pid) As PROCESSENTRY32
        Dim i
        ' 从进程数组中找出进程ID等于给定pid的进程
        For i = 1 To nProcesses
                ' 进程数组第i个单元的进程ID等于给定的pid
                If Processes(i).th32ProcessID = pid Then
                        ' 找到了则返回进程数组中第i个单元
                        GetProcess = Processes(i)
                        Exit Function
                End If
        Next
        ' 返回0表示不存在该进程
        GetProcess.th32ProcessID = 0
End Function
