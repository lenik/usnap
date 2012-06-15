Attribute VB_Name = "modVBTool01"

' 桃壳高科技 效率工程 | 开发工具效率挖掘计划
' Visual Studio 系列
' Visual Basic 底层扩展工具 - 1 核心扩展
'
' 本扩展使用了:
'       桃壳高科技底层扩展工具  LowTool Release 4
'       桃壳高科技 ActiveX 扩展   LowXTool
'
' 版权所有(C) 桃壳高科技 2000-2001

Option Explicit

'Public ltArray As New LowXTool.Array
'Public ltString As New LowXTool.String

' LIBRARY HELPER FUNCTION
Declare Function returnIDFunc Lib "LowTool" () As Long
Declare Function returnHandle Lib "LowTool" () As Long

' VALUE TRANSLATE

Declare Function pAny Lib "LowTool" Alias "rV" (ByRef refData As Any) As Long
Declare Function pVal Lib "LowTool" Alias "rV" (ByVal valData As Any) As Long
Declare Function pVar Lib "LowTool" Alias "rV" (ByRef refVar As Variant) As Long

Declare Function pByte Lib "LowTool" Alias "rV" (ByRef refByte As Byte) As Long
Declare Function pWord Lib "LowTool" Alias "rV" (ByRef refWord As Integer) As Long
Declare Function pLong Lib "LowTool" Alias "rV" (ByRef refLong As Long) As Long

' 字符串在VB中的实际位置大概并没有变, 但在与外界接口上, VB总是给出它的副本,
' 且这个副本的位置并不固定(好像有一个缓冲区专门放置副本), 所以外部程序对字串
' 的修改不起作用.
'       l = pstrRef(<string>)      ' 字串所在变量的自动化变量地址
' 所以无法改变系统中字串的实际内容,
' 但是可以通过 str = str_op(unpStrPointer(l), ...)
' 将临时生成的串存回源串

' 不管是 byval / byref as string, VB永远将副本传递给 API。因此 pStr/ppStr 返回的
' 都是副本的指针, 对该指针指向的内容修改自然毫无意义.
' 但是如果在API声明中使用 as string, 那么VB将负责将副本重新写回原本。
' 这样做使得使用BSTR的VB可以和使用ASCIZ的API能够良好的合作。
Declare Function pStr Lib "LowTool" Alias "rV" (ByVal lpString As String) As Long
Declare Function ppStr Lib "LowTool" Alias "rV" (ByRef refString As String) As Long

Declare Function pFunc Lib "LowTool" Alias "rV" (ByVal lpPointer As Long) As Long

Declare Function toByte Lib "LowTool" Alias "rV" (ByVal val As Long) As Byte
Declare Function toWord Lib "LowTool" Alias "rV" (ByVal val As Long) As Integer
Declare Function toLong Lib "LowTool" Alias "rV" (ByVal val As Long) As Long
Declare Function toStr Lib "LowTool" Alias "rV" (ByVal address As Long) As String

' cSV: VB不支持 ByVal STRUCT，这就是说定义cSV实例必须将STRUCT打散作为参数使用。
Declare Function toDbl Lib "FP3T" Alias "cSV" (Optional ByVal Size As Long = 8, Optional ByVal PartL As Long, Optional ByVal PartH As Long) As Double
'Declare Function toDbl2 Lib "FP3T" Alias "cSV" (Optional ByVal size As Long = 8, Optional ByVal dv As Double) As Double
Type T1
        a As Long
        b As Long
End Type
Type T2
        c As Long
        d As Long
        e As Long
        f As Long
End Type
Public tt1 As T1, tt2 As T2
Declare Function toT2 Lib "FP3T" Alias "cSV" (Optional ByVal Size As Long = 8, Optional ByVal c As Long, _
                                                Optional ByVal d As Long, Optional ByVal e As Long, Optional ByVal f As Long) As T2

Declare Function toBytes Lib "FP3T" Alias "rSV" (ByVal pSAT As Long, Optional ByVal Size As Long = 16) As Byte()
Declare Function toWords Lib "FP3T" Alias "rSV" (ByVal pSAT As Long, Optional ByVal Size As Long = 16) As Integer()
Declare Function toLongs Lib "FP3T" Alias "rSV" (ByVal pSAT As Long, Optional ByVal Size As Long = 16) As Long()
Declare Function toStrs Lib "FP3T" Alias "rSV" (ByVal pSAT As Long, Optional ByVal Size As Long = 16) As String()

Declare Function toVar Lib "FP3T" Alias "rSV" (ByVal pVT As Long, Optional ByVal Size As Long = 16) As Variant

