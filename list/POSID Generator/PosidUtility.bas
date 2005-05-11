Attribute VB_Name = "modPosidUtility"
Option Explicit
Option Base 0


Public Const CCS5_Encode = "_abcdefghijklmnopqrstuvwxyz.:$@%"

Public Const CCS6_Encode = "_abcdefghijklmnopqrstuvwxyz01234.ABCDEFGHIJKLMNOPQRSTUVWXYZ56789"
'


' Extra bitgrp/padding in returned byte() should be taken care by caller.
Public Function BitSplit(bytes() As Byte, ByVal bits As Integer) As Byte()
    Dim shifts
    Dim nbytes As Integer

    shifts = Array(1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768)
    nbytes = UBound(bytes) + 1

    ' ceiling( bytes * 8 / bits )
    Dim bitsGroups As Integer
    bitsGroups = 8 * nbytes
    bitsGroups = Int((bitsGroups + bits - 1) / bits)
    ReDim res(0 To bitsGroups - 1) As Byte
    Dim iRes As Integer
    Dim i As Integer
    Dim v As Long
    Dim bc As Integer        ' bit-capacity in long value v  (0 -> ..)

    iRes = 0
    i = 0

    Do While iRes < bitsGroups

        v = (v * &H100)
        If i < nbytes Then v = v Or bytes(i)
        ' Else v = (v << 8) | 0x00

        bc = bc + 8
        i = i + 1

        ' Dump to result
        While bc >= bits And iRes < bitsGroups
            ' v >> (bc-bits)
            res(iRes) = Int(v / shifts(bc - bits))
            iRes = iRes + 1
            bc = bc - bits

            ' v >>= (bc-bits)  =>  v &= ~(1<<bc-bits)
            v = v And (shifts(bc) - 1)
        Wend

    Loop

    BitSplit = res
End Function


' Extra bitgrp/padding in bitgrps() should be trimmed by caller.
Public Function BitJoin(bitgrps() As Byte, ByVal bits As Integer) As Byte()
    Dim shifts
    Dim nbytes As Integer

    shifts = Array(1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768)
    nbytes = UBound(bitgrps) + 1

    ' ceiling( bitgrps * bits / 8 )
    Dim byteGroups As Integer
    byteGroups = bits * nbytes
    byteGroups = Int((byteGroups + 7) / 8)
    ReDim res(0 To byteGroups - 1) As Byte
    Dim iRes As Integer
    Dim i As Integer
    Dim v As Long
    Dim bc As Integer        ' bit-capacity in long value v  (0 -> ..)

    iRes = 0
    i = 0

    Do While iRes < byteGroups

        v = (v * shifts(bits))
        If i < nbytes Then v = v Or bitgrps(i)
        ' Else v = (v << bits) | 0x00

        bc = bc + bits
        i = i + 1

        ' Dump to result
        While bc >= 8 And iRes < byteGroups
            ' v >> (bc-8)
            res(iRes) = Int(v / shifts(bc - 8))
            iRes = iRes + 1
            bc = bc - 8

            ' v >>= (bcval-8)  =>  v &= ~(1<<bcval-8)
            v = v And (shifts(bc) - 1)
        Wend

    Loop

    BitJoin = res
End Function


Public Function BytesToCCS5(bytes() As Byte, ByVal bits As Integer) As String
    ' Assert bits > 0
    Dim chars As Integer
    Dim i As Integer
    Dim ccs5bytes

    chars = Int((bits + 4) / 5)
    ccs5bytes = BitSplit(bytes, 5)
    For i = 0 To chars - 1
        BytesToCCS5 = BytesToCCS5 & Mid(CCS5_Encode, ccs5bytes(i) + 1, 1)
    Next
End Function


Public Function BytesToCCS6(bytes() As Byte, ByVal bits As Integer) As String
    ' Assert bits > 0
    Dim chars As Integer
    Dim i As Integer
    Dim ccs6bytes

    chars = Int((bits + 5) / 6)
    ccs6bytes = BitSplit(bytes, 6)
    For i = 0 To chars - 1
        BytesToCCS6 = BytesToCCS6 & Mid(CCS6_Encode, ccs6bytes(i) + 1, 1)
    Next
End Function


Public Function CCS5ToBytes(ByVal ccs5 As String) As Byte()
    Dim l As Integer
    Dim i As Integer
    l = Len(ccs5)

    ReDim b5grps(0 To l - 1) As Byte
    Dim c As String * 1
    Dim cv As Integer

    For i = 0 To l - 1
        c = Mid(ccs5, i + 1, 1)
        cv = InStr(CCS5_Encode, c)
        If cv <= 0 Then Err.Raise -1, , "Invalid character in CCS-5 string: " & c
        cv = cv - 1
        b5grps(i) = cv
    Next

    Dim nbytes As Integer
    Dim res1

    nbytes = Int((l * 5 + 7) / 8)
    res1 = BitJoin(b5grps, 5)

    ReDim res2(0 To nbytes - 1) As Byte
    For i = 0 To nbytes - 1
        res2(i) = res1(i)
    Next

    CCS5ToBytes = res2
