// TEST FOR Intel 8286 (580ÂÀ86)
// Octal Bus Transceiver

/* PINS: A0 A1 A2 A3 A4 A5 A6 A7 nOE GND :: T B7 B6 B5 B4 B3 B2 B1 B0 VCC */

case 8286:

// left pins
#define P_A0	BIT_L0
#define P_A1	BIT_L1
#define P_A2	BIT_L2
#define P_A3	BIT_L3
#define P_A4	BIT_L4
#define P_A5	BIT_L5
#define P_A6	BIT_L6
#define P_A7	BIT_L7
#define P_nOE	BIT_L8
#define P_GND	BIT_L9	// this pin connected to GND

// right pins
#define P_T	BIT_H9
#define P_B7	BIT_H8
#define P_B6	BIT_H7
#define P_B5	BIT_H6
#define P_B4	BIT_H5
#define P_B3	BIT_H4
#define P_B2	BIT_H3
#define P_B1	BIT_H2
#define P_B0	BIT_H1
#define P_VCC	BIT_H0

	Direct_L = P_A0 | P_A1 | P_A2 | P_A3 | P_A4 | P_A5 | P_A6 | P_A7;
	Direct_H = P_VCC;
	Direct_E = P_B7 | P_nOE;

	Port_E = P_T;
	Port_L = P_A0 | P_A2 | P_A4 | P_A6;
	Port_H = P_B6 | P_B5 | P_B4 | P_B3 | P_B2 | P_B1 | P_B0 | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_A0 | P_A2 | P_A4 | P_A6)) && (Pin_H == (P_B6 | P_B4 | P_B2 | P_B0 | P_VCC)) && (Pin_E == P_T) );

	Port_L = P_A1 | P_A3 | P_A5 | P_A7;
	delay1ms();
	res &= ( (Pin_L == (P_A1 | P_A3 | P_A5 | P_A7)) && (Pin_H == (P_B5 | P_B3 | P_B1 | P_VCC)) && (Pin_E == (P_T | P_B7)) );

	Direct_L = 0;
	Direct_H = P_B6 | P_B5 | P_B4 | P_B3 | P_B2 | P_B1 | P_B0 | P_VCC;
	Direct_E = P_B7 | P_T | P_nOE;

	Port_E = 0;
	Port_L = P_A0 | P_A1 | P_A2 | P_A3 | P_A4 | P_A5 | P_A6 | P_A7;
	Port_H = P_B6 | P_B4 | P_B2 | P_B0 | P_VCC;
	delay1ms();
	res &= ( (Pin_L == (P_A0 | P_A2 | P_A4 | P_A6)) && (Pin_H == (P_B6 | P_B4 | P_B2 | P_B0 | P_VCC)) && (Pin_E == 0) );

	Port_H = P_B5 | P_B3 | P_B1 | P_VCC;
	Port_E = P_B7;
	delay1ms();
	res &= ( (Pin_L == (P_A1 | P_A3 | P_A5 | P_A7)) && (Pin_H == (P_B5 | P_B3 | P_B1 | P_VCC)) && (Pin_E == P_B7) );

	Port_L = 0;
	Port_H = 0;
	Port_E = 0;

#undef P_A0
#undef P_A1
#undef P_A2
#undef P_A3
#undef P_A4
#undef P_A5
#undef P_A6
#undef P_A7
#undef P_nOE
#undef P_GND
#undef P_T
#undef P_B7
#undef P_B6
#undef P_B5
#undef P_B4
#undef P_B3
#undef P_B2
#undef P_B1
#undef P_B0
#undef P_VCC

	break;
