#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include<cstdlib>
#include<ctime>

clock_t x_startTime, x_countTime;
unsigned int x_milliseconds=0, count_down_time_in_secs=0, time_left=0, pause_time=0;

void  delta_time_update_timer()
{
    x_countTime=clock();
    x_milliseconds=x_countTime-x_startTime;
    time_left=count_down_time_in_secs-(x_milliseconds/CLOCKS_PER_SEC);

    gotoxy(1, 2);
    printf("\nTime remaining: %d:%d ", time_left/60, time_left-((time_left/60)*60));
}

#endif // TIMER_H_INCLUDED
