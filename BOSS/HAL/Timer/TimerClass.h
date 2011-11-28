#ifndef TIMERCLASS_H_
#define TIMERCLASS_H_

#include "API/dataTypes.h"
#include "HAL/gpt.h"

class TimerClass {
	private:
		// Timer ID
		Timer m_id;
		
		// Timer base address 
		address m_baseAddress;
		
		// Interrupt Mode
		GptInterruptMode m_mode;
		
		// Interval Value
		int m_intervalValue;
		
		// Calculated from base address
		address m_tier;
		address m_tisr;
		address m_tclr;
		address m_tcrr;
		address m_tldr;
		address m_ttgr;
		address m_tmar;
		address m_tpir;
		address m_tnir;
		address m_tocr;
		address m_towr;
		
		void stopTimer();
		void disableInterrupt();
		void enableInterrupt(GptInterruptMode mode);
		void setOptionalFeatures();
		void startTimer();
		void setInternalCounter(int counterValue);
		void setTimerLoadValue(int timerLoadValue);
		void setCompareValue(int compareValue);
		void setIncrementRegisters();
		void setOneMsOverflowCounter();
		void setOneMsOverflowCompareValue();
		void selectSourceClock(bool is32k); 
		
		void initOneMsTimer();
		
	public:
		TimerClass(Timer id, address baseAddress);
		virtual ~TimerClass();
		
		void init(GptInterruptMode mode, int intervalValue);
		void start();
		void stop();
		void clearPendingInterrupts();
		void resetInternalCounter();
		
		GptInterruptMode getMode();
};

#endif /*TIMERCLASS_H_*/
