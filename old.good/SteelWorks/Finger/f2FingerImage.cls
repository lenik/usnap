VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "fingerImage"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public X As Single, Y As Single, w As Single, h As Single
Public m_picScene As PictureBox
Public m_picBack As PictureBox
Public m_ImgType As Integer
Private m_onDraw As Boolean
Public Function dispSpec() As Boolean
        dispSpec = True
        With frmMain.picBack
                .FillStyle = 0
                .FillColor = &H606060
                .ForeColor = &HFFFFFF
                Ellipse .hdc, 113, 96, 173, 130
                .FillStyle = 1
                .FontName = "宋体"
                .FontSize = 16
                .FontBold = True
                .FontUnderline = True
                TextOut .hdc, 120, 101, "返回", 4

                .ForeColor = &HFF4040
                .FontName = "黑体"
                .FontSize = 32
                .FontBold = False
                .FontUnderline = False
                TextOut .hdc, 172, 117, "恭喜您完成测试!", 15

                .ForeColor = &H10AF10
                .FontName = "宋体"
                .FontSize = 20
                TextOut .hdc, 130, 220, "您的速度：", 10
                TextOut .hdc, 130, 300, "您的准确率：", 12
                BitBltGradient .hdc, 280, 220, fingerClient.CurrentSpeed * 2, 32, &HFFFFFF, &H8080FF, True
                BitBltGradient .hdc, 280, 300, fingerClient.CurrentAccuracy * 2, 32, &HFFFFFF, &H8080FF, True
                TextOut .hdc, 280 + fingerClient.CurrentSpeed, 220, fingerClient.CurrentSpeed & "CPM", getStringLengthA(fingerClient.CurrentSpeed & "CPM")
                TextOut .hdc, 280 + fingerClient.CurrentAccuracy, 300, fingerClient.CurrentAccuracy & "%", getStringLengthA(fingerClient.CurrentAccuracy & "%")

                .FontSize = 10
                .ForeColor = 0
                .Refresh
        End With
End Function

Public Function Paint() As Boolean
        Dim vh As Single
        Dim outstr As String

        Paint = True
        If m_onDraw Then Clear

        Select Case m_ImgType
        Case 0  ' 速度图
                vh = fingerClient.CurrentSpeed
                If vh > 70 Then vh = 70
                BitBltGradient m_picScene.hdc, X + 13, Y + 70 - vh, 27, vh, 0, &HFFFFFF, True
                outstr = "速度:" & Int(fingerClient.CurrentSpeed) & "cpm"
                TextOut m_picScene.hdc, X + 0, Y + 75, outstr, getStringLengthA(outstr)
        Case 1 ' 正确率
                vh = fingerClient.CurrentAccuracy * 0.7
                BitBltGradient m_picScene.hdc, X + 13, Y + 70 - vh, 27, vh, 0, &HFFFFFF, True
                outstr = "正确率:" & Int(fingerClient.CurrentAccuracy) & "%"
                TextOut m_picScene.hdc, X + 0, Y + 75, outstr, getStringLengthA(outstr)
        End Select
        m_onDraw = True
End Function

Public Function Clear() As Boolean
        Clear = True
        If m_onDraw Then Load X, Y, w, h
End Function

Private Sub Class_Initialize()
        m_onDraw = False
        m_ImgType = 0
        Set m_picScene = frmMain.picBack
        Set m_picBack = frmMain.picBack3
End Sub

Public Function Save(ByVal X As Long, ByVal Y As Long, ByVal w As Long, ByVal h As Long) As Boolean
        'Save = BitBlt(m_picBack.hdc, X, Y, w, h, m_picScene.hdc, X, Y, SRCCOPY)
End Function
Public Function Load(ByVal X As Long, ByVal Y As Long, ByVal w As Long, ByVal h As Long) As Boolean
        Load = BitBlt(m_picScene.hdc, X, Y, w, h, m_picBack.hdc, X, Y, SRCCOPY)
End Function

Private Sub Class_Terminate()
        Clear
        Set m_picScene = Nothing
        Set m_picBack = Nothing
End Sub
