VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form3
   Caption         =   "Form3"
   ClientHeight    =   5895
   ClientLeft      =   2010
   ClientTop       =   2025
   ClientWidth     =   6420
   LinkTopic       =   "Form3"
   ScaleHeight     =   5895
   ScaleWidth      =   6420
   Begin VB.CommandButton Command3
      Caption         =   "accept"
      Height          =   255
      Left            =   180
      TabIndex        =   6
      Top             =   5520
      Width           =   2295
   End
   Begin VB.CommandButton Command2
      Caption         =   "connect"
      Height          =   315
      Left            =   3120
      TabIndex        =   5
      Top             =   5100
      Width           =   1995
   End
   Begin VB.CommandButton Command1
      Caption         =   "listen"
      Height          =   315
      Left            =   180
      TabIndex        =   4
      Top             =   5040
      Width           =   2175
   End
   Begin VB.TextBox tb
      Height          =   3075
      Left            =   3060
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   1920
      Width           =   2835
   End
   Begin VB.TextBox ta
      Height          =   3075
      Left            =   180
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   1920
      Width           =   2295
   End
   Begin MSWinsockLib.Winsock b
      Left            =   900
      Top             =   360
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemoteHost      =   "e01"
      RemotePort      =   3000
      LocalPort       =   3001
   End
   Begin MSWinsockLib.Winsock a
      Left            =   300
      Top             =   360
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemoteHost      =   "e01"
      RemotePort      =   3001
      LocalPort       =   3000
   End
   Begin VB.Label lb
      Caption         =   "Label1"
      Height          =   375
      Left            =   3180
      TabIndex        =   2
      Top             =   1200
      Width           =   1755
   End
   Begin VB.Label la
      Caption         =   "Label1"
      Height          =   315
      Left            =   240
      TabIndex        =   0
      Top             =   1320
      Width           =   1275
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub a_ConnectionRequest(ByVal requestID As Long)
    la = "a_ConnectionRequest:" + str(requestID)
End Sub

Private Sub a_DataArrival(ByVal bytesTotal As Long)
    la = "a_DataArrival:" + str(bytesTotal)
    ta = a.GetData
    b.SendData "I get your data!"
End Sub

Private Sub a_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    la = Description
End Sub

Private Sub b_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    lb = Description
End Sub

Private Sub Command1_Click()
    a.Listen
End Sub

Private Sub Command2_Click()
    b.Connect
End Sub

Private Sub Command3_Click()
    a.Accept 11
End Sub
