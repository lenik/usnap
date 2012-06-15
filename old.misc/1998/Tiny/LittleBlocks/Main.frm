VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "小积木"
   ClientHeight    =   390
   ClientLeft      =   1500
   ClientTop       =   1890
   ClientWidth     =   3795
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   26
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   253
   StartUpPosition =   1  '所有者中心
   Begin VB.Timer tmrPainter
      Interval        =   2
      Left            =   1980
      Top             =   4260
   End
   Begin VB.PictureBox picSource
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      Height          =   1275
      Left            =   180
      ScaleHeight     =   85
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   85
      TabIndex        =   1
      Top             =   3420
      Visible         =   0   'False
      Width           =   1275
   End
   Begin VB.Timer timer
      Enabled         =   0   'False
      Interval        =   200
      Left            =   1500
      Top             =   4260
   End
   Begin VB.PictureBox picPanel
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ClipControls    =   0   'False
      Height          =   150
      Left            =   120
      ScaleHeight     =   150
      ScaleWidth      =   150
      TabIndex        =   0
      Top             =   120
      Width           =   150
   End
   Begin VB.Menu mnuGame
      Caption         =   "&G游戏"
      Begin VB.Menu mnuGameNew
         Caption         =   "&N新游戏"
      End
      Begin VB.Menu mnuGameSave
         Caption         =   "&S存盘"
         Visible         =   0   'False
      End
      Begin VB.Menu mnuGameLoad
         Caption         =   "&L调入"
         Visible         =   0   'False
      End
   End
   Begin VB.Menu mnuRedraw
      Caption         =   "&D重画"
   End
   Begin VB.Menu mnuPause
      Caption         =   "&P暂停"
   End
   Begin VB.Menu mnuAbout
      Caption         =   "&A关于"
   End
   Begin VB.Menu mnuExit
      Caption         =   "&X退出"
   End
   Begin VB.Menu mnuScore
      Caption         =   ""
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Base 0

Const offmax = 8

Const blocksize = 300

Const noleft = 101
Const noright = 102
Const nobottom = 103
Const overblock = 200

Const bwidth = 20
Const bheight = 20

Dim blockcolor As Long, blockedgecolor As Long

Dim startgamelevel As Integer, gamelevel As Integer, score As Integer

' (x, y) is the position of upper-left corner of block
Dim x, y, yoff, maxx, maxy
Dim oldx, oldy, oldyoff

Dim curtype, curcom
Dim curblock(maxcom, maxcom) As Integer
Dim oldblock(maxcom, maxcom) As Integer
Dim scrmap(cmaxx, cmaxy) As Integer

Private Sub Form_Load()
  blockcolor = QBColor(0)
  blockedgecolor = QBColor(7)
End Sub

Sub drawblock()
  For iy = 0 To curcom - 1
    For ix = 0 To curcom - 1
      v = curblock(ix, iy)
      oldblock(ix, iy) = v
      If v <> 0 Then
        BitBlt picPanel.hDC, (x + ix) * bwidth, (y + iy - 1) * bheight + bheight * yoff / offmax, bwidth, bheight, picSource.hDC, (v And 3) * bwidth, (v And 12) / 4 * bheight, SRCCOPY
      End If
    Next
  Next
  oldx = x
  oldy = y
  oldyoff = yoff
End Sub

Sub eraseblock()
  If oldx < 0 Then Exit Sub
  For iy = 0 To curcom - 1
    For ix = 0 To curcom - 1
      v = oldblock(ix, iy)
      If v <> 0 Then
        BitBlt picPanel.hDC, (oldx + ix) * bwidth, (oldy + iy - 1) * bheight + bheight * oldyoff / offmax, bwidth, bheight, picSource.hDC, (v And 3) * bwidth, (v And 12) / 4 * bheight, WHITENESS
      End If
    Next
  Next
End Sub

Sub repaintall()
  picPanel.Cls
  For iy = 0 To maxy - 1
    For ix = 0 To maxx - 1
      v = scrmap(ix, iy)
      If v <> 0 Then
        BitBlt picPanel.hDC, ix * bwidth, iy * bheight, bwidth, bheight, picSource.hDC, (v And 3) * bwidth, (v And 12) / 4 * bheight, SRCCOPY
      End If
    Next
  Next
End Sub

Sub repaint()
  eraseblock
  drawblock
  picPanel.Refresh
End Sub