' MIDDLE LEVEL MEMORY OPERATION
Declare Function returnByte Lib "LowTool" Alias "rB" (ByVal base As Long, ByVal offset As Long) As Byte
Declare Function returnWord Lib "LowTool" Alias "rW" (ByVal base As Long, ByVal offset As Long) As Integer
Declare Function returnLong Lib "LowTool" Alias "rL" (ByVal base As Long, ByVal offset As Long) As Long
Declare Function returnNByte Lib "LowTool" Alias "rnB" (ByVal base As Long, ByVal offset As Long) As Byte
Declare Function returnNWord Lib "LowTool" Alias "rnW" (ByVal base As Long, ByVal offset As Long) As Integer
Declare Function returnNLong Lib "LowTool" Alias "rnL" (ByVal base As Long, ByVal offset As Long) As Long

Declare Function forceByte Lib "LowTool" Alias "fB" (ByVal base As Long, ByVal offforce As Long, ByVal vByte As Byte) As Byte
Declare Function forceWord Lib "LowTool" Alias "fW" (ByVal base As Long, ByVal offforce As Long, ByVal vWord As Integer) As Integer
Declare Function forceLong Lib "LowTool" Alias "fL" (ByVal base As Long, ByVal offforce As Long, ByVal vLong As Long) As Long
Declare Function forceNByte Lib "LowTool" Alias "fnB" (ByVal base As Long, ByVal offforce As Long, ByVal vByte As Byte) As Byte
Declare Function forceNWord Lib "LowTool" Alias "fnW" (ByVal base As Long, ByVal offforce As Long, ByVal vWord As Integer) As Integer
Declare Function forceNLong Lib "LowTool" Alias "fnL" (ByVal base As Long, ByVal offforce As Long, ByVal vLong As Long) As Long

' VB STRING TOOLS
Declare Function getStringLengthA Lib "LowTool" Alias "SLA" (ByVal lpString As String) As Long
Declare Function getStringLengthW Lib "LowTool" Alias "SLW" (ByVal lpString As String) As Long
Declare Function getStringLengthM Lib "LowTool" Alias "SLM" (ByVal lpString As String) As Long

Declare Function copyBytes Lib "LowTool" Alias "cB" (ByVal pDest As Long, ByVal pSrc As Long, Optional ByVal nCount As Long = 1) As Long
Declare Function copyAny Lib "LowTool" Alias "cB" (ByRef pDest As Any, ByRef pSrc As Any, ByVal nCount As Long) As Long

' ADVANCE VB CALLBACK
Declare Function callFunction0 Lib "LowTool" Alias "CF0" (ByVal lpCallback As Long) As Long
Declare Function callFunction1 Lib "LowTool" Alias "CF1" (ByVal lpCallback As Long, ByVal parameter1 As Long) As Long
Declare Function callFunction2 Lib "LowTool" Alias "CF2" (ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long) As Long
Declare Function callFunction3 Lib "LowTool" Alias "CF4" (ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long) As Long
Declare Function callFunction4 Lib "LowTool" Alias "CF4" (ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long, ByVal parameter4 As Long) As Long
Declare Sub callProcedure0 Lib "LowTool" Alias "CP0" (ByVal lpCallback As Long)
Declare Sub callProcedure1 Lib "LowTool" Alias "CP1" (ByVal lpCallback As Long, ByVal parameter1 As Long)
Declare Sub callProcedure2 Lib "LowTool" Alias "CP2" (ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long)
Declare Sub callProcedure3 Lib "LowTool" Alias "CP4" (ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long)
Declare Sub callProcedure4 Lib "LowTool" Alias "CP4" (ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long, ByVal parameter4 As Long)

Public Enum callPrototype
        protopascal = 0
        protostdcall = 0
        protocdecl = 1
        protofastcall = 1
End Enum
Declare Function callPascal Lib "LowTool" Alias "_CS" (ByVal lpCallback As Long, ByVal vaCount As Long, ByVal extra_release As Long, ByVal pva As Long) As Long
Declare Function callCdecl Lib "LowTool" Alias "_CC" (ByVal lpCallback As Long, ByVal vaCount As Long, ByVal extra_release As Long, ByVal pva As Long) As Long

' LANGUAGE EXTENSION
Declare Function dwAdd Lib "LowTool" Alias "DW_A" (ByVal a As Long, ByVal b As Long) As Long
Declare Function dwSub Lib "LowTool" Alias "DW_S" (ByVal a As Long, ByVal b As Long) As Long
Declare Function dwMul Lib "LowTool" Alias "DW_M" (ByVal a As Long, ByVal b As Long) As Long
Declare Function dwDiv Lib "LowTool" Alias "DW_D" (ByVal a As Long, ByVal b As Long) As Long
Declare Function dwShl Lib "LowTool" Alias "DW_L" (ByVal Data As Long, Optional ByVal Num As Long = 1) As Long
Declare Function dwShr Lib "LowTool" Alias "DW_R" (ByVal Data As Long, Optional ByVal Num As Long = 1) As Long

' KERNEL DEBUG
Declare Sub Critical Lib "LowTool" Alias "BREAK" ()

