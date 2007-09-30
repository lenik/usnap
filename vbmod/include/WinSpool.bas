Attribute VB_Name = "modWinSpool"
Option Explicit

' -------------
' Print APIs
' -------------

Type PRINTER_INFO_1
        flags As Long
        pDescription As String
        pName As String
        pComment As String
End Type

Type PRINTER_INFO_2
        pServerName As String
        pPrinterName As String
        pShareName As String
        pPortName As String
        pDriverName As String
        pComment As String
        pLocation As String
        pDevmode As DEVMODE
        pSepFile As String
        pPrintProcessor As String
        pDatatype As String
        pParameters As String
        pSecurityDescriptor As SECURITY_DESCRIPTOR
        Attributes As Long
        Priority As Long
        DefaultPriority As Long
        StartTime As Long
        UntilTime As Long
        Status As Long
        cJobs As Long
        AveragePPM As Long
End Type
Public Const PRINTER_INFO_2_LEN = 84

Type PRINTER_INFO_3
        pSecurityDescriptor As SECURITY_DESCRIPTOR
End Type

Public Const PRINTER_CONTROL_PAUSE = 1
Public Const PRINTER_CONTROL_RESUME = 2
Public Const PRINTER_CONTROL_PURGE = 3

Public Const PRINTER_STATUS_PAUSED = &H1
Public Const PRINTER_STATUS_ERROR = &H2
Public Const PRINTER_STATUS_PENDING_DELETION = &H4
Public Const PRINTER_STATUS_PAPER_JAM = &H8
Public Const PRINTER_STATUS_PAPER_OUT = &H10
Public Const PRINTER_STATUS_MANUAL_FEED = &H20
Public Const PRINTER_STATUS_PAPER_PROBLEM = &H40
Public Const PRINTER_STATUS_OFFLINE = &H80
Public Const PRINTER_STATUS_IO_ACTIVE = &H100
Public Const PRINTER_STATUS_BUSY = &H200
Public Const PRINTER_STATUS_PRINTING = &H400
Public Const PRINTER_STATUS_OUTPUT_BIN_FULL = &H800
Public Const PRINTER_STATUS_NOT_AVAILABLE = &H1000
Public Const PRINTER_STATUS_WAITING = &H2000
Public Const PRINTER_STATUS_PROCESSING = &H4000
Public Const PRINTER_STATUS_INITIALIZING = &H8000
Public Const PRINTER_STATUS_WARMING_UP = &H10000
Public Const PRINTER_STATUS_TONER_LOW = &H20000
Public Const PRINTER_STATUS_NO_TONER = &H40000
Public Const PRINTER_STATUS_PAGE_PUNT = &H80000
Public Const PRINTER_STATUS_USER_INTERVENTION = &H100000
Public Const PRINTER_STATUS_OUT_OF_MEMORY = &H200000
Public Const PRINTER_STATUS_DOOR_OPEN = &H400000
Public Const PRINTER_STATUS_SERVER_UNKNOWN = &H800000
Public Const PRINTER_STATUS_POWER_SAVE = &H1000000

Public Const PRINTER_ATTRIBUTE_QUEUED = &H1
Public Const PRINTER_ATTRIBUTE_DIRECT = &H2
Public Const PRINTER_ATTRIBUTE_DEFAULT = &H4
Public Const PRINTER_ATTRIBUTE_SHARED = &H8
Public Const PRINTER_ATTRIBUTE_NETWORK = &H10
Public Const PRINTER_ATTRIBUTE_HIDDEN = &H20
Public Const PRINTER_ATTRIBUTE_LOCAL = &H40

Public Const NO_PRIORITY = 0
Public Const MAX_PRIORITY = 99
Public Const MIN_PRIORITY = 1
Public Const DEF_PRIORITY = 1

Type JOB_INFO_1
        JobId As Long
        pPrinterName As String
        pMachineName As String
        pUserName As String
        pDocument As String
        pDatatype As String
        pStatus As String
        Status As Long
        Priority As Long
        Position As Long
        TotalPages As Long
        PagesPrinted As Long
        Submitted As SystemTime
End Type

Type JOB_INFO_2
        JobId As Long
        pPrinterName As String
        pMachineName As String
        pUserName As String
        pDocument As String
        pNotifyName As String
        pDatatype As String
        pPrintProcessor As String
        pParameters As String
        pDriverName As String
        pDevmode As DEVMODE
        pStatus As String
        pSecurityDescriptor As SECURITY_DESCRIPTOR
        Status As Long
        Priority As Long
        Position As Long
        StartTime As Long
        UntilTime As Long
        TotalPages As Long
        Size As Long
        Submitted As SystemTime
        time As Long
        PagesPrinted As Long
