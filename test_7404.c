void test_7404(void)
    {   
        sym[1]=4;
        sym[2]=0;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=213;
        Direct_H=171;
        Port_L=42;
        Port_H=85;
        delay_ms(1);
        if ((Pin_L==42) && (Pin_H==85)) res=1;
            else res=0;
        Port_L=63;
        Port_H=127;
        if ((Pin_L==21) && (Pin_H==43) && (res==1)) res=1;
            else res=0;
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    } 