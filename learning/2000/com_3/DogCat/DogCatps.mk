
DogCatps.dll: dlldata.obj DogCat_p.obj DogCat_i.obj
	link /dll /out:DogCatps.dll /def:DogCatps.def /entry:DllMain dlldata.obj DogCat_p.obj DogCat_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DogCatps.dll
	@del DogCatps.lib
	@del DogCatps.exp
	@del dlldata.obj
	@del DogCat_p.obj
	@del DogCat_i.obj
