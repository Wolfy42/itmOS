#include <stdio.h>
#include "TimerClass.h"
#include "HAL/bitOperations.h"

TimerClass::TimerClass(address baseAddress): m_baseAddress(baseAddress) {
	// Interruptmode Overflow as default
	m_mode = GPT_IRQMODE_OVERFLOW;
	
	// This register controls (enable/disable) the interrupt events
	m_tier = (address)((int)m_baseAddress + GPT_TIER_OFFSET);

	// This register shows which interrupt events are pending inside the module
	m_tisr = (address)((int)m_baseAddress + GPT_TISR_OFFSET);
	
	// This register controls optional features specific to the timer functionality
	m_tclr = (address)((int)m_baseAddress + GPT_TCLR_OFFSET);
	
	// This register holds the value of the internal counter
	m_tcrr = (address)((int)m_baseAddress + GPT_TCRR_OFFSET);
	
	// This register holds the timer load values
	m_tldr = (address)((int)m_baseAddress + GPT_TLDR_OFFSET);
	
	// This register triggers a counter reload of timer by writing any value in it
	m_ttgr = (address)((int)m_baseAddress + GPT_TTGR_OFFSET);
	
	// This register holds the value to be compared with the counter value
	m_tmar = (address)((int)m_baseAddress + GPT_TMAR_OFFSET);
}

TimerClass::~TimerClass() {
}


// ~~~~~~~~~~~~~~~~~~~~ PUBLIC ~~~~~~~~~~~~~~~~~~~~
void TimerClass::init(GptInterruptMode mode, int intervalValue) {
	// Set the mode
	m_mode = mode;
	
	// Stop the timer (could be already running)
	stop();
	
	
	// DEFAULT = GPT_IRQMODE_OVERFLOW
	switch (m_mode) {
		case GPT_IRQMODE_CAPTURE:
			// TODO: Not yet supported
			break;
			
		case GPT_IRQMODE_MATCH:  
			setCompareValue(intervalValue);
			setInternalCounter(0);
			break;
			
		default:	// GPT_IRQMODE_OVERFLOW
			setTimerLoadValue(0xFFFFFFFF - intervalValue);
			
			// Set bit to trigger load of "timer load value" to "timer counter register"
			setBit(m_ttgr, 1);
			break;
	}
	
	setOptionalFeatures();
	enableInterrupt(mode);
}

void TimerClass::stop() {
	disableInterrupt();
	stopTimer();
}

void TimerClass::start() {
	startTimer();
}

void TimerClass::clearPendingInterrupts() {
	setBit(m_tisr, GPT_PENDING_CAPTURE);
	setBit(m_tisr, GPT_PENDING_OVERFLOW);
	setBit(m_tisr, GPT_PENDING_MATCH);
}

void TimerClass::resetInternalCounter() {
	setInternalCounter(0);
}

GptInterruptMode TimerClass::getMode() {
	return m_mode;
}


// ~~~~~~~~~~~~~~~~~~~~ PRIVATE ~~~~~~~~~~~~~~~~~~~~
void TimerClass::disableInterrupt() {
	*(m_tier) &= 0; // set 0
}

void TimerClass::stopTimer() {
	unsetBit(m_tclr, GPT_TCLR_START);
}

void TimerClass::setInternalCounter(int counterValue) {
	*(m_tcrr) = counterValue;
}

void TimerClass::setTimerLoadValue(int timerLoadValue) {
	*(m_tldr) = timerLoadValue;
}

void TimerClass::setCompareValue(int compareValue) {
	*(m_tmar) = compareValue;
}

void TimerClass::enableInterrupt(GptInterruptMode mode) {
	disableInterrupt();
	setBit(m_tier, mode);
}

void TimerClass::setOptionalFeatures() {
	// Set 0 before setting optional features
	*(m_tclr) &= 0; // set 0
	
	setBit(m_tclr, GPT_TCLR_COMPARE);
	setBit(m_tclr, GPT_TCLR_AUTORELOAD);
}

void TimerClass::startTimer() {
	setBit(m_tclr, GPT_TCLR_START);
}
