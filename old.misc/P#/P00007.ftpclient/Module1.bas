Attribute VB_Name = "Module1"
Option Explicit

Public Const 注册表_名称 = "FTP服务器"

Public Const 颜色_断开 = &HFFFFFF
Public Const 颜色_空闲 = &HFF00&
Public Const 颜色_忙碌 = &HFFFF&
Public Const 颜色_错误 = &HFF&

Public Type 虚拟目录
        服务器主目录中位置 As String
        名称 As String
        映像目录 As String
End Type

Public Type 用户
        用户名 As String
        密码 As String
        允许Email密码 As Boolean
        读权限 As Boolean
        写权限 As Boolean
        目录操作权限 As Boolean
End Type

Public 正在接受连接 As Boolean
Public 发送完毕 As Boolean
Public 数据发送完毕 As Boolean

Public 远程地址, 远程端口

Public 当前用户 As 用户
Public 当前目录 As String
Public 当前目录对象 As scripting.Folder
Public 文件系统 As New scripting.FileSystemObject
Public 用户已登陆 As Boolean
Public 等待发送数据 As String
Public 接收数据 As String


Public Function 编码虚拟目录(d As 虚拟目录) As String
        编码虚拟目录 = d.名称 & "|" & "                                        " & _
                                        d.服务器主目录中位置 & "|" & _
                                        d.映像目录
End Function

Public Function 解码虚拟目录(s As String) As 虚拟目录
'        On Error Resume Next
        解码虚拟目录.名称 = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(解码虚拟目录.名称) + 22)
        解码虚拟目录.服务器主目录中位置 = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(解码虚拟目录.服务器主目录中位置) + 2)
        解码虚拟目录.映像目录 = s
End Function

Public Function 编码用户(u As 用户) As String
        编码用户 = u.用户名 & "|" & "                                        " & _
                                u.密码 & "|" & _
                                u.允许Email密码 & "|" & _
                                u.读权限 & "|" & _
                                u.写权限 & "|" & _
                                u.目录操作权限
End Function

Public Function 解码用户(s As String) As 用户
        解码用户.用户名 = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(解码用户.用户名) + 22)
        解码用户.密码 = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(解码用户.密码) + 2)
        解码用户.允许Email密码 = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(CStr(解码用户.允许Email密码)) + 2)
        解码用户.读权限 = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(CStr(解码用户.读权限)) + 2)
        解码用户.写权限 = Left(s, InStr(s, "|") - 1)
        s = Mid(s, Len(CStr(解码用户.写权限)) + 2)
        解码用户.目录操作权限 = s 'Left(s, InStr(s, "|") - 1)
End Function

Public Function 获取用户配置(用户名) As 用户
        Dim i
        For i = 0 To 用户配置.用户列表.ListCount - 1
                获取用户配置 = 解码用户(用户配置.用户列表.List(i))
                If 获取用户配置.用户名 = 用户名 Then Exit Function
        Next
        获取用户配置.用户名 = ""  '!!不存在该用户
End Function

'输出时间t的字符串表达式
Public Function 时间(t As Date) As String
        时间 = Trim(Month(t)) & "-" & Trim(Day(t)) & "-" & Right(Trim(Year(t)), 2) & " " & _
                Trim(Hour(t)) & ":" & Trim(Minute(t)) & ":" & Trim(Second(t))
End Function

Public Function 获取当前目录内容() As String
        Dim d As scripting.Folder

        Dim r
        Dim sf As scripting.File, sd As scripting.Folder

        r = ""

        For Each sf In 当前目录对象.Files
                r = r & 时间(sf.DateLastModified) & " " & sf.Size & " " & sf.Name & vbNewLine
        Next

        For Each sd In 当前目录对象.SubFolders
                r = r & 时间(sd.DateLastModified) & " " & "<DIR>" & " " & sd.Name & vbNewLine
        Next

        获取当前目录内容 = r
End Function

Public Function 目录连接(a, b) As String
        If Right(a, 1) = "\" Then
                If Left(b, 1) = "\" Then
                        目录连接 = a & Mid(b, 2)
                Else
                        目录连接 = a & b
                End If
        Else
                目录连接 = a & "\" & b
        End If
End Function
