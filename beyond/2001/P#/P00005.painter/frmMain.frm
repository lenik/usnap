VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form frmMain
   Appearance      =   0  'Flat
   BackColor       =   &H00FFFFFF&
   Caption         =   "painter"
   ClientHeight    =   3930
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   5610
   LinkTopic       =   "Form1"
   ScaleHeight     =   3930
   ScaleWidth      =   5610
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox p2
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   450
      Left            =   720
      ScaleHeight     =   28
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   30
      TabIndex        =   2
      Top             =   465
      Visible         =   0   'False
      Width           =   480
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   105
      Top             =   120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
      DefaultExt      =   "bmp"
      Filter          =   "BMPλͼ�ļ�|*.bmp||"
      Flags           =   1
   End
   Begin VB.PictureBox p
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H00000000&
      BorderStyle     =   0  'None
      FillStyle       =   0  'Solid
      ForeColor       =   &H80000008&
      Height          =   2775
      Left            =   600
      MousePointer    =   2  'Cross
      ScaleHeight     =   185
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   297
      TabIndex        =   1
      Top             =   360
      Width           =   4455
   End
   Begin MSComctlLib.StatusBar st
      Align           =   2  'Align Bottom
      Height          =   345
      Left            =   0
      TabIndex        =   0
      Top             =   3585
      Width           =   5610
      _ExtentX        =   9895
      _ExtentY        =   609
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628}
         NumPanels       =   2
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628}
            Object.Width           =   2187
            MinWidth        =   2187
         EndProperty
         BeginProperty Panel2 {8E3867AB-8586-11D1-B16A-00C0F0283628}
            AutoSize        =   2
            Bevel           =   0
         EndProperty
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin VB.Menu mFile
      Caption         =   "�ļ�(&F)"
      Begin VB.Menu mNew
         Caption         =   "�½�"
         Shortcut        =   ^N
      End
      Begin VB.Menu mOpen
         Caption         =   "��..."
         Shortcut        =   ^O
      End
      Begin VB.Menu mSave
         Caption         =   "����..."
         Shortcut        =   ^S
      End
      Begin VB.Menu mline11
         Caption         =   "-"
      End
      Begin VB.Menu mPrintSetup
         Caption         =   "��ӡ����"
      End
      Begin VB.Menu mPrint
         Caption         =   "��ӡ"
         Shortcut        =   ^P
      End
      Begin VB.Menu mline12
         Caption         =   "-"
      End
      Begin VB.Menu mExit
         Caption         =   "�˳�"
         Shortcut        =   ^{F4}
      End
   End
   Begin VB.Menu mEdit
      Caption         =   "�༭(&E)"
      Begin VB.Menu mUndo
         Caption         =   "����"
         Shortcut        =   ^Z
      End
      Begin VB.Menu mReundo
         Caption         =   "�ظ�"
         Shortcut        =   {F4}
      End
      Begin VB.Menu mline21
         Caption         =   "-"
      End
      Begin VB.Menu mCopy
         Caption         =   "����"
         Shortcut        =   ^C
      End
      Begin VB.Menu mCut
         Caption         =   "����"
         Shortcut        =   ^X
      End
      Begin VB.Menu mPaste
         Caption         =   "ճ��"
         Shortcut        =   ^V
      End
   End
   Begin VB.Menu mView
      Caption         =   "��ͼ(&V)"
      Begin VB.Menu mDraw
         Caption         =   "����"
      End
      Begin VB.Menu mModify
         Caption         =   "�޸�"
      End
      Begin VB.Menu mProcess
         Caption         =   "����"
      End
      Begin VB.Menu mColor
         Caption         =   "��ɫ"
      End
      Begin VB.Menu mline31
         Caption         =   "-"
      End
      Begin VB.Menu mRotateOption
         Caption         =   "��תѡ��"
      End
      Begin VB.Menu mSkewOption
         Caption         =   "��бѡ��"
      End
      Begin VB.Menu mBlurOptions
         Caption         =   "ģ��ѡ��"
      End
      Begin VB.Menu mFont
         Caption         =   "����"
      End
   End
   Begin VB.Menu mOption
      Caption         =   "ѡ��(&O)"
      Begin VB.Menu mmode
         Caption         =   "ʹ��͸��ɫ"
      End
   End
   Begin VB.Menu mHelp
      Caption         =   "����(&H)"
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit '������ñ��������ÿ������֮����ʹ��������������Ҫ�õı���û��������
                  '�򷢳�һ��������Ϣ�����ʡ�Ը���䣬��VB������Ҫ�Զ����ɱ�����

