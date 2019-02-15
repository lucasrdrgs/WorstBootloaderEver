ENTRY(loader)
SECTIONS
{
	. = 0x07e00;
	.text : { *(.text) }
	.rodata : { *(.rodata) }
	.data : { *(.data) }
}