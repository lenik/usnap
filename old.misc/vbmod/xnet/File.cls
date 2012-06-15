VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "File"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::File"
Private Const HASHBLOCK                 As Long = 16384

Public Enum PacketStatusConstants
    pktQueued = 0
    pktTransferring
    pktTransferred
End Enum

Private m_RecvMode As Boolean
Private m_GUID As String
Private m_Size As Long
Private m_PacketSize As Long
Private m_Checksum As String
Private m_FullName As String
Private m_Encrypted As Boolean

Private m_Status As PacketStatusConstants
Private m_Packets As Long
Private m_TransferringPackets As Long
Private m_TransferringSize As Long
Private m_TransferredPackets As Long
Private m_TransferredSize As Long

Private m_Pkt() As PacketStatusConstants

Private m_Path As String
Private m_File As BinaryFile
Private m_DeleteWhenTransferred As Boolean
Private m_DeleteWhenCanceled As Boolean

Public Event OnError(ByVal ErrId As Long, ByVal Description As String)
Public Event OnHashing(ByVal ProcessedSize As Long)

Public Property Get RecvMode() As Boolean
    RecvMode = m_RecvMode
End Property

Public Property Let RecvMode(ByVal newval As Boolean)
    m_RecvMode = newval
End Property

Public Property Get GUID() As String
    GUID = m_GUID
End Property

Public Property Let GUID(ByVal newval As String)
    m_GUID = newval
End Property

Public Property Get Size() As Long
    Size = m_Size
End Property

Public Property Get PacketSize() As Long
    PacketSize = m_PacketSize
End Property

Public Property Get Checksum() As String
    Checksum = m_Checksum
End Property

Public Property Let Checksum(ByVal newval As String)
    m_Checksum = newval
End Property

Public Property Get FullName() As String
    FullName = m_FullName
End Property

Public Property Let FullName(ByVal newval As String)
    m_FullName = newval
End Property

Public Property Get Encrypted() As Boolean
    Encrypted = m_Encrypted
End Property

Public Property Let Encrypted(ByVal newval As Boolean)
    m_Encrypted = newval
End Property

Public Property Get Prefix() As String
    Dim p As Integer
    p = InStrRev(m_FullName, "/")
    If p > 0 Then
        Prefix = Left(m_FullName, p - 1)
    End If
End Property

Public Property Get Name() As String
    Dim p As Integer
    p = InStrRev(m_FullName, "/")
    If p > 0 Then
        Name = Mid(m_FullName, p + 1)
    Else
        Name = m_FullName
    End If
End Property

Public Property Get Packets() As Long
    Packets = m_Packets
End Property

Public Property Get TransferringPackets() As Long
    TransferringPackets = m_TransferringPackets
End Property

Public Property Get TransferringSize() As Long
    TransferringSize = m_TransferringSize
End Property

Public Property Get TransferredPackets() As Long
    TransferredPackets = m_TransferredPackets
End Property

Public Property Get TransferredSize() As Long
    TransferredSize = m_TransferredSize
End Property

Public Property Get PacketStatus(ByVal Index As Long) As PacketStatusConstants
    PacketStatus = m_Pkt(Index)
End Property

Public Property Let PacketStatus(ByVal Index As Long, ByVal newval As PacketStatusConstants)
    If m_Pkt(Index) = newval Then Exit Property

    Dim PktSize As Long
    PktSize = GetPacketSize(Index)

    Select Case m_Pkt(Index)
    Case pktQueued
        If newval = pktTransferring Then
            m_TransferringPackets = m_TransferringPackets + 1
            m_TransferringSize = m_TransferringSize + PktSize
        Else        ' pktTransferred
            m_TransferredPackets = m_TransferredPackets + 1
            m_TransferredSize = m_TransferredSize + PktSize
        End If
    Case pktTransferring
        m_TransferringPackets = m_TransferringPackets - 1
        m_TransferringSize = m_TransferringSize - PktSize
        If newval = pktTransferred Then
            m_TransferredPackets = m_TransferredPackets + 1
            m_TransferredSize = m_TransferredSize + PktSize
        End If
    Case pktTransferred
        m_TransferredPackets = m_TransferredPackets - 1
        m_TransferredSize = m_TransferredSize - PktSize
        If newval = pktTransferring Then
            m_TransferringPackets = m_TransferringPackets + 1
            m_TransferringSize = m_TransferringSize + PktSize
        End If
    End Select

    m_Pkt(Index) = newval

    If m_TransferredPackets = m_Packets Then
        m_Status = pktTransferred
        If m_DeleteWhenTransferred Then
            Kill m_Path
        End If
    ElseIf m_TransferredPackets = 0 Then
        m_Status = pktQueued
    Else
        m_Status = pktTransferring
    End If
