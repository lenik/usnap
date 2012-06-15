Attribute VB_Name = "modWNet"

'  Windows Network support

'  RESOURCE ENUMERATION

Public Const RESOURCE_CONNECTED = &H1
Public Const RESOURCE_PUBLICNET = &H2
Public Const RESOURCE_REMEMBERED = &H3

Public Const RESOURCETYPE_ANY = &H0
Public Const RESOURCETYPE_DISK = &H1
Public Const RESOURCETYPE_PRINT = &H2
Public Const RESOURCETYPE_UNKNOWN = &HFFFF

Public Const RESOURCEUSAGE_CONNECTABLE = &H1
Public Const RESOURCEUSAGE_CONTAINER = &H2
Public Const RESOURCEUSAGE_RESERVED = &H80000000

Public Const RESOURCEDISPLAYTYPE_GENERIC = &H0
Public Const RESOURCEDISPLAYTYPE_DOMAIN = &H1
Public Const RESOURCEDISPLAYTYPE_SERVER = &H2
Public Const RESOURCEDISPLAYTYPE_SHARE = &H3
Public Const RESOURCEDISPLAYTYPE_FILE = &H4
Public Const RESOURCEDISPLAYTYPE_GROUP = &H5

Type NETRESOURCE
        dwScope As Long
        dwType As Long
        dwDisplayType As Long
        dwUsage As Long
        lpLocalName As String
        lpRemoteName As String
        lpComment As String
        lpProvider As String
End Type

Public Const CONNECT_UPDATE_PROFILE = &H1

Declare Function WNetAddConnection Lib "mpr.dll" Alias "WNetAddConnectionA" (ByVal lpszNetPath As String, ByVal lpszPassword As String, ByVal lpszLocalName As String) As Long
Declare Function WNetAddConnection2 Lib "mpr.dll" Alias "WNetAddConnection2A" (lpNetResource As NETRESOURCE, ByVal lpPassword As String, ByVal lpUserName As String, ByVal dwFlags As Long) As Long
Declare Function WNetCancelConnection Lib "mpr.dll" Alias "WNetCancelConnectionA" (ByVal lpszName As String, ByVal bForce As Long) As Long
Declare Function WNetCancelConnection2 Lib "mpr.dll" Alias "WNetCancelConnection2A" (ByVal lpName As String, ByVal dwFlags As Long, ByVal fForce As Long) As Long
Declare Function WNetGetConnection Lib "mpr.dll" Alias "WNetGetConnectionA" (ByVal lpszLocalName As String, ByVal lpszRemoteName As String, cbRemoteName As Long) As Long
'Declare Function WNetOpenEnum Lib "mpr.dll" Alias "WNetOpenEnumA" (ByVal dwScope As Long, ByVal dwType As Long, ByVal dwUsage As Long, lpNetResource As NETRESOURCE, lphEnum As Long) As Long
Declare Function WNetOpenEnum Lib "mpr.dll" Alias "WNetOpenEnumA" (ByVal dwScope As Long, ByVal dwType As Long, ByVal dwUsage As Long, lpNetResource As Any, lphEnum As Long) As Long
Declare Function WNetEnumResource Lib "mpr.dll" Alias "WNetEnumResourceA" (ByVal hEnum As Long, lpcCount As Long, lpBuffer As Any, lpBufferSize As Long) As Long
Declare Function WNetCloseEnum Lib "mpr.dll" (ByVal hEnum As Long) As Long

Declare Function WNetGetUser Lib "mpr.dll" Alias "WNetGetUserA" (ByVal lpName As String, ByVal lpUserName As String, lpnLength As Long) As Long

Declare Function WNetConnectionDialog Lib "mpr.dll" (ByVal hwnd As Long, ByVal dwType As Long) As Long
Declare Function WNetDisconnectDialog Lib "mpr.dll" (ByVal hwnd As Long, ByVal dwType As Long) As Long

Declare Function WNetGetLastError Lib "mpr.dll" Alias "WNetGetLastErrorA" (lpError As Long, ByVal lpErrorBuf As String, ByVal nErrorBufSize As Long, ByVal lpNameBuf As String, ByVal nNameBufSize As Long) As Long

' Status Codes

' This section is provided for backward compatibility.  Use of the ERROR_
' codes is preferred.  The WN_ error codes may not be available in future
' releases.

' General

Public Const WN_SUCCESS = NO_ERROR
Public Const WN_NOT_SUPPORTED = ERROR_NOT_SUPPORTED
Public Const WN_NET_ERROR = ERROR_UNEXP_NET_ERR
Public Const WN_MORE_DATA = ERROR_MORE_DATA
Public Const WN_BAD_POINTER = ERROR_INVALID_ADDRESS
Public Const WN_BAD_VALUE = ERROR_INVALID_PARAMETER
Public Const WN_BAD_PASSWORD = ERROR_INVALID_PASSWORD
Public Const WN_ACCESS_DENIED = ERROR_ACCESS_DENIED
Public Const WN_FUNCTION_BUSY = ERROR_BUSY
Public Const WN_WINDOWS_ERROR = ERROR_UNEXP_NET_ERR
Public Const WN_BAD_USER = ERROR_BAD_USERNAME
Public Const WN_OUT_OF_MEMORY = ERROR_NOT_ENOUGH_MEMORY
Public Const WN_NO_NETWORK = ERROR_NO_NETWORK
Public Const WN_EXTENDED_ERROR = ERROR_EXTENDED_ERROR

' Connection

Public Const WN_NOT_CONNECTED = ERROR_NOT_CONNECTED
Public Const WN_OPEN_FILES = ERROR_OPEN_FILES
Public Const WN_DEVICE_IN_USE = ERROR_DEVICE_IN_USE
Public Const WN_BAD_NETNAME = ERROR_BAD_NET_NAME
Public Const WN_BAD_LOCALNAME = ERROR_BAD_DEVICE
Public Const WN_ALREADY_CONNECTED = ERROR_ALREADY_ASSIGNED
Public Const WN_DEVICE_ERROR = ERROR_GEN_FAILURE
Public Const WN_CONNECTION_CLOSED = ERROR_CONNECTION_UNAVAIL
Public Const WN_NO_NET_OR_BAD_PATH = ERROR_NO_NET_OR_BAD_PATH
Public Const WN_BAD_PROVIDER = ERROR_BAD_PROVIDER
Public Const WN_CANNOT_OPEN_PROFILE = ERROR_CANNOT_OPEN_PROFILE
Public Const WN_BAD_PROFILE = ERROR_BAD_PROFILE

' Enumeration

Public Const WN_BAD_HANDLE = ERROR_INVALID_HANDLE
Public Const WN_NO_MORE_ENTRIES = ERROR_NO_MORE_ITEMS
Public Const WN_NOT_CONTAINER = ERROR_NOT_CONTAINER

Public Const WN_NO_ERROR = NO_ERROR
