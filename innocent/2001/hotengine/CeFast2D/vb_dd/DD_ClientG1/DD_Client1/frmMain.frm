VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   4170
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6255
   LinkTopic       =   "Form1"
   ScaleHeight     =   278
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   417
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton cmdDDcommands
      Caption         =   "dd commands"
      Height          =   600
      Left            =   3405
      TabIndex        =   3
      Top             =   1110
      Width           =   2415
   End
   Begin VB.CommandButton cmdHDCcommands
      Caption         =   "hdc commands"
      Height          =   525
      Left            =   3420
      TabIndex        =   2
      Top             =   255
      Width           =   2415
   End
   Begin VB.CommandButton cmdinitWindow
      Caption         =   "init window"
      Height          =   570
      Left            =   420
      TabIndex        =   1
      Top             =   1110
      Width           =   2445
   End
   Begin VB.CommandButton cmdinitFullscreen
      Caption         =   "init fullscreen"
      Height          =   570
      Left            =   420
      TabIndex        =   0
      Top             =   255
      Width           =   2445
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public bDown As Boolean, xDown As Single, yDown As Single

Const PI As Double = 3.14159265358979

Public Sub ddInit()
        Set lpdd = Nothing
        Set lpddsPrimary = Nothing
        Set lpddsBack = Nothing
        Set lpddc = Nothing
End Sub

Private Sub cmdDDcommands_Click()
        lpddsPrimary.DrawEllipse 0, 0, 400, 300
End Sub

Private Sub cmdHDCcommands_Click()
        Dim dc As Long
        dc = lpddsPrimary.GetDC
                SetBkColor dc, rgb(0, 0, 0)
                SetTextColor dc, rgb(255, 255, 255)
                TextOut dc, 10, 40, "Hello, world!", 13
                TextOut dc, 20, 70, "Hello, world!", 13
                TextOut dc, 30, 90, "Hello, world!", 13
                TextOut dc, 40, 140, "Hello, world!", 13
                TextOut dc, 50, 240, "Hello, world!", 13
                TextOut dc, 60, 340, "Hello, world!", 13
        lpddsPrimary.ReleaseDC dc
End Sub

Private Sub cmdinitFullscreen_Click()
        Dim dd As DDSURFACEDESC2
        Dim caps As DDSCAPS2

        ddInit
        Set lpdd = dx.DirectDrawCreate(vbNullString)
        lpdd.SetCooperativeLevel Me.hwnd, DDSCL_FULLSCREEN Or DDSCL_EXCLUSIVE
        lpdd.SetDisplayMode 800, 600, 32, 0, 0

        dd.lFlags = DDSD_CAPS Or DDSD_BACKBUFFERCOUNT
        dd.lBackBufferCount = 1
        dd.ddsCaps.lCaps = DDSCAPS_PRIMARYSURFACE Or _
                                DDSCAPS_COMPLEX Or _
                                DDSCAPS_FLIP
        caps.lCaps = DDSCAPS_BACKBUFFER

        Set lpddsPrimary = lpdd.CreateSurface(dd)
        Set lpddsBack = lpddsPrimary.GetAttachedSurface(caps)

        Dim clipRect(0 To 0) As DxVBLib.RECT
        clipRect(0).Left = 100
        clipRect(0).Top = 100
        clipRect(0).Right = 200
        clipRect(0).Bottom = 200
        Set lpddc = lpdd.CreateClipper(0)
        lpddc.SetClipList 1, clipRect
        'lpddc.SetHWnd Me.hWnd
        lpddsPrimary.SetClipper lpddc

End Sub

Private Sub cmdinitWindow_Click()
        Dim dd As DDSURFACEDESC2
        Dim caps As DDSCAPS2

        ddInit
        Set lpdd = dx.DirectDrawCreate(vbNullString)
        lpdd.SetCooperativeLevel Me.hwnd, DDSCL_NORMAL

        dd.lFlags = DDSD_CAPS
        dd.ddsCaps.lCaps = DDSCAPS_PRIMARYSURFACE

        Set lpddsPrimary = lpdd.CreateSurface(dd)

        Dim clipRect(0 To 2) As DxVBLib.RECT
        clipRect(0).Left = 100
        clipRect(0).Top = 100
        clipRect(0).Right = 200
        clipRect(0).Bottom = 200
        Set lpddc = lpdd.CreateClipper(0)
        'lpddc.SetClipList 1, clipRect
        lpddc.SetHWnd Me.hwnd
        lpddsPrimary.SetClipper lpddc

        Dim srcrect As DxVBLib.RECT, destrect As DxVBLib.RECT
        srcrect.Left = 10
        srcrect.Top = 10
        srcrect.Right = 500
        srcrect.Bottom = 400
        destrect.Left = 0
        destrect.Top = 0
        destrect.Right = 490
        destrect.Bottom = 390
        lpddsPrimary.Blt destrect, lpddsPrimary, srcrect, DDBLT_WAIT
        'lpddsPrimary.BltFast destrect.Left, destrect.Top, lpddsPrimary, srcrect, _
                        DDBLTFAST_NOCOLORKEY Or DDBLTFAST_WAIT

End Sub

Public Sub ddpx(Optional ByVal i As String = "x")
        Dim r As Double
        Dim c As Long
        Dim rw As Double, rh As Double
        Dim L As Double

        c = rgb(Rnd * 256, Rnd * 256, Rnd * 256)

        rw = MouseX - 400
        rh = MouseY - 200
        If rw = 0 Then
                r = Sgn(-rh) * PI / 2
                If r < 0 Then r = r + 2 * PI
        Else
                r = Atn(rh / rw)
        End If

        lpddsPrimary.SetForeColor c
        lpddsPrimary.DrawCircle MouseX, MouseY, 3


        r = r + 0.02
        L = Sqr(rw * rw + rh * rh)
        MouseX = L * Cos(r) + 400
        MouseY = L * Sin(r) + 200

End Sub
Public Sub ddpx2(Optional ByVal i As String = "x")
        Dim destrect As DxVBLib.RECT
        Dim desc As DDSURFACEDESC2
        Dim c As Long

        c = rgb(Rnd * 256, Rnd * 256, Rnd * 256)

        'lpddsPrimary.Lock destrect, desc, DDLOCK_SURFACEMEMORYPTR, ByVal 0
        '        lpddsPrimary.SetLockedPixel MouseX, MouseY, c
        'lpddsPrimary.Unlock destrect

        lpddsPrimary.SetForeColor c
        lpddsPrimary.DrawCircle MouseX, MouseY, 10

        Select Case i
        Case "x"
                MouseX = MouseX + 1
        Case "X"
                MouseX = MouseX - 1
        Case "y"
                MouseY = MouseY + 1
        Case "Y"
                MouseY = MouseY - 1
        End Select
End Sub

Private Sub Form_Load()
        cmdinitWindow_Click
End Sub

Private Sub Form_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        bDown = True
        xDown = X
        yDown = Y

        Dim c As String
        c = IIf(Button And vbRightButton, "y", "x")
        If Shift And vbCtrlMask Then c = UCase(c)
        ddpx c
End Sub
Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        If bDown Then
                Dim c As String
                c = IIf(Button And vbRightButton, "y", "x")
                If Shift And vbCtrlMask Then c = UCase(c)

                ddpx c
        End If
End Sub
Private Sub Form_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
        bDown = False
End Sub
