
CeMMps.dll: dlldata.obj CeMM_p.obj CeMM_i.obj
	link /dll /out:CeMMps.dll /def:CeMMps.def /entry:DllMain dlldata.obj CeMM_p.obj CeMM_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CeMMps.dll
	@del CeMMps.lib
	@del CeMMps.exp
	@del dlldata.obj
	@del CeMM_p.obj
	@del CeMM_i.obj
