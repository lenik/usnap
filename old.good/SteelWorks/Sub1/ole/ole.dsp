# Microsoft Developer Studio Project File - Name="ole" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ole - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "ole.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "ole.mak" CFG="ole - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "ole - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ole - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ole - Win32 Release"

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

!ELSEIF  "$(CFG)" == "ole - Win32 Debug"

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

# Name "ole - Win32 Release"
# Name "ole - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DlgProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\excel9.cpp
# End Source File
# Begin Source File

SOURCE=.\ole.cpp
# End Source File
# Begin Source File

SOURCE=.\ole.odl
# End Source File
# Begin Source File

SOURCE=.\ole.rc
# End Source File
# Begin Source File

SOURCE=.\oleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# Begin Source File

SOURCE=.\worksheet.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DlgProxy.h
# End Source File
# Begin Source File

SOURCE=.\excel9.h
# End Source File
# Begin Source File

SOURCE=.\ole.h
# End Source File
# Begin Source File

SOURCE=.\oleDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\worksheet.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ole.ico
# End Source File
# Begin Source File

SOURCE=.\res\ole.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ole.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section ole : {0719D4A0-5BCA-11D1-8051-00600893B445}
# 	2:5:Class:Cnterior
# 	2:10:HeaderFile:nterior.h
# 	2:8:ImplFile:nterior.cpp
# End Section
# Section ole : {A2BD023C-D428-11D1-8837-0060089BA39A}
# 	2:5:Class:CFilter
# 	2:10:HeaderFile:filter.h
# 	2:8:ImplFile:filter.cpp
# End Section
# Section ole : {5356F2F0-2DE7-11D1-B1CE-00A0C9056619}
# 	2:5:Class:CPane
# 	2:10:HeaderFile:pane.h
# 	2:8:ImplFile:pane.cpp
# End Section
# Section ole : {5C638330-2DE7-11D1-B1CE-00A0C9056619}
# 	2:5:Class:CPanes
# 	2:10:HeaderFile:panes.h
# 	2:8:ImplFile:panes.cpp
# End Section
# Section ole : {29CB89F0-2DE7-11D1-B1CE-00A0C9056619}
# 	2:5:Class:COWCFont
# 	2:10:HeaderFile:owcfont.h
# 	2:8:ImplFile:owcfont.cpp
# End Section
# Section ole : {1F40F4D0-2DE7-11D1-B1CE-00A0C9056619}
# 	2:5:Class:CBorders
# 	2:10:HeaderFile:borders.h
# 	2:8:ImplFile:borders.cpp
# End Section
# Section ole : {A7D3C540-2CED-11D1-B4D6-444553540000}
# 	2:5:Class:CRange
# 	2:10:HeaderFile:range.h
# 	2:8:ImplFile:range.cpp
# End Section
# Section ole : {C0846D11-D402-11D1-823A-0060083316C7}
# 	2:5:Class:CAutoFilter
# 	2:10:HeaderFile:autofilter.h
# 	2:8:ImplFile:autofilter.cpp
# End Section
# Section ole : {2D3BEF00-2C50-11D1-B1CE-00A0C9056619}
# 	2:5:Class:CWorksheet
# 	2:10:HeaderFile:worksheet.h
# 	2:8:ImplFile:worksheet.cpp
# End Section
# Section ole : {193F4B98-1CB8-11D1-9923-00C04FB937E1}
# 	2:5:Class:CWebCalc
# 	2:10:HeaderFile:webcalc.h
# 	2:8:ImplFile:webcalc.cpp
# End Section
# Section ole : {0FB45160-2DE7-11D1-B1CE-00A0C9056619}
# 	2:5:Class:CBorder
# 	2:10:HeaderFile:border.h
# 	2:8:ImplFile:border.cpp
# End Section
# Section ole : {4030E170-2DE7-11D1-B1CE-00A0C9056619}
# 	2:5:Class:CHyperlink
# 	2:10:HeaderFile:hyperlink.h
# 	2:8:ImplFile:hyperlink.cpp
# End Section
# Section ole : {A2BD023A-D428-11D1-8837-0060089BA39A}
# 	2:5:Class:CCriteria
# 	2:10:HeaderFile:criteria.h
# 	2:8:ImplFile:criteria.cpp
# End Section
# Section ole : {D7846FF1-91CE-11D1-9DE4-00600893B542}
# 	2:5:Class:CProtection
# 	2:10:HeaderFile:protection.h
# 	2:8:ImplFile:protection.cpp
# End Section
# Section ole : {BB917B40-2CED-11D1-B4D6-444553540000}
# 	2:5:Class:CTitleBar
# 	2:10:HeaderFile:titlebar.h
# 	2:8:ImplFile:titlebar.cpp
# End Section
# Section ole : {0002E510-0000-0000-C000-000000000046}
# 	2:21:DefaultSinkHeaderFile:webcalc.h
# 	2:16:DefaultSinkClass:CWebCalc
# End Section
# Section ole : {A2BD023D-D428-11D1-8837-0060089BA39A}
# 	2:5:Class:CFilters
# 	2:10:HeaderFile:filters.h
# 	2:8:ImplFile:filters.cpp
# End Section
