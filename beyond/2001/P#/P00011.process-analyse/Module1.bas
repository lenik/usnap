Attribute VB_Name = "modprocessapi"

Option Explicit

Public Const NORMAL_PRIORITY_CLASS = &H20
Public Const IDLE_PRIORITY_CLASS = &H40
Public Const HIGH_PRIORITY_CLASS = &H80
Public Const REALTIME_PRIORITY_CLASS = &H100

Public Const PROCESS_TERMINATE = &H1
Public Const PROCESS_CREATE_THREAD = &H2
Public Const PROCESS_SET_SESSIONID = &H4
Public Const PROCESS_VM_OPERATION = &H8
Public Const PROCESS_VM_READ = &H10
Public Const PROCESS_VM_WRITE = &H20
Public Const PROCESS_DUP_HANDLE = &H40
Public Const PROCESS_CREATE_PROCESS = &H80
Public Const PROCESS_SET_QUOTA = &H100
Public Const PROCESS_SET_INFORMATION = &H200
Public Const PROCESS_QUERY_INFORMATION = &H400

Declare Function GetCurrentProcess Lib "kernel32" () As Long
Declare Function GetCurrentProcessId Lib "kernel32" () As Long

Declare Function OpenProcess Lib "kernel32" (ByVal dwDesiredAccess As Long, ByVal bInheritHandle As Long, ByVal dwProcessID As Long) As Long
Declare Function CloseHandle Lib "kernel32" (ByVal hObject As Long) As Long

' 读取进程内存, 保存至lpBuffer数组中
' 其中hProcess需要具有PROCESS_VM_READ权限
Declare Function ReadProcessMemory Lib "kernel32" (ByVal hProcess As Long, ByVal lpBaseAddress As Long, lpBuffer As Byte, ByVal nSize As Long, lpNumberOfBytesRead As Long) As Boolean

' 将lpBuffer数组写入进程内存
' 其中hProcess需要具有PROCESS_VM_WRITE和PROCESS_VM_OPERATION权限
Declare Function WriteProcessMemory Lib "kernel32" (ByVal hProcess As Long, ByVal lpBaseAddress As Long, lpBuffer As Byte, ByVal nSize As Long, lpNumberOfBytesWritten As Long) As Boolean

' 读取进程内存, 保存至lpBuffer指定的内存空间中
Declare Function ReadProcessMemory2 Lib "kernel32" Alias "ReadProcessMemory" (ByVal hProcess As Long, ByVal lpBaseAddress As Long, ByVal lpBuffer As Long, ByVal nSize As Long, lpNumberOfBytesRead As Long) As Boolean

' 将lpBuffer指向的内存空间写入进程内存
Declare Function WriteProcessMemory2 Lib "kernel32" Alias "WriteProcessMemory" (ByVal hProcess As Long, ByVal lpBaseAddress As Long, ByVal lpBuffer As Long, ByVal nSize As Long, lpNumberOfBytesWritten As Long) As Boolean


Public Const TH32CS_SNAPHEAPLIST = 1
Public Const TH32CS_SNAPPROCESS = 2
Public Const TH32CS_SNAPTHREAD = 4
Public Const TH32CS_SNAPMODULE = 8
Public Const TH32CS_SNAPALL = 1 + 2 + 4 + 8
Public Const TH32CS_INHEARIT = &H80000000

Public Const HF32_DEFAULT = 1
Public Const HF32_SHARED = 2

Public Const LF32_FIXED = 1
Public Const LF32_FREE = 2
Public Const LF32_MOVEABLE = 4

Public Const MAX_MODULE_NAME32 = 255
Public Const MAX_MODULE_NAME32_1 = 256
Public Const MAX_PATH = 260

Public Type PROCESSENTRY32
        dwSize As Long
        cntUsage As Long
        th32ProcessID As Long
        th32DefaultHeapID As Long ' used in core
        th32ModuleID As Long
        cntThreads As Long
        th32ParentProcessID As Long
        pcPriClassBase As Long
        dwFlags As Long
        szExeFile As String * MAX_PATH
End Type

Public Type MODULEENTRY32
        dwSize As Long
        th32ModuleID As Long
        th32ProcessID As Long
        GlblcntUsage As Long
        ProccntUsage As Long
        modBaseAddr As Long
        modBaseSize As Long
        hModule As Long
        szModule As String * MAX_MODULE_NAME32_1
        szExePath As String * MAX_PATH
End Type

Public Type MODULEINFO
        lpBaseOfDll As Long
        SizeOfImage As Long
        EntryPoint As Long
End Type

Public Type THREADENTRY32
        dwSize As Long
        cntUsage As Long
        th32ThreadID As Long
        th32OwnerProcessID As Long
        tpBasePri As Long
        tpDeltaPri As Long
        dwFlags As Long
End Type

Public Type HEAPENTRY32
        dwSize As Long
        hHandle As Long
        dwAddress As Long
        dwBlockSize As Long
        dwFlags As Long
        dwLockCount As Long
        dwResvd As Long
        th32ProcessID As Long
        th32HeapID As Long
End Type

Public Type HEAPLIST32
        dwSize As Long
        th32ProcessID As Long
        th32HeapID As Long
        dwFlags As Long
End Type

' 建立32位帮助工具快照，th32ProcessID如果为0表示当前进程
Declare Function CreateToolhelp32Snapshot Lib "kernel32" (ByVal dwFlags As Long, ByVal th32ProcessID As Long) As Long

' 获取快照中第一个进程
Declare Function Process32First Lib "kernel32" (ByVal hSnapshot As Long, lppe As PROCESSENTRY32) As Boolean
' 获取快照中下一个进程，如果函数返回FALSE表示已经结束
Declare Function Process32Next Lib "kernel32" (ByVal hSnapshot As Long, lppe As PROCESSENTRY32) As Boolean

Declare Function Module32First Lib "kernel32" (ByVal hSnapshot As Long, lpme As MODULEENTRY32) As Boolean
Declare Function Module32Next Lib "kernel32" (ByVal hSnapshot As Long, lpme As MODULEENTRY32) As Boolean
Declare Function Thread32First Lib "kernel32" (ByVal hSnapshot As Long, lpte As THREADENTRY32) As Boolean
Declare Function Thread32Next Lib "kernel32" (ByVal hSnapshot As Long, lpte As THREADENTRY32) As Boolean
Declare Function Heap32First Lib "kernel32" (lphe As HEAPENTRY32, ByVal th32ProcessID As Long, ByVal th32HeapID As Long) As Boolean
Declare Function Heap32Next Lib "kernel32" (lphe As HEAPENTRY32) As Boolean
Declare Function Heap32ListFirst Lib "kernel32" (ByVal hSnapshot As Long, lphl As HEAPLIST32) As Boolean
Declare Function Heap32ListNext Lib "kernel32" (ByVal hSnapshot As Long, lphl As HEAPLIST32) As Boolean

Declare Function Toolhelp32ReadProcessMemory Lib "kernel32" (ByVal th32ProcessID As Long, ByVal lpBaseAddress As Long, lpBuffer As Byte, ByVal cbread As Long, lpNumberOfBytesRead As Long) As Boolean
