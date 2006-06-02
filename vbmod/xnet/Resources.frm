VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "mswinsck.ocx"
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#28.0#0"; "VBUserExt.ocx"
Begin VB.Form Resources
   Caption         =   "Resources"
   ClientHeight    =   4140
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5790
   LinkTopic       =   "Form1"
   ScaleHeight     =   4140
   ScaleWidth      =   5790
   StartUpPosition =   3  'Windows Default
   Begin VB.Timer Refresher
      Interval        =   10
      Left            =   600
      Top             =   60
   End
   Begin VBUserExt.ScrollableContainer Scroll
      Height          =   3555
      Left            =   120
      TabIndex        =   5
      Top             =   480
      Width           =   5535
      _ExtentX        =   9763
      _ExtentY        =   6271
      Begin Xnet.SocketInfo sckinfo
         Height          =   825
         Index           =   0
         Left            =   60
         TabIndex        =   6
         Top             =   0
         Visible         =   0   'False
         Width           =   5205
         _ExtentX        =   9181
         _ExtentY        =   1455
      End
   End
   Begin VB.CommandButton btnAdd
      Caption         =   "+"
      Height          =   315
      Left            =   4980
      TabIndex        =   4
      Top             =   120
      Width           =   315
   End
   Begin MSWinsockLib.Winsock sck
      Index           =   0
      Left            =   60
      Top             =   60
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      Protocol        =   1
   End
   Begin VB.Label Label1
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Label1"
      ForeColor       =   &H80000008&
      Height          =   15
      Left            =   0
      TabIndex        =   7
      Top             =   420
      Width           =   8535
   End
   Begin VB.Label lblFieldName
      Caption         =   "Local Address/Port"
      Height          =   255
      Index           =   4
      Left            =   3120
      TabIndex        =   3
      Top             =   180
      Width           =   1815
   End
   Begin VB.Label lblFieldName
      Caption         =   "Remote Address/Port"
      Height          =   255
      Index           =   2
      Left            =   1260
      TabIndex        =   2
      Top             =   180
      Width           =   1815
   End
   Begin VB.Label lblFieldName
      Caption         =   "Index"
      Height          =   255
      Index           =   1
      Left            =   600
      TabIndex        =   1
      Top             =   180
      Width           =   615
   End
   Begin VB.Label lblFieldName
      Caption         =   "St"
      Height          =   255
      Index           =   0
      Left            =   300
      TabIndex        =   0
      Top             =   180
      Width           =   255
   End
End
Attribute VB_Name = "Resources"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "Xnet::Resources"

Private m_Layout As New AutoScaleLayout

Private WithEvents Core As FastAlgLib.SAOT
Attribute Core.VB_VarHelpID = -1

Private m_OutgoingEvents As New VBExt.Map

Implements SocketEvents

Property Get CoreState() As String
    Dim Slot As Long
    CoreState = "[" & Core.Size & "]"
    For Slot = 0 To Core.SlotAllocated - 1
        CoreState = CoreState & "." & Core.FindSlot(Slot)
    Next
End Property

Function SlotToIndex(ByVal Slot As Long) As Integer
    SlotToIndex = Slot + 1
End Function

Function IndexToSlot(ByVal Index As Integer) As Long
    IndexToSlot = Index - 1
End Function

Function SlotToSeq(ByVal Slot As Long) As Long
    SlotToSeq = Core.FindSlot(Slot)
End Function

Function SeqToSlot(ByVal Seq As Long) As Long
    SeqToSlot = Core.FindIndex(Seq)
End Function

Function SeqToIndex(ByVal Seq As Long) As Integer
    SeqToIndex = SlotToIndex(SeqToSlot(Seq))
End Function

Function IndexToSeq(ByVal Index As Integer) As Long
    IndexToSeq = SlotToSeq(IndexToSlot(Index))
End Function

Private Sub btnAdd_Click()
    AllocSocket Me
End Sub

Private Sub Core_Add(ByVal Slot As Long, ByVal Seq As Long)
    Dim Index As Integer
    Index = SlotToIndex(Slot)
    Load sck(Index)
    Load sckinfo(Index)
    sckinfo(Index).Visible = True
    sckinfo(Index).BindSocket sck(Index)
    Rearrange
End Sub

Private Sub Core_Remove(ByVal Slot As Long, ByVal Seq As Long)
    Dim Index As Integer
    Index = SlotToIndex(Slot)
    Unload sckinfo(Index)
    Unload sck(Index)
    m_OutgoingEvents.Remove Index
    Rearrange
End Sub

Sub Rearrange()
    Dim Seq As Integer
    Dim Index As Integer
    For Seq = 0 To Core.Size - 1
        Index = SeqToIndex(Seq)
        Assert Index >= 1
        If Seq = 0 Then
            sckinfo(Index).Left = sckinfo(0).Left
            sckinfo(Index).Top = sckinfo(0).Top
        Else
            Dim IndexPrev As Integer
            IndexPrev = IIf(Seq = 0, 0, SeqToIndex(Seq - 1))
            Assert IndexPrev >= 0
            sckinfo(Index).Left = sckinfo(IndexPrev).Left
            sckinfo(Index).Top = sckinfo(IndexPrev).Top + sckinfo(IndexPrev).Height + 20
        End If
    Next
    Caption = CoreState
    Scroll.RecalcBounds
