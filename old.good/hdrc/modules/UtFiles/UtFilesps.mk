
UtFilesps.dll: dlldata.obj UtFiles_p.obj UtFiles_i.obj
	link /dll /out:UtFilesps.dll /def:UtFilesps.def /entry:DllMain dlldata.obj UtFiles_p.obj UtFiles_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del UtFilesps.dll
	@del UtFilesps.lib
	@del UtFilesps.exp
	@del dlldata.obj
	@del UtFiles_p.obj
	@del UtFiles_i.obj
