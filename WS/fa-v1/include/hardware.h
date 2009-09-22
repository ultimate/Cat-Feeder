#ifndef HARDWARE_H_
#define HARDWARE_H_

#include "display.h"

#endif /*HARDWARE_H_*/

int batteryState;
int tmpBatteryState;

void initHardware(void);

int isButton1Pressed(void);
int isButton2Pressed(void);

int hold(void);

void setOpen(int open);

int getBatteryLevel(void);

void updateBatteryLevel(void);
