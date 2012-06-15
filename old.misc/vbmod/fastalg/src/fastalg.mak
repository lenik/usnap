# Microsoft Developer Studio Generated NMAKE File, Based on fastalg.dsp
!IF "$(CFG)" == ""
CFG=fastalg - Win32 Debug
!MESSAGE No configuration specified. Defaulting to fastalg - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "fastalg - Win32 Debug" && "$(CFG)" != "fastalg - Win32 Unicode Debug" && "$(CFG)" != "fastalg - Win32 Release MinSize" && "$(CFG)" != "fastalg - Win32 Release MinDependency" && "$(CFG)" != "fastalg - Win32 Unicode Release MinSize" && "$(CFG)" != "fastalg - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "fastalg.mak" CFG="fastalg - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "fastalg - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "fastalg - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "fastalg - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "fastalg - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "fastalg - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "fastalg - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "fastalg - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\fastalg.dll" ".\fastalg.tlb" ".\fastalg.h" ".\fastalg_i.c" "$(OUTDIR)\fastalg.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\DRIA.obj"
	-@erase "$(INTDIR)\DRIA.sbr"
	-@erase "$(INTDIR)\fastalg.obj"
	-@erase "$(INTDIR)\fastalg.pch"
	-@erase "$(INTDIR)\fastalg.res"
	-@erase "$(INTDIR)\fastalg.sbr"
	-@erase "$(INTDIR)\HashCode.obj"
	-@erase "$(INTDIR)\HashCode.sbr"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\kernel.sbr"
	-@erase "$(INTDIR)\SAOT.obj"
	-@erase "$(INTDIR)\SAOT.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\fastalg.bsc"
	-@erase "$(OUTDIR)\fastalg.dll"
	-@erase "$(OUTDIR)\fastalg.exp"
	-@erase "$(OUTDIR)\fastalg.ilk"
	-@erase "$(OUTDIR)\fastalg.lib"
	-@erase "$(OUTDIR)\fastalg.pdb"
	-@erase ".\fastalg.h"
	-@erase ".\fastalg.tlb"
	-@erase ".\fastalg_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\fastalg.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\fastalg.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\fastalg.bsc"
BSC32_SBRS= \
	"$(INTDIR)\DRIA.sbr" \
	"$(INTDIR)\fastalg.sbr" \
	"$(INTDIR)\HashCode.sbr" \
	"$(INTDIR)\kernel.sbr" \
	"$(INTDIR)\SAOT.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\fastalg.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\fastalg.pdb" /debug /machine:I386 /def:".\fastalg.def" /out:"$(OUTDIR)\fastalg.dll" /implib:"$(OUTDIR)\fastalg.lib" /pdbtype:sept
DEF_FILE= \
	".\fastalg.def"
LINK32_OBJS= \
	"$(INTDIR)\DRIA.obj" \
	"$(INTDIR)\fastalg.obj" \
	"$(INTDIR)\HashCode.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\SAOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\fastalg.res"

"$(OUTDIR)\fastalg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\fastalg.dll
InputPath=.\Debug\fastalg.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\fastalg.dll" ".\fastalg.tlb" ".\fastalg.h" ".\fastalg_i.c" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\DRIA.obj"
	-@erase "$(INTDIR)\fastalg.obj"
	-@erase "$(INTDIR)\fastalg.pch"
	-@erase "$(INTDIR)\fastalg.res"
	-@erase "$(INTDIR)\HashCode.obj"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\SAOT.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\fastalg.dll"
	-@erase "$(OUTDIR)\fastalg.exp"
	-@erase "$(OUTDIR)\fastalg.ilk"
	-@erase "$(OUTDIR)\fastalg.lib"
	-@erase "$(OUTDIR)\fastalg.pdb"
	-@erase ".\fastalg.h"
	-@erase ".\fastalg.tlb"
	-@erase ".\fastalg_i.c"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\fastalg.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\fastalg.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\fastalg.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\fastalg.pdb" /debug /machine:I386 /def:".\fastalg.def" /out:"$(OUTDIR)\fastalg.dll" /implib:"$(OUTDIR)\fastalg.lib" /pdbtype:sept
DEF_FILE= \
	".\fastalg.def"
LINK32_OBJS= \
	"$(INTDIR)\DRIA.obj" \
	"$(INTDIR)\fastalg.obj" \
	"$(INTDIR)\HashCode.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\SAOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\fastalg.res"

"$(OUTDIR)\fastalg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\fastalg.dll
InputPath=.\DebugU\fastalg.dll
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


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

