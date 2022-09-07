#include "CTimer.h"

void CTimer::Start() {
    gettimeofday(&m_StartTime, nullptr);
}

void CTimer::Stop() {
    gettimeofday(&m_EndTime, nullptr);
}

double CTimer::GetElapsedMilliseconds() const {
    double delta = ((double) m_EndTime.tv_sec + 1.0e-6 * (double) m_EndTime.tv_usec) -
                   ((double) m_StartTime.tv_sec + 1.0e-6 * (double) m_StartTime.tv_usec);
    return 1000.0 * delta;
}
