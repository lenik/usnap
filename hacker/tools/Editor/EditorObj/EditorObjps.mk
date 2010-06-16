
EditorObjps.dll: dlldata.obj EditorObj_p.obj EditorObj_i.obj
	link /dll /out:EditorObjps.dll /def:EditorObjps.def /entry:DllMain dlldata.obj EditorObj_p.obj EditorObj_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del EditorObjps.dll
	@del EditorObjps.lib
	@del EditorObjps.exp
	@del dlldata.obj
	@del EditorObj_p.obj
	@del EditorObj_i.obj
