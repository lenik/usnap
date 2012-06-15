
auto1ps.dll: dlldata.obj auto1_p.obj auto1_i.obj
	link /dll /out:auto1ps.dll /def:auto1ps.def /entry:DllMain dlldata.obj auto1_p.obj auto1_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del auto1ps.dll
	@del auto1ps.lib
	@del auto1ps.exp
	@del dlldata.obj
	@del auto1_p.obj
	@del auto1_i.obj
