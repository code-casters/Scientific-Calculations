#include "Ray.h"
#include "Scene.h"

Ray::Ray(void)
{
}

Ray::Ray(Position *start,Position *end,int weigtht,int length)
{
	Start=start;
	End =end;
	Weigtht=weigtht;
	Length=length;
}

//bool Ray::Detect_Object()
//{
//	//áÍ íÔíß ÅĞÇ ÇáÑÇí Úã íÊŞÇØÚ ãÚ Ôí ÎØ
//}

Sel_Intersect * Ray::Intersect(Ray * ray,Scene * scene)
{
	int j=0;
	Sel_Intersect  * Vec_Intersect [4];
	for (int i = 0; i < 4; i++)
	{
		Position * position = Chk_Intersect(scene->walls[i]);
		if (position != NULL){
			Vec_Intersect[j++]=new Sel_Intersect(scene->walls[i],position);
		}
	}
}

Position Ray::*Chk_Intersect(Wall* wall){
	//ÅíÌÇÏ Íá ãÔÊÑß áãÚÇÏáÉ ãÓÊŞíãíä æÅĞÇ áã íßä åäÇß Íá íÚíÏ äæá
	//for Eyadof
}

Position  * Ray::ReflectRay(Ray *ray,double tita)
{
	//endPointByDot ÇáÎæÇÑÒíãÉ ÇáãáåãÈÉ :D

}

void Ray::Propogate (Scene* scene,int depth){
	if (depth<2){
		Sel_Intersect * sel_intersect = Intersect(this,scene);
		Position * end = ReflectRay(this,sel_intersect->wall->Calc_tita(this));
		Ray * ray = new Ray (sel_intersect->position,end,this->Weigtht-sel_intersect->wall->attenuation,5);// add length after adding Vector
		scene->rays [1] = ray;
		scene->rays [1]->Propogate(scene,++depth);
	}
}

Ray::~Ray(void)
{
}
