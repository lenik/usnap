# Microsoft Developer Studio Generated NMAKE File, Based on mapping.dsp
!IF "$(CFG)" == ""
CFG=mapping - Win32 Debug
!MESSAGE No configuration specified. Defaulting to mapping - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "mapping - Win32 Debug" && "$(CFG)" != "mapping - Win32 Unicode Debug" && "$(CFG)" != "mapping - Win32 Release MinSize" && "$(CFG)" != "mapping - Win32 Release MinDependency" && "$(CFG)" != "mapping - Win32 Unicode Release MinSize" && "$(CFG)" != "mapping - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "mapping.mak" CFG="mapping - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "mapping - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mapping - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mapping - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mapping - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mapping - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mapping - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "mapping - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mapping.dll" ".\mapping.tlb" ".\mapping.h" ".\mapping_i.c" "$(OUTDIR)\mapping.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CommandAdapter.obj"
	-@erase "$(INTDIR)\CommandAdapter.sbr"
	-@erase "$(INTDIR)\ConnectionAdapter.obj"
	-@erase "$(INTDIR)\ConnectionAdapter.sbr"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\Globals.sbr"
	-@erase "$(INTDIR)\mapping.obj"
	-@erase "$(INTDIR)\mapping.pch"
	-@erase "$(INTDIR)\mapping.res"
	-@erase "$(INTDIR)\mapping.sbr"
	-@erase "$(INTDIR)\RecordsetAdapter.obj"
	-@erase "$(INTDIR)\RecordsetAdapter.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mapping.bsc"
	-@erase "$(OUTDIR)\mapping.dll"
	-@erase "$(OUTDIR)\mapping.exp"
	-@erase "$(OUTDIR)\mapping.ilk"
	-@erase "$(OUTDIR)\mapping.lib"
	-@erase "$(OUTDIR)\mapping.pdb"
	-@erase ".\mapping.h"
	-@erase ".\mapping.tlb"
	-@erase ".\mapping_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mapping.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\mapping.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mapping.bsc"
BSC32_SBRS= \
	"$(INTDIR)\CommandAdapter.sbr" \
	"$(INTDIR)\ConnectionAdapter.sbr" \
	"$(INTDIR)\Globals.sbr" \
	"$(INTDIR)\mapping.sbr" \
	"$(INTDIR)\RecordsetAdapter.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\mapping.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\mapping.pdb" /debug /machine:I386 /def:".\mapping.def" /out:"$(OUTDIR)\mapping.dll" /implib:"$(OUTDIR)\mapping.lib" /pdbtype:sept
DEF_FILE= \
	".\mapping.def"
LINK32_OBJS= \
	"$(INTDIR)\CommandAdapter.obj" \
	"$(INTDIR)\ConnectionAdapter.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\mapping.obj" \
	"$(INTDIR)\RecordsetAdapter.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mapping.res"

"$(OUTDIR)\mapping.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\mapping.dll
InputPath=.\Debug\mapping.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\mapping.dll" ".\mapping.tlb" ".\mapping.h" ".\mapping_i.c" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CommandAdapter.obj"
	-@erase "$(INTDIR)\ConnectionAdapter.obj"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\mapping.obj"
	-@erase "$(INTDIR)\mapping.pch"
	-@erase "$(INTDIR)\mapping.res"
	-@erase "$(INTDIR)\RecordsetAdapter.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mapping.dll"
	-@erase "$(OUTDIR)\mapping.exp"
	-@erase "$(OUTDIR)\mapping.ilk"
	-@erase "$(OUTDIR)\mapping.lib"
	-@erase "$(OUTDIR)\mapping.pdb"
	-@erase ".\mapping.h"
	-@erase ".\mapping.tlb"
	-@erase ".\mapping_i.c"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\mapping.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\mapping.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mapping.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\mapping.pdb" /debug /machine:I386 /def:".\mapping.def" /out:"$(OUTDIR)\mapping.dll" /implib:"$(OUTDIR)\mapping.lib" /pdbtype:sept
DEF_FILE= \
	".\mapping.def"
LINK32_OBJS= \
	"$(INTDIR)\CommandAdapter.obj" \
	"$(INTDIR)\ConnectionAdapter.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\mapping.obj" \
	"$(INTDIR)\RecordsetAdapter.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mapping.res"

"$(OUTDIR)\mapping.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\mapping.dll
InputPath=.\DebugU\mapping.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	if "%OS%"=="" goto NOTNT
	if not "%OS%"=="Windows_NT" goto NOTNT
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
	goto end
	:NOTNT
	echo Warning : Cannot register Unicode DLL on Windows 95
	:end
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

