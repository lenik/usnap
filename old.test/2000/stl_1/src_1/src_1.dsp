# Microsoft Developer Studio Project File - Name="src_1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=src_1 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "src_1.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "src_1.mak" CFG="src_1 - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "src_1 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "src_1 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "src_1 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "src_1 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "src_1 - Win32 Release"
# Name "src_1 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\src_1.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\algorithm"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\BITSET"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CASSERT"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CCTYPE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CERRNO"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CERTSRV"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CFLOAT"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CISO646"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CLIMITS"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CLOCALE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CMATH"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\COMPLEX"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CSETJMP"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CSIGNAL"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CSTDARG"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CSTDDEF"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CSTDIO"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CSTDLIB"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CSTRING"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CTIME"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CWCHAR"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\CWCTYPE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\DEQUE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\exception"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\FSTREAM"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\functional"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\IOMANIP"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\IOS"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\IOSFWD"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\IOSTREAM"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\ISTREAM"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\ITERATOR"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\LIMITS"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\LIST"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\LOCALE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\MAP"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\MEMORY"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\NEW"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\NUMERIC"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\OSTREAM"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\QUEUE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\SET"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\SSTREAM"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\STACK"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\stdexcept"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\streambuf"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\STRING"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\strstream"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\TYPEINFO"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\UTILITY"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\VALARRAY"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\VECTOR"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\VERFILE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XCOMPLEX"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XIOSBASE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XLOCALE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XLOCINFO"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XLOCMON"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XLOCNUM"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XLOCTIME"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XMEMORY"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XSTDDEF"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XSTRING"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XTREE"
# End Source File
# Begin Source File

SOURCE="E:\Program Files\Microsoft Visual Studio\VC98\Include\XUTILITY"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
