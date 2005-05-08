VERSION 5.00
Begin VB.Form frmMain
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "POSID Generator"
   ClientHeight    =   3420
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   8685
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3420
   ScaleWidth      =   8685
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.OptionButton optArray
      Caption         =   "Array initializer"
      Height          =   255
      Left            =   6660
      TabIndex        =   8
      Top             =   1920
      Value           =   -1  'True
      Width           =   1515
   End
   Begin VB.OptionButton optDefines
      Caption         =   "DEFINES"
      Height          =   255
      Left            =   6660
      TabIndex        =   7
      Top             =   1560
      Width           =   1515
   End
   Begin VB.OptionButton optHex
      Caption         =   "Hex"
      Height          =   255
      Left            =   6660
      TabIndex        =   6
      Top             =   1200
      Width           =   1515
   End
   Begin VB.CommandButton cmdExit
      Cancel          =   -1  'True
      Caption         =   "E&xit"
      Height          =   615
      Left            =   6480
      TabIndex        =   12
      Top             =   2400
      Width           =   1755
   End
   Begin VB.CommandButton cmdCopy
      Caption         =   "&Copy to clipbooard"
      Height          =   615
      Left            =   4460
      TabIndex        =   11
      Top             =   2400
      Width           =   1755
   End
   Begin VB.CommandButton cmdByTime
      Caption         =   "Generate by &Timestamp"
      Height          =   615
      Left            =   2440
      TabIndex        =   10
      Top             =   2400
      Width           =   1755
   End
   Begin VB.CommandButton cmdByMAC
      Caption         =   "Generate by &MAC"
      Height          =   615
      Left            =   420
      TabIndex        =   9
      Top             =   2400
      Width           =   1755
   End
   Begin VB.CommandButton cmdDecode
      Caption         =   "&Hex to POSID"
      Height          =   375
      Left            =   6480
      TabIndex        =   2
      Top             =   360
      Width           =   1695
   End
   Begin VB.CommandButton cmdConvert
      Caption         =   "Con&vert To Code"
      Height          =   375
      Left            =   6480
      TabIndex        =   5
      Top             =   780
      Width           =   1695
   End
   Begin VB.TextBox txtCode
      BackColor       =   &H8000000F&
      BeginProperty Font
         Name            =   "Courier New"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1515
      Left            =   1680
      MultiLine       =   -1  'True
      TabIndex        =   4
      Top             =   720
      Width           =   4695
   End
   Begin VB.TextBox txtPosid
      BeginProperty Font
         Name            =   "Courier New"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   315
      Left            =   1680
      TabIndex        =   1
      Text            =   "utim-___3.-.7V-F2q-LbF-VoU"
      Top             =   360
      Width           =   4695
   End
   Begin VB.Label Label2
      Caption         =   "Co&de"
      Height          =   315
      Left            =   420
      TabIndex        =   3
      Top             =   780
      Width           =   1155
   End
   Begin VB.Label Label1
      Caption         =   "&POSID"
      Height          =   315
      Left            =   420
      TabIndex        =   0
      Top             =   360
      Width           =   1155
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdByMAC_Click()
    Dim id, mac, tail
    mac = BytesToCCS6(GetMac(0), 48)
    mac = Left(mac, 4) & "-" & Mid(mac, 5)
    tail = CCS6Random(3) & "-" & CCS6Random(3) & "-" & CCS6Random(3)
    txtPosid = "umac-" & mac & "-" & tail
    cmdConvert_Click
End Sub

Private Sub cmdByTime_Click()
    Dim id, st, tail
    st = GetPosidTimestamp()
    tail = CCS6Random(3) & "-" & CCS6Random(3) & "-" & CCS6Random(3)
    txtPosid = "utim-" & st & "-" & tail
    cmdConvert_Click
End Sub

Private Sub cmdConvert_Click()
    Dim bytes() As Byte
    bytes = CCS6ToBytes(Replace(Replace(txtPosid, " ", ""), "-", ""))

    If optHex Then
        txtCode = BytesToHex(bytes, " ")
    ElseIf optDefines Then
        txtCode = "/* " & txtPosid & " */" & vbCrLf & _
                    "POSID(" & BytesToHex(bytes, ", ") & ")"
    ElseIf optArray Then
        txtCode = "/* " & txtPosid & " */" & vbCrLf & _
                    "char POSID_NAME[] = { " & BytesToHex(bytes, ", ") & " }; "
    End If
End Sub

Private Sub cmdCopy_Click()
    Clipboard.SetText txtCode.Text
End Sub

Private Sub cmdDecode_Click()
    Dim bytes() As Byte, ccs6 As String
    bytes = HexToBytes(Replace(Replace(txtPosid, " ", ""), ":", ""))
    ccs6 = BytesToCCS6(bytes, (UBound(bytes) - LBound(bytes) + 1) * 8)

    If Left(ccs6, 4) = "umac" Then              ' umac-mmmm-mmmm-aaa-bbb-ccc
        txtPosid = Left(ccs6, 4) & "-" & _
                    Mid(ccs6, 5, 4) & "-" & _
                    Mid(ccs6, 9, 4) & "-" & _
                    Mid(ccs6, 13, 3) & "-" & _
                    Mid(ccs6, 16, 3) & "-" & _
                    Mid(ccs6, 19, 3)
    ElseIf Left(ccs6, 4) = "utim" Then          ' utim-ttttt-rrr-aaa-bbb-ccc
        txtPosid = Left(ccs6, 4) & "-" & _
                    Mid(ccs6, 5, 5) & "-" & _
                    Mid(ccs6, 10, 3) & "-" & _
                    Mid(ccs6, 13, 3) & "-" & _
                    Mid(ccs6, 16, 3) & "-" & _
                    Mid(ccs6, 19, 3)
    Else                                        ' xxxx-yyyy-...
        txtPosid = ""
        While ccs6 <> ""
            If txtPosid <> "" Then txtPosid = txtPosid & "-"
            txtPosid = txtPosid & Left(ccs6, 4)
            ccs6 = Mid(ccs6, 5)
        Wend
    End If
End Sub

Private Sub cmdExit_Click()
    End
End Sub

Private Sub Form_Load()
    Randomize Timer
    cmdByTime_Click
End Sub

Private Sub txtCode_GotFocus()
    txtCode.SelStart = 0
    txtCode.SelLength = Len(txtCode)
End Sub

Private Sub txtPosid_GotFocus()
    txtPosid.SelStart = 0
    txtPosid.SelLength = Len(txtPosid)
End Sub
