#include "counter.h"

void initCounter(void)
{
	hoursToWait = 0;
	minsToWait = 0;
	secsToWait = 0;
	
	// TODO register countdownStep for every second
}

void countdownStep(void)
{
	if(decreaseTime())
	{
		setOpen(1);
		timer1_reset();
		timer1_start();
		for(int i = 0; i < 6; i++)
		{
			timer1_wait(0, updateInterval*i);
			if((i % 2) == 1)
			{
				clearDisplayTime();
			}
			else
			{
				updateDisplayTime();
			}
		}
		timer1_stop();
		setOpen(0);
	}
	updateBatteryLevel();
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

void clearDisplayTime(void)
{
	for(int i = 8; i < 16; i++)
	{
		setDisplayChar(' '          ,  i, 1);
	}
}

void updateDisplayTime(void)
{
	if(hoursToWait/10)
		setDisplayInt(hoursToWait/10,  8, 1);
	else
		setDisplayChar(' '          ,  8, 1);
	setDisplayInt(hoursToWait%10,  9, 1);
	setDisplayChar(':'          , 10, 1);
	setDisplayInt(minsToWait/10 , 11, 1);
	setDisplayInt(minsToWait%10 , 12, 1);
	setDisplayChar(':'          , 13, 1);
	setDisplayInt(secsToWait/10 , 14, 1);
	setDisplayInt(secsToWait%10 , 15, 1);
}