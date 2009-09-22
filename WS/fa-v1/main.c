#include <htc.h>

#include "counter.h"
#include "display.h"
#include "hardware.h"
#include "menu.h"
#include "timer.h"

void main(void)
{
	initHardware();
	initTimers();
	initCounter();
	initDisplay();
	
	while(1)
	{
		if(!hold())
		{
			menu();
		}
		else
		{
			// TODO sleep()
			//countdown();
		}
	}
}
