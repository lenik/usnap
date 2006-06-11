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

Private m_Connection As Connection
Attribute m_Connection.VB_VarHelpID = -1

Public Event OnConnect()
Public Event OnDisconnect(ByVal Reason As DisconnectReasonConstants)

Public Event OnPreSendPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)
Public Event OnPreRecvPacket(ByVal Pkt As Packet, ByRef Cancel As Boolean)

Public Event OnSentPacket(ByVal Pkt As Packet)
Public Event OnRecvPacket(ByVal Pkt As Packet)

' Register-ID is LocalAddress/Port
Public Event OnRegistered()
Public Event OnUnregistered()

Public Event OnSetName(ByVal PeerName As String)
Public Event OnSetKey()
Public Event OnSetSessionKey()
Public Event OnTouch()
Public Event OnMessage(ByVal Message As String)
Public Event OnSendProgress(ByVal SentStart As Long, ByVal SentBytes As Long, ByVal TotalBytes As Long)
Public Event OnSendComplete()
Public Event OnSystemCommand(ByVal Pkt As Packet)
Public Event OnGet(ByVal URI As String, ByRef Response As String)

Public Event OnCanceled(ByVal File As File)

Implements IClientEvents

' Friend API
' ----------------------------------------------------------------------------
Property Set Driver(ByVal newval As ISocketDriver)
    Set m_Driver = newval
End Property

Function Connect(ByVal RemoteAddress As String) As Boolean
    Assert Not m_Driver Is Nothing, "Not Initialized", LOCATION

    Set m_ClientSocket = m_Driver.Connect(RemoteAddress, Me)
    Connect = Not m_ClientSocket Is Nothing
    If Connect Then
        Set m_Connection = New Connection
        Dim ClientChannel As New ClientChannel
        ClientChannel.Init m_ClientSocket
        Set m_Connection.Channel = ClientChannel
    End If
End Function

' Class
' ----------------------------------------------------------------------------
Public Property Get Connection() As Connection
    Set Connection = m_Connection
End Property

Private Sub m_Connection_OnRecvPacket(ByVal Pkt As Packet)
    RaiseEvent OnRecvPacket(Pkt)

    Select Case Pkt.Name
    Case NC_REGISTER                    ' Returned
        RaiseEvent OnRegistered
    Case NC_UNREGISTER                  ' Returned
        RaiseEvent OnUnregistered
    Case NC_SETNAME
        RaiseEvent OnSetName(Pkt.Arg(1))
    Case NC_SETKEY
        RaiseEvent OnSetKey
    Case NC_SETSHAREDKEY
        RaiseEvent OnSetSessionKey
    Case NC_TOUCH
        RaiseEvent OnTouch
    Case NC_MESSAGE
        RaiseEvent OnMessage(Pkt.Arg(1))
    Case NC_PUTFILE                     ' Returned
        'RaiseEvent OnPreRecvFile(f, Cancel)
        'If Cancel Then
        '    m_Connection.sendcancel (f.id)
    Case NC_FILEPACKET
        '
    Case NC_SYSTEM
        RaiseEvent OnSystemCommand(Pkt)
    Case Else
        'RaiseEvent OnUnknownPacket(c)
    End Select
End Sub

Private Sub m_Connection_OnPreRecvPacket(ByVal Pkt As Packet, Cancel As Boolean)
    RaiseEvent OnPreRecvPacket(Pkt, Cancel)
End Sub

Private Sub m_Connection_OnSentPacket(ByVal Pkt As Packet)
    RaiseEvent OnSentPacket(Pkt)
End Sub

' IClientEvents
' ----------------------------------------------------------------------------
Private Sub IClientEvents_Connect()
    RaiseEvent OnConnect
    m_Connection.Register
    m_Connection.SetName
    m_Connection.SetKey
    m_Connection.SetSharedKey
    m_Connection.SendTouch
End Sub

Private Sub IClientEvents_Disconnect(ByVal Reason As DisconnectReasonConstants)
    RaiseEvent OnDisconnect(Reason)
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
            m_Connection.RecvPacket Pkt
            RaiseEvent OnRecvPacket(Pkt)
        End If
    Wend
End Sub

Private Sub IClientEvents_SentBytes(ByVal Size As Long, ByVal PartialId As Long, ByVal PartialOffset As Long, ByVal PartialRemain As Long)
    'm_Connection
End Sub

' Class
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
End Sub
