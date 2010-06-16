# Microsoft Developer Studio Project File - Name="XEditBox" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=XEditBox - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "XEditBox.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "XEditBox.mak" CFG="XEditBox - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "XEditBox - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XEditBox - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XEditBox - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XEditBox - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "XEditBox - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\Release
TargetPath=.\Release\XEditBox.ocx
InputPath=.\Release\XEditBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ  /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ    /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\Debug
TargetPath=.\Debug\XEditBox.ocx
InputPath=.\Debug\XEditBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ    /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ  /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\DebugU
TargetPath=.\DebugU\XEditBox.ocx
InputPath=.\DebugU\XEditBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseU"
# PROP BASE Intermediate_Dir "ReleaseU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseU"
# PROP Intermediate_Dir "ReleaseU"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\ReleaseU
TargetPath=.\ReleaseU\XEditBox.ocx
InputPath=.\ReleaseU\XEditBox.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"

# End Custom Build

!ENDIF

# Begin Target

# Name "XEditBox - Win32 Release"
# Name "XEditBox - Win32 Debug"
# Name "XEditBox - Win32 Unicode Debug"
# Name "XEditBox - Win32 Unicode Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\XEditBox.cpp
# End Source File
# Begin Source File

SOURCE=.\XEditBox.def
# End Source File
# Begin Source File

SOURCE=.\XEditBox.hpj

!IF  "$(CFG)" == "XEditBox - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help ...
OutDir=.\Release
InputPath=.\XEditBox.hpj
InputName=XEditBox

BuildCmds= \
	start /wait hcw /C /E /M "$(InputName).hpj" \
	if errorlevel 1 goto :Error \
	if not exist "$(InputName).hlp" goto :Error \
	copy "$(InputName).hlp" $(OutDir) \
	goto :done \
	:Error \
	echo $(InputName).hpj(1) : error: Problem encountered creating help file \
	type $(InputName).log \
	:done \


"$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help ...
OutDir=.\Debug
InputPath=.\XEditBox.hpj
InputName=XEditBox

BuildCmds= \
	start /wait hcw /C /E /M "$(InputName).hpj" \
	if errorlevel 1 goto :Error \
	if not exist "$(InputName).hlp" goto :Error \
	copy "$(InputName).hlp" $(OutDir) \
	goto :done \
	:Error \
	echo $(InputName).hpj(1) : error: Problem encountered creating help file \
	type $(InputName).log \
	:done \


"$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help ...
OutDir=.\DebugU
InputPath=.\XEditBox.hpj
InputName=XEditBox

BuildCmds= \
	start /wait hcw /C /E /M "$(InputName).hpj" \
	if errorlevel 1 goto :Error \
	if not exist "$(InputName).hlp" goto :Error \
	copy "$(InputName).hlp" $(OutDir) \
	goto :done \
	:Error \
	echo $(InputName).hpj(1) : error: Problem encountered creating help file \
	type $(InputName).log \
	:done \


"$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Release"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help ...
OutDir=.\ReleaseU
InputPath=.\XEditBox.hpj
InputName=XEditBox

BuildCmds= \
	start /wait hcw /C /E /M "$(InputName).hpj" \
	if errorlevel 1 goto :Error \
	if not exist "$(InputName).hlp" goto :Error \
	copy "$(InputName).hlp" $(OutDir) \
	goto :done \
	:Error \
	echo $(InputName).hpj(1) : error: Problem encountered creating help file \
	type $(InputName).log \
	:done \


"$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\XEditBox.odl
# End Source File
# Begin Source File

SOURCE=.\XEditBox.rc
# End Source File
# Begin Source File

SOURCE=.\XEditBoxCtl.cpp
# End Source File
# Begin Source File

SOURCE=.\XEditBoxPpg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "XEditBox - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help Include File ...
TargetName=XEditBox
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm"
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm"
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm"
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm"
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm"
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm"
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm"
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm"
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help Include File ...
TargetName=XEditBox
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm"
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm"
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm"
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm"
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm"
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm"
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm"
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm"
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help Include File ...
TargetName=XEditBox
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm"
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm"
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm"
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm"
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm"
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm"
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm"
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm"
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Release"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Help Include File ...
TargetName=XEditBox
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm"
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm"
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm"
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm"
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm"
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm"
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm"
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm"
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm"
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm"

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\XEditBox.h
# End Source File
# Begin Source File

SOURCE=.\XEditBoxCtl.h
# End Source File
# Begin Source File

SOURCE=.\XEditBoxPpg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\XEditBox.ico
# End Source File
# Begin Source File

SOURCE=.\XEditBoxCtl.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\XEditBox.lic

!IF  "$(CFG)" == "XEditBox - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying license file...
OutDir=.\Release
ProjDir=.
TargetName=XEditBox
InputPath=.\XEditBox.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying license file...
OutDir=.\Debug
ProjDir=.
TargetName=XEditBox
InputPath=.\XEditBox.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Debug"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying license file...
OutDir=.\DebugU
ProjDir=.
TargetName=XEditBox
InputPath=.\XEditBox.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ELSEIF  "$(CFG)" == "XEditBox - Win32 Unicode Release"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying license file...
OutDir=.\ReleaseU
ProjDir=.
TargetName=XEditBox
InputPath=.\XEditBox.lic

"$(OutDir)\$(TargetName).lic" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "$(ProjDir)\$(TargetName).lic" "$(OutDir)"

# End Custom Build

!ENDIF

# End Source File
# Begin Source File

SOURCE=.\Hlp\XEditBox.rtf
# End Source File
# End Target
# End Project
