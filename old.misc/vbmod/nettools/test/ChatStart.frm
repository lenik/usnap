VERSION 5.00
Begin VB.Form ChatStart
   Caption         =   "Start"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   Begin VB.CommandButton Command2
      Caption         =   "&Client"
      Height          =   1095
      Left            =   1260
      TabIndex        =   1
      Top             =   1560
      Width           =   2235
   End
   Begin VB.CommandButton Command1
      Caption         =   "&Server"
      Height          =   1035
      Left            =   1260
      TabIndex        =   0
      Top             =   360
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
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
End Sub