ALL : "$(OUTDIR)\fastalg.dll" ".\fastalg.tlb" ".\fastalg.h" ".\fastalg_i.c" ".\ReleaseMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\DRIA.obj"
	-@erase "$(INTDIR)\fastalg.obj"
	-@erase "$(INTDIR)\fastalg.pch"
	-@erase "$(INTDIR)\fastalg.res"
	-@erase "$(INTDIR)\HashCode.obj"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\SAOT.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\fastalg.dll"
	-@erase "$(OUTDIR)\fastalg.exp"
	-@erase "$(OUTDIR)\fastalg.lib"
	-@erase ".\fastalg.h"
	-@erase ".\fastalg.tlb"
	-@erase ".\fastalg_i.c"
	-@erase ".\ReleaseMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\fastalg.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\fastalg.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\fastalg.pdb" /machine:I386 /def:".\fastalg.def" /out:"$(OUTDIR)\fastalg.dll" /implib:"$(OUTDIR)\fastalg.lib"
DEF_FILE= \
	".\fastalg.def"
LINK32_OBJS= \
	"$(INTDIR)\DRIA.obj" \
	"$(INTDIR)\fastalg.obj" \
	"$(INTDIR)\HashCode.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\SAOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\fastalg.res"

"$(OUTDIR)\fastalg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\fastalg.dll
InputPath=.\ReleaseMinSize\fastalg.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\fastalg.dll" ".\fastalg.tlb" ".\fastalg.h" ".\fastalg_i.c" ".\ReleaseMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\DRIA.obj"
	-@erase "$(INTDIR)\fastalg.obj"
	-@erase "$(INTDIR)\fastalg.pch"
	-@erase "$(INTDIR)\fastalg.res"
	-@erase "$(INTDIR)\HashCode.obj"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\SAOT.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\fastalg.dll"
	-@erase "$(OUTDIR)\fastalg.exp"
	-@erase "$(OUTDIR)\fastalg.lib"
	-@erase ".\fastalg.h"
	-@erase ".\fastalg.tlb"
	-@erase ".\fastalg_i.c"
	-@erase ".\ReleaseMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\fastalg.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\fastalg.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\fastalg.pdb" /machine:I386 /def:".\fastalg.def" /out:"$(OUTDIR)\fastalg.dll" /implib:"$(OUTDIR)\fastalg.lib"
DEF_FILE= \
	".\fastalg.def"
LINK32_OBJS= \
	"$(INTDIR)\DRIA.obj" \
	"$(INTDIR)\fastalg.obj" \
	"$(INTDIR)\HashCode.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\SAOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\fastalg.res"

"$(OUTDIR)\fastalg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\fastalg.dll
InputPath=.\ReleaseMinDependency\fastalg.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

ALL : "$(OUTDIR)\fastalg.dll" ".\fastalg.tlb" ".\fastalg.h" ".\fastalg_i.c" ".\ReleaseUMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\DRIA.obj"
	-@erase "$(INTDIR)\fastalg.obj"
	-@erase "$(INTDIR)\fastalg.pch"
	-@erase "$(INTDIR)\fastalg.res"
	-@erase "$(INTDIR)\HashCode.obj"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\SAOT.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\fastalg.dll"
	-@erase "$(OUTDIR)\fastalg.exp"
	-@erase "$(OUTDIR)\fastalg.lib"
	-@erase ".\fastalg.h"
	-@erase ".\fastalg.tlb"
	-@erase ".\fastalg_i.c"
	-@erase ".\ReleaseUMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\fastalg.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\fastalg.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\fastalg.pdb" /machine:I386 /def:".\fastalg.def" /out:"$(OUTDIR)\fastalg.dll" /implib:"$(OUTDIR)\fastalg.lib"
DEF_FILE= \
	".\fastalg.def"
LINK32_OBJS= \
	"$(INTDIR)\DRIA.obj" \
	"$(INTDIR)\fastalg.obj" \
	"$(INTDIR)\HashCode.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\SAOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\fastalg.res"

"$(OUTDIR)\fastalg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\fastalg.dll
InputPath=.\ReleaseUMinSize\fastalg.dll
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


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\fastalg.dll" ".\ReleaseUMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\DRIA.obj"
	-@erase "$(INTDIR)\fastalg.obj"
	-@erase "$(INTDIR)\fastalg.pch"
	-@erase "$(INTDIR)\fastalg.res"
	-@erase "$(INTDIR)\HashCode.obj"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\SAOT.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\fastalg.dll"
	-@erase "$(OUTDIR)\fastalg.exp"
	-@erase "$(OUTDIR)\fastalg.lib"
	-@erase ".\fastalg.h"
	-@erase ".\fastalg.tlb"
	-@erase ".\fastalg_i.c"
	-@erase ".\ReleaseUMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\fastalg.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\fastalg.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\fastalg.pdb" /machine:I386 /def:".\fastalg.def" /out:"$(OUTDIR)\fastalg.dll" /implib:"$(OUTDIR)\fastalg.lib"
DEF_FILE= \
	".\fastalg.def"
LINK32_OBJS= \
	"$(INTDIR)\DRIA.obj" \
	"$(INTDIR)\fastalg.obj" \
	"$(INTDIR)\HashCode.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\SAOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\fastalg.res"

