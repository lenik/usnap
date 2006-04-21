# Microsoft Developer Studio Generated NMAKE File, Based on glyphs.dsp
!IF "$(CFG)" == ""
CFG=glyphs - Win32 Debug
!MESSAGE No configuration specified. Defaulting to glyphs - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "glyphs - Win32 Debug" && "$(CFG)" != "glyphs - Win32 Unicode Debug" && "$(CFG)" != "glyphs - Win32 Release MinSize" && "$(CFG)" != "glyphs - Win32 Release MinDependency" && "$(CFG)" != "glyphs - Win32 Unicode Release MinSize" && "$(CFG)" != "glyphs - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "glyphs.mak" CFG="glyphs - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "glyphs - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "glyphs - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "glyphs - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "glyphs - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "glyphs - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "glyphs - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "glyphs - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\glyphs.dll" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\glyphs.obj"
	-@erase "$(INTDIR)\glyphs.pch"
	-@erase "$(INTDIR)\glyphs.res"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\Lines.obj"
	-@erase "$(INTDIR)\mat.obj"
	-@erase "$(INTDIR)\shape.obj"
	-@erase "$(INTDIR)\Shapes.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\glyphs.dll"
	-@erase "$(OUTDIR)\glyphs.exp"
	-@erase "$(OUTDIR)\glyphs.ilk"
	-@erase "$(OUTDIR)\glyphs.lib"
	-@erase "$(OUTDIR)\glyphs.pdb"
	-@erase ".\glyphs.h"
	-@erase ".\glyphs.tlb"
	-@erase ".\glyphs_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\glyphs.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\glyphs.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\glyphs.pdb" /debug /machine:I386 /def:".\glyphs.def" /out:"$(OUTDIR)\glyphs.dll" /implib:"$(OUTDIR)\glyphs.lib" /pdbtype:sept
DEF_FILE= \
	".\glyphs.def"
LINK32_OBJS= \
	"$(INTDIR)\glyphs.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\Lines.obj" \
	"$(INTDIR)\mat.obj" \
	"$(INTDIR)\shape.obj" \
	"$(INTDIR)\Shapes.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\glyphs.res"

"$(OUTDIR)\glyphs.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\glyphs.dll
InputPath=.\Debug\glyphs.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\glyphs.dll" ".\glyphs.tlb" ".\glyphs.h" ".\glyphs_i.c" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\glyphs.obj"
	-@erase "$(INTDIR)\glyphs.pch"
	-@erase "$(INTDIR)\glyphs.res"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\Lines.obj"
	-@erase "$(INTDIR)\mat.obj"
	-@erase "$(INTDIR)\shape.obj"
	-@erase "$(INTDIR)\Shapes.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\glyphs.dll"
	-@erase "$(OUTDIR)\glyphs.exp"
	-@erase "$(OUTDIR)\glyphs.ilk"
	-@erase "$(OUTDIR)\glyphs.lib"
	-@erase "$(OUTDIR)\glyphs.pdb"
	-@erase ".\glyphs.h"
	-@erase ".\glyphs.tlb"
	-@erase ".\glyphs_i.c"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\glyphs.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\glyphs.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\glyphs.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\glyphs.pdb" /debug /machine:I386 /def:".\glyphs.def" /out:"$(OUTDIR)\glyphs.dll" /implib:"$(OUTDIR)\glyphs.lib" /pdbtype:sept
DEF_FILE= \
	".\glyphs.def"
LINK32_OBJS= \
	"$(INTDIR)\glyphs.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\Lines.obj" \
	"$(INTDIR)\mat.obj" \
	"$(INTDIR)\shape.obj" \
	"$(INTDIR)\Shapes.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\glyphs.res"

"$(OUTDIR)\glyphs.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\glyphs.dll
InputPath=.\DebugU\glyphs.dll
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


!ELSEIF  "$(CFG)" == "glyphs - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize

ALL : "..\bin\glyphs_s.dll" ".\glyphs.tlb" ".\glyphs.h" ".\glyphs_i.c" ".\ReleaseMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\glyphs.obj"
	-@erase "$(INTDIR)\glyphs.pch"
	-@erase "$(INTDIR)\glyphs.res"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\Lines.obj"
	-@erase "$(INTDIR)\mat.obj"
	-@erase "$(INTDIR)\shape.obj"
	-@erase "$(INTDIR)\Shapes.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\glyphs_s.exp"
	-@erase "$(OUTDIR)\glyphs_s.lib"
	-@erase "..\bin\glyphs_s.dll"
	-@erase ".\glyphs.h"
	-@erase ".\glyphs.tlb"
	-@erase ".\glyphs_i.c"
	-@erase ".\ReleaseMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\glyphs.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\glyphs.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\glyphs_s.pdb" /machine:I386 /def:".\glyphs.def" /out:"../bin/glyphs_s.dll" /implib:"$(OUTDIR)\glyphs_s.lib"
