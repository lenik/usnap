VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmProcess
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "����"
   ClientHeight    =   1755
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   3030
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1755
   ScaleWidth      =   3030
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  '����ȱʡ
   Begin MSComctlLib.ImageList il
      Left            =   60
      Top             =   600
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   3
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmProcess.frx":0000
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmProcess.frx":031C
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmProcess.frx":0638
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.Toolbar tb
      Align           =   1  'Align Top
      Height          =   660
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   3030
      _ExtentX        =   5345
      _ExtentY        =   1164
      ButtonWidth     =   1032
      ButtonHeight    =   1005
      Appearance      =   1
      ImageList       =   "il"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628}
         NumButtons      =   3
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "GRADH"
            Description     =   "������ϳ�һ������򲢶������ˮƽ���䴦��"
            Object.ToolTipText     =   "ˮƽ����"
            ImageIndex      =   1
            Style           =   2
         EndProperty
         BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "GRADV"
            Description     =   "������ϳ�һ������򲢶�����д�ֱ���䴦��"
            Object.ToolTipText     =   "��ֱ����"
            ImageIndex      =   2
            Style           =   2
         EndProperty
         BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "BLUR"
            Description     =   "������ϳ�һ������򲢶������ģ������"
            Object.ToolTipText     =   "ģ����"
            ImageIndex      =   3
            Style           =   2
         EndProperty
      EndProperty
   End
End
Attribute VB_Name = "frmProcess"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Resize()
        Me.width = 100 + tb.ButtonWidth * tb.Buttons.Count
        Me.height = 380 + tb.ButtonHeight
End Sub

Private Sub tb_ButtonClick(ByVal Button As MSComctlLib.Button)
        Dim i
        With frmDraw.tb.Buttons
                For i = 1 To .Count
                        .Item(i).Value = tbrUnpressed
                Next
        End With
        With frmModify.tb.Buttons
                For i = 1 To .Count
                        .Item(i).Value = tbrUnpressed
                Next
        End With

        frmMain.st.Panels(1) = Button.ToolTipText
        frmMain.st.Panels(2) = Button.Description

        Select Case Button.key
        Case "GRADH"
                Op = OP_GRADH
        Case "GRADV"
                Op = OP_GRADV
        Case "BLUR"
                Op = OP_BLUR
        End Select
End Sub