End Type

Public Const JOB_CONTROL_PAUSE = 1
Public Const JOB_CONTROL_RESUME = 2
Public Const JOB_CONTROL_CANCEL = 3
Public Const JOB_CONTROL_RESTART = 4

Public Const JOB_STATUS_PAUSED = &H1
Public Const JOB_STATUS_ERROR = &H2
Public Const JOB_STATUS_DELETING = &H4
Public Const JOB_STATUS_SPOOLING = &H8
Public Const JOB_STATUS_PRINTING = &H10
Public Const JOB_STATUS_OFFLINE = &H20
Public Const JOB_STATUS_PAPEROUT = &H40
Public Const JOB_STATUS_PRINTED = &H80
Public Const JOB_STATUS_DELETED = &H100
Public Const JOB_STATUS_BLOCKED_DEVQ = &H200
Public Const JOB_STATUS_USER_INTERVENTION = &H400
Public Const JOB_STATUS_RESTART = &H800
Public Const JOB_STATUS_COMPLETE = &H1000

Public Const JOB_POSITION_UNSPECIFIED = 0

Type ADDJOB_INFO_1
        Path As String
        JobId As Long
End Type

Type DRIVER_INFO_1
        pName As String
End Type

Type DRIVER_INFO_2
        cVersion As Long
        pName As String
        pEnvironment As String
        pDriverPath As String
        pDataFile As String
        pConfigFile As String
End Type

Type DOC_INFO_1
        pDocName As String
        pOutputFile As String
        pDatatype As String
End Type

Type FORM_INFO_1
        pName As String
        Size As SIZEL
        ImageableArea As RECTL
End Type

Public Const FORM_BUILTIN = &H1

Type PRINTPROCESSOR_INFO_1
        pName As String
End Type

Type PORT_INFO_1
        pName As String
End Type

Type MONITOR_INFO_1
        pName As String
End Type

Type MONITOR_INFO_2
        pName As String
        pEnvironment As String
        pDLLName As String
End Type

Type DATATYPES_INFO_1
        pName As String
End Type

Type PRINTER_DEFAULTS
        pDatatype As String
        pDevmode As DEVMODE
        DesiredAccess As Long
End Type

Type PRINTER_INFO_4
        pPrinterName As String
        pServerName As String
        Attributes As Long
End Type

Type PRINTER_INFO_5
        pPrinterName As String
        pPortName As String
        Attributes As Long
        DeviceNotSelectedTimeout As Long
        TransmissionRetryTimeout As Long
End Type

Public Const PRINTER_CONTROL_SET_STATUS = 4
Public Const PRINTER_ATTRIBUTE_WORK_OFFLINE = &H400
Public Const PRINTER_ATTRIBUTE_ENABLE_BIDI = &H800
Public Const JOB_CONTROL_DELETE = 5

Type DRIVER_INFO_3
        cVersion As Long
        pName As String                    '  QMS 810
        pEnvironment As String             '  Win32 x86
        pDriverPath As String              '  c:\drivers\pscript.dll
        pDataFile As String                '  c:\drivers\QMS810.PPD
        pConfigFile As String              '  c:\drivers\PSCRPTUI.DLL
        pHelpFile As String                '  c:\drivers\PSCRPTUI.HLP
        pDependentFiles As String          '
        pMonitorName As String             '  "PJL monitor"
        pDefaultDataType As String         '  "EMF"
End Type

Type DOC_INFO_2
        pDocName As String
        pOutputFile As String
        pDatatype As String
        dwMode As Long
        JobId As Long
End Type

Public Const DI_CHANNEL = 1                  '  start direct read/write channel,
Public Const DI_READ_SPOOL_JOB = 3

Type PORT_INFO_2
        pPortName As String
        pMonitorName As String
        pDescription As String
        fPortType As Long
        Reserved As Long
End Type

Public Const PORT_TYPE_WRITE = &H1
Public Const PORT_TYPE_READ = &H2
Public Const PORT_TYPE_REDIRECTED = &H4
Public Const PORT_TYPE_NET_ATTACHED = &H8

