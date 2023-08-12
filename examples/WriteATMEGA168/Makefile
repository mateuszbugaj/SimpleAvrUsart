# USART Library
USART_LIBRARY_DIR = ../..
USART_LIBRARY_NAME = USART
USART_LIBRARY_INC_DIR = $(USART_LIBRARY_DIR)/inc
USART_LIB = $(USART_LIBRARY_DIR)/$(USART_LIBRARY_NAME).a

MCU=atmega168  
F_CPU=8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I$(USART_LIBRARY_INC_DIR) -I./inc
TARGET=main
SRCDIR := src
INCDIR := ./inc
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(SRCDIR)/%.o, $(SOURCES))

.PHONY: all flash clean

all: ${TARGET}.hex

# Rules to make .a library files using their Makefiles
$(USART_LIB):
	$(MAKE) -C $(USART_LIBRARY_DIR)

# Rule to make .o files from the example source code
$(SRCDIR)/%.o: $(SRCDIR)/%.c 
	${CC} -c -MMD ${CFLAGS} -I$(INCDIR) $< -o $@

# Rule to make .bin file using example .o files and .a libary files
${TARGET}.bin: $(OBJECTS) $(USART_LIB)
	${CC} ${CFLAGS} -o $@ $^

${TARGET}.hex: ${TARGET}.bin 
	${OBJCOPY} -j .text -j .data -O ihex $< $@

flash: ${TARGET}.hex
	avrdude -p ${MCU} -c usbasp -U flash:w:$<:i -F -P usb -B 4

clean:
	$(MAKE) -C $(USART_LIBRARY_DIR) clean
	rm -f *.bin *.hex $(SRCDIR)/*.o $(SRCDIR)/*.d

flash_and_clean: all flash clean