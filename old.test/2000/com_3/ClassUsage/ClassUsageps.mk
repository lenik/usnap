
ClassUsageps.dll: dlldata.obj ClassUsage_p.obj ClassUsage_i.obj
	link /dll /out:ClassUsageps.dll /def:ClassUsageps.def /entry:DllMain dlldata.obj ClassUsage_p.obj ClassUsage_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ClassUsageps.dll
	@del ClassUsageps.lib
	@del ClassUsageps.exp
	@del dlldata.obj
	@del ClassUsage_p.obj
	@del ClassUsage_i.obj
