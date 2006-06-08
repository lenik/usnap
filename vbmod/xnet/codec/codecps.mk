
codecps.dll: dlldata.obj codec_p.obj codec_i.obj
	link /dll /out:codecps.dll /def:codecps.def /entry:DllMain dlldata.obj codec_p.obj codec_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del codecps.dll
	@del codecps.lib
	@del codecps.exp
	@del dlldata.obj
	@del codec_p.obj
	@del codec_i.obj
