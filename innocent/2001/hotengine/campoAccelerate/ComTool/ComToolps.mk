
ComToolps.dll: dlldata.obj ComTool_p.obj ComTool_i.obj
	link /dll /out:ComToolps.dll /def:ComToolps.def /entry:DllMain dlldata.obj ComTool_p.obj ComTool_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ComToolps.dll
	@del ComToolps.lib
	@del ComToolps.exp
	@del dlldata.obj
	@del ComTool_p.obj
	@del ComTool_i.obj
