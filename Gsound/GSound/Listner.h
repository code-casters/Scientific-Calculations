#include "Position.h"
#pragma once
class Listner
{
public:
	Listner(void);
	Listner(int, int, int);
	Listner(Position* );
	~Listner(void);
	Position * position;
};

