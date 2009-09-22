#include "menu.h"

void menu(void)
{
	while(!hold())
	{
		if(isButton1Pressed() && !isButton2Pressed())
		{
			timer1_reset();
			timer1_start();
			while(isButton1Pressed());
			if(timer1_get() > resetTime)
			{
				hoursToWait = 0;
			}
			else
			{
				hoursToWait++;
			}
			timer1_stop();
		}
		if(isButton2Pressed() && !isButton1Pressed())
		{
			timer1_reset();
			timer1_start();
			while(isButton2Pressed());
			if(timer1_get() > resetTime)
			{
				minsToWait = 0;
				secsToWait = 0;
			}
			else
			{
				minsToWait++;
			}
			timer1_stop();
		}
		updateDisplayTime();
		updateBatteryLevel();
	}
}