DEF_FILE= \
	".\glyphs.def"
LINK32_OBJS= \
	"$(INTDIR)\glyphs.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\Lines.obj" \
	"$(INTDIR)\mat.obj" \
	"$(INTDIR)\shape.obj" \
	"$(INTDIR)\Shapes.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\glyphs.res"

"..\bin\glyphs_s.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=\.lokaj\zbmis\module\drawings\bin\glyphs_s.dll
InputPath=\.lokaj\zbmis\module\drawings\bin\glyphs_s.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency

ALL : "..\bin\glyphs_d.dll" ".\glyphs.tlb" ".\glyphs.h" ".\glyphs_i.c" ".\ReleaseMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\glyphs.obj"
	-@erase "$(INTDIR)\glyphs.pch"
	-@erase "$(INTDIR)\glyphs.res"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\Lines.obj"
	-@erase "$(INTDIR)\mat.obj"
	-@erase "$(INTDIR)\shape.obj"
	-@erase "$(INTDIR)\Shapes.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\glyphs_d.exp"
	-@erase "$(OUTDIR)\glyphs_d.lib"
	-@erase "..\bin\glyphs_d.dll"
	-@erase ".\glyphs.h"
	-@erase ".\glyphs.tlb"
	-@erase ".\glyphs_i.c"
	-@erase ".\ReleaseMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\glyphs.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\glyphs.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\glyphs_d.pdb" /machine:I386 /def:".\glyphs.def" /out:"../bin/glyphs_d.dll" /implib:"$(OUTDIR)\glyphs_d.lib"
DEF_FILE= \
	".\glyphs.def"
LINK32_OBJS= \
	"$(INTDIR)\glyphs.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\Lines.obj" \
	"$(INTDIR)\mat.obj" \
	"$(INTDIR)\shape.obj" \
	"$(INTDIR)\Shapes.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\glyphs.res"

"..\bin\glyphs_d.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=\.lokaj\zbmis\module\drawings\bin\glyphs_d.dll
InputPath=\.lokaj\zbmis\module\drawings\bin\glyphs_d.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat
	@echo off
	regsvr32 /s /c "$(TargetPath)"
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize

ALL : "..\bin\glyphs_us.dll" ".\glyphs.tlb" ".\glyphs.h" ".\glyphs_i.c" ".\ReleaseUMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\glyphs.obj"
	-@erase "$(INTDIR)\glyphs.pch"
	-@erase "$(INTDIR)\glyphs.res"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\Lines.obj"
	-@erase "$(INTDIR)\mat.obj"
	-@erase "$(INTDIR)\shape.obj"
	-@erase "$(INTDIR)\Shapes.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\glyphs_us.exp"
	-@erase "$(OUTDIR)\glyphs_us.lib"
	-@erase "..\bin\glyphs_us.dll"
	-@erase ".\glyphs.h"
	-@erase ".\glyphs.tlb"
	-@erase ".\glyphs_i.c"
	-@erase ".\ReleaseUMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\glyphs.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\glyphs.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\glyphs_us.pdb" /machine:I386 /def:".\glyphs.def" /out:"../bin/glyphs_us.dll" /implib:"$(OUTDIR)\glyphs_us.lib"
DEF_FILE= \
	".\glyphs.def"
LINK32_OBJS= \
	"$(INTDIR)\glyphs.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\Lines.obj" \
	"$(INTDIR)\mat.obj" \
	"$(INTDIR)\shape.obj" \
	"$(INTDIR)\Shapes.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\glyphs.res"

"..\bin\glyphs_us.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=\.lokaj\zbmis\module\drawings\bin\glyphs_us.dll
InputPath=\.lokaj\zbmis\module\drawings\bin\glyphs_us.dll
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


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency

