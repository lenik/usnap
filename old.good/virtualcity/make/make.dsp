# Microsoft Developer Studio Project File - Name="make" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=make - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "make.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "make.mak" CFG="make - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "make - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "make - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "make - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "make - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "make - Win32 Release"
# Name "make - Win32 Debug"
# Begin Group "源文件"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\coDevelopHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\src\coError.cpp
# End Source File
# Begin Source File

SOURCE=..\src\coGuider.cpp
# End Source File
# Begin Source File

SOURCE=..\src\coModel.cpp
# End Source File
# Begin Source File

SOURCE=..\src\coRouter.cpp
# End Source File
# Begin Source File

SOURCE=..\src\coType.cpp
# End Source File
# End Group
# Begin Group "头文件"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "unix"

# PROP Default_Filter ""
# Begin Group "stl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\include\stl\Algo.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Algobase.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Bool.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Bvector.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Defalloc.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Deque.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Faralloc.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Fdeque.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Flist.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Fmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Fmultmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Fmultset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Fset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Function.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hdeque.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Heap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hlist.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hmultmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hmultset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hugalloc.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Hvector.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Iterator.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Lbvector.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Ldeque.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\List.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Llist.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Lmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Lmultmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Lmultset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Lngalloc.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Lset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Map.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Multimap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Multiset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Neralloc.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Nmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Nmultmap.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Nmultset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Nset.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Pair.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Projectn.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Set.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Stack.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Tempbuf.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Tree.h
# End Source File
# Begin Source File

SOURCE=..\include\stl\Vector.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=..\include\coDef.h
# End Source File
# Begin Source File

SOURCE=..\include\coError.h
# End Source File
# Begin Source File

SOURCE=..\include\coGuider.h
# End Source File
# Begin Source File

SOURCE=..\include\coModel.h
# End Source File
# Begin Source File

SOURCE=..\include\coRouter.h
# End Source File
# Begin Source File

SOURCE=..\include\coType.h
# End Source File
# End Group
# Begin Group "资源文件"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "文档"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\docs\com_structure.txt
# End Source File
# Begin Source File

SOURCE="..\docs\对象语言注.txt"
# End Source File
# Begin Source File

SOURCE="..\docs\路线扩展.txt"
# End Source File
# End Group
# End Target
# End Project
