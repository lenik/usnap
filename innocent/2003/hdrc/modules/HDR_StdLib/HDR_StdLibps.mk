
HDR_StdLibps.dll: dlldata.obj HDR_StdLib_p.obj HDR_StdLib_i.obj
	link /dll /out:HDR_StdLibps.dll /def:HDR_StdLibps.def /entry:DllMain dlldata.obj HDR_StdLib_p.obj HDR_StdLib_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del HDR_StdLibps.dll
	@del HDR_StdLibps.lib
	@del HDR_StdLibps.exp
	@del dlldata.obj
	@del HDR_StdLib_p.obj
	@del HDR_StdLib_i.obj
