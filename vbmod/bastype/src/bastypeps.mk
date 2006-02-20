
bastypeps.dll: dlldata.obj bastype_p.obj bastype_i.obj
	link /dll /out:bastypeps.dll /def:bastypeps.def /entry:DllMain dlldata.obj bastype_p.obj bastype_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del bastypeps.dll
	@del bastypeps.lib
	@del bastypeps.exp
	@del dlldata.obj
	@del bastype_p.obj
	@del bastype_i.obj
