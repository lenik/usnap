
HDR_Kernelsps.dll: dlldata.obj HDR_Kernels_p.obj HDR_Kernels_i.obj
	link /dll /out:HDR_Kernelsps.dll /def:HDR_Kernelsps.def /entry:DllMain dlldata.obj HDR_Kernels_p.obj HDR_Kernels_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del HDR_Kernelsps.dll
	@del HDR_Kernelsps.lib
	@del HDR_Kernelsps.exp
	@del dlldata.obj
	@del HDR_Kernels_p.obj
	@del HDR_Kernels_i.obj
