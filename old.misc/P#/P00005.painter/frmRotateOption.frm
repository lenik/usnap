VERSION 5.00
Begin VB.Form frmRotateOption
   Caption         =   "������ת�Ƕ�"
   ClientHeight    =   1725
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3300
   LinkTopic       =   "Form1"
   ScaleHeight     =   1725
   ScaleWidth      =   3300
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command1
      Caption         =   "ȷ��"
      Height          =   375
      Left            =   1920
      TabIndex        =   3
      Top             =   1260
      Width           =   1275
   End
   Begin VB.OptionButton opt270
      Caption         =   "��ת270��"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1080
      Width           =   1575
   End
   Begin VB.OptionButton opt180
      Caption         =   "��ת180��"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   660
      Width           =   1575
   End
   Begin VB.OptionButton opt90
      Caption         =   "��ת90��"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Value           =   -1  'True
      Width           =   1575
   End
End
Attribute VB_Name = "frmRotateOption"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Me.Hide
End Sub
