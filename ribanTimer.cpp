#include "ribanTimer.h"
#include <Arduino.h>

Timer::Timer(bool Microsecond) :
    m_bMicroseconds(Microsecond),
    m_bPhase(false),
    m_lInterval(0),
    m_lCount(0)
{
}

void Timer::start(unsigned long Interval, bool OneShot)
{
    m_lInterval = Interval;
    m_lLastTriggerTime = m_bMicroseconds?micros():millis();
    m_bOneShot = OneShot;
    m_bPhase = true;
}

void Timer::stop()
{
    m_lInterval = 0;
    m_bPhase = false;
}

bool Timer::IsTriggered()
{
    bool bReturn = false;
    if(m_lInterval) //do nothing if interval not set
    {
        unsigned long lNow = m_bMicroseconds?micros():millis();
        if(m_lLastTriggerTime > lNow)
        {
            //timer has wrapped around
            bReturn = (0 - m_lLastTriggerTime >= m_lInterval - lNow);
        }
        else
        {
            bReturn = (lNow >= m_lLastTriggerTime + m_lInterval);
        }
        if(bReturn)
        {
            m_lCount++;
            m_lLastTriggerTime = lNow;
            if(m_bOneShot)
            {
                m_lInterval = 0;
                m_bPhase = false;
            }
            else m_bPhase = !m_bPhase;
        }
    }
    return bReturn;
};

unsigned long Timer::GetCount()
{
    return m_lCount;
}

bool Timer::IsRunning()
{
    IsTriggered();
    return (0 != m_lInterval);
}

bool Timer::IsOddPhase()
{
    return m_bPhase;
}
