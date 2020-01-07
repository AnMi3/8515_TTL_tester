// TEST FOR 74368 (หอ8)
// Hex 3-State buffer/line driver

/* PINS: n1OE 1A n1Y 2A n2Y 3A n3Y GND :: n4Y 4A n5Y 5A n6Y 6A n2OE VCC */

case 368:
	res = 1;

// left pins
#define P_n1OE	BIT_L0
#define P_1A	BIT_L1
#define P_n1Y	BIT_L2
#define P_2A	BIT_L3
#define P_n2Y	BIT_L4
#define P_3A	BIT_L5
#define P_n3Y	BIT_L6
#define P_GND	BIT_L7

// right pins
#define P_n4Y	BIT_H7
#define P_4A	BIT_H6
#define P_n5Y	BIT_H5
#define P_5A	BIT_H4
#define P_n6Y	BIT_H3
#define P_6A	BIT_H2
#define P_n2OE	BIT_H1
#define P_VCC	BIT_H0

        Direct_L = P_n1OE | P_1A | P_2A | P_3A | P_GND;
        Direct_H = P_4A | P_5A | P_6A | P_n2OE | P_VCC;
        Port_L = P_n1Y | P_n2Y | P_n3Y;
        Port_H = P_n4Y | P_n5Y | P_n6Y | P_VCC;
        delay1ms();
        res &= ( (Pin_L == (P_n1Y | P_n2Y | P_n3Y)) && (Pin_H == (P_n4Y | P_n5Y | P_n6Y | P_VCC)) );

        Port_L = P_1A | P_2A | P_3A | P_n1Y | P_n2Y | P_n3Y;
        Port_H = P_4A | P_5A | P_6A | P_n4Y | P_n5Y | P_n6Y | P_VCC;
        delay1ms();
        res &= ( (Pin_L == (P_1A | P_2A | P_3A)) && (Pin_H == (P_4A | P_5A | P_6A | P_VCC)) );

        Port_L = P_1A | P_3A | P_n1Y | P_n2Y | P_n3Y;
        Port_H = P_5A | P_n4Y | P_n5Y | P_n6Y | P_VCC;
        delay1ms();
        res &= ( (Pin_L == (P_1A | P_3A | P_n2Y)) && (Pin_H == (P_5A | P_n4Y | P_n6Y | P_VCC)) );

        Port_L = P_2A | P_n1Y | P_n2Y | P_n3Y;
        Port_H = P_4A | P_6A | P_n4Y | P_n5Y | P_n6Y | P_VCC;
        delay1ms();
        res &= ( (Pin_L == (P_2A | P_n1Y | P_n3Y)) && (Pin_H == (P_4A | P_6A | P_n5Y | P_VCC)) );

        Port_L = 0;
        Port_H = 0;

#undef P_n1OE
#undef P_1A
#undef P_n1Y
#undef P_2A
#undef P_n2Y
#undef P_3A
#undef P_n3Y
#undef P_GND
#undef P_n4Y
#undef P_4A
#undef P_n5Y
#undef P_5A
#undef P_n6Y
#undef P_6A
#undef P_n2OE
#undef P_VCC

	break;
