#ifndef TIMERCLASS_H_
#define TIMERCLASS_H_

#include "../../API/dataTypes.h"

class TimerClass {
	private:
		address m_baseAddress;
		
		void stopTimer();
		void disableInterrupt();
		void enableInterrupt();
		void startTimerWithOptionalFeatures();
		void setInternalCounter();
		void setTimerLoadValues();
		void setCompareValue();
		
	public:
		TimerClass(address baseAddress);
		virtual ~TimerClass();
		
		void init();
};

#endif /*TIMERCLASS_H_*/
