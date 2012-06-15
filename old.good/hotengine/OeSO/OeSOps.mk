
OeSOps.dll: dlldata.obj OeSO_p.obj OeSO_i.obj
	link /dll /out:OeSOps.dll /def:OeSOps.def /entry:DllMain dlldata.obj OeSO_p.obj OeSO_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OeSOps.dll
	@del OeSOps.lib
	@del OeSOps.exp
	@del dlldata.obj
	@del OeSO_p.obj
	@del OeSO_i.obj
