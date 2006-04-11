
OBJECTS=string.o

.PHONY: all dynamic static clean

all: dynamic static

dynamic: libcpf.so

static: libcpf.a

libcpf.so: $(OBJECTS)
	$(LD)

libcpf.a: $(OBJECTS)
	$(LD)

string.o: string.c
	$(CC) -o string.o string.c
