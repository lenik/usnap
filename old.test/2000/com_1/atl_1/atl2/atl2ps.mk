
atl2ps.dll: dlldata.obj atl2_p.obj atl2_i.obj
	link /dll /out:atl2ps.dll /def:atl2ps.def /entry:DllMain dlldata.obj atl2_p.obj atl2_i.obj \
		mtxih.lib mtx.lib mtxguid.lib \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
		ole32.lib advapi32.lib

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		/MD \
		$<

clean:
	@del atl2ps.dll
	@del atl2ps.lib
	@del atl2ps.exp
	@del dlldata.obj
	@del atl2_p.obj
	@del atl2_i.obj
