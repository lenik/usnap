VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "桃壳软件 - 兰太阳网络系统程序指南"
   ClientHeight    =   2085
   ClientLeft      =   1230
   ClientTop       =   2010
   ClientWidth     =   5640
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   2085
   ScaleWidth      =   5640
   Begin VB.CommandButton boxClass
      Height          =   615
      Left            =   180
      TabIndex        =   0
      TabStop         =   0   'False
      Top             =   1140
      Visible         =   0   'False
      Width           =   735
   End
   Begin BSNPF.CClass PClass
      Height          =   855
      Index           =   0
      Left            =   120
      TabIndex        =   1
      Top             =   120
      Visible         =   0   'False
      Width           =   855
      _ExtentX        =   1508
      _ExtentY        =   1508
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Class"
   End
   Begin BSNPF.CClass PClass
      Height          =   855
      Index           =   1
      Left            =   1020
      TabIndex        =   2
      Top             =   120
      Visible         =   0   'False
      Width           =   855
      _ExtentX        =   1508
      _ExtentY        =   1508
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Class"
   End
   Begin BSNPF.CClass PClass
      Height          =   855
      Index           =   2
      Left            =   1920
      TabIndex        =   3
      Top             =   120
      Visible         =   0   'False
      Width           =   855
      _ExtentX        =   1508
      _ExtentY        =   1508
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Class"
   End
   Begin BSNPF.CClass PClass
      Height          =   855
      Index           =   3
      Left            =   2820
      TabIndex        =   4
      Top             =   120
      Visible         =   0   'False
      Width           =   855
      _ExtentX        =   1508
      _ExtentY        =   1508
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Class"
   End
   Begin BSNPF.CClass PClass
      Height          =   855
      Index           =   4
      Left            =   3720
      TabIndex        =   5
      Top             =   120
      Visible         =   0   'False
      Width           =   855
      _ExtentX        =   1508
      _ExtentY        =   1508
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Class"
   End
   Begin BSNPF.CClass PClass
      Height          =   855
      Index           =   5
      Left            =   4620
      TabIndex        =   6
      Top             =   120
      Visible         =   0   'False
      Width           =   855
      _ExtentX        =   1508
      _ExtentY        =   1508
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Class"
   End
   Begin VB.Menu mnuSystem
      Caption         =   "&S系统"
      Begin VB.Menu mnuSystemStatusSystem
         Caption         =   "&I系统状态"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuSystemStatusNetwork
         Caption         =   "&N网络状态"
         Shortcut        =   ^N
      End
      Begin VB.Menu mnuSystemSep
         Caption         =   "-"
      End
      Begin VB.Menu mnuSystemShutdown
         Caption         =   "&D关机"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu mnuProgram
      Caption         =   "&P程序"
      Begin VB.Menu mnuProgramAddClass
         Caption         =   "&C新增分类"
      End
      Begin VB.Menu mnuProgramDelClass
         Caption         =   "&R删除分类"
      End
      Begin VB.Menu mnuProgramAddItem
         Caption         =   "&I新增项目"
      End
      Begin VB.Menu mnuProgramDelItem
         Caption         =   "&E删除项目"
      End
      Begin VB.Menu mnuProgramSep
         Caption         =   "-"
      End
      Begin VB.Menu mnuProgramArrange
         Caption         =   "&A排列图标"
         Shortcut        =   ^A
      End
   End
   Begin VB.Menu mnuSecurity
      Caption         =   "&M安全"
      Begin VB.Menu mnuSecurityMaintain
         Caption         =   "&L管理员"
         Enabled         =   0   'False
         Shortcut        =   ^L
      End
      Begin VB.Menu mnuSecurityDiary
         Caption         =   "&D日记"
         Enabled         =   0   'False
         Shortcut        =   ^D
      End
   End
   Begin VB.Menu mnuHelp
      Caption         =   "&H帮助"
      Begin VB.Menu mnuHelpContent
         Caption         =   "&C目录"
         Shortcut        =   {F1}
      End
      Begin VB.Menu mnuHelpSep
         Caption         =   "-"
      End
      Begin VB.Menu mnuHelpAbout
         Caption         =   "&A关于本软件"
         Shortcut        =   +{F1}
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Base 0

Dim Undefined As String

Dim ToAddClass As Boolean, ToDelClass As Boolean
Dim ToAddItem As Boolean, ToDelItem As Boolean

Dim ClassLeft As Long, ClassTop As Long

Dim IBaseX As Single, IBaseY As Single

Sub ResetAct()
  ToAddClass = False
  ToDelClass = False
  ToAddItem = False
  ToDelItem = False
