
CeFIps.dll: dlldata.obj CeFI_p.obj CeFI_i.obj
	link /dll /out:CeFIps.dll /def:CeFIps.def /entry:DllMain dlldata.obj CeFI_p.obj CeFI_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CeFIps.dll
	@del CeFIps.lib
	@del CeFIps.exp
	@del dlldata.obj
	@del CeFI_p.obj
	@del CeFI_i.obj
