VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TCPClientSocket"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "XnetXceed::TCPClientSocket"

Private xSocket As XceedWinsockLib.ConnectionOrientedSocket
Private WithEvents xConn As XceedWinsockLib.ConnectionEvents
Attribute xConn.VB_VarHelpID = -1
Private WithEvents xByte As XceedWinsockLib.ByteTransferEvents
Attribute xByte.VB_VarHelpID = -1
Private lConn As Long
Private lByte As Long

Private m_EventSink As IClientEvents
Private m_UnrecvBuffer As New ByteArray
Private m_SendOffset As Long
Private m_SentOffset As Long
Private m_RecvOffset As Long            ' Not include unrecved bytes
Private m_PartialStack As New Vector

Implements IClientSocket

' Friend API
' ----------------------------------------------------------------------------
Property Get Socket() As ConnectionOrientedSocket
    Set Socket = xSocket
End Property

Property Set Socket(ByVal newval As ConnectionOrientedSocket)
    Set xSocket = newval
End Property

Property Get RemoteAddress() As XceedWinsockLib.Address
    Set RemoteAddress = xSocket.RemoteAddress
End Property

Property Get LocalAddress() As XceedWinsockLib.Address
    Set LocalAddress = xSocket.LocalAddress
End Property

' IClientSocket Implementation
' ----------------------------------------------------------------------------
Private Function IClientSocket_Advise(ByVal EventSink As Xnet.IClientEvents) As Long
    Set m_EventSink = EventSink
End Function

Private Sub IClientSocket_Unadvise(Optional ByVal Cookie As Long = -1&)
    Set m_EventSink = Nothing
End Sub

Private Property Get IClientSocket_LocalAddress() As String
    IClientSocket_LocalAddress = Addr2Str(LocalAddress)
End Property

Private Property Get IClientSocket_RemoteAddress() As String
    IClientSocket_RemoteAddress = Addr2Str(RemoteAddress)
End Property

Private Sub IClientSocket_Connect(ByVal RemoteAddress As String, _
                                  Optional ByVal LocalAddress As String)
    Dim inaddr As New InetAddress
    If LocalAddress <> "" Then
        Set xSocket.LocalAddress = Str2Inaddr(LocalAddress)
    End If

    Set inaddr = Str2Inaddr(RemoteAddress)
    xSocket.Connect inaddr
End Sub

Private Sub IClientSocket_Disconnect()
    xSocket.Disconnect
End Sub

' XXX: synchronized
Private Sub IClientSocket_SendBytes(Bytes() As Byte, _
                                    Optional ByVal Offset As Long = 0&, _
                                    Optional ByVal Size As Long = -1&, _
                                    Optional ByVal PartialId As Long = -1&, _
                                    Optional ByVal Async As Boolean = False)
    If PartialId <> -1 Then
        Dim LastPartial As New Partial
        LastPartial.Id = PartialId
        LastPartial.Start = m_SendOffset
        m_PartialStack.Push LastPartial
    End If

    Assert Offset >= 0 And Offset <= UBound(Bytes)
    If Size = -1 Then Size = UBound(Bytes) + 1
    If Size = 0 Then Exit Sub

    If Offset > 0 Or Size > UBound(Bytes) + 1 Then
        ReDim Truncated(0 To Size - 1) As Byte
        bytscpy Truncated, 0, Bytes, Offset, Size
        If Async Then
            xSocket.AsyncSendBytes Truncated, 0, wsoNone
        Else
            xSocket.SendBytes Truncated, wsoNone
        End If
    Else
        If Async Then
            xSocket.AsyncSendBytes Bytes, 0, wsoNone
        Else
            xSocket.SendBytes Bytes, wsoNone
        End If
    End If

    m_SendOffset = m_SendOffset + Size
End Sub

Private Property Get IClientSocket_SentBytes() As Long
    IClientSocket_SentBytes = m_SentOffset
End Property

Private Property Get IClientSocket_UnsentBytes() As Long
    IClientSocket_UnsentBytes = m_SendOffset - m_SentOffset
End Property

' XXX: synchronized
Private Sub IClientSocket_ForgetSent()
    ' XXX
    Dim Part As Partial
    Dim i As Long
    For i = 0 To m_PartialStack.Size - 1
        Set Part = m_PartialStack.Item(i)
        Part.Start = Part.Start - m_SentOffset
    Next
    m_SendOffset = m_SendOffset - m_SentOffset
    m_SentOffset = 0
End Sub

Private Property Get IClientSocket_RecvBytes() As Long
    IClientSocket_RecvBytes = m_RecvOffset
End Property