Dim dshow As Boolean
Dim oldx0, oldy0, oldx1, oldy1
Dim oldtext
Dim scalestep

Sub dline(x0, y0, x1, y1)
        If dshow Then clearline
        p.DrawMode = 7  ' xor
        p.Line (x0, y0)-(x1, y1)
        oldx0 = x0: oldy0 = y0
        oldx1 = x1: oldy1 = y1
        p.DrawMode = 13 ' copy
        dshow = True

End Sub
Sub clearline()
        If dshow Then
                p.DrawMode = 7
                p.Line (oldx0, oldy0)-(oldx1, oldy1)
                dshow = False
                p.DrawMode = 13
        End If
End Sub

Sub drect(x0, y0, x1, y1)
        If dshow Then clearrect
        p.DrawMode = 7
        p.Line (x0, y0)-(x1, y1), , B
        oldx0 = x0: oldy0 = y0
        oldx1 = x1: oldy1 = y1
        p.DrawMode = 13
        dshow = True
End Sub
Sub clearrect()
        If dshow Then
                p.DrawMode = 7
                p.Line (oldx0, oldy0)-(oldx1, oldy1), , B
                dshow = False
                p.DrawMode = 13
        End If
End Sub

Sub dellipse(x0, y0, x1, y1)
        If dshow Then clearellipse
        p.DrawMode = 7

        Ellipse p.hdc, x0, y0, x1, y1

        oldx0 = x0: oldy0 = y0
        oldx1 = x1: oldy1 = y1
        p.DrawMode = 13
        dshow = True
End Sub
Sub clearellipse()
        If dshow Then
                p.DrawMode = 7
                Ellipse p.hdc, oldx0, oldy0, oldx1, oldy1
                dshow = False
                p.DrawMode = 13
        End If
End Sub

Sub dbezier()
        If dshow Then clearbezier
        p.DrawMode = 7

        bezier

        Dim i
        For i = 0 To pn
                oldpx(i) = px(i)
                oldpy(i) = py(i)
        Next
        oldpn = pn
        p.DrawMode = 13
        dshow = True
End Sub
Sub clearbezier()
        If dshow Then
                p.DrawMode = 7
                oldbezier
                dshow = False
                p.DrawMode = 13
        End If
End Sub

Private Sub Form_Load()
        frmDraw.Show
        frmModify.Show
        frmProcess.Show
        frmColor.Show

        SetWindowPos frmDraw.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE
        SetWindowPos frmModify.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE
        SetWindowPos frmProcess.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE
        SetWindowPos frmColor.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE

        frmMain.Left = GetSetting("painter", "pos", "frmmainx", frmMain.Left)
        frmMain.Top = GetSetting("painter", "pos", "frmmainy", frmMain.Top)
        frmDraw.Left = GetSetting("painter", "pos", "frmdrawx", frmDraw.Left)
        frmDraw.Top = GetSetting("painter", "pos", "frmdrawy", frmDraw.Top)
        frmModify.Left = GetSetting("painter", "pos", "frmmodifyx", frmModify.Left)
        frmModify.Top = GetSetting("painter", "pos", "frmmodifyy", frmModify.Top)
        frmProcess.Left = GetSetting("painter", "pos", "frmprocessx", frmProcess.Left)
        frmProcess.Top = GetSetting("painter", "pos", "frmprocessy", frmProcess.Top)
        frmColor.Left = GetSetting("painter", "pos", "frmcolorx", frmColor.Left)
        frmColor.Top = GetSetting("painter", "pos", "frmcolory", frmColor.Top)

        Op = OP_NONE
        dshow = False
        scalestep = 0
End Sub

