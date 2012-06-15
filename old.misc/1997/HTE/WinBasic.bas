Attribute VB_Name = "WinBasic"
Public Const ANYSIZE_ARRAY = 1
Type RECT
        Left As Long
        Top As Long
        Right As Long
        Bottom As Long
End Type

Type RECTL
        Left As Long
        Top As Long
        Right As Long
        Bottom As Long
End Type

Type POINTAPI
        X As Long
        Y As Long
End Type

Type POINTL
        X As Long
        Y As Long
End Type

Type Size
        cx As Long
        cy As Long
End Type

Type POINTS
        X  As Integer
        Y  As Integer
End Type

Type Msg
    hWnd As Long
    message As Long
    wParam As Long
    lParam As Long
    time As Long
    pt As POINTAPI
End Type


Public Const DELETE = &H10000
Public Const READ_CONTROL = &H20000
Public Const WRITE_DAC = &H40000
Public Const WRITE_OWNER = &H80000
Public Const SYNCHRONIZE = &H100000


Public Const STANDARD_RIGHTS_READ = (READ_CONTROL)
Public Const STANDARD_RIGHTS_WRITE = (READ_CONTROL)
Public Const STANDARD_RIGHTS_EXECUTE = (READ_CONTROL)
Public Const STANDARD_RIGHTS_REQUIRED = &HF0000
Public Const STANDARD_RIGHTS_ALL = &H1F0000

Public Const SPECIFIC_RIGHTS_ALL = &HFFFF


Type SID_IDENTIFIER_AUTHORITY
        Value(6) As Byte
End Type

Public Const SID_REVISION = (1)                         '  Current revision level
Public Const SID_MAX_SUB_AUTHORITIES = (15)
Public Const SID_RECOMMENDED_SUB_AUTHORITIES = (1)      ' Will change to around 6 in a future release.

Public Const SidTypeUser = 1
Public Const SidTypeGroup = 2
Public Const SidTypeDomain = 3
Public Const SidTypeAlias = 4
Public Const SidTypeWellKnownGroup = 5
Public Const SidTypeDeletedAccount = 6
Public Const SidTypeInvalid = 7
Public Const SidTypeUnknown = 8

Type SID_AND_ATTRIBUTES
        Sid As Long
        Attributes As Long
End Type
