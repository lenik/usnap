
ceVersionps.dll: dlldata.obj ceVersion_p.obj ceVersion_i.obj
	link /dll /out:ceVersionps.dll /def:ceVersionps.def /entry:DllMain dlldata.obj ceVersion_p.obj ceVersion_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ceVersionps.dll
	@del ceVersionps.lib
	@del ceVersionps.exp
	@del dlldata.obj
	@del ceVersion_p.obj
	@del ceVersion_i.obj
