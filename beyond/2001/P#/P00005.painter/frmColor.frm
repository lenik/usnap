VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form frmColor
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "ÑÕÉ«"
   ClientHeight    =   1755
   ClientLeft      =   45
   ClientTop       =   285
   ClientWidth     =   4665
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1755
   ScaleWidth      =   4665
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox ph
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   195
      Left            =   1140
      ScaleHeight     =   11
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   159
      TabIndex        =   19
      Top             =   840
      Width           =   2415
      Begin VB.Line lh
         BorderColor     =   &H00FFFFFF&
         DrawMode        =   7  'Invert
         X1              =   80
         X2              =   80
         Y1              =   0
         Y2              =   12
      End
   End
   Begin VB.TextBox th
      Appearance      =   0  'Flat
      Height          =   255
      Left            =   4080
      TabIndex        =   18
      Text            =   "0"
      Top             =   780
      Width           =   495
   End
   Begin VB.PictureBox ps
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   195
      Left            =   1140
      ScaleHeight     =   11
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   159
      TabIndex        =   17
      Top             =   1080
      Width           =   2415
      Begin VB.Line ls
         BorderColor     =   &H00FFFFFF&
         DrawMode        =   7  'Invert
         X1              =   80
         X2              =   80
         Y1              =   0
         Y2              =   12
      End
   End
   Begin VB.TextBox ts
      Appearance      =   0  'Flat
      Height          =   255
      Left            =   4080
      TabIndex        =   16
      Text            =   "0"
      Top             =   1020
      Width           =   495
   End
   Begin VB.PictureBox pv
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   195
      Left            =   1140
      ScaleHeight     =   11
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   159
      TabIndex        =   15
      Top             =   1320
      Width           =   2415
      Begin VB.Line lv
         BorderColor     =   &H00FFFFFF&
         DrawMode        =   7  'Invert
         X1              =   80
         X2              =   80
         Y1              =   0
         Y2              =   12
      End
   End
   Begin VB.TextBox tv
      Appearance      =   0  'Flat
      Height          =   255
      Left            =   4080
      TabIndex        =   14
      Text            =   "0"
      Top             =   1260
      Width           =   495
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   3000
      Top             =   240
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.TextBox tb
      Appearance      =   0  'Flat
      Height          =   255
      Left            =   4080
      TabIndex        =   13
      Text            =   "0"
      Top             =   480
      Width           =   495
   End
   Begin VB.PictureBox pb
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   195
      Left            =   1140
      ScaleHeight     =   11
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   159
      TabIndex        =   11
      Top             =   540
      Width           =   2415
      Begin VB.Line lb
         BorderColor     =   &H00FFFFFF&
         DrawMode        =   7  'Invert
         X1              =   80
         X2              =   80
         Y1              =   0
         Y2              =   12
      End
   End
   Begin VB.TextBox tg
      Appearance      =   0  'Flat
      Height          =   255
      Left            =   4080
      TabIndex        =   9
      Text            =   "0"
      Top             =   240
      Width           =   495
   End
   Begin VB.PictureBox pg
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   195
      Left            =   1140
      ScaleHeight     =   11
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   159
      TabIndex        =   7
      Top             =   300
      Width           =   2415
      Begin VB.Line lg
         BorderColor     =   &H00FFFFFF&
         DrawMode        =   7  'Invert
         X1              =   80
         X2              =   80
         Y1              =   0
         Y2              =   12
      End
   End
   Begin VB.TextBox tr
      Appearance      =   0  'Flat
      Height          =   255
      Left            =   4080
      TabIndex        =   5
      Text            =   "0"
      Top             =   0
      Width           =   495
   End
   Begin VB.PictureBox pr
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   195
      Left            =   1140
      ScaleHeight     =   11
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   159
      TabIndex        =   3
      Top             =   60
      Width           =   2415
      Begin VB.Line lr
         BorderColor     =   &H00FFFFFF&
         DrawMode        =   7  'Invert
         X1              =   80
         X2              =   80
         Y1              =   0
         Y2              =   12
      End
   End
   Begin VB.PictureBox pForeColor
      Appearance      =   0  'Flat
      BackColor       =   &H00FFFFFF&
      ForeColor       =   &H80000008&
      Height          =   375
      Left            =   120
      ScaleHeight     =   345
      ScaleWidth      =   345
      TabIndex        =   0
      Top             =   120
      Width           =   375
   End
   Begin VB.PictureBox pBackColor
      Appearance      =   0  'Flat
      BackColor       =   &H00000000&
      ForeColor       =   &H80000008&
      Height          =   375
      Left            =   300
      ScaleHeight     =   345
      ScaleWidth      =   345
      TabIndex        =   1
      Top             =   300
      Width           =   375
   End
   Begin VB.Label Label12
      AutoSize        =   -1  'True
      Caption         =   "H 0"
      Height          =   195
      Left            =   780
      TabIndex        =   25
      Top             =   840
      Width           =   255
   End
   Begin VB.Label Label11
      AutoSize        =   -1  'True
      Caption         =   "255"
      Height          =   195
      Left            =   3660
      TabIndex        =   24
      Top             =   840
      Width           =   270
   End
   Begin VB.Label Label10
      AutoSize        =   -1  'True
      Caption         =   "S 0"
      Height          =   195
      Left            =   780
      TabIndex        =   23
      Top             =   1080
      Width           =   240
   End
   Begin VB.Label Label9
      AutoSize        =   -1  'True
      Caption         =   "255"
      Height          =   195
      Left            =   3660
      TabIndex        =   22
      Top             =   1080
      Width           =   270
   End
   Begin VB.Label Label8
      AutoSize        =   -1  'True
      Caption         =   "V 0"
      Height          =   195
      Left            =   780
      TabIndex        =   21
      Top             =   1320
      Width           =   240
   End
   Begin VB.Label Label7
      AutoSize        =   -1  'True
      Caption         =   "255"
      Height          =   195
      Left            =   3660
      TabIndex        =   20
      Top             =   1320
      Width           =   270
   End
   Begin VB.Label Label6
      AutoSize        =   -1  'True
      Caption         =   "255"
      Height          =   195
      Left            =   3660
      TabIndex        =   12
      Top             =   540
      Width           =   270
   End
   Begin VB.Label Label5
      AutoSize        =   -1  'True
      Caption         =   "B 0"
      Height          =   195
      Left            =   780
      TabIndex        =   10
      Top             =   540
      Width           =   240
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      Caption         =   "255"
      Height          =   195
      Left            =   3660
      TabIndex        =   8
      Top             =   300
      Width           =   270
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "G 0"
      Height          =   195
      Left            =   780
      TabIndex        =   6
      Top             =   300
      Width           =   255
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "255"
      Height          =   195
      Left            =   3660
      TabIndex        =   4
      Top             =   60
      Width           =   270
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "R 0"
      Height          =   195
      Left            =   780
      TabIndex        =   2
      Top             =   60
      Width           =   255
   End
