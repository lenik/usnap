
Cryptps.dll: dlldata.obj Crypt_p.obj Crypt_i.obj
	link /dll /out:Cryptps.dll /def:Cryptps.def /entry:DllMain dlldata.obj Crypt_p.obj Crypt_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Cryptps.dll
	@del Cryptps.lib
	@del Cryptps.exp
	@del dlldata.obj
	@del Crypt_p.obj
	@del Crypt_i.obj
