// TEST FOR 74374 (ÈÐ23)
// Octal 3-State Non-Inverting D Flip-Flop

/* PINS: nOE Q1 D1 D2 Q2 Q3 D3 D4 Q4 GND :: CLK Q5 D5 D6 Q6 Q7 D7 D8 Q8 VCC */

case 374:
	res = 1;

// left pins
#define P_nOE	BIT_L0
#define P_Q1	BIT_L1
#define P_D1	BIT_L2
#define P_D2	BIT_L3
#define P_Q2	BIT_L4
#define P_Q3	BIT_L5
#define P_D3	BIT_L6
#define P_D4	BIT_L7
#define P_Q4	BIT_L8
#define P_GND	BIT_L9	// this pin connected to GND

// right pins
#define P_CLK	BIT_H9
#define P_Q5	BIT_H8
#define P_D5	BIT_H7
#define P_D6	BIT_H6
#define P_Q6	BIT_H5
#define P_Q7	BIT_H4
#define P_D7	BIT_H3
#define P_D8	BIT_H2
#define P_Q8	BIT_H1
#define P_VCC	BIT_H0

        Direct_L = P_nOE | P_D1 | P_D2 | P_D3 | P_D4;
        Direct_H = P_D5 | P_D6 | P_D7 | P_D8 | P_VCC;
        Direct_E = P_CLK;

        Port_L = P_D1 | P_D3;
        Port_H = P_D6 | P_D8 | P_VCC;
        Port_E = P_CLK;
        Port_E = 0;
        Port_L = 0;
        Port_H = P_VCC;
        res &= ( (Pin_L == (P_Q1 | P_Q3)) && (Pin_H == (P_Q6 | P_Q8 | P_VCC)) );

        Port_L = P_D2 | P_D4;
        Port_H = P_D5 | P_D7 | P_VCC;
        Port_E = P_CLK;
        Port_E = 0;
        Port_L = 0;
        Port_H = P_VCC;
        res &= ( (Pin_L == P_Q2) && (Pin_H == (P_Q7 | P_VCC)) && (Pin_E == (P_Q4 | P_Q5)) );

        Port_L = 0;
        Port_H = 0;
        Port_E = 0;

#undef P_nOE
#undef P_Q1
#undef P_D1
#undef P_D2
#undef P_Q2
#undef P_Q3
#undef P_D3
#undef P_D4
#undef P_Q4
#undef P_GND
#undef P_CLK
#undef P_Q5
#undef P_D5
#undef P_D6
#undef P_Q6
#undef P_Q7
#undef P_D7
#undef P_D8
#undef P_Q8
#undef P_VCC

	break;
