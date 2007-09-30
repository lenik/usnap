Attribute VB_Name = "modVBTool02"

' 桃壳高科技 效率工程 | 开发工具效率挖掘计划
' Visual Studio 系列
' Visual Basic 底层扩展工具 - 2 高速缓存
'
' 本扩展使用了:
'       桃壳高科技底层扩展工具  LowTool Release 4
'       桃壳高科技高速缓存      EMemory
'
' 版权所有(C) 桃壳高科技 2000-2001

Option Explicit

Enum ShowType
        asHex = 0
        asDec = 1
        asStr = 2
End Enum

Type BUFFERTYPE
        lpData   As Long
        unitsize As Long

        usednum As Long
        deltanum As Long
        allocnum As Long

        handle As Long
End Type

Declare Function EMfuncswitch Lib "EMemory" Alias "EMemory_funcswitch" (ByVal bAsGlobal As Boolean) As Boolean
Declare Function EMsetflags Lib "EMemory" Alias "EMemory_setflags" (ByVal newflags As Long) As Long
Declare Function EMresetvar Lib "EMemory" Alias "EMemory_resetvar" () As Boolean

Declare Function EMalloc Lib "EMemory" Alias "AllocMemory" (ByVal Size As Long, saveHandle As Long) As Long
Declare Function EMrealloc Lib "EMemory" Alias "ReallocMemory" (ByVal newsize As Long, saveHandle As Long) As Long
Declare Function EMfree Lib "EMemory" Alias "FreeMemory" (saveHandle As Long) As Boolean

Declare Function EBsize Lib "EMemory" Alias "EBuffer_setsize" (ByRef lpb As BUFFERTYPE, ByVal newsize As Long) As Boolean
Declare Function EBclear Lib "EMemory" Alias "EBuffer_clear" (ByRef lpb As BUFFERTYPE) As Boolean
Declare Function EBcompress Lib "EMemory" Alias "EBuffer_compress" (ByRef lpb As BUFFERTYPE) As Boolean

Declare Function EBset Lib "EMemory" Alias "EBuffer_setelement" (ByRef lpb As BUFFERTYPE, ByVal Index As Long, ByVal lpelement As Long, Optional ByVal Size As Long = -1) As Boolean
Declare Function EBget Lib "EMemory" Alias "EBuffer_getelement" (ByRef lpb As BUFFERTYPE, ByVal Index As Long) As Long
Declare Function EBmove Lib "EMemory" Alias "EBuffer_moveelement" (ByRef lpb As BUFFERTYPE, ByVal fromindex As Long, ByVal toindex As Long) As Boolean

Declare Function EBappend Lib "EMemory" Alias "EBuffer_appendelement" (ByRef lpb As BUFFERTYPE, ByVal lpelement As Long, Optional ByVal Size As Long = -1) As Long
Declare Function EBinsert Lib "EMemory" Alias "EBuffer_insertelement" (ByRef lpb As BUFFERTYPE, ByVal insertindex As Long, ByVal lpelement As Long, Optional ByVal Size As Long = -1) As Boolean
Declare Function EBdelete Lib "EMemory" Alias "EBuffer_deleteelement" (ByRef lpb As BUFFERTYPE, ByVal deleteindex As Long, Optional ByVal Num As Long = 1) As Boolean

Declare Function EB_P_size Lib "EMemory" Alias "EBuffer_setsize" (ByVal lpb As Long, ByVal newsize As Long) As Boolean
Declare Function EB_P_clear Lib "EMemory" Alias "EBuffer_clear" (ByVal lpb As Long) As Boolean
Declare Function EB_P_compress Lib "EMemory" Alias "EBuffer_compress" (ByVal lpb As Long) As Boolean

Declare Function EB_P_set Lib "EMemory" Alias "EBuffer_setelement" (ByVal lpb As Long, ByVal Index As Long, ByVal lpelement As Long, Optional ByVal Size As Long = -1) As Boolean
Declare Function EB_P_get Lib "EMemory" Alias "EBuffer_getelement" (ByVal lpb As Long, ByVal Index As Long) As Long
Declare Function EB_P_move Lib "EMemory" Alias "EBuffer_moveelement" (ByVal lpb As Long, ByVal fromindex As Long, ByVal toindex As Long) As Boolean

Declare Function EB_P_append Lib "EMemory" Alias "EBuffer_appendelement" (ByVal lpb As Long, ByVal lpelement As Long, Optional ByVal Size As Long = -1) As Long
Declare Function EB_P_insert Lib "EMemory" Alias "EBuffer_insertelement" (ByVal lpb As Long, ByVal insertindex As Long, ByVal lpelement As Long, Optional ByVal Size As Long = -1) As Boolean
Declare Function EB_P_delete Lib "EMemory" Alias "EBuffer_deleteelement" (ByVal lpb As Long, ByVal deleteindex As Long, Optional ByVal Num As Long = 1) As Boolean

Public Function EB_P_make(ByVal lpb As Long) As BUFFERTYPE
        copyBytes pAny(EB_P_make), lpb, Len(EB_P_make)
End Function