End
Attribute VB_Name = "frmColor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim p As PictureBox

Private Sub Form_Load()
        Set p = pForeColor
End Sub

Private Sub Form_Paint()
        Fresh
End Sub

Private Sub pBackColor_Click()
        pBackColor.ZOrder
        Set p = pBackColor

        Fresh
End Sub

Private Sub pBackColor_DblClick()
        cd.ShowColor
        p.BackColor = cd.color

        Fresh
End Sub

Private Sub pForeColor_Click()
        pForeColor.ZOrder
        Set p = pForeColor

        Fresh
End Sub

Private Sub pForeColor_DblClick()
        cd.ShowColor
        p.BackColor = cd.color

        Fresh
End Sub

Sub Fresh()
        Dim c, r0, r1, g0, g1, b0, b1
        c = p.BackColor
        r0 = FIBB_Rgb_To_Bgr(c And &HFFFF00)
        r1 = FIBB_Rgb_To_Bgr(c Or &HFF&)
        g0 = FIBB_Rgb_To_Bgr(c And &HFF00FF)
        g1 = FIBB_Rgb_To_Bgr(c Or &HFF00&)
        b0 = FIBB_Rgb_To_Bgr(c And &HFFFF&)
        b1 = FIBB_Rgb_To_Bgr(c Or &HFF0000)

        BitBltGradient pr.hdc, 0, 0, pr.ScaleWidth, pr.ScaleHeight, r0, r1, True
        BitBltGradient pg.hdc, 0, 0, pr.ScaleWidth, pr.ScaleHeight, g0, g1, True
        BitBltGradient pb.hdc, 0, 0, pr.ScaleWidth, pr.ScaleHeight, b0, b1, True

        tr = Int(c And &HFF&)
        tg = Int(c / &H100&) And &HFF&
        tb = Int(c / &H10000) And &HFF&

        lr.x1 = tr / 255 * pr.ScaleWidth: lr.X2 = lr.x1
        lg.x1 = tg / 255 * pg.ScaleWidth: lg.X2 = lg.x1
        lb.x1 = tb / 255 * pb.ScaleWidth: lb.X2 = lb.x1

        pr.Refresh
        pg.Refresh
        pb.Refresh

        ' RGB->HSV
        Dim r As Byte, g As Byte, b As Byte
        Dim h As Byte, s As Byte, v As Byte
        r = Int(c And &HFF&)
        g = Int(c / &H100&) And &HFF&
        b = Int(c / &H10000) And &HFF&
        RgbToHsv r, g, b, h, s, v
        lh.x1 = h / 255 * ph.ScaleWidth: lh.X2 = lh.x1
        ls.x1 = s / 255 * ps.ScaleWidth: ls.X2 = ls.x1
        lv.x1 = v / 255 * pv.ScaleWidth: lv.X2 = lv.x1

        Dim w
        For w = 0 To 255
                HsvToRgb w, s, v, r, g, b
                c = dwShl(b, 16) Or dwShl(g, 8) Or r
                ph.Line (w / 255 * ph.ScaleWidth, lh.y1)-(w / 255 * ph.ScaleWidth, lh.Y2), c
        Next
        For w = 0 To 255
                HsvToRgb h, w, v, r, g, b
                c = dwShl(b, 16) Or dwShl(g, 8) Or r
                ps.Line (w / 255 * ps.ScaleWidth, ls.y1)-(w / 255 * ps.ScaleWidth, ls.Y2), c
        Next
        For w = 0 To 255
                HsvToRgb h, v, w, r, g, b
                c = dwShl(b, 16) Or dwShl(g, 8) Or r
                pv.Line (w / 255 * pv.ScaleWidth, lv.y1)-(w / 255 * pv.ScaleWidth, lv.Y2), c
        Next
        'ph.Line (lh.x1, lh.y1)-(lh.X2, lh.Y2), c
        'ps.Line (ls.x1, ls.y1)-(ls.X2, ls.Y2), c
        'pv.Line (lv.x1, lv.y1)-(lv.X2, lv.Y2), c
        ph.Refresh
        ps.Refresh
        pv.Refresh
End Sub

Private Sub pr_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Not Button And vbLeftButton Then Exit Sub

        Dim c, a
        c = p.BackColor And &HFFFF00
        a = Int(x / pr.ScaleWidth * 255)
        If a >= 0 And a <= 255 Then
                c = c Or a
                p.BackColor = c

                Fresh
        End If
End Sub

Private Sub pg_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Not Button And vbLeftButton Then Exit Sub
        Dim c, a
        c = p.BackColor And &HFF00FF
        a = Int(x / pr.ScaleWidth * 255)
        If a >= 0 And a <= 255 Then
                c = c Or (a * &H100)
                p.BackColor = c

                Fresh
        End If
End Sub

Private Sub pb_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Not Button And vbLeftButton Then Exit Sub
        Dim c, a
        c = p.BackColor And &HFFFF&
        a = Int(x / pr.ScaleWidth * 255)
        If a >= 0 And a <= 255 Then
                c = c Or (a * &H10000)
                p.BackColor = c

                Fresh
        End If
End Sub
