Attribute VB_Name = "modEText"
Option Explicit
Public info As String

' ÎÄ×ÖÐ§¹û
Public Const ETEXT_DIR_HORIZ = 0
Public Const ETEXT_DIR_VERT = 1

'Public Const debugClass As Boolean = True
Public Const debugClass As Boolean = False

Public winDir As String, sysDir As String

Public Function initSysDir() As Boolean
        Dim sdbuf As String * 512
        Dim r As Boolean
        winDir = "C:\Windows"
        sysDir = "C:\Windows\System"
        r = GetWindowsDirectory(sdbuf, 500)
        If r Then winDir = Trim(sdbuf)
        r = GetSystemDirectory(sdbuf, 500)
        If r Then sysDir = Trim(sdbuf)
        initSysDir = r
End Function

Public Function copyEChar(r As EasyChar, o_o As EasyChar, Optional ByVal copyDrawState As Boolean = True, Optional ByVal copyContent As Boolean = True) As EasyChar
        If o_o Is Nothing Then Exit Function
        r.SetOwnerText Nothing, 0
        With o_o
                If copyContent Then
                        r.Content = .Content
                Else
                        r.Content = " "
                End If

                r.Font = .Font
                r.Size = .Size
                r.Bold = .Bold
                r.Italic = .Italic
                r.Underline = .Underline
                r.Strikethrough = .Strikethrough
                r.Break = .Break

                r.ForeColor = .ForeColor
                r.BackColor = .BackColor
                r.HasGradient = .HasGradient
                r.GradientC1 = .GradientC1
                r.GradientC2 = .GradientC2
                r.GradientDirection = .GradientDirection
                r.GradientLoop = .GradientLoop

                If copyDrawState Then
                        r.m_AuxX = o_o.m_AuxX
                        r.m_AuxY = o_o.m_AuxY
                        r.m_AuxOnDraw = o_o.m_AuxOnDraw

                        r.DrawExtentW = .DrawExtentW
                        r.DrawExtentH = .DrawExtentH
                        r.DrawContent = .DrawContent
                End If

                r.SetOwnerText .OwnerText, .CID
        End With
        Set copyEChar = r
End Function
Public Function newEChar(Optional o_o As EasyText = Nothing) As EasyChar
        Dim r As New EasyChar
        copyEChar r, o_o
        Set newEChar = r
End Function

Public Function copyEText(r As EasyText, o_o As EasyText, Optional ByVal copyData As Boolean = True, Optional ByVal copyContent As Boolean = True) As EasyText
        Dim I As Long
        If o_o Is Nothing Then Exit Function
        With o_o
                If copyData Then
                        r.SetSize o_o.Count
                        For I = 0 To o_o.Count - 1
                                copyEChar r.GetChar(I), o_o.GetChar(I), False, copyContent
                        Next
                Else
                        r.hSceneDC = o_o.hSceneDC
                        r.hSceneBakDC = o_o.hSceneBakDC
                        r.drawPic = o_o.drawPic
                        r.X = .X
                        r.Y = .Y
                        r.Visible = .Visible
                End If
        End With
        Set copyEText = r
End Function
Public Function newEText(Optional o_o As EasyText) As EasyText
        Dim r As New EasyText
        copyEText r, o_o
        Set newEText = r
End Function
