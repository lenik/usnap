# Microsoft Developer Studio Project File - Name="c4" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=c4 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "c4.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "c4.mak" CFG="c4 - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "c4 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "c4 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "c4 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x417 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x00400000" /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "c4 - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "c4 - Win32 Release"
# Name "c4 - Win32 Debug"
# Begin Group "c4"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\c4.cpp
# End Source File
# Begin Source File

SOURCE=.\c4.rc
# End Source File
# Begin Source File

SOURCE=.\c4_type.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "posic"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=Z:\s\t\posw\pos\pos\pos.h
# End Source File
# Begin Source File

SOURCE=.\poy_nodes.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\poy_nodes.h
# End Source File
# End Group
# Begin Group "script"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\lex.backup
# End Source File
# Begin Source File

SOURCE=.\sg_g.y

!IF  "$(CFG)" == "c4 - Win32 Release"

# Begin Custom Build - parse sg_g.y
InputDir=.
InputPath=.\sg_g.y
InputName=sg_g

"$(InputDir)\$(InputName)y.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	lalrc -v -d -p SimGraph -b lc -o $(InputDir)\$(InputName)y.cpp $(InputDir)\$(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "c4 - Win32 Debug"

# Begin Custom Build - parse sg_g.y
InputDir=.
InputPath=.\sg_g.y
InputName=sg_g

"$(InputDir)\$(InputName)y.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	lalrc -v -d -p SimGraph -b lc -o $(InputDir)\$(InputName)y.cpp $(InputDir)\$(InputName).y

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\sg_gy.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\sg_gy.cpp.h
# End Source File
# Begin Source File

SOURCE=.\sg_gy.cpp.output
# End Source File
# Begin Source File

SOURCE=.\sg_l.l

!IF  "$(CFG)" == "c4 - Win32 Release"

# Begin Custom Build - parse sg_l.l
InputDir=.
InputPath=.\sg_l.l
InputName=sg_l

"$(InputDir)\$(InputName)l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex -+ -Cr -PSimGraph -b -o$(InputDir)\$(InputName)l.cpp $(InputDir)\$(InputName).l

# End Custom Build

!ELSEIF  "$(CFG)" == "c4 - Win32 Debug"

# Begin Custom Build - parse sg_l.l
InputDir=.
InputPath=.\sg_l.l
InputName=sg_l

"$(InputDir)\$(InputName)l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex -+ -Cr -PSimGraph -b -o$(InputDir)\$(InputName)l.cpp $(InputDir)\$(InputName).l

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\sg_ll.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\sg_script.cpp
# End Source File
# Begin Source File

SOURCE=.\sg_script.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\N1992.in
# End Source File
# Begin Source File

SOURCE=".\N9-1.in"
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
