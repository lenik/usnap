Attribute VB_Name = "modMD5"
Option Explicit


Declare Function add Lib "maths" (ByVal x As Long, ByVal y As Long) As Long
Declare Function rol Lib "maths" (ByVal x As Long, ByVal y As Long) As Long
Declare Function ror Lib "maths" (ByVal x As Long, ByVal y As Long) As Long

' 输入：        data字节数组表示要检验的数据
'               size表示data数组的长度，有几个字节
' 输出：        md5code输出64位MD5检验码
Public Function MD5(data() As Byte, size As Long, md5code) As Long
        Dim padsize As Long, newsize As Long
        Dim i As Long, j As Long

        ' 第一步：附加填充位，使data数组元数+8为64字节整数倍
                ' 计算要填充的附加字节数
                If size Mod 64 = 56 Then
                        padsize = 64
                Else
                        padsize = (120 - size Mod 64) Mod 64
                End If
                newsize = size + padsize + 8

                ' 组合原数组data和附加位至新数组d
                ReDim D(0 To newsize - 1)
                For i = 0 To size - 1
                        D(i) = data(i)
                Next
                D(size) = &H80
                For i = size + 1 To newsize - 1
                        D(i) = 0
                Next

        ' 第二步：将原数据长度附加在后面
                D(size + padsize) = size Mod &H100
                D(size + padsize + 1) = Int(size / &H100) Mod &H100
                D(size + padsize + 2) = Int(size / &H10000) Mod &H100
                D(size + padsize + 3) = Int(size / &H1000000) Mod &H100
                D(size + padsize + 4) = 0
                D(size + padsize + 5) = 0
                D(size + padsize + 6) = 0
                D(size + padsize + 7) = 0

        ' 第三步：初始化MD缓存
                Dim A As Long
                Dim B As Long
                Dim C As Long
                Dim D As Long

                A = &H67452301
                B = &HEFCDAB89
                C = &H98BACDFE
                D = &H10325476

        ' 第四步：按每16字一块处理数据
                For i = 0 To newsize / 16 - 1
                        For j = 0 To 15

End Function

Public Function FF(x, y, z) As Long
        F = x And y Or Not x And z
End Function
Public Function FG(x, y, z) As Long
        G = x And z Or y And Not z
End Function
Public Function FH(x, y, z) As Long
        H = x Xor y Xor z
End Function
Public Function FI(x, y, z) As Long
        i = y Xor (x Or Not z)
End Function
