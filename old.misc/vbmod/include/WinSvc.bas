Attribute VB_Name = "modWinSvc"
Option Explicit

Public Const SERVICES_ACTIVE_DATABASE      As String = "ServicesActive"
Public Const SERVICES_FAILED_DATABASE      As String = "ServicesFailed"

Public Const SC_GROUP_IDENTIFIER           As Byte = 53     ' (int)'+'

' Value to indicate no change to an optional parameter
'
Public Const SERVICE_NO_CHANGE              As Long = &HFFFFFFFF

'
' Service State -- for Enum Requests (Bit Mask)
'
Public Const SERVICE_ACTIVE                 As Long = &H1
Public Const SERVICE_INACTIVE               As Long = &H2
Public Const SERVICE_STATE_ALL              As Long = (SERVICE_ACTIVE Or SERVICE_INACTIVE)

'
' Controls
'
Public Const SERVICE_CONTROL_STOP           As Long = &H1
Public Const SERVICE_CONTROL_PAUSE          As Long = &H2
Public Const SERVICE_CONTROL_CONTINUE       As Long = &H3
Public Const SERVICE_CONTROL_INTERROGATE    As Long = &H4
Public Const SERVICE_CONTROL_SHUTDOWN       As Long = &H5
Public Const SERVICE_CONTROL_PARAMCHANGE    As Long = &H6
Public Const SERVICE_CONTROL_NETBINDADD     As Long = &H7
Public Const SERVICE_CONTROL_NETBINDREMOVE  As Long = &H8
Public Const SERVICE_CONTROL_NETBINDENABLE  As Long = &H9
Public Const SERVICE_CONTROL_NETBINDDISABLE As Long = &HA

'
' Service State -- for CurrentState
'
Public Const SERVICE_STOPPED                As Long = &H1
Public Const SERVICE_START_PENDING          As Long = &H2
Public Const SERVICE_STOP_PENDING           As Long = &H3
Public Const SERVICE_RUNNING                As Long = &H4
Public Const SERVICE_CONTINUE_PENDING       As Long = &H5
Public Const SERVICE_PAUSE_PENDING          As Long = &H6
Public Const SERVICE_PAUSED                 As Long = &H7

'
' Controls Accepted  (Bit Mask)
'
Public Const SERVICE_ACCEPT_STOP            As Long = &H1
Public Const SERVICE_ACCEPT_PAUSE_CONTINUE  As Long = &H2
Public Const SERVICE_ACCEPT_SHUTDOWN        As Long = &H4
Public Const SERVICE_ACCEPT_PARAMCHANGE     As Long = &H8
Public Const SERVICE_ACCEPT_NETBINDCHANGE   As Long = &H10

'
' Service Control Manager object specific access types
'
Public Const SC_MANAGER_CONNECT             As Long = &H1
Public Const SC_MANAGER_CREATE_SERVICE      As Long = &H2
Public Const SC_MANAGER_ENUMERATE_SERVICE   As Long = &H4
Public Const SC_MANAGER_LOCK                As Long = &H8
Public Const SC_MANAGER_QUERY_LOCK_STATUS   As Long = &H10
Public Const SC_MANAGER_MODIFY_BOOT_CONFIG  As Long = &H20

        '
        Public Const STANDARD_RIGHTS_REQUIRED As Long = &HF0000

Public Const SC_MANAGER_ALL_ACCESS          As Long = (STANDARD_RIGHTS_REQUIRED Or _
                                        SC_MANAGER_CONNECT Or _
                                        SC_MANAGER_CREATE_SERVICE Or _
                                        SC_MANAGER_ENUMERATE_SERVICE Or _
                                        SC_MANAGER_LOCK Or _
                                        SC_MANAGER_QUERY_LOCK_STATUS Or _
                                        SC_MANAGER_MODIFY_BOOT_CONFIG)



'
' Service object specific access type
'
Public Const SERVICE_QUERY_CONFIG           As Long = &H1
Public Const SERVICE_CHANGE_CONFIG          As Long = &H2
Public Const SERVICE_QUERY_STATUS           As Long = &H4
Public Const SERVICE_ENUMERATE_DEPENDENTS   As Long = &H8
Public Const SERVICE_START                  As Long = &H10
Public Const SERVICE_STOP                   As Long = &H20
Public Const SERVICE_PAUSE_CONTINUE         As Long = &H40
Public Const SERVICE_INTERROGATE            As Long = &H80
Public Const SERVICE_USER_DEFINED_CONTROL   As Long = &H100

