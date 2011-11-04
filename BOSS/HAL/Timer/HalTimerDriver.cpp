#include "HalTimerDriver.h"

HalTimerDriver::HalTimerDriver(): 	m_timer1(GPTIMER1_BASE),
									m_timer2(GPTIMER2_BASE),
									m_timer3(GPTIMER3_BASE),
									m_timer4(GPTIMER4_BASE),
									m_timer5(GPTIMER5_BASE),
									m_timer6(GPTIMER6_BASE),
									m_timer7(GPTIMER7_BASE),
									m_timer8(GPTIMER8_BASE),
									m_timer9(GPTIMER9_BASE),
									m_timer10(GPTIMER10_BASE),
									m_timer11(GPTIMER11_BASE) {
}

HalTimerDriver::~HalTimerDriver() {
}


// ~~~~~~~~~~~~~~~~~~~~ PUBLIC ~~~~~~~~~~~~~~~~~~~~
void HalTimerDriver::init(Timer timer, int compareValue) {
	timerClassForEnum(timer).init(compareValue);
}

void HalTimerDriver::start(Timer timer, GptInterruptMode mode) {
	timerClassForEnum(timer).start(mode);
}

void HalTimerDriver::stop(Timer timer) {
	timerClassForEnum(timer).stop();
}

void HalTimerDriver::clearPendingInterrupts(Timer timer) {
	timerClassForEnum(timer).clearPendingInterrupts();
}

void HalTimerDriver::resetInternalCounter(Timer timer) {
	timerClassForEnum(timer).resetInternalCounter();
}


// ~~~~~~~~~~~~~~~~~~~~ PRIVATE ~~~~~~~~~~~~~~~~~~~~
// TODO: Implement all the timers
TimerClass HalTimerDriver::timerClassForEnum(Timer timerEnum) {
	switch (timerEnum) {
		/*case GPTIMER1:
			return m_timer1;*/
			
		case GPTIMER2:
			return m_timer2;
		
		case GPTIMER3:
			return m_timer3;	

		case GPTIMER4:
			return m_timer4;
			
		case GPTIMER5:
			return m_timer5;
	
		case GPTIMER6:
			return m_timer6;

		case GPTIMER7:
			return m_timer7;
		
		case GPTIMER8:
			return m_timer8;	

		case GPTIMER9:
			return m_timer9;
			
		case GPTIMER10:
			return m_timer10;
	
		case GPTIMER11:
			return m_timer11;
			
		default:
			return m_timer2;
	}
}
