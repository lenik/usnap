Attribute VB_Name = "modWinRegister"

Public Const ERROR_SUCCESS = 0

' Reg Create Type Values...
Public Const REG_OPTION_RESERVED = 0           ' Parameter is reserved
Public Const REG_OPTION_NON_VOLATILE = 0       ' Key is preserved when system is rebooted
Public Const REG_OPTION_VOLATILE = 1           ' Key is not preserved when system is rebooted
Public Const REG_OPTION_CREATE_LINK = 2        ' Created key is a symbolic link
Public Const REG_OPTION_BACKUP_RESTORE = 4     ' open for backup or restore

' Reg Data Types...
Public Const REG_NONE = 0                       ' No value type
Public Const REG_SZ = 1                         ' Unicode nul terminated string
Public Const REG_EXPAND_SZ = 2                  ' Unicode nul terminated string
Public Const REG_BINARY = 3                     ' Free form binary
Public Const REG_DWORD = 4                      ' 32-bit number
Public Const REG_DWORD_LITTLE_ENDIAN = 4        ' 32-bit number (same as REG_DWORD)
Public Const REG_DWORD_BIG_ENDIAN = 5           ' 32-bit number
Public Const REG_LINK = 6                       ' Symbolic Link (unicode)
Public Const REG_MULTI_SZ = 7                   ' Multiple Unicode strings
Public Const REG_RESOURCE_LIST = 8              ' Resource list in the resource map
Public Const REG_FULL_RESOURCE_DESCRIPTOR = 9   ' Resource list in the hardware description
Public Const REG_RESOURCE_REQUIREMENTS_LIST = 10

Public Const REG_CREATED_NEW_KEY = &H1                      ' New Registry Key created
Public Const REG_OPENED_EXISTING_KEY = &H2                      ' Existing Key opened
Public Const REG_WHOLE_HIVE_VOLATILE = &H1                      ' Restore whole hive volatile
Public Const REG_REFRESH_HIVE = &H2                      ' Unwind changes to last flush
Public Const REG_NOTIFY_CHANGE_NAME = &H1                      ' Create or delete (child)
Public Const REG_NOTIFY_CHANGE_ATTRIBUTES = &H2
Public Const REG_NOTIFY_CHANGE_LAST_SET = &H4                      ' Time stamp
Public Const REG_NOTIFY_CHANGE_SECURITY = &H8
Public Const REG_LEGAL_CHANGE_FILTER = (REG_NOTIFY_CHANGE_NAME Or REG_NOTIFY_CHANGE_ATTRIBUTES Or REG_NOTIFY_CHANGE_LAST_SET Or REG_NOTIFY_CHANGE_SECURITY)
Public Const REG_LEGAL_OPTION = (REG_OPTION_RESERVED Or REG_OPTION_NON_VOLATILE Or REG_OPTION_VOLATILE Or REG_OPTION_CREATE_LINK Or REG_OPTION_BACKUP_RESTORE)

' Reg Key Security Options
Public Const READ_CONTROL = &H20000
Public Const KEY_QUERY_VALUE = &H1
Public Const KEY_SET_VALUE = &H2
Public Const KEY_CREATE_SUB_KEY = &H4
Public Const KEY_ENUMERATE_SUB_KEYS = &H8
Public Const KEY_NOTIFY = &H10
Public Const KEY_CREATE_LINK = &H20
Public Const STANDARD_RIGHTS_READ = (READ_CONTROL)
Public Const STANDARD_RIGHTS_WRITE = (READ_CONTROL)
'Public Const KEY_READ = ((STANDARD_RIGHTS_READ Or KEY_QUERY_VALUE Or KEY_ENUMERATE_SUB_KEYS Or KEY_NOTIFY) And (Not SYNCHRONIZE))
'Public Const KEY_WRITE = ((STANDARD_RIGHTS_WRITE Or KEY_SET_VALUE Or KEY_CREATE_SUB_KEY) And (Not SYNCHRONIZE))
'Public Const KEY_ALL_ACCESS = ((STANDARD_RIGHTS_ALL Or KEY_QUERY_VALUE Or KEY_SET_VALUE Or KEY_CREATE_SUB_KEY Or KEY_ENUMERATE_SUB_KEYS Or KEY_NOTIFY Or KEY_CREATE_LINK) And (Not SYNCHRONIZE))
'Public Const KEY_EXECUTE = ((KEY_READ) And (Not SYNCHRONIZE))