Declare Function EnumPrinters Lib "winspool.drv" Alias "EnumPrintersA" (ByVal flags As Long, ByVal Name As String, ByVal Level As Long, ByVal pPrinterEnum As Long, ByVal cdBuf As Long, pcbNeeded As Long, pcReturned As Long) As Long

Declare Function EnumPrinterPropertySheets Lib "winspool.drv" (hPrinter As Long, hwnd As Long, lpfnAdd As Long, ByVal lParam As Long) As Long

Public Const PRINTER_ENUM_DEFAULT = &H1
Public Const PRINTER_ENUM_LOCAL = &H2
Public Const PRINTER_ENUM_CONNECTIONS = &H4
Public Const PRINTER_ENUM_FAVORITE = &H4
Public Const PRINTER_ENUM_NAME = &H8
Public Const PRINTER_ENUM_REMOTE = &H10
Public Const PRINTER_ENUM_SHARED = &H20
Public Const PRINTER_ENUM_NETWORK = &H40

Public Const PRINTER_ENUM_EXPAND = &H4000
Public Const PRINTER_ENUM_CONTAINER = &H8000

Public Const PRINTER_ENUM_ICONMASK = &HFF0000
Public Const PRINTER_ENUM_ICON1 = &H10000
Public Const PRINTER_ENUM_ICON2 = &H20000
Public Const PRINTER_ENUM_ICON3 = &H40000
Public Const PRINTER_ENUM_ICON4 = &H80000
Public Const PRINTER_ENUM_ICON5 = &H100000
Public Const PRINTER_ENUM_ICON6 = &H200000
Public Const PRINTER_ENUM_ICON7 = &H400000
Public Const PRINTER_ENUM_ICON8 = &H800000

Declare Function OpenPrinter Lib "winspool.drv" Alias "OpenPrinterA" (ByVal pPrinterName As String, phPrinter As Long, ByVal pDefault As Long) As Long
Declare Function ResetPrinter Lib "winspool.drv" Alias "ResetPrinterA" (ByVal hPrinter As Long, pDefault As PRINTER_DEFAULTS) As Long
Declare Function SetJob Lib "winspool.drv" Alias "SetJobA" (ByVal hPrinter As Long, ByVal JobId As Long, ByVal Level As Long, ByVal pJob As Long, ByVal Command As Long) As Long
Declare Function GetJob Lib "winspool.drv" Alias "GetJobA" (ByVal hPrinter As Long, ByVal JobId As Long, ByVal Level As Long, ByVal pJob As Long, ByVal cdBuf As Long, pcbNeeded As Long) As Long
Declare Function EnumJobs Lib "winspool.drv" Alias "EnumJobsA" (ByVal hPrinter As Long, ByVal FirstJob As Long, ByVal NoJobs As Long, ByVal Level As Long, ByVal pJob As Long, ByVal cdBuf As Long, pcbNeeded As Long, pcReturned As Long) As Long
Declare Function AddPrinter Lib "winspool.drv" Alias "AddPrinterA" (ByVal pName As String, ByVal Level As Long, pPrinter As Any) As Long

Declare Function AddPrinterDriver Lib "winspool.drv" Alias "AddPrinterDriverA" (ByVal pName As String, ByVal Level As Long, pDriverInfo As Any) As Long

Declare Function EnumPrinterDrivers Lib "winspool.drv" Alias "EnumPrinterDriversA" (ByVal pName As String, ByVal pEnvironment As String, ByVal Level As Long, ByVal pDriverInfo As Long, ByVal cdBuf As Long, pcbNeeded As Long, pcRetruned As Long) As Long
Declare Function GetPrinterDriver Lib "winspool.drv" Alias "GetPrinterDriverA" (ByVal hPrinter As Long, ByVal pEnvironment As String, ByVal Level As Long, ByVal pDriverInfo As Long, ByVal cdBuf As Long, pcbNeeded As Long) As Long
Declare Function GetPrinterDriverDirectory Lib "winspool.drv" Alias "GetPrinterDriverDirectoryA" (ByVal pName As String, ByVal pEnvironment As String, ByVal Level As Long, ByVal pDriverDirectory As Long, ByVal cdBuf As Long, pcbNeeded As Long) As Long
Declare Function DeletePrinterDriver Lib "winspool.drv" Alias "DeletePrinterDriverA" (ByVal pName As String, ByVal pEnvironment As String, ByVal pDriverName As String) As Long

