VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmModify
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "�޸�"
   ClientHeight    =   2850
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   3510
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2850
   ScaleWidth      =   3510
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  '����ȱʡ
   Begin MSComctlLib.ImageList il
      Left            =   120
      Top             =   540
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   5
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmModify.frx":0000
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmModify.frx":031A
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmModify.frx":0634
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmModify.frx":094E
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmModify.frx":0C68
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.Toolbar tb
      Align           =   1  'Align Top
      Height          =   600
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   3510
      _ExtentX        =   6191
      _ExtentY        =   1058
      ButtonWidth     =   1032
      ButtonHeight    =   1005
      Appearance      =   1
      Style           =   1
      ImageList       =   "il"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628}
         NumButtons      =   5
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "SCALE"
            Description     =   "ѡ��һ����������"
            Object.ToolTipText     =   "����"
            ImageIndex      =   1
            Style           =   2
         EndProperty
         BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "ROTATE"
            Description     =   "��ָ���Ƕ���תѡ���һ������"
            Object.ToolTipText     =   "��ת"
            ImageIndex      =   2
            Style           =   2
         EndProperty
         BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "MIRRORH"
            Description     =   "��ѡ���һ��ͼ�ν��о������"
            Object.ToolTipText     =   "ˮƽ����"
            ImageIndex      =   3
            Style           =   2
         EndProperty
         BeginProperty Button4 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "MIRRORV"
            Description     =   "��ѡ���һ��ͼ�ν��о������"
            Object.ToolTipText     =   "��ֱ����"
            ImageIndex      =   4
            Style           =   2
         EndProperty
         BeginProperty Button5 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "SKEW"
            Description     =   "��ָ���Ƕ���бѡ���һ������"
            Object.ToolTipText     =   "��б"
            ImageIndex      =   5
            Style           =   2
         EndProperty
      EndProperty
   End
End
Attribute VB_Name = "frmModify"
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
        With frmProcess.tb.Buttons
                For i = 1 To .Count
                        .Item(i).Value = tbrUnpressed
                Next
        End With

        frmMain.st.Panels(1) = Button.ToolTipText
        frmMain.st.Panels(2) = Button.Description

        Select Case Button.key
        Case "SCALE"
                Op = OP_SCALE
        Case "ROTATE"
                Op = OP_ROTATE
        Case "MIRRORH"
                Op = OP_MIRRORH
        Case "MIRRORV"
                Op = OP_MIRRORV
        Case "SKEW"
                Op = OP_SKEW
        End Select
End Sub
