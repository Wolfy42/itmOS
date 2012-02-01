#include "SnakeService.h"

SnakeService::SnakeService() : Service() {
	_score = 0;
	_direction = KEY_RIGHT;
	_current = new Position(5 * FIELD_SIZE, 3 * FIELD_SIZE);
	_paused = true;
	
	moveTo(100, 100);
	setColor(COLOR_PAUSE);
	drawChar('S', 3);
}

SnakeService::~SnakeService() {}

void SnakeService::executeMessage(Message* message) {
	int* params = message->getParams();
	char* char_params = new char[message->getParamsLength()];
	
	for (int i = 1; i < message->getParamsLength(); i++) {	
		char_params[i - 1] = params[i];	
	}

	SerialServiceCommand command = (SerialServiceCommand)params[0];
	
	switch (command) {
		case NEXT_CHAR:
			// set direction
			if (char_params[0] == KEY_UP 
					|| char_params[0] == KEY_DOWN
					|| char_params[0] == KEY_LEFT
					|| char_params[0] == KEY_RIGHT) {
				_direction = char_params[0];
			} else if (char_params[0] == PAUSE_KEY) {
				pause();
			} else if (char_params[0] == RESTART_KEY) {
				restart();
			}
			break;
	}
}

bool SnakeService::moveInDirection(void) {
	if (_paused) {
		return true;
	}	
	
	int actualX = _current->getX();
	int actualY = _current->getY();
		
	switch (_direction) {
		case KEY_UP:
			actualY -= FIELD_SIZE;
			break;
		
		case KEY_DOWN:
			actualY += FIELD_SIZE;
			break;
		
		case KEY_LEFT:
			actualX -= FIELD_SIZE;
			break;
		
		case KEY_RIGHT:
			actualX += FIELD_SIZE;
			break;
		
		default:
			break;
	}
	
	if (actualX < 0 || actualX > 1024 || actualY < 0 || actualY > 768) {
		return false;
	}
	
	// Add new Head
	_snake->push_back(new Position(actualX, actualY));
	
	// Draw new Head
	setColor(COLOR_SNAKE);
	moveTo(actualX, actualY);
	drawRect(FIELD_SIZE, FIELD_SIZE);
	
	// If we eat something, then increase the score and do not remove the tail
	if (ateSomething()) {
		_score++;
	} else {	
		// Get Tail and remove it if we didn't eat something
		Position* tail = _snake->front();
		_snake->pop_front();
		
		// Remove tail
		setColor(COLOR_BG);
		moveTo(tail->getX(), tail->getY());
		drawRect(FIELD_SIZE, FIELD_SIZE);
		
		// Delete tail
		delete tail;
	}
	
	return true;
}

bool SnakeService::ateSomething(void) {
	return true;
}

void SnakeService::pause(void) {
	_paused = !_paused;
}

void SnakeService::restart(void) {
	// Clear the whole screen and reset all the points and positions
	setColor(COLOR_BG);
	moveTo(0, 0);
	drawRect(1024, 768);
	
	// Clear the snake-list
	_snake->clear();
	
	// Reset all values
	_score = 0;
	_direction = KEY_RIGHT;
	_current = new Position(5 * FIELD_SIZE, 3 * FIELD_SIZE);
	_paused = false;
}

void SnakeService::run() {
	while(1) {
		while(moveInDirection())  {
			for (int z = 0; z < 80000;) {
				z++;
			}
		}
		// Display Score
		// Print Game Over and offer restart options
	}
}
