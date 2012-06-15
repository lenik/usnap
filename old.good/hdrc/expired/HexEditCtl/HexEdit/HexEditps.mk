
HexEditps.dll: dlldata.obj HexEdit_p.obj HexEdit_i.obj
	link /dll /out:HexEditps.dll /def:HexEditps.def /entry:DllMain dlldata.obj HexEdit_p.obj HexEdit_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del HexEditps.dll
	@del HexEditps.lib
	@del HexEditps.exp
	@del dlldata.obj
	@del HexEdit_p.obj
	@del HexEdit_i.obj
