# Microsoft Developer Studio Project File - Name="scomp2_client2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=scomp2_client2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "scomp2_client2.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "scomp2_client2.mak" CFG="scomp2_client2 - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "scomp2_client2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "scomp2_client2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "scomp2_client2 - Win32 Release"

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

!ELSEIF  "$(CFG)" == "scomp2_client2 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
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

# Name "scomp2_client2 - Win32 Release"
# Name "scomp2_client2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "dhtml"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\htmlsrc\dhtmledit.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmldocument2.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlelement.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlelementcollection.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmleventobj.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlfilterscollection.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlformelement.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlframescollection2.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlimageelementfactory.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlimgelement.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmllocation.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlmimetypescollection.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlopsprofile.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmloptionelement.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmloptionelementfactory.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlpluginscollection.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlrulestyle.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlscreen.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlselectionobject.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstyle.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheet.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheetrule.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheetrulescollection.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheetscollection.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlwindow2.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\omhistory.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\omnavigator.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\t\i\src\_SComp2.cpp
# End Source File
# Begin Source File

SOURCE=.\AdvancedSettingDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\html_temp\batch_compare_temp.htm
# End Source File
# Begin Source File

SOURCE=.\html_temp\detail_temp.htm
# End Source File
# Begin Source File

SOURCE=.\DetailDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\sc_plugin.cpp
# End Source File
# Begin Source File

SOURCE=..\t\i\src\SComp2.cpp
# End Source File
# Begin Source File

SOURCE=.\scomp2_client2.cpp
# End Source File
# Begin Source File

SOURCE=.\scomp2_client2.rc
# End Source File
# Begin Source File

SOURCE=.\scomp2_client2Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SettingDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\streamworkhelper01.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "dhtml.h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\htmlsrc\dhtmledit.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmldocument2.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlelement.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlelementcollection.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmleventobj.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlfilterscollection.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlformelement.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlframescollection2.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlimageelementfactory.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlimgelement.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmllocation.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlmimetypescollection.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlopsprofile.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmloptionelement.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmloptionelementfactory.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlpluginscollection.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlrulestyle.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlscreen.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlselectionobject.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstyle.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheet.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheetrule.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheetrulescollection.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlstylesheetscollection.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\htmlwindow2.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\omhistory.h
# End Source File
# Begin Source File

SOURCE=.\htmlsrc\omnavigator.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\t\i\_SComp.H
# End Source File
# Begin Source File

SOURCE=..\t\i\_SComp2.H
# End Source File
# Begin Source File

SOURCE=.\AdvancedSettingDialog.h
# End Source File
# Begin Source File

SOURCE=.\DetailDialog.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\sc_plugin.h
# End Source File
# Begin Source File

SOURCE=.\scomp2_client2.h
# End Source File
# Begin Source File

SOURCE=.\scomp2_client2Dlg.h
# End Source File
# Begin Source File

SOURCE=.\SettingDialog.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\streamworkhelper01.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bsn.ico
# End Source File
# Begin Source File

SOURCE=.\res\scomp2_client2.ico
# End Source File
# Begin Source File

