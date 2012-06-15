Attribute VB_Name = "ErrorConstants"
Option Explicit

' (Standard)
' ----------------------------------------------------------------------------
Public Const ERR_OK                 As Long = 0

' VBExt.Config
' ----------------------------------------------------------------------------
Public Const ERR_NOENTRY            As Long = 1001
Public Const ERR_CANT_LOAD_CONFIG   As Long = 1002
Public Const ERR_SUB_NOT_EXIST      As Long = 1003

' Xnet.File
' ----------------------------------------------------------------------------
Public Const ERR_PFK_OPEN_FILE      As Long = 2001
Public Const ERR_PFK_WRITE_FILE     As Long = 2002
Public Const ERR_PFK_CHECKSUM       As Long = 2003
Public Const ERR_PUT_CHECKSUM       As Long = 2010
Public Const ERR_HASH_READFILE      As Long = 2020

' ZBComm
' ----------------------------------------------------------------------------
Public Const ERR_DRIVER_IN_USE      As Long = 3001

'
' (在上面添加所有错误代码)
'
