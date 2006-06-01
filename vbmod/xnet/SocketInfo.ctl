VERSION 5.00
Begin VB.UserControl SocketInfo
   ClientHeight    =   825
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   5205
   ScaleHeight     =   825
   ScaleWidth      =   5205
   Begin VB.CommandButton btnRemove
      Caption         =   "X"
      Height          =   315
      Left            =   4800
      TabIndex        =   6
      Top             =   60
      Width           =   315
   End
   Begin VB.TextBox txtComment
      Height          =   285
      Left            =   420
      TabIndex        =   5
      Text            =   "..."
      Top             =   420
      Width           =   4335
   End
   Begin VB.TextBox txtRemotePort
      Height          =   285
      Left            =   4140
      Locked          =   -1  'True
      TabIndex        =   4
      Text            =   "0"
      Top             =   60
      Width           =   615
   End
   Begin VB.TextBox txtRemoteAddress
      Height          =   285
      Left            =   2940
      Locked          =   -1  'True
      TabIndex        =   3
      Text            =   "127.0.0.1"
      Top             =   60
      Width           =   1155
   End
   Begin VB.TextBox txtLocalPort
      Height          =   285
      Left            =   2280
      Locked          =   -1  'True
      TabIndex        =   2
      Text            =   "0"
      Top             =   60
      Width           =   615
   End
   Begin VB.TextBox txtLocalAddress
      Height          =   285
      Left            =   1080
      Locked          =   -1  'True
      TabIndex        =   1
      Text            =   "127.0.0.1"
      Top             =   60
      Width           =   1155
   End
   Begin VB.TextBox txtIndex
      Height          =   285
      Left            =   420
      Locked          =   -1  'True
      TabIndex        =   0
      Text            =   "0"
      Top             =   60
      Width           =   615
   End
   Begin VB.Shape Light
      FillColor       =   &H00808080&
      FillStyle       =   0  'Solid
      Height          =   255
      Left            =   60
      Shape           =   2  'Oval
      Top             =   60
      Width           =   255
   End
End
Attribute VB_Name = "SocketInfo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const STATE_CLOSED              As Long = &H808080
Private Const STATE_CONNECTED           As Long = &HFF00&
Private Const STATE_BUSY                As Long = &HFF&
Private Const STATE_ERROR               As Long = &HFFFF00

Private m_Socket As Winsock

Public Event OnRemove()

Sub BindSocket(sck As Winsock)
    Set m_Socket = sck
End Sub

Private Sub btnRemove_Click()
    RaiseEvent OnRemove
End Sub

Private Sub txtComment_Change()
    m_Socket.Tag = txtComment.Text
End Sub

Private Sub UserControl_Resize()
    Width = 5205
    Height = 825
End Sub

Public Sub Refresh()
    txtRemoteAddress.Text = m_Socket.RemoteHostIP
    txtRemotePort.Text = m_Socket.RemotePort
    txtLocalAddress.Text = m_Socket.LocalIP
    txtLocalPort.Text = m_Socket.LocalPort
    txtComment.Text = m_Socket.Tag
    txtIndex.Text = m_Socket.Index

    Light.FillStyle = vbSolid
    Select Case m_Socket.State
    Case sckClosed
        Light.FillColor = STATE_CLOSED
    Case sckClosing
        Light.FillColor = STATE_BUSY
    Case sckConnected
        Light.FillColor = STATE_CONNECTED
    Case sckConnecting
        Light.FillColor = STATE_BUSY
    Case sckConnectionPending
        Light.FillColor = STATE_BUSY
    Case sckError
        Light.FillColor = STATE_ERROR
        Light.FillStyle = vbDownwardDiagonal
    Case sckHostResolved
        Light.FillColor = STATE_BUSY
    Case sckListening
        Light.FillColor = STATE_CONNECTED
    Case sckOpen
        Light.FillColor = STATE_CONNECTED
    Case sckResolvingHost
        Light.FillColor = STATE_BUSY
    End Select
End Sub
