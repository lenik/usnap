
CeLiImagesps.dll: dlldata.obj CeLiImages_p.obj CeLiImages_i.obj
	link /dll /out:CeLiImagesps.dll /def:CeLiImagesps.def /entry:DllMain dlldata.obj CeLiImages_p.obj CeLiImages_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del CeLiImagesps.dll
	@del CeLiImagesps.lib
	@del CeLiImagesps.exp
	@del dlldata.obj
	@del CeLiImages_p.obj
	@del CeLiImages_i.obj
