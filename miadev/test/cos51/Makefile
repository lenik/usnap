
LIBDIR = ../../lib
HEX2BIN = hex2bin

CC = sdcc
CFLAGS = --std-c99 -I../../arch

C_STC89C52RC = --code-size 0x2000 --xram-size 0x200
C_STC89C58RD = --code-size 0x8000 --xram-size 0x500

LFLAGS = --iram-size 0x100 $(C_STC89C52RC)

#MODULES = commtest comm2
#UNITS = commtest

MODULES = $(basename $(wildcard *.c))
UNITS = $(basename $(wildcard *test.c))

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

test_small: $(addsuffix _s.su,$(UNITS))
test_medium: $(addsuffix _m.su,$(UNITS))
test_large: $(addsuffix _l.su,$(UNITS))

%.su: %.ihx
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
	rm -f *.asm *.bin *.ihx *.lnk *.lst *.map *.mem *.rel *.rst *.sym *.adb *.cdb
