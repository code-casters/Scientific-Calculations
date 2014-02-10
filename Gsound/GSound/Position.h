#pragma once
class Position
{
public:
	Position(void);
	Position(int, int, int);
	Position(const Position*  );
	~Position(void);
	double distanceTo(Position* position);
	int x,y,z;
};

