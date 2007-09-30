Attribute VB_Name = "modSComp"
Option Explicit

' API ��������

Public Const STREAM_COMP_UNMATCH = &H1
Public Const STREAM_COMP_EXTRA = &H2
Public Const STREAM_COMP_LOST = &H3

Public Const STREAM_COMP_UNMATCH_C = "x"
Public Const STREAM_COMP_EXTRA_C = "e"
Public Const STREAM_COMP_LOST_C = "l"

Public Const STREAM_COMP_FILLBLANK_C = " "

Public Const STREAM_COMP_ERROR = -1

' ���Ʊ���

Private Const MAXRES = 1024             ' ���������󳤶�
Private Const MaxLen = 16384            ' ����������󳤶�

Public SEARCH_DEPTH As Integer          ' �������
Public SAME_SIZE As Integer             ' ָʾ��ͬ����С����

'// ���Ƚ�
'// ref[]    �ο���, ����size_ref
'// obj[]    ʵ����, ����size_obj
'// search_depth �Ƚ���� (�������0)
'// same_size    ��Ϊ������ͬ����С����
'// cr       �ȽϽ�����ݵ��б�, ���ΪNULL�򲻴洢�ȽϽ��
'//          �洢�ȽϽ��, ��Ϊ��������:
'//              ��ͬ(1): ����Ϊ�ǲ���ͬ������
'//              ����(2): ����Ϊ�Ƕ��������
'//              ȱ��(3): ����Ϊ��ȱ�ٵ�����
'//              ����(0): ��ʾ�б����
'//          ����ʱ�� (����, refλ��, objλ��, ����, refλ��, objλ��...), ���б�����4���������ڴ��
'//              ��ͬ�� ��ͬ�� ������ ȱ����
'//          ������ռ������λ��
'// psize_cr cr�ṩ�ĳ���, ͬʱ���ڷ���ʵ��ʹ�õĳ���(����������)
'//
'// ��������ʱ����STREAM_COMP_ERROR, ���򷵻� 0

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

' ���ֽڴ���Ԫ����ȡ
Declare Function StreamCompMbC Lib "scomp.dll" Alias "SCM_GE" ( _
        ByVal Mbcs As String, _
        ByVal Index As Long _
        ) As Long

'/*
' * �������ȽϽ��
' *
' * cr       ���ȽϽ��
' * size_cr  ���ȽϽ����(����ͷ��4����Ԫ�ͽ�����3����Ԫ)
' * rbuf     �ο����������ȽϽ��
' * psize_rbuf   rbuf�ṩ�ĳ���, ͬʱ���ڷ���ʵ��ʹ�õĳ���. ��� <= 0 ������Ҫ�ĳ���
' * obuf     ʵ�����������ȽϽ��
' * psize_obuf   obuf�ṩ�ĳ���, ͬʱ���ڷ���ʵ��ʹ�õĳ���. ��� <= 0 ������Ҫ�ĳ���
' *
' * �����ȽϽ���в����ӽ�����'\0'
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
