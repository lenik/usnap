
com01ps.dll: dlldata.obj com01_p.obj com01_i.obj
	link /dll /out:com01ps.dll /def:com01ps.def /entry:DllMain dlldata.obj com01_p.obj com01_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del com01ps.dll
	@del com01ps.lib
	@del com01ps.exp
	@del dlldata.obj
	@del com01_p.obj
	@del com01_i.obj