Private Sub Form_Resize()
        On Error Resume Next  '������С��ʱ�������ִ���ʱ����ִ�д����е��������
        p.Left = 0
        p.Top = 0
        p.width = width - 145
        p.height = height - 1050
        p2.Left = p.Left
        p2.Top = p.Top
        p2.width = p.width
        p2.height = p.height
End Sub

Private Sub Form_Unload(Cancel As Integer)
        SaveSetting "painter", "pos", "frmmainx", frmMain.Left
        SaveSetting "painter", "pos", "frmmainy", frmMain.Top
        SaveSetting "painter", "pos", "frmdrawx", frmDraw.Left
        SaveSetting "painter", "pos", "frmdrawy", frmDraw.Top
        SaveSetting "painter", "pos", "frmmodifyx", frmModify.Left
        SaveSetting "painter", "pos", "frmmodifyy", frmModify.Top
        SaveSetting "painter", "pos", "frmprocessx", frmProcess.Left
        SaveSetting "painter", "pos", "frmprocessy", frmProcess.Top
        SaveSetting "painter", "pos", "frmcolorx", frmColor.Left
        SaveSetting "painter", "pos", "frmcolory", frmColor.Top
        End '���ر�������ʱ�������û�����Ҳȫ���ر�
End Sub

Private Sub mBlurOptions_Click()
        frmBlurOption.Show
End Sub

Private Sub mColor_Click()
        frmColor.Show
End Sub

Private Sub mCopy_Click()
        Dim i
        For i = 1 To frmDraw.tb.Buttons.Count
                frmDraw.tb.Buttons.Item(i).Value = tbrUnpressed
        Next
        For i = 1 To frmModify.tb.Buttons.Count
                frmModify.tb.Buttons.Item(i).Value = tbrUnpressed
        Next
        For i = 1 To frmProcess.tb.Buttons.Count
                frmProcess.tb.Buttons.Item(i).Value = tbrUnpressed
        Next

        frmMain.st.Panels(1) = "����"
        frmMain.st.Panels(2) = "����ѡ��ľ�������"

        Op = OP_COPY
End Sub

Private Sub mCut_Click()
        Dim i
        For i = 1 To frmDraw.tb.Buttons.Count
                frmDraw.tb.Buttons.Item(i).Value = tbrUnpressed
        Next
        For i = 1 To frmModify.tb.Buttons.Count
                frmModify.tb.Buttons.Item(i).Value = tbrUnpressed
        Next
        For i = 1 To frmProcess.tb.Buttons.Count
                frmProcess.tb.Buttons.Item(i).Value = tbrUnpressed
        Next

        frmMain.st.Panels(1) = "����"
        frmMain.st.Panels(2) = "����ѡ��ľ�������"

        Op = OP_CUT
End Sub

Private Sub mDraw_Click()
        frmDraw.Show
End Sub

Private Sub mExit_Click()
        Unload Me
End Sub

Private Sub mFont_Click()
        On Error GoTo x
        cd.ShowFont
        p.FontBold = cd.FontBold
        p.FontItalic = cd.FontItalic
        p.FontName = cd.FontName
        p.FontSize = cd.FontSize
        p.FontStrikethru = cd.FontStrikethru
        Exit Sub
x:
End Sub

Private Sub mHelp_Click()
        MsgBox "painter by ruiwan"
End Sub

Private Sub mmode_Click()
    mmode.Checked = Not mmode.Checked
    p.FillStyle = IIf(mmode.Checked, 1, 0)  '0��ʾ�����ʽΪʵ�ģ�1��ʾ����
End Sub

Private Sub mModify_Click()
        frmModify.Show
End Sub

Private Sub mNew_Click()
        Set p.Picture = Nothing 'Nothingֵ�ڶ�����ʹ�ã���ʾ���������δ��ʼ����
                                  '����ʾ�ж϶�������������Ĺ�����ϵ��
End Sub

