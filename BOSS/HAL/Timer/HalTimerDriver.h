#ifndef HALTIMERDRIVER_H_
#define HALTIMERDRIVER_H_

#include "TimerClass.h"

#define GPTIMER_TCLR_ST address 0x00000001	// 1 = Start the timer, 0 = stop the timer
#define GPTIMER_TCLR_AR address 0x00000010	// 1 = Autoreload mode overflow, 0 = One-shot mode overflow
#define GPTIMER_TCLR_CE address 0x01000000	// 1 = Compare enabled, 0 = Compare disabled

enum Timer {
	GPTIMER1 = 0,
	GPTIMER2 = 1
};

class HalTimerDriver {
	private:
		TimerClass m_timer1;
		TimerClass timerClassForEnum(Timer timerEnum);
		
	public:
		HalTimerDriver();
		virtual ~HalTimerDriver();
		
		void init();
};

#endif /*HALTIMERDRIVER_H_*/
