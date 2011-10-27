#ifndef LED_H_
#define LED_H_

class LEDClass {
	private:
		int m_bitNumber;
	
	public:
		LEDClass(int bitNumber);
		virtual ~LEDClass();
		
		void toggle();
		void switchOn();
		void switchOff();
		bool isOff();
};

#endif /*LED_H_*/
