uint8_t test_086(void)
{
		uint8_t res = 1;
		
        Direct_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6 | BIT_L7);
        Direct_H=(BIT_H0);
        DDRE=3;
        PORTE=2;
        Port_L=(BIT_L0 | BIT_L2 | BIT_L4 | BIT_L6);
        Port_H=(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0);
        delay1ms();       
        res &= ((Pin_L==(BIT_L0 | BIT_L2 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H1 | BIT_H0)) && (PINE==2));

        Port_L=(BIT_L1 | BIT_L3 | BIT_L5 | BIT_L7);
        delay1ms();
        res &= ((Pin_L==(BIT_L1 | BIT_L3 | BIT_L5 | BIT_L7)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0)) && (PINE==6));

        Direct_L=0;
        Direct_H=(BIT_H7 | BIT_H6 | BIT_H5 | BIT_H4 | BIT_H3 | BIT_H2 | BIT_H1 | BIT_H0);
        DDRE=7;
        PORTE=0;
        Port_L=(BIT_L0 | BIT_L1 | BIT_L2 | BIT_L3 | BIT_L4 | BIT_L5 | BIT_L6 | BIT_L7);
        Port_H=(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H1 | BIT_H0);
        delay1ms();       
        res &= ((Pin_L==(BIT_L0 | BIT_L2 | BIT_L4 | BIT_L6)) && (Pin_H==(BIT_H7 | BIT_H5 | BIT_H3 | BIT_H1 | BIT_H0)) && (PINE==0));

        Port_H=(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0);
        PORTE=4;
        delay1ms();
        res &= ((Pin_L==(BIT_L1 | BIT_L3 | BIT_L5 | BIT_L7)) && (Pin_H==(BIT_H6 | BIT_H4 | BIT_H2 | BIT_H0)) && (PINE==4));

        Port_L=0;
        Port_H=0;
        PORTE=0;            
		
		return res;
    }