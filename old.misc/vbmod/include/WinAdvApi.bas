Attribute VB_Name = "modWinAdvApi"
Option Explicit

' -----------------
' ADVAPI32
' -----------------

' function prototypes, constants, and type definitions
' for Windows 32-bit Registry API

Public Const HKEY_CLASSES_ROOT = &H80000000
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
Declare Function RegEnumKeyEx Lib "advapi32.dll" Alias "RegEnumKeyExA" (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpName As String, lpcbName As Long, ByVal lpReserved As Long, ByVal lpClass As String, lpcbClass As Long, lpftLastWriteTime As FILETIME) As Long
Declare Function RegEnumValue Lib "advapi32.dll" Alias "RegEnumValueA" (ByVal hKey As Long, ByVal dwIndex As Long, ByVal lpValueName As String, lpcbValueName As Long, ByVal lpReserved As Long, lpType As Long, lpData As Byte, lpcbData As Long) As Long
Declare Function RegFlushKey Lib "advapi32.dll" (ByVal hKey As Long) As Long
Declare Function RegGetKeySecurity Lib "advapi32.dll" (ByVal hKey As Long, ByVal SecurityInformation As Long, pSecurityDescriptor As SECURITY_DESCRIPTOR, lpcbSecurityDescriptor As Long) As Long
Declare Function RegLoadKey Lib "advapi32.dll" Alias "RegLoadKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal lpFile As String) As Long
Declare Function RegNotifyChangeKeyValue Lib "advapi32.dll" (ByVal hKey As Long, ByVal bWatchSubtree As Long, ByVal dwNotifyFilter As Long, ByVal hEvent As Long, ByVal fAsynchronus As Long) As Long
Declare Function RegOpenKey Lib "advapi32.dll" Alias "RegOpenKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, phkResult As Long) As Long
Declare Function RegOpenKeyEx Lib "advapi32.dll" Alias "RegOpenKeyExA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal ulOptions As Long, ByVal samDesired As Long, phkResult As Long) As Long
Declare Function RegQueryInfoKey Lib "advapi32.dll" Alias "RegQueryInfoKeyA" (ByVal hKey As Long, ByVal lpClass As String, lpcbClass As Long, ByVal lpReserved As Long, lpcSubKeys As Long, lpcbMaxSubKeyLen As Long, lpcbMaxClassLen As Long, lpcValues As Long, lpcbMaxValueNameLen As Long, lpcbMaxValueLen As Long, lpcbSecurityDescriptor As Long, lpftLastWriteTime As FILETIME) As Long
Declare Function RegQueryValue Lib "advapi32.dll" Alias "RegQueryValueA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal lpValue As String, lpcbValue As Long) As Long
Declare Function RegQueryValueEx Lib "advapi32.dll" Alias "RegQueryValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, lpType As Long, lpData As Any, lpcbData As Long) As Long         ' Note that if you declare the lpData parameter as String, you must pass it By Value.
Declare Function RegReplaceKey Lib "advapi32.dll" Alias "RegReplaceKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal lpNewFile As String, ByVal lpOldFile As String) As Long
Declare Function RegRestoreKey Lib "advapi32.dll" Alias "RegRestoreKeyA" (ByVal hKey As Long, ByVal lpFile As String, ByVal dwFlags As Long) As Long
Declare Function RegSaveKey Lib "advapi32.dll" Alias "RegSaveKeyA" (ByVal hKey As Long, ByVal lpFile As String, lpSecurityAttributes As SECURITY_ATTRIBUTES) As Long
Declare Function RegSetKeySecurity Lib "advapi32.dll" (ByVal hKey As Long, ByVal SecurityInformation As Long, pSecurityDescriptor As SECURITY_DESCRIPTOR) As Long
Declare Function RegSetValue Lib "advapi32.dll" Alias "RegSetValueA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal dwType As Long, ByVal lpData As String, ByVal cbData As Long) As Long
Declare Function RegSetValueEx Lib "advapi32.dll" Alias "RegSetValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal Reserved As Long, ByVal dwType As Long, lpData As Any, ByVal cbData As Long) As Long         ' Note that if you declare the lpData parameter as String, you must pass it By Value.
Declare Function RegUnLoadKey Lib "advapi32.dll" Alias "RegUnLoadKeyA" (ByVal hKey As Long, ByVal lpSubKey As String) As Long
Declare Function InitiateSystemShutdown Lib "advapi32.dll" Alias "InitiateSystemShutdownA" (ByVal lpMachineName As String, ByVal lpMessage As String, ByVal dwTimeout As Long, ByVal bForceAppsClosed As Long, ByVal bRebootAfterShutdown As Long) As Long
Declare Function AbortSystemShutdown Lib "advapi32.dll" Alias "AbortSystemShutdownA" (ByVal lpMachineName As String) As Long

