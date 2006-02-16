
Binariesps.dll: dlldata.obj Binaries_p.obj Binaries_i.obj
	link /dll /out:Binariesps.dll /def:Binariesps.def /entry:DllMain dlldata.obj Binaries_p.obj Binaries_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Binariesps.dll
	@del Binariesps.lib
	@del Binariesps.exp
	@del dlldata.obj
	@del Binaries_p.obj
	@del Binaries_i.obj
