
OeXpps.dll: dlldata.obj OeXp_p.obj OeXp_i.obj
	link /dll /out:OeXpps.dll /def:OeXpps.def /entry:DllMain dlldata.obj OeXp_p.obj OeXp_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OeXpps.dll
	@del OeXpps.lib
	@del OeXpps.exp
	@del dlldata.obj
	@del OeXp_p.obj
	@del OeXp_i.obj
