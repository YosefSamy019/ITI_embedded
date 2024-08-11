# @Youssef Samy Youssef, Copy Rights

PROJ_NAME= test

CC=avr-
CFLAGS=-mmcu=atmega32 -g
INCLUDE= -I.
LIBS=   #for static libraries (.a) extention

#------------------------------------------------
#FILES_C=$(shell find . -name '*.c')
#FILES_S=$(shell find . -name '*.s')
#FILES_H=$(shell find . -name '*.h')

FILES_C=$(wildcard *.c)
FILES_S=$(wildcard *.s)
FILES_H=$(wildcard *.h)

_C_TO_O=$(FILES_C:.c=.o)
_S_TO_O=$(FILES_S:.s=.o)
_C_TO_S=$(FILES_C:.c=.s)

#------------------------------------------------


all: $(PROJ_NAME).bin $(PROJ_NAME).hex util
	rm $(_C_TO_O) 
	rm $(_C_TO_S)
	rm $(_S_TO_O)
	
	@echo ""
	@echo "---> Build is Done <---"
	@echo "Make File by Youssef Samy"
	@echo ""
	

assembly:  $(PROJ_NAME).bin $(PROJ_NAME).hex $(_C_TO_S) util
	@echo ""
	@echo "---> Build is Done <---"
	@echo "Make File by Youssef Samy"
	@echo ""

util: 
	$(CC)objdump -h $(PROJ_NAME).elf
	#$(CC)objdump -D $(PROJ_NAME).elf
	#$(CC)objdump -x $(PROJ_NAME).elf

	#$(CC)nm $(PROJ_NAME).elf
	#$(CC)size $(PROJ_NAME).elf
	#$(CC)readelf -a $(PROJ_NAME).elf

clean:
	@echo ""
	@echo "CLEAN all"

	rm $(PROJ_NAME).hex
	rm $(PROJ_NAME).bin
	rm $(PROJ_NAME).elf
	rm Map_file.map
	rm $(_C_TO_O) 
	rm $(_C_TO_S)
	rm $(_S_TO_O)
	@echo ""

#------------------------------------------------

%.o: %.c $(FILES_H) 
	$(CC)gcc -c $(CFLAGS) $(INCLUDE) $< -o $@


%.s: %.c $(FILES_H)
	$(CC)gcc -S $(CFLAGS) $(INCLUDE) $< -o $@


%.o: %.s
	$(CC)as $(CFLAGS) $< -o $@

$(PROJ_NAME).elf: $(_C_TO_O) $(_S_TO_O) linker_script.ld
	$(CC)ld -T linker_script.ld $(LIBS) $(_C_TO_O) $(_S_TO_O) -o $@ -Map=Map_file.map


$(PROJ_NAME).bin: $(PROJ_NAME).elf
	$(CC)objcopy -O binary $< $@

$(PROJ_NAME).hex: $(PROJ_NAME).elf
	$(CC)objcopy -O ihex $< $@

#------------------------------------------------