Private Sub mOpen_Click()
        On Error GoTo x  '�ڴ򿪶Ի������������ȡ������ť���˳��򿪲���
        cd.Filter = "RWͼ���ļ�|*.rw|BMPλͼ�ļ�|*.bmp||"

        cd.ShowOpen
        If LCase(Mid(cd.FileName, InStr(cd.FileName, "."))) = ".bmp" Then
             Set p.Picture = LoadPicture(cd.FileName)
        Else
           Dim fn, w, h
            fn = FreeFile '����һ�� Integer��������һ���ɹ� Open ���ʹ�õ��ļ���
                          'ʹ�� FreeFile �����ɵõ���һ�����õ��ļ���

            '���δָ����ʽ������ Random ���ʷ�ʽ���ļ�
            Open cd.FileName For Binary As #fn Len = 4
            Get #fn, , w  '��һ���Ѵ򿪵Ĵ����ļ�����һ������֮��
            Get #fn, , h   '��ʡ�� recnumber��������������һ�� Get �� Put ���֮�����һ����¼���ֽ�
            BitBltFn p.hdc, 0, 0, w - 1, h - 1, 0, 0, 0, BITBLT_EXTEND Or BITBLT_ONLYDEST, AddressOf loadimage, fn
            Close #fn
        End If
        p.Refresh
x:
End Sub

Private Sub mPaste_Click()
        Dim i
        For i = 1 To frmDraw.tb.Buttons.Count
                frmDraw.tb.Buttons.Item(i).Value = tbrUnpressed
        Next
        For i = 1 To frmModify.tb.Buttons.Count
                frmModify.tb.Buttons.Item(i).Value = tbrUnpressed
        Next
        For i = 1 To frmProcess.tb.Buttons.Count
                frmProcess.tb.Buttons.Item(i).Value = tbrUnpressed
        Next

        frmMain.st.Panels(1) = "ճ��"
        frmMain.st.Panels(2) = "��ָ��λ��ճ��"

        Op = OP_PASTE
End Sub

Private Sub mPrintSetup_Click()
        On Error Resume Next
        cd.ShowPrinter
        PrintWindow p.hwnd, p.hdc, 0
End Sub

Private Sub mProcess_Click()
        frmProcess.Show
End Sub

Private Sub mRotateOption_Click()
        frmRotateOption.Show
End Sub

Private Sub mSave_Click()
        On Error GoTo x
        cd.Filter = "RWͼ���ļ�|*.rw||"
        cd.ShowSave
        Dim fn, w, h
        fn = FreeFile
        w = p.ScaleWidth
        h = p.ScaleHeight

        Open cd.FileName For Binary As #fn Len = 4
        Put #fn, , w
        Put #fn, , h
        BitBltFn p.hdc, 0, 0, w - 1, h - 1, 0, 0, 0, BITBLT_EXTEND Or BITBLT_ONLYDEST, AddressOf saveimage, fn
        Close #fn


        Exit Sub
x:
End Sub

Private Sub mSkewOption_Click()
        frmSkewOption.Show
End Sub

Private Sub p_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        x0 = x
        y0 = y
        p.CurrentX = x
        p.CurrentY = y

        If scalestep = 0 Then
                oldtext = st.Panels(2)
        End If

        Select Case Op
        Case OP_PIXEL
        Case OP_LINE
                st.Panels(2) = "�ƶ���굽��һ��λ�ò��ſ���һ��ֱ��"
        Case OP_RECT
                st.Panels(2) = "�ƶ���굽��һ��λ�ò��ſ���һ������"
        Case OP_ELLIPSE
                st.Panels(2) = "�ƶ���굽��һ��λ�ò��ſ���һ����Բ"
        Case OP_BEZIER
                st.Panels(2) = "�ƶ����ȷ��һ��bezier���Ƶ�"
        Case OP_TEXT
                st.Panels(2) = "����Ļ�ϵ������ָ���������λ��"
        Case OP_SCALE
                If scalestep = 0 Then
                        st.Panels(2) = "�϶����ѡ��Դ��������"
                End If
        Case OP_ROTATE, OP_MIRRORH, OP_MIRRORV, OP_SKEW
                st.Panels(2) = "�ƶ���굽��һ��λ�ò��ſ�ѡ��һ���������Ŀ�"
        Case OP_GRADH, OP_GRADV, OP_BLUR
                st.Panels(2) = "�ƶ���굽��һ��λ�ò��ſ�ѡ��һ��������Ŀ�"
        Case OP_COPY
                st.Panels(2) = "�ƶ���굽��һ��λ�ò��ſ�ѡ��һ�������ƵĿ�"
        Case OP_CUT
                st.Panels(2) = "�ƶ���굽��һ��λ�ò��ſ�ѡ��һ�������еĿ�"
        Case OP_PASTE
                st.Panels(2) = "�ſ���꼴��ճ��"
        End Select
