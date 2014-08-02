#define  SW1  RB4_bit
#define  SW2  RB5_bit
#define  SW3  RB6_bit
#define  SW4  RB7_bit

#define  RC_SERVO1   RB0_bit
#define  RC_SERVO2   RB1_bit
#define  RC_SERVO3   RB2_bit
#define  RC_SERVO4   RB3_bit

void dynamic_delay_10us(unsigned char delay);

void main()
{
    unsigned int angle=0;
    unsigned int delay=0;
    
    TRISB4_bit=1;
    TRISB5_bit=1;
    TRISB6_bit=1;
    TRISB7_bit=1;

    TRISB0_bit=0;
    TRISB1_bit=0;
    TRISB2_bit=0;
    TRISB3_bit=0;
    
    while(1)
    {
        if(SW1==0)
        {
            angle=0;         //set RC Servo angle to 0
        }
        else if(SW2==0)
        {
            angle=45;         //set RC Servo angle to 0
        }
        else if(SW3==0)
        {
            angle=90;         //set RC Servo angle to 0
        }
        else if(SW4==0)
        {
            angle=180;         //set RC Servo angle to 0
        }

        if((angle>=0)&&(angle<=180))
        {
            delay=(43+angle*148/180);
            
            RC_SERVO1=1;
            
            dynamic_delay_10us(delay);
            
            RC_SERVO1=0;
            
            dynamic_delay_10us(200-delay);
            
            Delay_ms(18);
        }
    }
}


void dynamic_delay_10us(unsigned char delay)
{
    for( ;delay>0;delay-=1)Delay_us(10);
}