ALL : "$(OUTDIR)\adomap.dll" ".\mapping.tlb" ".\mapping.h" ".\mapping_i.c" ".\ReleaseMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CommandAdapter.obj"
	-@erase "$(INTDIR)\ConnectionAdapter.obj"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\mapping.obj"
	-@erase "$(INTDIR)\mapping.pch"
	-@erase "$(INTDIR)\mapping.res"
	-@erase "$(INTDIR)\RecordsetAdapter.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\adomap.dll"
	-@erase "$(OUTDIR)\adomap.exp"
	-@erase "$(OUTDIR)\adomap.lib"
	-@erase ".\mapping.h"
	-@erase ".\mapping.tlb"
	-@erase ".\mapping_i.c"
	-@erase ".\ReleaseMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\mapping.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mapping.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\adomap.pdb" /machine:I386 /def:".\mapping.def" /out:"$(OUTDIR)\adomap.dll" /implib:"$(OUTDIR)\adomap.lib"
DEF_FILE= \
	".\mapping.def"
LINK32_OBJS= \
	"$(INTDIR)\CommandAdapter.obj" \
	"$(INTDIR)\ConnectionAdapter.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\mapping.obj" \
	"$(INTDIR)\RecordsetAdapter.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mapping.res"

"$(OUTDIR)\adomap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\adomap.dll
InputPath=.\ReleaseMinSize\adomap.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\adomap.dll" ".\mapping.tlb" ".\mapping.h" ".\mapping_i.c" ".\ReleaseMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CommandAdapter.obj"
	-@erase "$(INTDIR)\ConnectionAdapter.obj"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\mapping.obj"
	-@erase "$(INTDIR)\mapping.pch"
	-@erase "$(INTDIR)\mapping.res"
	-@erase "$(INTDIR)\RecordsetAdapter.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\adomap.dll"
	-@erase "$(OUTDIR)\adomap.exp"
	-@erase "$(OUTDIR)\adomap.lib"
	-@erase ".\mapping.h"
	-@erase ".\mapping.tlb"
	-@erase ".\mapping_i.c"
	-@erase ".\ReleaseMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\mapping.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mapping.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\adomap.pdb" /machine:I386 /def:".\mapping.def" /out:"$(OUTDIR)\adomap.dll" /implib:"$(OUTDIR)\adomap.lib"
DEF_FILE= \
	".\mapping.def"
LINK32_OBJS= \
	"$(INTDIR)\CommandAdapter.obj" \
	"$(INTDIR)\ConnectionAdapter.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\mapping.obj" \
	"$(INTDIR)\RecordsetAdapter.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mapping.res"

"$(OUTDIR)\adomap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\adomap.dll
InputPath=.\ReleaseMinDependency\adomap.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

ALL : "$(OUTDIR)\adomap.dll" ".\mapping.tlb" ".\mapping.h" ".\mapping_i.c" ".\ReleaseUMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CommandAdapter.obj"
	-@erase "$(INTDIR)\ConnectionAdapter.obj"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\mapping.obj"
	-@erase "$(INTDIR)\mapping.pch"
	-@erase "$(INTDIR)\mapping.res"
	-@erase "$(INTDIR)\RecordsetAdapter.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\adomap.dll"
	-@erase "$(OUTDIR)\adomap.exp"
	-@erase "$(OUTDIR)\adomap.lib"
	-@erase ".\mapping.h"
	-@erase ".\mapping.tlb"
	-@erase ".\mapping_i.c"
	-@erase ".\ReleaseUMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\mapping.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mapping.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\adomap.pdb" /machine:I386 /def:".\mapping.def" /out:"$(OUTDIR)\adomap.dll" /implib:"$(OUTDIR)\adomap.lib"
DEF_FILE= \
	".\mapping.def"
LINK32_OBJS= \
	"$(INTDIR)\CommandAdapter.obj" \
	"$(INTDIR)\ConnectionAdapter.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\mapping.obj" \
	"$(INTDIR)\RecordsetAdapter.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mapping.res"

"$(OUTDIR)\adomap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\adomap.dll
InputPath=.\ReleaseUMinSize\adomap.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	if "%OS%"=="" goto NOTNT
	if not "%OS%"=="Windows_NT" goto NOTNT
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
	goto end
	:NOTNT
	echo Warning : Cannot register Unicode DLL on Windows 95
	:end
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\adomap.dll" ".\ReleaseUMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CommandAdapter.obj"
	-@erase "$(INTDIR)\ConnectionAdapter.obj"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\mapping.obj"
	-@erase "$(INTDIR)\mapping.pch"
	-@erase "$(INTDIR)\mapping.res"
	-@erase "$(INTDIR)\RecordsetAdapter.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\adomap.dll"
	-@erase "$(OUTDIR)\adomap.exp"
	-@erase "$(OUTDIR)\adomap.lib"
	-@erase ".\mapping.h"
	-@erase ".\mapping.tlb"
	-@erase ".\mapping_i.c"
	-@erase ".\ReleaseUMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\mapping.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mapping.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\adomap.pdb" /machine:I386 /def:".\mapping.def" /out:"$(OUTDIR)\adomap.dll" /implib:"$(OUTDIR)\adomap.lib"
DEF_FILE= \
	".\mapping.def"
LINK32_OBJS= \
	"$(INTDIR)\CommandAdapter.obj" \
	"$(INTDIR)\ConnectionAdapter.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\mapping.obj" \
	"$(INTDIR)\RecordsetAdapter.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mapping.res"

