# Microsoft Developer Studio Project File - Name="lastbison" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=lastbison - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "lastbison.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "lastbison.mak" CFG="lastbison - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "lastbison - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "lastbison - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lastbison - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "STDC_HEADERS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /out:"Z:\t\w\LALRc.exe"

!ELSEIF  "$(CFG)" == "lastbison - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "STDC_HEADERS" /YX /FD /GZ /c
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

# Name "lastbison - Win32 Release"
# Name "lastbison - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\alloca.c
# End Source File
# Begin Source File

SOURCE=.\allocate.c
# End Source File
# Begin Source File

SOURCE=.\closure.c
# End Source File
# Begin Source File

SOURCE=.\conflicts.c
# End Source File
# Begin Source File

SOURCE=.\derives.c
# End Source File
# Begin Source File

SOURCE=.\files.c
# End Source File
# Begin Source File

SOURCE=.\getargs.c
# End Source File
# Begin Source File

SOURCE=.\getopt.c
# End Source File
# Begin Source File

SOURCE=.\getopt1.c
# End Source File
# Begin Source File

SOURCE=.\gram.c
# End Source File
# Begin Source File

SOURCE=.\lalr.c
# End Source File
# Begin Source File

SOURCE=.\lex.c
# End Source File
# Begin Source File

SOURCE=.\LR0.c
# End Source File
# Begin Source File

SOURCE=.\main.c
# End Source File
# Begin Source File

SOURCE=.\main_escstr.cpp
# End Source File
# Begin Source File

SOURCE=.\nullable.c
# End Source File
# Begin Source File

SOURCE=.\output.c
# End Source File
# Begin Source File

SOURCE=.\print.c
# End Source File
# Begin Source File

SOURCE=.\reader.c
# End Source File
# Begin Source File

SOURCE=.\reduce.c
# End Source File
# Begin Source File

SOURCE=.\symtab.c
# End Source File
# Begin Source File

SOURCE=.\version.c
# End Source File
# Begin Source File

SOURCE=.\warshall.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\files.h
# End Source File
# Begin Source File

SOURCE=.\getopt.h
# End Source File
# Begin Source File

SOURCE=.\gram.h
# End Source File
# Begin Source File

SOURCE=.\lex.h
# End Source File
# Begin Source File

SOURCE=.\machine.h
# End Source File
# Begin Source File

SOURCE=.\new.h
# End Source File
# Begin Source File

SOURCE=.\state.h
# End Source File
# Begin Source File

SOURCE=.\stdex.h
# End Source File
# Begin Source File

SOURCE=.\symtab.h
# End Source File
# Begin Source File

SOURCE=.\system.h
# End Source File
# Begin Source File

SOURCE=.\types.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\bison.hairy
# End Source File
# Begin Source File

SOURCE=.\bison.simple
# End Source File
# Begin Source File

SOURCE=.\lastbison.rc
# End Source File
# End Group
# Begin Group "up"

# PROP Default_Filter ""
# Begin Group "gen"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\escstr_lex.cpp
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=.\escstr.cpp
# End Source File
# Begin Source File

SOURCE=.\escstr.h
# End Source File
# Begin Source File

SOURCE=.\escstr_lex.lex

!IF  "$(CFG)" == "lastbison - Win32 Release"

# Begin Custom Build - parsing lexical script
InputDir=.
InputPath=.\escstr_lex.lex
InputName=escstr_lex

"$(InputDir)\$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex -+ -Cr -v -PLastBisonLex -o$(InputDir)\$(InputName).cpp $(InputPath)

# End Custom Build

!ELSEIF  "$(CFG)" == "lastbison - Win32 Debug"

# Begin Custom Build - parsing lexical script
InputDir=.
InputPath=.\escstr_lex.lex
InputName=escstr_lex

"$(InputDir)\$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex -+ -Cr -v -PLastBisonLex -o$(InputDir)\$(InputName).cpp $(InputPath)

# End Custom Build

!ENDIF

# End Source File
# End Group
# End Target
# End Project