' Client/xCOS Events Impl.
'   Adapter to IClientSocket
' ----------------------------------------------------------------------------
Private Sub xByte_OnBytesReceived(ByVal xSocket As Object, _
                                  ByVal vaData As Variant, _
                                  ByVal lUserParam As Long, _
                                  ByVal lResultCode As Long)
    Dim b() As Byte
    b = vaData

    Dim ConcatUnrecv As Boolean
    If Not m_UnrecvBuffer Is Nothing Then
        If m_UnrecvBuffer.Length > 0 Then
            ConcatUnrecv = True
        End If
    End If

    If LBound(b) <> 0 Or ConcatUnrecv Then
        Dim bb As New ByteArray
        If Not m_UnrecvBuffer Is Nothing Then
            bb.Append m_UnrecvBuffer.Raw
            Set m_UnrecvBuffer = Nothing
        End If
        bb.Append b
        b = bb.Raw
    End If

    Dim RecvBytes As Long
    Dim UnrecvBytes As Long
    RecvBytes = UBound(b) + 1

    m_EventSink.RecvBytes b, UnrecvBytes

    Assert UnrecvBytes >= 0 And UnrecvBytes <= RecvBytes
    If UnrecvBytes > 0 Then
        RecvBytes = RecvBytes - UnrecvBytes
        m_UnrecvBuffer = New ByteArray
        m_UnrecvBuffer.Append b, RecvBytes
    End If

    m_RecvOffset = m_RecvOffset + RecvBytes
End Sub

' XXX: synchronized
Private Sub xByte_OnBytesSent(ByVal xSocket As Object, _
                              ByVal lBytesSent As Long, _
                              ByVal lUserParam As Long, _
                              ByVal lResultCode As Long)
    While lBytesSent > 0
        If m_PartialStack.Size = 0 Then
            m_SentOffset = m_SentOffset + lBytesSent
            m_EventSink.SentBytes lBytesSent, -1, -1, -1
            lBytesSent = 0
        Else
            Dim Part1 As Partial
            Set Part1 = m_PartialStack.Item(0)
            '                   Part1
            '                   |             Part2
            '   ................|.............|..............
            ' 1.     ....Sent...>
            ' 2.              <. ..Sent....
            ' 3.                <...Sent....
            ' 3.2.              <...Sent...... .>
            Dim l As Long
            l = m_SentOffset + lBytesSent
            If l <= Part1.Start Then                ' .1
                m_SentOffset = m_SentOffset + lBytesSent
                m_EventSink.SentBytes lBytesSent, -1, -1, Part1.Start - l
                lBytesSent = 0
            ElseIf m_SentOffset < Part1.Start Then  ' .2
                Dim Before As Long
                Before = Part1.Start - l

                m_SentOffset = m_SentOffset + Before
                m_EventSink.SentBytes Before, -1, -1, 0
                lBytesSent = lBytesSent - Before

                ' Transfer remains to .3
            Else                                    ' .3
                Dim ExceedPart1 As Boolean
                Dim Part2 As Partial

                If m_PartialStack.Size > 1 Then
                    Set Part2 = m_PartialStack.Item(1)
                    If l > Part2.Start Then
                        ExceedPart1 = True
                    End If
                End If

                If Not ExceedPart1 Then
                    m_SentOffset = m_SentOffset + lBytesSent
                    m_EventSink.SentBytes lBytesSent, Part1.Id, _
                                          m_SentOffset - Part1.Start, -1
                    lBytesSent = 0
                Else                                ' .3.2
                    Dim Part1Remains As Long
                    Part1Remains = Part2.Start - m_SentOffset

                    m_SentOffset = m_SentOffset + Part1Remains
                    m_EventSink.SentBytes Part1Remains, Part1.Id, _
                                          m_SentOffset - Part1.Start, 0
                    lBytesSent = lBytesSent - Part1Remains

                    ' Part1 Completed.
                    m_PartialStack.Pop
                End If
            End If
        End If
    Wend
End Sub

Private Sub xConn_OnDisconnected(ByVal xSocket As Object, _
                                 ByVal vaCallerData As Variant, _
                                 vaCalleeData As Variant)
    m_EventSink.Disconnect drClosed
End Sub

' Class
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
    Set xSocket = SocketFactory.CreateConnectionOrientedSocket(G.IP_TCP, 0)
    Set xConn = New XceedWinsockLib.ConnectionEvents
    Set xByte = New XceedWinsockLib.ByteTransferEvents
    lConn = xSocket.ConnectionAdvise(xConn, _
        wcaAdviseDisconnected)
    lByte = xSocket.ByteTransferAdvise(xByte, _
        wtaAdviseReceivedAlways + wtaAdviseSent)
End Sub

Private Sub Class_Terminate()
    xSocket.ConnectionUnadvise lConn
    xSocket.ByteTransferUnadvise lByte
End Sub
