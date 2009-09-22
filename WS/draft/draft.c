
#define display1Line			0
#define display2Line			1
#define displayN 			 	display1Line

#define displayOff				0
#define displayOn				1
#define displayF 			 	displayOn

#define displayInit1Function {0,0,0,0,1,1,displayN,displayF,0,0}


#define timeScale 1000

#define numOfDisplayDigitsX 16
#define numOfDisplayDigitsY  1

#define increaseSmall  300*timeScale
#define increaseLarge 3600*timeScale

#define updateInterval  60*timeScale

#define resetTime 		 3*timeScale

int currentTime = 0;
int deltaTime = 0;

int hoursToWait = 0;
int minsToWait = 0;
int secsToWait = 0;

int batteryState = 1;
int tmpBatteryState = 1;

char digits[] = "0123456789";

void main(void)
{
	displayInit();
	while(1)
	{
		if(hold())
		{
			countdown();
		}
		else
		{
			menu();
		}
	}
}

void menu(void)
{
	while(!hold)
	{
		if(isButton1Pressed() && !isButton2Pressed())
		{
			currentTime = getTime();
			while(isButton1Pressed());
			deltaTime = getTime() - currentTime;
			if(deltaTime > resetTime)
			{
				hoursToWait = 0;
			}
			else
			{
				hoursToWait++;
			}
		}
		if(isButton2Pressed() && !isButton1Pressed())
		{
			currentTime = getTime();
			while(isButton2Pressed());
			deltaTime = getTime() - currentTime;
			if(deltaTime > resetTime)
			{
				minsToWait = 0;
				secsToWait = 0;
			}
			else
			{
				minsToWait++;
			}
		}
		updateDisplayTime();
		updateBatteryLevel();
	}
}

int isButton1Pressed(void)
{
	return 0;
}

int isButton2Pressed(void)
{
	return 0;
}

void countdown(void)
{
	if(decreaseTime())
	{
		setOpen(1);
		for(int i = 0; i < 10; i++)
		{
			currentTime = getTime();
			wait(updateInterval);
			if(i == 3)
			{
				setOpen(0);
			}
		}
	}
	else
	{
		wait(updateInterval);
	}
	updateBatteryLevel();
	currentTime = getTime();
}

void wait(int deltaTime)
{
	while(getTime() < currentTime + deltaTime);
}

void setOpen(int open)
{
	// TODO
}

long getTime(void)
{
	// TODO
	return 0;
}

int getBatteryLevel(void)
{
	// TODO
	return 100;
}

void updateBatteryLevel(void)
{
	// TODO
}

int decreaseTime(void)
{
	secsToWait--;
	if(secsToWait < 0)
	{
		secsToWait = 59;
		minsToWait--;
		if(minsToWait < 0)
		{
			minsToWait = 59;
			hoursToWait--;
		}
	}
	updateDisplayTime();
	return !secsToWait && !minsToWait && !hoursToWait;
}

void updateDisplayTime(void)
{
	if(hoursToWait/10)
		setDisplayChar(digits[hoursToWait/10],  8, 1);
	else
		setDisplayChar(' '                   ,  8, 1);
	setDisplayChar(digits[hoursToWait%10],  9, 1);
	setDisplayChar(':'                   , 10, 1);
	setDisplayChar(digits[minsToWait/10] , 11, 1);
	setDisplayChar(digits[minsToWait%10] , 12, 1);
	setDisplayChar(':'                   , 13, 1);
	setDisplayChar(digits[secsToWait/10] , 14, 1);
	setDisplayChar(digits[secsToWait%10] , 15, 1);
}

void setDisplayChar(char c, int posX, int posY)
{
	setDisplaySymbol((int) c, posX, posY);
}

void setDisplaySymbol(int symbol, int posX, int posY)
{
	if(posX >= numOfDisplayDigitsX)
		return;
	if(posY >= numOfDisplayDigitsY)
		return;
	if(posX < 0)
		return;
	if(posY < 0)
		return;
	// TODO
}

void displayInit(void)
{

}