' Register functions & Constants
Type ACL
        AclRevision As Byte
        Sbz1 As Byte
        AclSize As Integer
        AceCount As Integer
        Sbz2 As Integer
End Type
Type SECURITY_ATTRIBUTES
        nLength As Long
        lpSecurityDescriptor As Long
        bInheritHandle As Boolean
End Type
Type SECURITY_DESCRIPTOR
        Revision As Byte
        Sbz1 As Byte
        Control As Long
        Owner As Long
        Group As Long
        Sacl As ACL
        Dacl As ACL
End Type
Type FILETIME
        dwLowDateTime As Long
        dwHighDateTime As Long
End Type

Public Const HKEY_CLASSES_ROOT = &H80000001
Public Const HKEY_CURRENT_USER = &H80000001
Public Const HKEY_LOCAL_MACHINE = &H80000002
Public Const HKEY_USERS = &H80000003
Public Const HKEY_PERFORMANCE_DATA = &H80000004
Public Const HKEY_CURRENT_CONFIG = &H80000005
Public Const HKEY_DYN_DATA = &H80000006

' Registry API prototypes

Declare Function RegCloseKey Lib "advapi32.dll" (ByVal hKey As Long) As Long
Declare Function RegConnectRegistry Lib "advapi32.dll" Alias "RegConnectRegistryA" (ByVal lpMachineName As String, ByVal hKey As Long, phkResult As Long) As Long
Declare Function RegCreateKey Lib "advapi32.dll" Alias "RegCreateKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, phkResult As Long) As Long
Declare Function RegCreateKeyEx Lib "advapi32.dll" Alias "RegCreateKeyExA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal Reserved As Long, ByVal lpClass As String, ByVal dwOptions As Long, ByVal samDesired As Long, lpSecurityAttributes As SECURITY_ATTRIBUTES, phkResult As Long, lpdwDisposition As Long) As Long
Declare Function RegDeleteKey Lib "advapi32.dll" Alias "RegDeleteKeyA" (ByVal hKey As Long, ByVal lpSubKey As String) As Long
Declare Function RegDeleteValue Lib "advapi32.dll" Alias "RegDeleteValueA" (ByVal hKey As Long, ByVal lpValueName As String) As Long
Declare Function RegEnumKey Lib "advapi32.dll" Alias "RegEnumKeyA" (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpName As String, ByVal cbName As Long) As Long
Declare Function RegEnumKeyEx Lib "advapi32.dll" Alias "RegEnumKeyExA" (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpName As String, lpcbName As Long, lpReserved As Long, ByVal lpClass As String, lpcbClass As Long, lpftLastWriteTime As FILETIME) As Long
Declare Function RegEnumValue Lib "advapi32.dll" Alias "RegEnumValueA" (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpValueName As String, lpcbValueName As Long, ByVal lpReserved As Long, lpType As Long, ByVal lpData As String, lpcbData As Long) As Long
Declare Function RegFlushKey Lib "advapi32.dll" (ByVal hKey As Long) As Long
Declare Function RegGetKeySecurity Lib "advapi32.dll" (ByVal hKey As Long, ByVal SecurityInformation As Long, pSecurityDescriptor As SECURITY_DESCRIPTOR, lpcbSecurityDescriptor As Long) As Long
Declare Function RegLoadKey Lib "advapi32.dll" Alias "RegLoadKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal lpFile As String) As Long
Declare Function RegNotifyChangeKeyValue Lib "advapi32.dll" (ByVal hKey As Long, ByVal bWatchSubtree As Long, ByVal dwNotifyFilter As Long, ByVal hEvent As Long, ByVal fAsynchronus As Long) As Long
Declare Function RegOpenKey Lib "advapi32.dll" Alias "RegOpenKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, phkResult As Long) As Long
Declare Function RegOpenKeyEx Lib "advapi32.dll" Alias "RegOpenKeyExA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal ulOptions As Long, ByVal samDesired As Long, phkResult As Long) As Long
Declare Function RegQueryInfoKey Lib "advapi32.dll" Alias "RegQueryInfoKeyA" (ByVal hKey As Long, ByVal lpClass As String, lpcbClass As Long, lpReserved As Long, lpcSubKeys As Long, lpcbMaxSubKeyLen As Long, lpcbMaxClassLen As Long, lpcValues As Long, lpcbMaxValueNameLen As Long, lpcbMaxValueLen As Long, lpcbSecurityDescriptor As Long, lpftLastWriteTime As FILETIME) As Long
Declare Function RegQueryValue Lib "advapi32.dll" Alias "RegQueryValueA" (ByVal hKey As Long, ByVal lpSubKey As String, lpValue As Long, lpcbValue As Long) As Long
Declare Function RegQueryValueEx Lib "advapi32.dll" Alias "RegQueryValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, lpType As Long, ByVal lpData As Long, lpcbData As Long) As Long         ' Note that if you declare the lpData parameter as String, you must pass it By Value.
Declare Function RegReplaceKey Lib "advapi32.dll" Alias "RegReplaceKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal lpNewFile As String, ByVal lpOldFile As String) As Long
Declare Function RegRestoreKey Lib "advapi32.dll" Alias "RegRestoreKeyA" (ByVal hKey As Long, ByVal lpFile As String, ByVal dwFlags As Long) As Long
Declare Function RegSaveKey Lib "advapi32.dll" Alias "RegSaveKeyA" (ByVal hKey As Long, ByVal lpFile As String, lpSecurityAttributes As SECURITY_ATTRIBUTES) As Long
Declare Function RegSetKeySecurity Lib "advapi32.dll" (ByVal hKey As Long, ByVal SecurityInformation As Long, pSecurityDescriptor As SECURITY_DESCRIPTOR) As Long
Declare Function RegSetValue Lib "advapi32.dll" Alias "RegSetValueA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal dwType As Long, ByVal lpData As Long, ByVal cbData As Long) As Long
Declare Function RegSetValueEx Lib "advapi32.dll" Alias "RegSetValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, ByVal dwType As Long, ByVal lpData As Long, ByVal cbData As Long) As Long
Declare Function RegUnLoadKey Lib "advapi32.dll" Alias "RegUnLoadKeyA" (ByVal hKey As Long, ByVal lpSubKey As String) As Long

