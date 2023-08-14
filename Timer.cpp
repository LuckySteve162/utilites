#include "Timer.h"
#include <ctime>
#include <iostream>

Timer::Timer(int seconds) : t_start{time(0)}, t_finish{time(0)}, additional_seconds{seconds}, finished{false}
{
    // Time constructor with a input of seconds
}
Timer::Timer() : t_start{time(0)}, t_finish{time(0)}, additional_seconds{0}, finished{false}
{
    // empty constructor
}
void Timer::start()
{
    t_start = time(0);
    finished = false;
}
void Timer::stop()
{
    t_finish = time(0);
    finished = true;
}

void Timer::output()
{
    if (!finished)
    {
        std::cout << "Timer has not stopped. ";
    }
    std::cout << "Current elapsed time: " << elapsed();
    return;
}
