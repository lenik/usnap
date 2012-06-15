@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by DOCVIEW.HPJ. >"hlp\docview.hm"
echo. >>"hlp\docview.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\docview.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\docview.hm"
echo. >>"hlp\docview.hm"
echo // Prompts (IDP_*) >>"hlp\docview.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\docview.hm"
echo. >>"hlp\docview.hm"
echo // Resources (IDR_*) >>"hlp\docview.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\docview.hm"
echo. >>"hlp\docview.hm"
echo // Dialogs (IDD_*) >>"hlp\docview.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\docview.hm"
echo. >>"hlp\docview.hm"
echo // Frame Controls (IDW_*) >>"hlp\docview.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\docview.hm"
REM -- Make help for Project DOCVIEW


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\docview.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\docview.hlp" goto :Error
if not exist "hlp\docview.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\docview.hlp" Debug
if exist Debug\nul copy "hlp\docview.cnt" Debug
if exist Release\nul copy "hlp\docview.hlp" Release
if exist Release\nul copy "hlp\docview.cnt" Release
echo.
goto :done

:Error
echo hlp\docview.hpj(1) : error: Problem encountered creating help file

:done
echo.
