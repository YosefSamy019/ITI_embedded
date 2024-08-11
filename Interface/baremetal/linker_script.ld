/*
	@Youssef Samy Youssef
	Linker Script, Atmega32
*/


MEMORY{
	flash(rx) : ORIGIN  = 0x0000, LENGTH = 32k
	sram(rwx) : ORIGIN  = 0x0060, LENGTH =  2k
}


SECTIONS{
	
	. = 0x0000;

	.text : 
	{
		_TEXT_START = .;

		*(.vectors*)
		*(.text*)

		. = ALIGN(2);
		_TEXT_END = .;


	}> flash

	.rodata :
	{
		_RODATA_START = .;

		*(.rodata*)

		. = ALIGN(2);
		_RODATA_END = .;

	}> flash

	.data :
	{
		_DATA_START = .;

		*(.data*)

		. = ALIGN(2);
		_DATA_END = .;

	}> sram AT> flash

	.bss :
	{
		_BSS_START = .;

		*(.bss*)
	

		. = ALIGN(2);
		_BSS_END = .;

	
	}> sram
	
}
