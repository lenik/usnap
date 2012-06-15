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

Private Const LOCATION                  As String = "NetTools::Packer"

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
Public Event ZippingFile(ByVal FileName As String, ByVal FileSize As Long)
Public Event UnzippingFile(ByVal FileName As String, ByVal FileSize As Long, ByVal CompressedSize As Long)
Public Event Zipped()
Public Event Unzipped()

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
    Assert newval >= 0, "Invalid volume size", LOCATION
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

    If m_VolumeSize <> 0 Then
        m_Zip.SplitSize = m_VolumeSize
    End If

    m_Zip.ZipFilename = m_PackedPath
    If m_Secret <> "" Then
        m_Zip.EncryptionPassword = m_Secret
    End If
End Sub

Public Sub Pack()
    InitZip
    PF.MakeParents m_PackedPath
    m_Zip.Zip
End Sub

Public Sub Unpack()
    InitZip
    PF.MakeParents m_UnzipFolder
    m_Zip.Unzip
End Sub

Private Sub m_Zip_FileStatus(ByVal sFilename As String, _
                             ByVal lSize As Long, _
                             ByVal lCompressedSize As Long, _
                             ByVal lBytesProcessed As Long, _
                             ByVal nBytesPercent As Integer, _
                             ByVal nCompressionRatio As Integer, _
                             ByVal bFileCompleted As Boolean)

End Sub

Private Sub m_Zip_GlobalStatus(ByVal lFilesTotal As Long, _
                               ByVal lFilesProcessed As Long, _
                               ByVal lFilesSkipped As Long, _
                               ByVal nFilesPercent As Integer, _
                               ByVal lBytesTotal As Long, _
                               ByVal lBytesProcessed As Long, _
                               ByVal lBytesSkipped As Long, _
                               ByVal nBytesPercent As Integer, _
                               ByVal lBytesOutput As Long, _
                               ByVal nCompressionRatio As Integer)
    'RaiseEvent Progress
End Sub

Private Sub m_Zip_ProcessCompleted(ByVal lFilesTotal As Long, _
                                   ByVal lFilesProcessed As Long, _
                                   ByVal lFilesSkipped As Long, _
                                   ByVal lBytesTotal As Long, _
                                   ByVal lBytesProcessed As Long, _
                                   ByVal lBytesSkipped As Long, _
                                   ByVal lBytesOutput As Long, _
                                   ByVal nCompressionRatio As Integer, _
                                   ByVal xResult As XceedZipLib.xcdError)
    RaiseEvent Zipped
End Sub

Private Sub m_Zip_ProcessCompleted64(ByVal lFilesTotal As Long, _
                                     ByVal lFilesProcessed As Long, _
                                     ByVal lFilesSkipped As Long, _
                                     ByVal lBytesTotalLow As Long, _
                                     ByVal lBytesTotalHigh As Long, _
                                     ByVal lBytesProcessedLow As Long, _
                                     ByVal lBytesProcessedHigh As Long, _
                                     ByVal lBytesSkippedLow As Long, _
                                     ByVal lBytesSkippedHigh As Long, _
                                     ByVal lBytesOutputLow As Long, _
                                     ByVal lBytesOutputHigh As Long, _
                                     ByVal nCompressionRatio As Integer, _
                                     ByVal xResult As XceedZipLib.xcdError)
    RaiseEvent Zipped
End Sub

Private Sub m_Zip_UnzipPreprocessingFile(ByVal sFilename As String, _
                                         ByVal sComment As String, _
                                         sDestFilename As String, _
                                         ByVal lSize As Long, _
                                         ByVal lCompressedSize As Long, _
                                         xAttributes As XceedZipLib.xcdFileAttributes, _
                                         ByVal lCRC As Long, _
                                         dtLastModified As Date, _
                                         dtLastAccessed As Date, _
                                         dtCreated As Date, _
                                         ByVal xMethod As XceedZipLib.xcdCompressionMethod, _
                                         ByVal bEncrypted As Boolean, _
                                         sPassword As String, _
                                         ByVal lDiskNumber As Long, _
                                         bExcluded As Boolean, _
                                         ByVal xReason As XceedZipLib.xcdSkippingReason, _
                                         ByVal bExisting As Boolean, _
                                         xDestination As XceedZipLib.xcdUnzipDestination)
    RaiseEvent UnzippingFile(sFilename, lSize, lCompressedSize)
End Sub

Private Sub m_Zip_ZipPreprocessingFile(sFilename As String, _
                                       sComment As String, _
                                       ByVal sSourceFilename As String, _
                                       ByVal lSize As Long, _
                                       xAttributes As XceedZipLib.xcdFileAttributes, _
                                       dtLastModified As Date, _
                                       dtLastAccessed As Date, _
                                       dtCreated As Date, _
                                       xMethod As XceedZipLib.xcdCompressionMethod, _
                                       bEncrypted As Boolean, _
                                       sPassword As String, _
                                       bExcluded As Boolean, _
                                       ByVal xReason As XceedZipLib.xcdSkippingReason, _
                                       ByVal bExisting As Boolean)
    RaiseEvent ZippingFile(sFilename, lSize)
End Sub