ALL : "..\bin\glyphs_ud.dll" ".\glyphs.tlb" ".\glyphs.h" ".\glyphs_i.c" ".\ReleaseUMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\glyphs.obj"
	-@erase "$(INTDIR)\glyphs.pch"
	-@erase "$(INTDIR)\glyphs.res"
	-@erase "$(INTDIR)\kernel.obj"
	-@erase "$(INTDIR)\Lines.obj"
	-@erase "$(INTDIR)\mat.obj"
	-@erase "$(INTDIR)\shape.obj"
	-@erase "$(INTDIR)\Shapes.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\glyphs_ud.exp"
	-@erase "$(OUTDIR)\glyphs_ud.lib"
	-@erase "..\bin\glyphs_ud.dll"
	-@erase ".\glyphs.h"
	-@erase ".\glyphs.tlb"
	-@erase ".\glyphs_i.c"
	-@erase ".\ReleaseUMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\glyphs.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\glyphs.bsc"
BSC32_SBRS= \

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\glyphs_ud.pdb" /machine:I386 /def:".\glyphs.def" /out:"../bin/glyphs_ud.dll" /implib:"$(OUTDIR)\glyphs_ud.lib"
DEF_FILE= \
	".\glyphs.def"
LINK32_OBJS= \
	"$(INTDIR)\glyphs.obj" \
	"$(INTDIR)\kernel.obj" \
	"$(INTDIR)\Lines.obj" \
	"$(INTDIR)\mat.obj" \
	"$(INTDIR)\shape.obj" \
	"$(INTDIR)\Shapes.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\glyphs.res"

"..\bin\glyphs_ud.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=\.lokaj\zbmis\module\drawings\bin\glyphs_ud.dll
InputPath=\.lokaj\zbmis\module\drawings\bin\glyphs_ud.dll
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
!IF EXISTS("glyphs.dep")
!INCLUDE "glyphs.dep"
!ELSE
!MESSAGE Warning: cannot find "glyphs.dep"
!ENDIF
!ENDIF


!IF "$(CFG)" == "glyphs - Win32 Debug" || "$(CFG)" == "glyphs - Win32 Unicode Debug" || "$(CFG)" == "glyphs - Win32 Release MinSize" || "$(CFG)" == "glyphs - Win32 Release MinDependency" || "$(CFG)" == "glyphs - Win32 Unicode Release MinSize" || "$(CFG)" == "glyphs - Win32 Unicode Release MinDependency"
SOURCE=.\glyphs.cpp

"$(INTDIR)\glyphs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\glyphs.pch" ".\glyphs.h" ".\glyphs_i.c"


SOURCE=.\glyphs.idl

!IF  "$(CFG)" == "glyphs - Win32 Debug"

MTL_SWITCHES=/tlb ".\glyphs.tlb" /h "glyphs.h" /iid "glyphs_i.c" /Oicf

".\glyphs.tlb"	".\glyphs.h"	".\glyphs_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Debug"

MTL_SWITCHES=/tlb ".\glyphs.tlb" /h "glyphs.h" /iid "glyphs_i.c" /Oicf

".\glyphs.tlb"	".\glyphs.h"	".\glyphs_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Release MinSize"

MTL_SWITCHES=/tlb ".\glyphs.tlb" /h "glyphs.h" /iid "glyphs_i.c" /Oicf

".\glyphs.tlb"	".\glyphs.h"	".\glyphs_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Release MinDependency"

MTL_SWITCHES=/tlb ".\glyphs.tlb" /h "glyphs.h" /iid "glyphs_i.c" /Oicf

".\glyphs.tlb"	".\glyphs.h"	".\glyphs_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Release MinSize"

MTL_SWITCHES=/tlb ".\glyphs.tlb" /h "glyphs.h" /iid "glyphs_i.c" /Oicf

".\glyphs.tlb"	".\glyphs.h"	".\glyphs_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Release MinDependency"

MTL_SWITCHES=/tlb ".\glyphs.tlb" /h "glyphs.h" /iid "glyphs_i.c" /Oicf

".\glyphs.tlb"	".\glyphs.h"	".\glyphs_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=.\glyphs.rc

"$(INTDIR)\glyphs.res" : $(SOURCE) "$(INTDIR)" ".\glyphs.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\kernel.cpp

"$(INTDIR)\kernel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\glyphs.pch" ".\glyphs.h"


SOURCE=.\Lines.cpp

"$(INTDIR)\Lines.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\glyphs.pch" ".\glyphs.h"


SOURCE=.\mat.cpp

"$(INTDIR)\mat.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\glyphs.pch"


SOURCE=.\shape.cpp

"$(INTDIR)\shape.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\glyphs.pch"


SOURCE=.\Shapes.cpp

"$(INTDIR)\Shapes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\glyphs.pch" ".\glyphs.h"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "glyphs - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\glyphs.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\glyphs.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\glyphs.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\glyphs.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\glyphs.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\glyphs.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "glyphs - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\glyphs.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\glyphs.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF


!ENDIF

