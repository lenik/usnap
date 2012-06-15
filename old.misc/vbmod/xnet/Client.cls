VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Client"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::Client"

Private m_Driver As ISocketDriver
Private m_ClientSocket As IClientSocket
Private m_Connected As Boolean
Private m_Buffer As New Buffer

Private WithEvents m_Connection As Connection
Attribute m_Connection.VB_VarHelpID = -1

' Base Events
' ----------------------------------------------------------------------------
Public Event OnConnect(ByRef SecurityEnabled As Boolean)
Public Event OnDisconnect(ByVal Reason As DisconnectReasonConstants)

Public Event OnPreSendPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnSentPacket(ByVal Pkt As Packet)
Public Event OnPreRecvPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnRecvPacket(ByVal Pkt As Packet)
Public Event OnUnknownPacket(ByVal Pkt As Packet)

Public Event OnPreReceiveFile(ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnReceivingFile(ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnReceivingFileError(ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)
Public Event OnReceivedFile(ByVal f As Xnet.File)

Public Event OnSendingFile(ByVal f As Xnet.File, ByRef Cancel As Boolean)
Public Event OnSendingFileError(ByVal f As Xnet.File, ByVal ErrId As Long, ByRef Cancel As Boolean)
Public Event OnSentFile(ByVal f As Xnet.File)

Public Event OnFileHashing(ByVal f As Xnet.File, ByVal ProcessedSize As Long)
Public Event OnFileCanceled(ByVal f As Xnet.File)

' Protocol Events
' ----------------------------------------------------------------------------

' Register-ID is LocalAddress/Port
Public Event OnRegistered()
Public Event OnUnregistered()

Public Event OnSetName(ByVal PeerName As String)
Public Event OnSetKey()
Public Event OnSetSharedKey()
Public Event OnTouch()
Public Event OnMessage(ByVal Message As String)
Public Event OnSystem(ByVal Pkt As Packet)
Public Event OnGet(ByVal URI As String, ByRef Response As String)

Implements IClientEvents

' Exported
' ----------------------------------------------------------------------------
Public Property Get Connection() As Connection
    Set Connection = m_Connection
End Property

Private Sub BreakConnection()
    ' Break the connection-eventsink at first.
    ' so incoming messages happens in disconnecting period will be ignored.
    m_Connected = False

    ' When m_Connected set to false, no access to m_Connection
    Set m_Connection = Nothing
End Sub

Public Sub Disconnect()
    ' Assert m_Connected, "Already disconnected. ", LOCATION
    If Not m_Connected Then Exit Sub

    BreakConnection

    m_ClientSocket.Disconnect
End Sub

Public Property Get Name() As String
    Name = m_Connection.Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Connection.Name = newval
End Property

' Friend API
' ----------------------------------------------------------------------------
Friend Property Set Driver(ByVal newval As ISocketDriver)
    Set m_Driver = newval
End Property

' see m_Driver.LastError if connect failed
Friend Function Connect(ByVal RemoteAddress As String) As Boolean
    Assert Not m_Driver Is Nothing, "Not Initialized", LOCATION

    Assert Not m_Connected, "Already connected.  " & vbNewLine _
                          & "The connect method should only be called by Driver.", LOCATION

    Dim ClientChannel As ClientChannel
    Dim SecurityEnabled As Boolean

    Set m_ClientSocket = m_Driver.Connect(RemoteAddress, Me)

    ' Cannot create the socket
    If m_ClientSocket Is Nothing Then Exit Function

    Set m_Connection = New Connection
    Set ClientChannel = New ClientChannel
    ClientChannel.Init m_ClientSocket
    Set m_Connection.Channel = ClientChannel

    m_Connection.Address = m_ClientSocket.LocalAddress
    m_Connection.PeerAddress = RemoteAddress

    ' The m_Connection now ready to receive messages.
    m_Connected = True

    SecurityEnabled = True
    RaiseEvent OnConnect(SecurityEnabled)

    ' Initial commands
    m_Connection.Register           ' Designed For UDP protocol
    m_Connection.SetName

    If SecurityEnabled Then
        m_Connection.SetKey
        ' SetSharedKey after setkey replied.
        ' m_Connection.SetSharedKey
    End If

    m_Connection.SendTouch

    Connect = True
End Function

Private Sub m_Connection_OnPreSendPacket(ByVal Pkt As Packet, Cancel As Boolean)
    RaiseEvent OnPreSendPacket(Pkt, Cancel)
End Sub

Private Sub m_Connection_OnSendingFileError(ByVal f As Xnet.File, ByVal ErrId As Long, Cancel As Boolean)
    RaiseEvent OnSendingFileError(f, ErrId, Cancel)
End Sub

Private Sub m_Connection_OnSentPacket(ByVal Pkt As Packet)
    RaiseEvent OnSentPacket(Pkt)
End Sub

Private Sub m_Connection_OnUnknownPacket(ByVal Pkt As Packet)
    RaiseEvent OnUnknownPacket(Pkt)
End Sub

Private Sub m_Connection_OnPreReceiveFile(ByVal f As Xnet.File, Cancel As Boolean)
    RaiseEvent OnPreReceiveFile(f, Cancel)
End Sub

Private Sub m_Connection_OnReceivingFile(ByVal f As Xnet.File, Cancel As Boolean)
    RaiseEvent OnReceivingFile(f, Cancel)
End Sub

Private Sub m_Connection_OnReceivingFileError(ByVal f As Xnet.File, ByVal ErrId As Long, Cancel As Boolean)
    RaiseEvent OnReceivingFileError(f, ErrId, Cancel)
End Sub

Private Sub m_Connection_OnReceivedFile(ByVal f As Xnet.File)
    RaiseEvent OnReceivedFile(f)
End Sub

Private Sub m_Connection_OnSendingFile(ByVal f As Xnet.File, Cancel As Boolean)
    RaiseEvent OnSendingFile(f, Cancel)
End Sub

Private Sub m_Connection_OnSentFile(ByVal f As Xnet.File)
    RaiseEvent OnSentFile(f)
End Sub

Private Sub m_Connection_OnFileHashing(ByVal f As Xnet.File, ByVal ProcessedSize As Long)
    RaiseEvent OnFileHashing(f, ProcessedSize)
End Sub

Private Sub m_Connection_OnFileCanceled(ByVal f As Xnet.File)
    RaiseEvent OnFileCanceled(f)
End Sub

' IClientEvents
' ----------------------------------------------------------------------------
Private Sub IClientEvents_Disconnect(ByVal Reason As DisconnectReasonConstants)
    If Not m_Connected Then Exit Sub

    ' May be closed by remote
    BreakConnection
    RaiseEvent OnDisconnect(Reason)
End Sub

Private Sub PreProcess(ByVal Pkt As Packet, ByRef Cancel As Boolean)
    ' Do Nothing.
End Sub

Private Sub PostProcess(ByVal Pkt As Packet, ByRef Cancel As Boolean)
    Select Case Pkt.Name
    Case NC_REGISTER
        Assert Not Pkt.Initiative
        RaiseEvent OnRegistered
    Case NC_UNREGISTER
        Assert Not Pkt.Initiative
        RaiseEvent OnUnregistered
    Case NC_SETNAME
        RaiseEvent OnSetName(m_Connection.PeerName)
    Case NC_SETKEY
        RaiseEvent OnSetKey
    Case NC_SETSHAREDKEY
        RaiseEvent OnSetSharedKey
    Case NC_TOUCH
        RaiseEvent OnTouch
    Case NC_MESSAGE
        RaiseEvent OnMessage(Pkt.XArg(0))
    Case NC_SYSTEM
        RaiseEvent OnSystem(Pkt)
    End Select
End Sub

Private Sub IClientEvents_RecvBytes(Bytes() As Byte, UnrecvBytes As Long)
    If Not m_Connected Then Exit Sub

    Dim Pkt As Packet
    Dim Cancel As Boolean

    m_Buffer.AddBytes Bytes
    While m_Buffer.PacketReady
        Set Pkt = m_Buffer.NextPacket

        Cancel = False
        RaiseEvent OnPreRecvPacket(Pkt, Cancel)
        If Not Cancel Then
            PreProcess Pkt, Cancel
            If Not Cancel Then
                ' Though m_Connected=false will break the connection
                ' But incoming data when disconnecting is still possible.
                If m_Connection Is Nothing Then Exit Sub

                m_Connection.RecvPacket Pkt
                PostProcess Pkt, Cancel
                If Not Cancel Then
                    RaiseEvent OnRecvPacket(Pkt)
                End If
            End If
        End If
    Wend
End Sub

Private Sub IClientEvents_SentBytes(ByVal Size As Long, _
                                    ByVal PartialId As Long, _
                                    ByVal PartialOffset As Long, _
                                    ByVal PartialRemain As Long)
    ' The Xnet protocol is designed for support UDP small packets,
    ' so this progress info is not used.
End Sub

' Class
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
End Sub

Private Sub Class_Terminate()
    If m_Connected Then
        Disconnect
        m_Connected = False
    End If
End Sub
