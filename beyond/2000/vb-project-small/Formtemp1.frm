VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3780
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5670
   LinkTopic       =   "Form1"
   ScaleHeight     =   3780
   ScaleWidth      =   5670
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text1
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1695
      Left            =   2400
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   2040
      Width           =   3255
   End
   Begin VB.CommandButton Command1
      Caption         =   "获取服务器"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   1
      Top             =   240
      Width           =   2175
   End
   Begin VB.ListBox lstServers
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2580
      Left            =   120
      TabIndex        =   0
      Top             =   1080
      Width           =   2175
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "服务器信息"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   180
      Left            =   2400
      TabIndex        =   2
      Top             =   1800
      Width           =   900
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Declare Function IdDoMsgBox Lib "MSO97.dll" (ByVal prompt As String, Optional ByVal buttons As Long = vbOK, Optional ByVal title As String = vbNullString, Optional ByVal helpfile As String = vbNullString, Optional ByVal context As String = vbNullString) As Long

Private Sub Command_Click()
    Dim str1 As String * 100
    Dim str2 As String * 100
    Dim s1 As String
    Dim s2 As String
    Dim ds1
    Dim ds2

    Dim byte1 As Byte
    Dim byte2 As Byte
    Dim byte3 As Byte

    Dim aBys() As Byte

    byte1 = 12
    byte2 = 34
    byte3 = 56
    str1 = "Hello, World!"
    str2 = "Oh, MYGOD!"
    s1 = "What's your NAME?!"
    s2 = "I know where you gone..."
End Sub

Private Sub Command1_Click()
    Dim serverinfo As SERVER_INFO_100

    Dim res As Long

    res = NetServerEnum(vbNullString, 100, getDataPointer(serverinfo), Len(serverinfo) + 10, entriesread, totalentries, SV_TYPE_ALL, vbNullString, vbNull)

    lstServers.AddItem serverinfo.sv100_name
End Sub
