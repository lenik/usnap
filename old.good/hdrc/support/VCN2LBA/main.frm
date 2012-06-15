VERSION 5.00
Begin VB.Form dlgMain
   BorderStyle     =   1  'Fixed Single
   Caption         =   "VCN/LCN To LBA Index"
   ClientHeight    =   4455
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6945
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   4455
   ScaleWidth      =   6945
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Vals
      Appearance      =   0  'Flat
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Index           =   5
      Left            =   2535
      TabIndex        =   11
      Tag             =   "ClusterSize"
      Text            =   "4096"
      Top             =   3645
      Width           =   3510
   End
   Begin VB.TextBox Vals
      Appearance      =   0  'Flat
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Index           =   4
      Left            =   2535
      TabIndex        =   9
      Tag             =   "LBA"
      Text            =   "1"
      Top             =   3030
      Width           =   3510
   End
   Begin VB.TextBox Vals
      Appearance      =   0  'Flat
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Index           =   3
      Left            =   2535
      TabIndex        =   7
      Tag             =   "VCN"
      Text            =   "0"
      Top             =   2409
      Width           =   3510
   End
   Begin VB.TextBox Vals
      Appearance      =   0  'Flat
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Index           =   2
      Left            =   2535
      TabIndex        =   5
      Tag             =   "Runs"
      Text            =   "8C3E@C0000,10@+B74F0C"
      Top             =   1791
      Width           =   3510
   End
   Begin VB.TextBox Vals
      Appearance      =   0  'Flat
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Index           =   1
      Left            =   2535
      TabIndex        =   3
      Tag             =   "LCN"
      Text            =   "0"
      Top             =   1173
      Width           =   3510
   End
   Begin VB.TextBox Vals
      Appearance      =   0  'Flat
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Index           =   0
      Left            =   2535
      TabIndex        =   1
      Tag             =   "PartStart"
      Text            =   "63"
      Top             =   555
      Width           =   3510
   End
   Begin VB.Label info
      AutoSize        =   -1  'True
      Caption         =   "&Cluster Size"
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Index           =   5
      Left            =   330
      TabIndex        =   10
      Top             =   3690
      Width           =   1140
   End
   Begin VB.Label info
      AutoSize        =   -1  'True
      Caption         =   "LB&A"
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Index           =   4
      Left            =   330
      TabIndex        =   8
      Top             =   3075
      Width           =   375
   End
   Begin VB.Label info
      AutoSize        =   -1  'True
      Caption         =   "&VCN"
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Index           =   3
      Left            =   330
      TabIndex        =   6
      Top             =   2454
      Width           =   375
   End
   Begin VB.Label info
      AutoSize        =   -1  'True
      Caption         =   "Data &Runs"
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Index           =   2
      Left            =   330
      TabIndex        =   4
      Top             =   1836
      Width           =   1005
   End
   Begin VB.Label info
      AutoSize        =   -1  'True
      Caption         =   "LCN"
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Index           =   1
      Left            =   330
      TabIndex        =   2
      Top             =   1218
      Width           =   345
   End
   Begin VB.Label info
      AutoSize        =   -1  'True
      Caption         =   "&Partition Start"
      BeginProperty Font
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   240
      Index           =   0
      Left            =   330
      TabIndex        =   0
      Top             =   600
      Width           =   1410
   End
End
Attribute VB_Name = "dlgMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public Property Get PartStart() As Long
    PartStart = Val(Vals(0).Text)
End Property

Public Property Get LCN() As Long
    LCN = Val("&H" & Vals(1).Text & "&")
End Property
Public Property Let LCN(ByVal newVal As Long)
    Vals(1).Text = Hex(newVal)
End Property

Public Property Get DataRuns() As String
    DataRuns = Vals(2).Text
End Property
Public Property Let DataRuns(ByVal newVal As String)
    Vals(2).Text = newVal
End Property

Public Property Get VCN() As Long
    VCN = Val("&H" & Vals(3).Text & "&")
End Property
Public Property Let VCN(ByVal newVal As Long)
    Vals(3).Text = Hex(newVal)
End Property

Public Property Get LBA() As Long
    LBA = Val(Vals(4).Text)
End Property
Public Property Let LBA(ByVal newVal As Long)
    Vals(4).Text = Trim(newVal) & "," & Hex(newVal) & "H"
End Property

Public Property Get SectorsPerCluster() As Long
    SectorsPerCluster = Val(Vals(5).Text) / 512
End Property


Sub kPartStart()
    ' --> LBA
    LBA = PartStart + LCN * SectorsPerCluster + 1
End Sub

Sub kLCN()
    ' --> LBA, VCN
    LBA = PartStart + LCN * SectorsPerCluster + 1
    If DataRuns <> "" Then
    End If
End Sub

Sub kRuns()
    ' --> LCN, LBA
End Sub

Sub kVCN()
    ' --> LCN, LBA
End Sub

Sub kLBA()
    ' --> LCN, VCN
End Sub


Private Sub Vals_Change(Index As Integer)
    Select Case Vals(Index).Tag
    Case "PartStart"
    Case "LCN"
        kLCN
    Case "Runs"
    Case "VCN"
        kVCN
    Case "LBA"
        kLBA
    End Select
End Sub

Private Sub Vals_KeyPress(Index As Integer, KeyAscii As Integer)
    If KeyAscii = 13 Then
        KeyAscii = 0
        Select Case Vals(Index).Tag
        Case "PartStart"
            kPartStart
        Case "LCN"
            kLCN
        Case "Runs"
            kRuns
        Case "VCN"
            kVCN
        Case "LBA"
            kLBA
        End Select
    End If
End Sub

Private Sub Vals_LostFocus(Index As Integer)
    Select Case Vals(Index).Tag
    Case "PartStart"
        kPartStart
    Case "LCN"
    Case "Runs"
        kRuns
    Case "VCN"
    Case "LBA"
    End Select
End Sub