"$(OUTDIR)\fastalg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\fastalg.dll
InputPath=.\ReleaseUMinDependency\fastalg.dll
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
!IF EXISTS("fastalg.dep")
!INCLUDE "fastalg.dep"
!ELSE
!MESSAGE Warning: cannot find "fastalg.dep"
!ENDIF
!ENDIF


!IF "$(CFG)" == "fastalg - Win32 Debug" || "$(CFG)" == "fastalg - Win32 Unicode Debug" || "$(CFG)" == "fastalg - Win32 Release MinSize" || "$(CFG)" == "fastalg - Win32 Release MinDependency" || "$(CFG)" == "fastalg - Win32 Unicode Release MinSize" || "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"
SOURCE=.\DRIA.cpp

!IF  "$(CFG)" == "fastalg - Win32 Debug"


"$(INTDIR)\DRIA.obj"	"$(INTDIR)\DRIA.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"


"$(INTDIR)\DRIA.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"


"$(INTDIR)\DRIA.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"


"$(INTDIR)\DRIA.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"


"$(INTDIR)\DRIA.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"


"$(INTDIR)\DRIA.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch" ".\fastalg.h"


!ENDIF

SOURCE=.\fastalg.cpp

!IF  "$(CFG)" == "fastalg - Win32 Debug"


"$(INTDIR)\fastalg.obj"	"$(INTDIR)\fastalg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"


"$(INTDIR)\fastalg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"


"$(INTDIR)\fastalg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"


"$(INTDIR)\fastalg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"


"$(INTDIR)\fastalg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"


"$(INTDIR)\fastalg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch" ".\fastalg_i.c" ".\fastalg.h"


!ENDIF

SOURCE=.\fastalg.idl

!IF  "$(CFG)" == "fastalg - Win32 Debug"

MTL_SWITCHES=/tlb ".\fastalg.tlb" /h "fastalg.h" /iid "fastalg_i.c" /Oicf

".\fastalg.tlb"	".\fastalg.h"	".\fastalg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"

MTL_SWITCHES=/tlb ".\fastalg.tlb" /h "fastalg.h" /iid "fastalg_i.c" /Oicf

".\fastalg.tlb"	".\fastalg.h"	".\fastalg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"

MTL_SWITCHES=/tlb ".\fastalg.tlb" /h "fastalg.h" /iid "fastalg_i.c" /Oicf

".\fastalg.tlb"	".\fastalg.h"	".\fastalg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"

MTL_SWITCHES=/tlb ".\fastalg.tlb" /h "fastalg.h" /iid "fastalg_i.c" /Oicf

".\fastalg.tlb"	".\fastalg.h"	".\fastalg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"

MTL_SWITCHES=/tlb ".\fastalg.tlb" /h "fastalg.h" /iid "fastalg_i.c" /Oicf

".\fastalg.tlb"	".\fastalg.h"	".\fastalg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"

MTL_SWITCHES=/tlb ".\fastalg.tlb" /h "fastalg.h" /iid "fastalg_i.c" /Oicf

".\fastalg.tlb"	".\fastalg.h"	".\fastalg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=.\fastalg.rc

"$(INTDIR)\fastalg.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\HashCode.cpp

!IF  "$(CFG)" == "fastalg - Win32 Debug"


"$(INTDIR)\HashCode.obj"	"$(INTDIR)\HashCode.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"


"$(INTDIR)\HashCode.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"


"$(INTDIR)\HashCode.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"


"$(INTDIR)\HashCode.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"


"$(INTDIR)\HashCode.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"


"$(INTDIR)\HashCode.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch" ".\fastalg.h"


!ENDIF

SOURCE=.\kernel.cpp

!IF  "$(CFG)" == "fastalg - Win32 Debug"


"$(INTDIR)\kernel.obj"	"$(INTDIR)\kernel.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"


"$(INTDIR)\kernel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"


"$(INTDIR)\kernel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"


"$(INTDIR)\kernel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"


"$(INTDIR)\kernel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"


"$(INTDIR)\kernel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ENDIF

SOURCE=.\SAOT.cpp

!IF  "$(CFG)" == "fastalg - Win32 Debug"


"$(INTDIR)\SAOT.obj"	"$(INTDIR)\SAOT.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"


"$(INTDIR)\SAOT.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"


"$(INTDIR)\SAOT.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"


"$(INTDIR)\SAOT.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"


"$(INTDIR)\SAOT.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch"


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"


"$(INTDIR)\SAOT.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\fastalg.pch" ".\fastalg.h"


!ENDIF

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "fastalg - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\fastalg.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\fastalg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\fastalg.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\fastalg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\fastalg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\fastalg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\fastalg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "fastalg - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\fastalg.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\fastalg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF


!ENDIF

