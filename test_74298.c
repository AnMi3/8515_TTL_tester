void test_74298(void)
    {
        sym[1]=8;
        sym[2]=9;
        sym[3]=2;
        res=0;
        sym[0]=12;
        Direct_L=255;
        Direct_H=225;
        Port_L=37;
        Port_H=129;
        Port_H=161;
        Port_H=129;
        delay_ms(1);
        if (Pin_H==139) res=1;
            else res=0;
        Port_H=193;
        Port_H=225;
        Port_H=193;
        delay_ms(1);
        if ((Pin_H==213) && (res==1)) res=1;
            else res=0;           
        Port_L=90;
        Port_H=1;
        Port_H=33;
        Port_H=1;
        delay_ms(1);
        if ((Pin_H==21) && (res==1)) res=1;
            else res=0;
        Port_H=65;
        Port_H=97;
        Port_H=65;
        delay_ms(1);
        if ((Pin_H==75) && (res==1)) res=1;
            else res=0;                  
        if (res==1) sym[0]=10;
            else sym[0]=11; 
        Port_L=0;
        Port_H=0;            
    }