' Service database names
Public Const SERVICES_ACTIVE_DATABASE = "ServicesActive"
Public Const SERVICES_FAILED_DATABASE = "ServicesFailed"

' Value to indicate no change to an optional parameter
Public Const SERVICE_NO_CHANGE = &HFFFF

' Service State -- for Enum Requests (Bit Mask)
Public Const SERVICE_ACTIVE = &H1
Public Const SERVICE_INACTIVE = &H2
Public Const SERVICE_STATE_ALL = (SERVICE_ACTIVE Or SERVICE_INACTIVE)

' Controls
Public Const SERVICE_CONTROL_STOP = &H1
Public Const SERVICE_CONTROL_PAUSE = &H2
Public Const SERVICE_CONTROL_CONTINUE = &H3
Public Const SERVICE_CONTROL_INTERROGATE = &H4
Public Const SERVICE_CONTROL_SHUTDOWN = &H5

' Service State -- for CurrentState
Public Const SERVICE_STOPPED = &H1
Public Const SERVICE_START_PENDING = &H2
Public Const SERVICE_STOP_PENDING = &H3
Public Const SERVICE_RUNNING = &H4
Public Const SERVICE_CONTINUE_PENDING = &H5
Public Const SERVICE_PAUSE_PENDING = &H6
Public Const SERVICE_PAUSED = &H7

' Controls Accepted  (Bit Mask)
Public Const SERVICE_ACCEPT_STOP = &H1
Public Const SERVICE_ACCEPT_PAUSE_CONTINUE = &H2
Public Const SERVICE_ACCEPT_SHUTDOWN = &H4

' Service Control Manager object specific access types
Public Const SC_MANAGER_CONNECT = &H1
Public Const SC_MANAGER_CREATE_SERVICE = &H2
Public Const SC_MANAGER_ENUMERATE_SERVICE = &H4
Public Const SC_MANAGER_LOCK = &H8
Public Const SC_MANAGER_QUERY_LOCK_STATUS = &H10
Public Const SC_MANAGER_MODIFY_BOOT_CONFIG = &H20

Public Const SC_MANAGER_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED Or SC_MANAGER_CONNECT Or SC_MANAGER_CREATE_SERVICE Or SC_MANAGER_ENUMERATE_SERVICE Or SC_MANAGER_LOCK Or SC_MANAGER_QUERY_LOCK_STATUS Or SC_MANAGER_MODIFY_BOOT_CONFIG)

' Service object specific access type
Public Const SERVICE_QUERY_CONFIG = &H1
Public Const SERVICE_CHANGE_CONFIG = &H2
Public Const SERVICE_QUERY_STATUS = &H4
Public Const SERVICE_ENUMERATE_DEPENDENTS = &H8
Public Const SERVICE_START = &H10
Public Const SERVICE_STOP = &H20
Public Const SERVICE_PAUSE_CONTINUE = &H40
Public Const SERVICE_INTERROGATE = &H80
Public Const SERVICE_USER_DEFINED_CONTROL = &H100

Public Const SERVICE_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED Or SERVICE_QUERY_CONFIG Or SERVICE_CHANGE_CONFIG Or SERVICE_QUERY_STATUS Or SERVICE_ENUMERATE_DEPENDENTS Or SERVICE_START Or SERVICE_STOP Or SERVICE_PAUSE_CONTINUE Or SERVICE_INTERROGATE Or SERVICE_USER_DEFINED_CONTROL)