Public Const SERVICE_ALL_ACCESS             As Long = (STANDARD_RIGHTS_REQUIRED Or _
                                        SERVICE_QUERY_CONFIG Or _
                                        SERVICE_CHANGE_CONFIG Or _
                                        SERVICE_QUERY_STATUS Or _
                                        SERVICE_ENUMERATE_DEPENDENTS Or _
                                        SERVICE_START Or _
                                        SERVICE_STOP Or _
                                        SERVICE_PAUSE_CONTINUE Or _
                                        SERVICE_INTERROGATE Or _
                                        SERVICE_USER_DEFINED_CONTROL)


'
' Info levels for ChangeServiceConfig2 and QueryServiceConfig2
'
Public Const SERVICE_CONFIG_DESCRIPTION     As Long = 1
Public Const SERVICE_CONFIG_FAILURE_ACTIONS As Long = 2

'
' Service description string
'
Type SERVICE_DESCRIPTION
    lpDescription As String
End Type
Type LPSERVICE_DESCRIPTION
    address As Long
End Type

'
' Actions to take on service failure
'
Enum SC_ACTION_TYPE
        SC_ACTION_NONE = 0
        SC_ACTION_RESTART = 1
        SC_ACTION_REBOOT = 2
        SC_ACTION_RUN_COMMAND = 3
End Enum

Type SC_ACTION
    actionType As SC_ACTION_TYPE
    Delay As Long
End Type
Type LPSC_ACTION
    address As Long
End Type

Type SERVICE_FAILURE_ACTIONS
    dwResetPeriod As Long
    lpRebootMsg As String
    lpCommand As String
    cActions As Long
    lpsaActions As Long            'size_is(cActions)
End Type
Type LPSERVICE_FAILURE_ACTIONS
    address As Long
End Type

'
' Service Status Structure
'

Type SERVICE_STATUS
     dwServiceType As Long
     dwCurrentState As Long
     dwControlsAccepted As Long
     dwWin32ExitCode As Long
     dwServiceSpecificExitCode As Long
     dwCheckPoint As Long
     dwWaitHint As Long
End Type
Type LPSERVICE_STATUS
    address As Long
End Type

'
' Service Status Enumeration Structure
'

Type ENUM_SERVICE_STATUS
    lpServiceName As String
    lpDisplayName As String
    ServiceStatus As SERVICE_STATUS
End Type
Type LPENUM_SERVICE_STATUS
    address As Long
End Type

'
' Structures for the Lock API functions
'

Type QUERY_SERVICE_LOCK_STATUS
    fIsLocked As Long
    lpLockOwner As String
    dwLockDuration As Long
End Type
Type LPQUERY_SERVICE_LOCK_STATUS
    address As Long
End Type


'
' Query Service Configuration Structure
'

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
Type LPQUERY_SERVICE_CONFIG
    address As Long
End Type

'
' Function Prototype for the Service Main Function
'

Type LPSERVICE_MAIN_FUNCTION
    address As Long
End Type
'typedef VOID ( *LPSERVICE_MAIN_FUNCTIONW)(
'    byval dwNumServicesArgs as long,
'    LPWSTR  *lpServiceArgVectors
'    );

'
' Service Start Table
'

Type SERVICE_TABLE_ENTRY
    lpServiceName As String
    lpServiceProc As LPSERVICE_MAIN_FUNCTION
End Type

'
' Prototype for the Service Control Handler Function
'

Type LPHANDLER_FUNCTION
    address As Long
End Type
'typedef VOID ( *LPHANDLER_FUNCTION)(
'    byval dwControl as long
'    );


'''''''''''''''''''''''''''''''''''''/
' API Function Prototypes
'''''''''''''''''''''''''''''''''''''/

