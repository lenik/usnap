VERSION 5.00
Begin VB.Form ChatStart
   Caption         =   "Start"
   ClientHeight    =   2430
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6000
   LinkTopic       =   "Form1"
   ScaleHeight     =   2430
   ScaleWidth      =   6000
   Begin VB.ComboBox lstDriver
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   675
      ItemData        =   "ChatStart.frx":0000
      Left            =   540
      List            =   "ChatStart.frx":000A
      Style           =   2  'Dropdown List
      TabIndex        =   2
      Top             =   240
      Width           =   4935
   End
   Begin VB.CommandButton Command2
      Caption         =   "&Client"
      Height          =   1035
      Left            =   3180
      TabIndex        =   1
      Top             =   1080
      Width           =   2235
   End
   Begin VB.CommandButton Command1
      Caption         =   "&Server"
      Height          =   1035
      Left            =   540
      TabIndex        =   0
      Top             =   1080
      Width           =   2235
   End
End
Attribute VB_Name = "ChatStart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_Layout As New AutoScaleLayout

Private Sub Command1_Click()
    Unload Me
    ChatServer.Show
End Sub

Private Sub Command2_Click()
    Unload Me
    ChatClient.Show
End Sub

Private Sub Form_Load()
    m_Layout.InitializeCoordinations Me
    lstDriver.ListIndex = 1
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
End Sub

Private Sub lstDriver_Click()
    Select Case lstDriver.ListIndex
    Case 0
        Set Driver = CreateObject("XnetWinsock.Driver")
    Case 1
        Set Driver = New XnetXceed.TCPDriver
    End Select
End Sub
