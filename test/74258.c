// TEST FOR 74258 ( œ14)
// 8-to-4 line 3-state inverting data selector/multiplexer

/* PINS: S A1 B1 Y1 A2 B2 Y2 GND :: Y3 B3 A3 Y4 B4 A4 nEN VCC */

case 258:

// left pins
#define P_S	BIT_L0
#define P_A1	BIT_L1
#define P_B1	BIT_L2
#define P_Y1	BIT_L3
#define P_A2	BIT_L4
#define P_B2	BIT_L5
#define P_Y2	BIT_L6
#define P_GND	BIT_L7

// right pins
#define P_Y3	BIT_H7
#define P_B3	BIT_H6
#define P_A3	BIT_H5
#define P_Y4	BIT_H4
#define P_B4	BIT_H3
#define P_A4	BIT_H2
#define P_nEN	BIT_H1
#define P_VCC	BIT_H0

	/* Set pins S, A1, B1, A2, B2, GND, B3, A3, B4, A4, nEN, VCC to output, other pins to input */
	Direct_L = P_S | P_A1 | P_B1 | P_A2 | P_B2 | P_GND;
	Direct_H = P_B3 | P_A3 | P_B4 | P_A4 | P_nEN | P_VCC;

	/* set Pull-up on Y inputs and set HIGH to VCC pin */
	Port_L = P_Y1 | P_Y2;
	Port_H = P_Y3 | P_Y4 | P_VCC;
	delay1ms();
	/* At first it should be Y and VCC at High state */
	res &= ( (Pin_L == (P_Y1 | P_Y2)) && (Pin_H == (P_Y3 | P_Y4 | P_VCC)) );

	/* set A High, B Low, nEN Low, S Low, Pull-up on Y and High to VCC */
	Port_L = P_A1 | P_A2 | P_Y1 | P_Y2;
	Port_H = P_A3 | P_A4 | P_Y3 | P_Y4 | P_VCC;
	delay1ms();
	/* A and VCC should be High (according to Truth table). nEn, S and B should be Low */
	res &= ( (Pin_L == (P_A1 | P_A2)) && (Pin_H == (P_A3 | P_A4 | P_VCC)) );


	/* set A High, B Low, nEN Low, S High, Pull-up on Y and High to VCC */
	Port_L = P_S | P_A1 | P_A2 | P_Y1 | P_Y2;
	delay1ms();
	/* S, A, Y and VCC should be High. nEn and B should be Low */
	res &= ( (Pin_L == (P_S | P_A1 | P_A2 | P_Y1 | P_Y2)) && (Pin_H == (P_A3 | P_A4 | P_Y3 | P_Y4 | P_VCC)) );

	/* set A Low, B High, nEN Low, S High, Pull-up on Y and High to VCC */
	Port_L = P_S | P_B1 | P_B2 | P_Y1 | P_Y2;
	Port_H = P_Y3 | P_B3 | P_B4 | P_Y4 | P_VCC;
	delay1ms();
	/* S, B and VCC should be High */
	res &= ( (Pin_L == (P_S | P_B1 | P_B2)) && (Pin_H == (P_B3 | P_B4 | P_VCC)) );

	// set ports to Low
	Port_L = 0;
	Port_H = 0;

#undef P_S
#undef P_A1
#undef P_B1
#undef P_Y1
#undef P_A2
#undef P_B2
#undef P_Y2
#undef P_GND
#undef P_Y3
#undef P_B3
#undef P_A3
#undef P_Y4
#undef P_B4
#undef P_A4
#undef P_nEN
#undef P_VCC

	break;
