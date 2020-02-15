// TEST FOR 74139 (ÈÄ14)
// Dual 2-to-4 line decoder/demultiplexer

/* PINS: n1E 1A0 1A1 1Y0 1Y1 1Y2 1Y3 GND :: 2Y3 2Y2 2Y1 2Y0 2A1 2A0 n2E VCC */

case 139:

// left pins
#define P_n1E	BIT_L0
#define P_1A0	BIT_L1
#define P_1A1	BIT_L2
#define P_1Y0	BIT_L3
#define P_1Y1	BIT_L4
#define P_1Y2	BIT_L5
#define P_1Y3	BIT_L6
#define P_GND	BIT_L7

// right pins
#define P_2Y3	BIT_H7
#define P_2Y2	BIT_H6
#define P_2Y1	BIT_H5
#define P_2Y0	BIT_H4
#define P_2A1	BIT_H3
#define P_2A0	BIT_H2
#define P_n2E	BIT_H1
#define P_VCC	BIT_H0

	Direct_L = P_n1E | P_1A0 | P_1A1 | P_GND;
	Direct_H = P_n2E | P_2A0 | P_2A1 | P_VCC;

	Port_L = P_n1E;
	Port_H = P_n2E | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_n1E | P_1Y0 | P_1Y1 | P_1Y2 | P_1Y3)) && (Pin_H == (P_n2E | P_2Y0 | P_2Y1 | P_2Y2 | P_2Y3 | P_VCC)) );

	Port_L = 0;
	Port_H = P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_1Y1 | P_1Y2 | P_1Y3)) && (Pin_H == (P_2Y1 | P_2Y2 | P_2Y3 | P_VCC)) );

	Port_L = P_1A0;
	Port_H = P_2A0 | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_1A0 | P_1Y0 | P_1Y2 | P_1Y3)) && (Pin_H == (P_2A0 | P_2Y0 | P_2Y2 | P_2Y3 | P_VCC)) );

	Port_L = P_1A1;
	Port_H = P_2A1 | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_1A1 | P_1Y0 | P_1Y1 | P_1Y3)) && (Pin_H == (P_2A1 | P_2Y0 | P_2Y1 | P_2Y3 | P_VCC)) );

	Port_L = P_1A0 | P_1A1;
	Port_H = P_2A0 | P_2A1 | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_1A0 | P_1A1 | P_1Y0 | P_1Y1 | P_1Y2)) && (Pin_H == (P_2A0 | P_2A1 | P_2Y0 | P_2Y1 | P_2Y2 | P_VCC)) );

	Port_L = 0;
	Port_H = 0;

#undef P_n1E
#undef P_1A0
#undef P_1A1
#undef P_1Y0
#undef P_1Y1
#undef P_1Y2
#undef P_1Y3
#undef P_GND
#undef P_2Y3
#undef P_2Y2
#undef P_2Y1
#undef P_2Y0
#undef P_2A1
#undef P_2A0
#undef P_n2E
#undef P_VCC

	break;
