#define LED1  RB0_bit
#define LED2  RB1_bit
#define LED3  RB2_bit
#define LED4  RB3_bit
#define LED5  RB4_bit
#define LED6  RB5_bit
#define LED7  RB6_bit
#define LED8  RB7_bit

#define KEYPAD_R1        RD0_bit
#define KEYPAD_R2        RD1_bit
#define KEYPAD_R3        RD2_bit
#define KEYPAD_R4        RD3_bit
#define KEYPAD_C1        RD4_bit
#define KEYPAD_C2        RD5_bit
#define KEYPAD_C3        RD6_bit
#define KEYPAD_C4        RD7_bit

#define KEYPAD_R1_DIR    TRISD0_bit
#define KEYPAD_R2_DIR    TRISD1_bit
#define KEYPAD_R3_DIR    TRISD2_bit
#define KEYPAD_R4_DIR    TRISD3_bit

unsigned char Read_Key(unsigned char row, unsigned char column);

void main()
{
    TRISB=0x00;

    TRISD=0xFF;

    LED1=0;
    LED2=0;
    LED3=0;
    LED4=0;
    LED5=0;
    LED6=0;
    LED7=0;
    LED8=0;

    while(1)
    {
        if(Read_Key(1,1)==0)
        {
            LED1=1;    //turn on LED1 if pressed
        }
        else if(Read_Key(1,2)==0)
        {
            LED2=1;    //turn on LED2 if pressed
        }
        else if(Read_Key(1,3)==0)
        {
            LED3=1;    //turn on LED3 if pressed
        }
        else if(Read_Key(2,1)==0)
        {
            LED4=1;    //turn on LED4 if pressed
        }
        else if(Read_Key(2,2)==0)
        {
            LED5=1;    //turn on LED5 if pressed
        }
        else if(Read_Key(2,3)==0)
        {
            LED6=1;    //turn on LED6 if pressed
        }
        else if(Read_Key(3,1)==0)
        {
            LED7=1;    //turn on LED7 if pressed
        }
        else if(Read_Key(3,2)==0)
        {
            LED8=1;    //turn on LED8 if pressed
        }
        else
        {
            LED1=0;    //turn off all LED
            LED2=0;
            LED3=0;
            LED4=0;
            LED5=0;
            LED6=0;
            LED7=0;
            LED8=0;
        }
    }
}


unsigned char Read_Key(unsigned char row, unsigned char column)
{
    KEYPAD_R1_DIR=1;
    KEYPAD_R2_DIR=1;
    KEYPAD_R3_DIR=1;
    KEYPAD_R4_DIR=1;
    
    switch(row)
    {
        case 1:               //Row 1 selected
            KEYPAD_R1_DIR=0;  //set Row 1 Pin as output
            KEYPAD_R1=0;      //set Row 1 Pin output 0
            break;
        case 2:               //Row 2 selected
            KEYPAD_R2_DIR=0;  //set Row 2 Pin as output
            KEYPAD_R2=0;      //set Row 2 Pin output 0
            break;
        case 3:               //Row 3 selected
            KEYPAD_R3_DIR=0;  //set Row 3 Pin as output
            KEYPAD_R3=0;      //set Row 3 Pin output 0
            break;
        case 4:               //Row 4 selected
            KEYPAD_R4_DIR=0;  //set Row 4 Pin as output
            KEYPAD_R4=0;      //set Row 4 pin output 0
            break;
    }

    switch(column)
    {
        case 1:                        //column 1 selected
            if(KEYPAD_C1==0)return 0;  //return 0 if pin is zero
            else return 1;
            break;
        case 2:                        //column 2 selected
            if(KEYPAD_C2==0)return 0;  //return 0 if pin is zero
            else return 1;
            break;
        case 3:                        //column 3 selected
            if(KEYPAD_C3==0)return 0;  //return 0 if pin is zero
            else return 1;
            break;
        case 4:                        //column 4 selected
            if(KEYPAD_C4==0)return 0;  //return 0 if pin is zero
            else return 1;
            break;
    }
}
