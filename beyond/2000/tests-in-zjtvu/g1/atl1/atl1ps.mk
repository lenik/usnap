
atl1ps.dll: dlldata.obj atl1_p.obj atl1_i.obj
	link /dll /out:atl1ps.dll /def:atl1ps.def /entry:DllMain dlldata.obj atl1_p.obj atl1_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del atl1ps.dll
	@del atl1ps.lib
	@del atl1ps.exp
	@del dlldata.obj
	@del atl1_p.obj
	@del atl1_i.obj
