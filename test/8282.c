// TEST FOR Intel 8282 (580ÈÐ82)
// 8-bit latch

/* PINS: D0 D1 D2 D3 D4 D5 D6 D7 nOE GND :: STB Q7 Q6 Q5 Q4 Q3 Q2 Q1 Q0 VCC */

case 8282:

/*
	Truth table
	STB	nOE	D	Q
	----------------------------------
	X	H	X	Z
	H	L	L	L
	H	L	H	H
	L	L	X	Latched D
*/

// left pins
#define P_D0	BIT_L0
#define P_D1	BIT_L1
#define P_D2	BIT_L2
#define P_D3	BIT_L3
#define P_D4	BIT_L4
#define P_D5	BIT_L5
#define P_D6	BIT_L6
#define P_D7	BIT_L7
#define P_nOE	BIT_L8
#define P_GND	BIT_L9	// this pin connected to GND

// right pins
#define P_STB	BIT_H9
#define P_Q7	BIT_H8
#define P_Q6	BIT_H7
#define P_Q5	BIT_H6
#define P_Q4	BIT_H5
#define P_Q3	BIT_H4
#define P_Q2	BIT_H3
#define P_Q1	BIT_H2
#define P_Q0	BIT_H1
#define P_VCC	BIT_H0
		
	Direct_L = P_D0 | P_D1 | P_D2 | P_D3 | P_D4 | P_D5 | P_D6 | P_D7;
	Direct_H = P_VCC;
	Direct_H = P_nOE | P_STB;

	Port_E = P_STB;
	Port_L = P_D0 | P_D2 | P_D4 | P_D6;
	Port_H = P_Q6 | P_Q5 | P_Q4 | P_Q3 | P_Q2 | P_Q1 | P_Q0 | P_VCC;
	delay1ms();       
	res &= ( (Pin_L == (P_D0 | P_D2 | P_D4 | P_D6)) && (Pin_H == (P_Q6 | P_Q4 | P_Q2 | P_Q0 | P_VCC)) && (Pin_E == P_STB) );

	Port_L = P_D1 | P_D3 | P_D5 | P_D7;
	delay1ms();
	res &= ( (Pin_L == (P_D1 | P_D3 | P_D5 | P_D7)) && (Pin_H == (P_Q5 | P_Q3 | P_Q1 | P_VCC)) && (Pin_E == (P_STB | P_Q7)) );

	Port_E = 0;
	Port_L = 0;
	delay1ms();
	res &= ( (Pin_L == 0) && (Pin_H == (P_Q5 | P_Q3 | P_Q1 | P_VCC)) && (Pin_E == P_Q7) );

	Port_L = 0;
	Port_H = 0;
	Port_E = 0;

#undef P_D0
#undef P_D1
#undef P_D2
#undef P_D3
#undef P_D4
#undef P_D5
#undef P_D6
#undef P_D7
#undef P_nOE
#undef P_GND
#undef P_STB
#undef P_Q7
#undef P_Q6
#undef P_Q5
#undef P_Q4
#undef P_Q3
#undef P_Q2
#undef P_Q1
#undef P_Q0
#undef P_VCC

	break;