"$(OUTDIR)\adomap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\adomap.dll
InputPath=.\ReleaseUMinDependency\adomap.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	if "%OS%"=="" goto NOTNT
	if not "%OS%"=="Windows_NT" goto NOTNT
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
	goto end
	:NOTNT
	echo Warning : Cannot register Unicode DLL on Windows 95
	:end
<<


!ENDIF


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mapping.dep")
!INCLUDE "mapping.dep"
!ELSE
!MESSAGE Warning: cannot find "mapping.dep"
!ENDIF
!ENDIF


!IF "$(CFG)" == "mapping - Win32 Debug" || "$(CFG)" == "mapping - Win32 Unicode Debug" || "$(CFG)" == "mapping - Win32 Release MinSize" || "$(CFG)" == "mapping - Win32 Release MinDependency" || "$(CFG)" == "mapping - Win32 Unicode Release MinSize" || "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"
SOURCE=.\CommandAdapter.cpp

!IF  "$(CFG)" == "mapping - Win32 Debug"


"$(INTDIR)\CommandAdapter.obj"	"$(INTDIR)\CommandAdapter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"


"$(INTDIR)\CommandAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"


"$(INTDIR)\CommandAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"


"$(INTDIR)\CommandAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"


"$(INTDIR)\CommandAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"


"$(INTDIR)\CommandAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch" ".\mapping.h"


!ENDIF

SOURCE=.\ConnectionAdapter.cpp

!IF  "$(CFG)" == "mapping - Win32 Debug"


"$(INTDIR)\ConnectionAdapter.obj"	"$(INTDIR)\ConnectionAdapter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"


"$(INTDIR)\ConnectionAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"


"$(INTDIR)\ConnectionAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"


"$(INTDIR)\ConnectionAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"


"$(INTDIR)\ConnectionAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"


"$(INTDIR)\ConnectionAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch" ".\mapping.h"


!ENDIF

SOURCE=.\Globals.cpp

!IF  "$(CFG)" == "mapping - Win32 Debug"


"$(INTDIR)\Globals.obj"	"$(INTDIR)\Globals.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"


"$(INTDIR)\Globals.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"


"$(INTDIR)\Globals.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"


"$(INTDIR)\Globals.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"


"$(INTDIR)\Globals.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"


"$(INTDIR)\Globals.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch" ".\mapping.h"


!ENDIF

SOURCE=.\mapping.cpp

!IF  "$(CFG)" == "mapping - Win32 Debug"


"$(INTDIR)\mapping.obj"	"$(INTDIR)\mapping.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"


"$(INTDIR)\mapping.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"


"$(INTDIR)\mapping.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"


"$(INTDIR)\mapping.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"


"$(INTDIR)\mapping.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"


"$(INTDIR)\mapping.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch" ".\mapping_i.c" ".\mapping.h"


!ENDIF

SOURCE=.\mapping.idl

!IF  "$(CFG)" == "mapping - Win32 Debug"

MTL_SWITCHES=/tlb ".\mapping.tlb" /h "mapping.h" /iid "mapping_i.c" /Oicf

".\mapping.tlb"	".\mapping.h"	".\mapping_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"

MTL_SWITCHES=/tlb ".\mapping.tlb" /h "mapping.h" /iid "mapping_i.c" /Oicf

".\mapping.tlb"	".\mapping.h"	".\mapping_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"

MTL_SWITCHES=/tlb ".\mapping.tlb" /h "mapping.h" /iid "mapping_i.c" /Oicf

".\mapping.tlb"	".\mapping.h"	".\mapping_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"

MTL_SWITCHES=/tlb ".\mapping.tlb" /h "mapping.h" /iid "mapping_i.c" /Oicf

".\mapping.tlb"	".\mapping.h"	".\mapping_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"

MTL_SWITCHES=/tlb ".\mapping.tlb" /h "mapping.h" /iid "mapping_i.c" /Oicf

".\mapping.tlb"	".\mapping.h"	".\mapping_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"

MTL_SWITCHES=/tlb ".\mapping.tlb" /h "mapping.h" /iid "mapping_i.c" /Oicf

".\mapping.tlb"	".\mapping.h"	".\mapping_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=.\mapping.rc

"$(INTDIR)\mapping.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\RecordsetAdapter.cpp

!IF  "$(CFG)" == "mapping - Win32 Debug"


"$(INTDIR)\RecordsetAdapter.obj"	"$(INTDIR)\RecordsetAdapter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"


"$(INTDIR)\RecordsetAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"


"$(INTDIR)\RecordsetAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"


"$(INTDIR)\RecordsetAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"


"$(INTDIR)\RecordsetAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch"


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"


"$(INTDIR)\RecordsetAdapter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mapping.pch" ".\mapping.h"


!ENDIF

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "mapping - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mapping.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\mapping.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\mapping.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mapping.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mapping.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mapping.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mapping.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mapping - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\mapping.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mapping.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=.\adoenum.idl
SOURCE=.\msado15.idl

!ENDIF
