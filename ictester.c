#include "ictester.h"

uint8_t sym[4], seg;

 /* encoded symbols for 7 segment indicators */
const uint8_t znak[] PROGMEM = { 
	215,17,203,91,29,94,222,19,223,95,	/* [0-9] digits 0-9 */
	15, 8,								/* [10,11] Good(o), Bad(-) symbols */
	66,									/* [12] two horizontal lines as a testing process indicator */
	0,									/* [13] empty symbol */
	206,								/* [14] letter E */
	142,								/* [15] letter F */  /* not used yet */
	204,								/* [16] letter t */
	198,								/* [17] letter C */
	136,								/* [18] letter r */
};

/* segment select constants */
const uint8_t razr[] PROGMEM = { 128,64,32,16 };

#include "delay.c"

#include "test_7400.c"
#include "test_7402.c"
#include "test_7404.c"
#include "test_7406.c"
#include "test_7407.c"
#include "test_7408.c"
#include "test_7410.c"
#include "test_7411.c"
#include "test_7420.c"
#include "test_7427.c"
#include "test_7430.c"
#include "test_7432.c"
#include "test_7438.c"
#include "test_7474.c"
#include "test_7475.c"
#include "test_7486.c"
#include "test_7493.c"
#include "test_74125.c"
#include "test_74138.c"
#include "test_74155.c"
#include "test_74161.c"
#include "test_74166.c"
#include "test_74169.c"
#include "test_74174.c"
#include "test_74175.c"
#include "test_74193.c"
#include "test_74244.c"
#include "test_74245.c"
#include "test_74253.c"
#include "test_74257.c"
#include "test_74295.c"
#include "test_74298.c"
#include "test_74374.c"
#include "test_c4520.c"
#include "test_011.c"
#include "test_019.c"
#include "test_082.c"
#include "test_086.c"


const struct chip
{
	uint8_t (*test)();
	uint8_t sym[3];
} chips[] =
{ // not more than 254 IC!!!
	{ test_7400,	{ 0x00, 13, 13 } },
	{ test_7402,	{ 0x02, 13, 13 } },
	{ test_7404,	{ 0x04, 13, 13 } },
	{ test_7406,	{ 0x06, 13, 13 } },
	{ test_7407,	{ 0x07, 13, 13 } },
	{ test_7408,	{ 0x08, 13, 13 } },
	{ test_7410,	{ 0x10, 13, 13 } },
	{ test_7411,	{ 0x11, 13, 13 } },
	{ test_7420,	{ 0x20, 13, 13 } },
	{ test_7427,	{ 0x27, 13, 13 } },
	{ test_7430,	{ 0x30, 13, 13 } },
	{ test_7432,	{ 0x32, 13, 13 } },
	{ test_7438,	{ 0x38, 13, 13 } },
	{ test_7474,	{ 0x74, 13, 13 } },
	{ test_7475,	{ 0x75, 13, 13 } },
	{ test_7486,	{ 0x86, 13, 13 } },
	{ test_7493,	{ 0x93, 13, 13 } },
	{ test_74125,	{ 0x25,  1, 13 } },
	{ test_74138,	{ 0x38,  1, 13 } },
	{ test_74155,	{ 0x55,  1, 13 } },
	{ test_74161,	{ 0x61,  1, 13 } },
	{ test_74166,	{ 0x66,  1, 13 } },
	{ test_74169,	{ 0x69,  1, 13 } },
	{ test_74174,	{ 0x74,  1, 13 } },
	{ test_74175,	{ 0x75,  1, 13 } },
	{ test_74193,	{ 0x93,  1, 13 } },
	{ test_74244,	{ 0x44,  2, 13 } },
	{ test_74245,	{ 0x45,  2, 13 } },
	{ test_74253,	{ 0x53,  2, 13 } },
	{ test_74257,	{ 0x57,  2, 13 } },
	{ test_74295,	{ 0x95,  2, 13 } },
	{ test_74298,	{ 0x98,  2, 13 } },
	{ test_74374,	{ 0x74,  3, 13 } },
	{ test_C4520,	{ 0x20, 17, 13 } }, /* C20 on Display */
	{ test_011,		{ 0x11, 12, 13 } },
	{ test_019,		{ 0x19, 12, 13 } },
	{ test_082,		{ 0x82, 12, 13 } },
	{ test_086,		{ 0x86, 12, 13 } },
};