Sub newblock()
  Dim bs(1 To 4) As String
  bs(1) = "1"
  bs(2) = "0001;0101;0111;0110"
  bs(3) = "001001001;001011010;010011001;000011011;011001001;011010010;000010111"
  bs(4) = "0001000100010001;0001001001001000"
  ' bs(n).total = (len(bs(n))+1)/(n*n+1)
  ' bs(n).m = mid(bs(n), (n*n+1)m, len=n*n)
  x = (maxx - maxcom) / 2
  y = 0
  rn = Int(Rnd * maxtype) + 1
  rm = Int(Rnd * (Len(bs(curcom)) + 1) / (curcom * curcom + 1))
  bsc = Mid(bs(curcom), (curcom * curcom + 1) * rm + 1, curcom * curcom)
  For ry = 0 To curcom - 1
    For rx = 0 To curcom - 1
      curblock(rx, ry) = Asc(Mid(bsc, ry * curcom + rx + 1, 1)) - Asc("0")
    Next
  Next

  'Edge generator
  generateedge
  oldx = -1000
End Sub

Sub generateedge()
  For ry = 0 To curcom - 1
    For rx = 0 To curcom - 1
      If curblock(rx, ry) <> 0 Then
        curblock(rx, ry) = &H10
        If rx = curcom - 1 Then 'Right edge
          curblock(rx, ry) = curblock(rx, ry) Or 1
        ElseIf curblock(rx + 1, ry) = 0 Then
          curblock(rx, ry) = curblock(rx, ry) Or 1
        End If
        If rx = 0 Then ' Left edge
          curblock(rx, ry) = curblock(rx, ry) Or 2
        ElseIf curblock(rx - 1, ry) = 0 Then
          curblock(rx, ry) = curblock(rx, ry) Or 2
        End If
        If ry = curcom - 1 Then 'Bottom edge
          curblock(rx, ry) = curblock(rx, ry) Or 4
        ElseIf curblock(rx, ry + 1) = 0 Then
          curblock(rx, ry) = curblock(rx, ry) Or 4
        End If
        If ry = 0 Then 'Top edge
          curblock(rx, ry) = curblock(rx, ry) Or 8
        ElseIf curblock(rx, ry - 1) = 0 Then
          curblock(rx, ry) = curblock(rx, ry) Or 8
        End If
      End If
    Next
  Next
End Sub

Sub mleft()
  Select Case canmove(x - 1, y)
    Case 0: x = x - 1: Exit Sub
    Case noleft:  Shift (-1)
  End Select
End Sub

Sub mright()
  Select Case canmove(x + 1, y)
    Case 0: x = x + 1: Exit Sub
    Case noright:  Shift (1)
  End Select
End Sub

Function mdown() As Boolean
  Select Case canmove(x, y + 1)
    Case 0:
      y = y + 1
      mdown = True
      Exit Function
    Case nobottom:
      mdown = shiftdown
  End Select
End Function

Sub Shift(d)
  Select Case d
    Case -1:
      For iy = 0 To curcom - 1
        If curblock(0, iy) <> 0 Then Exit Sub
      Next
      For iy = 0 To curcom - 1
        For ix = 1 To curcom - 1
          curblock(ix - 1, iy) = curblock(ix, iy)
        Next
        curblock(curcom - 1, iy) = 0
      Next
    Case 1:
      For iy = 0 To curcom - 1
        If curblock(curcom - 1, iy) <> 0 Then Exit Sub
      Next
      For iy = 0 To curcom - 1
        For ix = curcom - 1 To 1 Step -1
          curblock(ix, iy) = curblock(ix - 1, iy)
        Next
        curblock(0, iy) = 0
      Next
  End Select
End Sub

Function shiftdown() As Boolean
  For ix = 0 To curcom - 1
    If curblock(ix, curcom - 1) <> 0 Then
      shiftdown = False
      Exit Function
    End If
  Next
    For ix = 0 To curcom - 1
      For iy = curcom - 1 To 1 Step -1
        curblock(ix, iy) = curblock(ix, iy - 1)
      Next
    curblock(ix, 0) = 0
  Next
  shiftdown = True
End Function

Sub rotate(d)
  Dim xblock(maxcom, maxcom)
  'Another copy
  For cx = 0 To curcom - 1
    For cy = 0 To curcom - 1
      xblock(cx, cy) = curblock(cx, cy)
    Next
  Next
  If d = 0 Then
    'Rotate left
    For cx = 0 To curcom - 1
      For cy = 0 To curcom - 1
        curblock(cx, cy) = xblock(cy, cx)
      Next
    Next
  Else
    'Rotate right
    For cx = 0 To curcom - 1
      For cy = 0 To curcom - 1
        curblock(curcom - 1 - cx, cy) = xblock(cy, cx)
      Next
    Next
  End If

  If canmove(x, y) = 0 Then
    generateedge
    Exit Sub
  End If
  For cx = 0 To curcom - 1
    For cy = 0 To curcom - 1
      curblock(cx, cy) = xblock(cx, cy)
    Next
  Next
End Sub

Function canmove(x, y) As Integer
  If x < 0 Then
    canmove = noleft
    Exit Function
  ElseIf x + curcom > maxx Then
    canmove = noright
    Exit Function
  ElseIf y + curcom > maxy Then
    canmove = nobottom
    Exit Function
  End If

  For ix = 0 To curcom - 1
    For iy = 0 To curcom - 1
      If curblock(ix, iy) <> 0 And scrmap(x + ix, y + iy) <> 0 Then
        canmove = overblock
        Exit Function
      End If
    Next
  Next
  canmove = 0
