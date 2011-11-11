#ifndef TIMERCLASS_H_
#define TIMERCLASS_H_

#include "API/dataTypes.h"
#include "HAL/gpt.h"

class TimerClass {
	private:
		// Timer base address 
		address m_baseAddress;
		
		// Calculated from base address
		address m_tier;
		address m_tisr;
		address m_tclr;
		address m_tcrr;
		address m_tldr;
		address m_ttgr;
		address m_tmar;
		
		void stopTimer();
		void disableInterrupt();
		void enableInterrupt(GptInterruptMode mode);
		void setOptionalFeatures();
		void startTimer();
		void setInternalCounter(int counterValue);
		void setTimerLoadValue(int timerLoadValue);
		void setCompareValue(int compareValue);
		
	public:
		TimerClass(address baseAddress);
		virtual ~TimerClass();
		
		void init(GptInterruptMode mode, int intervalValue);
		void start();
		void stop();
		void clearPendingInterrupts();
		void resetInternalCounter();
};

#endif /*TIMERCLASS_H_*/
