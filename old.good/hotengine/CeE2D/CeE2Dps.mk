
CeE2Dps.dll: dlldata.obj CeE2D_p.obj CeE2D_i.obj
	link /dll /out:CeE2Dps.dll /def:CeE2Dps.def /entry:DllMain dlldata.obj CeE2D_p.obj CeE2D_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CeE2Dps.dll
	@del CeE2Dps.lib
	@del CeE2Dps.exp
	@del dlldata.obj
	@del CeE2D_p.obj
	@del CeE2D_i.obj
