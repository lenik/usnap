VERSION 5.00
Object = "{683364A1-B37D-11D1-ADC5-006008A5848C}#1.0#0"; "dhtmled.ocx"
Begin VB.Form frmHTMLFlattener
   Caption         =   "<<S'FIA|TC>> - HTML Flattener"
   ClientHeight    =   5625
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   7395
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   ScaleHeight     =   5625
   ScaleWidth      =   7395
   StartUpPosition =   3  'Windows Default
   Begin VB.FileListBox FindFiles
      Height          =   1455
      Left            =   2400
      TabIndex        =   10
      Top             =   3660
      Visible         =   0   'False
      Width           =   1635
   End
   Begin DHTMLEDLibCtl.DHTMLEdit HtmlPreview
      Height          =   1560
      Left            =   480
      TabIndex        =   0
      Top             =   3660
      Visible         =   0   'False
      Width           =   1770
      ActivateApplets =   0   'False
      ActivateActiveXControls=   0   'False
      ActivateDTCs    =   -1  'True
      ShowDetails     =   0   'False
      ShowBorders     =   0   'False
      Appearance      =   1
      Scrollbars      =   -1  'True
      ScrollbarAppearance=   1
      SourceCodePreservation=   -1  'True
      AbsoluteDropMode=   0   'False
      SnapToGrid      =   0   'False
      SnapToGridX     =   50
      SnapToGridY     =   50
      BrowseMode      =   0   'False
      UseDivOnCarriageReturn=   0   'False
   End
   Begin VB.CommandButton cmdRemoveAll
      Caption         =   "R&emove All"
      Height          =   495
      Left            =   5160
      TabIndex        =   5
      Top             =   2226
      Width           =   1935
   End
   Begin VB.CommandButton cmdRemove
      Caption         =   "&Remove"
      Height          =   495
      Left            =   5160
      TabIndex        =   4
      Top             =   1564
      Width           =   1935
   End
   Begin VB.CommandButton cmdAbout
      Caption         =   "&About"
      Height          =   495
      Left            =   5160
      TabIndex        =   8
      Top             =   4212
      Width           =   1935
   End
   Begin VB.CommandButton cmdExit
      Caption         =   "E&xit"
      Height          =   495
      Left            =   5160
      TabIndex        =   9
      Top             =   4875
      Width           =   1935
   End
   Begin VB.CommandButton cmdConvert
      Caption         =   "&Convert"
      Default         =   -1  'True
      Height          =   495
      Left            =   5160
      TabIndex        =   7
      Top             =   3550
      Width           =   1935
   End
   Begin VB.CommandButton cmdOptions
      Caption         =   "&Options"
      Height          =   495
      Left            =   5160
      TabIndex        =   6
      Top             =   2888
      Width           =   1935
   End
   Begin VB.CommandButton cmdAddDirectory
      Caption         =   "Add &Directory"
      Height          =   495
      Left            =   5160
      TabIndex        =   3
      Top             =   902
      Width           =   1935
   End
   Begin VB.CommandButton cmdAddFiles
      Caption         =   "Add &Files"
      Height          =   495
      Left            =   5160
      TabIndex        =   2
      Top             =   240
      Width           =   1935
   End
   Begin VB.ListBox lstFiles
      Height          =   5130
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   4815
   End
End
Attribute VB_Name = "frmHTMLFlattener"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit


Public Options As New Options


Private Sub cmdAbout_Click()
    frmAbout.Show 1
End Sub

Private Sub cmdAddDirectory_Click()
    Dim bi As BROWSEINFO
    Dim l As Long
    Dim szTitle As String * 50
    Dim szDisplayName As String * 300

    bi.hwndOwner = Me.hWnd
    bi.lpszTitle = StrPtr("Select Directory to Add")
    bi.pszDisplayName = StrPtr(szDisplayName)

    l = SHBrowseForFolder(bi)

    MsgBox szDisplayName & ">"
End Sub

Private Sub cmdAddFiles_Click()
    Dim ofn As OPENFILENAME
    ofn.hInstance = App.hInstance
    ofn.hwndOwner = Me.hWnd
    ofn.lStructSize = Len(ofn)

    If GetOpenFileName(ofn) = IDOK Then

    End If
End Sub

Private Sub cmdExit_Click()
    End
End Sub

Private Sub cmdOptions_Click()
    frmOptions.SetOptions Options
End Sub


Private Sub cmdRemove_Click()
    If lstFiles.ListIndex >= 0 Then
        Dim last
        last = lstFiles.ListIndex
        lstFiles.RemoveItem last
        If last < lstFiles.ListCount Then
            lstFiles.ListIndex = last
        Else
            If lstFiles.ListCount > 0 Then
                lstFiles.ListIndex = lstFiles.ListCount - 1
            End If
        End If
    End If
End Sub

Private Sub cmdRemoveAll_Click()
    lstFiles.Clear
End Sub

Private Sub Form_Load()
    Options.Variables.Add _
        "<<S'FIA | TC>> - HTML Flattener " & _
        App.Major & "." & App.Minor & "." & App.Revision, _
        "PROGRAM"
    Options.Variables.Add "", "TITLE"
    Options.Variables.Add "", "SOURCE"
    Options.Variables.Add "", "DEST"

    Load frmOptions
    frmOptions.SaveOptions Options
End Sub

Private Sub Form_Unload(Cancel As Integer)
    End
End Sub