Type SERVICE_STATUS
        dwServiceType As Long
        dwCurrentState As Long
        dwControlsAccepted As Long
        dwWin32ExitCode As Long
        dwServiceSpecificExitCode As Long
        dwCheckPoint As Long
        dwWaitHint As Long
End Type

Type ENUM_SERVICE_STATUS
        lpServiceName As String
        lpDisplayName As String
        ServiceStatus As SERVICE_STATUS
End Type

Type QUERY_SERVICE_LOCK_STATUS
        fIsLocked As Long
        lpLockOwner As String
        dwLockDuration As Long
End Type

Type QUERY_SERVICE_CONFIG
        dwServiceType As Long
        dwStartType As Long
        dwErrorControl As Long
        lpBinaryPathName As String
        lpLoadOrderGroup As String
        dwTagId As Long
        lpDependencies As String
        lpServiceStartName As String
        lpDisplayName As String
End Type

Type SERVICE_TABLE_ENTRY
        lpServiceName As String
        lpServiceProc As Long
End Type


' ++ BUILD Version: 0010    '  Increment this if a change has global effects
' Copyright (c) 1995  Microsoft Corporation
' Module Name:
'     winsvc.h
' Abstract:
'     Header file for the Service Control Manager
' Environment:
'     User Mode - Win32
' --*/
'
'  Constants

'  Character to designate that a name is a group
'
Public Const SC_GROUP_IDENTIFIER = "+"

'  Prototype for the Service Control Handler Function

' /////////////////////////////////////////////////////////////////////////
'  API Function Prototypes
' /////////////////////////////////////////////////////////////////////////

