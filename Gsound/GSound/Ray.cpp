#include "Ray.h"
#include"Scene.h"
#include"MyMath.h"
Ray::Ray(void)
{
}

Ray::Ray(Position* start,Position* end,int weigtht,int length)
{
	this->start = start;
	this->end = end;
	this->weigtht = weigtht;
	this->length = length;
}


Sel_Intersect * Ray::Intersect(Scene * scene)
{
	bool first = true;
	//Sel_Intersect  * Vec_Intersect [4];
	Sel_Intersect  * detectIntersect = NULL;
	for (int i = 0; i < 4; i++)
	{
		Position * position = Chk_Intersect(scene->walls[i]);
		if (position != NULL ){
			int distance = this->start->distanceTo(position);
			if(first){
				detectIntersect = new Sel_Intersect(scene->walls[i],position,distance);
				first = !first;
			}
			else {				
				if( distance < detectIntersect->distance){
					detectIntersect->position = position ;
					detectIntersect->distance = distance;
					detectIntersect->wall = scene->walls[i];
				}

			}
		}
	}
	return detectIntersect;
}

Position* Ray:: Chk_Intersect(Wall * wall){
	Position* intersetionPoint = NULL;
	double m1 = MyMath::calculateM(this->start->x,this->start->y,this->end->x,this->end->y);
	double m2 = MyMath::calculateM(wall->start->x,wall->start->y,wall->end->x,wall->end->y);
	float x = 0 , y = 0;
	MyMath::commonSolution(m1,-1,this->start->y-(m1*this->start->x),m2,-1,wall->start->y-(m2*wall->start->x),x,y);
	if(x <= max(wall->start->x,wall->end->x) && x >= min(wall->start->x,wall->end->x))
		return new Position(x,y,0);
	else
		return NULL;
}

Position* Ray::reflectRay(Wall* wall,Position position)
{
	Vector2f L(this->end->x - this->start->x, this->end->y - this->start->y);
	Vector2f N(wall->end->x - wall->start->x, wall->end->y - wall->start->y);
	Vector2f C = L.projectOn(N);
	Vector2f R = (float)2*C - L ; 
	return new Position(R.x + wall->start->x, R.y + wall->start->y, 0);
}

void Ray::Propagate (Scene* scene,int depth){
	if (depth<2){
		Sel_Intersect * sel_intersect = this->Intersect(scene);		
		Position * endPoint = reflectRay(sel_intersect->wall,sel_intersect->position);
		Ray * ray = new Ray ( new Position(sel_intersect->position),endPoint,this->weigtht-sel_intersect->wall->attenuation,this->length);
		this->end = sel_intersect->position ;
		scene->rays[scene->i] = ray;
		scene->rays[scene->i++]->Propagate(scene,++depth);
	}
}

Ray::~Ray(void)
{
}
