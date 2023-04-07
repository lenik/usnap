# Microsoft Developer Studio Project File - Name="YourProject" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=YourProject - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "YourProject.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "YourProject.mak" CFG="YourProject - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "YourProject - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "YourProject - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "YourProject - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "YourProject - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ  /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "YourProject - Win32 Release"
# Name "YourProject - Win32 Debug"
# Begin Group "_vc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "script"

# PROP Default_Filter ""
# Begin Group "imp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\lex.backup
# End Source File
# Begin Source File

SOURCE=.\ResultContext.h
# End Source File
# Begin Source File

SOURCE=.\YTMF_gy.cpp

!IF  "$(CFG)" == "YourProject - Win32 Release"

!ELSEIF  "$(CFG)" == "YourProject - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\YTMF_gy.cpp.h
# End Source File
# Begin Source File

SOURCE=.\YTMF_gy.cpp.output
# End Source File
# Begin Source File

SOURCE=.\YTMF_ll.cpp

!IF  "$(CFG)" == "YourProject - Win32 Release"

!ELSEIF  "$(CFG)" == "YourProject - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\YTMF_script.cpp
# End Source File
# Begin Source File

SOURCE=.\YTMF_script.h
# End Source File
# Begin Source File

SOURCE=.\YTMF_util.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\YTMF_g.y

!IF  "$(CFG)" == "YourProject - Win32 Release"

# Begin Custom Build - generating grammer parser...
InputDir=.
InputPath=.\YTMF_g.y
InputName=YTMF_g

"$(InputDir)\$(InputName)y.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
    lalrc -v -d -p YTMF -b lc -o $(InputDir)\$(InputName)y.cpp $(InputDir)\$(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "YourProject - Win32 Debug"

# Begin Custom Build - generating grammer parser...
InputDir=.
InputPath=.\YTMF_g.y
InputName=YTMF_g

"$(InputDir)\$(InputName)y.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
    lalrc -v -d -p YTMF -b lc -o $(InputDir)\$(InputName)y.cpp $(InputDir)\$(InputName).y

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\YTMF_l.l

!IF  "$(CFG)" == "YourProject - Win32 Release"

# Begin Custom Build - generating lexical parser...
InputDir=.
InputPath=.\YTMF_l.l
InputName=YTMF_l

"$(InputDir)\$(InputName)l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
    flex -+ -Cr -PYTMF -b -o$(InputDir)\$(InputName)l.cpp $(InputDir)\$(InputName).l

# End Custom Build

!ELSEIF  "$(CFG)" == "YourProject - Win32 Debug"

# Begin Custom Build - generating lexical parser...
InputDir=.
InputPath=.\YTMF_l.l
InputName=YTMF_l

"$(InputDir)\$(InputName)l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
    flex -+ -Cr -PYTMF -b -o$(InputDir)\$(InputName)l.cpp $(InputDir)\$(InputName).l

# End Custom Build

!ENDIF

# End Source File
# End Group
# Begin Group "program"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\YTMF.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
