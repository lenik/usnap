
comops.dll: dlldata.obj como_p.obj como_i.obj
	link /dll /out:comops.dll /def:comops.def /entry:DllMain dlldata.obj como_p.obj como_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del comops.dll
	@del comops.lib
	@del comops.exp
	@del dlldata.obj
	@del como_p.obj
	@del como_i.obj
