#ifndef SNAKESERVICE_H_
#define SNAKESERVICE_H_

#include "Tasks/Services/Service.h"
#include "Tasks/Services/Snake/Position.h"
#include "Service-API/Serial/Serial.h"
#include "Service-API/Display/Display.h"
#include "Service-API/LED/LED.h"
#include <list>

#define KEY_UP 			'w'
#define KEY_DOWN 		's'
#define KEY_LEFT 		'a'
#define KEY_RIGHT 		'd'

#define PAUSE_KEY 		'p'
#define RESTART_KEY		'r'

#define FIELD_SIZE 	32
#define FIELDS_X	32
#define FIELDS_Y	24

#define COLOR_SNAKE	0xFFFFFF
#define COLOR_BG	0x000000
#define COLOR_PAUSE	0x0000FF	

class SnakeService : public Service {
	private: 
		int _score;
		char _direction;
		Position* _current;
		std::list<Position*>* _snake;
		
		bool _paused;
		
		virtual void executeMessage(Message* message);
		
		bool moveInDirection(void);
		bool ateSomething(void);
		
		void pause(void);
		void resume(void);
		void restart(void);
	
	public:
		SnakeService();
		virtual ~SnakeService();
	
		virtual void run();
};

#endif /*SNAKESERVICE_H_*/