End Sub

Private Sub p_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Button = 0 Then Exit Sub

        Dim xx
        If Button And vbLeftButton Then
                p.ForeColor = frmColor.pForeColor.BackColor
                p.FillColor = frmColor.pBackColor.BackColor
        Else
                p.ForeColor = frmColor.pBackColor.BackColor
                p.FillColor = frmColor.pForeColor.BackColor
        End If

        Select Case Op
        Case OP_PIXEL
                p.Line -(x, y)
                x0 = x: y0 = y
        Case OP_LINE
                dline x0, y0, x, y
        Case OP_RECT
                drect x0, y0, x, y
        Case OP_ELLIPSE
                dellipse x0, y0, x, y
        Case OP_BEZIER
                px(pn) = x
                py(pn) = y
                dbezier
        Case OP_SCALE, OP_MIRRORH, OP_MIRRORV, OP_SKEW
                drect x0, y0, x, y
        Case OP_ROTATE
                If Abs(x - x0) < Abs(y - y0) Then
                        xx = x - x0
                Else
                        xx = y - y0
                End If
                drect x0, y0, x0 + xx, y0 + xx
        Case OP_GRADH, OP_GRADV, OP_BLUR
                drect x0, y0, x, y
        Case OP_COPY, OP_CUT
                drect x0, y0, x, y
        End Select

        p.Refresh
End Sub

