
glyphsps.dll: dlldata.obj glyphs_p.obj glyphs_i.obj
	link /dll /out:glyphsps.dll /def:glyphsps.def /entry:DllMain dlldata.obj glyphs_p.obj glyphs_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del glyphsps.dll
	@del glyphsps.lib
	@del glyphsps.exp
	@del dlldata.obj
	@del glyphs_p.obj
	@del glyphs_i.obj
