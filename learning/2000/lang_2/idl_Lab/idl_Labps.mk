
idl_Labps.dll: dlldata.obj idl_Lab_p.obj idl_Lab_i.obj
	link /dll /out:idl_Labps.dll /def:idl_Labps.def /entry:DllMain dlldata.obj idl_Lab_p.obj idl_Lab_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del idl_Labps.dll
	@del idl_Labps.lib
	@del idl_Labps.exp
	@del dlldata.obj
	@del idl_Lab_p.obj
	@del idl_Lab_i.obj
