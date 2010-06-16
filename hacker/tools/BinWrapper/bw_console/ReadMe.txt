

BW_CONSOLE

	Binary Wrapper -- Console version

	the script file for wrapper is usually <wrapper>.ini, and
	you can use BW_CONSOLE_SCRIPT environ to override it.


-- script keys

	RouteTo
	PrefixArgsCount
	PrefixArgs0..n-1
	PostfixArgsCount
	PostfixArgs0..n-1
	EnvironsCount
	Environ0..n-1
	ShowRoutedName
	Disable
	FindPath

	CalledTimes

	Banner
	Preout
	RecordInfo
-- arguments

	!test
	!help
	!update
	!wrap <exefile>
	!which <exefile...>
	!debug
	!stop
	!continue



-- examples:

	Wrap DELTREE.exe, so we can trace all deleting commands:

	bw_console !wrap DELTREE.exe

		=> rename "DELTREE.exe" to "DELTREE0.exe"
		=> copy "bw_console.exe" to "DelTree.exe"
		=> create the "DELTEEE.ini"



	DELTREE.ini
	---------------------
		[DELTREE]
		SystemVersion=z:\t\w\bw_console.exe		; so can call "DelTree !update" to update the wrapper.
		RouteTo=DELTREE0.exe
		PrefixArgsCount=1
		PrefixArgs0=/y
		PostfixArgsCount=0
		EnvironsCount=1
		Environ0=SET
