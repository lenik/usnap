VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   4125
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7845
   LinkTopic       =   "Form1"
   ScaleHeight     =   4125
   ScaleWidth      =   7845
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton cmdTranClsid
      Caption         =   "Translate"
      Height          =   360
      Left            =   6330
      TabIndex        =   17
      Top             =   810
      Width           =   1305
   End
   Begin VB.TextBox txtClsid
      Height          =   345
      Left            =   1050
      TabIndex        =   16
      Text            =   "{00000000-4345-3001-0002-486954656368}"
      Top             =   825
      Width           =   5100
   End
   Begin VB.CommandButton cmdTranProgid
      Caption         =   "Translate"
      Height          =   360
      Left            =   6300
      TabIndex        =   14
      Top             =   315
      Width           =   1305
   End
   Begin VB.Frame Frame1
      Caption         =   "res"
      Height          =   2235
      Left            =   165
      TabIndex        =   5
      Top             =   1680
      Width           =   4950
      Begin VB.TextBox txtDesc
         Height          =   330
         Index           =   3
         Left            =   885
         TabIndex        =   13
         Top             =   1725
         Width           =   3855
      End
      Begin VB.TextBox txtDesc
         Height          =   330
         Index           =   2
         Left            =   900
         TabIndex        =   11
         Top             =   1230
         Width           =   3825
      End
      Begin VB.TextBox txtDesc
         Height          =   330
         Index           =   1
         Left            =   915
         TabIndex        =   9
         Top             =   705
         Width           =   3825
      End
      Begin VB.TextBox txtDesc
         Height          =   330
         Index           =   0
         Left            =   930
         TabIndex        =   7
         Top             =   255
         Width           =   3810
      End
      Begin VB.Label lblDesc
         AutoSize        =   -1  'True
         Caption         =   "Iid"
         Height          =   180
         Index           =   3
         Left            =   120
         TabIndex        =   12
         Top             =   1800
         Width           =   270
      End
      Begin VB.Label lblDesc
         AutoSize        =   -1  'True
         Caption         =   "Iface"
         Height          =   180
         Index           =   2
         Left            =   135
         TabIndex        =   10
         Top             =   1305
         Width           =   450
      End
      Begin VB.Label lblDesc
         AutoSize        =   -1  'True
         Caption         =   "Clsid"
         Height          =   180
         Index           =   1
         Left            =   150
         TabIndex        =   8
         Top             =   780
         Width           =   450
      End
      Begin VB.Label lblDesc
         AutoSize        =   -1  'True
         Caption         =   "Progid"
         Height          =   180
         Index           =   0
         Left            =   165
         TabIndex        =   6
         Top             =   330
         Width           =   540
      End
   End
   Begin VB.TextBox txtProgid
      Height          =   345
      Left            =   1065
      TabIndex        =   4
      Text            =   "TestCom.TestComCtrl.1"
      Top             =   330
      Width           =   5100
   End
   Begin VB.CommandButton Command3
      Caption         =   "New"
      Height          =   450
      Left            =   6945
      TabIndex        =   2
      Top             =   2025
      Width           =   705
   End
   Begin VB.CommandButton Command2
      Caption         =   "CreateObject"
      Height          =   540
      Left            =   6180
      TabIndex        =   1
      Top             =   2640
      Width           =   1470
   End
   Begin VB.CommandButton Command1
      Caption         =   "ComTool::CreateObject"
      Height          =   540
      Left            =   5175
      TabIndex        =   0
      Top             =   3345
      Width           =   2475
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ClsID"
      Height          =   180
      Index           =   2
      Left            =   180
      TabIndex        =   15
      Top             =   915
      Width           =   450
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ProgID"
      Height          =   180
      Index           =   0
      Left            =   195
      TabIndex        =   3
      Top             =   435
      Width           =   540
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public ct As New CaComToolLib.CaCTools
Public lp As New LowXTool.Pointer
Public ls As New LowXTool.String

Private Sub cmdTranClsid_Click()
        On Error GoTo err
        ct.Clsid = txtClsid.Text
        txtDesc(0).Text = ct.ProgId
        txtDesc(1).Text = ct.Clsid
        Exit Sub
err:
        MsgBox err.Description & vbNewLine & err.Source
End Sub

Private Sub cmdTranProgid_Click()
        On Error GoTo err
        ct.ProgId = txtProgid.Text
        txtDesc(0).Text = ct.ProgId
        txtDesc(1).Text = ct.Clsid

        Exit Sub
err:
        MsgBox err.Description & vbNewLine & err.Source
End Sub

Private Sub Command1_Click()
        Dim ce2 As Object
        ' Create: CLSID_CaTestComCtrl, IID__DTestCom _
        ' _
        Set ce2 = ct.CreateObjectByClsid2( _
                "{00000000-4341-FFFF-0012-486954656368}", _
                "{00000000-4341-FFFF-0011-486954656368}")
        'ce2.AboutBox

        Set ce2 = ct.CreateObjectByClsid("{00000010-0000-0010-8000-00AA006D2EA4}")
        ce2.Close
End Sub

Private Sub Command2_Click()
        Dim ce1 As Object
        Set ce1 = CreateObject("testcom.testcomctrl.1")
        ce1.AboutBox
End Sub

Private Sub Command3_Click()
        Dim x As New CaTestComLib.TestCom
        x.AboutBox
        x.AboutBox2
End Sub
