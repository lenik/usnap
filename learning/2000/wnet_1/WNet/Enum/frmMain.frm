VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "网络资源枚举"
   ClientHeight    =   4155
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5415
   LinkTopic       =   "Form1"
   ScaleHeight     =   4155
   ScaleWidth      =   5415
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame Frame1
      Caption         =   "详细资料"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2415
      Left            =   120
      TabIndex        =   5
      Top             =   600
      Width           =   5055
      Begin VB.Label lblComment
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BeginProperty Font
            Name            =   "宋体"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H80000008&
         Height          =   255
         Left            =   1560
         TabIndex        =   13
         Top             =   1800
         Width           =   1935
      End
      Begin VB.Label Label4
         Caption         =   "Comment: "
         Height          =   255
         Left            =   240
         TabIndex        =   12
         Top             =   1800
         Width           =   975
      End
      Begin VB.Label lblProvider
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BeginProperty Font
            Name            =   "宋体"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H80000008&
         Height          =   255
         Left            =   1560
         TabIndex        =   11
         Top             =   1320
         Width           =   1935
      End
      Begin VB.Label Label3
         Caption         =   "Provider: "
         Height          =   255
         Left            =   240
         TabIndex        =   10
         Top             =   1320
         Width           =   1095
      End
      Begin VB.Label lblRemoteName
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BeginProperty Font
            Name            =   "宋体"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H80000008&
         Height          =   255
         Left            =   1560
         TabIndex        =   9
         Top             =   840
         Width           =   1935
      End
      Begin VB.Label Label2
         AutoSize        =   -1  'True
         Caption         =   "RemoteName: "
         Height          =   195
         Left            =   240
         TabIndex        =   8
         Top             =   840
         Width           =   1065
      End
      Begin VB.Label lblLocalName
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BeginProperty Font
            Name            =   "宋体"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H80000008&
         Height          =   255
         Left            =   1560
         TabIndex        =   7
         Top             =   360
         Width           =   1935
      End
      Begin VB.Label Label1
         Caption         =   "LocalName: "
         Height          =   255
         Left            =   240
         TabIndex        =   6
         Top             =   360
         Width           =   855
      End
   End
   Begin VB.CommandButton cmdNext
      Caption         =   "Enum Next"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   3600
      Width           =   2295
   End
   Begin VB.CommandButton cmdRewine
      Caption         =   "Re-Enum"
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   3120
      Width           =   2295
   End
   Begin VB.Label lblErrorName
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   180
      Left            =   960
      TabIndex        =   4
      Top             =   360
      Width           =   90
   End
   Begin VB.Label lblErrorDesc
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   180
      Left            =   960
      TabIndex        =   3
      Top             =   120
      Width           =   90
   End
   Begin VB.Label lblError
      AutoSize        =   -1  'True
      Caption         =   "ERROR: "
      Height          =   195
      Left            =   120
      TabIndex        =   2
      Top             =   120
      Width           =   675
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim nr As NETRESOURCE
Dim hEnum As Long
Dim r As Long

Private Sub cmdRewine_Click()
    If hEnum <> 0 Then dr WNetCloseEnum(hEnum)
    nr.dwType = RESOURCETYPE_ANY
    nr.dwScope = RESOURCE_CONNECTED
    nr.lpLocalName = "桃壳信业"

    dr WNetOpenEnum(RESOURCE_CONNECTED, RESOURCETYPE_ANY, 0, nr, hEnum)

    freshnr
End Sub

Private Sub cmdNext_Click()
    Dim nCount As Long
    nCount = 1
    dr WNetEnumResource(hEnum, nCount, nr, Len(nr))
    freshnr
End Sub

Private Sub dr(r As Long)
    Dim strBuffer As String * 512
    Dim strProvider As String * 256
    If r = ERROR_SUCCESS Then
        lblError = "Success"
    Else
        lblError = Str(r)
        WNetGetLastError r, strBuffer, 512, strProvider, 256
        lblErrorDesc = strBuffer
        lblErrorName = strProvider
    End If
End Sub

Private Sub freshnr()
    lblLocalName = nr.lpLocalName
    lblRemoteName = nr.lpRemoteName
    lblProvider = nr.lpProvider
    lblComment = nr.lpComment
End Sub