End Sub

Private Sub Form_Activate()
    Refresher.Enabled = True
End Sub

Private Sub Form_Deactivate()
    Refresher.Enabled = False
End Sub

Private Sub Form_Load()
    Set Core = New FastAlgLib.SAOT
    m_Layout.InitializeCoordinations Me
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
End Sub

Private Sub Refresher_Timer()
    Dim Seq As Integer
    Dim Index As Integer
    For Seq = 0 To Core.Size - 1
        Index = SeqToIndex(Seq)
        Assert Index >= 1
        sckinfo(Index).Refresh
    Next
End Sub

Private Sub sck_Close(Index As Integer)
    Dim sx As SocketEvents
    Set sx = m_OutgoingEvents.Item(Index)
    Assert Not sx Is Nothing, "Outgoing Event Lost", LOCATION
    sx.OnClose
End Sub

Private Sub sck_Connect(Index As Integer)
    Dim sx As SocketEvents
    Set sx = m_OutgoingEvents.Item(Index)
    Assert Not sx Is Nothing, "Outgoing Event Lost", LOCATION
    sx.OnConnect
End Sub

Private Sub sck_ConnectionRequest(Index As Integer, ByVal requestID As Long)
    Dim sx As SocketEvents
    Set sx = m_OutgoingEvents.Item(Index)
    Assert Not sx Is Nothing
    sx.OnConnectionRequest requestID
End Sub

Private Sub sck_DataArrival(Index As Integer, ByVal bytesTotal As Long)
    Dim sx As SocketEvents
    Set sx = m_OutgoingEvents.Item(Index)
    Assert Not sx Is Nothing, "Outgoing Event Lost", LOCATION
    sx.OnDataArrival bytesTotal
End Sub

Private Sub sck_Error(Index As Integer, ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    Dim sx As SocketEvents
    Set sx = m_OutgoingEvents.Item(Index)
    Assert Not sx Is Nothing
    sx.OnError Number, Description, Scode, Source, HelpFile, HelpContext, CancelDisplay
End Sub

Private Sub sck_SendComplete(Index As Integer)
    Dim sx As SocketEvents
    Set sx = m_OutgoingEvents.Item(Index)
    Assert Not sx Is Nothing, "Outgoing Event Lost", LOCATION
    sx.OnSendComplete
End Sub

Private Sub sck_SendProgress(Index As Integer, ByVal bytesSent As Long, ByVal bytesRemaining As Long)
    Dim sx As SocketEvents
    Set sx = m_OutgoingEvents.Item(Index)
    Assert Not sx Is Nothing, "Outgoing Event Lost", LOCATION
    sx.OnSendProgress bytesSent, bytesRemaining
End Sub

Private Sub sckinfo_OnRemove(Index As Integer)
    Dim Slot As Long
    Dim Seq As Long
    Dim Handle As Long
    Slot = IndexToSlot(Index)
    Seq = SlotToSeq(Slot)
    Handle = Index
    FreeSocket Handle
End Sub

Public Property Get Socket(ByVal Handle As Long) As Winsock
    Dim Index As Integer
    Dim Slot As Long
    Dim Seq As Long
    Index = Handle
    Slot = IndexToSlot(Index)
    Seq = SlotToSeq(Slot)

    Assert Seq >= 0 And Seq < Core.Size, _
        "Invalid Socket Handle", LOCATION

    Set Socket = sck(Index)
End Property

Public Function AllocSocket(ByVal OutgoingEvent As SocketEvents) As Long
    Assert Not OutgoingEvent Is Nothing, _
           "OutgoingEvent must be specified", LOCATION
    Dim Seq As Long
    Dim Index As Integer
    Core.Append 1
    Seq = Core.Size - 1
    Index = SeqToIndex(Seq)
    m_OutgoingEvents.Item(Index) = OutgoingEvent
    AllocSocket = Index
End Function

Public Sub FreeSocket(ByVal Handle As Long)
    Dim Index As Integer
    Dim Slot As Long
    Dim Seq As Long
    Index = Handle
    Slot = IndexToSlot(Index)
    Seq = SlotToSeq(Slot)

    Assert Seq >= 0 And Seq < Core.Size, _
        "Invalid Socket Handle", LOCATION

    Core.SlotRemove Slot
End Sub

Public Property Get Status() As String
    Status = Me.Caption
End Property

Public Property Let Status(ByVal newval As String)
    Me.Caption = newval
End Property

Private Sub SocketEvents_OnClose()
    Status = "OnClose"
End Sub

Private Sub SocketEvents_OnConnect()
    Status = "OnConnect"
End Sub

Private Sub SocketEvents_OnConnectionRequest(ByVal requestID As Long)
    Status = "OnConnectionRequest " & requestID
End Sub

Private Sub SocketEvents_OnDataArrival(ByVal bytesTotal As Long)
    Status = "OnDataArrival " & bytesTotal
End Sub

Private Sub SocketEvents_OnError(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    Status = "OnError " & Number & "-" & Description _
           & " Code=" & Scode _
           & " Source=" & Source
End Sub

Private Sub SocketEvents_OnSendComplete()
    Status = "OnSendComplete"
End Sub

Private Sub SocketEvents_OnSendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
    Status = "OnSendProgress " & bytesSent & "/" & bytesRemaining
End Sub
