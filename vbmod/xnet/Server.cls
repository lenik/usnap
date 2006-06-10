VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Server"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Xnet::Server"

Private WithEvents m_Connection As Connection
Attribute m_Connection.VB_VarHelpID = -1

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


Public Property Get Connection() As Connection
    Set Connection = m_Connection
End Property

Private Sub Class_Initialize()
    Set m_Connection = New Connection
End Sub

Private Sub m_Connection_OnPreSendPacket(ByVal Pkt As Packet, Cancel As Boolean)
    RaiseEvent OnPreSendPacket(Pkt, Cancel)
End Sub

Private Sub m_Connection_OnRecvPacket(ByVal Pkt As Packet)
    RaiseEvent OnRecvPacket(Pkt)

    Select Case Pkt.Name
    Case NC_REGISTER                    ' Returned
        RaiseEvent OnRegistered
    Case NC_UNREGISTER                  ' Returned
        RaiseEvent OnUnregistered
    Case NC_SETNAME
        RaiseEvent OnSetName(Pkt.Parameter(1))
    Case NC_SETKEY
        RaiseEvent OnSetKey
    Case NC_SETSESSIONKEY
        RaiseEvent OnSetSessionKey
    Case NC_TOUCH
        RaiseEvent OnTouch
    Case NC_MESSAGE
        RaiseEvent OnMessage(Pkt.Parameter(1))
    Case NC_PUTFILE                     ' Returned
        'RaiseEvent OnPreRecvFile(f, Cancel)
        'If Cancel Then
        '    m_Connection.sendcancel (f.id)
    Case NC_CANCEL
        RaiseEvent OnCanceled(Pkt.Parameter(0))
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
