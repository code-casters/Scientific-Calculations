#pragma once
#include "Sel_Intersect.h"

class Scene;
class Ray
{
public:
	Ray(void);
	Ray(Position *,Position *,int,int);
	~Ray(void);
	Position * start;
	Position * end;
	int weigtht;
	int length;
	//bool Detect_Object();
	//Position * ReflectRay(Wall *,double);
	Position* reflectRay(Wall *,Position);
	Sel_Intersect* Intersect(Scene*);
	void Propagate (Scene*, int);
	Position* Chk_Intersect(Wall*);
};