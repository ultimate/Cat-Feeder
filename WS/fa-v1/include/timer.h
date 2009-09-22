#ifndef TIMER_H_
#define TIMER_H_

#endif /*TIMER_H_*/

void initTimers(void);

void 	timer1_reset(void);
void	timer1_start(void);
int		timer1_get(void);
void	timer1_stop(void);
void 	timer1_wait(int startTime, int deltaTime);