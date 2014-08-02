#define  SW1  RB4_bit
#define  SW2  RB5_bit
#define  SW3  RB6_bit
#define  SW4  RB7_bit

#define  RELAY1   RB0_bit
#define  RELAY2   RB1_bit
#define  RELAY3   RB2_bit
#define  RELAY4   RB3_bit

void main()
{
    TRISB4_bit=1;
    TRISB5_bit=1;
    TRISB6_bit=1;
    TRISB7_bit=1;

    TRISB0_bit=0;
    TRISB1_bit=0;
    TRISB2_bit=0;
    TRISB3_bit=0;
    
    RELAY1=0;
    RELAY2=0;
    RELAY3=0;
    RELAY4=0;

    while(1)
    {
        if(SW1==0)RELAY1=1;  //on Relay1 if SW1 pressed
        else RELAY1=0;       //off Relay1 if SW1 released

        if(SW2==0)RELAY2=1;  //on Relay2 if SW2 pressed
        else RELAY2=0;       //off Relay2 if SW2 released

        if(SW3==0)RELAY3=1;  //on Relay3 if SW3 pressed
        else RELAY3=0;       //off Relay3 if SW3 released

        if(SW4==0)RELAY4=1;  //on Relay4 if SW4 pressed
        else RELAY4=0;       //off Relay4 if SW4 released
    }
}
