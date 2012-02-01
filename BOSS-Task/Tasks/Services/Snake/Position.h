#ifndef POSITION_H_
#define POSITION_H_

class Position
{
	private:
		int _x;
		int _y;
	
	public:
		Position(int x, int y);
		virtual ~Position();
		
		int getX(void);
		int getY(void);
};

#endif /*POSITION_H_*/
