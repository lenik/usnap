
MultiLibps.dll: dlldata.obj MultiLib_p.obj MultiLib_i.obj
	link /dll /out:MultiLibps.dll /def:MultiLibps.def /entry:DllMain dlldata.obj MultiLib_p.obj MultiLib_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MultiLibps.dll
	@del MultiLibps.lib
	@del MultiLibps.exp
	@del dlldata.obj
	@del MultiLib_p.obj
	@del MultiLib_i.obj