Declare Function AddPrintProcessor Lib "winspool.drv" Alias "AddPrintProcessorA" (ByVal pName As String, ByVal pEnvironment As String, ByVal pPathName As String, ByVal pPrintProcessorName As String) As Long
Declare Function EnumPrintProcessors Lib "winspool.drv" Alias "EnumPrintProcessorsA" (ByVal pName As String, ByVal pEnvironment As String, ByVal Level As Long, ByVal pPrintProcessorInfo As Long, ByVal cdBuf As Long, pcbNeeded As Long, pcReturned As Long) As Long
Declare Function GetPrintProcessorDirectory Lib "winspool.drv" Alias "GetPrintProcessorDirectoryA" (ByVal pName As String, ByVal pEnvironment As String, ByVal Level As Long, ByVal pPrintProcessorInfo As String, ByVal cdBuf As Long, pcbNeeded As Long) As Long
Declare Function EnumPrintProcessorDatatypes Lib "winspool.drv" Alias "EnumPrintProcessorDatatypesA" (ByVal pName As String, ByVal pPrintProcessorName As String, ByVal Level As Long, ByVal pDatatypes As Long, ByVal cdBuf As Long, pcbNeeded As Long, pcRetruned As Long) As Long
Declare Function DeletePrintProcessor Lib "winspool.drv" Alias "DeletePrintProcessorA" (ByVal pName As String, ByVal pEnvironment As String, ByVal pPrintProcessorName As String) As Long

Declare Function StartDocPrinter Lib "winspool.drv" Alias "StartDocPrinterA" (ByVal hPrinter As Long, ByVal Level As Long, ByVal pDocInfo As Long) As Long
Declare Function StartPagePrinter Lib "winspool.drv" (ByVal hPrinter As Long) As Long
Declare Function WritePrinter Lib "winspool.drv" (ByVal hPrinter As Long, pBuf As Any, ByVal cdBuf As Long, pcWritten As Long) As Long
Declare Function EndPagePrinter Lib "winspool.drv" (ByVal hPrinter As Long) As Long
Declare Function AbortPrinter Lib "winspool.drv" (ByVal hPrinter As Long) As Long
Declare Function ReadPrinter Lib "winspool.drv" (ByVal hPrinter As Long, pBuf As Any, ByVal cdBuf As Long, pNoBytesRead As Long) As Long
Declare Function EndDocPrinter Lib "winspool.drv" (ByVal hPrinter As Long) As Long

Declare Function AddJob Lib "winspool.drv" Alias "AddJobA" (ByVal hPrinter As Long, ByVal Level As Long, ByVal pData As Long, ByVal cdBuf As Long, pcbNeeded As Long) As Long
Declare Function ScheduleJob Lib "winspool.drv" (ByVal hPrinter As Long, ByVal JobId As Long) As Long
Declare Function PrinterProperties Lib "winspool.drv" (ByVal hwnd As Long, ByVal hPrinter As Long) As Long
Declare Function DocumentProperties Lib "winspool.drv" Alias "DocumentPropertiesA" (ByVal hwnd As Long, ByVal hPrinter As Long, ByVal pDeviceName As String, pDevModeOutput As DEVMODE, pDevModeInput As DEVMODE, ByVal fMode As Long) As Long
Declare Function AdvancedDocumentProperties Lib "winspool.drv" Alias "AdvancedDocumentPropertiesA" (ByVal hwnd As Long, ByVal hPrinter As Long, ByVal pDeviceName As String, pDevModeOutput As DEVMODE, pDevModeInput As DEVMODE) As Long

Declare Function GetPrinterData Lib "winspool.drv" Alias "GetPrinterDataA" (ByVal hPrinter As Long, ByVal pValueName As String, pType As Long, ByVal pData As Long, ByVal nSize As Long, pcbNeeded As Long) As Long
Declare Function SetPrinterData Lib "winspool.drv" Alias "SetPrinterDataA" (ByVal hPrinter As Long, ByVal pValueName As String, ByVal dwType As Long, ByVal pData As Long, ByVal cbData As Long) As Long
Declare Function WaitForPrinterChange Lib "winspool.drv" (ByVal hPrinter As Long, ByVal flags As Long) As Long

