VERSION 5.00
Begin VB.Form frmOption
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "ѡ��"
   ClientHeight    =   1860
   ClientLeft      =   2565
   ClientTop       =   3345
   ClientWidth     =   2070
   Icon            =   "Option.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1860
   ScaleWidth      =   2070
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cmdBegin
      Caption         =   "&S��ʼ"
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   315
      Left            =   660
      TabIndex        =   8
      Top             =   1380
      Width           =   735
   End
   Begin VB.TextBox txtComplexity
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   1320
      TabIndex        =   7
      Text            =   "3"
      Top             =   1020
      Width           =   615
   End
   Begin VB.TextBox txtHeight
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   1320
      TabIndex        =   5
      Text            =   "12"
      Top             =   720
      Width           =   615
   End
   Begin VB.TextBox txtWidth
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   1320
      TabIndex        =   3
      Text            =   "12"
      Top             =   420
      Width           =   615
   End
   Begin VB.TextBox txtStartLevel
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   270
      Left            =   1320
      TabIndex        =   1
      Text            =   "1"
      Top             =   120
      Width           =   615
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "&4���Ӷ�:"
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   180
      Index           =   3
      Left            =   180
      TabIndex        =   6
      Top             =   1080
      Width           =   720
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "&3�߶�:"
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   180
      Index           =   2
      Left            =   180
      TabIndex        =   4
      Top             =   780
      Width           =   540
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "&2���:"
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   180
      Index           =   1
      Left            =   180
      TabIndex        =   2
      Top             =   480
      Width           =   540
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "&1��ʼ����:"
      BeginProperty Font
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   180
      Index           =   0
      Left            =   180
      TabIndex        =   0
      Top             =   180
      Width           =   900
   End
End
Attribute VB_Name = "frmOption"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdBegin_Click()
  If Val(txtStartLevel.Text) < 1 Or Val(txtStartLevel.Text) > maxlevel Then
    MsgBox "��ʼ��������� 1 -" + Str(maxlevel) + " ֮��", vbOKOnly, "��ʼ����Խ��"
    txtStartLevel.SetFocus
    Exit Sub
  End If
  If Val(txtWidth.Text) < 1 Or Val(txtWidth.Text) > cmaxx Then
    MsgBox "̫����: ��ȱ����� 1 - " + Str(cmaxx) + " ֮��", vbOKOnly, "���Խ��"
    txtWidth.SetFocus
    Exit Sub
  End If
  If Val(txtWidth.Text) < 1 Or Val(txtHeight.Text) > cmaxy Then
    MsgBox "̫����: �߶ȱ����� 1 - " + Str(cmaxy) + " ֮��", vbOKOnly, "�߶�Խ��"
    txtHeight.SetFocus
    Exit Sub
  End If
  If Val(txtComplexity.Text) < 1 Or Val(txtComplexity.Text) < 1 Or Val(txtComplexity.Text) > maxcom Then
    MsgBox "̫����: �߶ȱ����� 1 - " + Str(maxcom) + " ֮��", vbOKOnly, "�߶�Խ��"
    txtComplexity.SetFocus
    Exit Sub
  End If
  Me.Hide
End Sub
