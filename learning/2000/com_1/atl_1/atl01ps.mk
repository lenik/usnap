
atl01ps.dll: dlldata.obj atl01_p.obj atl01_i.obj
	link /dll /out:atl01ps.dll /def:atl01ps.def /entry:DllMain dlldata.obj atl01_p.obj atl01_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del atl01ps.dll
	@del atl01ps.lib
	@del atl01ps.exp
	@del dlldata.obj
	@del atl01_p.obj
	@del atl01_i.obj
