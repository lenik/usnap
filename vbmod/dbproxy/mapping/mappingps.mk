
mappingps.dll: dlldata.obj mapping_p.obj mapping_i.obj
	link /dll /out:mappingps.dll /def:mappingps.def /entry:DllMain dlldata.obj mapping_p.obj mapping_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del mappingps.dll
	@del mappingps.lib
	@del mappingps.exp
	@del dlldata.obj
	@del mapping_p.obj
	@del mapping_i.obj
