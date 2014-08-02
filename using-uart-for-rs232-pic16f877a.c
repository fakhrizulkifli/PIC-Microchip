#define LED1 RB0_bit
#define LED2 RB1_bit
#define LED3 RB2_bit
#define LED4 RB3_bit
#define LED5 RB4_bit
#define LED6 RB5_bit
#define LED7 RB6_bit
#define LED8 RB7_bit

#define SW1  RD0_bit
#define SW2  RD1_bit
#define SW3  RD2_bit
#define SW4  RD3_bit

void main()
{
    unsigned char receive;

    TRISB=0x00;
    
    TRISD0_bit=1;
    TRISD1_bit=1;
    TRISD2_bit=1;
    TRISD3_bit=1;

    LED1=0;
    LED2=0;
    LED3=0;
    LED4=0;
    LED5=0;
    LED6=0;
    LED7=0;
    LED8=0;

    UART1_Init(9600);

    while(1)
    {
        if(UART1_Data_Ready()==1)
        {
            receive=UART1_Read();

            switch(receive)
            {
                case '0':
                    LED1=0;
                    LED2=0;
                    LED3=0;
                    LED4=0;
                    LED5=0;
                    LED6=0;
                    LED7=0;
                    LED8=0;
                    break;
                case '1':
                    LED1=1;
                    break;
                case '2':
                    LED2=1;
                    break;
                case '3':
                    LED3=1;
                    break;
                case '4':
                    LED4=1;
                    break;
                case '5':
                    LED5=1;
                    break;
                case '6':
                    LED6=1;
                    break;
                case '7':
                    LED7=1;
                    break;
                case '8':
                    LED8=1;
                    break;
            }
        }

        //[insert code] check SW1, if SW1 is pressed, send a 'A' to PC using
        // UART1_Write function. make sure you put a debounce loop to wait
        // for SW1 to be release, and before transmitting using UART1_Write
        // function, make sure you check the TX idle status using UART1_Tx_Idle
        // function. wait for the previous transmission to complete before
        // sending out new data to PC
        if(SW1==0)
        {
            while(SW1==0);
            while(UART1_Tx_Idle()==0);
            UART1_Write('A');
        }
        
        //[insert code] check SW2, if SW2 is pressed, send a 'B' to PC using
        // UART1_Write function. make sure you put a debounce loop to wait
        // for SW2 to be release, and before transmitting using UART1_Write
        // function, make sure you check the TX idle status using UART1_Tx_Idle
        // function. wait for the previous transmission to complete before
        // sending out new data to PC
        if(SW2==0)
        {
            while(SW2==0);
            while(UART1_Tx_Idle()==0);
            UART1_Write('B');
        }
        
        //[insert code] check SW3, if SW3 is pressed, send a 'C' to PC using
        // UART1_Write function. make sure you put a debounce loop to wait
        // for SW3 to be release, and before transmitting using UART1_Write
        // function, make sure you check the TX idle status using UART1_Tx_Idle
        // function. wait for the previous transmission to complete before
        // sending out new data to PC
        if(SW3==0)
        {
            while(SW3==0);
            while(UART1_Tx_Idle()==0);
            UART1_Write('C');
        }
        
        //[insert code] check SW4, if SW4 is pressed, send a 'D' to PC using
        // UART1_Write function. make sure you put a debounce loop to wait
        // for SW4 to be release, and before transmitting using UART1_Write
        // function, make sure you check the TX idle status using UART1_Tx_Idle
        // function. wait for the previous transmission to complete before
        // sending out new data to PC
        if(SW4==0)
        {
            while(SW4==0);
            while(UART1_Tx_Idle()==0);
            UART1_Write('D');
        }
    }
}
