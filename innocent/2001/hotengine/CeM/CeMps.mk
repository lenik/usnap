
CeMps.dll: dlldata.obj CeM_p.obj CeM_i.obj
	link /dll /out:CeMps.dll /def:CeMps.def /entry:DllMain dlldata.obj CeM_p.obj CeM_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CeMps.dll
	@del CeMps.lib
	@del CeMps.exp
	@del dlldata.obj
	@del CeM_p.obj
	@del CeM_i.obj
