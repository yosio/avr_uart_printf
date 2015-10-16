PROG=main
OBJS=${PROG}.o CUart.o
MCU=atmega88
F_CPU=8000000UL # internal 8MHz clock
#--------

ELF=$(PROG)
IHEX=$(PROG).ihex

CC=avr-g++
CFLAGS=-g -O2 -mmcu=$(MCU) -DF_CPU=$(F_CPU)
LDFLAGS=-g -O2 -mmcu=$(MCU)
OBJCOPY=avr-objcopy

all: $(IHEX)

$(IHEX): $(ELF)

$(ELF): $(OBJS)

%.ihex: %
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

clean:
	-$(RM) $(ELF) $(IHEX) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

run: $(IHEX)
	hidspx $(IHEX)

.PHONY: all clean