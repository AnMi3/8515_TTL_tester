// TEST FOR 74298 (��13)
// 8-to-4 line noninverting data selector/multiplexer with output registers

/* PINS: 2A1 2A0 1A0 1A1 3A1 4A1 4A0 GND :: 3A0 S CLK 4Q 3Q 2Q 1Q VCC */

case 298:
	res = 1;

// left pins
#define P_2A1	BIT_L0
#define P_2A0	BIT_L1
#define P_1A0	BIT_L2
#define P_1A1	BIT_L3
#define P_3A1	BIT_L4
#define P_4A1	BIT_L5
#define P_4A0	BIT_L6
#define P_GND	BIT_L7

// right pins
#define P_3A0	BIT_H7
#define P_S	BIT_H6
#define P_CLK	BIT_H5
#define P_4Q	BIT_H4
#define P_3Q	BIT_H3
#define P_2Q	BIT_H2
#define P_1Q	BIT_H1
#define P_VCC	BIT_H0

	Direct_L = P_2A1 | P_2A0 | P_1A0 | P_1A1 | P_3A1 | P_4A1 | P_4A0 | P_GND;
	Direct_H = P_3A0 | P_S | P_CLK | P_VCC;

	Port_L = P_2A1 | P_1A0 | P_4A1;
	Port_H = P_3A0 | P_VCC;
	Port_H = P_3A0 | P_CLK | P_VCC;
	Port_H = P_3A0 | P_VCC;
	delay1ms();
	res &= ( Pin_H == (P_3A0 | P_3Q | P_1Q | P_VCC) );

	Port_H = P_3A0 | P_S | P_VCC;
	Port_H = P_3A0 | P_S | P_CLK | P_VCC;
	Port_H = P_3A0 | P_S | P_VCC;
	delay1ms();
	res &= ( Pin_H == (P_3A0 | P_S | P_4Q | P_2Q | P_VCC) );

	Port_L = P_2A0 | P_1A1 | P_3A1 | P_4A0;
	Port_H = P_VCC;
	Port_H = P_CLK | P_VCC;
	Port_H = P_VCC;
	delay1ms();
	res &= ( Pin_H == (P_4Q | P_2Q | P_VCC) );

	Port_H = P_S | P_VCC;
	Port_H = P_S | P_CLK | P_VCC;
	Port_H = P_S | P_VCC;
	delay1ms();
	res &= ( Pin_H == (P_S | P_3Q | P_1Q | P_VCC) );

	Port_L = 0;
	Port_H = 0;

#undef P_2A1
#undef P_2A0
#undef P_1A0
#undef P_1A1
#undef P_3A1
#undef P_4A1
#undef P_4A0
#undef P_GND
#undef P_3A0
#undef P_S
#undef P_CLK
#undef P_4Q
#undef P_3Q
#undef P_2Q
#undef P_1Q
#undef P_VCC

	break;
