
OeFSps.dll: dlldata.obj OeFS_p.obj OeFS_i.obj
	link /dll /out:OeFSps.dll /def:OeFSps.def /entry:DllMain dlldata.obj OeFS_p.obj OeFS_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OeFSps.dll
	@del OeFSps.lib
	@del OeFSps.exp
	@del dlldata.obj
	@del OeFS_p.obj
	@del OeFS_i.obj