SOURCE=.\res\scomp2_client2.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section scomp2_client2 : {3050F3FC-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLMimeTypesCollection
# 	2:10:HeaderFile:htmlmimetypescollection.h
# 	2:8:ImplFile:htmlmimetypescollection.cpp
# End Section
# Section scomp2_client2 : {3050F25E-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLStyle
# 	2:10:HeaderFile:htmlstyle.h
# 	2:8:ImplFile:htmlstyle.cpp
# End Section
# Section scomp2_client2 : {3050F2E3-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLStyleSheet
# 	2:10:HeaderFile:htmlstylesheet.h
# 	2:8:ImplFile:htmlstylesheet.cpp
# End Section
# Section scomp2_client2 : {CE04B591-2B1F-11D2-8D1E-00A0C959BC0A}
# 	2:5:Class:CDHTMLEdit
# 	2:10:HeaderFile:dhtmledit.h
# 	2:8:ImplFile:dhtmledit.cpp
# End Section
# Section scomp2_client2 : {3050F211-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLOptionElement
# 	2:10:HeaderFile:htmloptionelement.h
# 	2:8:ImplFile:htmloptionelement.cpp
# End Section
# Section scomp2_client2 : {FECEAAA2-8405-11CF-8BA1-00AA00476DA6}
# 	2:5:Class:COmHistory
# 	2:10:HeaderFile:omhistory.h
# 	2:8:ImplFile:omhistory.cpp
# End Section
# Section scomp2_client2 : {3050F357-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLStyleSheetRule
# 	2:10:HeaderFile:htmlstylesheetrule.h
# 	2:8:ImplFile:htmlstylesheetrule.cpp
# End Section
# Section scomp2_client2 : {332C4427-26CB-11D0-B483-00C04FD90119}
# 	2:5:Class:CHTMLWindow2
# 	2:10:HeaderFile:htmlwindow2.h
# 	2:8:ImplFile:htmlwindow2.cpp
# End Section
# Section scomp2_client2 : {3050F3CF-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLRuleStyle
# 	2:10:HeaderFile:htmlrulestyle.h
# 	2:8:ImplFile:htmlrulestyle.cpp
# End Section
# Section scomp2_client2 : {3050F38E-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLImageElementFactory
# 	2:10:HeaderFile:htmlimageelementfactory.h
# 	2:8:ImplFile:htmlimageelementfactory.cpp
# End Section
# Section scomp2_client2 : {3050F37E-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLStyleSheetsCollection
# 	2:10:HeaderFile:htmlstylesheetscollection.h
# 	2:8:ImplFile:htmlstylesheetscollection.cpp
# End Section
# Section scomp2_client2 : {3050F240-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLImgElement
# 	2:10:HeaderFile:htmlimgelement.h
# 	2:8:ImplFile:htmlimgelement.cpp
# End Section
# Section scomp2_client2 : {332C4426-26CB-11D0-B483-00C04FD90119}
# 	2:5:Class:CHTMLFramesCollection2
# 	2:10:HeaderFile:htmlframescollection2.h
# 	2:8:ImplFile:htmlframescollection2.cpp
# End Section
# Section scomp2_client2 : {FECEAAA5-8405-11CF-8BA1-00AA00476DA6}
# 	2:5:Class:COmNavigator
# 	2:10:HeaderFile:omnavigator.h
# 	2:8:ImplFile:omnavigator.cpp
# End Section
# Section scomp2_client2 : {3050F32D-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLEventObj
# 	2:10:HeaderFile:htmleventobj.h
# 	2:8:ImplFile:htmleventobj.cpp
# End Section
# Section scomp2_client2 : {3050F1FF-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLElement
# 	2:10:HeaderFile:htmlelement.h
# 	2:8:ImplFile:htmlelement.cpp
# End Section
# Section scomp2_client2 : {3050F3EE-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLFiltersCollection
# 	2:10:HeaderFile:htmlfilterscollection.h
# 	2:8:ImplFile:htmlfilterscollection.cpp
# End Section
# Section scomp2_client2 : {3050F2E5-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLStyleSheetRulesCollection
# 	2:10:HeaderFile:htmlstylesheetrulescollection.h
# 	2:8:ImplFile:htmlstylesheetrulescollection.cpp
# End Section
# Section scomp2_client2 : {2D360200-FFF5-11D1-8D03-00A0C959BC0A}
# 	2:21:DefaultSinkHeaderFile:dhtmledit.h
# 	2:16:DefaultSinkClass:CDHTMLEdit
# End Section
# Section scomp2_client2 : {3050F21F-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLElementCollection
# 	2:10:HeaderFile:htmlelementcollection.h
# 	2:8:ImplFile:htmlelementcollection.cpp
# End Section
# Section scomp2_client2 : {3050F1F7-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLFormElement
# 	2:10:HeaderFile:htmlformelement.h
# 	2:8:ImplFile:htmlformelement.cpp
# End Section
# Section scomp2_client2 : {332C4425-26CB-11D0-B483-00C04FD90119}
# 	2:5:Class:CHTMLDocument2
# 	2:10:HeaderFile:htmldocument2.h
# 	2:8:ImplFile:htmldocument2.cpp
# End Section
# Section scomp2_client2 : {3050F3FD-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLPluginsCollection
# 	2:10:HeaderFile:htmlpluginscollection.h
# 	2:8:ImplFile:htmlpluginscollection.cpp
# End Section
# Section scomp2_client2 : {3050F35C-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLScreen
# 	2:10:HeaderFile:htmlscreen.h
# 	2:8:ImplFile:htmlscreen.cpp
# End Section
# Section scomp2_client2 : {3050F25A-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLSelectionObject
# 	2:10:HeaderFile:htmlselectionobject.h
# 	2:8:ImplFile:htmlselectionobject.cpp
# End Section
# Section scomp2_client2 : {3050F38C-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLOptionElementFactory
# 	2:10:HeaderFile:htmloptionelementfactory.h
# 	2:8:ImplFile:htmloptionelementfactory.cpp
# End Section
# Section scomp2_client2 : {163BB1E0-6E00-11CF-837A-48DC04C10000}
# 	2:5:Class:CHTMLLocation
# 	2:10:HeaderFile:htmllocation.h
# 	2:8:ImplFile:htmllocation.cpp
# End Section
# Section scomp2_client2 : {3050F401-98B5-11CF-BB82-00AA00BDCE0B}
# 	2:5:Class:CHTMLOpsProfile
# 	2:10:HeaderFile:htmlopsprofile.h
# 	2:8:ImplFile:htmlopsprofile.cpp
# End Section