End Function

Function fulllines() As Integer
  fulllines = 0
  For iy = 0 To maxy - 1
    thislinefull = True
    For ix = 0 To maxx - 1
      If scrmap(ix, iy) = 0 Then
        thislinefull = False
        Exit For
      End If
    Next
    If thislinefull = True Then
      fulllines = fulllines + 1
      If iy > 0 Then
        For zy = iy - 1 To 0 Step -1
          For zx = 0 To maxx - 1
            scrmap(zx, zy + 1) = scrmap(zx, zy)
          Next
        Next
      End If
      For zx = 0 To maxx - 1
        scrmap(zx, 0) = 0
      Next
    End If
  Next
End Function
Private Sub mnuPause_Click()
  If timer.Enabled = True Then
    timer.Enabled = False
    mnuPause.Caption = "&P恢复"
  Else
    timer.Enabled = True
    mnuPause.Caption = "&P暂停"
  End If
End Sub

Private Sub picPanel_KeyDown(KeyCode As Integer, Shift As Integer)
  Select Case KeyCode
    Case 37:
      mleft
    Case 39:
      mright
    Case 38:
      rotate 1
    Case 40:
      If mdown = False Then timer_Timer
  End Select
End Sub

Private Sub picSource_Paint()
  Const bw1 = 5
  Const bh1 = 5

  picSource.Line (0, 0)-(4 * bwidth - 1, 4 * bheight - 1), blockcolor, BF

  picSource.Line (2 * bwidth - bw1, 0)-(2 * bwidth + bw1 - 1, 4 * bheight - 1), blockedgecolor, BF
  picSource.Line (3 * bwidth, 0)-(3 * bwidth + bw1 - 1, 4 * bheight - 1), blockedgecolor, BF
  picSource.Line (4 * bwidth - bw1, 0)-(4 * bwidth - 1, 4 * bheight - 1), blockedgecolor, BF

  picSource.Line (0, 2 * bheight - bh1)-(4 * bwidth - 1, 2 * bheight + bh1 - 1), blockedgecolor, BF
  picSource.Line (0, 3 * bheight)-(4 * bwidth - 1, 3 * bheight + bh1 - 1), blockedgecolor, BF
  picSource.Line (0, 4 * bheight - bh1)-(4 * bwidth - 1, 4 * bheight - 1), blockedgecolor, BF

End Sub

Private Sub timer_Timer()
  yoff = yoff + 1
  If yoff >= offmax Then
    yoff = 0
    If mdown = False Then
      If x > maxx / 2 - curcom And x < maxx / 2 + curcom And y < 1 Then
        timer.Enabled = False
        ii = MsgBox("还玩么??", vbYesNo, "游戏结束 GAME OVER 游戏结束")
        If ii <> vbYes Then mnuExit_Click Else mnuGameNew_Click
        Exit Sub
      End If
      For ix = 0 To curcom - 1    'fix
        For iy = 0 To curcom - 1
          If (curblock(ix, iy) <> 0) Then
            scrmap(x + ix, y + iy) = curblock(ix, iy)
          End If
        Next
      Next
      If fulllines <> 0 Then
        score = score + 1
        mnuScore.Caption = Str(score)
        gamelevel = score / 30
        timer.Interval = 500 - (startgamelevel + gamelevel) * 5
        Me.Caption = "小积木 - 第" + Str(startgamelevel + gamelevel) + " 关"
        repaintall
      End If
      newblock
    End If
  End If
  repaint
End Sub

Private Sub mnuAbout_Click()
  frmAbout.Show
End Sub

Private Sub mnuExit_Click()
  End
End Sub

Private Sub mnuGameNew_Click()
  timer.Enabled = False
  frmOption.Show 1
  startgamelevel = Val(frmOption.txtStartLevel.Text)
  timer.Interval = 500 - startgamelevel * 5
  If (timer.Interval) < 2 Then timer.Interval = 2
  maxx = Val(frmOption.txtWidth.Text)
  maxy = Val(frmOption.txtHeight.Text)
  picPanel.Width = maxx * bwidth
  picPanel.Height = maxy * bheight
  Me.Width = picPanel.ScaleWidth + 450
  Me.Height = picPanel.ScaleHeight + 1000
  curcom = Val(frmOption.txtComplexity.Text)
  For ix = 0 To maxx - 1
    For iy = 0 To maxy - 1
      scrmap(ix, iy) = 0
    Next
  Next
  score = 0
  picSource_Paint
  newblock
  timer.Enabled = True
  mnuRedraw_Click
End Sub

Private Sub tmrPainter_Timer()
  repaint
End Sub

Private Sub mnuRedraw_Click()
  repaintall
End Sub
