# Microsoft Developer Studio Project File - Name="g_x1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=g_x1 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "x1.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "x1.mak" CFG="g_x1 - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "g_x1 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "g_x1 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "g_x1 - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "g_x1 - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "g_x1 - Win32 Release"
# Name "g_x1 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\x1.cpp
# End Source File
# Begin Source File

SOURCE=.\x1.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\state_machine.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\x1.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "rep.g"

# PROP Default_Filter ".g"
# Begin Source File

SOURCE=..\..\rep\basic.g
# End Source File
# Begin Source File

SOURCE=..\..\rep\epfs_script.g
# End Source File
# Begin Source File

SOURCE=..\..\rep\g.g
# End Source File
# Begin Source File

SOURCE=..\..\rep\syntax.g
# End Source File
# Begin Source File

SOURCE=..\..\rep\xaa.g
# End Source File
# End Group
# Begin Group "x@a"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\..\..\p\sup\x@a\doc\x@a.ep.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\p\sup\x@a\doc\x@a.method.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\p\sup\x@a\doc\x@a.os.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\p\sup\x@a\doc\x@a.script.list.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\p\sup\x@a\doc\x@a.script.macro.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\p\sup\x@a\doc\x@a.script.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\p\sup\x@a\doc\x@a.txt"
# End Source File
# End Group
# Begin Group "doc"

# PROP Default_Filter ".txt"
# Begin Source File

SOURCE="..\..\doc\g系统模型.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\titi-1.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\动态语法规则.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\核心问题.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\嵌套语法形式.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\实现相关.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\图规约-图栈.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\形态转换.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\杂题.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\正则分析.txt"
# End Source File
# Begin Source File

SOURCE=".\转换文法.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\字符集.txt"
# End Source File
# Begin Source File

SOURCE="..\..\doc\字符集方案.txt"
# End Source File
# End Group
# Begin Group "original"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\ori\regular.y
# End Source File
# End Group
# Begin Group "samples.g"

# PROP Default_Filter ".g"
# Begin Group "gdl ref"

# PROP Default_Filter ".gdl"
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\BASIC\Basic.gdl
# End Source File
# Begin Source File

SOURCE="Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\C++\cpp.GDL"
# End Source File
# Begin Source File

SOURCE="Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\C#\CS.GDL"
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\csv\Csv.gdl
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\Dates\Dates.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\Backtracking\Expression\Expression.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\Expression\Expression.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\HTML\Html.gdl
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\IDL\Idl.gdl
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\Java\Java.gdl
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\JavaScript\JavaScript.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\JustFax\JustFax.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\HTML\Markup.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\Backtracking\Meridian\Meridian.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\MiniGram\MiniGram.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\Pascal\pascal.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\PhoneBook\PhoneBook.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\PHP\PHP.GDL
# End Source File
# Begin Source File

SOURCE="Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\C++\PreProcessCPP.GDL"
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\RegExp\RegExp.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\DevStudio\Resource.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\SmallTalk\SmallTalk.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\SQL\sql.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\SQL2\sql2.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\TSQL\TSQL.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\VB.NET\VBNET.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\BASIC\VBScript.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\VHDL\Vhdl.gdl
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\VisualBasic6\VisualBasic6.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\VRML\Vrml.gdl
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\XPath\XMLNames.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\XPath\XPath.GDL
# End Source File
# Begin Source File

SOURCE=Y:\Files\ref\grammer\soft\ProGrammar\Projects\Examples\XPath\XPtr.GDL
# End Source File
# End Group
# Begin Group "lang"

# PROP Default_Filter ".g"
# Begin Source File

SOURCE=..\..\samples\lang\ada.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\asp.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\basic.g
# End Source File
# Begin Source File

SOURCE="..\..\samples\lang\c#.g"
# End Source File
# Begin Source File

SOURCE="..\..\samples\lang\c++.g"
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\c.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\html.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\idl.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\java.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\javascript.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\pascal.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\perl.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\php.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\prolog.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\sgml.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\smalltalk.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\soml.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\vbscript.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\visualbasic.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\vrml.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\lang\xml.g
# End Source File
# End Group
# Begin Group "exp"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\samples\exp\mid-.g"
# End Source File
# Begin Source File

SOURCE="..\..\samples\exp\post-.g"
# End Source File
# Begin Source File

SOURCE=..\..\samples\exp\pretty.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\exp\regular.g
# End Source File
# End Group
# Begin Group "graph"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\samples\graph\cloud.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\graph\mountain.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\graph\tree.g
# End Source File
# End Group
# Begin Group "apps"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\samples\apps\bsd-1.g"
# End Source File
# Begin Source File

SOURCE=..\..\samples\apps\cord.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\apps\lethe.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\apps\rr.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\apps\tit.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\apps\titi.g
# End Source File
# End Group
# Begin Group "bin"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\samples\bin\c_51.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\bin\c_68k.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\bin\c_98.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\bin\c_ia32.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\bin\c_javavm.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\bin\c_pic.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\bin\c_x86.g
# End Source File
# Begin Source File

SOURCE=..\..\samples\bin\c_z80.g
# End Source File
# End Group
# End Group
# Begin Group "ref"

# PROP Default_Filter ""
# Begin Group "flex"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\ccl.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\dfa.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\ecs.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\flex.1"
# End Source File
# Begin Source File

SOURCE="C:\c\lang\flex-2.5.4\flex.skl"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\flexdef.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\FlexLexer.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\gen.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\main.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\misc.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\nfa.c"
# End Source File
# Begin Source File

SOURCE="C:\c\lang\flex-2.5.4\MISC\parse.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\parse.y"
# End Source File
# Begin Source File

SOURCE="C:\c\lang\flex-2.5.4\scan.l"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\skel.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\sym.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\tblcmp.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\version.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\flex-2.5.4\yylex.c"
# End Source File
# End Group
# Begin Group "bison"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\alloca.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\allocate.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\closure.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\conflicts.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\derives.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\files.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\files.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\getargs.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\getopt.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\getopt.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\getopt1.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\gram.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\gram.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\lalr.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\lex.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\lex.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\LR0.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\machine.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\main.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\new.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\nullable.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\output.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\print.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\reader.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\reduce.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\state.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\symtab.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\symtab.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\system.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\types.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\version.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\vmsgetargs.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\warshall.c"
# End Source File
# End Group
# Begin Group "PackerC"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\..\a\ide\PackerC\PackerC\ReadMe.txt
# End Source File
# End Group
# Begin Group "ref.doc"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\bison.info-1"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\bison.info-2"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\bison.info-3"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\bison.info-4"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\bison.info-5"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\..\c\lang\bison-1.25\bison.simple"
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
