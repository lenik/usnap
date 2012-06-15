
VBC=C:\progra~1\vs98\vb98\vb6.exe

.PHONY: all test clean

all: bin/vbext.dll

bin/vbext.dll:
	if not exist bin\* md bin
	$(VBC) /m vbext.vbp /outdir bin /out bin\make.out
	remd wait? ...
	type bin\make.out

test:
