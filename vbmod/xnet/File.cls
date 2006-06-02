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

Public Enum PacketStatusConstants
    pktQueued = 0
    pktTransferring
    pktTransferred
End Enum

Private m_GUID As String
Private m_Size As Long
Private m_PacketSize As Long
Private m_Checksum As String
Private m_FullName As String

Private m_Packets As Long
Private m_TransferredPackets As Long
Private m_Pkt() As PacketStatusConstants
Private m_PktChecksum() As Long

Private m_Path As String
Private m_File As New BinaryFile

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

Public Property Get TransferredPackets() As Long
    TransferredPackets = m_TransferredPackets
End Property

Public Property Get PacketStatus(ByVal Index As Long) As PacketStatusConstants
    PacketStatus = m_Pkt(Index)
End Property

Public Property Let PacketStatus(ByVal Index As Long, ByVal newval As PacketStatusConstants)
    m_Pkt(Index) = newval
End Property

Public Property Get Path() As String
    Path = m_Path
End Property

Public Property Let Path(ByVal newval As String)
    m_Path = newval
End Property

Public Sub Init(ByVal Size As Long, Optional ByVal PacketSize As Long = DEFAULT_PKTSIZE)
    ' Assert Size >= 0 And PacketSize > 0
    m_Size = Size
    m_PacketSize = PacketSize

    Dim Packets As Long
    Packets = Int(Size / PacketSize)
    If Size Mod PacketSize Then Packets = Packets + 1

    ReDim m_Pkt(-1 To Packets - 1)
    ReDim m_PktChecksum(-1 To Packets - 1)

    m_Packets = Packets

    ' Truncate or Extend the file, if file isn't existed, create then.
    m_File.Size = Size
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
    If m_Packets = 0 Then Exit Property
    TransferredRatio = m_TransferredPackets / m_Packets
End Property

Public Function GetPacketString(ByVal PacketIndex As Long, _
                                Optional ByVal RawMode As Boolean = False) As String
    Assert PacketIndex >= 0 And PacketIndex < m_Packets

    Dim PacketSize As Long
    If PacketIndex = m_Packets - 1 Then
        PacketSize = m_Size Mod m_PacketSize
    Else
        PacketSize = m_PacketSize
    End If

    m_File.Open_ m_Path, amRead
    m_File.SetCurrentPosition m_PacketSize * PacketIndex, prBegin
    If RawMode Then
        GetPacketString = m_File.ReadStringB(Int(PacketSize / 2))
    Else
        GetPacketString = m_File.ReadString(PacketSize)
    End If
    m_File.Close_
End Function

Public Function GetPacketData(ByVal PacketIndex As Long, _
                              Optional ByVal RawMode As Boolean = False)
    Assert PacketIndex >= 0 And PacketIndex < m_Packets

    Dim PacketSize As Long
    If PacketIndex = m_Packets - 1 Then
        PacketSize = m_Size Mod m_PacketSize
    Else
        PacketSize = m_PacketSize
    End If

    m_File.Open_ m_Path, amRead
    m_File.SetCurrentPosition m_PacketSize * PacketIndex, prBegin

    GetPacketData = m_File.Read(PacketSize)

    m_File.Close_
End Function

' Returns False if "Packet Checksum Error"
Public Function PutPacket(ByVal PacketIndex As Long, PacketData, _
                          Optional ByVal RawMode As Boolean = False) As Boolean
    Assert PacketIndex >= 0 And PacketIndex < m_Packets

    Dim chk As Long
    ' TODO  calculate the packet checksum -> chk.
    If chk <> m_PktChecksum(PacketIndex) Then
        PutPacket = False
        Exit Function
    End If

    Dim PacketSize As Long
    If PacketIndex = m_Packets - 1 Then
        PacketSize = m_Size Mod m_PacketSize
    Else
        PacketSize = m_PacketSize
    End If

    m_File.Open_ m_Path, amWrite
    m_File.SetCurrentPosition m_PacketSize * PacketIndex, prBegin

    Select Case VarType(PacketData)
    Case vbString
        If RawMode Then
            m_File.WriteStringB PacketData, PacketSize
        Else
            m_File.WriteString PacketData, PacketSize
        End If
    Case vbByte + vbArray
        m_File.Write_ PacketData, PacketSize
    End Select

    m_File.Close_

    m_Pkt(PacketIndex) = pktTransferred
    m_TransferredPackets = m_TransferredPackets + 1

    PutPacket = True
End Function

Public Property Get RealFileChecksum() As String
    ' TODO  get checksum by xceed..?
    ' ...
End Property
