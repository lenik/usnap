
HDR_Servicesps.dll: dlldata.obj HDR_Services_p.obj HDR_Services_i.obj
	link /dll /out:HDR_Servicesps.dll /def:HDR_Servicesps.def /entry:DllMain dlldata.obj HDR_Services_p.obj HDR_Services_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del HDR_Servicesps.dll
	@del HDR_Servicesps.lib
	@del HDR_Servicesps.exp
	@del dlldata.obj
	@del HDR_Services_p.obj
	@del HDR_Services_i.obj
