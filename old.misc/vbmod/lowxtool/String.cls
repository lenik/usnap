VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "String"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function saveAscizString(ByVal addrAscizString As Long, Optional ByVal Mbcs As Boolean = True) As String
        Dim off As Long
        Dim i As Long

        saveAscizString = ""
        If addrAscizString = 0 Then Exit Function

        off = 0
        Do While off < &H10000
                i = returnByte(addrAscizString, off)
                off = off + 1
                If i = 0 Then Exit Do
                If Mbcs And (i And &H80) Then
                        i = i * &H100 + returnByte(addrAscizString, off)
                        off = off + 1
                End If
                saveAscizString = saveAscizString & Chr(i)
        Loop
End Function

Public Function saveUnicodeString(ByVal addrUnicodeString As Long) As String
        Dim off As Long
        Dim i As Long

        saveUnicodeString = ""
        If addrUnicodeString = 0 Then Exit Function

        off = 0
        Do While off < &H10000
                i = returnWord(addrUnicodeString, off)
                off = off + 2
                If i = 0 Then Exit Do
                saveUnicodeString = saveUnicodeString & ChrW(i)
        Loop
End Function

Public Function enc(ByVal ori As String, Optional ByVal version As Integer = 0) As String
        ' version 编码版本
        '       0       一般编码, 标准ID字(除下划线)不变,
        '               其余字取16进制并前后缀_
        Dim p As Integer
        Dim l As Integer
        Dim a As Integer, c As String

        p = 1
        l = Len(ori)
        enc = ""
        Do While p <= l
                c = Mid(ori, p, 1)
                a = Asc(c)
                If (a >= &H41 And a <= &H5A) Or (a >= &H61 And a <= &H7A) Then
                        enc = enc & c
                Else
                        enc = enc & "_" & Hex(a) & "_"
                End If
                p = p + 1
        Loop
End Function
Public Function dec(ByVal ori As String, Optional ByVal version As Integer = 0) As String
        Dim p As Integer
        Dim l As Integer
        Dim a As Integer, c As String
        Dim x As Long, xm As Boolean

        p = 1
        l = Len(ori)
        xm = False
        Do While p <= l
                c = Mid(ori, p, 1)
                a = Asc(c)
                If a = &H5F Then
                        If Not xm Then
                                x = 0
                        Else
                                dec = dec & Chr(x)
                        End If
                        xm = Not xm
                Else
                        If Not xm Then
                                dec = dec & c
                        End If
                End If

                If xm Then
                        If a >= &H41 And a <= &H5A Then a = a + &H20
                        If (a >= &H30 And a <= &H39) Or (a >= &H61 And a <= &H7A) Then
                                a = a - IIf(a > &H60, &H57, &H30)
                                x = x * &H10 + a
                        End If
                End If
                p = p + 1
        Loop
End Function

