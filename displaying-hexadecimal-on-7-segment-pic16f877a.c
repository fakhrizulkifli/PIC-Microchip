#define _7SEG_DATA PORTB
#define _7SEG1_LE  RD0_bit
#define _7SEG2_LE  RD1_bit
#define _7SEG3_LE  RD2_bit
#define _7SEG4_LE  RD3_bit

// No need for re-representation to the binary.
// Just put the binary or hex into the array.
#define HEXNUM_0   0b00111111
#define HEXNUM_1   0b00000110
#define HEXNUM_2   0b01011011
#define HEXNUM_3   0b01001111
#define HEXNUM_4   0b01100110
#define HEXNUM_5   0b01101101
#define HEXNUM_6   0b01111101
#define HEXNUM_7   0b00000111
#define HEXNUM_8   0b01111111
#define HEXNUM_9   0b01101111
#define HEXNUM_A   0b01110111
#define HEXNUM_B   0b01111100
#define HEXNUM_C   0b00111001
#define HEXNUM_D   0b01011110
#define HEXNUM_E   0b01111001
#define HEXNUM_F   0b01110001

void _7SEG1(unsigned char DATA);
void _7SEG2(unsigned char DATA);
void _7SEG3(unsigned char DATA);
void _7SEG4(unsigned char DATA);

// Just put the reserved hex memory address here.
// 0x1 - 0xF can't be altered, when it is declared in the array it will use the represented binary code.
// any added value inside the array must be called using 0x10 - 0xff
unsigned char HEXNUM[16]=
         {HEXNUM_0,HEXNUM_1,HEXNUM_2,HEXNUM_3,
         HEXNUM_4,HEXNUM_5,HEXNUM_6,HEXNUM_7,
         HEXNUM_8,HEXNUM_9,HEXNUM_A,HEXNUM_B,
         HEXNUM_C,HEXNUM_D,HEXNUM_E,HEXNUM_F};

void main()
{
    TRISB=0x00;        //set whole PORTB as output

    TRISD0_bit=0;      //set RD0-RD3 as output
    TRISD1_bit=0;
    TRISD2_bit=0;
    TRISD3_bit=0;

    _7SEG1(0x00);      //clear 7 Segment 1
    _7SEG2(0x00);      //clear 7 Segment 2
    _7SEG3(0x00);      //clear 7 Segment 3
    _7SEG4(0x00);      //clear 7 Segment 4

    _7SEG1(HEXNUM[0x1]);   //set 7 Segment 1 to "1"
    _7SEG2(HEXNUM[0xA]);   //set 7 Segment 2 to "A"
    _7SEG3(HEXNUM[0xB]);   //set 7 Segment 3 to "B"
    _7SEG4(HEXNUM[0xC]);   //set 7 Segment 4 to "C"

    while(1);
}


void _7SEG1(unsigned char DATA)
{
    _7SEG_DATA=DATA; //put the DATA to the 8 I/O PORT
    _7SEG1_LE=1;     //Latch 1 LE to 1 to latch out the output to 7 Segment 1
    _7SEG1_LE=0;     //Latch 1 LE to 0
}

void _7SEG2(unsigned char DATA)
{
    _7SEG_DATA=DATA; //put the DATA to the 8 I/O PORT
    _7SEG2_LE=1;     //Latch 2 LE to 1 to latch out the output to 7 Segment 2
    _7SEG2_LE=0;     //Latch 2 LE to 0
}

void _7SEG3(unsigned char DATA)
{
    _7SEG_DATA=DATA; //put the DATA to the 8 I/O PORT
    _7SEG3_LE=1;     //Latch 3 LE to 1 to latch out the output to 7 Segment 3
    _7SEG3_LE=0;     //Latch 3 LE to 0
}

void _7SEG4(unsigned char DATA)
{
    _7SEG_DATA=DATA; //put the DATA to the 8 I/O PORT
    _7SEG4_LE=1;     //Latch 4 LE to 1 to latch out the output to 7 Segment 4
    _7SEG4_LE=0;     //Latch 4 LE to 0
}
