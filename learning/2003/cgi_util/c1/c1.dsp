# Microsoft Developer Studio Project File - Name="c1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=c1 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "c1.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "c1.mak" CFG="c1 - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "c1 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "c1 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "c1 - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "W:\CGI-BIN\ACGI\INCLUDE" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_CPPRTTI" /YX /FD /c
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

!ELSEIF  "$(CFG)" == "c1 - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "W:\cgi-bin\acgi\include" /I "W:\CGI-BIN\ACGI\INCLUDE" /D "_DEBUG" /D "_CPPRTTI" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
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

# Name "c1 - Win32 Release"
# Name "c1 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "acgi.src"

# PROP Default_Filter ""
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_ANSI.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_ARRAY.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_BASE.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_BELEM.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_BITARY.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_CONV.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_CRYPTO.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_DATAI.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_ELEM.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_ELIST.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_FLIST.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_FORMI.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_GLOBAL.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_HTML.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_LIST.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_PAIRI.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_PLIST.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_RANDOM.CPP"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SRC\A_STREAM.CPP"
# End Source File
# End Group
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\SAMPLES\HTML_EX.CPP"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_ACGI.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_ARRAY.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_BASE.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_CONV.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_ELIST.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_FORM.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_GLOBAL.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_LIST.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_PREDEF.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_RANDOM.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_STREAM.H"
# End Source File
# Begin Source File

SOURCE="W:\cgi-bin\ACGI\INCLUDE\A_STRUCT.H"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
