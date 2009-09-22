#ifndef COUNTER_H_
#define COUNTER_H_

#include "hardware.h"
#include "timer.h"

#endif /*COUNTER_H_*/

#define timeScale 1000

#define increaseSmall  300*timeScale
#define increaseLarge 3600*timeScale

#define updateInterval  60*timeScale

#define resetTime 		 3*timeScale

int hoursToWait;
int minsToWait;
int secsToWait;

void initCounter(void);

void countdownStep(void);

int decreaseTime(void);

void clearDisplayTime(void);
void updateDisplayTime(void);