Declare Function ChangeServiceConfig Lib "" Alias "ChangeServiceConfigW" (ByVal hService As Long, ByVal dwServiceType As Long, ByVal dwStartType As Long, ByVal dwErrorControl As Long, ByVal lpBinaryPathName As String, ByVal lpLoadOrderGroup As String, lpdwTagId As Long, ByVal lpDependencies As String, ByVal lpServiceStartName As String, ByVal lpPassword As String, ByVal lpDisplayName As String) As Boolean
Declare Function ChangeServiceConfig2 Lib "" (ByVal hService As Long, ByVal dwInfoLevel As Long, ByVal lpvoid_lpInfo As Long) As Boolean
Declare Function CloseServiceHandle Lib "" (ByVal hSCObject As Long) As Boolean
Declare Function ControlService Lib "" (ByVal hService As Long, ByVal dwControl As Long, ByVal lpServiceStatus As LPSERVICE_STATUS) As Boolean
Declare Function CreateService Lib "" Alias "CreateServiceW" (ByVal hSCManager As Long, ByVal lpServiceName As String, ByVal lpDisplayName As String, ByVal dwDesiredAccess As Long, ByVal dwServiceType As Long, ByVal dwStartType As Long, ByVal dwErrorControl As Long, ByVal lpBinaryPathName As String, ByVal lpLoadOrderGroup As String, lpdwTagId As Long, ByVal lpDependencies As String, ByVal lpServiceStartName As String, ByVal lpPassword As String) As Long
Declare Function DeleteService Lib "" (ByVal hService As Long) As Boolean
Declare Function EnumDependentServices Lib "" Alias "EnumDependentServicesW(ByVal hService As Long, ByVal dwServiceState As Long, ByVal lpServices As LPENUM_SERVICE_STATUS, ByVal cbBufSize As Long, pcbBytesNeeded As Long, lpServicesReturned As Long) As Boolean" ()
Declare Function EnumServicesStatus Lib "" Alias "EnumServicesStatusW" (ByVal hSCManager As Long, ByVal dwServiceType As Long, ByVal dwServiceState As Long, ByVal lpServices As LPENUM_SERVICE_STATUS, ByVal cbBufSize As Long, pcbBytesNeeded As Long, lpServicesReturned As Long, lpResumeHandle As Long) As Boolean
Declare Function GetServiceKeyName Lib "" Alias "GetServiceKeyNameW" (ByVal hSCManager As Long, ByVal lpDisplayName As String, ByVal lpServiceName As String, lpcchBuffer As Long) As Boolean
Declare Function GetServiceDisplayName Lib "" Alias "GetServiceDisplayNameW" (ByVal hSCManager As Long, ByVal lpServiceName As String, ByVal lpDisplayName As String, lpcchBuffer As Long) As Boolean
Declare Function LockServiceDatabase Lib "" (ByVal hSCManager As Long) As Long        ' lpVoid
Declare Function NotifyBootConfigStatus Lib "" (ByVal BootAcceptable As Boolean) As Boolean
Declare Function OpenSCManagerA Lib "" (ByVal lpMachineName As String, ByVal lpDatabaseName As String, ByVal dwDesiredAccess As Long) As Long
Declare Function OpenSCManager Lib "" Alias "OpenSCManagerW lib (    byval lpMachineName as string,    byval lpDatabaseName as string,    byval dwDesiredAccess as long    ) as long" ()
Declare Function OpenService Lib "" Alias "OpenServiceW" (ByVal hSCManager As Long, ByVal lpServiceName As String, ByVal dwDesiredAccess As Long) As Long
Declare Function QueryServiceConfig Lib "" Alias "QueryServiceConfigW" (ByVal hService As Long, ByVal lpServiceConfig As LPQUERY_SERVICE_CONFIG, ByVal cbBufSize As Long, pcbBytesNeeded As Long) As Boolean
Declare Function QueryServiceConfig2 Lib "" Alias "QueryServiceConfig2W" (ByVal hService As Long, ByVal dwInfoLevel As Long, lpBuffer As Byte, ByVal cbBufSize As Long, pcbBytesNeeded As Long) As Boolean
Declare Function QueryServiceLockStatus Lib "" Alias "QueryServiceLockStatusW" (ByVal hSCManager As Long, ByVal lpLockStatus As LPQUERY_SERVICE_LOCK_STATUS, ByVal cbBufSize As Long, pcbBytesNeeded As Long) As Boolean
'Declare Function QueryServiceObjectSecurity Lib "" (ByVal hService As Long, ByVal dwSecurityInformation As SECURITY_INFORMATION, ByVal lpSecurityDescriptor As PSECURITY_DESCRIPTOR, ByVal cbBufSize As Long, pcbBytesNeeded As Long) As Boolean
Declare Function QueryServiceStatus Lib "" (ByVal hService As Long, ByVal lpServiceStatus As LPSERVICE_STATUS) As Boolean
Declare Function RegisterServiceCtrlHandle Lib "" Alias "RegisterServiceCtrlHandlerW" (ByVal lpServiceName As String, ByVal lpHandlerProc As LPHANDLER_FUNCTION) As Long
'Declare Function SetServiceObjectSecurity Lib "" (ByVal hService As Long, ByVal dwSecurityInformation As SECURITY_INFORMATION, ByVal lpSecurityDescriptor As PSECURITY_DESCRIPTOR) As Boolean
Declare Function SetServiceStatus Lib "" (ByVal hServiceStatus As Long, ByVal lpServiceStatus As LPSERVICE_STATUS) As Boolean
Declare Function StartServiceCtrlDispatcher Lib "" Alias "StartServiceCtrlDispatcherW" (lpServiceStartTable As SERVICE_TABLE_ENTRY) As Boolean
Declare Function StartService Lib "StartServiceW" (ByVal hService As Long, ByVal dwNumServiceArgs As Long, ByVal reflpServiceArgVectors As Long) As Boolean
Declare Function UnlockServiceDatabase Lib "" (ByVal lpvoid_ScLock As Long) As Boolean
