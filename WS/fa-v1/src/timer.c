#include "timer.h"

void initTimers(void)
{
	// TODO
}

void 	timer1_reset(void)
{
	// TODO
}

void	timer1_start(void)
{
	// TODO
}

int		timer1_get(void)
{
	// TODO
}

void	timer1_stop(void)
{
	// TODO
}

void 	timer1_wait(int startTime, int deltaTime)
{	
	while(timer1_get() < startTime + deltaTime);
}
