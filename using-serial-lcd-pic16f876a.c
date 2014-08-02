#define SLCD_EN   RA5_bit

void Slcd_Init();
void Slcd_Out(unsigned char row, unsigned char column, char *text);
void Slcd_Out_Cp(char *text);
void Slcd_Chr(unsigned char row, unsigned char column, char out_char);
void Slcd_Chr_Cp(char out_char);
void Slcd_Cmd(unsigned char out_char);
unsigned char Slcd_Bit_Swap(unsigned char DATA);

void main()
{
    ADCON1=0b00000110;     //enable RA5 pin as digital pin
    TRISA5_bit=0;          //set RA5 as output

    Slcd_Init();           //this function initialize all LCD configuration
                           //including the pin direction configuration

    Slcd_Out(1,1,"Hello World!");   //display "Hello World!" text on Row 1 Column 1

    while(1);
}

void Slcd_Init()
{
    SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV64,_SPI_DATA_SAMPLE_MIDDLE,
        _SPI_CLK_IDLE_LOW,_SPI_LOW_2_HIGH);

    Slcd_Cmd(0b00000110);   //Entry Mode Set AC increment, display shift OFF
    Slcd_Cmd(0b00001111);   //Display ON, Cursor underline ON, Blinking cursor ON
    Slcd_Cmd(0b00010100);   //Cursor moving, shift to right
    Slcd_Cmd(0b00111000);   //8-bit interface, 2 line mode, 5x7 dot format
    Slcd_Cmd(0b00000010);   //Display and Cursor Home
    Slcd_Cmd(0b00000001);   //Clear Screen

}

void Slcd_Out(unsigned char row, unsigned char column, char *text)
{
    if((column-1)>0x27)return;

    if(row==1)Slcd_Cmd(0x80|(column-1));
    else if(row==2)Slcd_Cmd(0x80|0x40|(column-1));
    else return;

    Slcd_Out_Cp(text);
}

void Slcd_Out_Cp(char *text)
{
    while((text!=0)&&(*text!=0))
    {
        Slcd_Chr_Cp(*text++);
    }
}

void Slcd_Chr(unsigned char row, unsigned char column, char out_char)
{
    if((column-1)>0x27)return;

    if(row==1)Slcd_Cmd(0x80|(column-1));
    else if(row==2)Slcd_Cmd(0x80|0x40|(column-1));
    else return;

    Slcd_Chr_Cp(out_char);
}

void Slcd_Chr_Cp(char out_char)
{
    SPI1_Write(Slcd_Bit_Swap(0x02));
    SPI1_Write(Slcd_Bit_Swap(out_char));
    SLCD_EN=1;
    Delay_Us(200);     //short delay for EN pulse
    SLCD_EN=0;
    Delay_Us(200);     //short delay for EN pulse
}

void Slcd_Cmd(unsigned char out_char)
{
    SPI1_Write(Slcd_Bit_Swap(0x00));
    SPI1_Write(Slcd_Bit_Swap(out_char));
    SLCD_EN=1;
    Delay_Us(200);     //short delay for EN pulse
    SLCD_EN=0;
    Delay_Ms(5);      //short delay (5ms) for configuration byte
}

unsigned char Slcd_Bit_Swap(unsigned char DATA)
{
    unsigned char i=0;
    unsigned char RESULT=0;
    for(i=0;i<=7;i+=1)
    {
        RESULT=RESULT<<1;
        RESULT=RESULT|((DATA>>i)&0x01);
    }
    return RESULT;
}