Declare Function RegQueryValueExB Lib "advapi32.dll" Alias "RegQueryValueExA" (ByVal hKey As Long, lpValueName As Byte, ByVal lpReserved As Long, lpType As Long, lpData As Byte, lpcbData As Long) As Long         ' Note that if you declare the lpData parameter as String, you must pass it By Value.
Declare Function RegSetValueExB Lib "advapi32.dll" Alias "RegSetValueExA" (ByVal hKey As Long, lpValueName As Byte, ByVal Reserved As Long, ByVal dwType As Long, lpData As Byte, ByVal cbData As Long) As Long

Declare Function RegQueryValueExS Lib "advapi32.dll" Alias "RegQueryValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, lpType As Long, ByVal lpData As String, lpcbData As Long) As Long
Declare Function RegSetValueExS Lib "advapi32.dll" Alias "RegSetValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, ByVal dwType As Long, ByVal lpData As String, ByVal cbData As Long) As Long

Public regLog As String
Public HKEY_SPECROOT As String

Public Function appendRegLog(str As String) As String
    regLog = regLog + str + vbNewLine
    appendRegLog = regLog
End Function

Public Function RegEnumName(ByVal hKey As Long, ByVal dwIndex As Long, lpValueName As String) As Long
    Dim lpNameBuffer(0 To 511) As Byte
    Dim nameBufSize As Long
    Dim valueBytes(0 To 1023) As Byte
    Dim valueLen As Long
    Dim valueType As Long
    nameBufSize = 511
    valueLen = 1023
    RegEnumName = RegEnumValue(hKey, dwIndex, lpNameBuffer(0), nameBufSize, 0, valueType, valueBytes(0), valueLen)
    lpValueName = IIf(RegEnumName = ERROR_SUCCESS, BytesToString(lpNameBuffer, 511), "")
