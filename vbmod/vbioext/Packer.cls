VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Packer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "ZbComm::Packer"

Private Const ZIP_LEVEL                 As Integer = 6 ' xclMedium
Private Const ZIP_METHOD                As Integer = 9 ' xcmDeflated64

Private m_ZipFolder As String
Private m_Recursive As Boolean
Private m_UnzipFolder As String
Private m_PackedPath As String
Private m_PackedName As String
Private m_VolumeSize As Long
Private m_Secret As String

Private WithEvents m_Zip As XceedZipLib.XceedZip
Attribute m_Zip.VB_VarHelpID = -1

Public Event Progress(ByVal Percent As Single, ByRef Cancel As Boolean)

Public Property Get ZipFolder() As String
    ZipFolder = m_ZipFolder
End Property

Public Property Let ZipFolder(ByVal newval As String)
    m_ZipFolder = newval
End Property

Public Property Get Recursive() As Boolean
    Recursive = m_Recursive
End Property

Public Property Let Recursive(ByVal newval As Boolean)
    m_Recursive = newval
End Property

Public Property Get UnzipFolder() As String
    UnzipFolder = m_UnzipFolder
End Property

Public Property Let UnzipFolder(ByVal newval As String)
    m_UnzipFolder = newval
End Property

Public Property Get PackedPath() As String
    PackedPath = m_PackedPath
End Property

Public Property Let PackedPath(ByVal newval As String)
    m_PackedPath = newval
End Property

Public Property Get PackedName() As String
    PackedName = m_PackedName
End Property

Public Property Let PackedName(ByVal newval As String)
    m_PackedName = newval
End Property

Public Property Get VolumeSize() As Long
    VolumeSize = m_VolumeSize
End Property

Public Property Let VolumeSize(ByVal newval As Long)
    m_VolumeSize = newval
End Property

Public Property Get Secret() As String
    Secret = m_Secret
End Property

Public Property Let Secret(ByVal newval As String)
    m_Secret = newval
End Property

Sub InitZip()
    Set m_Zip = New XceedZipLib.XceedZip
    m_Zip.License LICENSE_XC_ZIP

    m_Zip.BackgroundProcessing = False
    m_Zip.CompressionLevel = ZIP_LEVEL
    m_Zip.CompressionMethod = ZIP_METHOD

    m_Zip.BasePath = m_ZipFolder
    m_Zip.FilesToProcess = "*"
    m_Zip.ProcessSubfolders = m_Recursive
    m_Zip.PreservePaths = True

    m_Zip.ZipFilename = m_PackedPath
    If m_Secret <> "" Then
        m_Zip.EncryptionPassword = m_Secret
    End If
End Sub

Public Sub Pack()
    InitZip
    m_Zip.Zip
End Sub

Public Sub Unpack()
    InitZip
    m_Zip.Unzip
End Sub
