#ifndef _CTIMER_H
#define _CTIMER_H

#include <sys/time.h>

class CTimer {
public:

    CTimer() {};

    ~CTimer() {};

    void Start();

    void Stop();

    double GetElapsedMilliseconds() const;

protected:
    struct timeval m_StartTime;
    struct timeval m_EndTime;
};

#endif // _CTIMER_H
