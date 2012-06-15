VERSION 5.00
Begin VB.Form frmMain
   BorderStyle     =   1  'Fixed Single
   Caption         =   "S'FIA|TC - POSID Generator"
   ClientHeight    =   3060
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   8310
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   3060
   ScaleWidth      =   8310
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkIdentifier
      Caption         =   "&IDentifier"
      Height          =   195
      Left            =   6540
      TabIndex        =   9
      ToolTipText     =   "This will reduce the bits of generated POSID"
      Top             =   1800
      Value           =   1  'Checked
      Width           =   1575
   End
   Begin VB.CommandButton cmdAbout
      Caption         =   "&About"
      Height          =   555
      Left            =   4980
      TabIndex        =   13
      Top             =   2280
      Width           =   1515
   End
   Begin VB.OptionButton optArray
      Caption         =   "Array initializer"
      Height          =   195
      Left            =   6540
      TabIndex        =   8
      Top             =   1560
      Value           =   -1  'True
      Width           =   1515
   End
   Begin VB.OptionButton optDefines
      Caption         =   "DEFINES"
      Height          =   195
      Left            =   6540
      TabIndex        =   7
      Top             =   1320
      Width           =   1515
   End
   Begin VB.OptionButton optHex
      Caption         =   "Hex"
      Height          =   195
      Left            =   6540
      TabIndex        =   6
      Top             =   1080
      Width           =   1515
   End
   Begin VB.CommandButton cmdExit
      Cancel          =   -1  'True
      Caption         =   "E&xit"
      Height          =   555
      Left            =   6540
      TabIndex        =   14
      Top             =   2280
      Width           =   1515
   End
   Begin VB.CommandButton cmdCopy
      Caption         =   "&Copy to clipbooard"
      Height          =   555
      Left            =   3420
      TabIndex        =   12
      Top             =   2280
      Width           =   1515
   End
   Begin VB.CommandButton cmdByTime
      Caption         =   "Generate by &Timestamp"
      Height          =   555
      Left            =   1860
      TabIndex        =   11
      Top             =   2280
      Width           =   1515
   End
   Begin VB.CommandButton cmdByMAC
      Caption         =   "Generate by &MAC"
      Height          =   555
      Left            =   300
      TabIndex        =   10
      Top             =   2280
      Width           =   1515
   End
   Begin VB.CommandButton cmdDecode
      Caption         =   "&Hex to POSID"
      Height          =   375
      Left            =   6360
      TabIndex        =   2
      Top             =   240
      Width           =   1695
   End
   Begin VB.CommandButton cmdConvert
      Caption         =   "Con&vert To Code"
      Height          =   375
      Left            =   6360
      TabIndex        =   5
      Top             =   660
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
      Left            =   1560
      MultiLine       =   -1  'True
      TabIndex        =   4
      Top             =   600
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
      Left            =   1560
      TabIndex        =   1
      Text            =   "utim-___3.-.7V-F2q-LbF-VoU"
      Top             =   240
      Width           =   4695
   End
   Begin VB.Label Label2
      Caption         =   "Co&de"
      Height          =   315
      Left            =   300
      TabIndex        =   3
      Top             =   660
      Width           =   1155
   End
   Begin VB.Label Label1
      Caption         =   "&POSID"
      Height          =   315
      Left            =   300
      TabIndex        =   0
      Top             =   240
      Width           =   1155
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Option Base 0

Function PosidPrint(posid) As String
    If chkIdentifier Then
        PosidPrint = Replace(posid, "-", "")
    Else
        PosidPrint = posid
    End If
End Function

Private Sub chkIdentifier_Click()
    If chkIdentifier Then
        EnableIdentifier True
    Else
        EnableIdentifier False
    End If
End Sub

Private Sub cmdAbout_Click()
    frmAbout.Show 1
End Sub

Private Sub cmdByMAC_Click()
    Dim id, mac, tail
    mac = BytesToCCS6(GetMac(0), 48)
    mac = Left(mac, 4) & "-" & Mid(mac, 5)
    tail = CCS6Random(3) & "-" & CCS6Random(3) & "-" & CCS6Random(3)
    txtPosid = PosidPrint("umac-" & mac & "-" & tail)
    cmdConvert_Click
End Sub

Private Sub cmdByTime_Click()
    Dim id, st, tail
    st = GetPosidTimestamp()
    tail = CCS6Random(3) & "-" & CCS6Random(3) & "-" & CCS6Random(3)
    txtPosid = PosidPrint("utim-" & st & "-" & tail)
    cmdConvert_Click
End Sub

Private Sub cmdConvert_Click()
    Dim posid As String
    Dim bytes() As Byte

    posid = Replace(Replace(txtPosid, " ", ""), "-", "")
    If posid = "" Then Exit Sub

    If Len(posid) = 3 Then
        bytes = CCS5ToBytes(posid)
    Else
        bytes = CCS6ToBytes(posid)
    End If

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
    Dim bytes() As Byte, ccs As String
    Dim nbytes As Integer

    bytes = HexToBytes(Replace(Replace(txtPosid, " ", ""), ":", ""))
    nbytes = UBound(bytes) + 1

    If nbytes = 2 And (bytes(1) And 1 = 0) Then
        ccs = BytesToCCS6(bytes, nbytes * 8)
    Else
        ccs = BytesToCCS5(bytes, 15)
    End If

    If Left(ccs, 4) = "umac" Then              ' umac-mmmm-mmmm-aaa-bbb-ccc
        txtPosid = PosidPrint(Left(ccs, 4) & "-" & _
                    Mid(ccs, 5, 4) & "-" & _
                    Mid(ccs, 9, 4) & "-" & _
                    Mid(ccs, 13, 3) & "-" & _
                    Mid(ccs, 16, 3) & "-" & _
                    Mid(ccs, 19, 3))
    ElseIf Left(ccs, 4) = "utim" Then          ' utim-ttttt-rrr-aaa-bbb-ccc
        txtPosid = PosidPrint(Left(ccs, 4) & "-" & _
                    Mid(ccs, 5, 5) & "-" & _
                    Mid(ccs, 10, 3) & "-" & _
                    Mid(ccs, 13, 3) & "-" & _
                    Mid(ccs, 16, 3) & "-" & _
                    Mid(ccs, 19, 3))
    Else                                        ' xxxx-yyyy-...
        txtPosid = ""
        While ccs <> ""
            If txtPosid <> "" Then txtPosid = txtPosid & "-"
            txtPosid = PosidPrint(txtPosid & Left(ccs, 4))
            ccs = Mid(ccs, 5)
        Wend
    End If
End Sub

Private Sub cmdExit_Click()
    End
End Sub

Private Sub Form_Load()
    Randomize Timer
    EnableIdentifier True
    cmdByTime_Click
    txtPosid_GotFocus
End Sub

Private Sub txtCode_GotFocus()
    txtCode.SelStart = 0
    txtCode.SelLength = Len(txtCode)
End Sub

Private Sub txtPosid_Change()
    cmdConvert_Click
End Sub

Private Sub txtPosid_GotFocus()
    If Len(txtPosid) > 15 Then
        txtPosid.SelStart = 15
    Else
        txtPosid.SelStart = 0
    End If
    txtPosid.SelLength = Len(txtPosid) - txtPosid.SelStart
End Sub
