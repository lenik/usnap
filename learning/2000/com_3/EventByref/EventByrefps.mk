
EventByrefps.dll: dlldata.obj EventByref_p.obj EventByref_i.obj
	link /dll /out:EventByrefps.dll /def:EventByrefps.def /entry:DllMain dlldata.obj EventByref_p.obj EventByref_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del EventByrefps.dll
	@del EventByrefps.lib
	@del EventByrefps.exp
	@del dlldata.obj
	@del EventByref_p.obj
	@del EventByref_i.obj
