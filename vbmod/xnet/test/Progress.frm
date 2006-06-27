VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "comctl32.ocx"
Begin VB.Form frmProgress
   Caption         =   "Progress"
   ClientHeight    =   4485
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7260
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   4485
   ScaleWidth      =   7260
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin ComctlLib.ProgressBar progTotal
      Height          =   435
      Left            =   720
      TabIndex        =   4
      Top             =   2340
      Width           =   5655
      _ExtentX        =   9975
      _ExtentY        =   767
      _Version        =   327682
      Appearance      =   0
      Max             =   10000
   End
   Begin ComctlLib.ProgressBar progItem
      Height          =   435
      Left            =   720
      TabIndex        =   2
      Top             =   1560
      Width           =   5655
      _ExtentX        =   9975
      _ExtentY        =   767
      _Version        =   327682
      Appearance      =   0
      Max             =   10000
   End
   Begin ComctlLib.StatusBar status
      Align           =   2  'Align Bottom
      Height          =   375
      Left            =   0
      TabIndex        =   9
      Top             =   4110
      Width           =   7260
      _ExtentX        =   12806
      _ExtentY        =   661
      SimpleText      =   ""
      _Version        =   327682
      BeginProperty Panels {0713E89E-850A-101B-AFC0-4210102A8DA7}
         NumPanels       =   8
         BeginProperty Panel1 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Object.Width           =   1060
            MinWidth        =   1060
            Text            =   "发送:"
            TextSave        =   "发送:"
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel2 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Object.Width           =   1411
            MinWidth        =   1411
            Text            =   "0"
            TextSave        =   "0"
            Key             =   "SendPkt"
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel3 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Object.Width           =   1060
            MinWidth        =   1060
            Text            =   "接收:"
            TextSave        =   "接收:"
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel4 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Object.Width           =   1411
            MinWidth        =   1411
            Text            =   "0"
            TextSave        =   "0"
            Key             =   "RecvPkt"
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel5 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Object.Width           =   1060
            MinWidth        =   1060
            Text            =   "错误:"
            TextSave        =   "错误:"
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel6 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Object.Width           =   1058
            MinWidth        =   1058
            Text            =   "0"
            TextSave        =   "0"
            Key             =   "ErrPkt"
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel7 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Object.Width           =   1764
            MinWidth        =   1764
            Text            =   "传输速率:"
            TextSave        =   "传输速率:"
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel8 {0713E89F-850A-101B-AFC0-4210102A8DA7}
            Text            =   "0 KB/s"
            TextSave        =   "0 KB/s"
            Key             =   "Speed"
            Object.Tag             =   ""
         EndProperty
      EndProperty
   End
   Begin VB.CommandButton btnPause
      Caption         =   "暂停"
      Enabled         =   0   'False
      Height          =   435
      Left            =   4200
      TabIndex        =   7
      Top             =   3600
      Visible         =   0   'False
      Width           =   1215
   End
   Begin VB.CommandButton btnCancel
      Caption         =   "取消"
      Height          =   435
      Left            =   5640
      TabIndex        =   8
      Top             =   3600
      Width           =   1215
   End
   Begin VB.CommandButton btnTerminate
      Caption         =   "中止传输"
      Height          =   435
      Left            =   2760
      TabIndex        =   6
      Top             =   3600
      Visible         =   0   'False
      Width           =   1215
   End
   Begin VB.Line Line1
      X1              =   0
      X2              =   9000
      Y1              =   3360
      Y2              =   3360
   End
   Begin VB.Label lblItem
      Caption         =   "."
      Height          =   915
      Left            =   1320
      TabIndex        =   1
      Top             =   420
      Width           =   5055
      WordWrap        =   -1  'True
   End
   Begin VB.Label lblItemTitle
      Alignment       =   1  'Right Justify
      Caption         =   "Item"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   420
      Width           =   975
   End
   Begin VB.Label progItemText
      Alignment       =   2  'Center
      Caption         =   "当前项"
      Height          =   195
      Left            =   720
      TabIndex        =   3
      Top             =   2040
      Width           =   5655
   End
   Begin VB.Label progTotalText
      Alignment       =   2  'Center
      Caption         =   "总进度"
      Height          =   195
      Left            =   720
      TabIndex        =   5
      Top             =   2820
      Width           =   5655
   End