End Function


Public Function CCS6ToBytes(ByVal ccs6 As String) As Byte()
    Dim l As Integer
    Dim i As Integer
    l = Len(ccs6)

    ReDim b6grps(0 To l - 1) As Byte
    Dim c As String * 1
    Dim cv As Integer

    For i = 0 To l - 1
        c = Mid(ccs6, i + 1, 1)
        cv = InStr(CCS6_Encode, c)
        If cv <= 0 Then Err.Raise -1, , "Invalid character in CCS-6 string: " & c
        cv = cv - 1
        b6grps(i) = cv
    Next

    Dim nbytes As Integer
    Dim res1

    nbytes = Int((l * 6 + 7) / 8)
    res1 = BitJoin(b6grps, 6)

    ReDim res2(0 To nbytes - 1) As Byte
    For i = 0 To nbytes - 1
        res2(i) = res1(i)
    Next

    CCS6ToBytes = res2
End Function


Public Function CCS5Random(ByVal size As Integer) As String
    While size > 0
        size = size - 1
        CCS5Random = CCS5Random & Mid(CCS5_Encode, 1 + Int(Rnd * 32), 1)
    Wend
End Function


Public Function CCS6Random(ByVal size As Integer) As String
    While size > 0
        size = size - 1
        CCS6Random = CCS6Random & Mid(CCS6_Encode, 1 + Int(Rnd * 64), 1)
    Wend
End Function



' AA-BB-CC-DD in transferring order
'   -> DDCCBBAA for LE-machine  (* This version)
'   -> AABBCCDD for BE-machine
Public Function BytesToLong(bytes() As Byte) As Long
    Dim l As Long

    If bytes(3) < &H80 Then
        l = bytes(3) * &H1000000
    Else
        l = (bytes(3) - &H80) * &H1000000 Or &H80000000
    End If

    l = l Or bytes(0) Or bytes(1) * &H100& Or bytes(2) * &H10000

    BytesToLong = l
End Function


' AABBCCDD of long value
'   -> DD-CC-BB-AA in transferring order for LE-machine  (* This version)
'   -> AA-BB-CC-DD in transferring order for BE-machine
Public Function LongToBytes(ByVal l As Long) As Byte()
    Dim bytes(0 To 3) As Byte

    bytes(3) = ((l And &HFF000000) / &H1000000) And &HFF
    l = l And &HFFFFFF

    bytes(0) = l Mod &H100
    l = (l - bytes(0)) / &H100
    bytes(1) = l Mod &H100
    l = (l - bytes(1)) / &H100
    bytes(2) = l Mod &H100

    LongToBytes = bytes
End Function


Public Function ReverseBytes(bytes() As Byte)
    Dim nbytes As Integer
    Dim i As Integer

    nbytes = UBound(bytes) + 1

    ReDim res(0 To nbytes - 1) As Byte

    For i = 0 To nbytes - 1
        res(nbytes - 1 - i) = bytes(i)
    Next

    ReverseBytes = res
End Function


Public Function BytesToHex(bytes() As Byte, Optional delim As String = "-") As String
    Dim i As Integer
    Dim s As String
    For i = 0 To UBound(bytes)
        If (bytes(i) < 16) Then
            s = "0" & Hex(bytes(i))
        Else
            s = Hex(bytes(i))
        End If
        If i > LBound(bytes) Then BytesToHex = BytesToHex & delim
        BytesToHex = BytesToHex & s
    Next
End Function


Public Function HexToBytes(ByVal hexes As String) As Byte()
    hexes = Replace(hexes, "-", "")

    If Len(hexes) Mod 2 = 1 Then hexes = hexes & "0"
    hexes = LCase(hexes)

    Dim nbytes As Integer
    nbytes = Int(Len(hexes) / 2)

    ReDim bytes(0 To nbytes - 1) As Byte
    Dim i As Integer

    On Error GoTo InvalidSyntax
    For i = 0 To nbytes - 1
        bytes(i) = Val("&H" & Mid(hexes, 1 + i * 2, 2))
    Next
    On Error GoTo 0

    HexToBytes = bytes
    Exit Function

InvalidSyntax:
    MsgBox "Invalid hex syntax", vbCritical, "Error"
    On Error GoTo 0
End Function
