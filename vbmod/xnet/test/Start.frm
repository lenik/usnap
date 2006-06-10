VERSION 5.00
Begin VB.Form Start
   Caption         =   "Form1"
   ClientHeight    =   2820
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6420
   LinkTopic       =   "Form1"
   ScaleHeight     =   2820
   ScaleWidth      =   6420
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4
      Caption         =   "&Server"
      Height          =   1035
      Left            =   600
      TabIndex        =   2
      Top             =   1260
      Width           =   2235
   End
   Begin VB.CommandButton Command3
      Caption         =   "&Client"
      Height          =   1035
      Left            =   3240
      TabIndex        =   1
      Top             =   1260
      Width           =   2235
   End
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
      ItemData        =   "Start.frx":0000
      Left            =   600
      List            =   "Start.frx":000A
      Style           =   2  'Dropdown List
      TabIndex        =   0
      Top             =   420
      Width           =   4935
   End
End
Attribute VB_Name = "Start"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Server.Show
    Unload Me
End Sub

Private Sub Command2_Click()
    Client.Show
    Unload Me
End Sub

Private Sub lstDriver_Click()
    Select Case lstDriver.ListIndex
    Case 0
        Set Driver = CreateObject("XnetWinsock.Driver")
    Case 1
        Set Driver = New XnetXceed.TCPDriver
    End Select
End Sub
