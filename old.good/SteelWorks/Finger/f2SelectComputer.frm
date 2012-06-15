VERSION 5.00
Begin VB.Form frmSelectComputer
   Caption         =   "请选择一台计算机"
   ClientHeight    =   3720
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4080
   ControlBox      =   0   'False
   Icon            =   "f2SelectComputer.frx":0000
   LinkTopic       =   "Form2"
   ScaleHeight     =   3720
   ScaleWidth      =   4080
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame frmBox
      BorderStyle     =   0  'None
      Caption         =   "Frame1"
      Height          =   1200
      Left            =   120
      TabIndex        =   2
      Top             =   2400
      Width           =   3735
      Begin VB.CommandButton cmdOK
         Caption         =   "&O确定"
         Height          =   375
         Left            =   1560
         TabIndex        =   5
         Top             =   660
         Width           =   975
      End
      Begin VB.CommandButton cmdCancel
         Caption         =   "&X取消"
         Enabled         =   0   'False
         Height          =   375
         Left            =   2700
         TabIndex        =   4
         Top             =   660
         Width           =   975
      End
      Begin VB.CommandButton cmdFresh
         Caption         =   "&F刷新"
         Height          =   375
         Left            =   0
         TabIndex        =   3
         Top             =   660
         Width           =   975
      End
      Begin VB.Label Label2
         AutoSize        =   -1  'True
         Caption         =   "计算机名"
         Height          =   180
         Left            =   0
         TabIndex        =   9
         Top             =   0
         Width           =   720
      End
      Begin VB.Label lblComputerName
         AutoSize        =   -1  'True
         Caption         =   "-"
         Height          =   180
         Left            =   1020
         TabIndex        =   8
         Top             =   0
         Width           =   90
      End
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "IP地址"
         Height          =   180
         Left            =   0
         TabIndex        =   7
         Top             =   300
         Width           =   540
      End
      Begin VB.Label lblComputerIP
         AutoSize        =   -1  'True
         Caption         =   "-"
         Height          =   180
         Left            =   1020
         TabIndex        =   6
         Top             =   300
         Width           =   90
      End
   End
   Begin VB.ListBox lstComputers
      Height          =   1635
      Left            =   240
      Style           =   1  'Checkbox
      TabIndex        =   0
      Top             =   540
      Width           =   3555
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "网络上的计算机"
      ForeColor       =   &H00400000&
      Height          =   180
      Left            =   180
      TabIndex        =   1
      Top             =   180
      Width           =   1260
   End
End
Attribute VB_Name = "frmSelectComputer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim Status As Integer
Dim bMulti As Boolean

Public SelectComputer_Sep As String

Public pEnumProc As Long

Public Function Run(Optional ByVal multiselect As Boolean = False, Optional ByVal bCancelable As Boolean = False, Optional ByVal opEnumProc As Long = 0) As String
        Dim I As Integer

        ' init vars
                pEnumProc = IIf(opEnumProc = 0, _
                                pFunc(AddressOf Finger_EnumResourceProc), _
                                opEnumProc)

                Status = 0
                cmdCancel.Enabled = bCancelable

                bMulti = multiselect
                Me.Caption = IIf(bMulti, "请选择计算机", "请选择一台计算机")

        ' main
                Me.Show
                cmdFresh_Click
                Do While Status = 0
                        DoEvents
                Loop

        ' check retval
        If Status = 1 Then ' selected
                If bMulti Then
                        Run = ""
                        For I = 0 To lstComputers.ListCount - 1
                                If lstComputers.Selected(I) Then
                                        Run = Run & IIf(Run = "", "", SelectComputer_Sep) & lstComputers.List(I)
                                End If
                        Next
                Else
                        Run = lstComputers.text
                End If
        Else ' canceled
                Run = ""
        End If

        Me.Hide
End Function

Private Sub cmdCancel_Click()
        Status = 2
End Sub

Private Sub cmdFresh_Click()
        lstComputers.Clear
        frmWaitingBox.TurnOn "正在查找计算机, 请稍后...."
        DoEvents

        NetEnum 0, pEnumProc

        frmWaitingBox.TurnOff
End Sub

Private Sub cmdOK_Click()
        Status = 1
End Sub

Private Sub Form_Load()
        Status = 0
        bMulti = False
        SelectComputer_Sep = ";"
        pEnumProc = pFunc(AddressOf Finger_EnumResourceProc)
End Sub

Private Sub Form_Resize()
        If Me.width < 3000 Then Me.width = 3000
        If Me.height < 3000 Then Me.height = 3000

        lstComputers.width = Me.width - 40 * 15
        lstComputers.height = Me.height - lstComputers.Top - 1700
        frmBox.Top = lstComputers.Top + lstComputers.height + 200
End Sub

Private Sub lstComputers_Click()
        Dim selIndex As Integer
        Dim I As Integer

        ' no reentry
        Static bLocked As Boolean
        If bLocked Then Exit Sub
        bLocked = True

        If Not bMulti Then
                selIndex = lstComputers.ListIndex

                For I = 0 To lstComputers.ListCount - 1
                        lstComputers.Selected(I) = False
                Next
                lstComputers.Selected(selIndex) = True
        End If

        bLocked = False
End Sub

Private Sub lstComputers_DblClick()
        Status = 1
End Sub
