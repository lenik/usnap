VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmDraw
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "绘图"
   ClientHeight    =   3750
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   3090
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3750
   ScaleWidth      =   3090
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin MSComctlLib.ImageList il
      Left            =   120
      Top             =   120
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   6
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmDraw.frx":0000
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmDraw.frx":031A
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmDraw.frx":0634
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmDraw.frx":094E
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmDraw.frx":0C68
            Key             =   ""
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "frmDraw.frx":0F82
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.Toolbar tb
      Align           =   3  'Align Left
      Height          =   3750
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   600
      _ExtentX        =   1058
      _ExtentY        =   6615
      ButtonWidth     =   1032
      ButtonHeight    =   1005
      Appearance      =   1
      Style           =   1
      ImageList       =   "il"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628}
         NumButtons      =   6
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "DRAWPIXEL"
            Description     =   "在屏幕上画点"
            Object.ToolTipText     =   "画点"
            ImageIndex      =   1
            Style           =   2
         EndProperty
         BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "DRAWLINE"
            Description     =   "在屏幕上按住鼠标并拖动画线"
            Object.ToolTipText     =   "画线"
            ImageIndex      =   2
            Style           =   2
         EndProperty
         BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "DRAWRECT"
            Description     =   "在屏幕上按住鼠标并拖动画矩形"
            Object.ToolTipText     =   "画矩形"
            ImageIndex      =   3
            Style           =   2
         EndProperty
         BeginProperty Button4 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "DRAWELLIPSE"
            Description     =   "在屏幕上按住鼠标并拖动画椭圆"
            Object.ToolTipText     =   "画椭圆"
            ImageIndex      =   4
            Style           =   2
         EndProperty
         BeginProperty Button5 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "DRAWBEZIER"
            Description     =   "选择若干个控制点画Bezier曲线"
            Object.ToolTipText     =   "画曲线"
            ImageIndex      =   5
            Style           =   2
         EndProperty
         BeginProperty Button6 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Key             =   "DRAWTEXT"
            Description     =   "输出一行文字"
            Object.ToolTipText     =   "绘制文字"
            ImageIndex      =   6
            Style           =   2
         EndProperty
      EndProperty
   End
End
Attribute VB_Name = "frmDraw"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Resize()
        Me.width = 100 + tb.ButtonWidth
        Me.height = 380 + tb.ButtonHeight * tb.Buttons.Count
End Sub

Private Sub tb_ButtonClick(ByVal Button As MSComctlLib.Button)
        Dim i
        With frmModify.tb.Buttons
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
        Case "DRAWPIXEL"
                Op = OP_PIXEL
        Case "DRAWLINE"
                Op = OP_LINE
        Case "DRAWRECT"
                Op = OP_RECT
        Case "DRAWELLIPSE"
                Op = OP_ELLIPSE
        Case "DRAWBEZIER"
                Op = OP_BEZIER
                pn = 0
        Case "DRAWTEXT"
                Op = OP_TEXT
        End Select
End Sub
