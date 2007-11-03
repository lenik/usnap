@echo off

if "%setenv%"=="1" goto setenv

call vcvars32

rem gtk
set include=%include%;C:\.cirkonstancoj\SDK\GTK\include;C:\.cirkonstancoj\SDK\GTK\include\atk-1.0;C:\.cirkonstancoj\SDK\GTK\include\fontconfig;C:\.cirkonstancoj\SDK\GTK\include\freetype2;C:\.cirkonstancoj\SDK\GTK\include\glib-2.0;C:\.cirkonstancoj\SDK\GTK\include\gtk-2.0;C:\.cirkonstancoj\SDK\GTK\include\gtkglext-1.0;C:\.cirkonstancoj\SDK\GTK\include\libart-2.0;C:\.cirkonstancoj\SDK\GTK\include\libglade-2.0;C:\.cirkonstancoj\SDK\GTK\include\libxml2;C:\.cirkonstancoj\SDK\GTK\include\pango-1.0
set include=%include%;C:\.cirkonstancoj\SDK\GTK\lib\glib-2.0\include
set lib=%lib%;C:\.cirkonstancoj\SDK\GTK\lib
set path=C:\.cirkonstancoj\SDK\GTK\bin;%path%

set include=..\src;%include%
set setenv=1

:setenv

rem gcc words.c ..\src\parser.c glib-2.0.lib -o words.exe
cl words.c ..\src\parser.c glib-2.0.lib -o words.exe
cl dbls.c ..\src\parser.c glib-2.0.lib -o dbls.exe
