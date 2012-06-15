

rem testgate batch file
set pp=c:\s\develop\general\dll_research\sockgate

rem 1. dll1->dll1old
	copy %pp%\testgate_dll1\debug\testgate_dll1.dll %pp%\testgate_dll1gate\dll_temp\testgate_dll1old.dll
	copy %pp%\testgate_dll1\debug\testgate_dll1.dll %pp%\testgate_dll1gate\debug\testgate_dll1old.dll

rem 2. dll1->client\1
	copy %pp%\testgate_dll1\debug\testgate_dll1.dll %pp%\testgate_dll1_client2\run_with_original

rem 3. dll1old, dll1gate->client\2
	copy %pp%\testgate_dll1gate\debug\testgate_dll1old.dll %pp%\testgate_dll1_client2\run_with_gate
	copy %pp%\testgate_dll1gate\debug\testgate_dll1.dll %pp%\testgate_dll1_client2\run_with_gate
