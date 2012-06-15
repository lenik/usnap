
NetToolsps.dll: dlldata.obj NetTools_p.obj NetTools_i.obj
	link /dll /out:NetToolsps.dll /def:NetToolsps.def /entry:DllMain dlldata.obj NetTools_p.obj NetTools_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del NetToolsps.dll
	@del NetToolsps.lib
	@del NetToolsps.exp
	@del dlldata.obj
	@del NetTools_p.obj
	@del NetTools_i.obj
