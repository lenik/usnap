
LIBDIR = ../../lib
HEX2BIN = hex2bin

CC = sdcc
CFLAGS = --std-c99 -I../../arch

C_STC89C52RC = --code-size 0x2000 --xram-size 0x200 -Wl-bPAGE1=0x1a00
C_STC89C58RD = --code-size 0x8000 --xram-size 0x500 -Wl-bPAGE1=0x1a00

LFLAGS = --iram-size 0x100 $(C_STC89C52RC)

MODULES = $(basename $(wildcard *.c))
#MODULES = commtest comm2

UNITS = $(basename $(wildcard *test.c))
#UNITS = comm1test comm2test

S51TEST = s51test

.SECONDARY: \
	$(addsuffix _s.ihx,$(MODULES)) \
	$(addsuffix _m.ihx,$(MODULES)) \
	$(addsuffix _l.ihx,$(MODULES))

all: bin_medium

test: test_medium

bin_small: $(addsuffix _s.bin,$(MODULES))
bin_medium: $(addsuffix _m.bin,$(MODULES))
bin_large: $(addsuffix _l.bin,$(MODULES))

test_small: $(addsuffix _s.out,$(UNITS))
test_medium: $(addsuffix _m.out,$(UNITS))
test_large: $(addsuffix _l.out,$(UNITS))

%.out: %.ihx
	$(S51TEST) $<

%.bin: %.ihx
	$(HEX2BIN) $<

%_s.ihx: %_s.rel $(LIBDIR)/cos51small.lib
	$(CC) --model-small     $(LFLAGS) $^

%_m.ihx: %_m.rel $(LIBDIR)/cos51medium.lib
	$(CC) --model-medium    $(LFLAGS) $^

%_l.ihx: %_l.rel $(LIBDIR)/cos51large.lib
	$(CC) --model-large     $(LFLAGS) $^


%_s.rel: %.c
	$(CC) -c $(CFLAGS) --model-small    -o $@ $<

%_m.rel: %.c
	$(CC) -c $(CFLAGS) --model-medium   -o $@ $<

%_l.rel: %.c
	$(CC) -c $(CFLAGS) --model-large    -o $@ $<

clean:
	rm -f *.asm *.bin *.ihx *.lnk *.lst *.map *.mem *.rel *.rst *.sym *.adb *.cdb *.out
