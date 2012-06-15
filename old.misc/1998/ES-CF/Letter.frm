VERSION 5.00
Begin VB.Form frmLetter
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "信件"
   ClientHeight    =   6210
   ClientLeft      =   1560
   ClientTop       =   1410
   ClientWidth     =   7500
   BeginProperty Font
      Name            =   "宋体"
      Size            =   9
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Letter.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6210
   ScaleWidth      =   7500
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton cmdExit
      Caption         =   "&X 放弃"
      Height          =   315
      Left            =   6300
      TabIndex        =   15
      Top             =   5700
      Width           =   1035
   End
   Begin VB.CommandButton cmdSubmit
      Caption         =   "&S 提交"
      Height          =   315
      Left            =   5100
      TabIndex        =   14
      Top             =   5700
      Width           =   1095
   End
   Begin VB.TextBox txtContext
      ForeColor       =   &H00FF0000&
      Height          =   1755
      Left            =   900
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   13
      Top             =   3660
      Width           =   6195
   End
   Begin VB.TextBox txtCaption2
      ForeColor       =   &H00FF0000&
      Height          =   315
      Left            =   4740
      TabIndex        =   11
      Top             =   3240
      Width           =   2355
   End
   Begin VB.TextBox txtCaption
      ForeColor       =   &H00FF0000&
      Height          =   315
      Left            =   900
      TabIndex        =   9
      Top             =   3240
      Width           =   2595
   End
   Begin VB.TextBox txtFrom
      ForeColor       =   &H00FF00FF&
      Height          =   315
      Left            =   4140
      TabIndex        =   7
      Top             =   2100
      Width           =   2415
   End
   Begin VB.ComboBox cboType
      ForeColor       =   &H00FF00FF&
      Height          =   300
      Index           =   1
      ItemData        =   "Letter.frx":030A
      Left            =   4020
      List            =   "Letter.frx":031A
      Style           =   2  'Dropdown List
      TabIndex        =   5
      Top             =   1680
      Width           =   1695
   End
   Begin VB.ComboBox cboType
      ForeColor       =   &H00FF00FF&
      Height          =   300
      Index           =   0
      ItemData        =   "Letter.frx":036A
      Left            =   2040
      List            =   "Letter.frx":0374
      Style           =   2  'Dropdown List
      TabIndex        =   4
      Top             =   1680
      Width           =   1815
   End
   Begin VB.TextBox txtOtherObject
      ForeColor       =   &H00FF00FF&
      Height          =   315
      Left            =   2040
      TabIndex        =   2
      Top             =   1200
      Visible         =   0   'False
      Width           =   3675
   End
   Begin VB.ComboBox cboObject
      ForeColor       =   &H00FF00FF&
      Height          =   300
      ItemData        =   "Letter.frx":038A
      Left            =   2040
      List            =   "Letter.frx":039D
      Style           =   2  'Dropdown List
      TabIndex        =   1
      Top             =   840
      Width           =   3675
   End
   Begin VB.Label lblContext
      AutoSize        =   -1  'True
      Caption         =   "内容:"
      ForeColor       =   &H00404000&
      Height          =   180
      Left            =   300
      TabIndex        =   12
      Top             =   3720
      Width           =   450
   End
   Begin VB.Label lblCaption2
      AutoSize        =   -1  'True
      Caption         =   "副标题:"
      ForeColor       =   &H00404000&
      Height          =   180
      Left            =   3960
      TabIndex        =   10
      Top             =   3300
      Width           =   630
   End
   Begin VB.Label lblCaption
      AutoSize        =   -1  'True
      Caption         =   "标题:"
      ForeColor       =   &H00404000&
      Height          =   180
      Left            =   300
      TabIndex        =   8
      Top             =   3300
      Width           =   450
   End
   Begin VB.Label lblFrom
      AutoSize        =   -1  'True
      Caption         =   "发送方/笔名:"
      ForeColor       =   &H00808000&
      Height          =   180
      Left            =   2940
      TabIndex        =   6
      Top             =   2160
      Width           =   1080
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   11
      Left            =   6840
      Top             =   2520
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   10
      Left            =   6420
      Top             =   2520
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   9
      Left            =   6000
      Top             =   2520
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   8
      Left            =   5580
      Top             =   2520
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   7
      Left            =   5160
      Top             =   2520
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   6
      Left            =   4740
      Top             =   2520
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   5
      Left            =   2280
      Top             =   300
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   4
      Left            =   1860
      Top             =   300
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   3
      Left            =   1440
      Top             =   300
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   2
      Left            =   1020
      Top             =   300
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   1
      Left            =   600
      Top             =   300
      Width           =   375
   End
   Begin VB.Shape Shape2
      BorderColor     =   &H00008000&
      Height          =   375
      Index           =   0
      Left            =   180
      Top             =   300
      Width           =   375
   End
   Begin VB.Label lblType
      AutoSize        =   -1  'True
      Caption         =   "类型:"
      ForeColor       =   &H00808000&
      Height          =   180
      Left            =   960
      TabIndex        =   3
      Top             =   1740
      Width           =   450
   End
   Begin VB.Label lblObject
      AutoSize        =   -1  'True
      Caption         =   "发送对象:"
      ForeColor       =   &H00808000&
      Height          =   180
      Left            =   960
      TabIndex        =   0
      Top             =   900
      Width           =   810
   End
   Begin VB.Shape Shape1
      BorderColor     =   &H00004000&
      Height          =   2895
      Left            =   60
      Top             =   120
      Width           =   7335
   End
End
Attribute VB_Name = "frmLetter"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Function TranString(S As String, w As Integer) As String
    Dim p As Integer, l As Integer, c As String * 1
    ' w =   0       No translation
    '       1       Xor &H01
    '       2       Xor &H07
    '       3       Xor &HFF
    l = Len(S)
    TranString = ""
    For p = 1 To l
        c = Mid(S, p, 1)
        Select Case w
            Case 0:
            Case 1:
                c = Chr(Asc(c) Xor &H1)
            Case 2:
                c = Chr(Asc(c) Xor &H7)
            Case 3:
                c = Chr(Asc(c) Xor &HFF)
        End Select
        TranString = TranString + c
    Next
End Function

Private Sub cboObject_Click()
    txtOtherObject.Visible = IIf(cboObject.ListIndex = 4, True, False)
End Sub

Private Sub cmdExit_Click()
    Me.Hide
End Sub

Private Sub cmdSubmit_Click()
    Dim F As Integer
    F = FreeFile
    Dim FName As String
    FName = SaveDir + LetterDir + GenID + Left(Trim(TStr(txtCaption)), 6)
    Open FName For Append As #F
        PrintHead F
        If cboObject.ListIndex <> 4 Then
            Print #F, lblObject + Space + cboObject.Text
        Else
            Print #F, lblObject + Space + "(其它)" + txtOtherObject
        End If
        Print #F, lblType + Space + cboType(0).Text + Space + cboType(1).Text
        Print #F, lblFrom + Space + txtFrom
        Print #F, lblCaption + Space + txtCaption
        Print #F, lblCaption2 + Space + txtCaption2
        Print #F, lblContext
        Print #F, "---- ---- ---- ---- ---- ----"
        Print #F, TranString(txtContext, cboType(1).ListIndex)
        Print #F, "---- ---- ---- ---- ---- ----"
        PrintEnd F
    Close #F
    Me.Hide
End Sub

Private Sub Form_Load()
    cboObject.ListIndex = 0
    cboType(0).ListIndex = 0
    cboType(1).ListIndex = 0
End Sub
