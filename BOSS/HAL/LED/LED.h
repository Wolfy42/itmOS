#ifndef LED_H_
#define LED_H_

class LEDClass {
	private:
		int m_bitNumber;
	
	public:
		LEDClass(int regNumber);
		virtual ~LEDClass();
		
		void toggle();
		void switchOn();
		void switchOff();
		bool isOn();
};

#endif /*LED_H_*/
