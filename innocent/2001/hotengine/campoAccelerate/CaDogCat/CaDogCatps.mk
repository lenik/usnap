
CaDogCatps.dll: dlldata.obj CaDogCat_p.obj CaDogCat_i.obj
	link /dll /out:CaDogCatps.dll /def:CaDogCatps.def /entry:DllMain dlldata.obj CaDogCat_p.obj CaDogCat_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CaDogCatps.dll
	@del CaDogCatps.lib
	@del CaDogCatps.exp
	@del dlldata.obj
	@del CaDogCat_p.obj
	@del CaDogCat_i.obj
