Attribute VB_Name = "modTlHelp32"

Declare Function CLoseHandle Lib "user32" (ByVal hHandle As Long) As Boolean

' TLHelp32.bas
' Tool help 32 module

Option Base 0

Const MAX_MODULE_NAME32 = 255

Const TH32CS_SNAPHEAPLIST = &H1
Const TH32CS_SNAPPROCESS = &H2
Const TH32CS_SNAPTHREAD = &H4
Const TH32CS_SNAPMODULE = &H8
Const TH32CS_SNAPALL = TH32CS_SNAPHEAPLIST Or TH32CS_SNAPPROCESS Or TH32CS_SNAPTHREAD Or TH32CS_SNAPMODULE
Const TH32CS_INHERIT = &H80000000

Declare Function CreateToolhelp32SnapshotA Lib "user32" (ByVal dwFlags As Long, ByVal th32ProcessID As Long) As Long
Declare Function Toolhelp32ReadProcessMemory Lib "user32" (ByVal th32ProcessID As Long, ByRef lpBaseAddress As Any, lpBuffer As Any, ByRef cbRead As Long, lpNumberOfBytesRead As Long) As Boolean

Type HEAPLIST32
    dwSize As Long
    th32ProcessID As Long
    th32HeapID As Long
    dwFlags As Long
End Type

Const HF32_DEFAULT = 1
Const HF32_SHARED = 2

Declare Function Heap32ListFirst Lib "user32" (ByVal hSnapshot As Long, lphl As HEAPLIST32) As Boolean
Declare Function Heap32ListNext Lib "user32" (ByVal hSnapshot As Long, lphl As HEAPLIST32) As Boolean

Type HEAPENTRY32
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

Const LF32_FIXED = &H1
Const LF32_FREE = &H2
Const LF32_MOVEABLE = &H4

Declare Function Heap32First Lib "user32" (lphe As HEAPENTRY32, ByVal th32ProcessID As Long, ByVal th32HeapID As Long) As Boolean
Declare Function Heap32Next Lib "user32" (lphe As HEAPENTRY32) As Boolean

Type PROCESSENTRY32W
    dwSize As Long
    cntUsage As Long
    th32ProcessID As Long
    th32DefaultHeapID As Long
    th32ModuleID As Long
    cntThreads As Long
    th32ParentProcessID As Long
    pcPriClassBase As Long
    dwFlags As Long
    szExeFile As String 'wchar
End Type

Declare Function Process32FirstW Lib "user32" (ByVal hSnapshot As Long, ByRef lppe As PROCESSENTRY32W) As Boolean
Declare Function Process32NextW Lib "user32" (ByVal hSnapshot As Long, ByRef lppe As PROCESSENTRY32W) As Boolean

Type PROCESSENTRY32
    dwSize As Long
    cntUsage As Long
    th32ProcessID As Long
    th32DefaultHeapID As Long
    th32ModuleID As Long
    cntThreads As Long
    th32ParentProcessID As Long
    pcPriClassBase As Long
    dwFlags As Long
    szExeFile As String 'wchar
End Type

Declare Function Process32First Lib "user32" (ByVal hSnapshot As Long, ByRef lppe As PROCESSENTRY32) As Boolean
Declare Function Process32Next Lib "user32" (ByVal hSnapshot As Long, ByRef lppe As PROCESSENTRY32) As Boolean

Type THREADENTRY32
    dwSize As Long
    cntUsage As Long
    th32ThreadID As Long
    th32OwnerProcessID As Long
    tpBasePri As Long
    tpDeltaPri As Long
    dwFlags As Long
End Type

Declare Function Thread32First Lib "user32" (ByVal hSnapshot As Long, ByRef lpte As THREADENTRY32) As Boolean
Declare Function Thread32Next Lib "user32" (ByVal hSnapshot As Long, ByRef lpte As THREADENTRY32) As Boolean

Type MODULEENTRY32W
    dwSize As Long
    th32ModuleID As Long
    th32ProcessID As Long
    GlblcntUsage As Long
    ProccntUsage As Long
    modBaseAddr As Long     ' BYTE *
    modBaseSize As Long
    hModule As Long
    szModule As String
    szExePath As String
End Type

Declare Function Module32FirstW Lib "user32" (ByVal hSnapshot As Long, ByRef lpme As MODULEENTRY32W) As Boolean
Declare Function Module32NextW Lib "user32" (ByVal hSnapshot As Long, ByRef lpme As MODULEENTRY32W) As Boolean

Type MODULEENTRY32
    dwSize As Long
    th32ModuleID As Long
    th32ProcessID As Long
    GlblcntUsage As Long
    ProccntUsage As Long
    modBaseAddr As Long     ' BYTE *
    modBaseSize As Long
    hModule As Long
    szModule As String
    szExePath As String
End Type

Declare Function Module32First Lib "user32" (ByVal hSnapshot As Long, ByRef lpme As MODULEENTRY32) As Boolean
Declare Function Module32Next Lib "user32" (ByVal hSnapshot As Long, ByRef lpme As MODULEENTRY32) As Boolean
