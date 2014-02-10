#include "Listner.h"

Listner::Listner(void)
{
}

Listner::Listner(int x, int y, int z)
{
	this->position->x = x;
	this->position->y = y;
	this->position->z = z;
}

Listner::Listner(Position * position)
{
	this->position = position;
}

Listner::~Listner(void)
{
}
