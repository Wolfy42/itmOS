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
	enableInterrupt();
	setOptionalFeatures();
	setInternalCounter();
	setTimerLoadValues();
	setCompareValue();
}

void TimerClass::enableInterrupt() {
	address target = (address)0x4831801C;//m_baseAddress + GPTIMER_TIER_OFFSET;
	*(target) |= 1; 
	int i = 1;
}

void TimerClass::setOptionalFeatures() {
	address target = (address)0x48318024;//m_baseAddress + GPTIMER_TIER_OFFSET;
	*(target) |= 0x43;
	int i = 1;
}

void TimerClass::setInternalCounter() {
	address target = (address)0x48318028;//m_baseAddress + GPTIMER_TCRR_OFFSET;
	*(target) &= 0;
	int i = 1;
}

void TimerClass::setTimerLoadValues() {
	address target = (address)0x4831802C;//m_baseAddress + GPTIMER_TLDR_OFFSET;
	*(target) &= 0;
}

void TimerClass::setCompareValue() {
	address target = (address)0x48318038;//m_baseAddress + GPTIMER_TMAR_OFFSET;
	*(target) |= 1;
}
