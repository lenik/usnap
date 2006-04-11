@echo off

set /p nfst=Enter Nfs Title:
set /p nfsm=Enter Nfs Mapping Target:
if "%nfsm%"=="" set nfsm=.
nfs -m=%nfsm% %nfst%
