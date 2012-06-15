
# mirror:: /usnap/cpf/src
# mirror:: /open/sourceforge/xjl/simxml/src

CPF_HOME=../../../../../usnap/cpf

include $(CPF_HOME)/Makefile

.PHONY: all test clean cpf

all: six test

six: six.exe

six.exe: main.o parser.o input.o
	@$(LD) -o simxml.exe main.o input.o parser.o $(CPF_HOME)/lib/libcpf.a

input.o: input.cc

parser.o: parser.cc

cpf:
	@$(MAKE) -f $(CPF_HOME)/Makefile

test:
	cd test
	@$(MAKE)
	cd ..

clean:
	rm *.o
	rm *.exe