Declare Function ChangeServiceConfig Lib "advapi32.dll" Alias "ChangeServiceConfigA" (ByVal hService As Long, ByVal dwServiceType As Long, ByVal dwStartType As Long, ByVal dwErrorControl As Long, ByVal lpBinaryPathName As String, ByVal lpLoadOrderGroup As String, lpdwTagId As Long, ByVal lpDependencies As String, ByVal lpServiceStartName As String, ByVal lpPassword As String, ByVal lpDisplayName As String) As Long
Declare Function CloseServiceHandle Lib "advapi32.dll" (ByVal hSCObject As Long) As Long
Declare Function ControlService Lib "advapi32.dll" (ByVal hService As Long, ByVal dwControl As Long, lpServiceStatus As SERVICE_STATUS) As Long
Declare Function CreateService Lib "advapi32.dll" Alias "CreateServiceA" (ByVal hSCManager As Long, ByVal lpServiceName As String, ByVal lpDisplayName As String, ByVal dwDesiredAccess As Long, ByVal dwServiceType As Long, ByVal dwStartType As Long, ByVal dwErrorControl As Long, ByVal lpBinaryPathName As String, ByVal lpLoadOrderGroup As String, lpdwTagId As Long, ByVal lpDependencies As String, ByVal lp As String, ByVal lpPassword As String) As Long
Declare Function DeleteService Lib "advapi32.dll" (ByVal hService As Long) As Long
Declare Function EnumDependentServices Lib "advapi32.dll" Alias "EnumDependentServicesA" (ByVal hService As Long, ByVal dwServiceState As Long, lpServices As ENUM_SERVICE_STATUS, ByVal cbBufSize As Long, pcbBytesNeeded As Long, lpServicesReturned As Long) As Long
Declare Function EnumServicesStatus Lib "advapi32.dll" Alias "EnumServicesStatusA" (ByVal hSCManager As Long, ByVal dwServiceType As Long, ByVal dwServiceState As Long, lpServices As ENUM_SERVICE_STATUS, ByVal cbBufSize As Long, pcbBytesNeeded As Long, lpServicesReturned As Long, lpResumeHandle As Long) As Long
Declare Function GetServiceKeyName Lib "advapi32.dll" Alias "GetServiceKeyNameA" (ByVal hSCManager As Long, ByVal lpDisplayName As String, ByVal lpServiceName As String, lpcchBuffer As Long) As Long
Declare Function GetServiceDisplayName Lib "advapi32.dll" Alias "GetServiceDisplayNameA" (ByVal hSCManager As Long, ByVal lpServiceName As String, ByVal lpDisplayName As String, lpcchBuffer As Long) As Long
Declare Function LockServiceDatabase Lib "advapi32.dll" (ByVal hSCManager As Long) As Long
Declare Function NotifyBootConfigStatus Lib "advapi32.dll" (ByVal BootAcceptable As Long) As Long
Declare Function OpenSCManager Lib "advapi32.dll" Alias "OpenSCManagerA" (ByVal lpMachineName As String, ByVal lpDatabaseName As String, ByVal dwDesiredAccess As Long) As Long
Declare Function OpenService Lib "advapi32.dll" Alias "OpenServiceA" (ByVal hSCManager As Long, ByVal lpServiceName As String, ByVal dwDesiredAccess As Long) As Long
Declare Function QueryServiceConfig Lib "advapi32.dll" Alias "QueryServiceConfigA" (ByVal hService As Long, lpServiceConfig As QUERY_SERVICE_CONFIG, ByVal cbBufSize As Long, pcbBytesNeeded As Long) As Long
Declare Function QueryServiceLockStatus Lib "advapi32.dll" Alias "QueryServiceLockStatusA" (ByVal hSCManager As Long, lpLockStatus As QUERY_SERVICE_LOCK_STATUS, ByVal cbBufSize As Long, pcbBytesNeeded As Long) As Long
Declare Function QueryServiceObjectSecurity Lib "advapi32.dll" (ByVal hService As Long, ByVal dwSecurityInformation As Long, lpSecurityDescriptor As Any, ByVal cbBufSize As Long, pcbBytesNeeded As Long) As Long
Declare Function QueryServiceStatus Lib "advapi32.dll" (ByVal hService As Long, lpServiceStatus As SERVICE_STATUS) As Long
Declare Function RegisterServiceCtrlHandler Lib "advapi32.dll" Alias "RegisterServiceCtrlHandlerA" (ByVal lpServiceName As String, ByVal lpHandlerProc As Long) As Long
Declare Function SetServiceObjectSecurity Lib "advapi32.dll" (ByVal hService As Long, ByVal dwSecurityInformation As Long, lpSecurityDescriptor As Any) As Long
Declare Function SetServiceStatus Lib "advapi32.dll" (ByVal hServiceStatus As Long, lpServiceStatus As SERVICE_STATUS) As Long
Declare Function StartServiceCtrlDispatcher Lib "advapi32.dll" Alias "StartServiceCtrlDispatcherA" (lpServiceStartTable As SERVICE_TABLE_ENTRY) As Long
Declare Function StartService Lib "advapi32.dll" Alias "StartServiceA" (ByVal hService As Long, ByVal dwNumServiceArgs As Long, ByVal lpServiceArgVectors As Long) As Long
Declare Function UnlockServiceDatabase Lib "advapi32.dll" (ScLock As Any) As Long

Type LARGE_INTEGER
    lowpart As Long
    highpart As Long
End Type


' Section for Performance Monitor data

Public Const PERF_DATA_VERSION = 1
Public Const PERF_DATA_REVISION = 1

Type PERF_DATA_BLOCK
        Signature As String * 4
        LittleEndian As Long
        Version As Long
        Revision As Long
        TotalByteLength As Long
        HeaderLength As Long
        NumObjectTypes As Long
        DefaultObject As Long
        SystemTime As SystemTime
        PerfTime As LARGE_INTEGER
        PerfFreq As LARGE_INTEGER
        PerTime100nSec As LARGE_INTEGER
        SystemNameLength As Long
        SystemNameOffset As Long
End Type

Type PERF_OBJECT_TYPE
        TotalByteLength As Long
        DefinitionLength As Long
        HeaderLength As Long
        ObjectNameTitleIndex As Long
        ObjectNameTitle As String
        ObjectHelpTitleIndex As Long
        ObjectHelpTitle As String
        DetailLevel As Long
        NumCounters As Long
        DefaultCounter As Long
        NumInstances As Long
        CodePage As Long
        PerfTime As LARGE_INTEGER
        PerfFreq As LARGE_INTEGER
End Type

Public Const PERF_NO_INSTANCES = -1  '  no instances

