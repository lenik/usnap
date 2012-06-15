Attribute VB_Name = "modmemory"
Option Explicit

' 建立堆对象，返回堆句柄
Declare Function HeapCreate Lib "kernel32" (ByVal flOptions As Long, ByVal dwInitialSize As Long, ByVal dwMaximumSize As Long) As Long
' 删除堆对象，参数hHeap指定堆句柄
Declare Function HeapDestroy Lib "kernel32" (ByVal hHeap As Long) As Boolean
' 在堆对象中分配内存空间，返回分配空间起始地址
Declare Function HeapAlloc Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal dwBytes As Long) As Long
' 重新分配(堆中的)内存空间的大小
Declare Function HeapReAlloc Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal lpMem As Long, ByVal dwBytes As Long) As Long
' 释放(堆中的)内存
Declare Function HeapFree Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal lpMem As Long) As Boolean
' 返回(堆中的)内存大小
Declare Function HeapSize Lib "kernel32" (ByVal hHeap As Long, ByVal dwFlags As Long, ByVal lpMem As Long) As Long

Public heap As Long
Public hstart As Long
Public hsize As Long

' 程序最大支持分析 HEAPMAXSIZE / 4 大的进程内存空间
' 这是因为分析数据的每一项都是进程内存字节的地址
Public Const MAXSIZE            As Long = 1000000
Public Const HEAPMAXSIZE        As Long = MAXSIZE * 4

' 增加分析点，返回加入该分析点后找到的符合分析条件的结果数。
' hstart 是用于分析内存的临时缓存，size指出该缓存的大小
' val 是本次分析用的值。函数将从缓存中删去所有值不等于val的单元
Public Function AddAnalyse(hProcess As Long, val As Byte) As Long
        Dim ua As Long, uv As Byte, i As Long, j As Long

        j = 0
        ' 遍历缓存中的每个单元
        For i = 0 To hsize / 4 - 1
                ua = returnLong(hstart, i * 4)

                Dim cread As Long
                ' 获取进程hProcess中第ua地址单元的值
                ReadProcessMemory hProcess, ua, uv, 1, cread

                If uv = val Then
                ' 将符合分析条件的单元移到左边、用于将结果整理成连续的空间
                        forceLong hstart, j * 4, ua
                        j = j + 1
                End If
        Next

        hsize = j * 4
End Function

' 分析复位
Public Sub ResetAnalyse(hProcess As Long, start As Long, size As Long)
        Dim i As Long
        Dim pstart As Long, pend As Long

        ' 如果堆已经建立，则删除
        If heap <> 0 Then HeapDestroy heap

        ' 重新建立一个新的堆
        heap = HeapCreate(0, HEAPMAXSIZE, 0)

        ' 要分配的空间为单元数目的4倍。分配空间中的每个单元用于存放地址
        hsize = size * 4
        ' 在堆heap中分配空间
        hstart = HeapAlloc(heap, 0, hsize)

        ' 如果建立堆失败或者分配空间失败
        If heap = 0 Or hstart = 0 Then
                MsgBox "无法分配足够的内存用于分析"
                Exit Sub
        End If

        ' 初始化堆空间，将 start 至 end 的每个地址放入堆空间中。
        For i = 0 To size - 1
                forceNLong hstart, i, start + i
        Next
End Sub

' 获取分析结果，返回分析结果数组
Public Function GetAnalyse(hProcess As Long)
        ReDim r(0 To hsize / 4 - 1, 0 To 1) As Long
        Dim i As Long, cread As Long
        ' 列举堆空间中的每一项
        For i = 0 To hsize / 4 - 1
                ' 将每一项的地址内容放入数组r的第一个下标中
                r(i, 0) = returnLong(hstart, i * 4)
                Dim b As Byte
                ' 将每一项的地址内容对应的进程内存数值放入数组第二个下标中
                ReadProcessMemory hProcess, r(i, 0), b, 1, cread
                r(i, 1) = b
        Next
        ' 将数组 r 返回
        GetAnalyse = r
End Function
