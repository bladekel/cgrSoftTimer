#include "cgrSoftTimer.h"

cgrSoftTimer::cgrSoftTimer()
{

}

cgrSoftTimer::cgrSoftTimer(usedTimer usedTimerPtr)
{
	this->usedTimerPtr = usedTimerPtr;
}

void cgrSoftTimer::setPrecision(usedTimer usedTimerPtr)
{
	this->usedTimerPtr = usedTimerPtr;
}

void cgrSoftTimer::setHertz(unsigned int hertz)
{
	__hertz = hertz;	
	__hertz = (__hertz > 0) ? __hertz : 1;
	
	if(this->usedTimerPtr == millis)
	{
		__hertz = (__hertz < 1000) ? __hertz : 1000;
		__timeout = (unsigned long)(1000 / __hertz);
	}
	
	else if(this->usedTimerPtr == micros)
	{
		__timeout = (unsigned long)(1000000 / __hertz);
	}		
}

void cgrSoftTimer::setTimeout(unsigned long timeout)
{
	timeout = (timeout > 0) ? timeout : 1;
	
	__timeout = timeout;
}

void cgrSoftTimer::__checkStatus()
{
	if(__isActive == true && getElapsedTime() >= __timeout)
	{
		__repeatCount++;
		__isExpired = true;
		__onExpired = true;
	}
}

void cgrSoftTimer::__checkRepeat()
{
	if(__repeatCount < __repeatLimit || __repeatLimit == 0)
	{
		if(__onExpired)__start();
	}
	
	else 
	{
		__onExpired = false;
		__isActive = false;
		__isCompleted = true;
	}
}

void cgrSoftTimer::__start()
{
	__onExpired = false;
	__kickOff = usedTimerPtr();
}

void cgrSoftTimer::start(unsigned int repeatLimit)
{
	__isActive = true;
	__repeatLimit = repeatLimit;
	__start();
}

void cgrSoftTimer::restart()
{
	stop();
	__isActive = true;
	__isExpired = false;
	__isCompleted = false;
	__repeatCount = 0;
	__start();
}

void cgrSoftTimer::stop()
{
	__isActive = false;
	__isCompleted = false;
}

bool cgrSoftTimer::isExpired()
{
	__checkStatus();
	
	if(__isExpired == true)
	{
		__checkRepeat();
		return true;
	}
}

bool cgrSoftTimer::onExpired()
{
	__checkStatus();
	
	if(__onExpired == true)
	{
		__checkRepeat();
		return true;
	}
}

bool cgrSoftTimer::isCompleted()
{
	__checkStatus();
	__checkRepeat();
	return __isCompleted;
}

bool cgrSoftTimer::isActive()
{
	__checkStatus();
	__checkRepeat();
	return __isActive;
}

unsigned long cgrSoftTimer::getElapsedTime()
{	
	return usedTimerPtr() - __kickOff;
}

unsigned int cgrSoftTimer::getRepeats()
{
	return __repeatCount;
}

unsigned long cgrSoftTimer::getRemainingTime()
{
	return (unsigned long)__timeout - getElapsedTime();
}

unsigned long cgrSoftTimer::getElapsedPercent()
{
	return (getElapsedTime()*100)/__timeout;
}

unsigned long cgrSoftTimer::getRemainingPercent()
{
	return 100 - getElapsedPercent();
}

unsigned int cgrSoftTimer::getHertz()
{
	return __hertz;
}

unsigned long cgrSoftTimer::getTimeout()
{
	return __timeout;
}
