
binaryps.dll: dlldata.obj binary_p.obj binary_i.obj
	link /dll /out:binaryps.dll /def:binaryps.def /entry:DllMain dlldata.obj binary_p.obj binary_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del binaryps.dll
	@del binaryps.lib
	@del binaryps.exp
	@del dlldata.obj
	@del binary_p.obj
	@del binary_i.obj
