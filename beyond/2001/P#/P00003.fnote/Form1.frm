VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1
   Caption         =   "文本编辑器"
   ClientHeight    =   4950
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   6750
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   4950
   ScaleWidth      =   6750
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog cd
      Left            =   1080
      Top             =   3600
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DialogTitle     =   "存为文件："
   End
   Begin MSComctlLib.StatusBar st
      Align           =   2  'Align Bottom
      Height          =   375
      Left            =   0
      TabIndex        =   3
      Top             =   4575
      Width           =   6750
      _ExtentX        =   11906
      _ExtentY        =   661
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628}
         NumPanels       =   1
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628}
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList ImageList1
      Left            =   1620
      Top             =   3540
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   5
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Form1.frx":0442
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Form1.frx":0894
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Form1.frx":0CE6
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Form1.frx":1138
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Form1.frx":158A
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin VB.TextBox t
      BeginProperty Font
         Name            =   "新宋体"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   4455
      Left            =   2760
      MaxLength       =   65535
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   1
      Top             =   0
      Width           =   3795
   End
   Begin MSComctlLib.TreeView tv
      Height          =   4455
      Left            =   60
      TabIndex        =   0
      Top             =   0
      Width           =   2475
      _ExtentX        =   4366
      _ExtentY        =   7858
      _Version        =   393217
      Indentation     =   265
      Style           =   7
      ImageList       =   "ImageList1"
      Appearance      =   1
   End
   Begin VB.PictureBox splt1
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      FillColor       =   &H8000000F&
      ForeColor       =   &H80000008&
      Height          =   4935
      Left            =   2640
      ScaleHeight     =   4935
      ScaleWidth      =   75
      TabIndex        =   2
      Top             =   -120
      Width           =   75
   End
   Begin VB.Menu mSave
      Caption         =   "&Save"
   End
   Begin VB.Menu mSaveAs
      Caption         =   "Save &as"
   End
   Begin VB.Menu mOptions
      Caption         =   "&Options"
      Begin VB.Menu mFilterExt
         Caption         =   "Filter ext name"
      End
      Begin VB.Menu mmScroll
         Caption         =   "ScrollBar"
      End
   End
   Begin VB.Menu mAbout
      Caption         =   "About"
   End
   Begin VB.Menu mExit
      Caption         =   "E&xit"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public fso As New Scripting.FileSystemObject
Public s_d As Boolean, s_dx, s_dy
Public MAX_FILE_SIZE
Public Fext

Const LAST_OK = "上次操作成功"

Property Let status(v)
        st.Panels(1).Text = v
End Property

Public Sub alignToSplitter()
        On Error Resume Next
        tv.Width = splt1.Left - 40
        t.Left = splt1.Left + 50
        t.Width = Width - splt1.Left - 200
End Sub

