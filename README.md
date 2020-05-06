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
- Include library and create your timer objects with your preferred precision
```c++
#include <cgrSoftTimer.h>

cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision
cgrSoftTimer tmr2(&micros); // tmr2 object with microseconds precision

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

## setHertz
- Sets the running count of the timer per one second.
- Range of milliseconds precision timer : 1-1000 Hz 
- Range of microseconds precision timer : 1-250000 Hz 

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision
cgrSoftTimer tmr2(&micros); // tmr2 object with microseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setHertz(5);     // tmr1 will pulse 5 times per second
  tmr2.setHertz(1500);  // tmr2 will pulse 1500 times per second
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

## setTimeout
- Sets the running period of the timer

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision
cgrSoftTimer tmr2(&micros); // tmr2 object with microseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  tmr2.setTimeout(1000000);  // tmr2 will pulse every 1 seconds ( 1 seconds = 1000000 microseconds )
}

void loop() {
  // put your main code here, to run repeatedly:
}
```
