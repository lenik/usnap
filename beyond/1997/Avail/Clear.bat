@echo off
echo Deleteing Backup Files ...
echo --------------------------

echo Deleted Backup Files :>Backup
dir /b Include\*.bak   >>Backup
dir /b Lib\*.bak       >>Backup
dir /b Source\*.bak    >>Backup
dir /b Source\Module\*.bak     >>Backup
dir /b Program\*.Bak   >>Backup
dir /b Runtime\*.Bak   >>Backup

dt /y Include\*.bak >nul
dt /y Lib\*.bak >nul
dt /y Source\*.bak >nul
dt /y Source\Module\*.bak >nul
dt /y Program\*.Bak >nul
dt /y Runtime\*.Bak >nul

type Backup
dt /y Backup >nul
echo All Done!