#define _ICs (sizeof(chips)/sizeof(struct chip))


//uint8_t test2(uint8_t IC)
//{
	/* We have ZIF-24 */
	/* Pins 1-8 on PortC, Pins 23-17 on PortA */
	/* Pins 9,15,16 on PortE, 10,11,15,16 on PortB */
	//uint8_t pinsC = 00000000b;  // 0 - output, 1 - input
	//uint8_t pinsA = 00000000b;  // 0 - output, 1 - input
	//uint8_t pinsBE = 00000000b; // 0 - output, 1 - input
	
//}

/* interrupt for indicator update */
ISR(TIMER0_OVF_vect)
{
	seg++;
	seg &= 0x03;					/* we have only 4 segments */
	PORTB = ~(razr[seg]);			/* select segment on display */
	Display_P = znak[sym[seg]];		/* write to display segment */
}

uint8_t test(uint8_t ic_num)
{
    /* set IC number for indicator */
    sym[3] = chips[ic_num].sym[1];
    sym[2] = (chips[ic_num].sym[0] >> 4) & 0x0F;
	sym[1] = chips[ic_num].sym[0] & 0x0F;
    sym[0] = 12;					/* two horizontal lines as a testing process indicator */
    
    /* start test for selected IC */
	uint8_t res = chips[ic_num].test();
    sym[0] = res == 1 ? 10 : 11;	/* GOOD or BAD symbol */
	
	return res;
}

void menu(uint8_t sel)
{
	if ( sel < _ICs )   // for safety
	{
		sym[0] = chips[sel].sym[0] & 0x0F;
		sym[1] = (chips[sel].sym[0] >> 4) & 0x0F;
		sym[2] = chips[sel].sym[1];
		sym[3] = chips[sel].sym[2];
	}
}

uint8_t search(void)
{
	for (uint8_t i = 0; i < _ICs; i++ )
		if ( test(i) == 1 )
			return i;

	/* not found, print "Err" */
	sym[3] = 14; /* E */
	sym[2] = 18; /* r */
	sym[1] = 18; /* r */
	sym[0] = 13; /* empty */
	return 255;
}

int main(void)
{	
	/* Initialize ports */
	Port_H = 0x00;
	Direct_H = 0x00;

	Port_L = 0x00;
	Direct_L = 0x00;

	PORTB = 0x0F;
	DDRB = 0xF0;
 
	Display_P = 0x00;
	Display_D = 0xFF;

	PORTE = 0x00;
	DDRE = 0x00;

	/* Init timer */
	TCCR0 = 0x03;
	TCNT0 = 0x00;
	OCR0 = 0x00;
	TIMSK = 0x02;

	/* Init indicator */
	seg = 0;
	sym[3] = 16;	/* t */
	sym[2] = 14;	/* E */
	sym[1] = 5;		/* S */
	sym[0] = 16;	/* t */

	uint8_t sel = 0;

	sei();							/* enable interrupts */

	/* keys loop */
	for( ; ; )
    {
		/* Key UP */
        if( key_UP == 0 )
		{
			sel = (sel < _ICs) ? sel + 1 : 0;
            menu(sel);
			delay200ms();
        }
        while( key_UP == 0 );		/* wait for release key */

		/* Key DOWN */
        if( key_DN == 0 )
		{
			sel = ( sel > 0 ) ? sel - 1 : _ICs;
            menu(sel);
			delay200ms();
        }     
        while( key_DN == 0 );		/* wait for release key */

		/* Key SEARCH */
        if( key_SEARCH == 0 )
			sel = search();
        while( key_SEARCH == 0 );	/* wait for release key */
        
		/* Key TEST */
		if( key_TEST == 0 ) 
        {
			if ( sel < _ICs )		/* for safety */
				test(sel);
			delay200ms();  
		}
		while( key_TEST == 0 );		/* wait for release key */
    }
	
	return 0;
}
                        


