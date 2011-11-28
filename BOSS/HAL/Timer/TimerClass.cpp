#include <stdio.h>
#include "TimerClass.h"
#include "Lib/bitOperations.h"

TimerClass::TimerClass(Timer id, address baseAddress): m_id(id), m_baseAddress(baseAddress) {
	// Interruptmode Overflow as default
	m_mode = GPT_IRQMODE_OVERFLOW;
	
	// Interval Value default
	m_intervalValue = 1000;
	
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
	
	// This register holds the value to be compared with the counter value
	m_tpir = (address)((int)m_baseAddress + GPT_TPIR_OFFSET);
	
	// This register holds the value to be compared with the counter value
	m_tnir = (address)((int)m_baseAddress + GPT_TNIR_OFFSET);
	
	// This register holds the value to be compared with the counter value
	m_tocr = (address)((int)m_baseAddress + GPT_TOCR_OFFSET);
	
	// This register holds the value to be compared with the counter value
	m_towr = (address)((int)m_baseAddress + GPT_TOWR_OFFSET);
}

TimerClass::~TimerClass() {
}


// ~~~~~~~~~~~~~~~~~~~~ PUBLIC ~~~~~~~~~~~~~~~~~~~~
void TimerClass::init(GptInterruptMode mode, int intervalValue) {
	// Set the mode
	m_mode = mode;
	
	// Set interval value
	m_intervalValue = intervalValue;
	
	// Setup GPTIMER1
	if (m_id == GPTIMER1) {
		enableGptimer1();
	}
	
	// Stop the timer (could be already running)
	stop();
	
	// Clear all interrupts
	clearPendingInterrupts();
	
	if (m_id == GPTIMER1 || m_id == GPTIMER2) {
		initOneMsTimer();
	} else {		
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
void TimerClass::initOneMsTimer() {	
  	setIncrementRegisters();
  	
  	// DEFAULT = GPT_IRQMODE_OVERFLOW
	switch (m_mode) {
		case GPT_IRQMODE_CAPTURE:
			// TODO: Not yet supported
			break;
			
		case GPT_IRQMODE_MATCH:  
			setCompareValue(0xFFFFFFFF - ONE_MS_VALUE);
			setInternalCounter(0);
			break;
			
		default:	// GPT_IRQMODE_OVERFLOW
			setTimerLoadValue(ONE_MS_VALUE);
			
			// Set bit to trigger load of "timer load value" to "timer counter register"
			setBit(m_ttgr, 1);
			break;
	}
	
	setOneMsOverflowCounter();
	setOneMsOverflowCompareValue();
	selectSourceClock(true);
}

void TimerClass::enableGptimer1() {
	// Set registers to use GPTIMER1
	setBit(CM_FCLKEN_WKUP, EN_GPT1);
	setBit(CM_ICLKEN_WKUP, EN_GPT1);
	unsetBit(CM_CLKSEL_WKUP, 0);
		
	// Wait until GPTIMER1 is ready to use
	unsigned int totalWaitTimeMs = 0;
	while (readBit(CM_IDLEST_WKUP, ST_GPT1)) {
	 	totalWaitTimeMs++;
	}
		 
	// Softreset GPTIMER1
	setBit(TIOCP_CFG_GPT1, SOFTRESET);
		 
	// Wait until GPTIMER1 is reset
	totalWaitTimeMs = 0;
 	while (readBit(TISTAT_GPT1, RESETDONE) == 0) {
  		totalWaitTimeMs++;
 	}
}

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
	
	setBit(m_tclr, GPT_TCLR_TRG_OVF_MAT);
	setBit(m_tclr, GPT_TCLR_COMPARE);
	setBit(m_tclr, GPT_TCLR_AUTORELOAD);
}

void TimerClass::startTimer() {
	setBit(m_tclr, GPT_TCLR_START);
}

void TimerClass::setIncrementRegisters() {
	// Set up 1ms 
	int overflow_ticks = 1;
  	int pos_inc = ((((int)(CLK_FREQUENCE * overflow_ticks)) + 1) * 1000000) - (CLK_FREQUENCE * overflow_ticks * 1000000);
  	int neg_inc = (( (int)(CLK_FREQUENCE * overflow_ticks)) 	 * 1000000) - (CLK_FREQUENCE * overflow_ticks * 1000000);
  	
  	*(m_tpir) = pos_inc;
  	*(m_tnir) = neg_inc;	
}

void TimerClass::setOneMsOverflowCounter() {
	*(m_tocr) = 0;
}

void TimerClass::setOneMsOverflowCompareValue() {
	*(m_towr) = m_intervalValue;
}

void TimerClass::selectSourceClock(bool is32k) {
	if (is32k) {
		unsetBit(CM_CLKSEL_PER, m_id - 2);
	} else {
		setBit(CM_CLKSEL_PER, m_id - 2);
	}
}
