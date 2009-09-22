#ifndef DISPLAY_H_
#define DISPLAY_H_

#endif /*DISPLAY_H_*/

// cursor move direction
#define display_ID_Increase 	1
#define display_ID_Decrease 	0

// specifies shift of display
#define display_SH_shift_On	 	1
#define display_SH_shift_Off 	0

// display
#define display_D_On			1
#define display_D_Off			0

// cursor
#define display_C_On			1
#define display_C_Off			0

// blinking
#define display_B_On			1
#define display_B_Off			0

// shift or cursor move
#define display_SC_shift		1
#define display_SC_cursorMove	0

// shift direction
#define display_RL_rightShift	1
#define display_RL_leftShift	0

// interface bit-type
#define display_DL_8bit			1
#define display_DL_4bit			0

// lines
#define display_N_2line			1
#define display_N_1line			0

// matrix-size
#define display_F_5x10dots		1
#define display_F_5x7dots		0

// busy or not
#define display_BF_busy			1
#define display_BF_ready		0

// digit addresses
#define display_digit_0			0x00
#define display_digit_1			0x01
#define display_digit_2			0x02
#define display_digit_3			0x03
#define display_digit_4			0x04
#define display_digit_5			0x05
#define display_digit_6			0x06
#define display_digit_7			0x07
#define display_digit_8			0x40
#define display_digit_9			0x41
#define display_digit_10		0x42
#define display_digit_11		0x43
#define display_digit_12		0x44
#define display_digit_13		0x45
#define display_digit_14		0x46
#define display_digit_15		0x47

// base-commands
#define display_clear_command				1<<0
#define display_returnHome_command			1<<1
#define display_entryModeSet_command		1<<2
#define display_on_command					1<<3
#define display_shift_command				1>>4
#define display_setFunction_command			1<<5
#define display_setCGRamAddress_command		1<<6
#define display_setDDRamAddress_command		1<<7
#define display_readBusyFlag_command		1<<8
#define display_writeData_command			1<<9
#define display_readData_command			1<<10 | 1<<9

#define numOfDigitsX			16
#define numOfDigitsY			1

char num2digit[10];

int display_digit[numOfDigitsX][numOfDigitsY];

void initDisplay(void);

int  display_command(int command);

void display_clear(void);
void display_returnHome(void);
void display_entryModeSet(int ID, int SH);
void display_on(int D, int C, int B);
void display_shift(int SC, int RL);
void display_setFunction(int DL, int N, int F);
void display_setCGRamAddress(int address);
void display_setDDRamAddress(int address);
int  display_readBusyFlag(int address);
void display_writeData(int data);
int  display_readData(void);

void setDisplayInt(int i, int posX, int posY);
void setDisplayChar(char c, int posX, int posY);
void setDisplaySymbol(int symbol, int posX, int posY);