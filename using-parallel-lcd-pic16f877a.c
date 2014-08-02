sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;

#define LCD_RW  RB6_bit
#define LCD_BL  RB7_bit

void main()
{
    TRISB6_bit=0;   //set both RB6 and RB7 pin as output
    TRISB7_bit=0;

    LCD_BL=1;    //turn on Backlight
    LCD_RW=0;    //set LCD in write mode

    Lcd_Init();  //this function initialize all LCD configuration
                 //including the pin direction configuration

    Lcd_Out(1,1,"Hello World!");  //display "Hello World!" text on Row 1 Column 1

    while(1);
}
