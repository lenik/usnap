Attribute VB_Name = "modAPIs"

' 基本结构
    Type RECT
            Left As Long
            Top As Long
            Right As Long
            Bottom As Long
    End Type

' 作图
    Declare Function Arc Lib "gdi32" (ByVal hdc As Long, ByVal X1 As Long, ByVal Y1 As Long, ByVal X2 As Long, ByVal Y2 As Long, ByVal X3 As Long, ByVal Y3 As Long, ByVal X4 As Long, ByVal Y4 As Long) As Long
    Declare Function CancelDC Lib "gdi32" (ByVal hdc As Long) As Long
    Declare Function Chord Lib "gdi32" (ByVal hdc As Long, ByVal X1 As Long, ByVal Y1 As Long, ByVal X2 As Long, ByVal Y2 As Long, ByVal X3 As Long, ByVal Y3 As Long, ByVal X4 As Long, ByVal Y4 As Long) As Long
    Declare Function CloseMetaFile Lib "gdi32" (ByVal hMF As Long) As Long
    Declare Function CombineRgn Lib "gdi32" (ByVal hDestRgn As Long, ByVal hSrcRgn1 As Long, ByVal hSrcRgn2 As Long, ByVal nCombineMode As Long) As Long
    Declare Function CopyMetaFile Lib "gdi32" Alias "CopyMetaFileA" (ByVal hMF As Long, ByVal lpFileName As String) As Long

    Declare Function CreateCompatibleBitmap Lib "gdi32" (ByVal hdc As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
    Declare Function CreateDiscardableBitmap Lib "gdi32" (ByVal hdc As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long

    Declare Function CreateHatchBrush Lib "gdi32" (ByVal nIndex As Long, ByVal crColor As Long) As Long

    Declare Function CreatePen Lib "gdi32" (ByVal nPenStyle As Long, ByVal nWidth As Long, ByVal crColor As Long) As Long
    Declare Function CreateRectRgn Lib "gdi32" (ByVal X1 As Long, ByVal Y1 As Long, ByVal X2 As Long, ByVal Y2 As Long) As Long
    Declare Function CreateRoundRectRgn Lib "gdi32" (ByVal X1 As Long, ByVal Y1 As Long, ByVal X2 As Long, ByVal Y2 As Long, ByVal X3 As Long, ByVal Y3 As Long) As Long
    Declare Function CreateScalableFontResource Lib "gdi32" Alias "CreateScalableFontResourceA" (ByVal fHidden As Long, ByVal lpszResourceFile As String, ByVal lpszFontFile As String, ByVal lpszCurrentPath As String) As Long
    Declare Function CreateSolidBrush Lib "gdi32" (ByVal crColor As Long) As Long

    Declare Function DeleteDC Lib "gdi32" (ByVal hdc As Long) As Long
    Declare Function DeleteObject Lib "gdi32" (ByVal hObject As Long) As Long
    Declare Function DeleteMetaFile Lib "gdi32" (ByVal hMF As Long) As Long

    Declare Function GetObject Lib "gdi32" Alias "GetObjectA" (ByVal hObject As Long, ByVal nCount As Long, lpObject As Any) As Long
    Declare Function ExtTextOut Lib "gdi32" Alias "ExtTextOutA" (ByVal hdc As Long, ByVal X As Long, ByVal Y As Long, ByVal wOptions As Long, lpRect As RECT, ByVal lpString As String, ByVal nCount As Long, lpDx As Long) As Long

    Declare Function TextOut Lib "gdi32" Alias "TextOutA" (ByVal hdc As Long, ByVal X As Long, ByVal Y As Long, ByVal lpString As String, ByVal nCount As Long) As Long

        ' 二进制光栅操作
        Public Const R2_BLACK = 1       '   0
        Public Const R2_NOTMERGEPEN = 2 '  DPon
        Public Const R2_MASKNOTPEN = 3  '  DPna
        Public Const R2_NOTCOPYPEN = 4  '  PN
        Public Const R2_MASKPENNOT = 5  '  PDna
        Public Const R2_NOT = 6 '  Dn
        Public Const R2_XORPEN = 7      '  DPx
        Public Const R2_NOTMASKPEN = 8  '  DPan
        Public Const R2_MASKPEN = 9     '  DPa
        Public Const R2_NOTXORPEN = 10  '  DPxn
        Public Const R2_NOP = 11        '  D
        Public Const R2_MERGENOTPEN = 12        '  DPno
        Public Const R2_COPYPEN = 13    '  P
        Public Const R2_MERGEPENNOT = 14        '  PDno
        Public Const R2_MERGEPEN = 15   '  DPo
        Public Const R2_WHITE = 16      '   1
        Public Const R2_LAST = 16

        ' 光栅操作
        Public Const SRCCOPY = &HCC0020 ' (DWORD) dest = source
        Public Const SRCPAINT = &HEE0086        ' (DWORD) dest = source OR dest
        Public Const SRCAND = &H8800C6  ' (DWORD) dest = source AND dest
        Public Const SRCINVERT = &H660046       ' (DWORD) dest = source XOR dest
        Public Const SRCERASE = &H440328        ' (DWORD) dest = source AND (NOT dest )
        Public Const NOTSRCCOPY = &H330008      ' (DWORD) dest = (NOT source)
        Public Const NOTSRCERASE = &H1100A6     ' (DWORD) dest = (NOT src) AND (NOT dest)
        Public Const MERGECOPY = &HC000CA       ' (DWORD) dest = (source AND pattern)
        Public Const MERGEPAINT = &HBB0226      ' (DWORD) dest = (NOT source) OR dest
        Public Const PATCOPY = &HF00021 ' (DWORD) dest = pattern
        Public Const PATPAINT = &HFB0A09        ' (DWORD) dest = DPSnoo
        Public Const PATINVERT = &H5A0049       ' (DWORD) dest = pattern XOR dest
        Public Const DSTINVERT = &H550009       ' (DWORD) dest = (NOT dest)
        Public Const BLACKNESS = &H42 ' (DWORD) dest = BLACK
        Public Const WHITENESS = &HFF0062       ' (DWORD) dest = WHITE

    Declare Function BitBlt Lib "gdi32" (ByVal hDestDC As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal dwRop As Long) As Long

' 配置输入输出
    ' 初始化文件操作Api
    Declare Function GetProfileInt Lib "kernel32" Alias "GetProfileIntA" (ByVal lpAppName As String, ByVal lpKeyName As String, ByVal nDefault As Long) As Long
    Declare Function GetProfileString Lib "kernel32" Alias "GetProfileStringA" (ByVal lpAppName As String, ByVal lpKeyName As String, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long) As Long
    Declare Function WriteProfileString Lib "kernel32" Alias "WriteProfileStringA" (ByVal lpszSection As String, ByVal lpszKeyName As String, ByVal lpszString As String) As Long
    Declare Function GetProfileSection Lib "kernel32" Alias "GetProfileSectionA" (ByVal lpAppName As String, ByVal lpReturnedString As String, ByVal nSize As Long) As Long
    Declare Function WriteProfileSection Lib "kernel32" Alias "WriteProfileSectionA" (ByVal lpAppName As String, ByVal lpString As String) As Long
    Declare Function GetPrivateProfileInt Lib "kernel32" Alias "GetPrivateProfileIntA" (ByVal lpApplicationName As String, ByVal lpKeyName As String, ByVal nDefault As Long, ByVal lpFileName As String) As Long
    Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
    Declare Function WritePrivateProfileString Lib "kernel32" Alias "WritePrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, ByVal lpFileName As String) As Long
    Declare Function GetPrivateProfileSection Lib "kernel32" Alias "GetPrivateProfileSectionA" (ByVal lpAppName As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
    Declare Function WritePrivateProfileSection Lib "kernel32" Alias "WritePrivateProfileSectionA" (ByVal lpAppName As String, ByVal lpString As String, ByVal lpFileName As String) As Long

' 文件系统查询
    Declare Function GetWindowsDirectory Lib "kernel32" Alias "GetWindowsDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
    Declare Function GetSystemDirectory Lib "kernel32" Alias "GetSystemDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
    Declare Function GetTempPath Lib "kernel32" Alias "GetTempPathA" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long
    Declare Function SetCurrentDirectory Lib "kernel32" Alias "SetCurrentDirectoryA" (ByVal lpPathName As String) As Long
    Declare Function GetCurrentDirectory Lib "kernel32" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long
    Declare Function GetDiskFreeSpace Lib "kernel32" Alias "GetDiskFreeSpaceA" (ByVal lpRootPathName As String, lpSectorsPerCluster As Long, lpBytesPerSector As Long, lpNumberOfFreeClusters As Long, lpTtoalNumberOfClusters As Long) As Long
    Declare Function GetFullPathName Lib "kernel32" Alias "GetFullPathNameA" (ByVal lpFileName As String, ByVal nBufferLength As Long, ByVal lpBuffer As String, ByVal lpFilePart As String) As Long

Function NotColor(nColor As Long) As Long
    NotColor = Not nColor And &HFFFFFF
End Function