' The counter type is the "or" of the following values as described below
'
' select one of the following to indicate the counter's data size
Public Const PERF_SIZE_DWORD = &H0
Public Const PERF_SIZE_LARGE = &H100
Public Const PERF_SIZE_ZERO = &H200       '  for Zero Length fields
Public Const PERF_SIZE_VARIABLE_LEN = &H300       '  length is in CounterLength field of Counter Definition struct

' select one of the following values to indicate the counter field usage
Public Const PERF_TYPE_NUMBER = &H0         '  a number (not a counter)
Public Const PERF_TYPE_COUNTER = &H400       '  an increasing numeric value
Public Const PERF_TYPE_TEXT = &H800       '  a text field
Public Const PERF_TYPE_ZERO = &HC00       '  displays a zero

' If the PERF_TYPE_NUMBER field was selected, then select one of the
' following to describe the Number
Public Const PERF_NUMBER_HEX = &H0         '  display as HEX value
Public Const PERF_NUMBER_DECIMAL = &H10000     '  display as a decimal integer
Public Const PERF_NUMBER_DEC_1000 = &H20000     '  display as a decimal/1000
'
' If the PERF_TYPE_COUNTER value was selected then select one of the
' following to indicate the type of counter
Public Const PERF_COUNTER_VALUE = &H0         '  display counter value
Public Const PERF_COUNTER_RATE = &H10000     '  divide ctr / delta time
Public Const PERF_COUNTER_FRACTION = &H20000     '  divide ctr / base
Public Const PERF_COUNTER_BASE = &H30000     '  base value used in fractions
Public Const PERF_COUNTER_ELAPSED = &H40000     '  subtract counter from current time
Public Const PERF_COUNTER_QUEUELEN = &H50000     '  Use Queuelen processing func.
Public Const PERF_COUNTER_HISTOGRAM = &H60000     '  Counter begins or ends a histogram

' If the PERF_TYPE_TEXT value was selected, then select one of the
' following to indicate the type of TEXT data.
Public Const PERF_TEXT_UNICODE = &H0         '  type of text in text field
Public Const PERF_TEXT_ASCII = &H10000     '  ASCII using the CodePage field

' Timer SubTypes
Public Const PERF_TIMER_TICK = &H0         '  use system perf. freq for base
Public Const PERF_TIMER_100NS = &H100000    '  use 100 NS timer time base units
Public Const PERF_OBJECT_TIMER = &H200000    '  use the object timer freq

' Any types that have calculations performed can use one or more of
' the following calculation modification flags listed here
Public Const PERF_DELTA_COUNTER = &H400000    '  compute difference first
Public Const PERF_DELTA_BASE = &H800000    '  compute base diff as well
Public Const PERF_INVERSE_COUNTER = &H1000000   '  show as 1.00-value (assumes:
Public Const PERF_MULTI_COUNTER = &H2000000   '  sum of multiple instances

' Select one of the following values to indicate the display suffix (if any)
Public Const PERF_DISPLAY_NO_SUFFIX = &H0         '  no suffix
Public Const PERF_DISPLAY_PER_SEC = &H10000000  '  "/sec"
Public Const PERF_DISPLAY_PERCENT = &H20000000  '  "%"
Public Const PERF_DISPLAY_SECONDS = &H30000000  '  "secs"
Public Const PERF_DISPLAY_NOSHOW = &H40000000  '  value is not displayed

' Predefined counter types

' 32-bit Counter.  Divide delta by delta time.  Display suffix: "/sec"
Public Const PERF_COUNTER_COUNTER = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_TICK Or PERF_DELTA_COUNTER Or PERF_DISPLAY_PER_SEC)

' 64-bit Timer.  Divide delta by delta time.  Display suffix: "%"
Public Const PERF_COUNTER_TIMER = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_TICK Or PERF_DELTA_COUNTER Or PERF_DISPLAY_PERCENT)

' Queue Length Space-Time Product. Divide delta by delta time. No Display Suffix.
Public Const PERF_COUNTER_QUEUELEN_TYPE = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_QUEUELEN Or PERF_TIMER_TICK Or PERF_DELTA_COUNTER Or PERF_DISPLAY_NO_SUFFIX)

