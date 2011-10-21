#include "HalTimerDriver.h"
#include "../gpt.h"

HalTimerDriver::HalTimerDriver(): m_timer1(GPTIMER2_BASE) {
}

HalTimerDriver::~HalTimerDriver() {
}

TimerClass HalTimerDriver::timerClassForEnum(Timer timerEnum) {
	switch (timerEnum) {
		case GPTIMER1:
			return m_timer1;
			
		default:
			return m_timer1;
	}
}
