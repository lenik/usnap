Attribute VB_Name = "modSComp"
Option Explicit

' API 常数定义

Public Const STREAM_COMP_UNMATCH = &H1
Public Const STREAM_COMP_EXTRA = &H2
Public Const STREAM_COMP_LOST = &H3

Public Const STREAM_COMP_UNMATCH_C = "x"
Public Const STREAM_COMP_EXTRA_C = "e"
Public Const STREAM_COMP_LOST_C = "l"

Public Const STREAM_COMP_FILLBLANK_C = " "

Public Const STREAM_COMP_ERROR = -1

' 控制变量

Private Const MAXRES = 1024             ' 结果流的最大长度
Private Const MaxLen = 16384            ' 美化串的最大长度

Public SEARCH_DEPTH As Integer          ' 查找深度
Public SAME_SIZE As Integer             ' 指示相同的最小长度

'// 流比较
'// ref[]    参考流, 长度size_ref
'// obj[]    实例流, 长度size_obj
'// search_depth 比较深度 (必须大于0)
'// same_size    认为部分相同的最小长度
'// cr       比较结果数据的列表, 如果为NULL则不存储比较结果
'//          存储比较结果, 分为四种类型:
'//              异同(1): 被认为是不相同的数据
'//              多余(2): 被认为是多余的数据
'//              缺少(3): 被认为是缺少的数据
'//              结束(0): 表示列表结束
'//          返回时按 (类型, ref位置, obj位置, 类型, ref位置, obj位置...), 在列表的最顶部4个数据用于存放
'//              相同数 异同数 多余数 缺少数
'//          结束符占用三个位置
'// psize_cr cr提供的长度, 同时用于返回实际使用的长度(包括结束符)
'//
'// 参数错误时返回STREAM_COMP_ERROR, 否则返回 0

Declare Function StreamCompAnsi Lib "scomp.dll" Alias "SCB" ( _
        ByVal addrAnsiRef As Long, _
        ByVal addrAnsiObj As Long, _
        ByVal size_ref As Long, _
        ByVal size_obj As Long, _
        ByVal SEARCH_DEPTH As Long, _
        ByVal SAME_SIZE As Long, _
        cr_0 As Long, _
        psize_cr As Long _
        ) As Long

Declare Function StreamCompUnicode Lib "scomp.dll" Alias "SCW" ( _
        ByVal addrUnicodeRef As Long, _
        ByVal addrUnicodeObj As Long, _
        ByVal size_ref As Long, _
        ByVal size_obj As Long, _
        ByVal SEARCH_DEPTH As Long, _
        ByVal SAME_SIZE As Long, _
        cr_0 As Long, _
        psize_cr As Long _
        ) As Long

Declare Function StreamCompLong Lib "scomp.dll" Alias "SCD" ( _
        ByVal addrLongRef As Long, _
        ByVal addrLongObj As Long, _
        ByVal size_ref As Long, _
        ByVal size_obj As Long, _
        ByVal SEARCH_DEPTH As Long, _
        ByVal SAME_SIZE As Long, _
        cr_0 As Long, _
        psize_cr As Long _
        ) As Long

Declare Function StreamCompMbcs Lib "scomp.dll" Alias "SCM" ( _
        ByVal ref As String, _
        ByVal obj As String, _
        ByVal size_ref As Long, _
        ByVal size_obj As Long, _
        ByVal SEARCH_DEPTH As Long, _
        ByVal SAME_SIZE As Long, _
        cr_0 As Long, _
        psize_cr As Long _
        ) As Long

Declare Function StreamCompMbcsFast Lib "scomp.dll" Alias "SCM_F" ( _
        ByVal ref As String, _
        ByVal obj As String, _
        ByVal size_ref As Long, _
        ByVal size_obj As Long, _
        ByVal SEARCH_DEPTH As Long, _
        ByVal SAME_SIZE As Long, _
        cr_0 As Long, _
        psize_cr As Long _
        ) As Long

' 多字节串的元素提取
Declare Function StreamCompMbC Lib "scomp.dll" Alias "SCM_GE" ( _
        ByVal Mbcs As String, _
        ByVal Index As Long _
        ) As Long

'/*
' * 美化流比较结果
' *
' * cr       流比较结果
' * size_cr  流比较结果的(包括头部4个单元和结束符3个单元)
' * rbuf     参考流的美化比较结果
' * psize_rbuf   rbuf提供的长度, 同时用于返回实际使用的长度. 如果 <= 0 返回需要的长度
' * obuf     实例流的美化比较结果
' * psize_obuf   obuf提供的长度, 同时用于返回实际使用的长度. 如果 <= 0 返回需要的长度
' *
' * 美化比较结果中不附加结束符'\0'
' */
Declare Function StreamCompPretty Lib "scomp.dll" Alias "SCPR" ( _
        cr_0 As Long, _
        ByVal size_cr As Long, _
        ByVal rbuf As String, _
        psize_rbuf As Long, _
        ByVal obuf As String, _
        psize_obuf As Long _
        ) As Long

Declare Function ResetNumInfoLost Lib "scomp.dll" Alias "RNIL" () As Long

Type COMPRESULT
        Right As Integer
        wrong As Integer
        extra As Integer
        lost As Integer
        resultRef As String
        resultObj As String
End Type

Public forceMbcs As Boolean

Public Function FuzzyComp(ByVal strref As String, ByVal strobj As String, Optional ByVal bMbcs As Boolean = False) As COMPRESULT
        Dim cr(0 To MAXRES) As Long
        Dim size_cr As Long
        Dim r As Long
        Dim rbuf As String * MaxLen
        Dim obuf As String * MaxLen
        Dim size_rbuf As Long, size_obuf As Long

        size_cr = MAXRES
        If SEARCH_DEPTH < 1 Then SetDepth 10
        If SAME_SIZE < 1 Then SetSame 4

        FuzzyComp.Right = -1
        If bMbcs Or forceMbcs Then
                r = StreamCompMbcs( _
                        strref, strobj, Len(strref), Len(strobj), _
                        SEARCH_DEPTH, SAME_SIZE, cr(0), size_cr)
        Else
                r = StreamCompAnsi( _
                        pStr(strref), pStr(strobj), _
                        getStringLengthA(strref), getStringLengthA(strobj), _
                        SEARCH_DEPTH, SAME_SIZE, _
                        cr(0), size_cr)
        End If
        If r = STREAM_COMP_ERROR Then Exit Function

        FuzzyComp.Right = cr(0)
        FuzzyComp.wrong = cr(1)
        FuzzyComp.extra = cr(2)
        FuzzyComp.lost = cr(3)

        size_rbuf = MaxLen
        size_obuf = MaxLen
        r = StreamCompPretty(cr(0), size_cr, rbuf, size_rbuf, obuf, size_obuf)
        If r = STREAM_COMP_ERROR Then Exit Function

        FuzzyComp.resultRef = Left(rbuf, size_rbuf)
        FuzzyComp.resultObj = Left(obuf, size_obuf)

End Function

Public Function SetDepth(ByVal newdepth As Integer) As Integer
        SetDepth = SEARCH_DEPTH
        SEARCH_DEPTH = newdepth
End Function

Public Function SetSame(ByVal newsamesize As Integer) As Integer
        SetSame = SAME_SIZE
        SAME_SIZE = newsamesize
End Function
