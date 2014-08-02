#define  SW1  RB0_bit
#define  SW2  RB1_bit
#define  SW3  RB2_bit
#define  SW4  RB3_bit

#define  ENABLE   RC5_bit
#define  DIR      RC6_bit

void main()
{
    TRISB0_bit=1;
    TRISB1_bit=1;
    TRISB2_bit=1;
    TRISB3_bit=1;
    
    TRISC5_bit=0;
    TRISC6_bit=0;
    
    ENABLE=1;             //disable motor
    
    PWM1_Init(5000);      //initialize PWM1 module at 5KHz
    PWM1_Set_Duty(0);     //initialize PWM1 dut cycle as 0
    PWM1_Start();         //start PWM1

    while(1)
    {
        if(SW1==0)
        {
            PWM1_Set_Duty(192);   //set motor speed to 75%
            DIR=1;                //set motor direction to CW
            ENABLE=0;             //enable motor
        }
        else if(SW2==0)
        {
            PWM1_Set_Duty(192);   //set motor speed to 75%
            DIR=0;                //set motor direction to CCW
            ENABLE=0;             //enable motor
        }
        else if(SW3==0)
        {
            PWM1_Set_Duty(255);   //set motor speed to 100%
            DIR=1;                //set motor direction to CW
            ENABLE=0;             //enable motor
        }
        else if(SW4==0)
        {
            PWM1_Set_Duty(255);   //set motor speed to 100%
            DIR=0;                //set motor direction to CCW
            ENABLE=0;             //enable motor
        }
        else
        {
            ENABLE=1;             //disable motor
        }
    }
}
