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

' 字符串在VB中的实际位置大概并没有变, 但在与外界接口上, VB总是给出它的副本,
' 且这个副本的位置并不固定(好像有一个缓冲区专门放置副本), 所以外部程序对字串
' 的修改不起作用.
'       l = getStrPointerRef(<string>)      ' 字串所在变量的自动化变量地址
' 所以无法改变系统中字串的实际内容,
' 但是可以通过 str = str_op(unpStrPointer(l), ...)
' 将临时生成的串存回源串

Declare Function pAny Lib "LowTool" Alias "rV" (ByRef refData As Any) As Long

Declare Function pByte Lib "LowTool" Alias "rV" (ByRef refByte As Byte) As Long
Declare Function pWord Lib "LowTool" Alias "rV" (ByRef refWord As Integer) As Long
Declare Function pLong Lib "LowTool" Alias "rV" (ByRef refLong As Long) As Long
Declare Function pStr Lib "LowTool" Alias "rV" (ByVal lpString As String) As Long

Declare Function ppStr Lib "LowTool" Alias "rV" (ByRef refString As String) As Long
Declare Function pFunc Lib "LowTool" Alias "rV" (ByVal lpPointer As Long) As Long

Declare Function toByte Lib "LowTool" Alias "rV" (ByVal val As Long) As Byte
Declare Function toWord Lib "LowTool" Alias "rV" (ByVal val As Long) As Integer
Declare Function toLong Lib "LowTool" Alias "rV" (ByVal val As Long) As Long
Declare Function toStr Lib "LowTool" Alias "rV" (ByVal address As Long) As String

Declare Function toBytes Lib "LowTool" Alias "rV" (ByVal address As Long) As Byte()
Declare Function toWords Lib "LowTool" Alias "rV" (ByVal address As Long) As Integer()
Declare Function toLongs Lib "LowTool" Alias "rV" (ByVal address As Long) As Long()
Declare Function toStrings Lib "LowTool" Alias "rV" (ByVal address As Long) As String()

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

' ADVANCE VB CALLBACK
Declare Function callFunction0 Lib "LowTool" Alias "CF0" (ByVal lpcallback As Long) As Long
Declare Function callFunction1 Lib "LowTool" Alias "CF1" (ByVal lpcallback As Long, ByVal parameter1 As Long) As Long
Declare Function callFunction2 Lib "LowTool" Alias "CF2" (ByVal lpcallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long) As Long
Declare Function callFunction3 Lib "LowTool" Alias "CF4" (ByVal lpcallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long) As Long
Declare Function callFunction4 Lib "LowTool" Alias "CF4" (ByVal lpcallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long, ByVal parameter4 As Long) As Long
Declare Sub callProcedure0 Lib "LowTool" Alias "CP0" (ByVal lpcallback As Long)
Declare Sub callProcedure1 Lib "LowTool" Alias "CP1" (ByVal lpcallback As Long, ByVal parameter1 As Long)
Declare Sub callProcedure2 Lib "LowTool" Alias "CP2" (ByVal lpcallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long)
Declare Sub callProcedure3 Lib "LowTool" Alias "CP4" (ByVal lpcallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long)
Declare Sub callProcedure4 Lib "LowTool" Alias "CP4" (ByVal lpcallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long, ByVal parameter4 As Long)

Public Enum callPrototype
        protopascal = 0
        protostdcall = 0
        protocdecl = 1
        protofastcall = 1
End Enum
Declare Function callPascal Lib "LowTool" Alias "_CS" (ByVal lpcallback As Long, ByVal vacount As Long, ByVal extra_release As Long, ByVal pva As Long) As Long
Declare Function callCdecl Lib "LowTool" Alias "_CC" (ByVal lpcallback As Long, ByVal vacount As Long, ByVal extra_release As Long, ByVal pva As Long) As Long

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
'       WNDPROC switchproc(WNDPROC oldproc)
Declare Function catchMessage Lib "LowTool" Alias "Mcatch" (ByVal hWnd As Long, ByVal switchprocProc As Long) As Long
Declare Function chainMessage Lib "LowTool" Alias "Mchain" (ByVal wndproc As Long, ByVal hWnd As Long, ByVal message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long

' DEBUG
'Declare Function vbtString Lib "LowTool" (ByVal Index As Integer) As String
'Declare Function vbtString2 Lib "LowTool" Alias "vbtString" (ByVal Index As Integer) As Long
'Declare Sub lower Lib "LowTool" Alias "lowerString" (ByVal str As String)

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
        Dim vacount As Long

        vacount = UBound(va) - LBound(va) + 1
        ReDim pva(0 To vacount - 1) As Long

        For i = LBound(va) To UBound(va)
                pva(i - LBound(va)) = va(i)
        Next

        Select Case proto
        Case protopascal Or protostdcall
                callFunc = callPascal(proc, vacount, extra_release, pLong(pva(0)))
        Case protocdecl Or protofastcall
                callFunc = callCdecl(proc, vacount, extra_release, pLong(pva(0)))
        End Select
End Function