' USER EXTEND
'       oldproc = CatchMessage(me.hWnd, AddressOf newproc)
'		newproc:
'			...
'			newproc = ChainMessage(oldproc, hWnd, message, wParam, lParam)
Declare Function CatchMessage Lib "LowTool" Alias "Mcatch" (ByVal hWnd As Long, ByVal new_wndproc As Long) As Long
Declare Function ChainMessage Lib "LowTool" Alias "Mchain" (ByVal wndproc As Long, ByVal hWnd As Long, ByVal message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long

' DEBUG
'Declare Function vbtString Lib "LowTool" (ByVal Index As Integer) As String
'Declare Function vbtString2 Lib "LowTool" Alias "vbtString" (ByVal Index As Integer) As Long
'Declare Sub lower Lib "LowTool" Alias "lowerString" (ByVal str As String)


Public Type SafeArrayBoundType
        cElements As Long
        lLbound As Long
End Type
Public Type SafeArrayType
        cDims As Integer
        fFeatures As Integer
        cbElements As Long
        cLocks As Long
        pvData As Long
        rgsabound(0 To 15) As SafeArrayBoundType
End Type

Public Enum VarTypeEnum
        VT_EMPTY = 0
        VT_NULL = 1
        VT_I2 = 2
        VT_I4 = 3
        VT_R4 = 4
        VT_R8 = 5
        VT_CY = 6
        VT_DATE = 7
        VT_BSTR = 8
        VT_DISPATCH = 9
        VT_ERROR = 10
        VT_BOOL = 11
        VT_VARIANT = 12
        VT_UNKNOWN = 13
        VT_DECIMAL = 14
        VT_I1 = 16
        VT_UI1 = 17
        VT_UI2 = 18
        VT_UI4 = 19
        VT_I8 = 20
        VT_UI8 = 21
        VT_INT = 22
        VT_UINT = 23
        VT_VOID = 24
        VT_HRESULT = 25
        VT_PTR = 26
        VT_SAFEARRAY = 27
        VT_CARRAY = 28
        VT_USERDEFINED = 29
        VT_LPSTR = 30
        VT_LPWSTR = 31
        VT_RECORD = 36
        VT_FILETIME = 64
        VT_BLOB = 65
        VT_STREAM = 66
        VT_STORAGE = 67
        VT_STREAMED_OBJECT = 68
        VT_STORED_OBJECT = 69
        VT_BLOB_OBJECT = 70
        VT_CF = 71
        VT_CLSID = 72
        VT_BSTR_BLOB = &HFFF
        VT_VECTOR = &H1000
        VT_ARRAY = &H2000
        VT_BYREF = &H4000
        VT_RESERVED = &H8000
        VT_ILLEGAL = &HFFFF
        VT_ILLEGALMASKED = &HFFF
        VT_TYPEMASK = &HFFF
End Enum
Public Type VariantType
        VarType As VarTypeEnum
        'wReserved1 As Integer
        wReserved2 As Integer
        wReserved3 As Integer
        DataL As Long
        DataH As Long
End Type

Public Function AsBytes(ByVal p As Long, ByVal Elements As Long, Optional ByVal lBase As Long = 0) As Byte()
        Dim SAT As SafeArrayType
        SAT.cDims = 1
        SAT.cbElements = 1
        SAT.pvData = p
        SAT.rgsabound(0).cElements = Elements
        SAT.rgsabound(0).lLbound = lBase
        AsBytes = toBytes(pAny(SAT))
End Function

Public Function AsVar(ByVal VTE As VarTypeEnum, ByVal Data As Long, Optional ByVal DataH As Long) As Variant
        Dim VT As VariantType
        VT.VarType = VTE
        VT.DataL = Data
        VT.DataH = DataH
        AsVar = toVar(pAny(VT))
End Function

Public Function MLen2ALen(ByVal str As String, ByVal mlen As Long) As Long
        MLen2ALen = getStringLengthA(Left(str, mlen))
End Function
Public Function ALen2MLen(ByVal str As String, ByVal alen As Long) As Long
        Dim mlen As Long
        Dim mtotlen As Long
        Dim mpart As Long, mpart1 As Long
        mtotlen = Len(str)
        For mlen = 0 To mtotlen
                mpart = getStringLengthA(Left(str, mlen))
                mpart1 = getStringLengthA(Left(str, mlen + 1))
                If mpart <= alen And (alen < mpart1 Or mpart = mpart1) Then
                        ALen2MLen = mlen
                        Exit For
                End If
        Next
End Function

Public Function callFunc(ByVal proto As callPrototype, ByVal proc As Long, ByVal extra_release As Long, ParamArray va()) As Long
        Dim i As Integer
        Dim vaCount As Long

        vaCount = UBound(va) - LBound(va) + 1
        ReDim pva(0 To vaCount - 1) As Long

        For i = LBound(va) To UBound(va)
                pva(i - LBound(va)) = va(i)
        Next

        Select Case proto
        Case protopascal Or protostdcall
                callFunc = callPascal(proc, vaCount, extra_release, pLong(pva(0)))
        Case protocdecl Or protofastcall
                callFunc = callCdecl(proc, vaCount, extra_release, pLong(pva(0)))
        End Select
End Function
