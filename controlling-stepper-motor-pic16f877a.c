#define  SW1  RB0_bit
#define  SW2  RB1_bit
#define  SW3  RB2_bit
#define  SW4  RB3_bit

#define  ENABLE   RC5_bit
#define  DIR      RC6_bit
#define  PULSE    RC2_bit

void dynamic_delay_ms(unsigned int delay);

void main()
{
    unsigned int frequency=0;
    
    TRISB0_bit=1;
    TRISB1_bit=1;
    TRISB2_bit=1;
    TRISB3_bit=1;

    TRISC5_bit=0;
    TRISC6_bit=0;
    TRISC2_bit=0;
    
    ENABLE=1;             //disable motor

    while(1)
    {
        if(SW1==0)
        {
            frequency=250;       //set motor speed to 250Hz
            DIR=1;               //set motor direction to CW
            ENABLE=0;            //enable motor
        }
        else if(SW2==0)
        {
            frequency=250;       //set motor speed to 250Hz
            DIR=0;               //set motor direction to CCW
            ENABLE=0;            //enable motor
        }
        else if(SW3==0)
        {
            frequency=500;       //set motor speed to 500Hz
            DIR=1;               //set motor direction to CW
            ENABLE=0;            //enable motor
        }
        else if(SW4==0)
        {
            frequency=500;        //set motor speed to 500Hz
            DIR=0;                //set motor direction to CCW
            ENABLE=0;             //enable motor
        }
        else
        {
            frequency=0;          //set motor speed to 800Hz
            ENABLE=1;             //disable motor
        }

        PULSE=1;
        PULSE=0;
        
        if(frequency>0)dynamic_delay_ms(1000/frequency);
    }
}


void dynamic_delay_ms(unsigned int delay)
{
    for( ;delay>0;delay-=1)Delay_Ms(1);
}
