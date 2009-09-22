#include "display.h"

void initDisplay(void)
{
	num2digit[0] = '0';
	num2digit[1] = '1';
	num2digit[2] = '2';
	num2digit[3] = '3';
	num2digit[4] = '4';
	num2digit[5] = '5';
	num2digit[6] = '6';
	num2digit[7] = '7';
	num2digit[8] = '8';
	num2digit[9] = '9';
	
	display_digit[0][0] 	= display_digit_0;
	display_digit[1][0] 	= display_digit_1;
	display_digit[2][0] 	= display_digit_2;
	display_digit[3][0] 	= display_digit_3;
	display_digit[4][0] 	= display_digit_4;
	display_digit[5][0] 	= display_digit_5;
	display_digit[6][0] 	= display_digit_6;
	display_digit[7][0] 	= display_digit_7;
	display_digit[8][0] 	= display_digit_8;
	display_digit[9][0] 	= display_digit_9;
	display_digit[10][0] 	= display_digit_10;
	display_digit[11][0] 	= display_digit_11;
	display_digit[12][0] 	= display_digit_12;
	display_digit[13][0] 	= display_digit_13;
	display_digit[14][0] 	= display_digit_14;
	display_digit[15][0] 	= display_digit_15;
	
	display_on(display_D_On, display_C_Off, display_B_Off);
}

int display_command(int command)
{
	// TODO
}

void display_clear(void)
{
	display_command(display_clear_command);
}

void display_returnHome(void)
{
	display_command(display_returnHome_command);
}

void display_entryModeSet(int ID, int SH)
{
	display_command(display_entryModeSet_command | ID<<1 | SH);
}

void display_on(int D, int C, int B)
{
	display_command(display_on_command | D<<2 | C<<1 | B<<0);
}

void display_shift(int SC, int RL)
{
	display_command(display_shift_command | SC<<3 | RL<<2);
}

void display_setFunction(int DL, int N, int F)
{
	display_command(display_setFunction_command | DL<<4 | N<<3 | F<<2);
}

void display_setCGRamAddress(int address)
{
	display_command(display_setCGRamAddress_command | address);
}

void display_setDDRamAddress(int address)
{
	display_command(display_setDDRamAddress_command | address);
}

int  display_readBusyFlag(int address)
{
	return display_command(display_readBusyFlag_command | address);
}

void display_writeData(int data)
{
	display_command(display_writeData_command | data);
}

int  display_readData(void)
{
	return display_command(display_readData_command);
}

void setDisplayInt(int i, int posX, int posY)
{
	setDisplayChar(num2digit[i], posX, posY);
}

void setDisplayChar(char c, int posX, int posY)
{
	setDisplaySymbol((int) c, posX, posY);
}

void setDisplaySymbol(int symbol, int posX, int posY)
{
	if(posX >= numOfDigitsX)
		return;
	if(posY >= numOfDigitsY)
		return;
	if(posX < 0)
		return;
	if(posY < 0)
		return;
	
	display_setDDRamAddress(display_digit[posX][posY]);
	// TODO wait 42us
	display_writeData(symbol);
}