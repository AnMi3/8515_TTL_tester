// TEST FOR 74393 (»≈19)
// Dual 4-bit binary ripple counter

/* PINS: n1CP 1MR 1Q0 1Q1 1Q2 1Q3 GND :: 2Q3 2Q2 2Q1 2Q0 2MR n2CP VCC */

case 393:

// left pins
#define P_n1CP	BIT_L0
#define P_1MR	BIT_L1
#define P_1Q0	BIT_L2
#define P_1Q1	BIT_L3
#define P_1Q2	BIT_L4
#define P_1Q3	BIT_L5
#define P_GND	BIT_L6

// right pins
#define P_2Q3	BIT_H6
#define P_2Q2	BIT_H5
#define P_2Q1	BIT_H4
#define P_2Q0	BIT_H3
#define P_2MR	BIT_H2
#define P_n2CP	BIT_H1
#define P_VCC	BIT_H0
        
	Direct_L = P_n1CP | P_1MR | P_GND | BIT_L7;
        Direct_H = BIT_H7 | P_2MR | P_n2CP | P_VCC;

        Port_L = P_1MR | P_1Q0 | P_1Q1 | P_1Q2 | P_1Q3;
        Port_H = P_2Q3 | P_2Q2 | P_2Q1 | P_2Q0 | P_2MR | P_VCC;
        Port_L = P_1Q0 | P_1Q1 | P_1Q2 | P_1Q3;
        Port_H = P_2Q3 | P_2Q2 | P_2Q1 | P_2Q0 | P_VCC;
        delay1ms();       
        res &= ( (Pin_L == 0) && (Pin_H == P_VCC) );

        Port_L = P_n1CP | P_1Q0 | P_1Q1 | P_1Q2 | P_1Q3;
        Port_L = P_1Q0 | P_1Q1 | P_1Q2 | P_1Q3;
        Port_H = P_2Q3 | P_2Q2 | P_2Q1 | P_2Q0 | P_n2CP | P_VCC;
        Port_H = P_2Q3 | P_2Q2 | P_2Q1 | P_2Q0 | P_VCC;
        delay1ms();
        res &= ( (Pin_L == P_1Q0) && (Pin_H == (P_2Q0 | P_VCC)) );

        for( uint8_t n = 0; n < 14; n++ )
	{    
            Port_L = P_n1CP | P_1Q0 | P_1Q1 | P_1Q2 | P_1Q3;
            Port_L = P_1Q0 | P_1Q1 | P_1Q2 | P_1Q3;
            Port_H = P_2Q3 | P_2Q2 | P_2Q1 | P_2Q0 | P_n2CP | P_VCC;
            Port_H = P_2Q3 | P_2Q2 | P_2Q1 | P_2Q0 | P_VCC;
	}
	delay1ms();
        res &= ( (Pin_L == (P_1Q0 | P_1Q1 | P_1Q2 | P_1Q3)) && (Pin_H == (P_2Q3 | P_2Q2 | P_2Q1 | P_2Q0 | P_VCC)) );

        Port_L = 0;
        Port_H = 0;

#undef P_n1CP
#undef P_1MR
#undef P_1Q0
#undef P_1Q1
#undef P_1Q2
#undef P_1Q3
#undef P_GND
#undef P_2Q3
#undef P_2Q2
#undef P_2Q1
#undef P_2Q0
#undef P_2MR
#undef P_n2CP
#undef P_VCC

	break;