Public Const PRINTER_CHANGE_ADD_PRINTER = &H1
Public Const PRINTER_CHANGE_SET_PRINTER = &H2
Public Const PRINTER_CHANGE_DELETE_PRINTER = &H4
Public Const PRINTER_CHANGE_PRINTER = &HFF
Public Const PRINTER_CHANGE_ADD_JOB = &H100
Public Const PRINTER_CHANGE_SET_JOB = &H200
Public Const PRINTER_CHANGE_DELETE_JOB = &H400
Public Const PRINTER_CHANGE_WRITE_JOB = &H800
Public Const PRINTER_CHANGE_JOB = &HFF00
Public Const PRINTER_CHANGE_ADD_FORM = &H10000
Public Const PRINTER_CHANGE_SET_FORM = &H20000
Public Const PRINTER_CHANGE_DELETE_FORM = &H40000
Public Const PRINTER_CHANGE_FORM = &H70000
Public Const PRINTER_CHANGE_ADD_PORT = &H100000
Public Const PRINTER_CHANGE_CONFIGURE_PORT = &H200000
Public Const PRINTER_CHANGE_DELETE_PORT = &H400000
Public Const PRINTER_CHANGE_PORT = &H700000
Public Const PRINTER_CHANGE_ADD_PRINT_PROCESSOR = &H1000000
Public Const PRINTER_CHANGE_DELETE_PRINT_PROCESSOR = &H4000000
Public Const PRINTER_CHANGE_PRINT_PROCESSOR = &H7000000
Public Const PRINTER_CHANGE_ADD_PRINTER_DRIVER = &H10000000
Public Const PRINTER_CHANGE_DELETE_PRINTER_DRIVER = &H40000000
Public Const PRINTER_CHANGE_PRINTER_DRIVER = &H70000000
Public Const PRINTER_CHANGE_TIMEOUT = &H80000000
Public Const PRINTER_CHANGE_ALL = &H7777FFFF

Declare Function PrinterMessageBox Lib "winspool.drv" Alias "PrinterMessageBoxA" (ByVal hPrinter As Long, ByVal error As Long, ByVal hwnd As Long, ByVal pText As String, ByVal pCaption As String, ByVal dwType As Long) As Long

Public Const PRINTER_ERROR_INFORMATION = &H80000000
Public Const PRINTER_ERROR_WARNING = &H40000000
Public Const PRINTER_ERROR_SEVERE = &H20000000

Public Const PRINTER_ERROR_OUTOFPAPER = &H1
Public Const PRINTER_ERROR_JAM = &H2
Public Const PRINTER_ERROR_OUTOFTONER = &H4

Declare Function ClosePrinter Lib "winspool.drv" (ByVal hPrinter As Long) As Long
Declare Function AddForm Lib "winspool.drv" Alias "AddFormA" (ByVal hPrinter As Long, ByVal Level As Long, ByVal pForm As Long) As Long
Declare Function DeleteForm Lib "winspool.drv" Alias "DeleteFormA" (ByVal hPrinter As Long, ByVal pFormName As String) As Long
Declare Function GetForm Lib "winspool.drv" Alias "GetFormA" (ByVal hPrinter As Long, ByVal pFormName As String, ByVal Level As Long, ByVal pForm As Long, ByVal cbBuf As Long, pcbNeeded As Long) As Long
Declare Function SetForm Lib "winspool.drv" Alias "SetFormA" (ByVal hPrinter As Long, ByVal pFormName As String, ByVal Level As Long, ByVal pForm As Long) As Long
Declare Function EnumForms Lib "winspool.drv" Alias "EnumFormsA" (ByVal hPrinter As Long, ByVal Level As Long, ByVal pForm As Long, ByVal cbBuf As Long, pcbNeeded As Long, pcReturned As Long) As Long

Declare Function EnumMonitors Lib "winspool.drv" Alias "EnumMonitorsA" (ByVal pName As String, ByVal Level As Long, ByVal pMonitors As Long, ByVal cbBuf As Long, pcbNeeded As Long, pcReturned As Long) As Long
Declare Function AddMonitor Lib "winspool.drv" Alias "AddMonitorA" (ByVal pName As String, ByVal Level As Long, ByVal pMonitors As Long) As Long
Declare Function DeleteMonitor Lib "winspool.drv" Alias "DeleteMonitorA" (ByVal pName As String, ByVal pEnvironment As String, ByVal pMonitorName As String) As Long

Declare Function EnumPorts Lib "winspool.drv" Alias "EnumPortsA" (ByVal pName As String, ByVal Level As Long, ByVal lpbPorts As Long, ByVal cbBuf As Long, pcbNeeded As Long, pcReturned As Long) As Long
Declare Function AddPort Lib "winspool.drv" Alias "AddPortA" (ByVal pName As String, ByVal hwnd As Long, ByVal pMonitorName As String) As Long
Declare Function ConfigurePort Lib "winspool.drv" Alias "ConfigurePortA" (ByVal pName As String, ByVal hwnd As Long, ByVal pPortName As String) As Long
Declare Function DeletePort Lib "winspool.drv" Alias "DeletePortA" (ByVal pName As String, ByVal hwnd As Long, ByVal pPortName As String) As Long

