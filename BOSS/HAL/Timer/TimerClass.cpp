#include "TimerClass.h"
#include "../gpt.h"

TimerClass::TimerClass(address baseAddress): m_baseAddress(baseAddress) 
{
	init();
}

TimerClass::~TimerClass()
{
}

void TimerClass::init() {
	disableInterrupt();
	stopTimer();
	setInternalCounter();
	setTimerLoadValues();
	setCompareValue();
	enableInterrupt();
	startTimerWithOptionalFeatures();
}

void TimerClass::disableInterrupt() {
	address target = (address)0x4903201C;//m_baseAddress + GPTIMER_TIER_OFFSET;
	*(target) &= 0; // set 0
}

void TimerClass::stopTimer() {
	address target = (address)0x49032024;//m_baseAddress + GPTIMER_TCLR_OFFSET;
	*(target) &= 0; 	// set 0
}

void TimerClass::setInternalCounter() {
	address target = (address)0x49032028;//m_baseAddress + GPTIMER_TCRR_OFFSET;
	*(target) &= 0; // set 0
}

void TimerClass::setTimerLoadValues() {
	address target = (address)0x4903202C;//m_baseAddress + GPTIMER_TLDR_OFFSET;
	*(target) &= 0; // set 0
}

void TimerClass::setCompareValue() {
	address target = (address)0x49032038;//m_baseAddress + GPTIMER_TMAR_OFFSET;
	*(target) &= 0; // set 0
	*(target) |= 10; // set 10
}

void TimerClass::enableInterrupt() {
	address target = (address)0x4903201C;//m_baseAddress + GPTIMER_TIER_OFFSET;
	*(target) |= 1; // set 1
}

void TimerClass::startTimerWithOptionalFeatures() {
	address target = (address)0x49032024;//m_baseAddress + GPTIMER_TCLR_OFFSET;
	*(target) |= 0x43; 	// set 0100 0011
}
