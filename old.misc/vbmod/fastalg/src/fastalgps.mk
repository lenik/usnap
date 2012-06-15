
fastalgps.dll: dlldata.obj fastalg_p.obj fastalg_i.obj
	link /dll /out:fastalgps.dll /def:fastalgps.def /entry:DllMain dlldata.obj fastalg_p.obj fastalg_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del fastalgps.dll
	@del fastalgps.lib
	@del fastalgps.exp
	@del dlldata.obj
	@del fastalg_p.obj
	@del fastalg_i.obj
