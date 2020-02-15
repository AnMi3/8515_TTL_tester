// TEST FOR 74295 (ÈÐ16)
// 4-Bit Right-Shift Left-Shift Registers With 3-State

/* PINS: D P0 P1 P2 P3 LD_nSH GND :: OE nCLK Y3 Y2 Y1 Y0 VCC */

case 295:

// left pins
#define P_D	BIT_L0
#define P_P0	BIT_L1
#define P_P1	BIT_L2
#define P_P2	BIT_L3
#define P_P3	BIT_L4
#define P_LD_nSH	BIT_L5
#define P_GND	BIT_L6

// right pins
#define P_OE	BIT_H6
#define P_nCLK	BIT_H5
#define P_Y3	BIT_H4
#define P_Y2	BIT_H3
#define P_Y1	BIT_H2
#define P_Y0	BIT_H1
#define P_VCC	BIT_H0

	Direct_L = P_D | P_P0 | P_P1 | P_P2 | P_P3 | P_LD_nSH | P_GND | BIT_L7;
	Direct_H = BIT_H7 | P_OE | P_nCLK | P_VCC;

	Port_L = P_LD_nSH;
	Port_H = P_OE | P_nCLK | P_VCC;
	Port_H = P_OE | P_VCC;
	Port_H = P_OE | P_nCLK | P_VCC;
	Port_L = 0;
	delay1ms();
	res &= ( (Pin_L == 0) && (Pin_H == (P_OE | P_nCLK | P_VCC)) );

	Port_L = P_D;
	Port_H = P_OE | P_VCC;
	Port_H = P_OE | P_nCLK | P_VCC;
	res &= ( (Pin_L == P_D) && (Pin_H == (P_OE | P_nCLK | P_Y0 | P_VCC)) );

	Port_H = P_OE | P_VCC;
	Port_H = P_OE | P_nCLK | P_VCC;
	Port_H = P_OE | P_VCC;
	Port_H = P_OE | P_nCLK | P_VCC;
	Port_H = P_OE | P_VCC;
	Port_H = P_OE | P_nCLK | P_VCC;
	res &= ( (Pin_L == P_D) && (Pin_H == (P_OE | P_nCLK | P_Y3 | P_Y2 | P_Y1 | P_Y0 | P_VCC)) );

	Port_L = P_LD_nSH;
	Port_H = P_OE | P_VCC;
	Port_H = P_OE | P_nCLK | P_VCC;
	Port_L = 0;
	delay1ms();
	res &= ( (Pin_L == 0) && (Pin_H == (P_OE | P_nCLK | P_VCC)) );

	Port_L = 0;
	Port_H = 0;

#undef P_D
#undef P_P0
#undef P_P1
#undef P_P2
#undef P_P3
#undef P_LD_nSH
#undef P_GND
#undef P_OE
#undef P_nCLK
#undef P_Y3
#undef P_Y2
#undef P_Y1
#undef P_Y0
#undef P_VCC

	break;
