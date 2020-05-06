# cgrSoftTimer

- For using milliseconds and microseconds timekeeping on arduino without blocking the code
- Suitable for multitasking and OOP
- Create your timer object and do your staff 

## Public methods
- [cgrSoftTimer](#cgrSoftTimer)
- [setHertz](#setHertz)
- [setTimeout](#setTimeout)
- [start](#start)
- [restart](#restart)
- [stop](#stop)
- [isExpired](#isExpired)
- [onExpired](#onExpired)
- [isActive](#isActive)
- [getElapsedTime](#getElapsedTime)
- [getRemainingTime](#getRemainingTime)
- [getRepeats](#getRepeats)
- [getElapsedPercent](#getElapsedPercent)
- [getRemainingPercent](#getRemainingPercent)

## cgrSoftTimer
Include library and create your timer objects with your preferred precision
```c++
#include <cgrSoftTimer.h>

cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision
cgrSoftTimer tmr2(&micros); // tmr2 object with microseconds precision
```
