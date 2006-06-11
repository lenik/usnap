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

Public Event OnPreReceiveFile(ByVal f As File, ByRef Cancel As Boolean)
Public Event OnReceivingFile(ByVal f As File, ByRef Cancel As Boolean)
Public Event OnReceivedFile(ByVal f As File)

Public Event OnSendingFile(ByVal f As File)
Public Event OnSentFile(ByVal f As File)

Public Event OnFileCanceled(ByVal f As File, ByVal ReceiveMode As Boolean)

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

' Friend API
' ----------------------------------------------------------------------------
Property Set Driver(ByVal newval As ISocketDriver)
    Set m_Driver = newval
End Property

' see m_Driver.LastError if connect failed
Function Connect(ByVal RemoteAddress As String) As Boolean
    Assert Not m_Driver Is Nothing, "Not Initialized", LOCATION

    Set m_ClientSocket = m_Driver.Connect(RemoteAddress, Me)
    Connect = Not m_ClientSocket Is Nothing

    If Connect Then
        Set m_Connection = New Connection
        Dim ClientChannel As New ClientChannel
        ClientChannel.Init m_ClientSocket
        Set m_Connection.Channel = ClientChannel

        m_Connection.Address = m_ClientSocket.LocalAddress
        m_Connection.PeerAddress = RemoteAddress

        Dim SecurityEnabled As Boolean
        SecurityEnabled = True
        RaiseEvent OnConnect(SecurityEnabled)

        ' Initial commands
        m_Connection.Register           ' Designed For UDP protocol
        m_Connection.SetName

        If SecurityEnabled Then
            m_Connection.SetKey
            m_Connection.SetSharedKey
        End If

        m_Connection.SendTouch
    End If
End Function

Public Property Get Connection() As Connection
    Set Connection = m_Connection
End Property

Private Sub m_Connection_OnPreSendPacket(ByVal Pkt As Packet, Cancel As Boolean)
    RaiseEvent OnPreSendPacket(Pkt, Cancel)
End Sub

Private Sub m_Connection_OnSentPacket(ByVal Pkt As Packet)
    RaiseEvent OnSentPacket(Pkt)
End Sub

' IClientEvents
' ----------------------------------------------------------------------------
Private Sub IClientEvents_Disconnect(ByVal Reason As DisconnectReasonConstants)
    ' Connection.channel.stop??
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
        RaiseEvent OnMessage(Pkt.XArg(1))
    Case NC_SYSTEM
        RaiseEvent OnSystem(Pkt)
    End Select
End Sub

Private Sub IClientEvents_RecvBytes(Bytes() As Byte, UnrecvBytes As Long)
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
    ' m_ClientSocket
End Sub
