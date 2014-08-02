#define LED  PORTB

void main()
{
    TRISB=0x00;

    ADC_Init();

    while(1)
    {
        LED=(unsigned char)(ADC_Get_Sample(0)&0xff);
    }
}
