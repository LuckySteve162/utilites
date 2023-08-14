#include <ctime>

#ifndef TIMER_H_INC
#define TIMER_H_INC
class Timer
{

private:
    time_t t_start;
    time_t t_finish;
    int additional_seconds;
    bool finished;
    Timer(int seconds);

public:
    // main functions
    Timer();
    void start();
    void stop();
    inline double elapsed()
    {
        if (!finished)
        {
            return static_cast<int>(difftime(time(0), t_start)) + additional_seconds;
        }
        return static_cast<int>(difftime(t_finish, t_start)) + additional_seconds;
    }
    void output();
    // inline functions
    inline Timer add(Timer &t1, Timer &t2)
    {
        Timer total_time = Timer(static_cast<int>(t1.elapsed() + t2.elapsed()));
        total_time.stop();
        return total_time;
    }
    inline Timer subtract(Timer &t1, Timer &t2)
    {
        Timer total_time = Timer(static_cast<int>(t1.elapsed() - t2.elapsed()));
        total_time.stop();
        return total_time;
    }
};
#endif