' 64-bit Counter.  Divide delta by delta time. Display Suffix: "/sec"
Public Const PERF_COUNTER_BULK_COUNT = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_TICK Or PERF_DELTA_COUNTER Or PERF_DISPLAY_PER_SEC)

' Indicates the counter is not a  counter but rather Unicode text Display as text.
Public Const PERF_COUNTER_TEXT = (PERF_SIZE_VARIABLE_LEN Or PERF_TYPE_TEXT Or PERF_TEXT_UNICODE Or PERF_DISPLAY_NO_SUFFIX)

' Indicates the data is a counter  which should not be
' time averaged on display (such as an error counter on a serial line)
' Display as is.  No Display Suffix.
Public Const PERF_COUNTER_RAWCOUNT = (PERF_SIZE_DWORD Or PERF_TYPE_NUMBER Or PERF_NUMBER_DECIMAL Or PERF_DISPLAY_NO_SUFFIX)

' A count which is either 1 or 0 on each sampling interrupt (% busy)
' Divide delta by delta base. Display Suffix: "%"
Public Const PERF_SAMPLE_FRACTION = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_FRACTION Or PERF_DELTA_COUNTER Or PERF_DELTA_BASE Or PERF_DISPLAY_PERCENT)

' A count which is sampled on each sampling interrupt (queue length)
' Divide delta by delta time. No Display Suffix.
Public Const PERF_SAMPLE_COUNTER = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_TICK Or PERF_DELTA_COUNTER Or PERF_DISPLAY_NO_SUFFIX)

' A label: no data is associated with this counter (it has 0 length)
' Do not display.
Public Const PERF_COUNTER_NODATA = (PERF_SIZE_ZERO Or PERF_DISPLAY_NOSHOW)

' 64-bit Timer inverse (e.g., idle is measured, but display busy  As Integer)
' Display 100 - delta divided by delta time.  Display suffix: "%"
Public Const PERF_COUNTER_TIMER_INV = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_TICK Or PERF_DELTA_COUNTER Or PERF_INVERSE_COUNTER Or PERF_DISPLAY_PERCENT)

' The divisor for a sample, used with the previous counter to form a
' sampled %.  You must check for >0 before dividing by this!  This
' counter will directly follow the  numerator counter.  It should not
' be displayed to the user.
Public Const PERF_SAMPLE_BASE = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_BASE Or PERF_DISPLAY_NOSHOW Or &H1)         '  for compatibility with pre-beta versions

' A timer which, when divided by an average base, produces a time
' in seconds which is the average time of some operation.  This
' timer times total operations, and  the base is the number of opera-
' tions.  Display Suffix: "sec"
Public Const PERF_AVERAGE_TIMER = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_FRACTION Or PERF_DISPLAY_SECONDS)

' Used as the denominator in the computation of time or count
' averages.  Must directly follow the numerator counter.  Not dis-
' played to the user.
Public Const PERF_AVERAGE_BASE = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_BASE Or PERF_DISPLAY_NOSHOW Or &H2)         '  for compatibility with pre-beta versions

' A bulk count which, when divided (typically) by the number of
' operations, gives (typically) the number of bytes per operation.
' No Display Suffix.
Public Const PERF_AVERAGE_BULK = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_FRACTION Or PERF_DISPLAY_NOSHOW)

' 64-bit Timer in 100 nsec units. Display delta divided by
' delta time.  Display suffix: "%"
Public Const PERF_100NSEC_TIMER = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_100NS Or PERF_DELTA_COUNTER Or PERF_DISPLAY_PERCENT)

' 64-bit Timer inverse (e.g., idle is measured, but display busy  As Integer)
' Display 100 - delta divided by delta time.  Display suffix: "%"
Public Const PERF_100NSEC_TIMER_INV = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_100NS Or PERF_DELTA_COUNTER Or PERF_INVERSE_COUNTER Or PERF_DISPLAY_PERCENT)

' 64-bit Timer.  Divide delta by delta time.  Display suffix: "%"
' Timer for multiple instances, so result can exceed 100%.
Public Const PERF_COUNTER_MULTI_TIMER = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_DELTA_COUNTER Or PERF_TIMER_TICK Or PERF_MULTI_COUNTER Or PERF_DISPLAY_PERCENT)