End
Attribute VB_Name = "frmProgress"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_SendPkt As Long
Private m_RecvPkt As Long
Private m_ErrPkt As Long
Private m_SendKB As Long
Private m_RecvKB As Long
Private m_StartTime As Double

Public Event OnTerminate()
Public Event OnCancel()
Public Event OnPause()
Public Event OnResume()

Public Property Get Cancelable() As Boolean
    Cancelable = btnCancel.Enabled
End Property

Public Property Let Cancelable(ByVal newval As Boolean)
    btnCancel.Enabled = newval
End Property

Public Property Get Pausable() As Boolean
    Pausable = btnPause.Enabled
End Property

Public Property Let Pausable(ByVal newval As Boolean)
    btnPause.Enabled = newval
End Property

Public Property Get SendPkt() As Long
    SendPkt = m_SendPkt
End Property
Public Property Let SendPkt(ByVal newval As Long)
    m_SendKB = newval
    status.Panels("SendPkt").Text = m_SendPkt
End Property

Public Property Get RecvPkt() As Long
    RecvPkt = m_RecvPkt
End Property
Public Property Let RecvPkt(ByVal newval As Long)
    m_RecvKB = newval
    status.Panels("RecvPkt").Text = m_SendPkt
End Property

Public Property Get ErrPkt() As Long
    ErrPkt = m_ErrPkt
End Property
Public Property Let ErrPkt(ByVal newval As Long)
    m_ErrPkt = newval
    status.Panels("ErrPkt").Text = m_SendPkt
End Property

Public Property Get SendKB() As Long
    SendKB = m_SendKB
End Property
Public Property Let SendKB(ByVal newval As Long)
    m_SendKB = newval
    UpdateSpeed
End Property

Public Property Get RecvKB() As Long
    RecvKB = m_RecvKB
End Property
Public Property Let RecvKB(ByVal newval As Long)
    m_SendKB = newval
    UpdateSpeed
End Property

Private Sub UpdateSpeed()
    Dim TotalKB As Long
    Dim Duration As Double
    Dim Speed As String
    TotalKB = m_SendKB + m_RecvKB
    Duration = Time - m_StartTime
    If Duration < 0.01 Then Duration = 0.01
    Speed = Int(TotalKB / Duration) & " KB/s"
    status.Panels("Speed").Text = Speed
End Sub

Public Property Get ItemPrefix() As String
    ItemPrefix = lblItemTitle.Caption
End Property

Public Property Let ItemPrefix(ByVal newval As String)
    lblItemTitle.Caption = newval
End Property

Public Property Get Item() As String
    Item = lblItem
End Property

Public Property Let Item(ByVal newval As String)
    lblItem = newval
End Property

Public Property Get NTotal() As Single
    NTotal = progTotal.Value / 10000
End Property

Public Property Let NTotal(ByVal newval As Single)
    progTotal.Value = Round(newval * 10000)
End Property

Public Property Get NItem() As Single
    NItem = progItem.Value / 10000
End Property

Public Property Let NItem(ByVal newval As Single)
    progItem.Value = Round(newval * 10000)
End Property

Private Sub btnCancel_Click()
    RaiseEvent OnCancel
End Sub

Private Sub btnPause_Click()
    If btnPause.Tag = "1" Then
        btnPause.Caption = "暂停"
        btnPause.Tag = "0"
        RaiseEvent OnResume
    Else
        btnPause.Caption = "继续"
        btnPause.Tag = "1"
        RaiseEvent OnPause
    End If
End Sub

Private Sub btnTerminate_Click()
    RaiseEvent OnTerminate
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    If UnloadMode = vbFormControlMenu Then
        Cancel = 1
        btnCancel_Click
    End If
End Sub
