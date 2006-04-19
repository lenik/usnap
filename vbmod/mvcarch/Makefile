
VBC=C:\progra~1\vs98\vb98\vb6.exe

.PHONY: all test clean

all: bin/mvcarch.dll

bin/mvcarch.dll:
	if not exist bin\* md bin
	$(VBC) /m mvcarch.vbp /outdir bin /out bin\make.out
	type bin\make.out

test:
