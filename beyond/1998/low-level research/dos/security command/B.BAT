@echo off
set aaa=%1
if "%1"=="" set aaa=scmd
tasm %aaa%, %aaa%.obj, %aaa%.lst, %aaa%.xrf
tlink %aaa% /t

set aaa=
