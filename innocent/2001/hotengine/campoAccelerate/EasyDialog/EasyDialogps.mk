
EasyDialogps.dll: dlldata.obj EasyDialog_p.obj EasyDialog_i.obj
	link /dll /out:EasyDialogps.dll /def:EasyDialogps.def /entry:DllMain dlldata.obj EasyDialog_p.obj EasyDialog_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del EasyDialogps.dll
	@del EasyDialogps.lib
	@del EasyDialogps.exp
	@del dlldata.obj
	@del EasyDialog_p.obj
	@del EasyDialog_i.obj