End Property

Public Property Get Status() As PacketStatusConstants
    Status = m_Status
End Property

Public Property Let Status(ByVal newval As PacketStatusConstants)
    m_Status = newval
End Property

Public Property Get Path() As String
    Path = m_Path
End Property

Public Property Let Path(ByVal newval As String)
    m_Path = newval
End Property

Public Property Get File() As VBIOExt.BinaryFile
    Set File = m_File
End Property

Public Property Get DeleteWhenTransferred() As Boolean
    DeleteWhenTransferred = m_DeleteWhenTransferred
End Property

Public Property Let DeleteWhenTransferred(ByVal newval As Boolean)
    m_DeleteWhenTransferred = newval
End Property

Public Property Get DeleteWhenCanceled() As Boolean
    DeleteWhenCanceled = m_DeleteWhenCanceled
End Property

Public Property Let DeleteWhenCanceled(ByVal newval As Boolean)
    m_DeleteWhenCanceled = newval
End Property

Public Sub Cancel()
    If m_DeleteWhenCanceled Then
        Set m_File = Nothing
        Kill m_Path
    End If
End Sub

Public Sub Init(Optional ByVal Size As Long = -1, Optional ByVal PacketSize As Long = -1)
    If Size < 0 Then
        Assert FSO.FileExists(m_Path), "Can't determine file size, the file isn't existed", LOCATION
        Size = FSO.GetFile(m_Path).Size
    End If
    If PacketSize < 0 Then
        PacketSize = Constants.DEFAULT_PKTSIZE
    End If
    ' Assert Size >= 0 And PacketSize > 0, "Invalid arguments", LOCATION

    m_Size = Size
    m_PacketSize = PacketSize

    Dim Packets As Long
    Packets = Int(Size / PacketSize)
    If Size Mod PacketSize Then Packets = Packets + 1

    ReDim m_Pkt(-1 To Packets - 1)
    ReDim m_PktChecksum(-1 To Packets - 1)

    m_Packets = Packets
End Sub

' Returns -1 if not more packet in the queue.
Public Property Get NextPacketInQueue() As Long
    Dim i As Long
    For i = 0 To m_Packets - 1
        If m_Pkt(i) = pktQueued Then
            NextPacketInQueue = i
            Exit Property
        End If
    Next
    NextPacketInQueue = -1
    Exit Property
End Property

Public Property Get TransferredRatio() As Single
    If m_Packets = 0 Then TransferredRatio = 1: Exit Property
    TransferredRatio = m_TransferredPackets / m_Packets
End Property

Public Property Get TransferredRatioOfBytes() As Single
    If m_Size = 0 Then TransferredRatioOfBytes = 1: Exit Property
    TransferredRatioOfBytes = m_TransferredSize / m_Size
End Property

Public Function GetPacketSize(ByVal PacketIndex As Long) As Long
    Assert PacketIndex >= 0 And PacketIndex < m_Packets

    If PacketIndex = m_Packets - 1 Then
        GetPacketSize = m_Size Mod m_PacketSize
    Else
        GetPacketSize = m_PacketSize
    End If
End Function

