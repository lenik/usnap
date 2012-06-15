
CeE3Dps.dll: dlldata.obj CeE3D_p.obj CeE3D_i.obj
	link /dll /out:CeE3Dps.dll /def:CeE3Dps.def /entry:DllMain dlldata.obj CeE3D_p.obj CeE3D_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CeE3Dps.dll
	@del CeE3Dps.lib
	@del CeE3Dps.exp
	@del dlldata.obj
	@del CeE3D_p.obj
	@del CeE3D_i.obj