Public Sub RefreshNode(Node As Node, Optional GoInside As Boolean = True)
        Dim f As Folder, fi As File, sf As Folder, n As Node
        On Error Resume Next
        Select Case Node.Tag
        Case "D"
                Set f = fso.GetFolder(Node.Text & "\")
        Case "P"
                Set f = fso.GetFolder(Node.FullPath)
        End Select
        For Each sf In f.SubFolders
                Set n = tv.Nodes.Add(Node, tvwChild, , sf.Name, 2, 3)
                n.Tag = "P"
                If GoInside Then RefreshNode n, False
        Next
        For Each fi In f.Files
                If Fext <> "" Then
                        If LCase(Right(fi.Name, Len(Fext))) <> LCase(Fext) Then
                                GoTo skip
                        End If
                End If
                Set n = tv.Nodes.Add(Node, tvwChild, , fi.Name, 4, 5)
                n.Tag = "F"
skip:
        Next
End Sub

Private Sub Form_Load()
        Dim i As Long
        Dim n As Node, n1 As Node
        Dim Drive As Drive
        For Each Drive In fso.Drives
                If Drive.IsReady Then
                        Set n = tv.Nodes.Add(, tvwChild, , Drive.DriveLetter & ":", 1, 1)
                        n.Tag = "D"
                        RefreshNode n
                End If
        Next

        MAX_FILE_SIZE = 40000

End Sub

Private Sub Form_Resize()
        On Error Resume Next
        splt1.Height = Height
        tv.Height = Height - 1050
        t.Height = Height - 1050
        alignToSplitter
        st.Panels(1).Width = Width - 500
End Sub

Private Sub mAbout_Click()
        MsgBox "本程序本来用于快速建立P#系列的ASP管理文件。因为使用文本格式么，这样方便些。" & vbNewLine & _
                "Mr.Zweinatas Aburchen Untlichier Julia DanSei, 2002.4.10"
End Sub

Public Sub RemoveNodeChildren(n As Node)
        Dim nn As Node, mm As Node
        Set nn = n.Child.FirstSibling
        Dim i
        For i = 1 To n.Children
                Set mm = nn.Next
                tv.Nodes.Remove nn.Index
                Set nn = mm
        Next
End Sub

Private Sub mExit_Click()
        End
End Sub

Private Sub mFilterExt_Click()
        Fext = InputBox("new filter extension name:", , Fext)
End Sub

Private Sub mmScroll_Click()
        mmScroll.Checked = Not mmScroll.Checked
        't.ScrollBars = IIf(mmScroll.Checked, 3, 2)
End Sub

Private Sub mSave_Click()
        On Error GoTo x
        Dim n As Node, fi As File, ts As TextStream
        Set n = tv.SelectedItem
        If n Is Nothing Or n.Tag <> "F" Then
                status = "在目录树中选择一个文件"
                Exit Sub
        End If
        Set ts = fso.OpenTextFile(n.FullPath, ForWriting, True)
        ts.Write t
        ts.Close
        Set ts = Nothing
        status = LAST_OK
        Exit Sub
x:
        status = "写文件时出错"
End Sub

Private Sub mSaveAs_Click()
        On Error GoTo x
        cd.ShowSave
        If cd.FileName <> "" Then
                Dim ts As TextStream
                Set ts = fso.OpenTextFile(cd.FileName, ForWriting, True)
                ts.Write t
                ts.Close
                Set ts = Nothing
                Exit Sub
        End If
x:
        status = "写文件时出错"
End Sub

Private Sub splt1_MouseDown(Button As Integer, Shift As Integer, x As Single, Y As Single)
        s_d = True
        s_dx = x
        s_dy = Y
End Sub

Private Sub splt1_MouseMove(Button As Integer, Shift As Integer, x As Single, Y As Single)
        If s_d Then
                Dim nl
                nl = splt1.Left + x - s_dx
                If nl > 200 And nl < Width - 400 Then
                        splt1.Left = nl
                        alignToSplitter
                End If
        End If

End Sub

Private Sub splt1_MouseUp(Button As Integer, Shift As Integer, x As Single, Y As Single)
        s_d = False
End Sub

Private Sub t_KeyDown(KeyCode As Integer, Shift As Integer)
        If KeyCode = 65 And Shift = 2 Then
                t.SelStart = 0
                t.SelLength = Len(t)
        End If
End Sub

Private Sub t_KeyPress(KeyAscii As Integer)
        If KeyAscii = 1 Then
                KeyAscii = 0
        End If
End Sub

Private Sub tv_Click()
        On Error Resume Next
        Dim n As Node, fi As File
        Set n = tv.SelectedItem
        If n Is Nothing Then Exit Sub
        If n.Tag = "F" Then
                Set fi = fso.GetFile(n.FullPath)
                If fi Is Nothing Then
                        status = "不能打开文件"
                        Exit Sub
                End If
                If fi.Size > MAX_FILE_SIZE Then
                        status = "文件太大,最大不能超过40k"
                        Exit Sub
                End If
                Dim ts As TextStream
                Set ts = fi.OpenAsTextStream
                t = ts.ReadAll
                ts.Close
                Set ts = Nothing
                status = LAST_OK
        End If
End Sub

Private Sub tv_Expand(ByVal Node As MSComctlLib.Node)
        ' remove node' all children
        RemoveNodeChildren Node

        RefreshNode Node
End Sub
