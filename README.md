# cgrSoftTimer

- For using milliseconds and microseconds timekeeping on arduino without blocking the code
- Suitable for multitasking and OOP
- Create your timer object and do your staff 

## Public methods
- [cgrSoftTimer](#cgrSoftTimer)
- [cgrSoftTimer(usedTimer usedTimerPtr)](#cgrSoftTimer1)
- [void setHertz(unsigned int hertz)](#setHertz)
- [void setTimeout(unsigned int timeout)](#setTimeout)
- [void start(unsigned int repeatLimit)](#start)
- [void stop()](#stop)
- [void restart()](#restart)
- [bool isExpired()](#isExpired)
- [bool onExpired()](#onExpired)
- [bool isActive()](#isActive)
- [unsigned long getElapsedTime()](#getElapsedTime)
- [unsigned long getRemainingTime()](#getRemainingTime)
- [unsigned long getElapsedPercent()](#getElapsedPercent)
- [unsigned long getRemainingPercent()](#getRemainingPercent)
- [unsigned int getRepeats()](#getRepeats)

## cgrSoftTimer
- Include library with any defines
```c++
#include <cgrSoftTimer.h>

cgrSoftTimer tmr1; // tmr1 object
```

<h2 id="cgrSoftTimer1">
  cgrSoftTimer(usedTimer usedTimerPtr)
</h2>
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


<h2 id="setHertz">
  void setHertz(unsigned int hertz)
</h2>

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
<h2 id="setTimeout">
  void setTimeout(unsigned long timeout)
</h2>

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

<h2 id="start">
  void start(unsigned int repeatLimit)
</h2>

- Starts the timer with given repeat count. Give **0 (zero)** to function to work infinite

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

<h2 id="stop">
  void stop()
</h2>

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

<h2 id="restart">
  void restart()
</h2>

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

<h2 id="isExpired">
  bool isExpired()
</h2>

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

<h2 id="onExpired">
  bool onExpired()
</h2>

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

<h2 id="isActive">
  bool isActive()
</h2>

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

<h2 id="getElapsedTime">
  unsigned long getElapsedTime()
</h2>

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

<h2 id="getRemainingTime">
  unsigned long getRemainingTime()
</h2>

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

<h2 id="getElapsedPercent">
  unsigned long getElapsedPercent()
</h2>

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

<h2 id="getRemainingPercent">
  unsigned long getRemainingPercent()
</h2>

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

<h2 id="getRepeats">
  unsigned int getRepeats()
</h2>

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