' 64-bit Timer inverse (e.g., idle is measured, but display busy  As Integer)
' Display 100  _MULTI_BASE - delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result
' can exceed 100%.  Followed by a counter of type _MULTI_BASE.
Public Const PERF_COUNTER_MULTI_TIMER_INV = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_RATE Or PERF_DELTA_COUNTER Or PERF_MULTI_COUNTER Or PERF_TIMER_TICK Or PERF_INVERSE_COUNTER Or PERF_DISPLAY_PERCENT)

' Number of instances to which the preceding _MULTI_..._INV counter
' applies.  Used as a factor to get the percentage.
Public Const PERF_COUNTER_MULTI_BASE = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_BASE Or PERF_MULTI_COUNTER Or PERF_DISPLAY_NOSHOW)

' 64-bit Timer in 100 nsec units. Display delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result can exceed 100%.
Public Const PERF_100NSEC_MULTI_TIMER = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_DELTA_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_100NS Or PERF_MULTI_COUNTER Or PERF_DISPLAY_PERCENT)

' 64-bit Timer inverse (e.g., idle is measured, but display busy  As Integer)
' Display 100  _MULTI_BASE - delta divided by delta time.
' Display suffix: "%" Timer for multiple instances, so result
' can exceed 100%.  Followed by a counter of type _MULTI_BASE.
Public Const PERF_100NSEC_MULTI_TIMER_INV = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_DELTA_COUNTER Or PERF_COUNTER_RATE Or PERF_TIMER_100NS Or PERF_MULTI_COUNTER Or PERF_INVERSE_COUNTER Or PERF_DISPLAY_PERCENT)

' Indicates the data is a fraction of the following counter  which
' should not be time averaged on display (such as free space over
' total space.) Display as is.  Display the quotient as "%".
Public Const PERF_RAW_FRACTION = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_FRACTION Or PERF_DISPLAY_PERCENT)

' Indicates the data is a base for the preceding counter which should
' not be time averaged on display (such as free space over total space.)
Public Const PERF_RAW_BASE = (PERF_SIZE_DWORD Or PERF_TYPE_COUNTER Or PERF_COUNTER_BASE Or PERF_DISPLAY_NOSHOW Or &H3)         '  for compatibility with pre-beta versions

' The data collected in this counter is actually the start time of the
' item being measured. For display, this data is subtracted from the
' sample time to yield the elapsed time as the difference between the two.
' In the definition below, the PerfTime field of the Object contains
' the sample time as indicated by the PERF_OBJECT_TIMER bit and the
' difference is scaled by the PerfFreq of the Object to convert the time
' units into seconds.
Public Const PERF_ELAPSED_TIME = (PERF_SIZE_LARGE Or PERF_TYPE_COUNTER Or PERF_COUNTER_ELAPSED Or PERF_OBJECT_TIMER Or PERF_DISPLAY_SECONDS)

' The following counter type can be used with the preceding types to
' define a range of values to be displayed in a histogram.
Public Const PERF_COUNTER_HISTOGRAM_TYPE = &H80000000  ' Counter begins or ends a histogram

' The following are used to determine the level of detail associated
' with the counter.  The user will be setting the level of detail
' that should be displayed at any given time.
Public Const PERF_DETAIL_NOVICE = 100 '  The uninformed can understand it
Public Const PERF_DETAIL_ADVANCED = 200 '  For the advanced user
Public Const PERF_DETAIL_EXPERT = 300 '  For the expert user
Public Const PERF_DETAIL_WIZARD = 400 '  For the system designer

Type PERF_COUNTER_DEFINITION
        ByteLength As Long
        CounterNameTitleIndex As Long
        CounterNameTitle As String
        CounterHelpTitleIndex As Long
        CounterHelpTitle As String
        DefaultScale As Long
        DetailLevel As Long
        CounterType As Long
        CounterSize As Long
        CounterOffset As Long
End Type

Public Const PERF_NO_UNIQUE_ID = -1

Type PERF_INSTANCE_DEFINITION
        ByteLength As Long
        ParentObjectTitleIndex As Long
        ParentObjectInstance As Long
        UniqueID As Long
        NameOffset As Long
        NameLength As Long
