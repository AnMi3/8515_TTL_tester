// TEST FOR 74HC4520 (561»≈10)
// Dual 4-bit synchronous binary counter

/* PINS: 1CP0 n1CP1 1Q0 1Q1 1Q2 1Q3 1MR GND :: 2CP0 n2CP1 2Q0 2Q1 2Q2 2Q3 2MR VCC */

case 4520:

// left pins
#define P_1CP0	BIT_L0
#define P_n1CP1	BIT_L1
#define P_1Q0	BIT_L2
#define P_1Q1	BIT_L3
#define P_1Q2	BIT_L4
#define P_1Q3	BIT_L5
#define P_1MR	BIT_L6
#define P_GND	BIT_L7

// right pins
#define P_2CP0	BIT_H7
#define P_n2CP1	BIT_H6
#define P_2Q0	BIT_H5
#define P_2Q1	BIT_H4
#define P_2Q2	BIT_H3
#define P_2Q3	BIT_H2
#define P_2MR	BIT_H1
#define P_VCC	BIT_H0

	Direct_L = P_1CP0 | P_n1CP1 | P_1MR | P_GND;
	Direct_H = P_2CP0 | P_n2CP1 | P_2MR | P_VCC;
	Port_L = P_1MR;
	Port_H = P_2MR | P_VCC;
	Port_L = 0;
	Port_H = P_VCC;
	delay1ms();
	res &= ( (Pin_L == 0) && (Pin_H == P_VCC) );

	Port_L = P_n1CP1;
	Port_H = P_n2CP1 | P_VCC;
	Port_L = P_1CP0 | P_n1CP1;
	Port_H = P_2CP0 | P_n2CP1 | P_VCC;
	Port_L = P_n1CP1;
	Port_H = P_n2CP1 | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_n1CP1 | P_1Q0)) && (Pin_H == (P_n2CP1 | P_2Q0 | P_VCC)) );

	Port_L = P_n1CP1;
	Port_H = P_n2CP1 | P_VCC;
	Port_L = P_1CP0 | P_n1CP1;
	Port_H = P_2CP0 | P_n2CP1 | P_VCC;
	Port_L = P_n1CP1;
	Port_H = P_n2CP1 | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_n1CP1 | P_1Q1)) && (Pin_H == (P_n2CP1 | P_2Q1 | P_VCC)) );

	for( uint8_t i = 0; i < 10; i++ )
	{
		Port_L = P_n1CP1;
		Port_H = P_n2CP1 | P_VCC;
		Port_L = 0;
		Port_H = P_VCC;
	}
	delay1ms();
	res &= ( (Pin_L == (P_1Q2 | P_1Q3)) && (Pin_H == (P_2Q2 | P_2Q3 | P_VCC)) );

	Port_L = 0;
	Port_H = 0;

#undef P_1CP0
#undef P_n1CP1
#undef P_1Q0
#undef P_1Q1
#undef P_1Q2
#undef P_1Q3
#undef P_1MR
#undef P_GND
#undef P_2CP0
#undef P_n2CP1
#undef P_2Q0
#undef P_2Q1
#undef P_2Q2
#undef P_2Q3
#undef P_2MR
#undef P_VCC

	break;