End Function

Public Function RegGetVal(ByVal lpSubKey As String, ByVal lpValueName As String, lpValueString As String) As Long
    Dim hKey As Long
    Dim hSubKey As Long
    Dim valType As Long
    Dim valname(0 To 1023) As Byte, namelen As Long
    Dim valData(0 To 16383) As Byte, datalen As Long

    RegGetVal = RegOpenKey(HKEY_CURRENT_USER, HKEY_SPECROOT, hKey)
    If regErrored(RegGetVal) Then Exit Function

    If lpSubKey = "" Then
        hSubKey = hKey
    Else
        RegGetVal = RegOpenKey(hKey, lpSubKey, hSubKey)
        If regErrored(RegGetVal) Then
            RegCloseKey hKey
            Exit Function
        End If
    End If

    namelen = 1023
    datalen = 16383
    StringToBytes lpValueName, valname, namelen + 1

    RegGetVal = RegQueryValueExB(hSubKey, valname(0), 0, valType, valData(0), datalen)

    lpValueString = BytesToString(valData, datalen)

    If lpSubKey <> HKEY_SPECROOT Then RegCloseKey hSubKey
    RegCloseKey hKey
End Function

Public Function RegSetVal(ByVal lpSubKey As String, ByVal lpValueName As String, ByVal lpValueString As String) As Long
    Dim hKey As Long
    Dim hSubKey As Long
    Dim valType As Long
    Dim valname(0 To 1023) As Byte, namelen As Long
    Dim valData(0 To 16383) As Byte, datalen As Long

    RegSetVal = RegOpenKey(HKEY_CURRENT_USER, HKEY_SPECROOT, hKey)
    If regErrored(RegSetVal) Then
        RegSetVal = RegCreateKey(HKEY_CURRENT_USER, HKEY_SPECROOT, hKey)
        If regErrored(RegSetVal) Then Exit Function
    End If


    If lpSubKey = "" Then
        hSubKey = hKey
    Else
        RegSetVal = RegOpenKey(hKey, lpSubKey, hSubKey)
        If regErrored(RegSetVal) Then
            RegSetVal = RegCreateKey(hKey, lpSubKey, hSubKey)
            If regErrored(RegSetVal) Then
                RegCloseKey hKey
                Exit Function
            End If
        End If
    End If

    StringToBytes lpValueName, valname, 1024
    StringToBytes lpValueString, valData, 16384

    namelen = Len(lpValueName) + 1
    datalen = Len(lpValueString) + 1

    valType = REG_SZ
    RegSetVal = RegSetValueExB(hSubKey, valname(0), 0, valType, valData(0), datalen)

    If lpSubKey <> HKEY_SPECROOT Then RegCloseKey hSubKey
    RegCloseKey hKey
End Function

Public Function regErrored(ByVal result As Long)
    regErrored = result <> ERROR_SUCCESS
End Function

