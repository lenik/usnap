
DiskDriveKernelps.dll: dlldata.obj DiskDriveKernel_p.obj DiskDriveKernel_i.obj
	link /dll /out:DiskDriveKernelps.dll /def:DiskDriveKernelps.def /entry:DllMain dlldata.obj DiskDriveKernel_p.obj DiskDriveKernel_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DiskDriveKernelps.dll
	@del DiskDriveKernelps.lib
	@del DiskDriveKernelps.exp
	@del dlldata.obj
	@del DiskDriveKernel_p.obj
	@del DiskDriveKernel_i.obj