Declare Function AddPrinterConnection Lib "winspool.drv" Alias "AddPrinterConnectionA" (ByVal pName As String) As Long

Declare Function DeletePrinterConnection Lib "winspool.drv" Alias "DeletePrinterConnectionA" (ByVal pName As String) As Long
Declare Function ConnectToPrinterDlg Lib "winspool.drv" (ByVal hwnd As Long, ByVal flags As Long) As Long

Declare Function DeletePrinter Lib "winspool.drv" (ByVal hPrinter As Long) As Long

Declare Function FindClosePrinterChangeNotification Lib "winspool.drv" (ByVal hChange As Long) As Long
Declare Function FindFirstPrinterChangeNotification Lib "winspool.drv" (ByVal hPrinter As Long, ByVal fdwFlags As Long, ByVal fdwOptions As Long, ByVal pPrinterNotifyOptions As String) As Long
Declare Function FindNextPrinterChangeNotification Lib "winspool.drv" (ByVal hChange As Long, pdwChange As Long, ByVal pvReserved As String, ByVal ppPrinterNotifyInfo As Long) As Long
Declare Function GetPrinter Lib "winspool.drv" Alias "GetPrinterA" (ByVal hPrinter As Long, ByVal Level As Long, ByVal pPrinter As Long, ByVal cbBuf As Long, pcbNeeded As Long) As Long
Declare Function SetPrinter Lib "winspool.drv" Alias "SetPrinterA" (ByVal hPrinter As Long, ByVal Level As Long, ByVal pPrinter As Long, ByVal Command As Long) As Long

Type PROVIDOR_INFO_1
        pName As String
        pEnvironment As String
        pDLLName As String
End Type

Declare Function AddPrintProvidor Lib "winspool.drv" Alias "AddPrintProvidorA" (ByVal pName As String, ByVal Level As Long, ByVal pProvidorInfo As Long) As Long
Declare Function DeletePrintProvidor Lib "winspool.drv" Alias "DeletePrintProvidorA" (ByVal pName As String, ByVal pEnvironment As String, ByVal pPrintProvidorName As String) As Long

Public Const SERVER_ACCESS_ADMINISTER = &H1
Public Const SERVER_ACCESS_ENUMERATE = &H2

Public Const PRINTER_ACCESS_ADMINISTER = &H4
Public Const PRINTER_ACCESS_USE = &H8

Public Const JOB_ACCESS_ADMINISTER = &H10

' Access rights for print servers

Public Const SERVER_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED Or SERVER_ACCESS_ADMINISTER Or SERVER_ACCESS_ENUMERATE)
Public Const SERVER_READ = (STANDARD_RIGHTS_READ Or SERVER_ACCESS_ENUMERATE)
Public Const SERVER_WRITE = (STANDARD_RIGHTS_WRITE Or SERVER_ACCESS_ADMINISTER Or SERVER_ACCESS_ENUMERATE)
Public Const SERVER_EXECUTE = (STANDARD_RIGHTS_EXECUTE Or SERVER_ACCESS_ENUMERATE)

' Access rights for printers
Public Const PRINTER_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED Or PRINTER_ACCESS_ADMINISTER Or PRINTER_ACCESS_USE)
Public Const PRINTER_READ = (STANDARD_RIGHTS_READ Or PRINTER_ACCESS_USE)
Public Const PRINTER_WRITE = (STANDARD_RIGHTS_WRITE Or PRINTER_ACCESS_USE)
Public Const PRINTER_EXECUTE = (STANDARD_RIGHTS_EXECUTE Or PRINTER_ACCESS_USE)

' Access rights for jobs
Public Const JOB_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED Or JOB_ACCESS_ADMINISTER)
Public Const JOB_READ = (STANDARD_RIGHTS_READ Or JOB_ACCESS_ADMINISTER)
Public Const JOB_WRITE = (STANDARD_RIGHTS_WRITE Or JOB_ACCESS_ADMINISTER)
Public Const JOB_EXECUTE = (STANDARD_RIGHTS_EXECUTE Or JOB_ACCESS_ADMINISTER)
