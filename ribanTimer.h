/**     ribanTimer - Timer functions without 32-bit roll-over issues
*       Copyright (c) 2014, Brian Walton. All rights reserved. GLPL.
*       Source availble at https://github.com/riban-bw/ribanTimer.git
*/

#pragma once

/** @brief  This class provides a non-blocking timer
*   @note   Provides one-shot or repeating events with one millisecond or one microsecond resolution.
*   @note   Maximum interval of millisecond timer is 4294967296ms (49 days, 17 hours, 2 minutes, 47 seconds, 296 milliseconds)
*   @note   Maximum interval of microsecond timer is 4294967296us (1 hour,11 minutes, 34 seconds, 967 milliseconds, 296 microseconds)
*   @note   Arduino library has minimum resolution greater than 1 microsecond limiting minimum values for microsecond timer
*/
class Timer
{
    public:
        /** @brief  Construct a timer
        *   @param  Microsecond True to configure microsecond timer. Default = false
        */
        Timer(bool Microsecond = false);

        /** @brief  Start the timer
        *   @param  Interval Interval between timer triggers. Zero stops timer (inhibits events)
        *   @param  OneShot Set to true to trigger once then stop. Default = false
        */
        void start(unsigned long Interval, bool OneShot = false);

        /** @brief  Stops timer
        */
        void stop();

        /** @brief  Check if timer event triggered
        *   @return <i>bool</i> True if triggered
        *   @note   Call IsTriggered regulary, e.g. within main loop
        */
        bool IsTriggered();

        /** @brief  Gets the number of events triggered since intialised
        *   @return <i>unsigned long</i> Quantity of events
        */
        unsigned long GetCount();

    private:
        bool m_bMicroseconds; // True to configure as microsecond timer
        bool m_bOneShot; // True for one-shot timers
        unsigned long m_lInterval; // Timer interval in miliseconds - zero means disable timer
        unsigned long m_lLastTriggerTime; // Time of last update
        unsigned long m_lCount; // Number of times has been triggered
};
