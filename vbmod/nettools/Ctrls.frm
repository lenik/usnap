VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Ctrls
   Caption         =   "SocketCtrls"
   ClientHeight    =   1635
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   2130
   LinkTopic       =   "Form1"
   ScaleHeight     =   1635
   ScaleWidth      =   2130
   StartUpPosition =   3  'Windows Default
   Begin MSWinsockLib.Winsock ctrl
      Index           =   0
      Left            =   180
      Top             =   240
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
End
Attribute VB_Name = "Ctrls"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents sa As SAOT
Attribute sa.VB_VarHelpID = -1
Private sa_data As New SAOT
Private last_slot As Integer
Private last_index As Integer

' Index -> Socket
Private sdmap As New Collection

Private Sub ctrl_Close(Index As Integer)
    Dim sd As Socket
    Set sd = sdmap(Index)
    sd.OnClose
End Sub

Private Sub ctrl_Connect(Index As Integer)
    Dim sd As Socket
    Set sd = sdmap(Index)
    sdmap(Index).OnConnect
End Sub

Private Sub ctrl_ConnectionRequest(Index As Integer, ByVal requestID As Long)
    Dim sd As Socket
    Set sd = sdmap(Index)
    sd.OnConnectionRequest requestID
End Sub

Private Sub ctrl_DataArrival(Index As Integer, ByVal bytesTotal As Long)
    Dim sd As Socket
    Set sd = sdmap(Index)
    sd.OnDataArrival bytesTotal
End Sub

Private Sub ctrl_Error(Index As Integer, ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    Dim sd As Socket
    Set sd = sdmap(Index)
    sd.OnError Number, Description, Scode, Source, HelpFile, HelpContext, CancelDisplay
End Sub

Private Sub ctrl_SendComplete(Index As Integer)
    Dim sd As Socket
    Set sd = sdmap(Index)
    sd.OnSendComplete
End Sub

Private Sub ctrl_SendProgress(Index As Integer, ByVal bytesSent As Long, ByVal bytesRemaining As Long)
    Dim sd As Socket
    Set sd = sdmap(Index)
    sd.OnSendProgress bytesSent, bytesRemaining
End Sub

Private Sub Form_Load()
    sa.Clear
    ' default ctrl(0), which is never used
    Set sa = sa_data
    ' sa.Append 1
End Sub

Public Function Allocate() As Integer
    Dim ctrl_index As Integer
    sa.Append 1
    ctrl_index = last_slot
    Allocate = last_index
    Load ctrl(ctrl_index)
End Function

Public Sub Free(ByVal Index As Integer)
    Dim ctrl_index As Integer
    ctrl_index = sa.Remove(Index)
    Unload ctrl(ctrl_index)
End Sub

Public Property Get Item(ByVal Index As Integer) As Winsock
    Set Item = ctrl(Index)
End Property

Private Sub sa_Add(ByVal slot As Long, ByVal Index As Long)
    last_slot = slot
    last_index = Index
End Sub

Private Sub sa_Remove(ByVal slot As Long, ByVal Index As Long)
    last_slot = slot
    last_index = Index
End Sub
