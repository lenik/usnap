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

Private WithEvents m_Connection As Connection
Attribute m_Connection.VB_VarHelpID = -1

Public Event OnPreSendCommand(ByVal c As Command, ByRef Cancel As Boolean)
Public Event OnPreRecvCommand(ByVal c As Command, ByRef Cancel As Boolean)

Public Event OnSentCommand(ByVal c As Command)
Public Event OnRecvCommand(ByVal c As Command)

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
Public Event OnSystemCommand(ByVal c As Command)
Public Event OnGet(ByVal URI As String, ByRef Response As String)

Public Property Get Socket() As Socket
    Set Socket = m_Connection.Socket
End Property

Public Property Get LocalIP() As String
    LocalIP = Socket.LocalIP
End Property

Public Property Let LocalIP(ByVal newval As String)
    Assert False, "Not supported", LOCATION
    'Socket.LocalIP = newval
End Property

Public Property Get LocalPort() As Long
    LocalPort = Socket.LocalPort
End Property

Public Property Let LocalPort(ByVal newval As Long)
    Socket.LocalPort = newval
End Property

Public Property Get RemoteHost() As String
    RemoteHost = Socket.RemoteHost
End Property

Public Property Get RemoteHostIP() As String
    RemoteHostIP = Socket.RemoteHostIP
End Property

Public Property Get RemotePort() As Long
    RemotePort = Socket.RemotePort
End Property

Public Property Get User()
    If IsObject(Socket.User) Then
        Set User = Socket.User
    Else
        User = Socket.User
    End If
End Property

Public Property Let User(ByVal newval)
    Socket.User = newval
End Property

Public Property Set User(ByVal newval)
    Set Socket.User = newval
End Property

Public Property Get Tag() As String
    Tag = Socket.Tag
End Property

Public Property Let Tag(ByVal newval As String)
    Socket.Tag = newval
End Property

Private Sub Class_Initialize()
    Set m_Connection = New Connection
End Sub

Private Sub m_Connection_OnPreSendCommand(ByVal c As Command, Cancel As Boolean)
    RaiseEvent OnPreSendCommand(c, Cancel)
End Sub

Private Sub m_Connection_OnRecvCommand(ByVal c As Command)
    RaiseEvent OnRecvCommand(c)

    Select Case c.Name
    Case NC_REGISTER                    ' Returned
        RaiseEvent OnRegistered
    Case NC_UNREGISTER                  ' Returned
        RaiseEvent OnUnregistered
    Case NC_SETNAME
        RaiseEvent OnSetName(c.Parameter(1))
    Case NC_SETKEY
        RaiseEvent OnSetKey
    Case NC_SETSESSIONKEY
        RaiseEvent OnSetSessionKey
    Case NC_TOUCH
        RaiseEvent OnTouch
    Case NC_MESSAGE
        RaiseEvent OnMessage(c.Parameter(1))
    Case NC_FILEINFO                    ' Returned
        '
    Case NC_FILEPACKET
        '
    Case NC_SYSTEM
        RaiseEvent OnSystemCommand(c)
    Case Else
        'RaiseEvent OnUnknownCommand(c)
    End Select
End Sub

Private Sub m_Connection_OnPreRecvCommand(ByVal c As Command, Cancel As Boolean)
    RaiseEvent OnPreRecvCommand(c, Cancel)
End Sub

Private Sub m_Connection_OnSentCommand(ByVal c As Command)
    RaiseEvent OnSentCommand(c)
End Sub
