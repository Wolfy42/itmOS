#include <stdio.h>
#include "TimerClass.h"
#include "HAL/bitOperations.h"

TimerClass::TimerClass(address baseAddress): m_baseAddress(baseAddress) {
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
	
	// This register holds the value to be compared with the counter value
	m_tmar = (address)((int)m_baseAddress + GPT_TMAR_OFFSET);
}

TimerClass::~TimerClass() {
}


// ~~~~~~~~~~~~~~~~~~~~ PUBLIC ~~~~~~~~~~~~~~~~~~~~
void TimerClass::init(int compareValue) {
	// Stop the timer (could be already running)
	stop();
	
	setTimerLoadValue(0);
	setCompareValue(compareValue);
	setOptionalFeatures();
}

void TimerClass::stop() {
	disableInterrupt();
	stopTimer();
	setInternalCounter(0);
}

void TimerClass::start(GptInterruptMode mode) {
	enableInterrupt(mode);
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
	//disableInterrupt();
	setBit(m_tier, mode);
}

void TimerClass::setOptionalFeatures() {
	// Set 0 before setting optional features
	//*(m_tclr) &= 0; // set 0
	
	setBit(m_tclr, GPT_TCLR_COMPARE);
	setBit(m_tclr, GPT_TCLR_AUTORELOAD);
}

void TimerClass::startTimer() {
	setBit(m_tclr, GPT_TCLR_START);
}