End Sub

Function ReadIn() As Boolean
  ReadIn = FReadIn(frmMain)
End Function

Function Save() As Boolean
  Save = FSave(frmMain)
End Function

Sub Developping()
    MsgBox "正在开发中. 这是测试版, 该功能由于并不常用留待以后开发, 敬请留意! ", , "注意信息"
End Sub

Sub ModifyItem(Index As Integer, ItemIndex As Integer)
    frmAddFile.cboClass.Enabled = False
    frmAddFile.txtAlias = PClass(Index).GetName(ItemIndex)
    frmAddFile.txtProgramName = PClass(Index).GetAlias(ItemIndex)
    frmAddFile.txtIconFile = PClass(Index).GetIconName(ItemIndex)
    frmAddFile.IBackup
    frmAddFile.Show 1
    frmAddFile.cboClass.Enabled = True
    PClass(Index).SetName ItemIndex, frmAddFile.txtAlias
    PClass(Index).SetAlias ItemIndex, frmAddFile.txtProgramName
    PClass(Index).SetIconName ItemIndex, frmAddFile.txtIconFile
    Save
    Init
    ReadIn
End Sub

Sub Init()
  Dim I As Integer, J As Integer

  Undefined = "@@UNDEFINED@@"

  CurDir = String$(300, " ")
  CurDir = Left(CurDir, GetCurrentDirectory(300, CurDir)) + "\"

  FSystemDir = "F:\TOPCROAK\SOFTWARE\BSNPF\"
  DataDir = "F:\CONFIG\SOFTWARE\BSNPF\"
  ClassDataFile = "Class.Dat"
  UserFile = "Users.dat"

  For I = 0 To PClassMax - 1
    For J = 0 To PItemMax - 1
      PClass(I).SetName J, Undefined
      PClass(I).SetAlias J, Undefined
      PClass(I).SetPicture J, LoadPicture()
      PClass(I).Hide J
    Next
    PClass(I).Visible = False
  Next

  ResetAct

End Sub

Private Sub Form_Load()
  Init
  ReadIn
End Sub

Private Sub Form_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
  If ToAddClass = True And Button = 1 Then
    ClassLeft = X
    ClassTop = Y
    boxClass.Left = X
    boxClass.Top = Y
    boxClass.Width = 0
    boxClass.Height = 0
    boxClass.Visible = True
  End If
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  If ToAddClass = True And Button = 1 Then
    If X - ClassLeft > 0 Then
      boxClass.Left = ClassLeft
      boxClass.Width = X - boxClass.Left
    Else    ' X in opposite direction
      boxClass.Left = X
      boxClass.Width = ClassLeft - X
    End If

    If Y - ClassTop > 0 Then
      boxClass.Top = ClassTop
      boxClass.Height = Y - boxClass.Top
    Else    ' Y in opposite direction
      boxClass.Top = Y
      boxClass.Height = ClassTop - Y
    End If
  End If
End Sub

Private Sub Form_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
  'On error resume next
  If ToAddClass = True And Button = 1 Then
    ResetAct
    If MaxClass < PClassMax Then
      PClass(MaxClass).Caption = InputBox("请输入类别名: ", "提示")
      PClass(MaxClass).Left = boxClass.Left
      PClass(MaxClass).Top = boxClass.Top
      PClass(MaxClass).Width = boxClass.Width
      PClass(MaxClass).Height = boxClass.Height
      PClass(MaxClass).Visible = True
      MaxClass = MaxClass + 1
      Save
    Else
      MsgBox "too many classes."
    End If
    boxClass.Visible = False
  End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
  Save
End Sub

Private Sub mnuHelpAbout_Click()
  frmAbout.Show
End Sub

Private Sub mnuHelpContent_Click()
    WinExec SysDrive + "\Progra~1\Intern~1\IExplore " + FSystemDir + "Content.html", SW_NORMAL
End Sub

Private Sub mnuProgramAddClass_Click()
    ResetAct
    ToAddClass = True
End Sub

Private Sub mnuProgramAddItem_Click()
    ResetAct
    ToAddItem = True
End Sub

Private Sub mnuProgramArrange_Click()
    For ii = 0 To MaxClass - 1
        If PClass(ii).Visible = True Then
            PClass(ii).ArrangeItem True
        End If
    Next
End Sub

Private Sub mnuProgramDelClass_Click()
    ResetAct
    ToDelClass = True
End Sub

Private Sub mnuProgramDelItem_Click()
    ResetAct
    ToDelItem = True
End Sub

Private Sub mnuSecurityDiary_Click()
    Developping
End Sub

Private Sub mnuSecurityMaintain_Click()
    Developping
