#ifndef __CGRSOFTTİMER_H__
#define __CGRSOFTTİMER_H__

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class cgrSoftTimer
{
	private:
		unsigned int __hertz	= 1;
		unsigned long __timeout = 1000;
		unsigned int __repeatLimit;
		unsigned int __repeatCount;
		unsigned long __kickOff;
		bool __isStarted = false;
		bool __isExpired = false;
		bool __onExpired;
		bool __isActive = false;
		bool __isCompleted = false;
		void __checkStatus();
		void __checkRepeat();
		void __start();
		typedef uint32_t (*usedTimer)();
		usedTimer usedTimerPtr;		// Timer function (millis ? micros )
		
	public:
		cgrSoftTimer(usedTimer usedTimerPtr); // Class constructor
	
		void setHertz(unsigned int hertz); // Set the timer hertz
		void setTimeout(unsigned long timeout); // Sets the timer timeout
		void start(unsigned int repeatLimit); // Starts the timer with given count limit (0 is unlimited)
		void restart(); // Restarts the timer with given values before
		void stop(); // Stops the timer
	
		bool isExpired(); // Returns true continuously while in expire
		bool onExpired(); // Returns true one time when has expired
		bool isCompleted(); // Returns true if all repeats are completed
		bool isActive();  // Returns the timer status
		unsigned long getElapsedTime(); // Returns the elapsed time
		unsigned long getRemainingTime(); // Returns the remaining time
		unsigned int  getRepeats(); // Returns the repeat count
		unsigned long getElapsedPercent(); // Returns the percentage of the elapsed time
		unsigned long getRemainingPercent(); // Returns the percentage of the remaining time
}; //cgrSoftTimer

#endif //__CGRSOFTTİMER_H__
