#define LED  PORTB

void main()
{
    TRISB=0x00;

    while(1)
    {
        LED=0b10101010;

        Delay_ms(300);

        LED=0b01010101;

        Delay_ms(300);
    }
}
