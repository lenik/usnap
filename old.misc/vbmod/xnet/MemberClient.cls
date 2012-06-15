VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MemberClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public xSocket As ConnectionOrientedSocket
Public UserData As Variant

Private m_Id As Long

Private m_UnrecvBuffer As New ByteArray
Private m_SendOffset As Long
Private m_SentOffset As Long
Private m_RecvOffset As Long             ' Not include unrecved bytes
Private m_PartialStack As New Vector

Property Get RemoteAddress() As XceedWinsockLib.Address
    Set RemoteAddress = xSocket.RemoteAddress
End Property

Property Get LocalAddress() As XceedWinsockLib.Address
    Set LocalAddress = xSocket.LocalAddress
End Property

Property Get Id() As Long
    Id = m_Id
End Property

Property Let Id(ByVal newval As Long)
    m_Id = newval
End Property

Sub Disconnect()
    xSocket.Disconnect
End Sub

Property Get SentBytes() As Long
    SentBytes = m_SentOffset
End Property

Property Get UnsentBytes() As Long
    UnsentBytes = m_SendOffset - m_SentOffset
End Property

' XXX: synchronized
Sub ForgetSent()
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

Property Get RecvBytes() As Long
    RecvBytes = m_RecvOffset
End Property

Sub SendBytes(Bytes() As Byte, _
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

Sub xByte_OnBytesReceived(ByVal m_EventSink As IServerEvents, _
                            ByVal xSocket As Object, _
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

    m_EventSink.RecvBytes m_Id, b, UnrecvBytes

    Assert UnrecvBytes >= 0 And UnrecvBytes <= RecvBytes
    If UnrecvBytes > 0 Then
        RecvBytes = RecvBytes - UnrecvBytes
        m_UnrecvBuffer = New ByteArray
        m_UnrecvBuffer.Append b, RecvBytes
    End If

    m_RecvOffset = m_RecvOffset + RecvBytes
End Sub

Sub xByte_OnBytesSent(ByVal m_EventSink As IServerEvents, _
                        ByVal xSocket As Object, _
                        ByVal lBytesSent As Long, _
                        ByVal lUserParam As Long, _
                        ByVal lResultCode As Long)
    While lBytesSent > 0
        If m_PartialStack.Size = 0 Then
            m_SentOffset = m_SentOffset + lBytesSent
            m_EventSink.SentBytes m_Id, lBytesSent, -1, -1, -1
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
                m_EventSink.SentBytes m_Id, lBytesSent, -1, -1, Part1.Start - l
                lBytesSent = 0
            ElseIf m_SentOffset < Part1.Start Then  ' .2
                Dim Before As Long
                Before = Part1.Start - l

                m_SentOffset = m_SentOffset + Before
                m_EventSink.SentBytes m_Id, Before, -1, -1, 0
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
                    m_EventSink.SentBytes m_Id, lBytesSent, Part1.Id, _
                                          m_SentOffset - Part1.Start, -1
                    lBytesSent = 0
                Else                                ' .3.2
                    Dim Part1Remains As Long
                    Part1Remains = Part2.Start - m_SentOffset

                    m_SentOffset = m_SentOffset + Part1Remains
                    m_EventSink.SentBytes m_Id, Part1Remains, Part1.Id, _
                                          m_SentOffset - Part1.Start, 0
                    lBytesSent = lBytesSent - Part1Remains

                    ' Part1 Completed.
                    m_PartialStack.Pop
                End If
            End If
        End If
    Wend
End Sub
