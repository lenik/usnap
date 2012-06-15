# Microsoft Developer Studio Project File - Name="OeSO" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=OeSO - Win32 Debug COM
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "OeSO.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "OeSO.mak" CFG="OeSO - Win32 Debug COM"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "OeSO - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OeSO - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OeSO - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OeSO - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OeSO - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OeSO - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OeSO - Win32 Debug COM" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OeSO - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\OeSO.dll
InputPath=.\Debug\OeSO.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=.\DebugU\OeSO.dll
InputPath=.\DebugU\OeSO.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT
	if not "%OS%"=="Windows_NT" goto NOTNT
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
	goto end
	:NOTNT
	echo Warning : Cannot register Unicode DLL on Windows 95
	:end

# End Custom Build

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinSize"
# PROP BASE Intermediate_Dir "ReleaseMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinSize"
# PROP Intermediate_Dir "ReleaseMinSize"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\OeSO.dll
InputPath=.\ReleaseMinSize\OeSO.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\OeSO.dll
InputPath=.\ReleaseMinDependency\OeSO.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinSize"
# PROP BASE Intermediate_Dir "ReleaseUMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinSize"
# PROP Intermediate_Dir "ReleaseUMinSize"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\OeSO.dll
InputPath=.\ReleaseUMinSize\OeSO.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT
	if not "%OS%"=="Windows_NT" goto NOTNT
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
	goto end
	:NOTNT
	echo Warning : Cannot register Unicode DLL on Windows 95
	:end

# End Custom Build

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinDependency"
# PROP BASE Intermediate_Dir "ReleaseUMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinDependency"
# PROP Intermediate_Dir "ReleaseUMinDependency"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\OeSO.dll
InputPath=.\ReleaseUMinDependency\OeSO.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT
	if not "%OS%"=="Windows_NT" goto NOTNT
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
	goto end
	:NOTNT
	echo Warning : Cannot register Unicode DLL on Windows 95
	:end

# End Custom Build

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "OeSO___Win32_Debug_COM"
# PROP BASE Intermediate_Dir "OeSO___Win32_Debug_COM"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "OeSO___Win32_Debug_COM"
# PROP Intermediate_Dir "OeSO___Win32_Debug_COM"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DEBUG_INTERFACES" /D "_ATL_DEBUG_QI" /D "_ATL_DEBUG_REFCOUNT" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\OeSO___Win32_Debug_COM
TargetPath=.\OeSO___Win32_Debug_COM\OeSO.dll
InputPath=.\OeSO___Win32_Debug_COM\OeSO.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ENDIF

# Begin Target

# Name "OeSO - Win32 Debug"
# Name "OeSO - Win32 Unicode Debug"
# Name "OeSO - Win32 Release MinSize"
# Name "OeSO - Win32 Release MinDependency"
# Name "OeSO - Win32 Unicode Release MinSize"
# Name "OeSO - Win32 Unicode Release MinDependency"
# Name "OeSO - Win32 Debug COM"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "C.Misc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\OeSO.cpp
# End Source File
# Begin Source File

SOURCE=.\OeSO.def
# End Source File
# Begin Source File

SOURCE=.\OeSO.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "C.外观(Facade)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\impls\OeSOCompiler.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOEvaluator.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOParser.h
# End Source File
# End Group
# Begin Group "C.基本对象"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\impls\OeSOAttribute.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOClass.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOEvent.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOInterface.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOMethod.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOObject.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOStatus.h
# End Source File
# End Group
# Begin Group "C.集合对象"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\impls\OeSOAttributesCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOClassesCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOEventsCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOInterfacesCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOMethodsCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOObjectsCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\impls\OeSOStatusesCollection.h
# End Source File
# End Group
# Begin Group "C.应用体"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\impls\OeSOApplication.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\objects.cpp
# End Source File
# Begin Source File

SOURCE=.\OeSO.idl
# ADD MTL /tlb ".\OeSO.tlb" /h "OeSO.h" /iid "OeSO_i.c" /Oicf
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "H.外观(Facade)"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\OeSOCompiler.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEvaluator.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOParser.h
# End Source File
# End Group
# Begin Group "H.基本对象"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\OeSOAttribute.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOClass.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEvent.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOInterface.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOMethod.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOObject.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOStatus.h
# End Source File
# End Group
# Begin Group "H.集合对象"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\OeSOAttributesCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOClassesCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEventsCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOInterfacesCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOMethodsCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOObjectsCollection.h
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOStatusesCollection.h
# End Source File
# End Group
# Begin Group "H.应用体"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\OeSOApplication.h
# End Source File
# End Group
# Begin Group "H.Misc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Debug\msxml.tlh
# End Source File
# Begin Source File

SOURCE=.\Debug\msxml3.tlh
# End Source File
# Begin Source File

SOURCE=.\OeSODeclares.h
# End Source File
# Begin Source File

SOURCE=.\OeSODispids.h
# End Source File
# Begin Source File

SOURCE=.\Debug\OeT.tlh
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\IOeSOCollection.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\attribut.ico
# End Source File
# Begin Source File

SOURCE=.\class.ico
# End Source File
# Begin Source File

SOURCE=.\compiler.ico
# End Source File
# Begin Source File

SOURCE=.\evaluato.ico
# End Source File
# Begin Source File

SOURCE=.\event.ico
# End Source File
# Begin Source File

SOURCE=.\event1.ico
# End Source File
# Begin Source File

SOURCE=.\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\interfac.ico
# End Source File
# Begin Source File

SOURCE=.\object.ico
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOApplication.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOAttribute.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOAttributesCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOClass.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOClassesCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOCompiler.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEvaluator.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEvent.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEventsCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOInterface.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOInterfacesCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOMethod.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOMethodsCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOObject.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOObjectsCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOParser.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOStatus.rgs
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOStatusesCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\parser.ico
# End Source File
# End Group
# Begin Group "文档"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objects\OeSOApplication.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOAttribute.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOAttributesCollection.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOClass.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOClassesCollection.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOCompiler.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEvaluator.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEvent.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOEventsCollection.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOInterface.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOInterfacesCollection.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOMethod.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOMethodsCollection.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOObject.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOObjectsCollection.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOParser.txt

!IF  "$(CFG)" == "OeSO - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinSize"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Unicode Release MinDependency"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "OeSO - Win32 Debug COM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\objects\OeSOStatus.txt
# End Source File
# Begin Source File

SOURCE=.\objects\OeSOStatusesCollection.txt
# End Source File
# End Group
# End Target
# End Project
