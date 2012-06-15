# Microsoft Developer Studio Project File - Name="libcpf_static" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libcpf_static - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "libcpf_static.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "libcpf_static.mak" CFG="libcpf_static - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "libcpf_static - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libcpf_static - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "libcpf_static - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../../../config" /I "../../../inc" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../lib/cpf/libcpf.lib"

!ELSEIF  "$(CFG)" == "libcpf_static - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../../config" /I "../../../inc" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../lib/cpf/libcpf_chk.lib"

!ENDIF

# Begin Target

# Name "libcpf_static - Win32 Release"
# Name "libcpf_static - Win32 Debug"
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\cpf\src\const\bitinfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\cpf\src\dt\buffer.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\libcall\dynasub.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\cpf\src\getopt.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\cpf\src\dt\list.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\cpf\src\mcell\mcell.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\cpf\src\alg\sort\qsort_.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\test\stl.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\cpf\src\string.c
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\inc\cpf\const\bitinfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\dt\buffer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\dynasub.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\dt\list.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\alg\sort\qsort_.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\dt\raw.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\mcell\somt.h
# End Source File
# Begin Source File

SOURCE=..\..\..\config\stdhdrs.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\test\stl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\string.h
# End Source File
# Begin Source File

SOURCE=..\..\..\inc\cpf\dt\tree.h
# End Source File
# End Group
# End Target
# End Project
