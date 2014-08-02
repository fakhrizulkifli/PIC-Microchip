#define LED1  RB0_bit
#define LED2  RB1_bit
#define LED3  RB2_bit
#define LED4  RB3_bit
#define LED5  RB4_bit
#define LED6  RB5_bit
#define LED7  RB6_bit
#define LED8  RB7_bit

#define PE1   RD0_bit
#define PE2   RD1_bit
#define PE3   RD2_bit
#define PE4   RD3_bit

void main()
{
    TRISB=0x00;
    
    PORTB=0x00;             //clear PORTB by default
    
    TRISD0_bit=1;
    TRISD1_bit=1;
    TRISD2_bit=1;
    TRISD3_bit=1;

    while(1)
    {
        if(PE1==0)LED1=1;    //turn ON LED1 if PE1 is active
        else LED1=0;         //turn OFF LED1 if PE1 is not active

        if(PE2==0)LED2=1;    //turn ON LED2 if PE2 is active
        else LED2=0;         //turn OFF LED2 if PE2 is not active

        if(PE3==0)LED3=1;    //turn ON LED3 if PE3 is active
        else LED3=0;         //turn OFF LED3 if PE3 is not active

        if(PE4==0)LED4=1;    //turn ON LED4 if PE4 is active
        else LED4=0;         //turn OFF LED4 if PE4 is not active
    }
}
