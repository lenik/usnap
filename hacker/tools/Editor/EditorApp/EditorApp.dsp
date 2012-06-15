# Microsoft Developer Studio Project File - Name="EditorApp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=EditorApp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "EditorApp.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "EditorApp.mak" CFG="EditorApp - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "EditorApp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "EditorApp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "EditorApp - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "EditorApp - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ  /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ   /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "EditorApp - Win32 Release"
# Name "EditorApp - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\EditorApp.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditorApp.hpj

!IF  "$(CFG)" == "EditorApp - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__EDITO=hlp\AfxCore.rtf	hlp\AfxPrint.rtf	hlp\$(TargetName).hm
# Begin Custom Build - Making help file...
OutDir=.\Release
TargetName=EditorApp
InputPath=.\hlp\EditorApp.hpj
InputName=EditorApp

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj"
	if errorlevel 1 goto :Error
	if not exist "hlp\$(InputName).hlp" goto :Error
	copy "hlp\$(InputName).hlp" $(OutDir)
	goto :done
	:Error
	echo hlp\$(InputName).hpj(1) : error:
	type "hlp\$(InputName).log"
	:done

# End Custom Build

!ELSEIF  "$(CFG)" == "EditorApp - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__EDITO=hlp\AfxCore.rtf	hlp\AfxPrint.rtf	hlp\$(TargetName).hm
# Begin Custom Build - Making help file...
OutDir=.\Debug
TargetName=EditorApp
InputPath=.\hlp\EditorApp.hpj
InputName=EditorApp

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj"
	if errorlevel 1 goto :Error
	if not exist "hlp\$(InputName).hlp" goto :Error
	copy "hlp\$(InputName).hlp" $(OutDir)
	goto :done
	:Error
	echo hlp\$(InputName).hpj(1) : error:
	type "hlp\$(InputName).log"
	:done

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\EditorApp.rc
# End Source File
# Begin Source File

SOURCE=.\EditorAppDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\EditorAppView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\EditorApp.h
# End Source File
# Begin Source File

SOURCE=.\EditorAppDoc.h
# End Source File
# Begin Source File

SOURCE=.\EditorAppView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "EditorApp - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=EditorApp
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm"
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm"
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm"
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm"
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm"
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm"
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm"

# End Custom Build

!ELSEIF  "$(CFG)" == "EditorApp - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=EditorApp
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm"
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm"
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm"
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm"
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm"
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo. >>"hlp\$(TargetName).hm"
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm"
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm"

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\EditorApp.ico
# End Source File
# Begin Source File

SOURCE=.\res\EditorApp.rc2
# End Source File
# Begin Source File

SOURCE=.\res\EditorAppDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AfxPrint.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditorApp.cnt

!IF  "$(CFG)" == "EditorApp - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\EditorApp.cnt
InputName=EditorApp

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "EditorApp - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\EditorApp.cnt
InputName=EditorApp

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecFirst.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecLast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecNext.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecPrev.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp
# End Source File
# End Group
# Begin Group "Interface"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\EditorApp.odl
# End Source File
# Begin Source File

SOURCE=.\EditorApp.reg
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
