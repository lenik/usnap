
OeTps.dll: dlldata.obj OeT_p.obj OeT_i.obj
	link /dll /out:OeTps.dll /def:OeTps.def /entry:DllMain dlldata.obj OeT_p.obj OeT_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OeTps.dll
	@del OeTps.lib
	@del OeTps.exp
	@del dlldata.obj
	@del OeT_p.obj
	@del OeT_i.obj
