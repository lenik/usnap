@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by DV01.HPJ. >"hlp\dv01.hm"
echo. >>"hlp\dv01.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\dv01.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\dv01.hm"
echo. >>"hlp\dv01.hm"
echo // Prompts (IDP_*) >>"hlp\dv01.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\dv01.hm"
echo. >>"hlp\dv01.hm"
echo // Resources (IDR_*) >>"hlp\dv01.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\dv01.hm"
echo. >>"hlp\dv01.hm"
echo // Dialogs (IDD_*) >>"hlp\dv01.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\dv01.hm"
echo. >>"hlp\dv01.hm"
echo // Frame Controls (IDW_*) >>"hlp\dv01.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\dv01.hm"
REM -- Make help for Project DV01


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\dv01.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\dv01.hlp" goto :Error
if not exist "hlp\dv01.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\dv01.hlp" Debug
if exist Debug\nul copy "hlp\dv01.cnt" Debug
if exist Release\nul copy "hlp\dv01.hlp" Release
if exist Release\nul copy "hlp\dv01.cnt" Release
echo.
goto :done

:Error
echo hlp\dv01.hpj(1) : error: Problem encountered creating help file

:done
echo.
