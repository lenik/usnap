
atl3ps.dll: dlldata.obj atl3_p.obj atl3_i.obj
	link /dll /out:atl3ps.dll /def:atl3ps.def /entry:DllMain dlldata.obj atl3_p.obj atl3_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del atl3ps.dll
	@del atl3ps.lib
	@del atl3ps.exp
	@del dlldata.obj
	@del atl3_p.obj
	@del atl3_i.obj
