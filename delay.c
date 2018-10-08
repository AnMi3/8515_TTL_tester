void delay200ms()
{
	asm volatile (
	"    ldi  r18, 9"	"\n\t"
	"    ldi  r19, 30"	"\n\t"
	"    ldi  r20, 229"	"\n\t"
	"1:  dec  r20"		"\n\t"
	"    brne 1b"		"\n\t"
	"    dec  r19"		"\n\t"
	"    brne 1b"		"\n\t"
	"    dec  r18"		"\n\t"
	"    brne 1b"		"\n\t"
	"    nop"			"\n\t"
	);
}

void delay1ms()
{
	asm volatile (
	"    ldi  r18, 11"	"\n\t"
	"    ldi  r19, 99"	"\n\t"
	"1:  dec  r19"		"\n\t"
	"    brne 1b"		"\n\t"
	"    dec  r18"		"\n\t"
	"    brne 1b"		"\n\t"
	);
}