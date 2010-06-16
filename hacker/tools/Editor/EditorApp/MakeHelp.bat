@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by EDITORAPP.HPJ. >"hlp\EditorApp.hm"
echo. >>"hlp\EditorApp.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\EditorApp.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\EditorApp.hm"
echo. >>"hlp\EditorApp.hm"
echo // Prompts (IDP_*) >>"hlp\EditorApp.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\EditorApp.hm"
echo. >>"hlp\EditorApp.hm"
echo // Resources (IDR_*) >>"hlp\EditorApp.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\EditorApp.hm"
echo. >>"hlp\EditorApp.hm"
echo // Dialogs (IDD_*) >>"hlp\EditorApp.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\EditorApp.hm"
echo. >>"hlp\EditorApp.hm"
echo // Frame Controls (IDW_*) >>"hlp\EditorApp.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\EditorApp.hm"
REM -- Make help for Project EDITORAPP


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\EditorApp.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\EditorApp.hlp" goto :Error
if not exist "hlp\EditorApp.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\EditorApp.hlp" Debug
if exist Debug\nul copy "hlp\EditorApp.cnt" Debug
if exist Release\nul copy "hlp\EditorApp.hlp" Release
if exist Release\nul copy "hlp\EditorApp.cnt" Release
echo.
goto :done

:Error
echo hlp\EditorApp.hpj(1) : error: Problem encountered creating help file

:done
echo.
