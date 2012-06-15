Attribute VB_Name = "modNT"

' 列出操作系统中运行的进程, 保存到lpidProcesses数组中
Declare Function EnumProcesses Lib "psapi" (lpidProcesses As Long, ByVal cb As Long, cbNeeded As Long) As Boolean

' 列出一个进程中包含的模块, 保存到lphModule数组中
' 其中hProcess可以通过OpenProcess打开ProcessID来获得,
' 并且具有PROCESS_QUERY_INFORMATION权限
' 列出的第一个模块是主模块
Declare Function EnumProcessModules Lib "psapi" (ByVal hProcess As Long, lphModule As Long, ByVal cb As Long, cbNeeded As Long) As Boolean

' 获取模块文件名
Declare Function GetModuleBaseName Lib "psapi" Alias "GetModuleBaseNameA" (ByVal hProcess As Long, ByVal hModule As Long, ByVal lpBaseName As Long, ByVal nSize As Long) As Long


Declare Function SetPriorityClass Lib "kernel32" (ByVal hProcess As Long, ByVal dwPriorityClass As Long) As Long
Declare Function GetPriorityClass Lib "kernel32" (ByVal hProcess As Long) As Long


Declare Function EnumWindows Lib "user32" (ByVal lpEnumFunc As Long, ByVal lParam As Long) As Boolean
Declare Function EnumChildWindows Lib "user32" (ByVal hWndParent As Long, ByVal lpEnumFunc As Long, ByVal lParam As Long) As Boolean

Public Const GW_HWNDFIRST = 0
Public Const GW_HWNDLAST = 1
Public Const GW_HWNDNEXT = 2
Public Const GW_HWNDPREV = 3
Public Const GW_OWNER = 4
Public Const GW_CHILD = 5
Public Const GW_MAX = 5

Declare Function GetWindow Lib "user32" (ByVal hWnd As Long, ByVal wCmd As Long) As Long

Declare Function GetWindowThreadProcessId Lib "user32" (ByVal hWnd As Long, lpdwProcessId As Long) As Long

Declare Function GetWindowText Lib "user32" Alias "GetWindowTextA" (ByVal hWnd As Long, ByVal lpString As String, ByVal cch As Long) As Long
Declare Function GetWindowTextLength Lib "user32" Alias "GetWindowTextLengthA" (ByVal hWnd As Long) As Long




' 进程信息结构
Public Type ProcessInfo
    ProcessId As Long
    ProcessName As String
End Type

' 获取操作系统中运行的进程 Windows NT,2000版
Public Sub GetProcessesNT()
    Dim a(1000) As Long
    Dim cb As Long, cb2 As Long
    EnumProcesses a(1), 1000 * 4, cb
    nProcesses = cb
    For i = 1 To cb
        Dim hProcess As Long
        Dim hModule As Long
        Dim basename As String * 100
        hProcess = OpenProcess(0, 0, a(i))
        ' 这里的单位是字节，而Long的长度是字节长度的4倍，所以*4
        EnumProcessModules hProcess, hModule, 1 * 4, cb2
        GetModuleBaseName hProcess, hModule, basename, 100
        Processes(i).ProcessId = a(i)
        Processes(i).ProcessName = Trim2(basename)
    Next
End Sub