End Type

Type PERF_COUNTER_BLOCK
        ByteLength As Long
End Type

Public Const CDERR_DIALOGFAILURE = &HFFFF

Public Const CDERR_GENERALCODES = &H0
Public Const CDERR_STRUCTSIZE = &H1
Public Const CDERR_INITIALIZATION = &H2
Public Const CDERR_NOTEMPLATE = &H3
Public Const CDERR_NOHINSTANCE = &H4
Public Const CDERR_LOADSTRFAILURE = &H5
Public Const CDERR_FINDRESFAILURE = &H6
Public Const CDERR_LOADRESFAILURE = &H7
Public Const CDERR_LOCKRESFAILURE = &H8
Public Const CDERR_MEMALLOCFAILURE = &H9
Public Const CDERR_MEMLOCKFAILURE = &HA
Public Const CDERR_NOHOOK = &HB
Public Const CDERR_REGISTERMSGFAIL = &HC

Public Const PDERR_PRINTERCODES = &H1000
Public Const PDERR_SETUPFAILURE = &H1001
Public Const PDERR_PARSEFAILURE = &H1002
Public Const PDERR_RETDEFFAILURE = &H1003
Public Const PDERR_LOADDRVFAILURE = &H1004
Public Const PDERR_GETDEVMODEFAIL = &H1005
Public Const PDERR_INITFAILURE = &H1006
Public Const PDERR_NODEVICES = &H1007
Public Const PDERR_NODEFAULTPRN = &H1008
Public Const PDERR_DNDMMISMATCH = &H1009
Public Const PDERR_CREATEICFAILURE = &H100A
Public Const PDERR_PRINTERNOTFOUND = &H100B
Public Const PDERR_DEFAULTDIFFERENT = &H100C

Public Const CFERR_CHOOSEFONTCODES = &H2000
Public Const CFERR_NOFONTS = &H2001
Public Const CFERR_MAXLESSTHANMIN = &H2002

Public Const FNERR_FILENAMECODES = &H3000
Public Const FNERR_SUBCLASSFAILURE = &H3001
Public Const FNERR_INVALIDFILENAME = &H3002
Public Const FNERR_BUFFERTOOSMALL = &H3003

Public Const FRERR_FINDREPLACECODES = &H4000
Public Const FRERR_BUFFERLENGTHZERO = &H4001

Public Const CCERR_CHOOSECOLORCODES = &H5000


' Public interface to LZEXP?.LIB

'  LZEXPAND error return codes
Public Const LZERROR_BADINHANDLE = (-1)  '  invalid input handle
Public Const LZERROR_BADOUTHANDLE = (-2) '  invalid output handle
Public Const LZERROR_READ = (-3)         '  corrupt compressed file format
Public Const LZERROR_WRITE = (-4)        '  out of space for output file
Public Const LZERROR_PUBLICLOC = (-5)    '  insufficient memory for LZFile struct
Public Const LZERROR_GLOBLOCK = (-6)     '  bad Global handle
Public Const LZERROR_BADVALUE = (-7)     '  input parameter out of range
Public Const LZERROR_UNKNOWNALG = (-8)   '  compression algorithm not recognized

Declare Function LZCopy Lib "lz32.dll" (ByVal hfSource As Long, ByVal hfDest As Long) As Long
Declare Function LZInit Lib "lz32.dll" (ByVal hfSrc As Long) As Long
Declare Function GetExpandedName Lib "lz32.dll" Alias "GetExpandedNameA" (ByVal lpszSource As String, ByVal lpszBuffer As String) As Long
Declare Function LZOpenFile Lib "lz32.dll" Alias "LZOpenFileA" (ByVal lpszFile As String, lpOf As OFSTRUCT, ByVal style As Long) As Long
Declare Function LZSeek Lib "lz32.dll" (ByVal hfFile As Long, ByVal lOffset As Long, ByVal nOrigin As Long) As Long
Declare Function LZRead Lib "lz32.dll" (ByVal hfFile As Long, ByVal lpvBuf As String, ByVal cbread As Long) As Long
Declare Sub LZClose Lib "lz32.dll" (ByVal hfFile As Long)
