
catps.dll: dlldata.obj cat_p.obj cat_i.obj
	link /dll /out:catps.dll /def:catps.def /entry:DllMain dlldata.obj cat_p.obj cat_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del catps.dll
	@del catps.lib
	@del catps.exp
	@del dlldata.obj
	@del cat_p.obj
	@del cat_i.obj
