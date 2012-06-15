VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Executable"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Function VLoadLibrary(ByVal lpLibFileName As String) As Long: VLoadLibrary = LoadLibrary(lpLibFileName): End Function
Function VLoadLibraryEx(ByVal lpLibFileName As String, ByVal hFile As Long, ByVal dwFlags As Long): VLoadLibraryEx = LoadLibraryEx(lpLibFileName, hFile, dwFlags): End Function
Function VLoadModule(ByVal lpModuleName As String, lpParameterBlock) As Long: VLoadModule = LoadModule(lpModuleName, lpParameterBlock): End Function
Function VGetProcAddress(ByVal hModule As Long, ByVal lpProcName As String) As Long: VGetProcAddress = GetProcAddress(hModule, lpProcName): End Function
Function VFreeLibrary(ByVal hLibModule As Long): VFreeLibrary = FreeLibrary(hLibModule): End Function

Function VWinExec(ByVal lpCmdLine As String, ByVal nCmdShow As Long) As Long: VWinExec = WinExec(lpCmdLine, nCmdShow): End Function

Function VGetCommandLine() As String: VGetCommandLine = GetCommandLine: End Function

Function VCatchMessage(ByVal hWnd As Long, ByVal switchprocProc As Long) As Long: VCatchMessage = catchMessage(hWnd, switchprocProc): End Function
Function VChainMessage(ByVal wndproc As Long, ByVal hWnd As Long, ByVal message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long: VChainMessage = chainMessage(wndproc, hWnd, message, wParam, lParam): End Function
