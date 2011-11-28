#ifndef HALTIMERDRIVER_H_
#define HALTIMERDRIVER_H_

#include "HAL/Timer/TimerClass.h"
#include "HAL/gpt.h"

class HalTimerDriver {
	private:		
		static HalTimerDriver TIMER_DRIVER;
	
		HalTimerDriver();
		virtual ~HalTimerDriver();
		
		TimerClass m_timer1;
		TimerClass m_timer2;
		TimerClass m_timer3;
		TimerClass m_timer4;
		TimerClass m_timer5;
		TimerClass m_timer6;
		TimerClass m_timer7;
		TimerClass m_timer8;
		TimerClass m_timer9;
		TimerClass m_timer10;
		TimerClass m_timer11;		
		
		TimerClass timerClassForEnum(Timer timerEnum);
		
	public:		
		static Timer timerForIRQNumber(int irqNumber);
		static int irqNumberForTimer(Timer timerEnum);
		
		static void init(Timer timer, GptInterruptMode mode, int intervalValue);
		static void start(Timer timer);
		static void stop(Timer timer);
		static void clearPendingInterrupts(Timer timer);
		static void resetInternalCounter(Timer timer);
		
		static GptInterruptMode getMode(Timer timer);
};

#endif /*HALTIMERDRIVER_H_*/