End Sub

Private Sub mnuSystemShutdown_Click()
    frmShutDown.Show 1
End Sub

Private Sub mnuSystemStatusNetwork_Click()
    Developping
End Sub

Private Sub mnuSystemStatusSystem_Click()
    Developping
End Sub

Private Sub PClass_IMouseDown(Index As Integer, ItemIndex As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    CurClass = Index
    If Button = 1 Then
        If Shift = 0 Then
            If ToDelItem = True Then
                ResetAct
                PClass(Index).Hide ItemIndex
                Save
                Init
                ReadIn
            End If
        ElseIf Shift = 4 Then   'Alt-
            ModifyItem Index, ItemIndex
        End If
    ElseIf Button = 2 Then
        IBaseX = PClass(Index).GetX(ItemIndex) - X
        IBaseY = PClass(Index).GetY(ItemIndex) - Y
        boxClass.Caption = "Moving"
        boxClass.Width = PClass(Index).GetWidth(ItemIndex)
        boxClass.Height = PClass(Index).GetHeight(ItemIndex)
        boxClass.Visible = True
    End If
End Sub

Private Sub PClass_IMouseMove(Index As Integer, ItemIndex As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button = 2 Then
      boxClass.Left = PClass(Index).Left + IBaseX + X
      boxClass.Top = PClass(Index).Top + IBaseY + Y
    End If
End Sub

Private Sub PClass_IMouseUp(Index As Integer, ItemIndex As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button = 2 Then
      PClass(Index).SetXY ItemIndex, IBaseX + X, IBaseY + Y
      boxClass.Visible = False
      boxClass.Caption = ""
    End If
End Sub

Private Sub PClass_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
  Dim MI As Integer

  CurClass = Index

  If Button = 2 And boxClass.Visible = False Then
      If Shift = 0 Then
          IBaseX = PClass(Index).Left - X
          IBaseY = PClass(Index).Top - Y
          boxClass.Caption = "Moving"
          boxClass.Width = PClass(Index).Width
          boxClass.Height = PClass(Index).Height
          boxClass.Visible = True
      Else
          boxClass.Caption = "Sizing"
          boxClass.Left = PClass(Index).Left
          boxClass.Top = PClass(Index).Top
          boxClass.Width = X
          boxClass.Height = Y
          boxClass.Visible = True
      End If
  End If

  If Button = 1 Then
    If Shift = 4 Then
      PClass(CurClass).Caption = InputBox("请输入类别名: ", "提示")
      Save
    ElseIf ToAddItem = True Then
      ResetAct
      If MaxClass = 0 Then
        MsgBox "没有至少一个类别情况下不可以新建程序项"
        Exit Sub
      End If
      frmAddFile.InitClassCombo
      frmAddFile.IBackup
      frmAddFile.Show 1
      ObjClass = frmAddFile.cboClass.ListIndex
      MI = PClass(ObjClass).MaxItem
      If MI < PItemMax Then
        PClass(ObjClass).SetName MI, frmAddFile.txtAlias.Text
        PClass(ObjClass).SetAlias MI, frmAddFile.txtProgramName.Text
        PClass(ObjClass).SetIconName MI, frmAddFile.txtIconFile.Text
        PClass(ObjClass).SetXY MI, Int(X), Int(Y)
        PClass(ObjClass).Show MI
        PClass(ObjClass).MaxItem = MI + 1
        Save
      Else
        MsgBox "Too many items"
      End If
    ElseIf ToDelClass = True Then
      ResetAct
      PClass(Index).Visible = False
      Save
      Init
      ReadIn
      Exit Sub
    End If
  End If

End Sub

Private Sub PClass_Click(Index As Integer, ItemIndex As Integer, VName As String)
  CurClass = Index
  WinExec VName, SW_NORMAL
End Sub

Private Sub PClass_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
  If Button = 2 Then
      If Shift = 0 Then
          boxClass.Left = IBaseX + X
          boxClass.Top = IBaseY + Y
      Else
          If X > 0 Then boxClass.Width = X
          If Y > 0 Then boxClass.Height = Y
      End If
  End If
End Sub

Private Sub PClass_MouseUp(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button = 2 Then
        If Shift = 0 Then
            PClass(Index).Left = IBaseX + X
            PClass(Index).Top = IBaseY + Y
            boxClass.Visible = False
            boxClass.Caption = ""
        Else
            If X > 0 Then PClass(Index).SetWidth Int(X)
            If Y > 0 Then PClass(Index).SetHeight Int(Y)
            boxClass.Visible = False
            boxClass.Caption = ""
        End If
    End If
End Sub
