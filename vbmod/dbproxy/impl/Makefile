
VBC=C:\progra~1\vs98\vb98\vb6.exe

.PHONY: all test clean

all: ../bin/dbproxy.dll

../bin/dbproxy.dll:
	if not exist ..\bin\* md ..\bin
	$(VBC) /m dbproxy.vbp /outdir ..\bin /out make.out
	type make.out

test:
