#include "Position.h"
#include <math.h>

Position::Position(void)
{
}
Position::Position(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Position::Position(const Position*  position)
{
	this->x = position->x;
	this->y = position->y;
	this->z = position->z;
}
Position::~Position(void)
{
}

double Position::distanceTo(Position* position)
{
	double a = pow( double(this->x - position->x) ,2);
	double b = pow( double(this->y - position->y) ,2);
	return sqrt(a + b);
}
