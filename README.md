# cgrSoftTimer

- For using milliseconds and microseconds timekeeping on arduino without blocking the code
- Suitable for multitasking and OOP
- Create your timer object and do your staff 

## Public methods
- [cgrSoftTimer](#cgrSoftTimer)
- [List CheckBox (selam)](#list-checkbox-[selam])
- [deneme1](#deneme)
- [start](#start)
- [stop](#stop)
- [restart](#restart)
- [isExpired](#isExpired)
- [onExpired](#onExpired)
- [isActive](#isActive)
- [getElapsedTime](#getElapsedTime)
- [getRemainingTime](#getRemainingTime)
- [getElapsedPercent](#getElapsedPercent)
- [getRemainingPercent](#getRemainingPercent)
- [getRepeats](#getRepeats)

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
## deneme1
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
## setTimeout(unsigned long timeout)
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

## start
- Starts the timer with given repeat count. Give 0 (zero) to function to work infinite

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision
cgrSoftTimer tmr2(&micros); // tmr2 object with microseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  tmr2.setTimeout(1000000);  // tmr2 will pulse every 1 seconds ( 1 seconds = 1000000 microseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
  tmr2.start(0); // tmr1 is going to work unlimited times
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

## stop
- Stops the timer working

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
    
  tmr1.stop(); // tmr1 is stopped
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

## restart
- Restarts the timer with the given values before
- You can use this function in any phase of timer working. (eg. while working for refreshin the timer, or after stopped to re use)

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
    
  tmr1.stop(); // tmr1 is stopped
  tmr1.restart(); // tmr1 is restarted
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

## isExpired
- This will run continuously after timer's first fired up phase. It means that the timer is fired up.

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(tmr1.isExpired())
  {
    // After first 1000 milliseconds, codes in here will run continuously
    // do your staff here
  }
}
```

## onExpired
- This will run only once on every timer fired up phase. It means the timer is on the fire up time.

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(tmr1.onExpired())
  {
    // At every 1000 milliseconds, codes in here will run once..
    // do your staff here
  }
}
```

## isActive
- Checks is the timer is on working phase

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(tmr1.isActive())
  {
    // Codes in here will run continuously till the count limit defined on 'tmr1.start(5);' ends.
    // do your staff here
  }
}
```

## getElapsedTime
- Returns an **unsigned long** for how much time have passed

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
   unsigned long elapsedTime = tmr1.getElapsedTime(); // Gets the value of elapsed time of tmr1
}
```

## getRemainingTime
- Returns an **unsigned long** for how much time is remaining

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
   unsigned long remainingTime = tmr1.getRemainingTime(); // Gets the value of remaining time of tmr1
}
```


## getElapsedPercent
- Returns an **unsigned long** for how much time have passed as an percentage

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
   unsigned long elapsedPercent = tmr1.getElapsedPercent(); // Gets the percentage of elapsed time of tmr1
}
```


## getRemainingPercent
- Returns an **unsigned long** for how much time is remaining as an percentage

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
   unsigned long remainingPercent = tmr1.getRemainingPercent(); // Gets the percentage of remaining time of tmr1
}
```


## getRepeats
- Returns an **unsigned int** for how much pulse has been counted

```c++
cgrSoftTimer tmr1(&millis); // tmr1 object with milliseconds precision

void setup() {
  // put your setup code here, to run once:
  tmr1.setTimeout(1000);     // tmr1 will pulse every 1 seconds ( 1 seconds = 1000 milliseconds )
  
  tmr1.start(5); // tmr1 is going to work 5 times
}

void loop() {
  // put your main code here, to run repeatedly:
  
   unsigned int totalPulse = tmr1.getRepeats(); // Gets the counted pulses of tmr1
}
```