Private Sub p_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
        Dim xx
        If Button And vbLeftButton Then
                p.ForeColor = frmColor.pForeColor.BackColor
                p.FillColor = frmColor.pBackColor.BackColor
        Else
                p.ForeColor = frmColor.pBackColor.BackColor
                p.FillColor = frmColor.pForeColor.BackColor
        End If

        Select Case Op
        Case OP_LINE
                clearline
                p.Line (x0, y0)-(x, y)
        Case OP_RECT
                clearrect
                p.Line (x0, y0)-(x, y), , B
        Case OP_ELLIPSE
                clearellipse
                Ellipse p.hdc, x0, y0, x, y
        Case OP_BEZIER
                clearbezier
                px(pn) = x
                py(pn) = y
                bezier
                pn = pn + 1
        Case OP_TEXT
                xx = InputBox("����Ҫ���Ƶ�����:", , "abcdefg")
                TextOut p.hdc, x, y, xx, Len(xx)
        Case OP_SCALE
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                If scalestep = 0 Then
                        scalefromx0 = x0
                        scalefromy0 = y0
                        scalefromx1 = x
                        scalefromy1 = y
                        scalestep = 1
                ElseIf scalestep = 1 Then
                        scaletox0 = x0
                        scaletoy0 = y0
                        scaletox1 = x
                        scaletoy1 = y
                        scalestep = 0

                        Dim ux0, uy0, ux1, uy1
                        ux0 = IIf(scalefromx0 < scaletox0, scalefromx0, scaletox0)
                        uy0 = IIf(scalefromy0 < scaletoy0, scalefromy0, scaletoy0)
                        ux1 = IIf(scalefromx1 > scaletox1, scalefromx1, scaletox1)
                        uy1 = IIf(scalefromy1 > scaletoy1, scalefromy1, scaletoy1)
                        'IIF�Ǹ��ڲ��������Ե�һ����Ԫ��ֵ�����IIFΪTrue,�򷵻صڶ���
                        '����Ԫ�����ΪFalse���򷵻ص�������Ԫ
                        scalefromx0 = scalefromx0 - ux0
                        scalefromy0 = scalefromy0 - uy0
                        scalefromx1 = scalefromx1 - ux0
                        scalefromy1 = scalefromy1 - uy0
                        scaletox0 = scaletox0 - ux0
                        scaletoy0 = scaletoy0 - uy0
                        scaletox1 = scaletox1 - ux0
                        scaletoy1 = scaletoy1 - uy0

                        BitBltFn p.hdc, ux0, uy0, ux1 - ux0 + 1, uy1 - uy0 + 1, 0, 0, 0, _
                                BITBLT_EXTEND Or BITBLT_ONLYDEST, _
                                AddressOf scaleimage, _
                                0
                End If
        Case OP_ROTATE
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                If x - x0 > y - y0 Then x = x0 + y - y0

                If frmRotateOption.Visible = False Then frmRotateOption.Show 1  'ֻ�е���ʾ��ת����ʱ�Ұ���ȷ��������ת
                If frmRotateOption.opt90.Value Then xx = 90
                If frmRotateOption.opt180.Value Then xx = 180
                If frmRotateOption.opt270.Value Then xx = 270
                BitBltFn p.hdc, x0, y0, x - x0 + 1, x - x0 + 1, 0, 0, 0, _
                        BITBLT_ONLYDEST Or BITBLT_EXTEND, _
                        AddressOf rotate, xx

        Case OP_MIRRORH
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                BitBltFn p.hdc, x0, y0, x - x0 + 1, y - y0 + 1, 0, 0, 0, _
                        BITBLT_ONLYDEST Or BITBLT_EXTEND, _
                        AddressOf mirrorh, 0
        Case OP_MIRRORV
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                BitBltFn p.hdc, x0, y0, x - x0 + 1, y - y0 + 1, 0, 0, 0, _
                        BITBLT_ONLYDEST Or BITBLT_EXTEND, _
                        AddressOf mirrorv, 0
        Case OP_SKEW
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                If frmSkewOption.Visible = False Then frmSkewOption.Show 1
                If frmSkewOption.optp45.Value Then xx = 45
                If frmSkewOption.optn45.Value Then xx = -45

                Dim xx0
                If xx < 0 Then
                    xx0 = x0 - (y - y0 + 1)
                Else
                    xx0 = x0
                End If
                BitBltFn _
                        p.hdc, xx0, y0, x - x0 + 1 + y - y0 + 1, y - y0 + 1, _
                        0, 0, 0, _
                        BITBLT_EXTEND Or BITBLT_ONLYDEST, _
                        AddressOf skew, _
                        xx
        Case OP_GRADH
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                BitBltGradient p.hdc, x0, y0, x - x0 + 1, y - y0 + 1, _
                        FIBB_Rgb_To_Bgr(p.ForeColor), _
                        FIBB_Rgb_To_Bgr(p.FillColor), False
        Case OP_GRADV
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                BitBltGradient p.hdc, x0, y0, x - x0 + 1, y - y0 + 1, _
                        FIBB_Rgb_To_Bgr(p.ForeColor), _
                        FIBB_Rgb_To_Bgr(p.FillColor), True
        Case OP_BLUR
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                If frmBlurOption.Visible = False Then frmBlurOption.Show 1
                BitBltBlur p.hdc, x0, y0, x - x0 + 1, y - y0 + 1, _
                        256 * frmBlurOption.sDepth.Value + 127 + frmBlurOption.sLevel.Value
        Case OP_COPY
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                BitBlt p2.hdc, 0, 0, x - x0 + 1, y - y0 + 1, p.hdc, x0, y0, SRCCOPY
                copyw = x - x0 + 1
                copyh = y - y0 + 1
        Case OP_CUT
                clearrect
                If x < x0 Then xx = x: x = x0: x0 = xx
                If y < y0 Then xx = y: y = y0: y0 = xx
                BitBlt p2.hdc, 0, 0, x - x0 + 1, y - y0 + 1, p.hdc, x0, y0, SRCCOPY
                copyw = x - x0 + 1
                copyh = y - y0 + 1
                p.Line (x0, y0)-(x, y), p.FillColor, BF
        Case OP_PASTE
                BitBlt p.hdc, x, y, copyw, copyh, p2.hdc, 0, 0, SRCCOPY
        End Select

        If scalestep = 0 Then
                st.Panels(2) = oldtext
        Else
                st.Panels(2) = "�϶����ѡ��Ŀ����������"
        End If

        p.Refresh
End Sub