Public Function quoteString(ByVal literalstring As String) As String
        quoteString = Replace(literalstring, """", """""")
End Function

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
                                Num = val(Mid(info, p + 1, 4))
                                NumLen = Len(Trim(str(Num))) + Len(partChar) + 1
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
        decodePart = IIf(decodeOffset, str(p - NumLen), Mid(info, p, Num))
End Function
Public Function departPart(info As String, ByVal Index As Integer, Optional ByVal partChar As String = "#") As String
        Dim l As Integer, M As Integer
        departPart = decodePart(info, Index, , partChar)
        l = val(decodePart(info, Index, True, partChar)) - 1
        M = val(decodePart(info, Index + 1, True, partChar))
        info = Left(info, IIf(l < 0, 0, l)) & Mid(info, IIf(M <= 0, 1, M))
End Function

Public Function encodeLisp(ByVal Lisp As String, Optional ByVal leftclose As String = "(", Optional ByVal rightclose As String = ")") As String: encodeLisp = leftclose & Len(Lisp) & "." & Lisp & rightclose: End Function
Public Function decodeLisp(ByVal info As String, ByVal Index As Integer, Optional ByVal decodeOffset As Boolean = False, Optional ByVal leftclose As String = "(", Optional ByVal rightclose As String = ")") As String
        Dim p As Integer, l As Integer
        Dim c As String
        Dim Num As Integer, NumLen As Integer
        Dim i As Integer

        If Index = 0 Then
                decodeLisp = IIf(decodeOffset, 1, Left(info, decodeLisp(info, 1, True, leftclose, rightclose) - 1))
                Exit Function
        End If

        p = 1: l = Len(info)
        Num = 0
        i = 0
        Do While p <= l And i <> Index
                p = p + Num
                Num = 0: NumLen = 0
                c = Mid(info, p, 1)
                If c = leftclose Then
                        If p < l And InStr("0123456789", Mid(info, p + 1, 1)) Then
                                ' 如果后续数字, 下一个Lisp位置
                                Num = val(Mid(info, p + 1, 4))
                                NumLen = Len(Trim(str(Num))) + Len(leftclose) + Len(rightclose) + 1
                        Else
                                ' 如果P已是结尾或无后续数字, 下一个Lisp位置
                                ' 本Lisp长度=下一个Lisp偏移数-1
                                Num = InStr(Mid(info, p + 1), leftclose) - 1
                                ' 如果找不到下一个Lisp, 本Lisp长度=本Lisp开始...字串结尾
                                If Num < 0 Then Num = l - p
                                NumLen = Len(leftclose) + Len(rightclose)
                        End If
                        p = p + NumLen
                        i = i + 1
                Else
                        p = p + 1
                End If
        Loop
        If i < Index Then p = p + 1
        decodeLisp = IIf(decodeOffset, str(p - NumLen), Mid(info, p, Num))
End Function
Public Function deLispLisp(info As String, ByVal Index As Integer, Optional ByVal LispChar As String = "#") As String
        Dim l As Integer, M As Integer
        deLispLisp = decodeLisp(info, Index, , LispChar)
        l = val(decodeLisp(info, Index, True, LispChar)) - 1
        M = val(decodeLisp(info, Index + 1, True, LispChar))
        info = Left(info, IIf(l < 0, 0, l)) & Mid(info, IIf(M <= 0, 1, M))
End Function

Public Function partcode_to_lispcode(ByVal partcode As String, Optional ByVal partChar As String = "#", Optional ByVal leftclose As String = "(", Optional ByVal rightclose As String = ")") As String
        Dim parti As Integer, parts As String
        Dim CPartS As String
        Dim r As String

        r = ""
        parti = 1
        Do
                parts = decodePart(partcode, parti, False, partChar)
                If parts = "" Then Exit Do

                r = r & leftclose & _
                        decodePart(parts, 0, False, partChar) & _
                        partcode_to_lispcode(parts, partChar, leftclose, rightclose) & _
                        rightclose

                parti = parti + 1
        Loop
        partcode_to_lispcode = r
End Function

Public Function lispcode_to_partcode(ByVal lispcode As String, Optional ByVal partChar As String = "#", Optional ByVal leftclose As String = "(", Optional ByVal rightclose As String = ")") As String
        Dim parti As Integer, parts As String
        Dim CPartS As String
        Dim r As String

        r = ""
        parti = 1
        Do
                parts = decodePart(lispcode, parti, False, partChar)
                If parts = "" Then Exit Do

                r = r & leftclose & _
                        decodePart(parts, 0, False, partChar) & _
                        partcode_to_lispcode(parts, partChar, leftclose, rightclose) & _
                        rightclose

                parti = parti + 1
        Loop
        lispcode_to_partcode = r
End Function



Public Function Hash2(ByVal Key As String, ByVal value As String) As String
        Hash2 = encodePart(encodePart(Key) & encodePart(value))
End Function
Public Function Hash(ByVal key_value As String, Optional ByVal TrimSpace As Boolean = True) As String
        Dim Key As String, value As String
        Key = decodePart(key_value, 0, , "=", True)
        value = decodePart(key_value, 1, , "=", True)
        If TrimSpace Then
                Key = Trim(Key)
                value = Trim(value)
        End If
        If Key <> "" Then Hash = Hash2(Key, value)
End Function
Public Function Hashs(ByVal key_values As String, Optional ByVal seperator As String = ",")
        Dim i As Long
        Dim ps As String
        i = 0
        Hashs = ""
        Do
                ps = decodePart(key_values, i, , seperator, True)
                If ps = "" Then Exit Do
                Hashs = Hashs & Hash(ps)
                i = i + 1
        Loop
End Function

Public Function HashKey(ByVal hashed As String) As String
        HashKey = decodePart(decodePart(hashed, 1), 0)
End Function
Public Function HashValue(ByVal hashed As String) As String
        HashValue = decodePart(decodePart(hashed, 1), 1)
End Function

Public Function HashKeyi(ByVal hashed_s As String, ByVal Index As Long) As String
        HashKeyi = decodePart(decodePart(hashed_s, Index + 1), 1)
End Function
Public Function HashValuei(ByVal hashed_s As String, ByVal Index As Long) As String
        HashValuei = decodePart(decodePart(hashed_s, Index + 1), 2)
End Function

Public Function HashQuery(ByVal hashed_s As String, ByVal Key As String, Optional ByVal IgnoreCase As Boolean = True, Optional ByVal DefaultValue As String = "") As String
        Dim i As Long
        Dim key_ As String
        Dim ps As String, pskey As String

        key_ = IIf(IgnoreCase, UCase(Key), Key)
        HashQuery = DefaultValue
        i = 1
        Do
                ps = decodePart(hashed_s, i)
                If ps = "" Then Exit Do
                pskey = decodePart(ps, 1)
                If IgnoreCase Then pskey = UCase(pskey)
                If pskey = key_ Then
                        HashQuery = decodePart(ps, 2)
                        Exit Do
                End If
                i = i + 1
        Loop
End Function
Public Function HashRemove(ByVal hashed_s As String, ByVal Key As String, Optional ByVal IgnoreCase As Boolean = True) As String
        Dim i As Long
        Dim key_ As String
        Dim ps As String, pskey As String

        key_ = IIf(IgnoreCase, UCase(Key), Key)
        HashRemove = ""
        i = 1
        Do
                ps = decodePart(hashed_s, i)
                If ps = "" Then Exit Do
                pskey = decodePart(ps, 1)
                If IgnoreCase Then pskey = UCase(pskey)
                If pskey <> key_ Then
                        HashRemove = HashRemove & encodePart(ps)
                End If
                i = i + 1
        Loop
End Function

Public Function SymbolReplace(ByVal text As String, ByVal Key As String, ByVal value As String, Optional ByVal IgnoreCase As Boolean = True, Optional ByVal SymbolID As String = "$") As String
        Dim keypos As Long
        Dim keys As String, keyslen As Long
        Dim compareMode As Integer

        If IgnoreCase Then Key = UCase(Key)
        compareMode = IIf(IgnoreCase, vbTextCompare, vbBinaryCompare)
        Do
                keys = SymbolID & Key
                keypos = InStr(1, text, keys, compareMode)
                If keypos = 0 Then
                        keys = SymbolID & "{" & Key & "}"
                        keypos = InStr(1, text, keys, compareMode)
                End If
                If keypos = 0 Then Exit Do

                keyslen = Len(keys)
                text = Left(text, keypos - 1) & value & Mid(text, keypos + keyslen)
        Loop
        SymbolReplace = text
End Function

Public Function InterpreteByHashes(ByVal text As String, ByVal hashed_s As String, Optional ByVal IgnoreCase As Boolean = True, Optional ByVal SymbolID As String = "$")
        Dim i As Long
        Dim ps As String
        Dim pskey As String, psvalue As String

        i = 1
        Do
                ps = decodePart(hashed_s, i)
                If ps = "" Then Exit Do

                pskey = decodePart(ps, 1)
                psvalue = decodePart(ps, 2)

                text = SymbolReplace(text, pskey, psvalue, IgnoreCase, SymbolID)

                i = i + 1
        Loop
        InterpreteByHashes = text
End Function

Public Function InterpreteControlChars(ByVal text As String, Optional ByVal ControlCharID As String = "\") As String
        Dim CTable As String
        CTable = Hashs( _
                "n=" & vbNewLine & _
                ",t=" & vbTab & _
                ",!=" & "dansei, HiTech")
        InterpreteControlChars = InterpreteByHashes(text, CTable, , "\")
End Function
