
LowXps.dll: dlldata.obj LowX_p.obj LowX_i.obj
	link /dll /out:LowXps.dll /def:LowXps.def /entry:DllMain dlldata.obj LowX_p.obj LowX_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del LowXps.dll
	@del LowXps.lib
	@del LowXps.exp
	@del dlldata.obj
	@del LowX_p.obj
	@del LowX_i.obj
