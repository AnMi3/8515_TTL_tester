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


const struct chip
{
	uint16_t code;
	uint8_t sym[3];
} chips[] =
{ // not more than 254 ICs!!!
	{ 0,	{ 0x00, 13, 13 } },
	{ 2,	{ 0x02, 13, 13 } },
	{ 4,	{ 0x04, 13, 13 } },
	{ 6,	{ 0x06, 13, 13 } },
	{ 7,	{ 0x07, 13, 13 } },
	{ 8,	{ 0x08, 13, 13 } },
	{ 10,	{ 0x10, 13, 13 } },
	{ 11,	{ 0x11, 13, 13 } },
	{ 20,	{ 0x20, 13, 13 } },
	{ 27,	{ 0x27, 13, 13 } },
	{ 30,	{ 0x30, 13, 13 } },
	{ 32,	{ 0x32, 13, 13 } },
	{ 38,	{ 0x38, 13, 13 } },
	{ 74,	{ 0x74, 13, 13 } },
	{ 75,	{ 0x75, 13, 13 } },
	{ 86,	{ 0x86, 13, 13 } },
	{ 93,	{ 0x93, 13, 13 } },
	{ 125,	{ 0x25,  1, 13 } },
	{ 138,	{ 0x38,  1, 13 } },
	{ 139,	{ 0x39,  1, 13 } },
	{ 155,	{ 0x55,  1, 13 } },
	{ 161,	{ 0x61,  1, 13 } },
	{ 166,	{ 0x66,  1, 13 } },
	{ 169,	{ 0x69,  1, 13 } },
	{ 174,	{ 0x74,  1, 13 } },
	{ 175,	{ 0x75,  1, 13 } },
	{ 193,	{ 0x93,  1, 13 } },
	{ 244,	{ 0x44,  2, 13 } },
	{ 245,	{ 0x45,  2, 13 } },
	{ 253,	{ 0x53,  2, 13 } },
	{ 257,	{ 0x57,  2, 13 } },
	{ 258,	{ 0x58,  2, 13 } },
	{ 295,	{ 0x95,  2, 13 } },
	{ 298,	{ 0x98,  2, 13 } },
	{ 367,	{ 0x67,  3, 13 } },
	{ 368,	{ 0x68,  3, 13 } },
	{ 374,	{ 0x74,  3, 13 } },
	{ 393,	{ 0x93,  3, 13 } },
	{ 4520,	{ 0x20, 17, 13 } }, /* C20 on Display */
	{ 8282,	{ 0x82, 14, 13 } }, /* E82 on Display */
	{ 8286,	{ 0x86, 14, 13 } }, /* E86 on Display */
};

#define _ICs (sizeof(chips)/sizeof(struct chip))

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
	uint8_t res = 0;
	switch(chips[ic_num].code)
	{
#include "test\\74_00.c"
#include "test\\74_02.c"
#include "test\\74_04.c"
#include "test\\74_06.c"
#include "test\\74_07.c"
#include "test\\74_08.c"
#include "test\\74_10.c"
#include "test\\74_11.c"
#include "test\\74_20.c"
#include "test\\74_27.c"
#include "test\\74_30.c"
#include "test\\74_32.c"
#include "test\\74_38.c"
#include "test\\74_74.c"
#include "test\\74_75.c"
#include "test\\74_86.c"
#include "test\\74_93.c"
#include "test\\74125.c"
#include "test\\74138.c"
#include "test\\74139.c"
#include "test\\74155.c"
#include "test\\74161.c"
#include "test\\74166.c"
#include "test\\74169.c"
#include "test\\74174.c"
#include "test\\74175.c"
#include "test\\74193.c"
#include "test\\74244.c"
#include "test\\74245.c"
#include "test\\74253.c"
#include "test\\74257.c"
#include "test\\74258.c"
#include "test\\74295.c"
#include "test\\74298.c"
#include "test\\74367.c"
#include "test\\74368.c"
#include "test\\74374.c"
#include "test\\74393.c"
#include "test\\C4520.c"
#include "test\\8282.c"
#include "test\\8286.c"
	}
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

	Port_E = 0x00;
	Direct_E = 0x00;

	PORTB = 0x0F;
	DDRB = 0xF0;
 
	Display_P = 0x00;
	Display_D = 0xFF;

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
                        


