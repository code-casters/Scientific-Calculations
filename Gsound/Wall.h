#include "Position.h"
#pragma once
class Wall
{
public:
	Wall(void);
	~Wall(void);
	Position start;
	Position end;
	int attenuation;
	double Calc_tita(Ray *ray1);
};

