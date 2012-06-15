Attribute VB_Name = "modG1"
Option Explicit

Public xapp As Excel.Application
Public book As Excel.Workbook
Public s As Excel.Worksheet

Public vbc As VBIDE.VBComponent

Public sh As Excel.Shape

Public i As Long

Public Function encodePart(ByVal Part As String, Optional ByVal partChar As String = "#") As String: encodePart = partChar & Len(Part) & "," & Part: End Function
Public Function decodePart(ByVal info As String, ByVal Index As Integer, Optional ByVal decodeOffset As Boolean = False, Optional ByVal partChar As String = "#", Optional ByVal ignoreNumber As Boolean = False) As String
        Dim p As Integer, l As Integer
        Dim c As String
        Dim Num As Integer, NumLen As Integer
        Dim i As Integer

        If Index = 0 Then
                decodePart = IIf(decodeOffset, 1, Left(info, decodePart(info, 1, True, partChar) - 1))
                Exit Function
        End If

        p = 1: l = Len(info)
        Num = 0
        i = 0
        Do While p <= l And i <> Index
                p = p + Num
                Num = 0: NumLen = 0
                c = Mid(info, p, 1)
                If c = partChar Then
                        If Not ignoreNumber And p < l And InStr("0123456789", Mid(info, p + 1, 1)) Then
                                ' 如果后续数字, 下一个Part位置
                                Num = Val(Mid(info, p + 1, 4))
                                NumLen = Len(Trim(Str(Num))) + Len(partChar) + 1
                        Else
                                ' 如果P已是结尾或无后续数字, 下一个Part位置
                                ' 本Part长度=下一个Part偏移数-1
                                Num = InStr(Mid(info, p + 1), partChar) - 1
                                ' 如果找不到下一个Part, 本Part长度=本Part开始...字串结尾
                                If Num < 0 Then Num = l - p
                                NumLen = Len(partChar)
                        End If
                        p = p + NumLen
                        i = i + 1
                Else
                        p = p + 1
                End If
        Loop
        If i < Index Then p = p + 1
        decodePart = IIf(decodeOffset, Str(p - NumLen), Mid(info, p, Num))
End Function