Public Function GetPacketString(ByVal PacketIndex As Long, _
                                Optional ByVal RawMode As Boolean = False) As String
    Assert PacketIndex >= 0 And PacketIndex < m_Packets

    Dim PacketSize As Long
    PacketSize = GetPacketSize(PacketIndex)

    m_File.Open_ m_Path, amRead
    m_File.SetCurrentPosition m_PacketSize * PacketIndex, prBegin
    If RawMode Then
        GetPacketString = m_File.ReadStringB(Int(PacketSize / 2))
    Else
        GetPacketString = m_File.ReadString(PacketSize)
    End If
    m_File.Close_
End Function

Public Function GetPacketData(ByVal PacketIndex As Long) As Byte()
    Assert PacketIndex >= 0 And PacketIndex < m_Packets

    Dim PacketSize As Long
    PacketSize = GetPacketSize(PacketIndex)

    ' XXX  if failed...
    m_File.Open_ m_Path, amRead

    m_File.SetCurrentPosition m_PacketSize * PacketIndex, prBegin

    GetPacketData = m_File.Read(PacketSize)

    m_File.Close_
End Function

' Returns False if "Packet Checksum Error"
Public Function PutPacket(ByVal PacketIndex As Long, ByVal PacketData As Variant, _
                          Optional ByVal RawMode As Boolean = False) As Long
    Assert PacketIndex >= 0 And PacketIndex < m_Packets
    PutPacket = ERR_OK
'
'    If m_PktChecksum(PacketIndex) <> 0 Then
'        Dim chk As Long
'        chk = CalcChecksum(PacketData)
'        If chk <> m_PktChecksum(PacketIndex) Then
'            PutPacket = ERR_PFK_CHECKSUM
'            Exit Function
'        End If
'    End If

    Dim PacketSize As Long
    If PacketIndex = m_Packets - 1 Then
        PacketSize = m_Size Mod m_PacketSize
    Else
        PacketSize = m_PacketSize
    End If

    If Not m_File.Open_(m_Path, amWrite) Then
        PutPacket = ERR_PFK_OPEN_FILE
        Exit Function
    End If

    ' Truncate or Extend the file, if file isn't existed, create then.
    If m_File.Size <> m_Size Then m_File.Size = m_Size

    m_File.SetCurrentPosition m_PacketSize * PacketIndex, prBegin

    Dim ret As Boolean

    Select Case VarType(PacketData)
    Case vbString
        If RawMode Then
            ret = m_File.WriteStringB(PacketData, PacketSize)
        Else
            ret = m_File.WriteString(PacketData, PacketSize)
        End If
    Case vbByte + vbArray
        Dim b() As Byte
        b = PacketData
        ret = m_File.Write_(b, PacketSize)
    End Select

    If Not ret Then PutPacket = ERR_PFK_WRITE_FILE

    m_File.Close_

    PacketStatus(PacketIndex) = pktTransferred
End Function

Public Function Hash() As String
    If Not FSO.FileExists(Path) Then Exit Function

    Dim h As New XceedEncryptionLib.XceedHashing
    Dim sha1 As New XceedEncryptionLib.XceedSHAHashingMethod
    h.License LICENSE_XC_ENCRYPT

    Set h.HashingMethod = sha1

    h.Hash FILEHASH_PREFIX, False

    Dim fs As Long
    Dim r As Long
    Dim bl As Long
    Dim l As Long
    Dim cb As Long
    fs = FSO.GetFile(Path).Size
    r = fs
    While r > 0
        bl = r Mod HASHBLOCK
        If bl = 0 Then bl = HASHBLOCK
        r = r - bl
        cb = h.ReadFile(Path, l, bl, efpHash, False)
        l = l + bl
        If cb <> bl Then
            RaiseEvent OnError(ERR_HASH_READFILE, "Read " & cb & " bytes, " _
                                                & "while expected " & bl & " bytes")
            Exit Function
        End If
        RaiseEvent OnHashing(l)
    Wend

    h.Hash FILEHASH_SUFFIX, True

    Hash = Replace(StringToBase64(sha1.HashValue, True), " ", "")
End Function

Private Sub Class_Initialize()
    m_GUID = ":" & G.NextUniqueId
    Set m_File = New BinaryFile
    m_File.CreateDirectoryStructure = True
End Sub
