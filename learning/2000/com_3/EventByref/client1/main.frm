VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "event byref demonstrate"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command4
      Caption         =   "Command4"
      Height          =   375
      Left            =   3375
      TabIndex        =   7
      Top             =   2625
      Width           =   1050
   End
   Begin VB.CommandButton Command3
      Caption         =   "Command3"
      Height          =   405
      Left            =   3360
      TabIndex        =   6
      Top             =   1980
      Width           =   1050
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   375
      Left            =   3345
      TabIndex        =   5
      Top             =   1395
      Width           =   1125
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   405
      Left            =   3345
      TabIndex        =   4
      Top             =   780
      Width           =   1110
   End
   Begin VB.CommandButton �����¼�2
      Caption         =   "�����¼�2"
      Height          =   540
      Left            =   165
      TabIndex        =   2
      Top             =   1845
      Width           =   2040
   End
   Begin VB.CommandButton �����¼�1
      Caption         =   "�����¼�1"
      Height          =   540
      Left            =   165
      TabIndex        =   1
      Top             =   1050
      Width           =   2040
   End
   Begin VB.CommandButton ���������¼�
      Caption         =   "���������¼�"
      Height          =   525
      Left            =   165
      TabIndex        =   0
      Top             =   300
      Width           =   2055
   End
   Begin VB.Label I1
      Caption         =   "Label1"
      Height          =   450
      Left            =   2880
      TabIndex        =   3
      Top             =   360
      Width           =   1560
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public WithEvents TEventByref As EventByrefLib.CaEventByref
Attribute TEventByref.VB_VarHelpID = -1
Public EventByref1 As New EventByrefLib.CaEventByref

Public aSimple As New ATLEVENTHANDLINGLib.Simple
Public aNotSoSimple As New ATLEVENTHANDLINGLib.NotSoSimple

Public Sub ˢ��()
        I1 = EventByref1.prop1
End Sub

Private Sub Command1_Click()
        aSimple.Start
End Sub

Private Sub Command2_Click()
        aSimple.Stop
End Sub

Private Sub Command3_Click()
        aNotSoSimple.Start
End Sub

Private Sub Command4_Click()
        aNotSoSimple.Stop
End Sub

Private Sub TEventByref_onEvent1()
        MsgBox "�¼�1������"
        EventByref1.prop1 = EventByref1.prop1 + 1
        ˢ��
End Sub

Private Sub TEventByref_onEvent2()
        MsgBox "�¼�2������"
        EventByref1.prop1 = EventByref1.prop1 + 2
        ˢ��
End Sub

Private Sub TEventByref_onEventTest()
        MsgBox "�����¼�������"
        ˢ��
End Sub

Private Sub Form_Load()
        Set TEventByref = EventByref1
        EventByref1.prop1 = 0
End Sub

Private Sub ���������¼�_Click()
        EventByref1.makeEventTest
End Sub

Private Sub �����¼�1_Click()
        EventByref1.makeEvent1
End Sub

Private Sub �����¼�2_Click()
        EventByref1.makeEvent2
End Sub
