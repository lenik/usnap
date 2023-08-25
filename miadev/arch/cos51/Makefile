
CC = sdcc
CFLAGS = --std-c99

FREEFLAGS = -DNDEBUG
CHECKFLAGS = --debug

CCLIB = sdar -rc

HEADERS = $(wildcard *.h)
MODULES = $(basename $(wildcard *.c))
SOURCES = $(addsuffix .c,$(MODULES))

all: all_medium
all_small: 	../../lib/cos51small.lib 	../../lib/cos51small_dbg.lib
all_medium: ../../lib/cos51medium.lib 	../../lib/cos51medium_dbg.lib
all_large: 	../../lib/cos51large.lib 	../../lib/cos51large_dbg.lib

../../lib/cos51small.lib: $(addsuffix _s.rel,$(MODULES))
	$(CCLIB) $@ $^

../../lib/cos51medium.lib: $(addsuffix _m.rel,$(MODULES))
	$(CCLIB) $@ $^

../../lib/cos51large.lib: $(addsuffix _l.rel,$(MODULES))
	$(CCLIB) $@ $^

../../lib/cos51small_dbg.lib: $(addsuffix _sd.rel,$(MODULES))
	$(CCLIB) $@ $^

../../lib/cos51medium_dbg.lib: $(addsuffix _md.rel,$(MODULES))
	$(CCLIB) $@ $^

../../lib/cos51large_dbg.lib: $(addsuffix _ld.rel,$(MODULES))
	$(CCLIB) $@ $^

%_s.rel: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(FREEFLAGS) --model-small -o $@ $<

%_m.rel: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(FREEFLAGS) --model-medium -o $@ $<

%_l.rel: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(FREEFLAGS) --model-large -o $@ $<

%_sd.rel: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(CHECKFLAGS) --model-small -o $@ $<

%_md.rel: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(CHECKFLAGS) --model-medium -o $@ $<

%_ld.rel: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(CHECKFLAGS) --model-large -o $@ $<

clean:
	rm -f *.adb *.asm *.bin *.lnk *.lst *.map *.mem *.rel *.rst *.sym
