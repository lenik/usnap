
CeSps.dll: dlldata.obj CeS_p.obj CeS_i.obj
	link /dll /out:CeSps.dll /def:CeSps.def /entry:DllMain dlldata.obj CeS_p.obj CeS_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CeSps.dll
	@del CeSps.lib
	@del CeSps.exp
	@del dlldata.obj
	@del CeS_p.obj
	@del CeS_i.obj
