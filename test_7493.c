void test_7493(void)
    {   
        sym[1]=3;
        sym[2]=9;
        sym[3]=13;
        res=0;
        sym[0]=12;
        Direct_L=255;
        Direct_H=147;
        Port_H=0;        
        Port_L=22;
        Port_L=16;
        delay_ms(1);
        if (Pin_H==0) res=1;
            else res=0;
        Port_H=1;
        Port_H=0;
        delay_ms(1);       
        if ((Pin_H==4) && (res==1)) res=1;
            else res=0;
        Port_L=17;
        Port_L=16;
        delay_ms(1);       
        if ((Pin_H==36) && (res==1)) res=1;
            else res=0;
        Port_L=17;
        Port_L=16;
        delay_ms(1);
        if ((Pin_H==68) && (res==1)) res=1;
            else res=0;
        Port_L=17;
        Port_L=16;
        Port_L=17;
        Port_L=16;
        delay_ms(1);    
        if ((Pin_H==12) && (res==1)) res=1;
            else res=0;
        Port_L=22;
        Port_L=16;
        delay_ms(1);
        if ((Pin_H==0) && (res==1)) res=1;
            else res=0;               
        if (res==1) sym[0]=10;
            else sym[0]=11;  
        Port_L=0;
        Port_H=0;                                        
    }