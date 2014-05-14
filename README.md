ribanTimer
==========

Timer library for Arduino

This library provides a non-blocking timer
Provides one-shot or repeating events with one millisecond or one microsecond resolution.
Maximum interval of millisecond timer is 4294967296ms (49 days, 17 hours, 2 minutes, 47 seconds, 296 milliseconds)
Maximum interval of microsecond timer is 4294967296us (1 hour,11 minutes, 34 seconds, 967 milliseconds, 296 microseconds)
Arduino library has minimum resolution greater than 1 microsecond limiting minimum values for microsecond timer
Does not suffer from 32-bit wrap-around (49 day) issue.

Declare a timer, e.g. globally.
Start timer.
Check for timer event regularly (e.g. in main program loop).

The class is fairly simple. See examples for suggested use.

There are various timer routines and libraries but none (that I found) provided the features I needed. Some were more complex, adding to code size whilst others had fewer features.

This library is licenced under the LGPL and is copyright (c) Brian Walton. It is not knowingly derived from any other works but depends on the Arduino libraries.
