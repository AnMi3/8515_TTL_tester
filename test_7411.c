void test_7411(void)
    {   
        sym[1]=1;
        sym[2]=1;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=223;
        Direct_H=187;
        Port_L=32;
        Port_H=69;
        delay_ms(1);
        if ((Pin_L==0) && (Pin_H==1)) res=1;
            else res=0;
        Port_L=37;
        Port_H=77;
        if ((Pin_L==5) && (Pin_H==9) && (res==1)) res=1;
            else res=0; 
        Port_L=47;
        Port_H=93;
        if ((Pin_L==15) && (Pin_H==25) && (res==1)) res=1;
            else res=0;
        Port_L=63;
        Port_H=127;
        if ((Pin_L==63) && (Pin_H==127) && (res==1)) res=1;
            else res=0;       
        if (res==1) sym[0]=10;
            else sym[0]=11;
        Port_L=0;
        Port_H=0;                                        
    }