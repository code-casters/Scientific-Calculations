#include<iostream>
using namespace std;
#include "Source.h"
#include "SoundFile.h"
#include "Room.h"
#include "Ray.h"
#include "MyMath.h"
#include "Scene.h"
using namespace std;
void main (){
	 //SoundFile soundfile();
	 //Source source();
	Ray* raytest = new Ray(new Position(1,1,0), new Position(2,2,0), 2, 4); 
	//Position* t = raytest->Chk_Intersect(new Wall(new Position(5,1,0), new Position(5,4,0)) );
	Wall* wall1 = new Wall(new Position(5,-4,0), new Position(5,4,0));
	Wall* wall2 = new Wall(new Position(-5,-4,0), new Position(-5,4,0));
	Wall* wall3 = new Wall(new Position(-5,4,0), new Position(5,4,0));
	Wall* wall4 = new Wall(new Position(-5,-4,0), new Position(5,-4,0));
	Scene* scene = new Scene(wall1,wall2,wall3,wall4);
	raytest->Propagate(scene,1);
	//Sel_Intersect* t = raytest->Intersect(scene);
	//cout<< t->position->x <<" "<< t->position->y<<endl ;

}