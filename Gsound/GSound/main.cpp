#include<iostream>
using namespace std;
#include "Source.h"
#include "SoundFile.h"
#include "Room.h"
#include "Ray.h"
#include "MyMath.h"
using namespace std;
void main (){
	 //SoundFile soundfile();
	 //Source source();
	/*Ray* raytest = new Ray(new Position(-4,-1,0), new Position(-2,-2,0), 2, 4); 
	Position t = raytest->reflectRay(new Wall(new Position(-2,-2,0), new Position(-3,-3,0)) );
	cout<< t.x <<" "<< t.y<<endl ;*/
	cout<<MyMath::calculateM(-2,1,3,4);
	float x ,y;
	MyMath::commonSolution(3,-2,7,3,-2,4,x,y);
	cout<<x<<endl;
	cout<<y<<endl;
}