Public Function getCStr(ByVal v As Long, Optional ByVal pureConv As Boolean = True) As String
    Const nstr As String = "零一二三四五六七八九"
    Dim l As Integer, v_s As String, v_i As Integer, i As Integer

    getCStr = ""
    If v < 0 Then getCStr = "负": v = -v

    v_s = Trim(str(v))
    l = Len(v_s)
    i = 1
    While i <= l
        v_i = val(Mid(v_s, i, 1))
        If Not pureConv And v_i = 1 And l - i + 1 Mod 4 = 2 Then
        Else
            getCStr = getCStr + Mid(nstr, v_i + 1, 1)
        End If
        If Not pureConv Then
            Select Case (l - i + 1) Mod 4
            Case 0:
                getCStr = getCStr + "千"
            Case 1:
                Select Case Int((l - i + 1) / 4) 'num of 4-pairs
                Case 1: getCStr = getCStr + "万"
                Case 2: getCStr = getCStr + "亿"
                Case 3: getCStr = getCStr + "万亿"
                End Select
            Case 2: getCStr = getCStr + "十"
            Case 3: getCStr = getCStr + "百"
            End Select
        End If
        i = i + 1
    Wend
    If getCStr = "" Then getCStr = "零"
End Function

Public Function BytesToString(bytes() As Byte, ByVal numBytes As Long) As String
    Dim a As Long
    BytesToString = ""
    i = 0
    Do While i < numBytes
        a = bytes(i)
        If a = 0 Then Exit Do
        If a < 128 Then
            BytesToString = BytesToString + Chr(bytes(i))
        ElseIf i < numBytes - 1 Then
            i = i + 1
            BytesToString = BytesToString + Chr(a * 256 + bytes(i))
        End If
        i = i + 1
    Loop
End Function

Public Function lowByte(ByVal w As Long, ByVal order As Integer) As Byte
    Dim hexChr1 As Integer
    Dim hexChr2 As Integer
    On Error Resume Next

    hexChr1 = Asc(Left(Right(Hex(w), order * 2), 1)) - Asc("0")
    hexChr2 = Asc(Mid(Right(Hex(w), order * 2), 2, 1)) - Asc("0")
    If hexChr1 > 9 Then hexChr1 = hexChr1 - 7
    If hexChr2 > 9 Then hexChr2 = hexChr2 - 7

    lowByte = hexChr1 * 16 + hexChr2
End Function

Public Function StringToBytes(ByVal str As String, bytes() As Byte, ByVal numBytes As Long) As Boolean
    Dim pStr As Long, pByte As Long
    Dim c As Integer
    StringToBytes = True

    pStr = 1: pByte = 0
    Do While pByte < numBytes - 1 And pStr <= Len(str)
        c = Asc(Mid(str, pStr, 1))
        If Abs(c) >= 256 Then
            If pByte < numBytes - 2 Then
                bytes(pByte) = lowByte(c, 2)
                pByte = pByte + 1
            Else
                StringToBytes = False
                Exit Do
            End If
        End If
        bytes(pByte) = lowByte(c, 1)
        pByte = pByte + 1
        pStr = pStr + 1
    Loop
    bytes(pByte) = 0
End Function

Public Function getFirstNonBlankLine(ByVal text As String) As String
    Dim P As Integer, pStart As Integer
    Dim c As String
    Dim bStarted As Boolean
    P = 1
    bStarted = False
    Do While P < Len(text)
        c = Mid(text, P, 1)
        If Not bStarted Then
            If InStr(Chr(10) + Chr(13) + " " + vbTab, c) > 0 Then GoTo nextc
            bStarted = True
            pStart = P
        Else
            If InStr(Chr(10) + Chr(13), c) > 0 Then Exit Do
        End If
nextc:
        P = P + 1
    Loop
    If bStarted Then
        getFirstNonBlankLine = Mid(text, pStart, P - pStart)
    Else
        getFirstNonBlankLine = ""
    End If
End Function
