
C_FILES= $(wildcard *.c)

_EXE_FILES= $(C_FILES:.c=.exe)





all: $(_EXE_FILES)
	@echo "All files are compiled"
	@echo ""

clean:
	rm $(_EXE_FILES)

%.exe: %.c
	gcc -I. $< -o $@
	
