VERSION 5.00
Begin VB.Form frmA1_SelectType
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Select object type"
   ClientHeight    =   3825
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   7245
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3825
   ScaleWidth      =   7245
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CheckBox chkArray
      BackColor       =   &H00E0FFFF&
      Caption         =   "Create &Array"
      Height          =   1215
      Left            =   4860
      Picture         =   "frmA1_SelectType.frx":0000
      Style           =   1  'Graphical
      TabIndex        =   5
      Top             =   2160
      Width           =   1755
   End
   Begin VB.CommandButton btnShape
      BackColor       =   &H00E0FFFF&
      Caption         =   "&Color Range"
      Height          =   1215
      Index           =   4
      Left            =   2700
      Picture         =   "frmA1_SelectType.frx":373E
      Style           =   1  'Graphical
      TabIndex        =   4
      Tag             =   "COLOR"
      Top             =   2160
      Width           =   1755
   End
   Begin VB.CommandButton btnShape
      BackColor       =   &H00E0FFFF&
      Caption         =   "&Polygon"
      Height          =   1215
      Index           =   3
      Left            =   600
      Picture         =   "frmA1_SelectType.frx":67BC
      Style           =   1  'Graphical
      TabIndex        =   3
      Tag             =   "POLY"
      Top             =   2160
      Width           =   1755
   End
   Begin VB.CommandButton btnShape
      BackColor       =   &H00E0FFFF&
      Caption         =   "&Ellipse"
      Height          =   1215
      Index           =   2
      Left            =   4860
      Picture         =   "frmA1_SelectType.frx":9AAA
      Style           =   1  'Graphical
      TabIndex        =   2
      Tag             =   "ELLIPSE"
      Top             =   420
      Width           =   1755
   End
   Begin VB.CommandButton btnShape
      BackColor       =   &H00E0FFFF&
      Caption         =   "R&ound Rectangle"
      Height          =   1215
      Index           =   1
      Left            =   2700
      Picture         =   "frmA1_SelectType.frx":D084
      Style           =   1  'Graphical
      TabIndex        =   1
      Tag             =   "ROUNDRECT"
      Top             =   420
      Width           =   1755
   End
   Begin VB.CommandButton btnShape
      BackColor       =   &H00E0FFFF&
      Caption         =   "&Rectangle"
      Height          =   1215
      Index           =   0
      Left            =   600
      Picture         =   "frmA1_SelectType.frx":1065E
      Style           =   1  'Graphical
      TabIndex        =   0
      Tag             =   "RECT"
      Top             =   420
      Width           =   1755
   End
End
Attribute VB_Name = "frmA1_SelectType"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit


Public array_info As frmA2_ArrayOptions
Public shape As String

Public Property Get getButton(ByVal name As String) As CommandButton
    Dim i As Integer
    For i = 0 To btnShape.Count - 1
        If btnShape(i).Tag = name Then
            Set getButton = btnShape(i)
            Exit Property
        End If
    Next
    Err.Raise -1, , "Invalid name (" & name & ")"
End Property


Private Sub btnShape_Click(Index As Integer)
    Set array_info = Nothing

    If chkArray Then
        If frmA2_ArrayOptions.getArrayOptions = "NONE" Then
            Exit Sub
        Else
            Set array_info = frmA2_ArrayOptions
        End If
    End If

    shape = btnShape(Index).Tag
    Me.Hide
End Sub

Private Sub Form_Load()
    shape = "NONE"
End Sub

Private Sub Form_Unload(Cancel As Integer)
    shape = "NONE"
    Me.Hide
End Sub

Public Function selectType() As String
    Me.Show 1
    selectType = shape
End Function
