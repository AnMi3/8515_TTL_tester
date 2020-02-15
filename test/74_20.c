// TEST FOR 7420 (��1)
// Dual 4-Input Positive-NAND Gates

/* PINS: 1A 1B NC 1C 1D n1Y GND :: n2Y 2A 2B NC 2C 2D VCC */

case 20:

// left pins
#define P_1A	BIT_L0
#define P_1B	BIT_L1
#define P_NC1	BIT_L2
#define P_1C	BIT_L3
#define P_1D	BIT_L4
#define P_n1Y	BIT_L5
#define P_GND	BIT_L6

// right pins
#define P_n2Y	BIT_H6
#define P_2A	BIT_H5
#define P_2B	BIT_H4
#define P_NC2	BIT_H3
#define P_2C	BIT_H2
#define P_2D	BIT_H1
#define P_VCC	BIT_H0

	Direct_L = P_1A | P_1B | P_NC1 | P_1C | P_1D | P_GND | BIT_L7;
	Direct_H = BIT_H7 | P_2A | P_2B | P_NC2 | P_2C | P_2D | P_VCC;

	Port_L = P_n1Y;
	Port_H = P_n2Y | P_VCC;
	delay1ms();
	res &= ( (Pin_L == P_n1Y) && (Pin_H == (P_n2Y | P_VCC)) );

	Port_L = P_1A | P_n1Y;
	Port_H = P_n2Y | P_2D | P_VCC;
	res &= ( (Pin_L == (P_1A | P_n1Y)) && (Pin_H == (P_n2Y | P_2D | P_VCC)) );

	Port_L = P_1A | P_1B | P_n1Y;
	Port_H = P_n2Y | P_2C | P_2D | P_VCC;
	res &= ( (Pin_L == (P_1A | P_1B | P_n1Y)) && (Pin_H == (P_n2Y | P_2C | P_2D | P_VCC)) );

	Port_L = P_1A | P_1B | P_1C | P_n1Y;
	Port_H = P_n2Y | P_2B | P_2C | P_2D | P_VCC;
	res &= ( (Pin_L == (P_1A | P_1B | P_1C | P_n1Y)) && (Pin_H == (P_n2Y | P_2B | P_2C | P_2D | P_VCC)) );

	Port_L = P_1A | P_1B | P_1C | P_1D | P_n1Y;
	Port_H = P_n2Y | P_2A | P_2B | P_2C | P_2D | P_VCC;
	res &= ( (Pin_L == (P_1A | P_1B | P_1C | P_1D)) && (Pin_H == (P_2A | P_2B | P_2C | P_2D | P_VCC)) );

	Port_L = 0;
	Port_H = 0;

#undef P_1A
#undef P_1B
#undef P_NC1
#undef P_1C
#undef P_1D
#undef P_n1Y
#undef P_GND
#undef P_n2Y
#undef P_2A
#undef P_2B
#undef P_NC2
#undef P_2C
#undef P_2D
#undef P_VCC

	break;
