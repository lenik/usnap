VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form3
   Caption         =   "Form3"
   ClientHeight    =   2610
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5625
   LinkTopic       =   "Form3"
   ScaleHeight     =   2610
   ScaleWidth      =   5625
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton cmdConnect
      Caption         =   "连接"
      Height          =   315
      Left            =   4680
      TabIndex        =   13
      Top             =   120
      Width           =   855
   End
   Begin VB.CommandButton cmdClose
      Caption         =   "关闭"
      Height          =   315
      Left            =   4680
      TabIndex        =   12
      Top             =   540
      Width           =   855
   End
   Begin VB.CommandButton cmdSend
      Caption         =   "发送"
      Enabled         =   0   'False
      Height          =   255
      Left            =   60
      TabIndex        =   11
      Top             =   1620
      Width           =   615
   End
   Begin MSWinsockLib.Winsock sock
      Left            =   180
      Top             =   120
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin VB.TextBox rec
      Height          =   270
      Left            =   780
      TabIndex        =   10
      Text            =   "Text1"
      Top             =   1980
      Width           =   3735
   End
   Begin VB.TextBox send
      Height          =   270
      Left            =   780
      TabIndex        =   9
      Text            =   "Text1"
      Top             =   1620
      Width           =   3735
   End
   Begin VB.TextBox localport
      Height          =   255
      Left            =   3360
      TabIndex        =   8
      Text            =   "2000"
      Top             =   660
      Width           =   1155
   End
   Begin VB.TextBox remoteport
      Height          =   255
      Left            =   3360
      TabIndex        =   7
      Text            =   "1000"
      Top             =   1020
      Width           =   1155
   End
   Begin VB.TextBox remoteaddr
      Height          =   270
      Left            =   780
      TabIndex        =   6
      Text            =   "tc-info"
      Top             =   1020
      Width           =   2355
   End
   Begin VB.TextBox localaddr
      Height          =   270
      Left            =   780
      TabIndex        =   5
      Text            =   "tc-info"
      Top             =   660
      Width           =   2355
   End
   Begin VB.TextBox msg
      Height          =   270
      Left            =   2580
      TabIndex        =   4
      Top             =   180
      Width           =   1935
   End
   Begin VB.CheckBox bServer
      Caption         =   "服务器模式"
      Height          =   315
      Left            =   840
      TabIndex        =   0
      Top             =   180
      Width           =   1395
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "接收"
      Height          =   180
      Index           =   3
      Left            =   180
      TabIndex        =   3
      Top             =   1980
      Width           =   360
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "远程"
      Height          =   180
      Index           =   1
      Left            =   180
      TabIndex        =   2
      Top             =   1080
      Width           =   360
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "本地"
      Height          =   180
      Index           =   0
      Left            =   180
      TabIndex        =   1
      Top             =   720
      Width           =   360
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub bServer_Click()
    If bServer Then
        cmdConnect.Caption = "侦听"
    Else
        cmdConnect.Caption = "连接"
    End If
End Sub

Private Sub cmdClose_Click()
    If sock.State <> sckClosed Then
        sock.Close
    End If
End Sub

Private Sub cmdConnect_Click()
    If sock.State <> sckClosed Then sock.Close
    cmdSend.Enabled = False
    If bServer Then
        sock.localport = remoteport
        sock.RemoteHost = localaddr
        sock.remoteport = localport

        sock.Listen
    Else
        sock.localport = localport
        sock.RemoteHost = remoteaddr
        sock.remoteport = remoteport

        sock.Connect
    End If
End Sub

Private Sub cmdSend_Click()
    sock.SendData send.Text
End Sub

Private Sub Form_Load()
    localaddr = sock.LocalHostName
    remoteaddr = sock.LocalHostName
End Sub

Private Sub sock_Close()
    sock.Close
End Sub

Private Sub sock_Connect()
    msg = "连接成功"
    cmdSend.Enabled = True
End Sub

Private Sub sock_ConnectionRequest(ByVal requestID As Long)
    sock.Close
    sock.Accept requestID
    cmdSend.Enabled = True
End Sub

Private Sub sock_DataArrival(ByVal bytesTotal As Long)
    Dim buf As String * 1024
    sock.GetData buf, , 1024
    rec = Trim(buf)
End Sub

Private Sub sock_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    msg = Number & ":" & Description
End Sub
